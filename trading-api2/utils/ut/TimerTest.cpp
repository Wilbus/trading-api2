#include "SystemTimer.h"
#include "Timer.h"

#include <gtest/gtest.h>

using namespace utils;

class TimerTest : public ::testing::Test
{
public:
    class TimerTester : public Timer
    {
    public:
        TimerTester(size_t waitMs, std::function<void(void)>& callback)
            : Timer(waitMs, callback)
        {
            // force join the timer's child wait thread to test that the timer actually waited.
            // we shouldn't join in normal operation so as to not block parent thread
            waitThread.join();
        }
    };

    TimerTest()
    {
    }

    void testCallback()
    {
        test = 1;
    }

protected:
    int test{0};
};

TEST_F(TimerTest, timerTest)
{
    std::function<void()> callback = std::bind(&TimerTest::testCallback, this);
    size_t waitMs = 1000;

    time_t beforeTimer = nowMs();
    TimerTester(waitMs, callback);
    time_t afterTimer = nowMs();

    EXPECT_EQ(test, 1);

    time_t waitedTime = afterTimer - beforeTimer;

    // expect waited time is within 1ms error of requested wait
    EXPECT_NEAR(waitedTime, waitMs, 1);
}
