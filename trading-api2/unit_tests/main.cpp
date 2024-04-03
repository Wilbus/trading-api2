#include "RestClientCurlTest.h"
#include "SchwabAccountDataParserTest.h"
#include "SchwabMarketDataParserTest.h"
#include "SchwabErrorParserTest.h"
#include "SchwabClientTest.h"
#include "SchwabConfigsTest.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

int main(int argc, char** argv)
{
    ::testing::InitGoogleMock(&argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}