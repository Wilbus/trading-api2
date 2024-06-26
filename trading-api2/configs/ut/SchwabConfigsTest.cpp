#include "SchwabConfigs.h"

#include <gtest/gtest.h>

using namespace configs;

// TODO: use getcwd instead of absolute paths for the fake schwab_authentication.json file
class SchwabConfigsTest : public ::testing::Test
{
public:
    SchwabConfigsTest()
    {
    }

    void SetUp()
    {
        expectedAuthConfig.app_key = "app_key123";
        expectedAuthConfig.app_secret = "app_secret123";
        expectedAuthConfig.redirect_uri = "https://127.0.0.1";

        authCode.code = "authcode1234";
        authCode.granted_at_time = 1711778400000;
        refreshToken.token = "refresh1234";
        refreshToken.granted_at_time = 2711778400000;
        refreshToken.expires_at_time = 3711778400000;
        accessToken.token = "access1234";
        accessToken.granted_at_time = 4711778400000;
        accessToken.expires_at_time = 5711778400000;

        expectedAuthConfig.authorization_code = authCode;
        expectedAuthConfig.refresh_token = refreshToken;
        expectedAuthConfig.access_token = accessToken;

        expectedSubscribeConfig.levelOneEquities = {
            {"QQQ", "SPY", "TGT"}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}};
        expectedSubscribeConfig.chartEquities = {{"QQQ", "SPY"}, {0, 1, 2, 3, 4, 5, 6, 7, 8}};

        expectedInfluxConnectionConf = {"user", "pass", "localhost", "dbname", "token123"};
    }

    void modifyAuthConfig()
    {
        newAuthCode.code = "newauthcode1234";
        newAuthCode.granted_at_time = 1711778400001;

        newRefreshToken.token = "newrefresh1234";
        newRefreshToken.granted_at_time = 2711778400001;
        newRefreshToken.expires_at_time = 3711778400001;

        newAccessToken.token = "newaccess1234";
        newAccessToken.granted_at_time = 4711778400001;
        newAccessToken.expires_at_time = 5711778400001;

        SchwabConfigs conf("/home/wilbus/trading-api2/trading-api2/configs/ut//");
        conf.saveAuthorizationCode(newAuthCode);
        conf.saveRefreshToken(newRefreshToken);
        conf.saveAccessToken(newAccessToken);
    }

    void restoreAuthConfig()
    {
        SchwabConfigs conf("/home/wilbus/trading-api2/trading-api2/configs/ut//");
        conf.saveAuthorizationCode(authCode);
        conf.saveRefreshToken(refreshToken);
        conf.saveAccessToken(accessToken);
    }

    void checkRestoredAuthConfig()
    {
        std::shared_ptr<SchwabConfigs> conf =
            std::make_shared<SchwabConfigs>("/home/wilbus/trading-api2/trading-api2/configs/ut//");
        EXPECT_EQ(conf->getAppKey(), expectedAuthConfig.app_key);
        EXPECT_EQ(conf->getAppSecret(), expectedAuthConfig.app_secret);
        EXPECT_EQ(conf->getRedirectUri(), expectedAuthConfig.redirect_uri);

        auto restoredauthCode = conf->getAuthorizationCode();
        EXPECT_EQ(restoredauthCode.code, expectedAuthConfig.authorization_code.code);
        EXPECT_EQ(restoredauthCode.granted_at_time, expectedAuthConfig.authorization_code.granted_at_time);

        auto restoredrefreshToken = conf->getRefreshToken();
        EXPECT_EQ(restoredrefreshToken.token, expectedAuthConfig.refresh_token.token);
        EXPECT_EQ(restoredrefreshToken.token, expectedAuthConfig.refresh_token.token);
        EXPECT_EQ(restoredrefreshToken.expires_at_time, expectedAuthConfig.refresh_token.expires_at_time);

        auto restoredaccessToken = conf->getAccessToken();
        EXPECT_EQ(restoredaccessToken.token, expectedAuthConfig.access_token.token);
        EXPECT_EQ(restoredaccessToken.granted_at_time, expectedAuthConfig.access_token.granted_at_time);
        EXPECT_EQ(restoredaccessToken.expires_at_time, expectedAuthConfig.access_token.expires_at_time);
    }

protected:
    AuthConfig expectedAuthConfig;
    AuthorizationCode authCode;
    Token refreshToken;
    Token accessToken;

    AuthorizationCode newAuthCode;
    Token newRefreshToken;
    Token newAccessToken;

    SchwabSubcriptions expectedSubscribeConfig;
    InfluxConnectionConf expectedInfluxConnectionConf;
};

