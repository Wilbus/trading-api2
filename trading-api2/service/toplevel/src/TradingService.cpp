#include "TradingService.h"

namespace tradingservice
{

TradingService::TradingService(std::string configFolder, std::string logFile)
    : logFile(logFile)
    , configFolder(configFolder)
    , configs(std::make_shared<SchwabConfigs>(configFolder))
{
    infologprint(logFile, "%s: init", __func__);
}

void TradingService::start()
{
    auto influxConf = configs->getInfluxConnectionConfig();
    influxConnectionInfo = InfluxConnectionInfo{influxConf.user, influxConf.pass, influxConf.host, influxConf.dbname, influxConf.authToken};

    manager = std::make_shared<SchwabConnectionManager>(configFolder, logFile);
    manager->buildAllRequests();
    manager->startThreadFuncThread();

    databank = std::make_shared<SchwabDatabank>(
        std::make_shared<SchwabDatabaseHandler>(influxConnectionInfo), manager->getStreamer()->repliesQueue(), logFile);
    databank->startParsing();

    manager->reconnectingStreamThread.join();
}

}