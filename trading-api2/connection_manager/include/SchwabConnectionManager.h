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
    // testing
    SchwabConnectionManager(
        std::shared_ptr<ISchwabConfigs> configs, std::shared_ptr<ISchwabClient> sclient, std::string logfile = "");
    // production
    SchwabConnectionManager(std::string configfolder);

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
    SchwabRequestsIdMap requestsMap;
    std::string logfile;
};