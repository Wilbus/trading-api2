#pragma once

#include "RestClientCurl.h"
#include "SchwabClient.h"

#include <gtest/gtest.h>

class SchwabEndpointsTest : public ::testing::Test
{
public:
    SchwabEndpointsTest()
    {
        restclient = std::make_shared<RestClientCurl>("/datadisk0/sambashare0/coding/trading-api2-endpoint-test-logs/");

        configs = std::make_shared<SchwabConfigs>("/datadisk0/sambashare0/coding/configs/");
        sclient = std::make_shared<SchwabClient>(configs, restclient);
    }

    std::shared_ptr<RestClientCurl> restclient;
    std::shared_ptr<SchwabConfigs> configs;
    std::shared_ptr<SchwabClient> sclient;
};

TEST_F(SchwabEndpointsTest, GetQuotes)
{
    auto quotes = sclient->getEquityQuotes(std::set<std::string>{"SPY", "AAPL", "MSFT", "QQQ", "CAVA"});
    // auto quotes = sclient->getEquityQuotes(std::set<std::string>{"SPY", "AAPL", "MSFT", "QQQ"});
    EXPECT_EQ(quotes.size(), 5);
}

TEST_F(SchwabEndpointsTest, GetOptionChain)
{
    auto optionchain = sclient->getOptionChain("SPY", 10);
    for (const auto& [expdate, strikeschain] : optionchain.callExpDateMap)
    {
        EXPECT_EQ(strikeschain.size(), 10);
    }
    for (const auto& [expdate, strikeschain] : optionchain.putExpDateMap)
    {
        EXPECT_EQ(strikeschain.size(), 10);
    }
}

TEST_F(SchwabEndpointsTest, GetOptionExpirations)
{
    auto expirations = sclient->getOptionExpirations("SPY");
    EXPECT_GT(expirations.size(), 0);
}

TEST_F(SchwabEndpointsTest, GetPriceHistory)
{
    auto priceHistory = sclient->getPriceHistory(
        "SPY", PriceHistoryPeriodType::YEAR, 1, PriceHistoryTimeFreq::DAILY, 1, "2024-03-20", "", true, true);
    EXPECT_GT(priceHistory.candles.size(), 0);
}

TEST_F(SchwabEndpointsTest, GetAccountNumbers)
{
    auto accountNmbers = sclient->getAccountNumbers();
    // EXPECT_GT(priceHistory.candles.size(), 0);
}

TEST_F(SchwabEndpointsTest, GetUserPreferences)
{
    auto prefs = sclient->getUserPreferences();
    EXPECT_GT(prefs.accounts.size(), 0);
    EXPECT_GT(prefs.streamerInfo.size(), 0);
}