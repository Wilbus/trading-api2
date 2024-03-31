#pragma once

#include <string>

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

} // namespace schwabAccountData