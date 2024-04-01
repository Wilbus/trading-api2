#pragma once

#include <string>
#include <functional>

namespace schwabAccountData {

struct AuthTokens
{
    uint64_t expires_in;
    std::string token_type;
    std::string scope;
    std::string refresh_token;
    std::string access_token;
    std::string id_token;
};

struct SchwabAuth
{
    std::string appkey;
    std::string appsecret;
    std::string token;
    std::string callbackUrl;
    AuthTokens authTokens;
};

struct AuthorizationCode
{
    std::string code;
    uint64_t granted_at_time;
};

struct Token
{
    std::string token;
    uint64_t granted_at_time;
    uint64_t expires_at_time;

    bool operator==(const Token& other)
    {
        return other.token == token && other.granted_at_time == granted_at_time && other.expires_at_time == expires_at_time;
    }
};

//needed for SchwabClientTest
static bool operator==(const Token& lhs, const Token& rhs)
{
    return lhs.token == rhs.token && lhs.granted_at_time == rhs.granted_at_time && lhs.expires_at_time == rhs.expires_at_time;
}

struct AuthConfig
{
    std::string app_key;
    std::string app_secret;
    std::string redirect_uri;
    AuthorizationCode authorization_code;
    Token access_token;
    Token refresh_token;
#if 0
    AuthConfig()
    {

    }

    ~AuthConfig() = default;

    AuthConfig(std::string app_key, std::string app_secret, std::string redirect_uri,
        AuthorizationCode authorization_code, Token access_token, Token refresh_token)
        : app_key(app_key)
        , app_secret(app_secret)
        , redirect_uri(redirect_uri)
        , authorization_code(authorization_code)
        , access_token(access_token)
        , refresh_token(refresh_token)
    {

    }

    AuthConfig(const AuthConfig& other)
        : AuthConfig(other.app_key, other.app_secret, other.redirect_uri,
            other.authorization_code, other.access_token, other.refresh_token)
    {

    }

    AuthConfig& operator=(const AuthConfig& other)
    {
        if(this == &other)
            return *this;
        
        app_key = other.app_key;
        app_secret = other.app_secret;
        redirect_uri = other.redirect_uri;
        authorization_code = other.authorization_code;
        access_token = other.access_token;
        refresh_token = other.refresh_token;
        return *this;
    }
#endif
};

} // namespace schwabAccountData