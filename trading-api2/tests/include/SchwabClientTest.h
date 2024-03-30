#include "RestClientMock.h"
#include "SchwabClient.h"
#include "schwabtestvalues.h"
#include "schwabOptionsTestValues.h"

#include <gtest/gtest.h>

using namespace utils;
using namespace schwabMarketData;

class SchwabClientTest : public ::testing::Test
{
public:
    SchwabClientTest()
    {
        restClientMock = std::make_shared<RestClientMock>();
        client = std::make_shared<SchwabClient>(createSchwabAuthStub(), restClientMock);
    }

    SchwabAuth createSchwabAuthStub()
    {
        SchwabAuth auths;
        auths.appkey = "appkey123";
        auths.appsecret = "appsecret123";
        auths.token = "authtoken123";
        return auths;
    }

    httplib::Headers expectedHeaders()
    {
        return {{"Accept", "application/json"}, {"Authorization", "Bearer IO.authtoken123"}};
    }

protected:
    std::shared_ptr<RestClientMock> restClientMock;
    std::shared_ptr<SchwabClient> client;
};

TEST_F(SchwabClientTest, getQuotesCaughtException)
{
    std::set<std::string> symbols = {"SPY", "AAPL"};
    std::string path = R"(?symbols=AAPL%2CSPY&fields=quote&indicative=false)";

    EXPECT_CALL(*restClientMock.get(), getResponse(path, expectedHeaders())).WillOnce(Throw(std::runtime_error("")));
    auto quotesmap = client->getEquityQuotes(symbols);
    EXPECT_EQ(quotesmap.size(), 0);
}

TEST_F(SchwabClientTest, getQuotes)
{
    std::set<std::string> symbols = {"SPY", "AAPL"};
    std::string path = R"(?symbols=AAPL%2CSPY&fields=quote&indicative=false)";

    EXPECT_CALL(*restClientMock.get(), getResponse(path, expectedHeaders())).WillOnce(Return(multiEquityQuotesExample));
    auto quotesmap = client->getEquityQuotes(symbols);
}

TEST_F(SchwabClientTest, getOptionExpirationsCaughtException)
{
    std::string expectedPath = "?symbol=AAPL";
    EXPECT_CALL(*restClientMock.get(), getResponse(expectedPath, expectedHeaders()))
        .WillOnce(Throw(std::runtime_error("")));
    auto expirations = client->getOptionExpirations("AAPL");
    EXPECT_EQ(expirations.size(), 0);
}

TEST_F(SchwabClientTest, getOptionExpirations)
{
    std::string expectedPath = "?symbol=AAPL";
    EXPECT_CALL(*restClientMock.get(), getResponse(expectedPath, expectedHeaders()))
        .WillOnce(Return(expirationListExample));
    auto expirations = client->getOptionExpirations("AAPL");
    EXPECT_GT(expirations.size(), 0);
}

TEST_F(SchwabClientTest, getPriceHistoryCaughtException)
{
    /*'https://api.schwabapi.com/marketdata/v1/pricehistory?symbol=SPY&periodType=year&period=1&frequencyType=daily&frequency=1&startDate=1710954774000&needExtendedHoursData=true&needPreviousClose=true'*/
    std::string expectedPath = "?symbol=SPY&periodType=year&period=1&frequencyType=daily&frequency=1&startDate="
                               "1710914400000&needExtendedHoursData=true&needPreviousClose=true";

    EXPECT_CALL(*restClientMock.get(), getResponse(expectedPath, expectedHeaders()))
        .WillOnce(Throw(std::runtime_error("")));
    auto priceHistory = client->getPriceHistory(
        "SPY", PriceHistoryPeriodType::YEAR, 1, PriceHistoryTimeFreq::DAILY, 1, "2024-03-20", "", true, true);
    EXPECT_EQ(priceHistory.candles.size(), 0);
}

TEST_F(SchwabClientTest, getPriceHistoryNoEndDate)
{
    /*'https://api.schwabapi.com/marketdata/v1/pricehistory?symbol=SPY&periodType=year&period=1&frequencyType=daily&frequency=1&startDate=1710954774000&needExtendedHoursData=true&needPreviousClose=true'*/
    std::string expectedPath = "?symbol=SPY&periodType=year&period=1&frequencyType=daily&frequency=1&startDate="
                               "1710914400000&needExtendedHoursData=true&needPreviousClose=true";

    EXPECT_CALL(*restClientMock.get(), getResponse(expectedPath, expectedHeaders()))
        .WillOnce(Return(mockGetPriceHistoryResp));
    auto priceHistory = client->getPriceHistory(
        "SPY", PriceHistoryPeriodType::YEAR, 1, PriceHistoryTimeFreq::DAILY, 1, "2024-03-20", "", true, true);
    EXPECT_EQ(priceHistory.candles.size(), 7);
}

TEST_F(SchwabClientTest, getPriceHistoryStartAndEndDates)
{
    std::string expectedPath = "?symbol=SPY&periodType=year&period=1&frequencyType=daily&frequency=1&startDate="
                               "1710914400000&endDate=1711778400000&needExtendedHoursData=true&needPreviousClose=true";

    EXPECT_CALL(*restClientMock.get(), getResponse(expectedPath, expectedHeaders()))
        .WillOnce(Return(mockGetPriceHistoryResp));
    auto priceHistory = client->getPriceHistory(
        "SPY", PriceHistoryPeriodType::YEAR, 1, PriceHistoryTimeFreq::DAILY, 1, "2024-03-20", "2024-03-30", true, true);
    EXPECT_EQ(priceHistory.candles.size(), 7);
}

TEST_F(SchwabClientTest, getPriceHistoryStartAndEndDatesMinutes)
{
    std::string expectedPath = "?symbol=AAPL&periodType=day&period=10&frequencyType=minute&frequency=30&startDate="
                               "1710914400000&needExtendedHoursData=true&needPreviousClose=true";

    EXPECT_CALL(*restClientMock.get(), getResponse(expectedPath, expectedHeaders()))
        .WillOnce(Return(mockGetPriceHistoryResp));
    auto priceHistory = client->getPriceHistory(
        "AAPL", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 30, "2024-03-20", "", true, true);
    EXPECT_GT(priceHistory.candles.size(), 0);
}

TEST_F(SchwabClientTest, getOptionChainCaughtException)
{
    std::string expectedPath = "?symbol=AAPL&contractType=ALL&strikeCount=5&strategy=SINGLE";
    EXPECT_CALL(*restClientMock.get(), getResponse(expectedPath, expectedHeaders()))
        .WillOnce(Throw(std::runtime_error("")));
    auto optionChain = client->getOptionChain("AAPL", 5);
    EXPECT_EQ(optionChain.callExpDateMap.size(), 0);
    EXPECT_EQ(optionChain.putExpDateMap.size(), 0);
}

TEST_F(SchwabClientTest, getOptionChain)
{
    std::string expectedPath = "?symbol=AAPL&contractType=ALL&strikeCount=5&strategy=SINGLE";
    EXPECT_CALL(*restClientMock.get(), getResponse(expectedPath, expectedHeaders()))
        .WillOnce(Return(schwabOptionsExample_ALL_5Strikes));
    auto optionChain = client->getOptionChain("AAPL", 5);
    EXPECT_GT(optionChain.callExpDateMap.size(), 0);
    EXPECT_GT(optionChain.putExpDateMap.size(), 0);
}