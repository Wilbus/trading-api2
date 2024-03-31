#pragma once

#include "SchwabAccountDataParser.h"
#include "schwabtestauthvalues.h"

#include <gtest/gtest.h>

using namespace schwabAccountData;

class SchwabAccountDataParserTest : public ::testing::Test
{
public:
    SchwabAccountDataParserTest()
    {
    }

protected:
};

TEST_F(SchwabAccountDataParserTest, parseAuthTokens)
{
    auto authtokens = parseAuthTokens(createAccessTokenRespExample);
    EXPECT_EQ(authtokens.expires_in, 1800);
    EXPECT_EQ(authtokens.token_type, "Bearer");
    EXPECT_EQ(authtokens.scope, "api");
    EXPECT_EQ(authtokens.refresh_token, "REFRESH_TOKEN_HERE");
    EXPECT_EQ(authtokens.access_token, "ACCESS_TOKEN_HERE");
    EXPECT_EQ(authtokens.id_token, "JWT_HERE");
}