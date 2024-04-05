#pragma once

#include "SchwabAccountDataTypes.h"

#include "json.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/stringbuffer.h"
#include <rapidjson/prettywriter.h>

#include <iostream>

namespace schwabStreamReq
{
using namespace schwabAccountData;

using rapidjson::Document;
using rapidjson::FileWriteStream;
using rapidjson::kObjectType;
using rapidjson::PrettyWriter;
using rapidjson::StringRef;
using rapidjson::Value;
using rapidjson::StringBuffer;

std::string loginRequest(const UserPreferences pref, const std::string accessToken)
{
    Document d;
    d.SetObject();
    d.AddMember("service", "ADMIN", d.GetAllocator());
    d.AddMember("requestid", 0, d.GetAllocator());
    d.AddMember("command", "LOGIN", d.GetAllocator());
    d.AddMember("SchwabClientCustomerId", StringRef(pref.streamerInfo[0].schwabClientCustomerId.c_str()), d.GetAllocator());
    d.AddMember("SchwabClientCorrelId", StringRef(pref.streamerInfo[0].schwabClientCorrelId.c_str()), d.GetAllocator());
    Value parameters(kObjectType);
    parameters.AddMember("Authorization", StringRef(accessToken.c_str()), d.GetAllocator());
    parameters.AddMember("SchwabClientChannel", StringRef(pref.streamerInfo[0].schwabClientChannel.c_str()), d.GetAllocator());
    parameters.AddMember("SchwabClientFunctionId", StringRef(pref.streamerInfo[0].schwabClientFunctionId.c_str()), d.GetAllocator());
    d.AddMember("parameters", parameters, d.GetAllocator());
    StringBuffer buffer;
    PrettyWriter<StringBuffer> pwriter(buffer);
    d.Accept(pwriter);
    std::string jsonreq = buffer.GetString();

    return jsonreq;
}

}