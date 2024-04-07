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

TEST_F(SchwabStreamParserTest, parseAccountActivityResponse)
{
    std::vector<Response> resps = parseResponse(acccountActivityResponse);
    EXPECT_EQ(resps.size(), 1);
    Response resp = resps[0];
    EXPECT_EQ(resp.service, ServiceType::ACCT_ACTIVITY);
    EXPECT_EQ(resp.command, CommandType::SUBS);
    EXPECT_EQ(resp.requestid, 1);
    EXPECT_EQ(resp.SchwabClientCorrelId, "abcd-1234");
    EXPECT_EQ(resp.timestamp, 1712461126712);
    EXPECT_EQ(resp.content.code, 0);
    EXPECT_EQ(resp.content.msg, "SUBS command succeeded");
}

TEST_F(SchwabStreamParserTest, parseLevelOneEquitiesResponse)
{
    std::vector<Response> resps = parseResponse(levelOneEquitiesResponse);
    EXPECT_EQ(resps.size(), 1);
    Response resp = resps[0];
    EXPECT_EQ(resp.service, ServiceType::LEVELONE_EQUITIES);
    EXPECT_EQ(resp.command, CommandType::SUBS);
    EXPECT_EQ(resp.requestid, 1);
    EXPECT_EQ(resp.SchwabClientCorrelId, "abcd-1234");
    EXPECT_EQ(resp.timestamp, 1712461126712);
    EXPECT_EQ(resp.content.code, 0);
    EXPECT_EQ(resp.content.msg, "SUBS command succeeded");
}

TEST_F(SchwabStreamParserTest, parseChartEquityResponse)
{
    std::vector<Response> resps = parseResponse(chartEquityResponse);
    EXPECT_EQ(resps.size(), 1);
    Response resp = resps[0];
    EXPECT_EQ(resp.service, ServiceType::CHART_EQUITY);
    EXPECT_EQ(resp.command, CommandType::SUBS);
    EXPECT_EQ(resp.requestid, 3);
    EXPECT_EQ(resp.SchwabClientCorrelId, "abcd-1234");
    EXPECT_EQ(resp.timestamp, 1712461126819);
    EXPECT_EQ(resp.content.code, 0);
    EXPECT_EQ(resp.content.msg, "SUBS command succeeded");
}

TEST_F(SchwabStreamParserTest, parseOptionResponse)
{
    std::vector<Response> resps = parseResponse(optionResponse);
    EXPECT_EQ(resps.size(), 1);
    Response resp = resps[0];
    EXPECT_EQ(resp.service, ServiceType::OPTION);
    EXPECT_EQ(resp.command, CommandType::SUBS);
    EXPECT_EQ(resp.requestid, 4);
    EXPECT_EQ(resp.SchwabClientCorrelId, "abcd-1234");
    EXPECT_EQ(resp.timestamp, 1712461126869);
    EXPECT_EQ(resp.content.code, 0);
    EXPECT_EQ(resp.content.msg, "SUBS command succeeded");
}