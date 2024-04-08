#pragma once

#include "SchwabStreamDataTypes.h"
#include "json.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#include <iostream>
#include <vector>

namespace schwabStreamParser {

// TODO: consider using same rapidjson::Document instance for all, and use d.Clear() on each parse call to save some
// time from re-initializing
Heartbeat parseHeartbeat(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    if (!d.IsObject())
    {
        return {};
    }

    if (d.HasMember("notify") && d["notify"].IsArray())
    {
        Heartbeat hb;
        for (const auto& heartbeatObj : d["notify"].GetArray())
        {
            std::string temp;
            PARSE_STRING(temp, "heartbeat", heartbeatObj);
            hb.timestamp = std::stol(temp);
            return hb; // assuming only one heartbeat value per heartbeat response
        }
    }
    return {}; // response isn't a heartbeat type
}

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
            resp.service = stringToServiceTypeMap.at(temp);

            PARSE_STRING(temp, "command", respObj);
            resp.command = stringToCommandTypeMap.at(temp);

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