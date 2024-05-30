#pragma once

#include "DataQueue.h"

#include "uWS.h"

#include <set>
#include <string>

namespace streamer {
using utils::DataQueue;

const std::string kDefaultData = "{}";

class IStreamHandler
{
public:
    virtual void run() = 0;

    virtual void onConnectionCallback(uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req) = 0;
    virtual void onMessageCallback(
        uWS::WebSocket<uWS::CLIENT>* ws, char* message, size_t length, uWS::OpCode opCode) = 0;
    virtual void onDisconnectionCallback(uWS::WebSocket<uWS::CLIENT>* ws, int code, char* message, size_t length) = 0;
    virtual void onErrorCallback(void* e) = 0;
    virtual void reconnectingStream() = 0;
    virtual void connectStream() = 0;
    virtual std::shared_ptr<DataQueue<std::string>> repliesQueue() = 0;
};

} // namespace streamer