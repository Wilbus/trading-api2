#pragma once

// #include "SchwabAccountDataTypes.h"
#include "SchwabStreamDataTypes.h"
#include "json.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/stringbuffer.h"

#include <rapidjson/prettywriter.h>

#include <iostream>

namespace schwabStreamReq {
// using namespace schwabAccountData;

using rapidjson::Document;
using rapidjson::FileWriteStream;
using rapidjson::kObjectType;
using rapidjson::PrettyWriter;
using rapidjson::StringBuffer;
using rapidjson::StringRef;
using rapidjson::Value;
#if 0
std::string buildLoginRequest(const int reqId, const UserPreferences pref, const std::string accessToken)
{
    Document d;
    d.SetObject();
    d.AddMember("service", "ADMIN", d.GetAllocator());
    d.AddMember("requestid", reqId, d.GetAllocator());
    d.AddMember("command", "LOGIN", d.GetAllocator());
    d.AddMember(
        "SchwabClientCustomerId", StringRef(pref.streamerInfo[0].schwabClientCustomerId.c_str()), d.GetAllocator());
    d.AddMember("SchwabClientCorrelId", StringRef(pref.streamerInfo[0].schwabClientCorrelId.c_str()), d.GetAllocator());
    Value parameters(kObjectType);
    parameters.AddMember("Authorization", StringRef(accessToken.c_str()), d.GetAllocator());
    parameters.AddMember(
        "SchwabClientChannel", StringRef(pref.streamerInfo[0].schwabClientChannel.c_str()), d.GetAllocator());
    parameters.AddMember(
        "SchwabClientFunctionId", StringRef(pref.streamerInfo[0].schwabClientFunctionId.c_str()), d.GetAllocator());
    d.AddMember("parameters", parameters, d.GetAllocator());
    StringBuffer buffer;
    PrettyWriter<StringBuffer> pwriter(buffer);
    d.Accept(pwriter);
    std::string jsonreq = buffer.GetString();

    return jsonreq;
}
#endif
std::string buildRequestString(Request request)
{
    Document d;
    d.SetObject();
    switch (request.serviceType)
    {
        case ServiceType::ADMIN: {
            d.AddMember("service", "ADMIN", d.GetAllocator());
            break;
        }
        case ServiceType::ACCT_ACTIVITY: {
            d.AddMember("service", "ACCT_ACTIVITY", d.GetAllocator());
            break;
        }
        case ServiceType::LEVELONE_EQUITIES:
        {
            d.AddMember("service", "LEVELONE_EQUITIES", d.GetAllocator());
            break;
        }
        default: {
            throw std::runtime_error("invalid service type provided");
        }
    }

    d.AddMember("requestid", request.requestid, d.GetAllocator());

    switch (request.commandType)
    {
        case CommandType::LOGIN: {
            d.AddMember("command", "LOGIN", d.GetAllocator());
            break;
        }
        case CommandType::QOS: {
            d.AddMember("command", "QOS", d.GetAllocator());
            break;
        }
        case CommandType::SUBS: {
            d.AddMember("command", "SUBS", d.GetAllocator());
            break;
        }
        default: {
            throw std::runtime_error("invalid command type type provided");
        }
    }

    d.AddMember("SchwabClientCustomerId", StringRef(request.schwabClientCustomerId.c_str()), d.GetAllocator());
    d.AddMember("SchwabClientCorrelId", StringRef(request.schwabClientCorrelId.c_str()), d.GetAllocator());

    Value parameters(kObjectType);
    if (request.parameters.authorization.size() > 0)
    {
        parameters.AddMember("Authorization", StringRef(request.parameters.authorization.c_str()), d.GetAllocator());
    }
    if (request.parameters.schwabClientChannel.size() > 0)
    {
        parameters.AddMember(
            "SchwabClientChannel", StringRef(request.parameters.schwabClientChannel.c_str()), d.GetAllocator());
    }
    if (request.parameters.schwabClientFunctionId.size() > 0)
    {
        parameters.AddMember(
            "SchwabClientFunctionId", StringRef(request.parameters.schwabClientFunctionId.c_str()), d.GetAllocator());
    }
    if (request.parameters.qoslevel.size() > 0)
    {
        parameters.AddMember("qoslevel", StringRef(request.parameters.qoslevel.c_str()), d.GetAllocator());
    }
    if (request.parameters.keys.size() > 0)
    {
        parameters.AddMember("keys", StringRef(request.parameters.keys.c_str()), d.GetAllocator());
    }
    if (request.parameters.fields.size() > 0)
    {
        parameters.AddMember("fields", StringRef(request.parameters.fields.c_str()), d.GetAllocator());
    }
    d.AddMember("parameters", parameters, d.GetAllocator());

    StringBuffer buffer;
    PrettyWriter<StringBuffer> pwriter(buffer);
    d.Accept(pwriter);
    std::string jsonreq = buffer.GetString();

    return jsonreq;
}
#if 0
std::string buildAccountActivityRequest(const int reqId, const UserPreferences pref)
{
    Document d;
    d.SetObject();
    d.AddMember("service", "ACCT_ACTIVITY", d.GetAllocator());
    d.AddMember("requestid", reqId, d.GetAllocator());
    d.AddMember("command", "SUBS", d.GetAllocator());
    d.AddMember("SchwabClientCustomerId", StringRef(pref.streamerInfo[0].schwabClientCustomerId.c_str()), d.GetAllocator());
    d.AddMember("SchwabClientCorrelId", StringRef(pref.streamerInfo[0].schwabClientCorrelId.c_str()), d.GetAllocator());
    Value parameters(kObjectType);
    parameters.AddMember("keys", "somekey", d.GetAllocator());
    parameters.AddMember("fields", "0,1,2,3", d.GetAllocator());
    d.AddMember("parameters", parameters, d.GetAllocator());
    StringBuffer buffer;
    PrettyWriter<StringBuffer> pwriter(buffer);
    d.Accept(pwriter);
    std::string jsonreq = buffer.GetString();
    return jsonreq;
}

std::string buildQosRequest(const int reqId, const UserPreferences pref, int qosLevel)
{
    Document d;
    d.SetObject();
    d.AddMember("service", "ADMIN", d.GetAllocator());
    d.AddMember("requestid", reqId, d.GetAllocator());
    d.AddMember("command", "QOS", d.GetAllocator());
    d.AddMember("SchwabClientCustomerId", StringRef(pref.streamerInfo[0].schwabClientCustomerId.c_str()), d.GetAllocator());
    d.AddMember("SchwabClientCorrelId", StringRef(pref.streamerInfo[0].schwabClientCorrelId.c_str()), d.GetAllocator());
     Value parameters(kObjectType);
    parameters.AddMember("qoslevel", qosLevel, d.GetAllocator());
    d.AddMember("parameters", parameters, d.GetAllocator());
    StringBuffer buffer;
    PrettyWriter<StringBuffer> pwriter(buffer);
    d.Accept(pwriter);
    std::string jsonreq = buffer.GetString();
}
#endif
} // namespace schwabStreamReq