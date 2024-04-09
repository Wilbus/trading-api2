#include "SchwabStreamDataParser.h"
#include "schwabStreamResponseValues.h"

#include <gtest/gtest.h>

using namespace schwabStreamParser;

class SchwabStreamDataarserTest : public ::testing::Test
{
public:
    SchwabStreamDataarserTest()
    {
    }
};

TEST_F(SchwabStreamDataarserTest, parseInvalidDataStream)
{
    SchwabServiceData data = parseServiceData("{not valid data}");
    EXPECT_EQ(data.chartEquities.size(), 0);
    EXPECT_EQ(data.levelOneEquities.size(), 0);
}

TEST_F(SchwabStreamDataarserTest, parseInitialLumpedServiceData)
{
    SchwabServiceData data = parseServiceData(bigLevelOneDataResponse);
    EXPECT_GT(data.chartEquities.size(), 0);
    ChartEquity e0 = data.chartEquities.at("TGT");
    EXPECT_EQ(e0.open, 169.51);
    EXPECT_EQ(e0.high, 169.51);
    EXPECT_EQ(e0.low, 169.51);
    EXPECT_EQ(e0.close, 169.51);
    EXPECT_EQ(e0.time, 1712620560000);
    EXPECT_EQ(e0.volume, 18);

    ChartEquity tsmChart = data.chartEquities.at("TSM");
    EXPECT_EQ(tsmChart.open, 143.5);
    EXPECT_EQ(tsmChart.high, 143.5);
    EXPECT_EQ(tsmChart.low, 143.01);
    EXPECT_EQ(tsmChart.close, 143.01);
    EXPECT_EQ(tsmChart.time, 1712620740000);
    EXPECT_EQ(tsmChart.volume, 140);

    EXPECT_GT(data.levelOneEquities.size(), 0);
}

TEST_F(SchwabStreamDataarserTest, parseShortLevelOneData)
{
    SchwabServiceData data = parseServiceData(shortLevelOneData);
    EXPECT_GT(data.levelOneEquities.size(), 0);

    LevelOneEquity l = data.levelOneEquities.at("CAVA");
    EXPECT_EQ(l.askprice, 65.08);
    EXPECT_EQ(l.bidprice, -1);
}