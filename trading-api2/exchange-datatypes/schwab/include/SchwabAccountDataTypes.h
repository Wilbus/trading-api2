#pragma once

#include <functional>
#include <string>

namespace schwabAccountData {

struct AuthTokens
{
    int64_t expires_in;
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

struct AccountNumbers
{
    std::string accountNumber;
    std::string hashValue;
};

struct Account
{
    std::string accountNumber;
    bool primaryAccount;
    std::string type;
    std::string nickName;
    std::string accountColor;
    std::string displayAcctId;
    std::string autoPositionEffect;
};

struct StreamerInfo
{
    std::string streamerSocketUrl;
    std::string schwabClientCustomerId;
    std::string schwabClientCorrelId;
    std::string schwabClientChannel;
    std::string schwabClientFunctionId;
};

struct Offers
{
    bool level2Permissions;
};

struct UserPreferences
{
    std::vector<Account> accounts;
    std::vector<StreamerInfo> streamerInfo;
    std::vector<Offers> offers;
};

} // namespace schwabAccountData