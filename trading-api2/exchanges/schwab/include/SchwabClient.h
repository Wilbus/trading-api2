
#pragma once

#include "IRestClientCurl.h"
#include "SchwabAccountDataTypes.h"
#include "SchwabConfigs.h"
#include "SchwabErrorDataTypes.h"
#include "SchwabMarketDataTypes.h"

#include <memory>

using namespace restclient;
using namespace schwabMarketData;
using namespace schwabAccountData;
using namespace schwabErrors;

namespace restclient {

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
    virtual bool createAccessToken(std::string authorizationCode) = 0;
    virtual bool updateAccessToken(std::string refreshToken) = 0;

    virtual std::map<std::string, QuoteEquityResponse> getEquityQuotes(std::set<std::string> symbols) = 0;

    virtual OptionChain getOptionChain(std::string symbol, unsigned strikesCount) = 0;

    virtual std::vector<OptionExpiration> getOptionExpirations(std::string symbol) = 0;

    virtual PriceHistory getPriceHistory(std::string symbol, PriceHistoryPeriodType periodType, unsigned periodAmount,
        PriceHistoryTimeFreq timeFreq, unsigned freqAmount, std::string startDate, std::string endDate,
        bool extendedHours = false, bool needPreviousClose = false) = 0;

    virtual std::vector<AccountNumbers> getAccountNumbers() = 0;
    virtual UserPreference getUserPreference() = 0;

    virtual bool checkAccessToken() = 0;
};

class SchwabClient : public ISchwabClient
{
public:
    SchwabClient(std::shared_ptr<ISchwabConfigs> config, std::shared_ptr<IRestClientCurl> restClient);

    /*
        AuthorizationCode: The code returned from the redirect url login
        RefreshToken: expires every 7 days. Retrieved by creating an access token with the AuthorizationCode.
            Use this to refresh the AccessToken
        AccessToken: expires every 30 minutes.
    */
    virtual bool createAccessToken(std::string authorizationCode) override;
    virtual bool updateAccessToken(std::string refreshToken) override;

    virtual std::map<std::string, QuoteEquityResponse> getEquityQuotes(std::set<std::string> symbols) override;

    virtual OptionChain getOptionChain(std::string symbol, unsigned strikesCount) override;
    std::vector<OptionExpiration> getOptionExpirations(std::string symbol) override;

    /*startDate format yyyy-MM-dd
      endDate format yyyy-MM-dd */
    virtual PriceHistory getPriceHistory(std::string symbol, PriceHistoryPeriodType periodType, unsigned periodAmount,
        PriceHistoryTimeFreq timeFreq, unsigned freqAmount, std::string startDate, std::string endDate,
        bool extendedHours = false, bool needPreviousClose = false) override;

    virtual std::vector<AccountNumbers> getAccountNumbers() override;
    virtual UserPreference getUserPreference() override;

    virtual bool checkAccessToken() override;

private:
    std::set<std::string> headers() const;
    void setMarketDataEndpoint();
    void setAuthenticationEndpoint();
    void setAccountsEndpoint();
    void logErrorResponse(ErrorResponse resp);
    SchwabAuth auths;
    std::shared_ptr<ISchwabConfigs> config;
    std::shared_ptr<IRestClientCurl> restClient;
};

} // namespace restclient