#pragma once

#include "SchwabConfigs.h"

#include <gtest/gtest.h>


class SchwabConfigsTest : public ::testing::Test
{
public:
    SchwabConfigsTest()
    {
    }

    /*void SetUp()
    {
        expectedAuthConfig.app_key = "app_key123";
        expectedAuthConfig.app_secret = "app_secret123";
        expectedAuthConfig.redirect_uri = "https://127.0.0.1";
        expectedAuthConfig.authorization_code.code = "authcode1234";
        expectedAuthConfig.authorization_code.granted_at_time = 1711778400000;
        expectedAuthConfig.refresh_token.token = "refresh1234";
        expectedAuthConfig.refresh_token.granted_at_time = 2711778400000;
        expectedAuthConfig.refresh_token.expires_at_time = 3711778400000;
        expectedAuthConfig.access_token.token = "access1234";
        expectedAuthConfig.access_token.granted_at_time = 4711778400000;
        expectedAuthConfig.access_token.expires_at_time = 5711778400000;
    }*/

protected:
    //AuthConfig expectedAuthConfig;
};

TEST_F(SchwabConfigsTest, readAuthConfig)
{
    AuthConfig expectedAuthConfig;
    expectedAuthConfig.app_key = "app_key123";
        expectedAuthConfig.app_secret = "app_secret123";
        expectedAuthConfig.redirect_uri = "https://127.0.0.1";
        expectedAuthConfig.authorization_code.code = "authcode1234";
        expectedAuthConfig.authorization_code.granted_at_time = 1711778400000;
        expectedAuthConfig.refresh_token.token = "refresh1234";
        expectedAuthConfig.refresh_token.granted_at_time = 2711778400000;
        expectedAuthConfig.refresh_token.expires_at_time = 3711778400000;
        expectedAuthConfig.access_token.token = "access1234";
        expectedAuthConfig.access_token.granted_at_time = 4711778400000;
        expectedAuthConfig.access_token.expires_at_time = 5711778400000;

    std::shared_ptr<SchwabConfigs> conf =
        std::make_shared<SchwabConfigs>("/datadisk0/sambashare0/coding/trading-api2/trading-api2/unit_tests/testfiles/");
    auto authconf = conf->getAuthConfig();

    EXPECT_EQ(authconf.app_key, expectedAuthConfig.app_key);
    EXPECT_EQ(authconf.app_secret, expectedAuthConfig.app_secret);
    EXPECT_EQ(authconf.redirect_uri, expectedAuthConfig.redirect_uri);

    EXPECT_EQ(authconf.authorization_code.code, expectedAuthConfig.authorization_code.code);
    EXPECT_EQ(authconf.authorization_code.granted_at_time, expectedAuthConfig.authorization_code.granted_at_time);

    EXPECT_EQ(authconf.refresh_token.token, expectedAuthConfig.refresh_token.token);
    EXPECT_EQ(authconf.refresh_token.token, expectedAuthConfig.refresh_token.token);
    EXPECT_EQ(authconf.refresh_token.expires_at_time, expectedAuthConfig.refresh_token.expires_at_time);

    EXPECT_EQ(authconf.access_token.token, expectedAuthConfig.access_token.token);
    EXPECT_EQ(authconf.access_token.granted_at_time, expectedAuthConfig.access_token.granted_at_time);
    EXPECT_EQ(authconf.access_token.expires_at_time, expectedAuthConfig.access_token.expires_at_time);
}

TEST_F(SchwabConfigsTest, getAuthConfigValues)
{
    AuthConfig expectedAuthConfig;
    expectedAuthConfig.app_key = "app_key123";
        expectedAuthConfig.app_secret = "app_secret123";
        expectedAuthConfig.redirect_uri = "https://127.0.0.1";
        expectedAuthConfig.authorization_code.code = "authcode1234";
        expectedAuthConfig.authorization_code.granted_at_time = 1711778400000;
        expectedAuthConfig.refresh_token.token = "refresh1234";
        expectedAuthConfig.refresh_token.granted_at_time = 2711778400000;
        expectedAuthConfig.refresh_token.expires_at_time = 3711778400000;
        expectedAuthConfig.access_token.token = "access1234";
        expectedAuthConfig.access_token.granted_at_time = 4711778400000;
        expectedAuthConfig.access_token.expires_at_time = 5711778400000;
    std::shared_ptr<SchwabConfigs> conf =
        std::make_shared<SchwabConfigs>("/datadisk0/sambashare0/coding/trading-api2/trading-api2/unit_tests/testfiles/");

    EXPECT_EQ(conf->getAppKey(), expectedAuthConfig.app_key);
    EXPECT_EQ(conf->getAppSecret(), expectedAuthConfig.app_secret);
    EXPECT_EQ(conf->getRedirectUri(), expectedAuthConfig.redirect_uri);

    auto authCode = conf->getAuthorizationCode();
    EXPECT_EQ(authCode.code, expectedAuthConfig.authorization_code.code);
    EXPECT_EQ(authCode.granted_at_time, expectedAuthConfig.authorization_code.granted_at_time);

    auto refreshToken = conf->getRefreshToken();
    EXPECT_EQ(refreshToken.token, expectedAuthConfig.refresh_token.token);
    EXPECT_EQ(refreshToken.token, expectedAuthConfig.refresh_token.token);
    EXPECT_EQ(refreshToken.expires_at_time, expectedAuthConfig.refresh_token.expires_at_time);

    auto accessToken = conf->getAccessToken();
    EXPECT_EQ(accessToken.token, expectedAuthConfig.access_token.token);
    EXPECT_EQ(accessToken.granted_at_time, expectedAuthConfig.access_token.granted_at_time);
    EXPECT_EQ(accessToken.expires_at_time, expectedAuthConfig.access_token.expires_at_time);
}
