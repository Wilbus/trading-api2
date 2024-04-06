#pragma once

#include "WebSocket.h"
#include <memory>
#include <gmock/gmock.h>

namespace uWS{

namespace mocks{

template<bool isServer>
class WebSocketMock
{
public:
    WebSocketMock();
    ~WebSocketMock();
    MOCK_METHOD3(send, void(const char*, size_t, uWS::OpCode));

    static WebSocketMock<isServer>& inst();
};

template<bool isServer>
WebSocketMock<isServer>::WebSocketMock()
{
}

template<bool isServer>
WebSocketMock<isServer>::~WebSocketMock()
{
}

template<bool isServer>
WebSocketMock<isServer>& WebSocketMock<isServer>::inst()
{
    static std::unique_ptr<WebSocketMock<isServer>> mockPtr(new WebSocketMock<isServer>());
    return *(mockPtr).get();
}

}
}