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
    std::shared_ptr<SchwabClient> sClient = std::make_shared<SchwabClient>(configs, std::make_shared<RestClientCurl>(), logFile);
    auto influxConf = configs->getInfluxConnectionConfig();
    influxConnectionInfo = InfluxConnectionInfo{influxConf.user, influxConf.pass, influxConf.host, influxConf.dbname, influxConf.authToken};
    
    databank = std::make_shared<SchwabDatabank>(sClient,
        std::make_shared<SchwabDatabaseHandler>(influxConnectionInfo), manager->getStreamer()->repliesQueue(), logFile);


    manager = std::make_shared<SchwabConnectionManager>(configs, sClient, logFile);
    manager->buildAllRequests();
    manager->startThreadFuncThread();


    databank->startParsing();

    manager->reconnectingStreamThread.join();
}

}