#pragma once

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

namespace streamer {

static std::string getTradierSubscribeChannelReq(const std::set<std::string>& product_id, const std::string sessionId)
{
    rapidjson::StringBuffer s;
    s.Clear();
    rapidjson::Writer<rapidjson::StringBuffer> writer(s);
    writer.StartObject();

    writer.Key("symbols");
    writer.StartArray();
    for (const auto& id : product_id)
    {
        writer.String(id.c_str());
    }
    writer.EndArray();

    writer.Key("filter");
    writer.StartArray();
    writer.String("trade");
    // writer.String("quote");
    // writer.String("summary");
    // writer.String("timesale");
    writer.String("tradex");
    writer.EndArray();

    writer.Key("sessionid");
    writer.String(sessionId.c_str());

    writer.Key("linebreak");
    writer.Bool(true);

    writer.Key("advancedDetails");
    writer.Bool(true);

    writer.EndObject();

    return s.GetString();
}

static std::string getAlpacaAuthentication(const std::string apiKey, const std::string apiSecret)
{
    rapidjson::StringBuffer s;
    s.Clear();
    rapidjson::Writer<rapidjson::StringBuffer> writer(s);
    writer.StartObject();
    writer.Key("action");
    writer.String("auth");
    writer.Key("key");
    writer.String(apiKey.c_str());
    writer.Key("secret");
    writer.String(apiSecret.c_str());
    writer.EndObject();
    std::printf("%s", s.GetString());
    return s.GetString();
}

static std::string getAlpacaChannelStreamsMsg(const std::set<std::string> symbols)
{
    rapidjson::StringBuffer sbuff;
    sbuff.Clear();
    rapidjson::Writer<rapidjson::StringBuffer> writer(sbuff);

    writer.StartObject();
    writer.Key("action");
    writer.String("subscribe");

    writer.Key("trades");
    writer.StartArray();
    for (const auto& s : symbols)
    {
        writer.String(s.c_str());
    }
    writer.EndArray();

    writer.Key("quotes");
    writer.StartArray();
    for (const auto& s : symbols)
    {
        writer.String(s.c_str());
    }
    writer.EndArray();

    writer.Key("bars");
    writer.StartArray();
    for (const auto& s : symbols)
    {
        writer.String(s.c_str());
    }
    writer.EndArray();
    writer.EndObject();

    std::printf("%s", sbuff.GetString());
    return sbuff.GetString();
}

}; // namespace streamer