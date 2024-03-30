#pragma once

#include "json.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

namespace alpacahelper {

enum MsgType
{
    SUCCESS,
    SUBSCRIPTION,
    TRADES,
    QUOTES,
    BARS,
    TRADESCORRECTIONS,
    TRADECANCELSERRORS,
    LULDS,
    TRADINGSTATUS
};

MsgType parseType(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    for (auto& val : d.GetArray())
    {
        if (val["T"].GetString() == "success")
        {
            return MsgType::SUCCESS;
        }
    }

    throw std::runtime_error("alpaca parseType failed");
}

}; // namespace alpacahelper