TEST_F(SchwabConfigsTest, readAuthConfig)
{
    std::shared_ptr<SchwabConfigs> conf =
        std::make_shared<SchwabConfigs>("/home/wilbus/trading-api2/trading-api2/configs/ut//");
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
    std::shared_ptr<SchwabConfigs> conf =
        std::make_shared<SchwabConfigs>("/home/wilbus/trading-api2/trading-api2/configs/ut//");

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

TEST_F(SchwabConfigsTest, saveAuthConfig)
{
    std::shared_ptr<SchwabConfigs> conf =
        std::make_shared<SchwabConfigs>("/home/wilbus/trading-api2/trading-api2/configs/ut//");
    EXPECT_NO_THROW(conf->saveAuthConfig());
}

TEST_F(SchwabConfigsTest, modifyAuthConfig)
{
    modifyAuthConfig();
    std::shared_ptr<SchwabConfigs> conf =
        std::make_shared<SchwabConfigs>("/home/wilbus/trading-api2/trading-api2/configs/ut//");

    EXPECT_EQ(conf->getAppKey(), expectedAuthConfig.app_key);
    EXPECT_EQ(conf->getAppSecret(), expectedAuthConfig.app_secret);
    EXPECT_EQ(conf->getRedirectUri(), expectedAuthConfig.redirect_uri);

    auto newauthCode = conf->getAuthorizationCode();
    EXPECT_EQ(newauthCode.code, "newauthcode1234");
    EXPECT_EQ(newauthCode.granted_at_time, 1711778400001);

    auto newrefreshToken = conf->getRefreshToken();
    EXPECT_EQ(newrefreshToken.token, "newrefresh1234");
    EXPECT_EQ(newrefreshToken.granted_at_time, 2711778400001);
    EXPECT_EQ(newrefreshToken.expires_at_time, 3711778400001);

    auto newaccessToken = conf->getAccessToken();
    EXPECT_EQ(newaccessToken.token, "newaccess1234");
    EXPECT_EQ(newaccessToken.granted_at_time, 4711778400001);
    EXPECT_EQ(newaccessToken.expires_at_time, 5711778400001);

    restoreAuthConfig();
    checkRestoredAuthConfig();
}

TEST_F(SchwabConfigsTest, getSubscribeConfigTest)
{
    std::shared_ptr<SchwabConfigs> conf =
        std::make_shared<SchwabConfigs>("/home/wilbus/trading-api2/trading-api2/configs/ut//");
    auto subconf = conf->getSubscribeConfig();

    EXPECT_EQ(subconf.levelOneEquities.symbols.size(), expectedSubscribeConfig.levelOneEquities.symbols.size());
    EXPECT_EQ(subconf.levelOneEquities.fields.size(), expectedSubscribeConfig.levelOneEquities.fields.size());
    EXPECT_EQ(subconf.chartEquities.symbols.size(), expectedSubscribeConfig.chartEquities.symbols.size());
    EXPECT_EQ(subconf.chartEquities.fields.size(), expectedSubscribeConfig.chartEquities.fields.size());

    for (size_t i = 0; i < subconf.levelOneEquities.symbols.size(); i++)
    {
        EXPECT_EQ(subconf.levelOneEquities.symbols[i], expectedSubscribeConfig.levelOneEquities.symbols[i]);
    }
    for (size_t i = 0; i < subconf.levelOneEquities.fields.size(); i++)
    {
        EXPECT_EQ(subconf.levelOneEquities.fields[i], expectedSubscribeConfig.levelOneEquities.fields[i]);
    }

    for (size_t i = 0; i < subconf.chartEquities.symbols.size(); i++)
    {
        EXPECT_EQ(subconf.chartEquities.symbols[i], expectedSubscribeConfig.chartEquities.symbols[i]);
    }
    for (size_t i = 0; i < subconf.chartEquities.fields.size(); i++)
    {
        EXPECT_EQ(subconf.chartEquities.fields[i], expectedSubscribeConfig.chartEquities.fields[i]);
    }
}

TEST_F(SchwabConfigsTest, getInfluxConnectionConfTest)
{
    std::shared_ptr<SchwabConfigs> conf =
        std::make_shared<SchwabConfigs>("/home/wilbus/trading-api2/trading-api2/configs/ut//");
    auto influxconf = conf->getInfluxConnectionConfig();

    EXPECT_EQ(influxconf.user, expectedInfluxConnectionConf.user);
    EXPECT_EQ(influxconf.pass, expectedInfluxConnectionConf.pass);
    EXPECT_EQ(influxconf.host, expectedInfluxConnectionConf.host);
    EXPECT_EQ(influxconf.dbname, expectedInfluxConnectionConf.dbname);
    EXPECT_EQ(influxconf.authToken, expectedInfluxConnectionConf.authToken);
}