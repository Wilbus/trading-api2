#pragma once

#include "EWrapperMock.h"
#include "TwsClientWrapperMock.h"
#include "TwsLiveMarketService.h"

#include <gtest/gtest.h>

using namespace charting;

class TwsLiveMarketServiceTest : public ::testing::Test
{
public:
    TwsLiveMarketServiceTest()
    {
        EWrapper* mock = new EWrapperMock();
        (void)mock;
    }

protected:
};

TEST_F(TwsLiveMarketServiceTest, firstTest)
{
}