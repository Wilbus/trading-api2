#include "SchwabClient.h"

#include "SchwabMarketDataParser.h"
#include "UriEncodeDecode.h"
#include "timefuncs.h"

SchwabClient::SchwabClient(SchwabAuth auths, std::shared_ptr<IRestClient> restClient)
    : auths(auths)
    , restClient(restClient)
{
}

httplib::Headers SchwabClient::headers() const
{
    //clang-format off
    std::string bearer = "Bearer IO." + auths.token;
    return {{"Accept", "application/json"}, {"Authorization", bearer.c_str()}};
    //clang-format on
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
    std::string path =
        "/chains?symbol=" + symbol + "&contractType=ALL&strikeCount=" + std::to_string(strikesCount) + "&strategy=SINGLE";
    try
    {
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

        auto resp = restClient->getResponse(path, headers());
        return parsePriceHistory(resp);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n";
        return {};
    }
}