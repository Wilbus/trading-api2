#pragma once

#include "SchwabStreamDataTypes.h"
#include "json.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

namespace schwabStreamParser {

std::vector<Response> parseResponse(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    if (!d.IsObject())
    {
        return {};
    }

    std::vector<Response> resps;

    if (d.HasMember("response") && d["response"].IsArray())
    {
        for (const auto& respObj : d["response"].GetArray())
        {
            Response resp;
            std::string temp;
            PARSE_STRING(temp, "service", respObj);
            if (temp == "ADMIN")
            {
                resp.service = ServiceType::ADMIN;
            }
            // else if...

            PARSE_STRING(temp, "command", respObj);
            if (temp == "LOGIN")
            {
                resp.command = CommandType::LOGIN;
            }
            // else if...

            std::string id;
            PARSE_STRING(id, "requestid", respObj);
            resp.requestid = std::stoi(id);
            PARSE_STRING(resp.SchwabClientCorrelId, "SchwabClientCorrelId", respObj);
            PARSE_INT64(resp.timestamp, "timestamp", respObj);

            if (respObj.HasMember("content") && respObj["content"].IsObject())
            {
                auto contentObj = respObj["content"].GetObject();
                PARSE_INT(resp.content.code, "code", contentObj);
                PARSE_STRING(resp.content.msg, "msg", contentObj);
            }

            resps.push_back(resp);
        }
    }
    return resps;
}

} // namespace schwabStreamParser