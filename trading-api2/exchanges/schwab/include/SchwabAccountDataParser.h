#pragma once

#include "SchwabAccountDataTypes.h"
#include "json.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

namespace schwabAccountData
{

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

}