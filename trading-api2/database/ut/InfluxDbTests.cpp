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

protected:
    std::shared_ptr<InfluxDbPusher> influxDbPusher;
};

// push data at current time, then pull data from some short seconds ago to current time
//  as of 4/17/2024 this test works. Disable so we don't hit the influxdb server and waste db space when running other
//  tests
#if 0
TEST_F(InfluxDbTests, PushPullTest)
{
    influxDbPusher = std::make_shared<InfluxDbPusher>("influxdbtests_rawstring", 1);

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

    std::this_thread::sleep_for(std::chrono::seconds(1));

    auto fromTimeS = (utils::nowMs() / 1000) - 1;
    auto toTimeS = fromTimeS + 1;
    auto fromTimeStr = unixTimeToString(fromTimeS, "%Y-%m-%d %H:%M:%S");
    auto toTimeStr = unixTimeToString(toTimeS, "%Y-%m-%d %H:%M:%S");

    auto result = influxDbPusher->pullRaw(pointName, fromTimeStr, toTimeStr);
    EXPECT_GT(result.size(), 0);
    auto firstResult = result[0];

    EXPECT_EQ(std::get<double>(firstResult.at("field1")), 1);
    EXPECT_EQ(std::get<std::string>(firstResult.at("field2")), "test data");
    EXPECT_EQ(std::get<std::string>(firstResult.at("testfield")), "test field data");
}
#endif