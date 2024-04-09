#pragma once

#include "SchwabStreamDataTypes.h"
#include "json.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#include <map>

namespace schwabStreamParser {

std::map<std::string, ChartEquity> parseChartEquity(const rapidjson::Value& chartEquityObj)
{
    std::map<std::string, ChartEquity> chartEquities;

    if (chartEquityObj.HasMember("content") && chartEquityObj["content"].IsArray())
    {
        for (const auto& equityContent : chartEquityObj["content"].GetArray())
        {
            // TODO: SUBJECT TO CHANGE WHEN OFFICIAL SCHWAB STREAMING API DOCS AVAILABLE
            ChartEquity e;
            PARSE_DOUBLE(e.open, "2", equityContent);
            PARSE_DOUBLE(e.high, "3", equityContent);
            PARSE_DOUBLE(e.low, "4", equityContent);
            PARSE_DOUBLE(e.close, "5", equityContent);
            PARSE_DOUBLE(e.volume, "6", equityContent);
            PARSE_INT64(e.time, "7", equityContent);
            PARSE_STRING(e.symbol, "key", equityContent);
            if (e.symbol.length() > 0)
            {
                chartEquities[e.symbol] = e;
            }
        }
    }

    return chartEquities;
}

std::map<std::string, LevelOneEquity> parseLevelOneEquity(const rapidjson::Value& levelOneEquityObj)
{
    std::map<std::string, LevelOneEquity> levelOneEquities;

    if (levelOneEquityObj.HasMember("content") && levelOneEquityObj["content"].IsArray())
    {
        for (const auto& levelOneContent : levelOneEquityObj["content"].GetArray())
        {
            LevelOneEquity l;
            // TODO: SUBJECT TO CHANGE WHEN OFFICIAL SCHWAB STREAMING API DOCS AVAILABLE
            PARSE_DOUBLE(l.bidprice, "1", levelOneContent);
            PARSE_DOUBLE(l.askprice, "2", levelOneContent);
            PARSE_DOUBLE(l.lastprice, "3", levelOneContent);
            PARSE_DOUBLE(l.bidsize, "4", levelOneContent);
            PARSE_DOUBLE(l.asksize, "5", levelOneContent);
            PARSE_STRING(l.bidid, "6", levelOneContent);
            PARSE_STRING(l.askid, "7", levelOneContent);
            PARSE_INT64(l.totalvolume, "8", levelOneContent);
            PARSE_DOUBLE(l.lastsize, "9", levelOneContent);
            PARSE_STRING(l.symbol, "key", levelOneContent);
            if (l.symbol.length() > 0)
            {
                levelOneEquities[l.symbol] = l;
            }
        }
    }

    return levelOneEquities;
}

SchwabServiceData parseServiceData(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    if (!d.IsObject())
    {
        return {};
    }

    if (d.HasMember("data") && d["data"].IsArray())
    {
        SchwabServiceData data;

        auto servicesArrayObj = d["data"].GetArray();
        for (const auto& serviceObj : servicesArrayObj)
        {
            std::string service;
            PARSE_STRING(service, "service", serviceObj);
            switch (stringToServiceTypeMap.at(service))
            {
                case ServiceType::CHART_EQUITY: {
                    data.chartEquities = parseChartEquity(serviceObj);
                    break;
                }
                case ServiceType::LEVELONE_EQUITIES: {
                    data.levelOneEquities = parseLevelOneEquity(serviceObj);
                    break;
                }
                default: {
                    continue;
                    break;
                }
            }
        }

        return data;
    }

    return {};
}

} // namespace schwabStreamParser