#include "InfluxDbPusher.h"
#include "SystemTimer.h"
#include "timefuncs.h"

#include <gtest/gtest.h>

using namespace utils;
using namespace timefuncs;
using namespace database;

class InfluxDbTests : public ::testing::Test
{
public:
    InfluxDbTests()
    {
    }

    void SetUp()
    {
        influxDbPusher =
            std::make_shared<InfluxDbPusher>("devtesterv1", "123456789", "192.168.0.130:8086", "dev-testing-v1",
                "N-q3KQNK6HEmUqj2bDwflK_08BQINRLTLlGsZhBrjQyFIQjVAK9AgCZtDjPEHD7IF7AWh20PPhgwAOaSXxyswQ==", 1);
    }

protected:
    std::shared_ptr<InfluxDbPusher> influxDbPusher;
};

// push data at current time, then pull data from some short seconds ago to current time
//  as of 4/17/2024 this test works. Disable so we don't hit the influxdb server and waste db space when running other
//  tests
// as of 5/29/2024 we are now using influxdb 2.0

// data takes a couple seconds to minute to show up in database sometimes
#if 0
TEST_F(InfluxDbTests, PushPullTest)
{
    std::string pointName = "testpoints6";
    FieldValueMap valueMap;
    valueMap["field1"] = 1;
    valueMap["field2"] = "test data";
    valueMap["testfield"] = "test field data";
    valueMap["open"] = 25.0;
    valueMap["high"] = 26.0;
    valueMap["low"] = 27.0;
    valueMap["close"] = 28.0;
    valueMap["volume"] = 29.0;
    valueMap["timestamp"] = 1713398340000.0;
    time_t nowMs = utils::nowMs();

    influxDbPusher->pushRaw(nowMs, pointName, valueMap);
    influxDbPusher->flushBatch();

    std::this_thread::sleep_for(std::chrono::seconds(2));

    auto fromTimeS = (nowMs / 1000) - 60;
    auto toTimeS = fromTimeS + 60;
    auto fromTimeStr = unixTimeToString(fromTimeS, "%Y-%m-%d %H:%M:%S");
    auto toTimeStr = unixTimeToString(toTimeS, "%Y-%m-%d %H:%M:%S");

    auto result = influxDbPusher->pullRaw(pointName, fromTimeStr, toTimeStr);
    EXPECT_GT(result.size(), 0);
    auto firstResult = result[0];

    EXPECT_EQ(std::get<double>(firstResult.at("field1")), 1);
    EXPECT_EQ(std::get<std::string>(firstResult.at("field2")), "test data");
    EXPECT_EQ(std::get<std::string>(firstResult.at("testfield")), "test field data");
}

TEST_F(InfluxDbTests, PushPullSpecifiedTimestampTest)
{
    std::string pointName = "testpoints_timestamp";
    FieldValueMap valueMap;
    valueMap["field1"] = 1;
    int64_t timestampMs = 1713398340000;

    for(unsigned i = 0; i < 5; i ++)
    {
        influxDbPusher->pushRaw(timestampMs, pointName, valueMap);
        influxDbPusher->flushBatch();
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    auto fromTimeS = (timestampMs / 1000) - 1;
    auto toTimeS = fromTimeS + 1;
    auto fromTimeStr = unixTimeToString(fromTimeS, "%Y-%m-%d %H:%M:%S");
    auto toTimeStr = unixTimeToString(toTimeS, "%Y-%m-%d %H:%M:%S");

    auto result = influxDbPusher->pullRaw(pointName, fromTimeStr, toTimeStr);
    EXPECT_EQ(result.size(), 1);
    auto firstResult = result[0];

    EXPECT_EQ(std::get<double>(firstResult.at("field1")), 1);
}
#endif