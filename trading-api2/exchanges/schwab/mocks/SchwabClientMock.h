##pragma once

#include "SchwabClient.h"

#include <gmock/gmock.h>

    class SchwabClientMock : public ISchwabClient
{
    MOCK_METHOD2(createAccessToken, bool(std::string, bool));
    MOCK_METHOD2(getEquityQuotes, std::map<std::string, QuoteEquityResponse>(std::set<std::string>));
    MOCK_METHOD2(getOptionChain, OptionChain(std::string symbol, unsigned));
    MOCK_METHOD1(getOptionExpirations, std::vector<OptionExpiration>(std::string));
    MOCK_METHOD9(getPriceHistory, PriceHistory(std::string, PriceHistoryPeriodType, unsigned, PriceHistoryTimeFreq,
                                      unsigned, std::string, std::string, bool, bool));
    MOCK_METHOD0(checkAccessToken, bool());
};