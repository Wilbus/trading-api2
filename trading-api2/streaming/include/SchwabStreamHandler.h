#pragma once

#include "DataQueue.h"
#include "IStreamHandler.h"
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

using utils::DataQueue;

class SchwabStreamHandler : public IStreamHandler
{
public:
    SchwabStreamHandler(std::string url, SchwabRequestsIdMap requestsIdMap,
        std::shared_ptr<DataQueue<std::string>> repliesQue, std::string logfile = "");
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

protected:
    SchwabRequestsIdMap requestsIdMap;
    std::map<RequestId, std::string> requestsIdStrMap;
    std::queue<Request> requestsQueue;
    RequestId currentReqId{0};

private:
    void setupCallbacks();
    uWS::Hub hub;
    uWS::Group<uWS::CLIENT>* group;
    std::string streamUrl;
    std::string logfile;
    std::shared_ptr<DataQueue<std::string>> repliesQue;
    time_t lastReceivedHeartbeat{-1};

    uint64_t msgcount{0};
};

} // namespace streamer