#pragma once

#include "SchwabAccountDataTypes.h"

using namespace schwabAccountData;

class ISchwabConfigs
{
public:

};

class SchwabConfigs
{
public:
    SchwabConfigs(std::string folderPath);

#if 0
    ~SchwabConfigs() = default;

    SchwabConfigs(const SchwabConfigs& other)
        : SchwabConfigs(other.getFolderPath())
    {

    }

    SchwabConfigs& operator=(const SchwabConfigs& other)
    {
        if(this == &other)
            return *this;
        cachedAuthConfig = other.getAuthConfig();
        folderPath = other.getFolderPath();
        return *this;
    }
#endif
    AuthConfig getAuthConfig() const;
    std::string getFolderPath() const;

    std::string getAppKey() const;
    std::string getAppSecret() const;
    std::string getRedirectUri() const;

    AuthorizationCode getAuthorizationCode() const;
    bool saveAuthorizationCode(const AuthorizationCode code);

    Token getRefreshToken() const;
    bool saveRefreshToken(const Token refreshToken);

    Token getAccessToken() const;
    bool saveAccessToken(const Token accessToken);

    void parseAuthConfig();
    void saveAuthConfig();

private:
    std::string folderPath;
    AuthConfig cachedAuthConfig;
};