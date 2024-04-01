#pragma once

#include "SchwabAccountDataTypes.h"

using namespace schwabAccountData;

class ISchwabConfigs
{
public:
    virtual AuthConfig getAuthConfig() const = 0;
    virtual std::string getFolderPath() const = 0;

    virtual std::string getAppKey() const = 0;
    virtual std::string getAppSecret() const = 0;
    virtual std::string getRedirectUri() const = 0;

    virtual AuthorizationCode getAuthorizationCode() const = 0;
    virtual bool saveAuthorizationCode(const AuthorizationCode code) = 0;

    virtual Token getRefreshToken() const = 0;
    virtual bool saveRefreshToken(const Token refreshToken) = 0;

    virtual Token getAccessToken() const = 0;
    virtual bool saveAccessToken(const Token accessToken) = 0;

    virtual void parseAuthConfig() = 0;
    virtual void saveAuthConfig() = 0;
};

class SchwabConfigs : public ISchwabConfigs
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
    virtual AuthConfig getAuthConfig() const override;
    virtual std::string getFolderPath() const override;

    virtual std::string getAppKey() const override;
    virtual std::string getAppSecret() const override;
    virtual std::string getRedirectUri() const override;

    virtual AuthorizationCode getAuthorizationCode() const override;
    virtual bool saveAuthorizationCode(const AuthorizationCode code) override;

    virtual Token getRefreshToken() const override;
    virtual bool saveRefreshToken(const Token refreshToken) override;

    virtual Token getAccessToken() const override;
    virtual bool saveAccessToken(const Token accessToken) override;

    virtual void parseAuthConfig() override;
    virtual void saveAuthConfig() override;

private:
    std::string folderPath;
    AuthConfig cachedAuthConfig;
};