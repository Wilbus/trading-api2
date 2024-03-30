#pragma once

#include "DataQueue.h"

#include <uWS/uWS.h>

#include <functional>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <variant>

namespace streamer {
using namespace utils;

class IAlpacaStreamHandler
{
public:
    virtual void run() = 0;
    // virtual void poll() = 0;
    virtual void setupCallbacks() = 0;

    virtual void onConnectionCallback(uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req) = 0;
    virtual void onMessageCallback(uWS::WebSocket<uWS::CLIENT>* ws, char* message, size_t length) = 0;
    virtual void onDisconnectionCallback(int code, char* message, size_t length) = 0;
    virtual void onErrorCallback(void* e) = 0;
    virtual void reconnectingStream() = 0;
    virtual void connectStream() = 0;
    virtual std::shared_ptr<DataQueue<std::string>> repliesQueue() = 0;
};

class AlpacaStreamHandler : public IAlpacaStreamHandler
{
public:
    AlpacaStreamHandler(std::string url, std::string apiKey, std::string apiSecret);
    AlpacaStreamHandler(std::string url);
    ~AlpacaStreamHandler();

    virtual void run() override;
    // virtual void poll() override;
    virtual void setupCallbacks() override;

    virtual void onConnectionCallback(uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req) override;
    virtual void onMessageCallback(uWS::WebSocket<uWS::CLIENT>* ws, char* message, size_t length) override;
    virtual void onDisconnectionCallback(int code, char* message, size_t length) override;
    virtual void onErrorCallback(void* e) override;
    virtual void reconnectingStream() override;
    virtual void connectStream() override;
    virtual std::shared_ptr<DataQueue<std::string>> repliesQueue() override;

private:
    uWS::Hub hub;
    uWS::Group<uWS::CLIENT>* group;
    std::string streamUrl;
    std::string apiKey;
    std::string apiSecret;
    std::shared_ptr<DataQueue<std::string>> repliesQue;
    uint64_t msgcount{0};
};

} // namespace streamer