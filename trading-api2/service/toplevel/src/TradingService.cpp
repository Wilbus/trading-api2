#include "TradingService.h"

namespace tradingservice
{

TradingService::TradingService(std::string configFolder, std::string logFile)
    : influxConnectionInfo{
        "devtesterv1",
        "123456789",
        "192.168.0.130:8086",
        "dev-testing-v1",
        "N-q3KQNK6HEmUqj2bDwflK_08BQINRLTLlGsZhBrjQyFIQjVAK9AgCZtDjPEHD7IF7AWh20PPhgwAOaSXxyswQ=="}
    , logFile(logFile)
    , configFolder(configFolder)
    , manager(std::make_shared<SchwabConnectionManager>(configFolder, logFile))

{
    infologprint(logFile, "%s: init", __func__);
}

void TradingService::start()
{
    manager->buildAllRequests();
    manager->startThreadFuncThread();

    databank = std::make_shared<SchwabDatabank>(
        std::make_shared<SchwabDatabaseHandler>(influxConnectionInfo), manager->getStreamer()->repliesQueue(), logFile);
    databank->startParsing();

    manager->reconnectingStreamThread.join();
}

}