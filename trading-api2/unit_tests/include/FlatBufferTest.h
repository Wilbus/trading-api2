#pragma once

#include "CandleStick.h"
#include "FlatbufferReader.h"
#include "schwab_auth_generated.h"
#include "schwab_candlelist_generated.h"
#include "schwabtestvalues.h"

#include <gtest/gtest.h>

/*
Here is test code for parsing API responses using flatbuffers from various exchanges
*/

using namespace utils;

class FlatBufferTest : public ::testing::Test
{
public:
    FlatBufferTest()
    {
    }

protected:
};

TEST_F(FlatBufferTest, SchwabAuthConfTest)
{
    FlatBufferReader<schwabAuthentication::Auths> reader(
        "/datadisk0/sambashare0/coding/trading-api2/trading-api2/tests/testfiles/schwabauthtest.json",
        "schwab_auth.fbs", ReadMode::jsonfile);
    auto authflat = reader.getRoot();
    auto appkey = std::string(authflat->appkey()->c_str());
    auto appsecret = std::string(authflat->appsecret()->c_str());
    EXPECT_EQ(appkey, "abcd1234");
    EXPECT_EQ(appsecret, "iamasecret");
}

TEST_F(FlatBufferTest, SchwabPriceHistoryParseTest)
{
    FlatBufferReader<schwabMarketData::CandleList> reader(
        examplePriceHistory, "schwab_candlelist.fbs", ReadMode::jsontext);
    auto flat = reader.getRoot();
    auto symbol = std::string(flat->symbol()->c_str());
    auto previousClose = flat->previousClose();
    auto previousCloseDate = flat->previousCloseDate();

    std::vector<CandleStick> candles;
    auto candlesflat = flat->candles();
    for (const auto c : *candlesflat)
    {
        CandleStick candle;
        candle.timestamp = c->datetime();
        candle.price_open = c->open();
        candle.price_high = c->high();
        candle.price_low = c->low();
        candle.price_close = c->close();
        candle.volume = (double)c->volume();

        candles.push_back(candle);
    }

    EXPECT_EQ(symbol, "AAPL");
    EXPECT_EQ(previousClose, 174.56);
    EXPECT_EQ(previousCloseDate, 1639029600000);
    EXPECT_EQ(candles[0].price_open, 175.01);
    EXPECT_EQ(candles[0].price_high, 175.15); // good enough to check just some indices
    EXPECT_EQ(candles[6].timestamp, 1640307540000);
}