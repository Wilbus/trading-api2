#include "ChartsAggregator.h"

#include <gtest/gtest.h>

using namespace databank;

class ChartsAggregatorTest : public ::testing::Test
{
public:
    ChartsAggregatorTest()
    {
        chartsAggregator = std::make_shared<ChartsAggregator>();
    }

    void SetUp() override
    {
    }

protected:
    std::shared_ptr<ChartsAggregator> chartsAggregator;
    ChartData3 minuteChartForFive;
};

TEST_F(ChartsAggregatorTest, addAndAggregateChartsTest)
{
    ChartData3 minuteChartForFive;
    // five minutes chart
    // 3000 seconds -> 10 5 minute candles
    for (size_t i = 0; i < 3000 * 1000; i += 300 * 1000)
    {
        CandleStick candle;
        candle.price_open = i * 2 / 1000;
        candle.price_close = i * 3 / 1000;
        candle.price_high = 1.0;
        candle.price_low = 1.0;
        candle.volume = 1.0;
        candle.timestamp = i;
        minuteChartForFive.addMultiCandle(MultiCandle{candle});
    }

    chartsAggregator->addChart("TGT", minuteChartForFive, Timeframe::FIVE);

    CandleStick candle0;
    candle0.price_open = 0;
    candle0.price_close = 5;
    candle0.price_high = 10;
    candle0.price_low = 0;
    candle0.volume = 100;
    candle0.timestamp = 3000 * 1000;

    chartsAggregator->addMinuteCandle("TGT", candle0);
    EXPECT_EQ(chartsAggregator->getChartData("TGT", Timeframe::FIVE).getBack(0).price_open, 5400);
    EXPECT_EQ(chartsAggregator->getChartData("TGT", Timeframe::FIVE).getBack(0).price_close, 8100);

    for (size_t i = 1; i < 6; i++)
    {
        CandleStick candle;
        candle.price_open = i;
        candle.price_close = i + 1;
        candle.price_high = 10 + i;
        candle.price_low = 10 - i;
        candle.volume = 100;
        candle.timestamp = candle0.timestamp + i * 60 * 1000;
        chartsAggregator->addMinuteCandle("TGT", candle);
    }

    EXPECT_EQ(chartsAggregator->getChartData("TGT", Timeframe::FIVE).getBack(0).price_open, 0);
    EXPECT_EQ(chartsAggregator->getChartData("TGT", Timeframe::FIVE).getBack(0).price_close, 5);
    EXPECT_EQ(chartsAggregator->getChartData("TGT", Timeframe::FIVE).getBack(0).price_high, 14);
    EXPECT_EQ(chartsAggregator->getChartData("TGT", Timeframe::FIVE).getBack(0).price_low, 0);
    EXPECT_EQ(chartsAggregator->getChartData("TGT", Timeframe::FIVE).getBack(0).timestamp, 3000 * 1000);
}