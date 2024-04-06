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
        StreamerInfo streamerInfo;
        streamerInfo.schwabClientCustomerId = "customerId";
        streamerInfo.schwabClientCorrelId = "correlId";
        streamerInfo.schwabClientChannel = "clientChannel";
        streamerInfo.schwabClientFunctionId = "clientFunctionId";
        prefs.streamerInfo.push_back(streamerInfo);
    }

    UserPreferences prefs;
    std::string accessToken{"accessToken"};
};
#if 0
TEST_F(SchwabStreamReqGeneratorTest, loginRequest)
{
    std::string loginReq = schwabStreamReq::buildLoginRequest(0, prefs, accessToken);
    EXPECT_EQ(loginReq, testlogin);
}

TEST_F(SchwabStreamReqGeneratorTest, qosRequest)
{
    std::string reqstr = schwabStreamReq::buildQosRequest(1, prefs, 0);
    EXPECT_EQ(reqstr, qosRequest);
}

TEST_F(SchwabStreamReqGeneratorTest, accountActivityRequest)
{
    std::string reqstr = schwabStreamReq::buildAccountActivityRequest(2, prefs);
    EXPECT_EQ(reqstr, accountAcitivtyRequest);
}
#endif

TEST_F(SchwabStreamReqGeneratorTest, buildLoginRequestTest)
{
    Request req;
    req.serviceType = ServiceType::ADMIN;
    req.requestid = 0;
    req.commandType = CommandType::LOGIN;
    req.schwabClientCustomerId = "customerId";
    req.schwabClientCorrelId = "correlId";
    req.parameters.authorization = "accessToken";
    req.parameters.schwabClientChannel = "clientChannel";
    req.parameters.schwabClientFunctionId = "clientFunctionId";
    std::string reqstr = schwabStreamReq::buildRequestString(req);

    EXPECT_EQ(reqstr, testlogin);
}

TEST_F(SchwabStreamReqGeneratorTest, buildQosRequestTest)
{
    Request req;
    req.serviceType = ServiceType::ADMIN;
    req.requestid = 1;
    req.commandType = CommandType::QOS;
    req.schwabClientCustomerId = "customerId";
    req.schwabClientCorrelId = "correlId";
    req.parameters.qoslevel = "0";
    std::string reqstr = schwabStreamReq::buildRequestString(req);

    EXPECT_EQ(reqstr, qosRequest);
}

TEST_F(SchwabStreamReqGeneratorTest, buildAccountActivityRequestTest)
{
    Request req;
    req.serviceType = ServiceType::ACCT_ACTIVITY;
    req.requestid = 2;
    req.commandType = CommandType::SUBS;
    req.schwabClientCustomerId = "customerId";
    req.schwabClientCorrelId = "correlId";
    req.parameters.keys = "somekey";
    req.parameters.fields = "0,1,2,3";
    std::string reqstr = schwabStreamReq::buildRequestString(req);

    EXPECT_EQ(reqstr, accountAcitivtyRequest);
}