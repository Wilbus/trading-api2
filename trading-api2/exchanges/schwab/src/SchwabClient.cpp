#include "SchwabClient.h"

#include "SchwabAccountDataParser.h"
#include "SchwabMarketDataParser.h"
#include "SystemTimer.h"
#include "UriEncodeDecode.h"
#include "timefuncs.h"

using namespace std::chrono;

SchwabClient::SchwabClient(std::shared_ptr<ISchwabConfigs> config, std::shared_ptr<IRestClient> restClient)
    : config(config)
    , restClient(restClient)
{
}

httplib::Headers SchwabClient::headers() const
{
    //clang-format off
    std::string bearer = "Bearer IO." + config->getAuthorizationCode().code;
    return {{"Accept", "application/json"}, {"Authorization", bearer.c_str()}};
    //clang-format on
}

void SchwabClient::setMarketDataEndpoint()
{
    restClient->setBaseEndpoint("https://api.schwabapi.com/marketdata/v1");
}

void SchwabClient::setAuthenticationEndpoint()
{
    restClient->setBaseEndpoint("https://api.schwabapi.com/v1");
}

void SchwabClient::setAccountsEndpoint()
{
    restClient->setBaseEndpoint("https://api.schwabapi.com/trader/v1");
}

bool SchwabClient::checkAccessToken()
{
    auto nowMs = utils::nowMs();
    auto accessToken = config->getAccessToken();
    return nowMs < accessToken.expires_at_time;
}

/*
curl -X POST \https://api.schwabapi.com/v1/oauth/token
\-H 'Authorization: Basic {BASE64_ENCODED_Client_ID:Client_Secret}
\-H 'Content-Type: application/x-www-form-urlencoded'
\-d
'grant_type=authorization_code&code={AUTHORIZATION_CODE_VALUE}&redirect_uri=https://example_url.com/callback_example'
*/
/*
    If isRefreshToken == true, passs the refresh token to update the current access token,
    otherwise pass the authorization code to retrieve a new refresh token
*/
void SchwabClient::createAccessToken(std::string authCodeOrRefreshToken, bool isRefreshToken)
{
    std::string path = "/oauth/token";
    std::string content_type = "application/x-www-form-urlencoded";

    std::string authorization_code_header = "Basic " + config->getAppSecret();
    httplib::Headers headers = {{"Authorization: ", authorization_code_header}, {"Content-Type: ", content_type}};

    std::string body;
    if (!isRefreshToken)
        body = "grant_type=authorization_code&code=" + authCodeOrRefreshToken +
               "&redirect_uri=" + config->getRedirectUri();
    else
        body = "grant_type=refresh_token&refresh_token=" + authCodeOrRefreshToken;

    try
    {
        setAuthenticationEndpoint();
        auto resp = restClient->postResponse(path, headers, body, "application/x-www-form-urlencoded");
        auto authTokens = parseAuthTokens(resp);

        if (!isRefreshToken)
        {
            Token accessToken;
            accessToken.token = authTokens.access_token;
            accessToken.granted_at_time = utils::nowMs();
            accessToken.expires_at_time = accessToken.granted_at_time + authTokens.expires_in;
            config->saveAccessToken(accessToken);
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}

//'https://api.schwabapi.com/marketdata/v1/quotes?symbols=SPY%2C%20AAPL&fields=quote%2Creference&indicative=true'
std::map<std::string, QuoteEquityResponse> SchwabClient::getEquityQuotes(std::set<std::string> symbols)
{
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
            createAccessToken(config->getRefreshToken().token, false);
        }
        setMarketDataEndpoint();
        auto resp = restClient->getResponse(path, headers());
        auto quotesmap = parseEquityQuotes(symbols, resp);
        return quotesmap;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n";
        return {};
    }
}

//'https://api.schwabapi.com/marketdata/v1/chains?symbol=AAPL&contractType=ALL&strikeCount=5&strategy=SINGLE'
OptionChain SchwabClient::getOptionChain(std::string symbol, unsigned strikesCount)
{
    std::string path = "/chains?symbol=" + symbol + "&contractType=ALL&strikeCount=" + std::to_string(strikesCount) +
                       "&strategy=SINGLE";
    try
    {
        if (!checkAccessToken())
        {
            createAccessToken(config->getRefreshToken().token, false);
        }
        setMarketDataEndpoint();
        auto resp = restClient->getResponse(path, headers());
        return parseOptionChain(resp);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
        return {};
    }
}

//'https://api.schwabapi.com/marketdata/v1/expirationchain?symbol=AAPL'
std::vector<OptionExpiration> SchwabClient::getOptionExpirations(std::string symbol)
{
    try
    {
        if (!checkAccessToken())
        {
            createAccessToken(config->getRefreshToken().token, false);
        }
        setMarketDataEndpoint();
        std::string path = "?symbol=" + symbol;
        auto resp = restClient->getResponse(path, headers());
        return parseOptionExpirations(resp);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
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
            createAccessToken(config->getRefreshToken().token, false);
        }
        setMarketDataEndpoint();
        auto resp = restClient->getResponse(path, headers());
        return parsePriceHistory(resp);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n";
        return {};
    }
}