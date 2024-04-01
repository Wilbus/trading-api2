
#pragma once

#include "IRestClient.h"
#include "SchwabAccountDataTypes.h"
#include "SchwabMarketDataTypes.h"
#include "SchwabConfigs.h"

using namespace restclient;
using namespace schwabMarketData;
using namespace schwabAccountData;

enum PriceHistoryPeriodType : uint8_t
{
    DAY,   // valid period amounts 1,2,3,4,5,10. default 10
    MONTH, // valid period amounts 1,2,3,6. default 1
    YEAR,  // valid period amounts 1,2,3,5,10,15,20. default 1
    YTD    // valid period amounts 1. default 1
};

enum PriceHistoryTimeFreq : uint8_t
{
    MINUTE, // valid freq amounts 1,5,10,15,30, default 1
    DAILY,  // valid freq amounts 1, default 1
    WEEKLY, // valid freq amounts 1, default 1
    MONTHLY // valid freq amounts 1, default 1
};

// clang-format off
const std::map<PriceHistoryPeriodType, std::string> priceHistoryPeriodMap = 
{
    {PriceHistoryPeriodType::DAY, "day"},
    {PriceHistoryPeriodType::MONTH, "month"},
    {PriceHistoryPeriodType::YEAR, "year"},
    {PriceHistoryPeriodType::YTD, "ytd"},
};

const std::map<PriceHistoryTimeFreq, std::string> priceHistoryTimeFreqMap = 
{
    {PriceHistoryTimeFreq::MINUTE, "minute"},
    {PriceHistoryTimeFreq::DAILY, "daily"},
    {PriceHistoryTimeFreq::WEEKLY, "weekly"},
    {PriceHistoryTimeFreq::MONTHLY, "monthly"}
};

const std::map<bool, std::string> booleanString =
{
    {false, "false"},
    {true, "true"}  
};
// clang-format on

class ISchwabClient
{
};

class SchwabClient : public ISchwabClient
{
public:
    SchwabClient(std::shared_ptr<ISchwabConfigs> config, std::shared_ptr<IRestClient> restClient);

    AuthTokens createAccessToken(std::string authCodeOrRefreshToken, bool isRefreshToken);
    
    std::map<std::string, QuoteEquityResponse> getEquityQuotes(std::set<std::string> symbols);

    OptionChain getOptionChain(std::string symbol, unsigned strikesCount);
    std::vector<OptionExpiration> getOptionExpirations(std::string symbol);

    /*startDate format yyyy-MM-dd
      endDate format yyyy-MM-dd */
    PriceHistory getPriceHistory(std::string symbol, PriceHistoryPeriodType periodType, unsigned periodAmount,
        PriceHistoryTimeFreq timeFreq, unsigned freqAmount, std::string startDate, std::string endDate,
        bool extendedHours = false, bool needPreviousClose = false);

    void timertest();

private:
    httplib::Headers headers() const;
    SchwabAuth auths;
    std::shared_ptr<ISchwabConfigs> config;
    std::shared_ptr<IRestClient> restClient;
};