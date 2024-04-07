#pragma once

#include "SchwabStreamHandler.h"
#include "WebSocketMock.h"
#include "schwabStreamResponseValues.h"

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

        const char* getRequestDataAtCurrentId()
        {
            return requestsIdStrMap[currentReqId].data();
        }

        size_t getRequestDataSizeAtCurrentId()
        {
            return requestsIdStrMap[currentReqId].size();
        }

        RequestId getCurrentReqid()
        {
            return currentReqId;
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
        send(handlerTestWrapper.getRequestDataPtr(0), handlerTestWrapper.getRequestDataSize(0), uWS::OpCode::TEXT));

    handlerTestWrapper.onConnectionCallback(someWebSocketInstance, {});
    EXPECT_EQ(handlerTestWrapper.getCurrentReqid(), 1);
}

TEST_F(SchwabStreamHandlerTest, onMessageLoginFailedResponse)
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

    EXPECT_THROW(handlerTestWrapper.onMessageCallback(
                     someWebSocketInstance, loginDeniedResponse.data(), loginDeniedResponse.size(), uWS::OpCode::TEXT),
        std::runtime_error);
}

TEST_F(SchwabStreamHandlerTest, onMessageResponse)
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

    /*Request qosReq;
    qosReq.serviceType = ServiceType::ADMIN;
    qosReq.requestid = 0;
    qosReq.commandType = CommandType::QOS;
    qosReq.schwabClientCustomerId = "customerId";
    qosReq.schwabClientCorrelId = "correlId";
    qosReq.parameters.qoslevel = "0";*/

    Request accActivityReq;
    accActivityReq.serviceType = ServiceType::ACCT_ACTIVITY;
    accActivityReq.requestid = 2;
    accActivityReq.commandType = CommandType::SUBS;
    accActivityReq.schwabClientCustomerId = "customerId";
    accActivityReq.schwabClientCorrelId = "correlId";
    accActivityReq.parameters.keys = "somekey";
    accActivityReq.parameters.fields = "0,1,2,3";

    Request levelOneActivityReq;
    levelOneActivityReq.serviceType = ServiceType::LEVELONE_EQUITIES;
    levelOneActivityReq.requestid = 2;
    levelOneActivityReq.commandType = CommandType::SUBS;
    levelOneActivityReq.schwabClientCustomerId = "customerId";
    levelOneActivityReq.schwabClientCorrelId = "correlId";
    levelOneActivityReq.parameters.keys = "QQQ";
    levelOneActivityReq.parameters.fields = "0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16";

    Request chartEquityReq;
    chartEquityReq.serviceType = ServiceType::CHART_EQUITY;
    chartEquityReq.requestid = 2;
    chartEquityReq.commandType = CommandType::SUBS;
    chartEquityReq.schwabClientCustomerId = "customerId";
    chartEquityReq.schwabClientCorrelId = "correlId";
    chartEquityReq.parameters.keys = "QQQ";
    chartEquityReq.parameters.fields = "0,1,2,3,4,5,6,7,8";

    Request optionReq;
    optionReq.serviceType = ServiceType::OPTION;
    optionReq.requestid = 2;
    optionReq.commandType = CommandType::SUBS;
    optionReq.schwabClientCustomerId = "customerId";
    optionReq.schwabClientCorrelId = "correlId";
    optionReq.parameters.keys = "QQQ";
    optionReq.parameters.fields = "0,1,2,3,4,5,6,7,8,9,10,11,12,20,21,22,23,24,32,33,34,35,36,38,41";

    map[0] = req;
    // map[1] = qosReq;
    map[1] = accActivityReq;
    // map[2] = levelOneActivityReq;
    // map[3] = chartEquityReq;
    // map[4] = optionReq;

    SchwabStreamHandlerTestWrapper handlerTestWrapper = SchwabStreamHandlerTestWrapper("wss://stream.com", map);

    EXPECT_CALL(WebSocketMock<uWS::CLIENT>::inst(),
        send(handlerTestWrapper.getRequestDataAtCurrentId(), handlerTestWrapper.getRequestDataSizeAtCurrentId(),
            uWS::OpCode::TEXT));
    handlerTestWrapper.onMessageCallback(
        someWebSocketInstance, loginResponse.data(), loginResponse.size(), uWS::OpCode::TEXT);

    EXPECT_CALL(WebSocketMock<uWS::CLIENT>::inst(),
        send(handlerTestWrapper.getRequestDataAtCurrentId(), handlerTestWrapper.getRequestDataSizeAtCurrentId(),
            uWS::OpCode::TEXT));
    handlerTestWrapper.onMessageCallback(
        someWebSocketInstance, acccountActivityResponse.data(), acccountActivityResponse.size(), uWS::OpCode::TEXT);

    EXPECT_CALL(WebSocketMock<uWS::CLIENT>::inst(),
        send(handlerTestWrapper.getRequestDataAtCurrentId(), handlerTestWrapper.getRequestDataSizeAtCurrentId(),
            uWS::OpCode::TEXT));
    handlerTestWrapper.onMessageCallback(
        someWebSocketInstance, levelOneEquitiesResponse.data(), levelOneEquitiesResponse.size(), uWS::OpCode::TEXT);

    EXPECT_CALL(WebSocketMock<uWS::CLIENT>::inst(),
        send(handlerTestWrapper.getRequestDataAtCurrentId(), handlerTestWrapper.getRequestDataSizeAtCurrentId(),
            uWS::OpCode::TEXT));
    handlerTestWrapper.onMessageCallback(
        someWebSocketInstance, chartEquityResponse.data(), chartEquityResponse.size(), uWS::OpCode::TEXT);

    EXPECT_CALL(WebSocketMock<uWS::CLIENT>::inst(),
        send(handlerTestWrapper.getRequestDataAtCurrentId(), handlerTestWrapper.getRequestDataSizeAtCurrentId(),
            uWS::OpCode::TEXT));
    handlerTestWrapper.onMessageCallback(
        someWebSocketInstance, optionResponse.data(), optionResponse.size(), uWS::OpCode::TEXT);
}