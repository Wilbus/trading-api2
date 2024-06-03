#pragma once

#include "SchwabClient.h"

#include <gmock/gmock.h>

class SchwabClientMock : public ISchwabClient
{
public:
    MOCK_METHOD1(createAccessToken, bool(std::string));
    MOCK_METHOD1(updateAccessToken, bool(std::string));
    MOCK_METHOD1(getEquityQuotes, std::map<std::string, QuoteEquityResponse>(std::set<std::string>));
    MOCK_METHOD2(getOptionChain, OptionChain(std::string symbol, unsigned));
    MOCK_METHOD1(getOptionExpirations, std::vector<OptionExpiration>(std::string));
    MOCK_METHOD9(getPriceHistory, PriceHistory(std::string, PriceHistoryPeriodType, unsigned, PriceHistoryTimeFreq,
                                      unsigned, std::string, std::string, bool, bool));
    MOCK_METHOD9(getPriceHistory, PriceHistory(std::string, PriceHistoryPeriodType, unsigned, PriceHistoryTimeFreq,
                                      unsigned, uint64_t, uint64_t, bool, bool));
    MOCK_METHOD0(checkAccessToken, bool());
    MOCK_METHOD0(getAccountNumbers, std::vector<AccountNumbers>());
    MOCK_METHOD0(getUserPreferences, UserPreferences());
};