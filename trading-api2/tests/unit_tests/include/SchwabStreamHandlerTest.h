#pragma once

#include "SchwabStreamHandler.h"
#include "WebSocketMock.h"

#include <gtest/gtest.h>

using namespace streamer;
using namespace uWS::mocks;

// TODO: perhaps add more complete tests for behavior of creating
// groups and websocket instances. For now we are testing if correct requests are made
class SchwabStreamHandlerTest : public ::testing::Test
{
    /*A hack to be able to get the pointer to the request data string out of the requestIdsMap
     to compare against the websocket->send(const char* ... ) calls*/
public:
    class SchwabStreamHandlerTestWrapper : public SchwabStreamHandler
    {
    public:
        SchwabStreamHandlerTestWrapper(std::string url, SchwabRequestsIdMap map)
            : SchwabStreamHandler(url, map)
        {
        }

        const char* getRequestDataPtr(RequestId id)
        {
            return requestsIdStrMap.at(id).data();
        }

        size_t getRequestDataSize(RequestId id)
        {
            return requestsIdStrMap.at(id).size();
        }
    };
    SchwabStreamHandlerTest()
    {
        someWebSocketInstance = (uWS::WebSocket<uWS::CLIENT>*)0xdeadbeef;
    }

    uWS::WebSocket<uWS::CLIENT>* someWebSocketInstance;
};

TEST_F(SchwabStreamHandlerTest, noLoginRequestOnConnectionThrows)
{
    SchwabRequestsIdMap map;
    std::shared_ptr<SchwabStreamHandler> handler = std::make_shared<SchwabStreamHandler>("wss://stream.com", map);

    EXPECT_THROW(handler->onConnectionCallback(someWebSocketInstance, {}), std::runtime_error);
}

TEST_F(SchwabStreamHandlerTest, loginRequestOnConnection)
{
    SchwabRequestsIdMap map;
    Request req;
    req.serviceType = ServiceType::ADMIN;
    req.requestid = 0;
    req.commandType = CommandType::LOGIN;
    req.schwabClientCustomerId = "customerId";
    req.schwabClientCorrelId = "correlId";
    req.parameters.authorization = "accessToken";
    req.parameters.schwabClientChannel = "clientChannel";
    req.parameters.schwabClientFunctionId = "clientFunctionId";

    map[0] = req;

    SchwabStreamHandlerTestWrapper handlerTestWrapper = SchwabStreamHandlerTestWrapper("wss://stream.com", map);

    EXPECT_CALL(WebSocketMock<uWS::CLIENT>::inst(),
        send(handlerTestWrapper.getRequestDataPtr(0), handlerTestWrapper.getRequestDataSize(0),
            uWS::OpCode::TEXT));
    handlerTestWrapper.onConnectionCallback(someWebSocketInstance, {});
}

TEST_F(SchwabStreamHandlerTest, onMessageResponse)
{
    
}