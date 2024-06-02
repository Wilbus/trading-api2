#pragma once

#include "RestClientCurl.h"
#include "SchwabClient.h"
#include "SchwabStreamDataTypes.h"
#include "SchwabStreamHandler.h"

#include <memory>
#include <thread>

using namespace streamer;

class SchwabConnectionManager
{
public:
    SchwabConnectionManager(std::shared_ptr<ISchwabConfigs> configs, std::shared_ptr<ISchwabClient> sclient,
        std::shared_ptr<DataQueue<std::string>> repliesQue, std::string logfile = "");
    SchwabConnectionManager(std::string configfolder, std::string logfile = "");

    void streamThreadFunc();
    void startThreadFuncThread();
    void buildAllRequests();

    std::shared_ptr<IStreamHandler> getStreamer();

    std::thread reconnectingStreamThread;

private:
    void connectAndRunStream();
    std::shared_ptr<ISchwabConfigs> configs;
    std::shared_ptr<ISchwabClient> sclient;
    std::shared_ptr<IStreamHandler> streamer;
    std::shared_ptr<DataQueue<std::string>> repliesQue;
    SchwabRequestsIdMap requestsMap;
    std::string logfile;
};