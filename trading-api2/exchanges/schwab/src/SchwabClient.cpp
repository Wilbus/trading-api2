#include "SchwabClient.h"

#include "Logger.h"
#include "SchwabAccountDataParser.h"
#include "SchwabErrorParser.h"
#include "SchwabMarketDataParser.h"
#include "SystemTimer.h"
#include "UriEncodeDecode.h"
#include "base64.hpp"
#include "timefuncs.h"

#include <iostream>

namespace restclient {
using namespace std::chrono;

SchwabClient::SchwabClient(
    std::shared_ptr<ISchwabConfigs> config, std::shared_ptr<IRestClientCurl> restClient, std::string logfile)
    : config(config)
    , restClient(restClient)
    , logfile(logfile)
{
    infologprint(logfile, "%s: init", __func__);
}

/*
example header
curl -X 'GET' \
  'https://api.schwabapi.com/marketdata/v1/quotes?symbols=SPY&fields=quote%2Creference&indicative=false' \
  -H 'accept: application/json' \
  -H 'Authorization: Bearer I0.fsfsfsfsssome_access_token0@'
*/
std::set<std::string> SchwabClient::headers() const
{
    //clang-format off
    std::string bearer = "Authorization: Bearer " + utils::url_decode(config->getAccessToken().token);
    std::string content_type = "accept: application/json";
    return std::set<std::string>{content_type, bearer};
    //clang-format on
}

void SchwabClient::setMarketDataEndpoint()
{
    restClient->setBaseEndpoint("https://api.schwabapi.com/marketdata/v1");
    infologprint(logfile, "%s", __func__);
}

void SchwabClient::setAuthenticationEndpoint()
{
    restClient->setBaseEndpoint("https://api.schwabapi.com/v1");
    infologprint(logfile, "%s", __func__);
}

void SchwabClient::setAccountsEndpoint()
{
    restClient->setBaseEndpoint("https://api.schwabapi.com/trader/v1");
    infologprint(logfile, "%s", __func__);
}

bool SchwabClient::checkAccessToken()
{
    time_t nowMs = utils::nowMs();

    Token accessToken = config->getAccessToken();
    time_t expires = accessToken.expires_at_time;

    /*timefuncs functions require unix time in seconds*/
    time_t temp_now_unix_seconds = nowMs / 1000;
    time_t temp_expires_unix_seconds = expires / 1000;
    std::string nowTimeStr = timefuncs::unixTimeToString(temp_now_unix_seconds, "%Y-%m-%dT%H:%M:%S");
    std::string accessTokenExpiresAt = timefuncs::unixTimeToString(temp_expires_unix_seconds, "%Y-%m-%dT%H:%M:%S");

    infologprint(logfile, "%s: Current time is %s, Access Token expires at %s", __func__, nowTimeStr.c_str(),
        accessTokenExpiresAt.c_str());

    // TODO: check if expires_at_time is a valid timestamp somehow
    // give 5 minute buffer before current token expires to avoid minor mismatches in local time and schwab server time
    time_t preemtiveExpire = accessToken.expires_at_time - 300000;
    if (nowMs < preemtiveExpire)
    {
        return true;
    }

    infologprint(logfile, "%s: Preemtively refreshing access token 5 minutes before expiry (which is %ld)", __func__,
        preemtiveExpire);
    return false;
}

void SchwabClient::logErrorResponse(ErrorResponse errorResp)
{
    infologprint(logfile, "%s: client received error: %s", errorResp.toString().c_str());
}

/*
curl -X POST \https://api.schwabapi.com/v1/oauth/token
\-H 'Authorization: Basic {BASE64_ENCODED_Client_ID:Client_Secret}
\-H 'Content-Type: application/x-www-form-urlencoded'
\-d
'grant_type=authorization_code&code={AUTHORIZATION_CODE_VALUE}&redirect_uri=https://example_url.com/callback_example'
*/
bool SchwabClient::createAccessToken(std::string authorizationCode)
{
    infologprint(logfile, "%s: creating access token", __func__);
    std::string path = "/oauth/token";
    std::string content_type = "Content-Type: application/x-www-form-urlencoded";

    std::string appkey = config->getAppKey();
    std::string appsecret = config->getAppSecret();
    std::string authorizationBasicField = base64::to_base64(appkey + ":" + appsecret);
    std::string authorization_code_header = "Authorization: Basic " + authorizationBasicField;
    std::set<std::string> headers{authorization_code_header, content_type};

    std::string body;

    body = "grant_type=authorization_code&code=" + utils::url_decode(authorizationCode) +
           "&redirect_uri=" + config->getRedirectUri();

    try
    {
        setAuthenticationEndpoint();
        auto resp = restClient->postResponse(path, headers, body);
        auto errorResp = checkErrors(resp);
        if (errorResp.errors.size() > 0)
        {
            logErrorResponse(errorResp);
            return false;
        }
        auto authTokens = parseAuthTokens(resp);
        auto granted_at_time = utils::nowMs();

        Token accessToken;
        accessToken.token = authTokens.access_token;
        accessToken.granted_at_time = granted_at_time;
        accessToken.expires_at_time = accessToken.granted_at_time + (authTokens.expires_in * 1000);
        config->saveAccessToken(accessToken);

        Token refreshToken;
        refreshToken.token = authTokens.refresh_token;
        refreshToken.granted_at_time = granted_at_time;
        refreshToken.expires_at_time =
            refreshToken.granted_at_time + (60 * 60 * 24 * 7 * 1000); // 7 days in milliseconds
        config->saveRefreshToken(refreshToken);

        return true;
    }
    catch (const std::exception& e)
    {
        infologprint(logfile, "%s: caught exception: %s", __func__, e.what());
        return false;
    }
}

bool SchwabClient::updateAccessToken(std::string refreshToken)
{
    infologprint(logfile, "%s: updating access token", __func__);
    std::string path = "/oauth/token";
    std::string content_type = "Content-Type: application/x-www-form-urlencoded";

    std::string appkey = config->getAppKey();
    std::string appsecret = config->getAppSecret();
    std::string authorizationBasicField = base64::to_base64(appkey + ":" + appsecret);
    std::string authorization_code_header = "Authorization: Basic " + authorizationBasicField;
    std::set<std::string> headers{authorization_code_header, content_type};

    std::string body;
    std::cout << "Refreshing a new access token\n";
    body = "grant_type=refresh_token&refresh_token=" + refreshToken;

    try
    {
        setAuthenticationEndpoint();
        auto resp = restClient->postResponse(path, headers, body);
        auto errorResp = checkErrors(resp);
        if (errorResp.errors.size() > 0)
        {
            logErrorResponse(errorResp);
            return false;
        }
        auto authTokens = parseAuthTokens(resp);

        /*updateAccessToken response also contains copy of current refreshToken.
        consider saving that also if needed*/
        Token accessToken;
        accessToken.token = authTokens.access_token;
        accessToken.granted_at_time = utils::nowMs();
        accessToken.expires_at_time = accessToken.granted_at_time + (authTokens.expires_in * 1000);
        config->saveAccessToken(accessToken);

        infologprint(logfile, "%s: updated access token expires at: %ld", __func__, accessToken.expires_at_time);
        return true;
    }
    catch (const std::exception& e)
    {
        infologprint(logfile, "%s: caught exception: %s", __func__, e.what());
        return false;
    }
}

//'https://api.schwabapi.com/marketdata/v1/quotes?symbols=SPY%2C%20AAPL&fields=quote%2Creference&indicative=true'
std::map<std::string, QuoteEquityResponse> SchwabClient::getEquityQuotes(std::set<std::string> symbols)
{
    std::string logsymbols;
    for (const auto& symb : symbols)
    {
        logsymbols += (symb + ", ");
    }
    infologprint(logfile, "%s: requesting equity quotes for: %s", __func__, logsymbols.c_str());
    // TODO: add ways to handle other fields such as fundamental, extended
    std::string path = "/quotes?symbols=";
    std::string quotelist;
    for (const auto& symbol : symbols)
    {
        quotelist += symbol + ",";
    }
    quotelist = quotelist.substr(0, quotelist.length() - 1); // take off last comma
    quotelist = utils::url_encode(quotelist);

    std::string fieldslist = "quote";
    std::string indicative = "false";

    path += quotelist + "&fields=" + fieldslist + "&indicative=" + indicative;

    try
    {
        if (!checkAccessToken())
        {
            updateAccessToken(config->getRefreshToken().token);
        }
        setMarketDataEndpoint();
        auto resp = restClient->getResponse(path, headers());
        auto errorResp = checkErrors(resp);
        if (errorResp.errors.size() > 0)
        {
            logErrorResponse(errorResp);
            return {};
        }
        auto quotesmap = parseEquityQuotes(symbols, resp);
        return quotesmap;
    }
    catch (std::exception& e)
    {
        infologprint(logfile, "%s: caught exception: %s", __func__, e.what());
        return {};
    }
}

//'https://api.schwabapi.com/marketdata/v1/chains?symbol=AAPL&contractType=ALL&strikeCount=5&strategy=SINGLE'
OptionChain SchwabClient::getOptionChain(std::string symbol, unsigned strikesCount)
{
    infologprint(logfile, "%s: request option chain for: %s, strikesCount: %u", __func__, symbol.c_str(), strikesCount);

    std::string path = "/chains?symbol=" + symbol + "&contractType=ALL&strikeCount=" + std::to_string(strikesCount) +
                       "&strategy=SINGLE";
    try
    {
        if (!checkAccessToken())
        {
            updateAccessToken(config->getRefreshToken().token);
        }
        setMarketDataEndpoint();
        auto resp = restClient->getResponse(path, headers());
        auto errorResp = checkErrors(resp);
        if (errorResp.errors.size() > 0)
        {
            logErrorResponse(errorResp);
            return {};
        }
        return parseOptionChain(resp);
    }
    catch (const std::exception& e)
    {
        infologprint(logfile, "%s: caught exception: %s", __func__, e.what());
        return {};
    }
}

//'https://api.schwabapi.com/marketdata/v1/expirationchain?symbol=AAPL'
std::vector<OptionExpiration> SchwabClient::getOptionExpirations(std::string symbol)
{
    infologprint(logfile, "%s: request option expirations for: %s", __func__, symbol.c_str());
    try
    {
        if (!checkAccessToken())
        {
            updateAccessToken(config->getRefreshToken().token);
        }
        setMarketDataEndpoint();
        std::string path = "/expirationchain?symbol=" + symbol;
        auto resp = restClient->getResponse(path, headers());
        auto errorResp = checkErrors(resp);
        if (errorResp.errors.size() > 0)
        {
            logErrorResponse(errorResp);
            return {};
        }
        return parseOptionExpirations(resp);
    }
    catch (const std::exception& e)
    {
        infologprint(logfile, "%s: caught exception: %s", __func__, e.what());
        return {};
    }
}

//'https://api.schwabapi.com/marketdata/v1/pricehistory?symbol=AAPL&periodType=year&period=1&frequencyType=daily&frequency=1&startDate=1711386774000&needExtendedHoursData=true&needPreviousClose=true'
PriceHistory SchwabClient::getPriceHistory(std::string symbol, PriceHistoryPeriodType periodType, unsigned periodAmount,
    PriceHistoryTimeFreq timeFreq, unsigned freqAmount, std::string startDate, std::string endDate, bool extendedHours,
    bool needPreviousClose)
{
    try
    {
        infologprint(logfile,
            "%s: request price history for: symbol=%s, periodType=%d, periodAmount=%u, timeFreq=%d,"
            "freqAmount=%u, startDate=%s, endDate=%s, extendedHours=%d, needPreviousClose=%d",
            __func__, symbol.c_str(), static_cast<int>(periodType), periodAmount, static_cast<int>(timeFreq),
            freqAmount, startDate.c_str(), endDate.c_str(), extendedHours, needPreviousClose);

        int64_t unixStartDate = static_cast<int64_t>(timefuncs::stringTimeToUnix(startDate, "%Y-%m-%d")) * 1000;
        int64_t unixEndDate;
        if (endDate.length() > 0)
        {
            unixEndDate = static_cast<int64_t>(timefuncs::stringTimeToUnix(endDate, "%Y-%m-%d")) * 1000;
        }

        std::string path = "/pricehistory?symbol=" + symbol + "&periodType=" + priceHistoryPeriodMap.at(periodType) +
                           "&period=" + std::to_string(periodAmount) +
                           "&frequencyType=" + priceHistoryTimeFreqMap.at(timeFreq) +
                           "&frequency=" + std::to_string(freqAmount) + "&startDate=" + std::to_string(unixStartDate);

        if (endDate.length() > 0)
        {
            path += "&endDate=" + std::to_string(unixEndDate);
        }

        path += "&needExtendedHoursData=" + booleanString.at(extendedHours) +
                "&needPreviousClose=" + booleanString.at(needPreviousClose);

        if (!checkAccessToken())
        {
            updateAccessToken(config->getRefreshToken().token);
        }
        setMarketDataEndpoint();
        auto resp = restClient->getResponse(path, headers());
        auto errorResp = checkErrors(resp);
        if (errorResp.errors.size() > 0)
        {
            logErrorResponse(errorResp);
            return {};
        }
        PriceHistory priceHistory = parsePriceHistory(resp);
        infologprint(logfile, "%s: received %lu candles", __func__, priceHistory.candles.size());
        return priceHistory;
    }
    catch (std::exception& e)
    {
        infologprint(logfile, "%s: caught exception: %s", __func__, e.what());
        return {};
    }
}

PriceHistory SchwabClient::getPriceHistory(std::string symbol, PriceHistoryPeriodType periodType, unsigned periodAmount,
    PriceHistoryTimeFreq timeFreq, unsigned freqAmount, uint64_t startDate, uint64_t endDate, bool extendedHours,
    bool needPreviousClose)
{
    try
    {
        infologprint(logfile,
            "%s: request price history for: symbol=%s, periodType=%d, periodAmount=%u, timeFreq=%d,"
            "freqAmount=%u, startDate=%lu, endDate=%lu, extendedHours=%d, needPreviousClose=%d",
            __func__, symbol.c_str(), static_cast<int>(periodType), periodAmount, static_cast<int>(timeFreq),
            freqAmount, startDate, endDate, extendedHours, needPreviousClose);

        std::string path = "/pricehistory?symbol=" + symbol + "&periodType=" + priceHistoryPeriodMap.at(periodType) +
                           "&period=" + std::to_string(periodAmount) +
                           "&frequencyType=" + priceHistoryTimeFreqMap.at(timeFreq) +
                           "&frequency=" + std::to_string(freqAmount) + "&startDate=" + std::to_string(startDate);

        path += "&endDate=" + std::to_string(endDate);

        path += "&needExtendedHoursData=" + booleanString.at(extendedHours) +
                "&needPreviousClose=" + booleanString.at(needPreviousClose);

        if (!checkAccessToken())
        {
            updateAccessToken(config->getRefreshToken().token);
        }
        setMarketDataEndpoint();
        auto resp = restClient->getResponse(path, headers());
        auto errorResp = checkErrors(resp);
        if (errorResp.errors.size() > 0)
        {
            logErrorResponse(errorResp);
            return {};
        }
        PriceHistory priceHistory = parsePriceHistory(resp);
        infologprint(logfile, "%s: received %lu candles, latest timestamp: %lu", __func__, priceHistory.candles.size(),
            priceHistory.candles.back().datetime);
        return priceHistory;
    }
    catch (std::exception& e)
    {
        infologprint(logfile, "%s: caught exception: %s", __func__, e.what());
        return {};
    }
}

// TODO: add UT for this
std::vector<AccountNumbers> SchwabClient::getAccountNumbers()
{
    try
    {
        infologprint(logfile, "%s: requesting account numbers", __func__);

        std::string path = "/accounts/accountNumbers";
        if (!checkAccessToken())
        {
            updateAccessToken(config->getRefreshToken().token);
        }
        setAccountsEndpoint();
        auto resp = restClient->getResponse(path, headers());
        auto errorResp = checkErrors(resp);
        if (errorResp.errors.size() > 0)
        {
            logErrorResponse(errorResp);
            return {};
        }
        return {};
    }
    catch (const std::exception& e)
    {
        infologprint(logfile, "%s: caught exception: %s", __func__, e.what());
        return {};
    }
}

// TODO: add UT for this
UserPreferences SchwabClient::getUserPreferences()
{
    try
    {
        infologprint(logfile, "%s: requesting user preferences", __func__);

        std::string path = "/userPreference";
        if (!checkAccessToken())
        {
            updateAccessToken(config->getRefreshToken().token);
        }
        setAccountsEndpoint();
        auto resp = restClient->getResponse(path, headers());
        auto errorResp = checkErrors(resp);
        auto preferences = parseUserPreferences(resp);
        if (errorResp.errors.size() > 0)
        {
            logErrorResponse(errorResp);
            return {};
        }
        return preferences;
    }
    catch (const std::exception& e)
    {
        infologprint(logfile, "%s: caught exception: %s", __func__, e.what());
        return {};
    }
}
#if 0
//https://api.schwabapi.com/marketdata/v1
// /markets?markets=equity&markets=option&markets=bond&markets=future&markets=forex&date=2024-06-04
std::vector<MarketHours> SchwabClient::getMarketHours(std::set<MarketType> marketType, std::string date)
{
    try
    {
        infologprint(logfile, "%s: requesting market hours for: %s, date: %s", __func__, marketTypeMap.at(marketType),
            date.c_str());

        std::string path = "/markets?";
        for(const auto& market : marketType)
        {
            path += "markets=" + marketTypeToStringMap.at(market) + "&";
        }
        path += "date=" + date;

        if (!checkAccessToken())
        {
            updateAccessToken(config->getRefreshToken().token);
        }
        setMarketDataEndpoint();
        auto resp = restClient->getResponse(path, headers());
        auto errorResp = checkErrors(resp);
        if (errorResp.errors.size() > 0)
        {
            logErrorResponse(errorResp);
            return {};
        }
        return parseMarketHours(resp);
    }
    catch (const std::exception& e)
    {
        infologprint(logfile, "%s: caught exception: %s", __func__, e.what());
        return {};
    }
}
#endif
} // namespace restclient