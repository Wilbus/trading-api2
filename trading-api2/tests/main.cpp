#include "CandleSamplerTest.h"
#include "TradierDataTest.h"
#include "TwsLiveMarketServiceTest.h"
// #include "FlatBufferTest.h"
#include "SchwabClientTest.h"
#include "SchwabMarketDataParserTest.h"

#include <gtest/gtest.h>

int main(int argc, char** argv)
{
    ::testing::InitGoogleMock(&argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}