#pragma once

#include "SchwabAccountDataTypes.h"
#include "json.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/stringbuffer.h"

#include <rapidjson/prettywriter.h>

using namespace schwabAccountData;

namespace configs {

using rapidjson::Document;
using rapidjson::FileWriteStream;
using rapidjson::kObjectType;
using rapidjson::PrettyWriter;
using rapidjson::StringRef;
using rapidjson::Value;

struct SubscribeSymbolConf
{
    std::vector<std::string> symbols;
    std::vector<uint8_t> fields;
};

struct SchwabSubcriptions
{
    SubscribeSymbolConf levelOneEquities;
    SubscribeSymbolConf chartEquities;
};

struct AuthorizationCode
{
    std::string code;
    int64_t granted_at_time;
};

struct Token
{
    std::string token;
    int64_t granted_at_time;
    int64_t expires_at_time;

    bool operator==(const Token& other)
    {
        return other.token == token && other.granted_at_time == granted_at_time &&
               other.expires_at_time == expires_at_time;
    }
};

// needed for SchwabClientTest
static bool operator==(const Token& lhs, const Token& rhs)
{
    return lhs.token == rhs.token && lhs.granted_at_time == rhs.granted_at_time &&
           lhs.expires_at_time == rhs.expires_at_time;
}

struct AuthConfig
{
    std::string app_key;
    std::string app_secret;
    std::string redirect_uri;
    AuthorizationCode authorization_code;
    Token access_token;
    Token refresh_token;
};

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

    virtual void parseSubscribeConfig() = 0;
    virtual SchwabSubcriptions getSubscribeConfig() const = 0;
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

    virtual void parseSubscribeConfig() override;
    virtual SchwabSubcriptions getSubscribeConfig() const override;

private:
    SubscribeSymbolConf parseSubscribeSymbolConf(const rapidjson::Value& value);

    std::string authConfigName{"schwab_authentication.json"};
    std::string subscribeConfigName{"schwab_subscription.json"};
    std::string folderPath;
    AuthConfig cachedAuthConfig;
    SchwabSubcriptions cachedSubscriptions;
};

} // namespace configs