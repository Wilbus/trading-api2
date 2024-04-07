#pragma once

#include "SchwabAccountDataTypes.h"
#include "json.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

namespace schwabAccountData {

AuthTokens parseAuthTokens(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    AuthTokens auth;
    PARSE_UINT64(auth.expires_in, "expires_in", d);
    PARSE_STRING(auth.token_type, "token_type", d);
    PARSE_STRING(auth.scope, "scope", d);
    PARSE_STRING(auth.refresh_token, "refresh_token", d);
    PARSE_STRING(auth.access_token, "access_token", d);
    PARSE_STRING(auth.id_token, "id_token", d);

    return auth;
}

UserPreferences parseUserPreferences(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    if (!d.IsObject())
    {
        return {};
    }

    UserPreferences pref;

    if (d.HasMember("accounts") && d["accounts"].IsArray())
    {
        Account acc;
        for (const auto& accountObj : d["accounts"].GetArray())
        {
            PARSE_STRING(acc.accountNumber, "accountNumber", accountObj);
            PARSE_BOOL(acc.primaryAccount, "primaryAccount", accountObj);
            PARSE_STRING(acc.type, "type", accountObj);
            PARSE_STRING(acc.displayAcctId, "displayAcctId", accountObj);
            PARSE_BOOL(acc.autoPositionEffect, "autoPositionEffect", accountObj);
            PARSE_STRING(acc.accountColor, "accountColor", accountObj);
            pref.accounts.push_back(acc);
        }
    }
    if (d.HasMember("streamerInfo") && d["streamerInfo"].IsArray())
    {
        for (const auto& streamerObj : d["streamerInfo"].GetArray())
        {
            StreamerInfo streamerInfo;
            PARSE_STRING(streamerInfo.streamerSocketUrl, "streamerSocketUrl", streamerObj);
            PARSE_STRING(streamerInfo.schwabClientCustomerId, "schwabClientCustomerId", streamerObj);
            PARSE_STRING(streamerInfo.schwabClientCorrelId, "schwabClientCorrelId", streamerObj);
            PARSE_STRING(streamerInfo.schwabClientChannel, "schwabClientChannel", streamerObj);
            PARSE_STRING(streamerInfo.schwabClientFunctionId, "schwabClientFunctionId", streamerObj);
            pref.streamerInfo.push_back(streamerInfo);
        }
    }
    if (d.HasMember("offers") && d["offers"].IsArray())
    {
        for (const auto& offersObj : d["offers"].GetArray())
        {
            Offers offers;
            PARSE_STRING(offers.level2Permissions, "level2Permissions", offersObj);
            pref.offers.push_back(offers);
        }
    }
    return pref;
}

} // namespace schwabAccountData