#pragma once

#include "SchwabStreamParser.h"
#include "schwabStreamResponseValues.h"

#include <gtest/gtest.h>

using namespace schwabStreamParser;

class SchwabStreamParserTest : public ::testing::Test
{
public:
    SchwabStreamParserTest()
    {
    }
};

TEST_F(SchwabStreamParserTest, parseLoginResponse)
{
    std::vector<Response> resps = parseResponse(loginResponse);
    EXPECT_EQ(resps.size(), 1);
    Response resp = resps[0];
    EXPECT_EQ(resp.service, ServiceType::ADMIN);
    EXPECT_EQ(resp.command, CommandType::LOGIN);
    EXPECT_EQ(resp.requestid, 0);
    EXPECT_EQ(resp.SchwabClientCorrelId, "abcd-1234");
    EXPECT_EQ(resp.timestamp, 1712381288369);
    EXPECT_EQ(resp.content.code, 0);
    EXPECT_EQ(resp.content.msg, "server=s6969-1;status=PN");
}

TEST_F(SchwabStreamParserTest, parseLoginDeniedResponse)
{
    std::vector<Response> resps = parseResponse(loginDeniedResponse);
    EXPECT_EQ(resps.size(), 1);
    Response resp = resps[0];
    EXPECT_EQ(resp.service, ServiceType::ADMIN);
    EXPECT_EQ(resp.command, CommandType::LOGIN);
    EXPECT_EQ(resp.requestid, 0);
    EXPECT_EQ(resp.SchwabClientCorrelId, "abcd-1234");
    EXPECT_EQ(resp.timestamp, 1712381288369);
    EXPECT_EQ(resp.content.code, 3);
    EXPECT_EQ(resp.content.msg, "Login denied");
}