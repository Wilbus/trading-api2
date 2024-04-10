#include "ChartData3.h"

#include <gtest/gtest.h>

using namespace charting;

class ChartData3Test : public ::testing::Test
{
protected:
    ChartData3 chartData;
};

TEST_F(ChartData3Test, testDefaultConstructor)
{
    EXPECT_EQ(0, chartData.getMultiCandles().size());
}

TEST_F(ChartData3Test, testAddMultiCandle)
{
    MultiCandle mcandle1;
    mcandle1.timestamp = 1;
    MultiCandle mcandle2;
    mcandle2.timestamp = 2;
    MultiCandle mcandle3;
    mcandle3.timestamp = 3;
    MultiCandle mcandle4;
    mcandle4.timestamp = 4;

    chartData.addMultiCandle(mcandle2);
    chartData.addMultiCandle(mcandle1);
    chartData.addMultiCandle(mcandle3);
    chartData.addMultiCandle(mcandle4);

    auto mcandles = chartData.getMultiCandles();
    EXPECT_EQ(4, mcandles.size());
    EXPECT_EQ(1, mcandles[0].timestamp);
    EXPECT_EQ(2, mcandles[1].timestamp);
    EXPECT_EQ(3, mcandles[2].timestamp);
    EXPECT_EQ(4, mcandles[3].timestamp);
}

TEST_F(ChartData3Test, testAddMultiCandles)
{
    MultiCandle mcandle1;
    mcandle1.timestamp = 1;
    MultiCandle mcandle2;
    mcandle2.timestamp = 2;
    MultiCandle mcandle3;
    mcandle3.timestamp = 3;
    MultiCandle mcandle4;
    mcandle4.timestamp = 4;

    std::vector<MultiCandle> mcandles;
    mcandles.push_back(mcandle1);
    mcandles.push_back(mcandle2);
    mcandles.push_back(mcandle3);
    mcandles.push_back(mcandle4);

    chartData.addMultiCandles(mcandles);

    auto mcandles2 = chartData.getMultiCandles();
    EXPECT_EQ(4, mcandles2.size());
    EXPECT_EQ(1, mcandles2[0].timestamp);
    EXPECT_EQ(2, mcandles2[1].timestamp);
    EXPECT_EQ(3, mcandles2[2].timestamp);
    EXPECT_EQ(4, mcandles2[3].timestamp);
}

TEST_F(ChartData3Test, testAddIndicator)
{
    IndicatorType sma5;
    sma5.name = "SMA5";
    sma5.type = IndicatorTypes::SMA;
    sma5.params = {"5"};

    IndicatorType sma10;
    sma10.name = "SMA10";
    sma10.type = IndicatorTypes::SMA;
    sma10.params = {"10"};

    for (unsigned i = 0; i < 100; i++)
    {
        MultiCandle mcandle;
        mcandle.timestamp = i;
        mcandle.price_close = i;
        chartData.addMultiCandle(mcandle);
    }

    chartData.addIndicator(sma5);
    chartData.addIndicator(sma10);

    auto mcandles = chartData.getMultiCandles();
    EXPECT_EQ(100, mcandles.size());
    EXPECT_EQ(2, mcandles[0].listIndicators().size());
    for (unsigned i = 0; i < mcandles.size(); i++)
    {
        auto indicators = mcandles[i].listIndicators();
        EXPECT_EQ(2, indicators.size());
        if (i < 4)
        {
            EXPECT_EQ(mcandles[i].getIndByName("SMA5").isNan, true);
            EXPECT_EQ(mcandles[i].getIndByName("SMA10").isNan, true);
        }
        else if (i < 9)
        {
            EXPECT_EQ(mcandles[i].getIndByName("SMA5").isNan, false);
            EXPECT_EQ(mcandles[i].getIndByName("SMA10").isNan, true);
        }
        else
        {
            EXPECT_EQ(mcandles[i].getIndByName("SMA5").isNan, false);
            EXPECT_EQ(mcandles[i].getIndByName("SMA10").isNan, false);
        }
    }
}

TEST_F(ChartData3Test, addMultiCandlesTes)
{
    MultiCandle mcandle1;
    mcandle1.timestamp = 1;
    MultiCandle mcandle2;
    mcandle2.timestamp = 2;
    MultiCandle mcandle3;
    mcandle3.timestamp = 3;
    MultiCandle mcandle4;
    mcandle4.timestamp = 4;

    std::vector<MultiCandle> mcandles;
    mcandles.push_back(mcandle1);
    mcandles.push_back(mcandle3);
    mcandles.push_back(mcandle2);
    mcandles.push_back(mcandle4);

    chartData.addMultiCandles(mcandles);

    auto mcandles2 = chartData.getMultiCandles();
    EXPECT_EQ(4, mcandles2.size());
    EXPECT_EQ(1, mcandles2[0].timestamp);
    EXPECT_EQ(2, mcandles2[1].timestamp);
    EXPECT_EQ(3, mcandles2[2].timestamp);
    EXPECT_EQ(4, mcandles2[3].timestamp);
}

TEST_F(ChartData3Test, dumpToCsvTest)
{
    MultiCandle mcandle1;
    mcandle1.timestamp = 1;
    mcandle1.price_open = 1.10;
    mcandle1.price_high = 1.20;
    mcandle1.price_low = 1.00;
    mcandle1.price_close = 1.10;
    mcandle1.volume = 100;
    mcandle1.product_id = "BTC-USD";
    chartData.addMultiCandle(mcandle1);

    MultiCandle mcandle2;
    mcandle2.timestamp = 2;
    mcandle2.price_open = 1.20;
    mcandle2.price_high = 1.30;
    mcandle2.price_low = 1.10;
    mcandle2.price_close = 1.20;
    mcandle2.volume = 200;
    mcandle2.product_id = "BTC-USD";
    chartData.addMultiCandle(mcandle2);

    MultiCandle mcandle3;
    mcandle3.timestamp = 3;
    mcandle3.price_open = 1.30;
    mcandle3.price_high = 1.40;
    mcandle3.price_low = 1.20;
    mcandle3.price_close = 1.30;
    mcandle3.volume = 300;
    mcandle3.product_id = "BTC-USD";
    chartData.addMultiCandle(mcandle3);

    IndicatorType sma5;
    sma5.name = "SMA5";
    sma5.type = IndicatorTypes::SMA;
    sma5.params = {"2"};

    chartData.addIndicator(sma5);

    std::string csvString;
    chartData.dumpToCSV(csvString);

    //clang-format off
    std::string expectedCsv = "timestamp,price_open,price_high,price_low,price_close,volume,SMA5,\n"
                              "1,1.10,1.20,1.00,1.10,100.000000000,,\n"
                              "2,1.20,1.30,1.10,1.20,200.000000000,1.15,\n"
                              "3,1.30,1.40,1.20,1.30,300.000000000,1.25,\n";
    //clang-format on

    EXPECT_EQ(expectedCsv, csvString);
}