#include "StreamHandler.h"

#include <iostream>

std::string testlogin = R"({
    "service": "ADMIN",
    "requestid": 0,
    "command": "LOGIN",
    "SchwabClientCustomerId": "<streamerInfo[0].schwabClientCustomerId>",
    "SchwabClientCorrelId": "<streamerInfo[0].schwabClientCorrelId>",
    "parameters":
    {
        "Authorization": "<ACCESS_TOKEN>",
        "SchwabClientChannel": "<streamerInfo[0].schwabClientChannel>",
        "SchwabClientFunctionId": "<streamerInfo[0].schwabClientFunctionId>"
    }
})";

int main(int argc, char** argv)
{
    uWS::Hub hub;
    uWS::Group<uWS::CLIENT>* group;

    group = hub.createGroup<uWS::CLIENT>();

    group->onConnection([](uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest)
    {
        std::cout << "test\n";
        ws->send(testlogin.data(), testlogin.size(), uWS::OpCode::TEXT);
    });

    group->onMessage([](uWS::WebSocket<uWS::CLIENT>* ws, char* message, size_t length, uWS::OpCode opCode)
    {
        std::string text = std::string(message, length);
        std::cout << text << "\n";
    });

    hub.connect("wss://streamer-api.schwab.com/ws", nullptr, {}, 5000, group);
    hub.run();
}