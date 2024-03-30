#pragma once

#include "CandleSampler.h"
#include "TradierTestData.h"

#include <gtest/gtest.h>

using namespace charting;

class CandleSamplerTest : public ::testing::Test
{
public:
    CandleSamplerTest()
    {
    }

protected:
};

TEST_F(CandleSamplerTest, SamplerTest)
{
    std::vector<CandleStick> candles;

    CandleSampler sampler;
    auto testvec = tradierTradeDataTestVec();
    for (auto& t : testvec)
    {
        auto candle = sampler.sampleTicker(t);
        if (candle.has_value())
        {
            // std::printf("%s\n", candle.value().toString().c_str());
            candles.push_back(candle.value());
        }
    }
}