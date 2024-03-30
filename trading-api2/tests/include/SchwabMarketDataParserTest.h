#include "SchwabMarketDataParser.h"
#include "schwabOptionsTestValues.h"
#include "schwabtestvalues.h"

#include <gtest/gtest.h>

using namespace utils;
using namespace schwabMarketData;

class SchwabMarketDataParserTest : public ::testing::Test
{
public:
    SchwabMarketDataParserTest()
    {
    }

protected:
};

/*too lazy to create whole separate struct to check equality against, if the parse function
    doesn't error out or crash then its a good chance its working correctly*/
TEST_F(SchwabMarketDataParserTest, parseEquityQuotesTest)
{
    auto quotes = schwabMarketData::parseEquityQuotes({"SPY", "AAPL"}, multiEquityQuotesExample);

    auto spyquote = quotes.at("SPY");
    EXPECT_EQ(spyquote.assetMainType, AssetMainType::EQUITY);
    EXPECT_EQ(spyquote.assetSubType, AssetSubType::ETF);
    EXPECT_EQ(spyquote.ssid, 1281357639);
    EXPECT_EQ(spyquote.symbol, "SPY");
    EXPECT_EQ(spyquote.quote.askPrice, 523.07);

    auto aaplquote = quotes.at("AAPL");
    EXPECT_EQ(aaplquote.quote.askPrice, 171.22);
}

TEST_F(SchwabMarketDataParserTest, parsePriceHistoryTest)
{
    auto priceHistory = schwabMarketData::parsePriceHistory(examplePriceHistory);

    EXPECT_EQ(priceHistory.symbol, "AAPL");
    EXPECT_EQ(priceHistory.candles[0].datetime, 1639137600000);
    EXPECT_EQ(priceHistory.candles[6].datetime, 1640307540000);
}

TEST_F(SchwabMarketDataParserTest, parseOptionsExpirations)
{
    auto exps = schwabMarketData::parseOptionExpirations(expirationListExample);

    EXPECT_EQ(exps.size(), 18);
    EXPECT_EQ(exps[17].expirationDate, "2024-01-19");
}

TEST_F(SchwabMarketDataParserTest, parseOptionChainNoThrow)
{
    EXPECT_NO_THROW(schwabMarketData::parseOptionChain(schwabOptionsExample_ALL_5Strikes));
}

