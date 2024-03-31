#include "SchwabConfigs.h"

#include "json.h"
#include "rapidjson/document.h"
#include <rapidjson/writer.h>
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include <iostream>
#include <cstdio>

SchwabConfigs::SchwabConfigs(std::string folderPath)
    : folderPath(folderPath)
{
    parseAuthConfig();
}

void SchwabConfigs::parseAuthConfig()
{
    std::string authConfigPath = folderPath + "schwab_authentication.json";
    FILE* fp = fopen(authConfigPath.c_str(), "rb");
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    rapidjson::Document d;
    d.ParseStream(is);

    PARSE_STRING(cachedAuthConfig.app_key, "app_key", d);
    PARSE_STRING(cachedAuthConfig.app_secret, "app_secret", d);
    PARSE_STRING(cachedAuthConfig.redirect_uri, "redirect_uri", d);

    if(d.HasMember("authorization_code") && d["authorization_code"].IsObject())
    {
        auto authorizationCodeObj = d["authorization_code"].GetObject();
        PARSE_STRING(cachedAuthConfig.authorization_code.code, "code", authorizationCodeObj);
        PARSE_UINT64(cachedAuthConfig.authorization_code.granted_at_time, "granted_at_time", authorizationCodeObj);
    }
    else
    {
        fclose(fp);
        throw std::runtime_error("failed to parse authorization code from schwab_authentication.json");
    }

    if(d.HasMember("refresh_token") && d["refresh_token"].IsObject())
    {
        auto refreshTokenObj = d["refresh_token"].GetObject();
        PARSE_STRING(cachedAuthConfig.refresh_token.token, "token", refreshTokenObj);
        PARSE_UINT64(cachedAuthConfig.refresh_token.granted_at_time, "granted_at_time", refreshTokenObj);
        PARSE_UINT64(cachedAuthConfig.refresh_token.expires_at_time, "expires_at_time", refreshTokenObj);
    }
    else
    {
        fclose(fp);
        throw std::runtime_error("failed to parse refresh token from schwab_authentication.json");
    }

    if(d.HasMember("access_token") && d["access_token"].IsObject())
    {
        auto accessTokenObj = d["access_token"].GetObject();
        PARSE_STRING(cachedAuthConfig.access_token.token, "token", accessTokenObj);
        PARSE_UINT64(cachedAuthConfig.access_token.granted_at_time, "granted_at_time", accessTokenObj);
        PARSE_UINT64(cachedAuthConfig.access_token.expires_at_time, "expires_at_time", accessTokenObj);
    }
    else
    {
        fclose(fp);
        throw std::runtime_error("failed to parse access token from schwab_authentication.json");
    }

    fclose(fp);
}

/*SchwabConfigs::~SchwabConfigs()
{
    //saveAuthConfig();
}*/

void SchwabConfigs::saveAuthConfig()
{
    rapidjson::Document d;
    d.SetObject();
    d.AddMember("app_key", cachedAuthConfig.app_key[0], d.GetAllocator());
    
    std::string authConfigPath = folderPath + "schwab_authentication.json";
    FILE* fp = fopen(authConfigPath.c_str(), "wb");
    char writeBuffer[65536];
    rapidjson::FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
    rapidjson::Writer<rapidjson::FileWriteStream> writer(os);
    d.Accept(writer);

    fclose(fp);
}

AuthConfig SchwabConfigs::getAuthConfig() const
{
    return cachedAuthConfig;
}

std::string SchwabConfigs::getFolderPath() const
{
    return folderPath;
}

std::string SchwabConfigs::getAppKey() const
{
    return cachedAuthConfig.app_key;
}

std::string SchwabConfigs::getAppSecret() const
{
    return cachedAuthConfig.app_secret;
}

std::string SchwabConfigs::getRedirectUri() const
{
    return cachedAuthConfig.redirect_uri;
}

AuthorizationCode SchwabConfigs::getAuthorizationCode() const
{
    return cachedAuthConfig.authorization_code;
}
bool SchwabConfigs::saveAuthorizationCode(const AuthorizationCode code)
{
    cachedAuthConfig.authorization_code = code;
}

Token SchwabConfigs::getRefreshToken() const
{
    return cachedAuthConfig.refresh_token;
}
bool SchwabConfigs::saveRefreshToken(const Token refreshToken)
{
    cachedAuthConfig.refresh_token = refreshToken;
}

Token SchwabConfigs::getAccessToken() const
{
    return cachedAuthConfig.access_token;
}
bool SchwabConfigs::saveAccessToken(const Token accessToken)
{
    cachedAuthConfig.access_token = accessToken;
}