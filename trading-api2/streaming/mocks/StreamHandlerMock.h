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
    MOCK_METHOD4(onMessageCallback, void(uWS::WebSocket<uWS::CLIENT>*, char*, size_t, uWS::OpCode));
    MOCK_METHOD4(onDisconnectionCallback, void(uWS::WebSocket<uWS::CLIENT>*, int, char*, size_t));
    MOCK_METHOD1(onErrorCallback, void(void*));
    MOCK_METHOD0(reconnectingStream, void());
    MOCK_METHOD0(connectStream, void());
    MOCK_METHOD0(repliesQueue, std::shared_ptr<DataQueue<std::string>>());
};