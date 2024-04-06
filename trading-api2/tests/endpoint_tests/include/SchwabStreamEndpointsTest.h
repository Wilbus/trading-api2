#pragma once

#include "RestClientCurl.h"
#include "SchwabClient.h"
#include "SchwabStreamHandler.h"
#include "SchwabStreamReqGenerator.h"

#include <thread>

#include <gtest/gtest.h>

using namespace streamer;

class SchwabStreamEndpointsTest : public ::testing::Test
{
public:
    SchwabStreamEndpointsTest()
    {
        restclient = std::make_shared<RestClientCurl>("/datadisk0/sambashare0/coding/trading-api2-endpoint-test-logs/");

        configs = std::make_shared<SchwabConfigs>("/datadisk0/sambashare0/coding/configs/");
        sclient = std::make_shared<SchwabClient>(configs, restclient);
    }

    void popQueue(std::shared_ptr<DataQueue<std::string>> queue)
    {
        unsigned count = 0;
        while(true)
        {
            if(!queue->isEmpty())
            {
                std::cout << "count: " << count << "\n";
                std::cout << "response: " << queue->front() << "\n";
                queue->pop();
                count++;
            }
            if(count > 3) //we can incrase this if we want to increase how many mesages to test receive
                break;
        }
    }

    std::shared_ptr<RestClientCurl> restclient;
    std::shared_ptr<SchwabConfigs> configs;
    std::shared_ptr<SchwabClient> sclient;
    std::shared_ptr<SchwabStreamHandler> streamer;
};

TEST_F(SchwabStreamEndpointsTest, streamOutputTest)
{
    SchwabRequestsIdMap map;
    
    

    UserPreferences prefs = sclient->getUserPreferences();
    
    Request loginReq;
    loginReq.serviceType = ServiceType::ADMIN;
    loginReq.requestid = 0;
    loginReq.commandType = CommandType::LOGIN;
    loginReq.schwabClientCustomerId = prefs.streamerInfo[0].schwabClientCustomerId;
    loginReq.schwabClientCorrelId = prefs.streamerInfo[0].schwabClientCorrelId;
    loginReq.parameters.authorization = configs->getAccessToken().token;
    loginReq.parameters.schwabClientChannel = prefs.streamerInfo[0].schwabClientChannel;
    loginReq.parameters.schwabClientFunctionId = prefs.streamerInfo[0].schwabClientFunctionId;

    Request qosReq;
    qosReq.serviceType = ServiceType::ADMIN;
    qosReq.requestid = 1;
    qosReq.commandType = CommandType::QOS;
    qosReq.schwabClientCustomerId = prefs.streamerInfo[0].schwabClientCustomerId;
    qosReq.schwabClientCorrelId = loginReq.schwabClientCorrelId = prefs.streamerInfo[0].schwabClientCorrelId;
    qosReq.parameters.qoslevel = "0";

    Request acctActivityReq;
    acctActivityReq.serviceType = ServiceType::ACCT_ACTIVITY;
    acctActivityReq.requestid = 2;
    acctActivityReq.commandType = CommandType::SUBS;
    acctActivityReq.schwabClientCustomerId = prefs.streamerInfo[0].schwabClientCustomerId;
    acctActivityReq.schwabClientCorrelId = prefs.streamerInfo[0].schwabClientCorrelId;
    acctActivityReq.parameters.keys = "somekey";
    acctActivityReq.parameters.fields = "0,1,2,3";

    map[0] = loginReq;
    map[1] = qosReq;
    map[2] = acctActivityReq;

    streamer = std::make_shared<SchwabStreamHandler>("wss://streamer-api.schwab.com/ws", map);

    streamer->connectStream();
    std::thread streamThread(&SchwabStreamHandler::run, streamer.get());
    std::thread popThread(&SchwabStreamEndpointsTest::popQueue, this, streamer->repliesQueue());

    popThread.join();
    streamThread.join();
}
