#pragma once

#include "IStreamHandler.h"
#include "DataQueue.h"
#include "SchwabStreamParser.h"
#include "SchwabStreamDataTypes.h"

#include <functional>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <variant>

namespace streamer {

using namespace schwabStreamParser;

using utils::DataQueue;

class SchwabStreamHandler : public IStreamHandler
{
public:
    SchwabStreamHandler(std::string url, SchwabRequestsIdMap requestsIdMap);
    ~SchwabStreamHandler();

    virtual void run() override;

    virtual void onConnectionCallback(uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req) override;
    virtual void onMessageCallback(
        uWS::WebSocket<uWS::CLIENT>* ws, char* message, size_t length, uWS::OpCode opCode) override;
    virtual void onDisconnectionCallback(
        uWS::WebSocket<uWS::CLIENT>* ws, int code, char* message, size_t length) override;
    virtual void onErrorCallback(void* e) override;
    virtual void reconnectingStream() override;
    virtual void connectStream() override;
    virtual std::shared_ptr<DataQueue<std::string>> repliesQueue() override;

    //std::function<void(uWS::WebSocket<uWS::CLIENT>*, uWS::HttpRequest)> onConnection;

protected:
    SchwabRequestsIdMap requestsIdMap;
    std::map<RequestId, std::string> requestsIdStrMap;

private:
    void setupCallbacks();
    uWS::Hub hub;
    uWS::Group<uWS::CLIENT>* group;
    std::string streamUrl;
    std::shared_ptr<DataQueue<std::string>> repliesQue;

    uint64_t msgcount{0};
};

} // namespace streamer