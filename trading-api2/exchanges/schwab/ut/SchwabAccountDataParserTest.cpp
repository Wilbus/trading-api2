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

TEST_F(SchwabAccountDataParserTest, parseUserPreferences)
{
    UserPreferences pref = parseUserPreferences(userPreferenceRespExample);

    EXPECT_EQ(pref.accounts.size(), 2);
    auto acc0 = pref.accounts[0];
    auto acc1 = pref.accounts[1];
    EXPECT_EQ(acc0.accountNumber, "123456789");
    EXPECT_EQ(acc0.primaryAccount, true);
    EXPECT_EQ(acc0.accountColor, "Green");

    EXPECT_EQ(acc1.accountNumber, "444555666");
    EXPECT_EQ(acc1.primaryAccount, false);
    EXPECT_EQ(acc1.accountColor, "Blue");

    auto streamerInfo = pref.streamerInfo[0];
    EXPECT_EQ(streamerInfo.streamerSocketUrl, "wss://streamer-api.schwab.com/ws");
    EXPECT_EQ(streamerInfo.schwabClientCustomerId, "some-customer-id");
    EXPECT_EQ(streamerInfo.schwabClientCorrelId, "some-correl-id");
    EXPECT_EQ(streamerInfo.schwabClientChannel, "N9");
}