TEST_F(SchwabMarketDataParserTest, parseOptionChainCheckValues)
{
    OptionChain optionChain = schwabMarketData::parseOptionChain(schwabOptionsExample_ALL_5Strikes);
    EXPECT_GT(optionChain.callExpDateMap.size(), 0);
    EXPECT_GT(optionChain.putExpDateMap.size(), 0);
    EXPECT_EQ(optionChain.symbol, "AAPL");
    EXPECT_EQ(optionChain.status, "SUCCESS");
    EXPECT_EQ(optionChain.strategy, OptionStrategy::SINGLE);
    EXPECT_EQ(optionChain.interestRate, 4.738);

    std::vector<double> strikes0{167.5, 170, 172.5, 175, 177.5};
    std::vector<double> strikes1{165, 170, 175, 180, 185};

    unsigned expCounts = 0;

    for(const auto& [expdate, callStrikes]: optionChain.callExpDateMap)
    {
        unsigned strikes0Count = 0;
        unsigned strikes1Count = 0;
        for(const auto& option: callStrikes)
        {
            if(expCounts < 3)
                EXPECT_EQ(option.strikePrice, strikes0[strikes0Count++]);
            else
                EXPECT_EQ(option.strikePrice, strikes1[strikes1Count++]);

            EXPECT_NE(option.bidPrice, MAXDOUBLE);
            EXPECT_NE(option.askPrice, MAXDOUBLE);
            EXPECT_NE(option.lastPrice, MAXDOUBLE);
            EXPECT_NE(option.markPrice, MAXDOUBLE);
            EXPECT_NE(option.bidSize, MAXDOUBLE);
            EXPECT_NE(option.askSize, MAXDOUBLE);
            EXPECT_NE(option.bidAskSize.length(), 0);
            EXPECT_NE(option.lastSize, MAXDOUBLE);
            EXPECT_NE(option.highPrice, MAXDOUBLE);
            EXPECT_NE(option.lowPrice, MAXDOUBLE);
            EXPECT_NE(option.closePrice, MAXDOUBLE);
            EXPECT_NE(option.totalVolume, MAXULONG);
            EXPECT_NE(option.quoteTimeInLong, MAXULONG);
            EXPECT_NE(option.tradeTimeInlong, MAXULONG);
            EXPECT_NE(option.netChange, MAXDOUBLE);
            EXPECT_NE(option.volatility, MAXDOUBLE);
            EXPECT_NE(option.delta, MAXDOUBLE);
            EXPECT_NE(option.gamma, MAXDOUBLE);
            EXPECT_NE(option.theta, MAXDOUBLE);
            EXPECT_NE(option.vega, MAXDOUBLE);
            EXPECT_NE(option.rho, MAXDOUBLE);
            EXPECT_NE(option.openInterest, MAXDOUBLE);
            EXPECT_NE(option.timeValue, MAXDOUBLE);
            EXPECT_NE(option.theoreticalOptionValue, MAXDOUBLE);
            EXPECT_NE(option.theoreticalVolatility, MAXDOUBLE);
            EXPECT_NE(option.expirationDate.length(), 0);
            EXPECT_NE(option.daysToExpiration, MAXUNSIGNED);
            EXPECT_NE(option.expirationType.length(), 0);
            EXPECT_NE(option.lastTradingDay, MAXULONG);
            EXPECT_NE(option.multiplier, MAXDOUBLE);
            EXPECT_NE(option.percentChange, MAXDOUBLE);
            EXPECT_NE(option.markChange, MAXDOUBLE);
            EXPECT_NE(option.markPercentChange, MAXDOUBLE);
            EXPECT_NE(option.intrinsicValue, MAXDOUBLE);
            EXPECT_NE(option.extrinsicValue, MAXDOUBLE);
            EXPECT_NE(option.optionRoot.length(), 0);
            EXPECT_NE(option.high52Week, MAXDOUBLE);
            EXPECT_NE(option.low52Week, MAXDOUBLE);
        }
        expCounts++;
    }

    expCounts = 0;
    for(const auto& [expdate, putStrikes]: optionChain.putExpDateMap)
    {
        unsigned strikes0Count = 0;
        unsigned strikes1Count = 0;
        for(const auto& option: putStrikes)
        {
            if(expCounts < 3)
                EXPECT_EQ(option.strikePrice, strikes0[strikes0Count++]);
            else
                EXPECT_EQ(option.strikePrice, strikes1[strikes1Count++]);

            EXPECT_NE(option.bidPrice, MAXDOUBLE);
            EXPECT_NE(option.askPrice, MAXDOUBLE);
            EXPECT_NE(option.lastPrice, MAXDOUBLE);
            EXPECT_NE(option.markPrice, MAXDOUBLE);
            EXPECT_NE(option.bidSize, MAXDOUBLE);
            EXPECT_NE(option.askSize, MAXDOUBLE);
            EXPECT_NE(option.bidAskSize.length(), 0);
            EXPECT_NE(option.lastSize, MAXDOUBLE);
            EXPECT_NE(option.highPrice, MAXDOUBLE);
            EXPECT_NE(option.lowPrice, MAXDOUBLE);
            EXPECT_NE(option.closePrice, MAXDOUBLE);
            EXPECT_NE(option.totalVolume, MAXULONG);
            EXPECT_NE(option.quoteTimeInLong, MAXULONG);
            EXPECT_NE(option.tradeTimeInlong, MAXULONG);
            EXPECT_NE(option.netChange, MAXDOUBLE);
            EXPECT_NE(option.volatility, MAXDOUBLE);
            EXPECT_NE(option.delta, MAXDOUBLE);
            EXPECT_NE(option.gamma, MAXDOUBLE);
            EXPECT_NE(option.theta, MAXDOUBLE);
            EXPECT_NE(option.vega, MAXDOUBLE);
            EXPECT_NE(option.rho, MAXDOUBLE);
            EXPECT_NE(option.openInterest, MAXDOUBLE);
            EXPECT_NE(option.timeValue, MAXDOUBLE);
            EXPECT_NE(option.theoreticalOptionValue, MAXDOUBLE);
            EXPECT_NE(option.theoreticalVolatility, MAXDOUBLE);
            EXPECT_NE(option.expirationDate.length(), 0);
            EXPECT_NE(option.daysToExpiration, MAXUNSIGNED);
            EXPECT_NE(option.expirationType.length(), 0);
            EXPECT_NE(option.lastTradingDay, MAXULONG);
            EXPECT_NE(option.multiplier, MAXDOUBLE);
            EXPECT_NE(option.percentChange, MAXDOUBLE);
            EXPECT_NE(option.markChange, MAXDOUBLE);
            EXPECT_NE(option.markPercentChange, MAXDOUBLE);
            EXPECT_NE(option.intrinsicValue, MAXDOUBLE);
            EXPECT_NE(option.extrinsicValue, MAXDOUBLE);
            EXPECT_NE(option.optionRoot.length(), 0);
            EXPECT_NE(option.high52Week, MAXDOUBLE);
            EXPECT_NE(option.low52Week, MAXDOUBLE);
        }
        expCounts++;
    }
}