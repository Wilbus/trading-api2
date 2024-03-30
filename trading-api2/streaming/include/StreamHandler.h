#pragma once

#include "IStreamHandler.h"

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

// typedef std::function<void(DataType)> StreamCallbackFunc;
// typedef std::map<std::string, StreamCallbackFunc> CallbackFuncMap;

class StreamHandler : public IStreamHandler
{
public:
    StreamHandler(std::string url, std::set<std::string> product_ids, std::string seshId);
    ~StreamHandler();

    virtual void run() override;
    // virtual void poll() override;
    virtual void setupCallbacks() override;

    virtual void onConnectionCallback(uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req) override;
    virtual void onMessageCallback(char* message, size_t length) override;
    virtual void onDisconnectionCallback(int code, char* message, size_t length) override;
    virtual void onErrorCallback(void* e) override;
    virtual void reconnectingStream() override;
    virtual void connectStream() override;
    virtual std::shared_ptr<DataQueue<std::string>> repliesQueue() override;

private:
    uWS::Hub hub;
    uWS::Group<uWS::CLIENT>* group;
    std::string streamUrl;
    std::shared_ptr<DataQueue<std::string>> repliesQue;
    std::set<std::string> product_ids;
    std::string seshId;

    uint64_t msgcount{0};
};

} // namespace streamer