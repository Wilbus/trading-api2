#include "SchwabConfigs.h"

#include <cstdio>
#include <iostream>

namespace configs {

SchwabConfigs::SchwabConfigs(std::string folderPath)
    : folderPath(folderPath)
{
    parseAuthConfig();
    parseSubscribeConfig();
    parseInfluxConnectionConfig();
}

void SchwabConfigs::parseAuthConfig()
{
    std::string authConfigPath = folderPath + authConfigName;
    FILE* fp = fopen(authConfigPath.c_str(), "rb");
    if (fp == nullptr)
    {
        std::string errmsg = "error opening file " + authConfigPath;
        throw std::runtime_error(errmsg.c_str());
    }
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    rapidjson::Document d;
    d.ParseStream(is);

    PARSE_STRING(cachedAuthConfig.app_key, "app_key", d);
    PARSE_STRING(cachedAuthConfig.app_secret, "app_secret", d);
    PARSE_STRING(cachedAuthConfig.redirect_uri, "redirect_uri", d);

    if (d.HasMember("authorization_code") && d["authorization_code"].IsObject())
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

    if (d.HasMember("refresh_token") && d["refresh_token"].IsObject())
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

    if (d.HasMember("access_token") && d["access_token"].IsObject())
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

void SchwabConfigs::parseSubscribeConfig()
{
    std::string subscribeConfigPath = folderPath + subscribeConfigName;
    FILE* fp = fopen(subscribeConfigPath.c_str(), "rb");
    if (fp == nullptr)
    {
        std::string errmsg = "error opening file " + subscribeConfigPath;
        throw std::runtime_error(errmsg.c_str());
    }
    char readBuffer[1045840]; // 1 MB
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    rapidjson::Document d;
    d.ParseStream(is);

    if (d.HasMember("levelone_equities") && d["levelone_equities"].IsObject())
    {
        cachedSubscriptions.levelOneEquities = parseSubscribeSymbolConf(d["levelone_equities"].GetObject());
    }
    if (d.HasMember("chart_equities") && d["chart_equities"].IsObject())
    {
        cachedSubscriptions.chartEquities = parseSubscribeSymbolConf(d["chart_equities"]);
    }

    fclose(fp);
}

SubscribeSymbolConf SchwabConfigs::parseSubscribeSymbolConf(const rapidjson::Value& value)
{
    SubscribeSymbolConf conf;
    if (value.HasMember("symbols") && value["symbols"].IsArray())
    {
        for (auto& symbol : value["symbols"].GetArray())
        {
            conf.symbols.push_back(symbol.GetString());
        }
    }
    if (value.HasMember("fields") && value["fields"].IsArray())
    {
        for (auto& field : value["fields"].GetArray())
        {
            conf.fields.push_back(field.GetInt());
        }
    }
    return conf;
}

void SchwabConfigs::parseInfluxConnectionConfig()
{
    std::string influxConnectionConfigPath = folderPath + influxConnectionConfigName;
    FILE* fp = fopen(influxConnectionConfigPath.c_str(), "rb");
    if (fp == nullptr)
    {
        std::string errmsg = "error opening file " + influxConnectionConfigPath;
        throw std::runtime_error(errmsg.c_str());
    }
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    rapidjson::Document d;
    d.ParseStream(is);

    if (d.HasMember("user") && d["user"].IsString())
    {
        PARSE_STRING(cachedInfluxConnection.user, "user", d);
    }
    if (d.HasMember("pass") && d["pass"].IsString())
    {
        PARSE_STRING(cachedInfluxConnection.pass, "pass", d);
    }
    if (d.HasMember("host") && d["host"].IsString())
    {
        PARSE_STRING(cachedInfluxConnection.host, "host", d);
    }
    if (d.HasMember("dbname") && d["dbname"].IsString())
    {
        PARSE_STRING(cachedInfluxConnection.dbname, "dbname", d);
    }
    if (d.HasMember("authToken") && d["authToken"].IsString())
    {
        PARSE_STRING(cachedInfluxConnection.authToken, "authToken", d);
    }

    fclose(fp);
}

InfluxConnectionConf SchwabConfigs::getInfluxConnectionConfig() const
{
    return cachedInfluxConnection;
}

/*SchwabConfigs::~SchwabConfigs()
{
    //saveAuthConfig();
}*/

void SchwabConfigs::saveAuthConfig()
{
    Document d;
    d.SetObject();
    d.AddMember("app_key", StringRef(cachedAuthConfig.app_key.c_str()), d.GetAllocator());
    d.AddMember("app_secret", StringRef(cachedAuthConfig.app_secret.c_str()), d.GetAllocator());
    d.AddMember("redirect_uri", StringRef(cachedAuthConfig.redirect_uri.c_str()), d.GetAllocator());

    Value authCodeVal(kObjectType);
    authCodeVal.AddMember("code", StringRef(cachedAuthConfig.authorization_code.code.c_str()), d.GetAllocator());
    authCodeVal.AddMember("granted_at_time", cachedAuthConfig.authorization_code.granted_at_time, d.GetAllocator());

    Value refreshTokenVal(kObjectType);
    refreshTokenVal.AddMember("token", StringRef(cachedAuthConfig.refresh_token.token.c_str()), d.GetAllocator());
    refreshTokenVal.AddMember("granted_at_time", cachedAuthConfig.refresh_token.granted_at_time, d.GetAllocator());
    refreshTokenVal.AddMember("expires_at_time", cachedAuthConfig.refresh_token.expires_at_time, d.GetAllocator());

    Value accessTokenVal(kObjectType);
    accessTokenVal.AddMember("token", StringRef(cachedAuthConfig.access_token.token.c_str()), d.GetAllocator());
    accessTokenVal.AddMember("granted_at_time", cachedAuthConfig.access_token.granted_at_time, d.GetAllocator());
    accessTokenVal.AddMember("expires_at_time", cachedAuthConfig.access_token.expires_at_time, d.GetAllocator());

    d.AddMember("authorization_code", authCodeVal, d.GetAllocator());
    d.AddMember("refresh_token", refreshTokenVal, d.GetAllocator());
    d.AddMember("access_token", accessTokenVal, d.GetAllocator());

    std::string authConfigPath = folderPath + authConfigName;
    FILE* fp = fopen(authConfigPath.c_str(), "wb");
    if (fp == nullptr)
    {
        throw std::runtime_error("error saving schwab_authentication.json");
    }
    char writeBuffer[65536];
    FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
    PrettyWriter<FileWriteStream> writer(os);
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
    try
    {
        saveAuthConfig();
        return true;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
        return false;
    }
}

Token SchwabConfigs::getRefreshToken() const
{
    return cachedAuthConfig.refresh_token;
}
bool SchwabConfigs::saveRefreshToken(const Token refreshToken)
{
    cachedAuthConfig.refresh_token = refreshToken;
    try
    {
        saveAuthConfig();
        return true;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
        return false;
    }
}

Token SchwabConfigs::getAccessToken() const
{
    return cachedAuthConfig.access_token;
}
bool SchwabConfigs::saveAccessToken(const Token accessToken)
{
    cachedAuthConfig.access_token = accessToken;
    try
    {
        saveAuthConfig();
        return true;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
        return false;
    }
}

SchwabSubcriptions SchwabConfigs::getSubscribeConfig() const
{
    return cachedSubscriptions;
}

} // namespace configs