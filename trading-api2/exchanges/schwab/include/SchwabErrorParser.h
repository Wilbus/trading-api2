#pragma once

#include "SchwabErrorDataTypes.h"
#include "json.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#include <iostream>

namespace schwabErrors {

ErrorSource parseErrorSource(const rapidjson::Value& errSourceObj)
{
    ErrorSource source;
    if (errSourceObj.HasMember("pointer") && errSourceObj["pointer"].IsArray())
    {
        for (const auto& p : errSourceObj["pointer"].GetArray())
        {
            source.pointer.push_back(p.GetString());
        }
    }
    if (errSourceObj.HasMember("parameter") && errSourceObj["parameter"].IsString())
    {
        source.parameter = errSourceObj["parameter"].GetString();
    }
    if (errSourceObj.HasMember("header") && errSourceObj["header"].IsString())
    {
        source.header = errSourceObj["header"].GetString();
    }
    return source;
}

Error parseError(const rapidjson::Value& errorObj)
{
    Error err;
    PARSE_STRING(err.id, "id", errorObj);
    // TODO: schwab api says this is string, but example shown can also be int...
    //  assume it is string always for now
    PARSE_STRING(err.status, "status", errorObj);
    PARSE_STRING(err.title, "title", errorObj);
    if (errorObj.HasMember("detail") && errorObj["detail"].IsString())
    {
        err.detail = errorObj["detail"].GetString();
    }
    if (errorObj.HasMember("source") && errorObj["source"].IsObject())
    {
        err.source = parseErrorSource(errorObj["source"].GetObject());
    }
    return err;
}

/*return empty error vector if no errors parsed or issue parsing error*/
ErrorResponse checkErrors(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    ErrorResponse errorResp;
    try
    {
        if (d.HasMember("errors") && d["errors"].IsArray())
        {
            for (const auto& e : d["errors"].GetArray())
            {
                Error err = parseError(e);
                errorResp.errors.push_back(err);
            }
        }

        // this key value pair is seen when invalid credentials sent in a POST
        Error miscError;
        bool isMiscError = false;
        if (d.HasMember("error") && d["error"].IsString())
        {
            isMiscError = true;
            PARSE_STRING(miscError.detail, "error", d);
        }
        if (d.HasMember("error_description") && d["error_description"].IsString())
        {
            PARSE_STRING(miscError.error_description, "error_description", d);
        }
        if (isMiscError)
        {
            errorResp.errors.push_back(miscError);
        }
        return errorResp;
    }
    catch (const std::exception& e)
    {
        std::cout << "warning: can't parse for error response\n";
        return errorResp;
    }
}

}; // namespace schwabErrors