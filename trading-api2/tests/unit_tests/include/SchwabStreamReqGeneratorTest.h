#pragma once

#include "SchwabStreamReqGenerator.h"
#include "schwabReqGeneratorValues.h"

#include <gtest/gtest.h>

using namespace schwabAccountData;

class SchwabStreamReqGeneratorTest : public ::testing::Test
{
public:
    SchwabStreamReqGeneratorTest()
    {
    }
};

TEST_F(SchwabStreamReqGeneratorTest, loginRequest)
{
    UserPreferences prefs;
    StreamerInfo streamerInfo;
    streamerInfo.schwabClientCustomerId = "customerId";
    streamerInfo.schwabClientCorrelId = "correlId";
    streamerInfo.schwabClientChannel = "clientChannel";
    streamerInfo.schwabClientFunctionId = "clientFunctionId";
    std::string accessToken = "accessToken";

    prefs.streamerInfo.push_back(streamerInfo);

    std::string loginReq = schwabStreamReq::loginRequest(prefs, accessToken);
    EXPECT_EQ(loginReq, testlogin);
}