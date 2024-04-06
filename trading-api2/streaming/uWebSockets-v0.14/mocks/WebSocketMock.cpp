#include "WebSocketMock.h"
#include "WebSocket.h"
#include <memory>

namespace uWS {

//template <bool isServer>
template <>
void WebSocket<uWS::CLIENT>::send(const char *message, size_t length, OpCode opCode,
    void(*callback)(WebSocket<uWS::CLIENT> *webSocket, void *data, bool cancelled,
    void *reserved), void *callbackData, bool compress)
{
    return uWS::mocks::WebSocketMock<uWS::CLIENT>::inst().send(message, length, opCode);
}

//template <bool isServer>
template <>
void WebSocket<uWS::SERVER>::send(const char *message, size_t length, OpCode opCode,
    void(*callback)(WebSocket<uWS::SERVER> *webSocket, void *data, bool cancelled,
    void *reserved), void *callbackData, bool compress)
{
    std::cout << "mock\n";
    return uWS::mocks::WebSocketMock<uWS::SERVER>::inst().send(message, length, opCode);
}

namespace mocks {

}
} // namespace mocks