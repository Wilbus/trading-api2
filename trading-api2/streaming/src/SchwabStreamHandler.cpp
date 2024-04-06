#include "SchwabStreamHandler.h"
#include "SchwabStreamReqGenerator.h"
#include "SchwabStreamParser.h"

#include <iostream>

namespace streamer {
// TODO: consider moving callback functions outside of this class to for example SchwabConnection class
SchwabStreamHandler::SchwabStreamHandler(std::string url, SchwabRequestsIdMap requestsIdMap)
    : group(hub.createGroup<uWS::CLIENT>())
    , streamUrl(url)
    , requestsIdMap(requestsIdMap)
{
    repliesQue = std::make_shared<DataQueue<std::string>>();
    for(const auto& [id, req] : requestsIdMap)
    {
        requestsIdStrMap[id] = schwabStreamReq::buildRequestString(req);
    }
    setupCallbacks();
}

SchwabStreamHandler::~SchwabStreamHandler()
{
    group->close();
    delete group;
}

void SchwabStreamHandler::setupCallbacks()
{
    group->onConnection(
        [this](uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req) {
            onConnectionCallback(ws, req);
            //onConnection(ws, req);
        });

    group->onMessage([this](uWS::WebSocket<uWS::CLIENT>* ws, char* message, size_t length, uWS::OpCode opCode) {
        onMessageCallback(ws, message, length, opCode);
    });

    group->onDisconnection([this](uWS::WebSocket<uWS::CLIENT>* ws, int code, char* message, size_t length) {
        onDisconnectionCallback(ws, code, message, length);
    });

    group->onError([this](void* e) { onErrorCallback(e); });
}

void SchwabStreamHandler::run()
{
    std::cout << "SchwabStreamHandler start run()\n";
    hub.run();
}

void SchwabStreamHandler::onConnectionCallback(uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req)
{
    if (requestsIdMap.find(0) == requestsIdMap.end())
    {
        throw std::runtime_error("no login request was requested");
    }
    //std::cout << "SchwabStreamHandler sends: \n" << requestsIdMap.at(loginRequestId) << "\n";

    ws->send(requestsIdStrMap.at(0).data(), requestsIdStrMap.at(0).size(), uWS::OpCode::TEXT),
        nullptr, nullptr, nullptr;
}

void SchwabStreamHandler::onMessageCallback(
    uWS::WebSocket<uWS::CLIENT>* ws, char* message, size_t length, uWS::OpCode opCode)
{
    (void)ws;
    (void)opCode;
    std::string text = std::string(message, length);
    //std::cout << text << "\n";


    repliesQue->push(text);
}

void SchwabStreamHandler::onDisconnectionCallback(
    uWS::WebSocket<uWS::CLIENT>* ws, int code, char* message, size_t length)
{
    (void)ws;
    (void)code;
    (void)message;
    (void)length;
    std::cout << "disconnect event";
}

void SchwabStreamHandler::onErrorCallback(void* e)
{
    (void)e;
}

void SchwabStreamHandler::reconnectingStream()
{
}

void SchwabStreamHandler::connectStream()
{
    std::cout << "SchwabStreamHandler connect to " << streamUrl << "\n";
    hub.connect(streamUrl, nullptr, {}, 5000, group);
    //hub.run();
}

std::shared_ptr<DataQueue<std::string>> SchwabStreamHandler::repliesQueue()
{
    return repliesQue;
}

} // namespace streamer