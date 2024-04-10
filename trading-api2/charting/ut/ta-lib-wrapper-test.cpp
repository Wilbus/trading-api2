#include "ta-lib-wrapper.h"

#include "MultiCandle.h"

#include <gtest/gtest.h>

using namespace ta_lib_wrapper;
using namespace charting;

class TALIBTest : public ::testing::Test
{
protected:
    TALIB talib;
};

TEST_F(TALIBTest, testSMA)
{
    std::vector<MultiCandle> mcandles;
    for (unsigned i = 0; i < 100; i++)
    {
        MultiCandle mcandle;
        mcandle.timestamp = i;
        mcandle.price_close = i;
        mcandles.push_back(mcandle);
    }

    auto ivalues = talib.SMA(mcandles, 0, mcandles.size() - 1, 5);
    EXPECT_EQ(100, ivalues.size());
    for (unsigned i = 0; i < 4; i++)
    {
        std::cout << ivalues[i].isNan << std::endl;
        std::cout << ivalues[i].value << std::endl;
        EXPECT_EQ(true, ivalues[i].isNan);
    }
}