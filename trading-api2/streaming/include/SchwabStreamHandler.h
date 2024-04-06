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

enum ServiceType : unsigned
{
    LOGIN,
};

/*only one request for each stream type*/
struct RequestId
{
    int requestId;
    ServiceType serviceType;
};

bool operator<(const RequestId& lhs, const RequestId& rhs)
{
    return lhs.requestId < rhs.requestId;
}

typedef std::string RequestJson;
typedef std::map<RequestId, RequestJson> SchwabRequestsIdMap;

using utils::DataQueue;

class ISchwabStreamHandler
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

class SchwabStreamHandler : public ISchwabStreamHandler
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

protected:
    SchwabRequestsIdMap requestsIdMap;

private:
    void setupCallbacks();
    uWS::Hub hub;
    uWS::Group<uWS::CLIENT>* group;
    std::string streamUrl;
    std::shared_ptr<DataQueue<std::string>> repliesQue;

    uint64_t msgcount{0};
};

} // namespace streamer