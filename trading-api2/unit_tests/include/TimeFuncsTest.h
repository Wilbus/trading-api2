#pragma once

#include "timefuncs.h"
#include "SystemTimer.h"

using namespace timefuncs;

class TimeFuncsTest : public ::testing::Test
{
public:
    TimeFuncsTest()
    {

    }

    time_t realNowTimeMs()
    {
        auto now = std::chrono::system_clock::now();
        auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
        auto epoch = now_ms.time_since_epoch();
        return epoch.count();
    }
};

TEST_F(TimeFuncsTest, unixTimeToStringTest)
{
    uint64_t timeMs = 1712188803000;
    uint64_t timeS = timeMs / 1000;
    time_t timeT = static_cast<time_t>(timeS);
    std::string timeStr = unixTimeToString(timeT, "%Y-%m-%dT%H:%M:%S +0000 UTC");
    EXPECT_EQ(timeStr, "2024-04-04T00:00:03 +0000 UTC");

    timeMs = 1712305853000;
    timeS = timeMs / 1000;
    timeT = static_cast<time_t>(timeS);
    timeStr = unixTimeToString(timeT, "%Y-%m-%dT%H:%M:%S +0000 UTC");
    EXPECT_EQ(timeStr, "2024-04-05T08:30:53 +0000 UTC");

    time_t nowMs = realNowTimeMs();
    timeS = nowMs / 1000;
    timeT = static_cast<time_t>(timeS);
    timeStr = unixTimeToString(timeT, "%Y-%m-%dT%H:%M:%S +0000 UTC");
    std::cout << "TimeFuncsTest::unixTimeToStringTest nowMs() is " << timeStr << "\n";
}