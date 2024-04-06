#include "SchwabStreamHandler.h"

namespace streamer {
// TODO: consider moving callback functions outside of this class to for example SchwabConnection class
SchwabStreamHandler::SchwabStreamHandler(std::string url, SchwabRequestsIdMap requestsIdMap)
    : group(hub.createGroup<uWS::CLIENT>())
    , streamUrl(url)
    , requestsIdMap(requestsIdMap)
{
    repliesQue = std::make_shared<DataQueue<std::string>>();
}

SchwabStreamHandler::~SchwabStreamHandler()
{
}

void SchwabStreamHandler::setupCallbacks()
{
    group->onConnection(
        [this](uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req) { onConnectionCallback(ws, req); });

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
}

void SchwabStreamHandler::onConnectionCallback(uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req)
{
    RequestId loginRequestId{0, ServiceType::LOGIN};
    if (requestsIdMap.find(loginRequestId) == requestsIdMap.end())
    {
        throw std::runtime_error("no login request was requested");
    }
    std::cout << "SchwabStreamHandler sends: \n" << requestsIdMap.at(loginRequestId) << "\n";

    ws->send(requestsIdMap.at(loginRequestId).data(), requestsIdMap.at(loginRequestId).size(), uWS::OpCode::TEXT),
        nullptr, nullptr, nullptr;
}

void SchwabStreamHandler::onMessageCallback(
    uWS::WebSocket<uWS::CLIENT>* ws, char* message, size_t length, uWS::OpCode opCode)
{
    (void)ws;
    (void)opCode;
    std::string text = std::string(message, length);
}

void SchwabStreamHandler::onDisconnectionCallback(
    uWS::WebSocket<uWS::CLIENT>* ws, int code, char* message, size_t length)
{
    (void)ws;
    (void)code;
    (void)message;
    (void)length;
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
}

std::shared_ptr<DataQueue<std::string>> SchwabStreamHandler::repliesQueue()
{
    return repliesQue;
}

} // namespace streamer