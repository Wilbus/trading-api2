#include "StreamHandler.h"
#include "SchwabClient.h"
#include "RestClientCurl.h"
#include "json.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/stringbuffer.h"
#include <rapidjson/prettywriter.h>

#include <iostream>

using namespace restclient;
using namespace schwabMarketData;
using namespace schwabAccountData;
using namespace schwabErrors;
using rapidjson::Document;
using rapidjson::FileWriteStream;
using rapidjson::kObjectType;
using rapidjson::PrettyWriter;
using rapidjson::StringRef;
using rapidjson::Value;
using rapidjson::StringBuffer;

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    std::shared_ptr<SchwabConfigs> config = std::make_shared<SchwabConfigs>("/datadisk0/sambashare0/coding/configs/");
    std::shared_ptr<RestClientCurl> restclient = std::make_shared<RestClientCurl>("/datadisk0/sambashare0/coding/trading-api2-endpoint-test-logs/");
    std::shared_ptr<SchwabClient> sclient = std::make_shared<SchwabClient>(config, restclient);

    UserPreferences pref = sclient->getUserPreferences();
    Document d;
    d.SetObject();
    d.AddMember("service", "ADMIN", d.GetAllocator());
    d.AddMember("requestid", 0, d.GetAllocator());
    d.AddMember("command", "LOGIN", d.GetAllocator());
    d.AddMember("SchwabClientCustomerId", StringRef(pref.streamerInfo[0].schwabClientCustomerId.c_str()), d.GetAllocator());
    d.AddMember("SchwabClientCorrelId", StringRef(pref.streamerInfo[0].schwabClientCorrelId.c_str()), d.GetAllocator());
    Value parameters(kObjectType);
    std::string access_token = config->getAccessToken().token; //ensure value passed to StringRef exists past lifetime of this being used
    parameters.AddMember("Authorization", StringRef(access_token.c_str()), d.GetAllocator());
    parameters.AddMember("SchwabClientChannel", StringRef(pref.streamerInfo[0].schwabClientChannel.c_str()), d.GetAllocator());
    parameters.AddMember("SchwabClientFunctionId", StringRef(pref.streamerInfo[0].schwabClientFunctionId.c_str()), d.GetAllocator());
    d.AddMember("parameters", parameters, d.GetAllocator());
    StringBuffer buffer;
    PrettyWriter<StringBuffer> pwriter(buffer);
    d.Accept(pwriter);
    std::string jsonreq = buffer.GetString();


    uWS::Hub hub;
    uWS::Group<uWS::CLIENT>* group;

    group = hub.createGroup<uWS::CLIENT>();

    group->onConnection([jsonreq](uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest)
    {
        std::cout << jsonreq;
        ws->send(jsonreq.data(), jsonreq.size(), uWS::OpCode::TEXT);
    });

    group->onMessage([](uWS::WebSocket<uWS::CLIENT>* ws, char* message, size_t length, uWS::OpCode opCode)
    {
        std::string text = std::string(message, length);
        std::cout << text << "\n";
    });

    group->onDisconnection([](uWS::WebSocket<uWS::CLIENT>* ws, int code, char* message, size_t length)
    {
        std::cout << "disconnect event\n";
    });

    hub.connect("wss://streamer-api.schwab.com/ws", nullptr, {}, 5000, group);
    hub.run();
}