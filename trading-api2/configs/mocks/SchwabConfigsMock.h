#pragma once

#include "SchwabConfigs.h"

#include <gmock/gmock.h>

using namespace configs;

class SchwabConfigsMock : public ISchwabConfigs
{
public:
    MOCK_CONST_METHOD0(getAuthConfig, AuthConfig());
    MOCK_CONST_METHOD0(getFolderPath, std::string());
    MOCK_CONST_METHOD0(getAppKey, std::string());
    MOCK_CONST_METHOD0(getAppSecret, std::string());
    MOCK_CONST_METHOD0(getRedirectUri, std::string());
    MOCK_CONST_METHOD0(getAuthorizationCode, AuthorizationCode());
    MOCK_METHOD1(saveAuthorizationCode, bool(const AuthorizationCode));
    MOCK_CONST_METHOD0(getRefreshToken, Token());
    MOCK_METHOD1(saveRefreshToken, bool(const Token));
    MOCK_CONST_METHOD0(getAccessToken, Token());
    MOCK_METHOD1(saveAccessToken, bool(const Token));
    MOCK_METHOD0(parseAuthConfig, void());
    MOCK_METHOD0(saveAuthConfig, void());
    MOCK_METHOD0(parseSubscribeConfig, void());
    MOCK_CONST_METHOD0(getSubscribeConfig, SchwabSubcriptions());
    MOCK_METHOD0(parseInfluxConnectionConfig, void());
    MOCK_CONST_METHOD0(getInfluxConnectionConfig, InfluxConnectionConf());
};