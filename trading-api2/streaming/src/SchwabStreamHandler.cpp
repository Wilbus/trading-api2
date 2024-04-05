#include "SchwabStreamHandler.h"

namespace streamer {

SchwabStreamHandler::SchwabStreamHandler(std::string url)
    : group(hub.createGroup<uWS::CLIENT>())
    , streamUrl(url)
{
    repliesQue = std::make_shared<DataQueue<std::string>>();
    setupCallbacks();
}

void SchwabStreamHandler::run()
{
}

void SchwabStreamHandler::setupCallbacks()
{
}

void SchwabStreamHandler::onConnectionCallback(uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req)
{

}

void SchwabStreamHandler::onMessageCallback(char* message, size_t length)
{
}

void SchwabStreamHandler::onDisconnectionCallback(int code, char* message, size_t length)
{
}

void SchwabStreamHandler::onErrorCallback(void* e)
{
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