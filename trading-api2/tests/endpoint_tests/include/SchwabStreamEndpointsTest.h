#pragma once

#include "Logger.h"
#include "RestClientCurl.h"
#include "SchwabClient.h"
#include "SchwabConnectionManager.h"
#include "SchwabStreamHandler.h"
#include "SchwabStreamReqGenerator.h"

#include <gtest/gtest.h>

#include <thread>

using namespace streamer;

class SchwabStreamEndpointsTest : public ::testing::Test
{
public:
    SchwabStreamEndpointsTest()
    {
        restclient =
            std::make_shared<RestClientCurl>("/home/wilbus/smbshare0/sambashare0/coding/trading-api2-endpoint-test-logs/", logfile);

        configs = std::make_shared<SchwabConfigs>("/home/wilbus/smbshare0/sambashare0/coding/configs/");
        sclient = std::make_shared<SchwabClient>(configs, restclient, logfile);
        manager = std::make_shared<SchwabConnectionManager>(configs, sclient, logfile);
    }

    void popQueue(std::shared_ptr<DataQueue<std::string>> queue, unsigned numberOfPops)
    {
        unsigned count = 0;
        while (true)
        {
            if (!queue->isEmpty())
            {
                // std::cout << "count: " << count << "\n";
                // std::cout << "dataqueue: " << queue->front() << "\n";
                // infologprint(logfile, "%s: count %u", __func__, count);
                // infologprint(logfile, "%s: %s", __func__, queue->front().c_str());
                // coutlog(logfile, "%s: %s", __func__, queue->front().c_str());
                std::cout << "DATA: " << queue->front().c_str() << "\n";
                queue->pop();
                count++;
            }
            if (numberOfPops != 0 &&
                count > numberOfPops) // we can incrase this if we want to increase how many mesages to test receive
                break;
        }
    }

    std::shared_ptr<RestClientCurl> restclient;
    std::shared_ptr<SchwabConfigs> configs;
    std::shared_ptr<SchwabClient> sclient;
    std::shared_ptr<SchwabStreamHandler> streamer;
    std::shared_ptr<SchwabConnectionManager> manager;
    std::string logfile = "/datadisk0/sambashare0/coding/trading-api2-endpoint-test-logs/endpoint_stream_testlog.txt";
};
#if 0
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

    /*Request qosReq;
    qosReq.serviceType = ServiceType::ADMIN;
    qosReq.requestid = 1;
    qosReq.commandType = CommandType::QOS;
    qosReq.schwabClientCustomerId = prefs.streamerInfo[0].schwabClientCustomerId;
    qosReq.schwabClientCorrelId = prefs.streamerInfo[0].schwabClientCorrelId;
    qosReq.parameters.qoslevel = "0";*/

    Request acctActivityReq;
    acctActivityReq.serviceType = ServiceType::ACCT_ACTIVITY;
    acctActivityReq.requestid = 1;
    acctActivityReq.commandType = CommandType::SUBS;
    acctActivityReq.schwabClientCustomerId = prefs.streamerInfo[0].schwabClientCustomerId;
    acctActivityReq.schwabClientCorrelId = prefs.streamerInfo[0].schwabClientCorrelId;
    acctActivityReq.parameters.keys = "somekey";
    acctActivityReq.parameters.fields = "0,1,2,3";

    Request levelOneActivityReq;
    levelOneActivityReq.serviceType = ServiceType::LEVELONE_EQUITIES;
    levelOneActivityReq.requestid = 2;
    levelOneActivityReq.commandType = CommandType::SUBS;
    levelOneActivityReq.schwabClientCustomerId = prefs.streamerInfo[0].schwabClientCustomerId;
    levelOneActivityReq.schwabClientCorrelId = prefs.streamerInfo[0].schwabClientCorrelId;
    levelOneActivityReq.parameters.keys = "QQQ";
    levelOneActivityReq.parameters.fields = "0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16";

    Request chartEquityReq;
    chartEquityReq.serviceType = ServiceType::CHART_EQUITY;
    chartEquityReq.requestid = 3;
    chartEquityReq.commandType = CommandType::SUBS;
    chartEquityReq.schwabClientCustomerId = prefs.streamerInfo[0].schwabClientCustomerId;
    chartEquityReq.schwabClientCorrelId = prefs.streamerInfo[0].schwabClientCorrelId;
    chartEquityReq.parameters.keys = "QQQ";
    chartEquityReq.parameters.fields = "0,1,2,3,4,5,6,7,8";

    Request optionReq;
    optionReq.serviceType = ServiceType::OPTION;
    optionReq.requestid = 4;
    optionReq.commandType = CommandType::SUBS;
    optionReq.schwabClientCustomerId = prefs.streamerInfo[0].schwabClientCustomerId;
    optionReq.schwabClientCorrelId = prefs.streamerInfo[0].schwabClientCorrelId;
    optionReq.parameters.keys = "QQQ";
    optionReq.parameters.fields = "0,1,2,3,4,5,6,7,8,9,10,11,12,20,21,22,23,24,32,33,34,35,36,38,41";

    map[0] = loginReq;
    // map[1] = qosReq;
    map[1] = acctActivityReq;
    map[2] = levelOneActivityReq;
    map[3] = chartEquityReq;
    map[4] = optionReq;

    streamer = std::make_shared<SchwabStreamHandler>("wss://streamer-api.schwab.com/ws", map);

    streamer->connectStream();
    std::thread streamThread(&SchwabStreamHandler::run, streamer.get());
    std::thread popThread(&SchwabStreamEndpointsTest::popQueue, this, streamer->repliesQueue());

    popThread.join();
    streamThread.join();
}
#endif

TEST_F(SchwabStreamEndpointsTest, schwabConnectionManagerContinuityTest)
{
    manager->buildAllRequests();
    manager->startThreadFuncThread();
    // manager->streamThreadFunc();

    std::thread popThread(&SchwabStreamEndpointsTest::popQueue, this, manager->getStreamer()->repliesQueue(), 0);
    // popThread.detach();

    popThread.join();
    manager->reconnectingStreamThread.join();
}

#if 0
TEST_F(SchwabStreamEndpointsTest, schwabConnectionManagerGroupCloseTest)
{
    manager->buildAllRequests();
    manager->startThreadFuncThread();
    // manager->streamThreadFunc();

    std::thread popThread(&SchwabStreamEndpointsTest::popQueue, this, manager->getStreamer()->repliesQueue(), 3);
    // popThread.detach();

    popThread.join();
    manager->getStreamer()->getGroupPtr()->close();
    
    manager->reconnectingStreamThread.join();
}
#endif