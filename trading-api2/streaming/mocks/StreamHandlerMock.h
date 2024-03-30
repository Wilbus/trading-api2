#pragma once

#include "IStreamHandler.h"

#include <gmock/gmock.h>

using namespace streamer;

class StreamHandlerMock : public IStreamHandler
{
public:
    MOCK_METHOD0(run, void());
    MOCK_METHOD0(setupCallbacks, void());
    MOCK_METHOD2(onConnectionCallback, void(uWS::WebSocket<uWS::CLIENT>*, uWS::HttpRequest));
    MOCK_METHOD2(onMessageCallback, void(char*, size_t));
    MOCK_METHOD3(onDisconnectionCallback, void(int, char*, size_t));
    MOCK_METHOD1(onErrorCallback, void(void*));
    MOCK_METHOD0(reconnectingStream, void());
    MOCK_METHOD0(connectStream, void());
    MOCK_METHOD0(repliesQueue, std::shared_ptr<DataQueue<std::string>>());
    MOCK_METHOD1(setSeshId, void(std::string));
    MOCK_METHOD1(setProductIds, void(std::set<std::string>));
};