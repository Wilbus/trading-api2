#include "TradingService.h"

namespace tradingservice {

TradingService::TradingService(std::string configFolder, std::string logFile)
    : logFile(logFile)
    , configFolder(configFolder)
    , repliesQueue(std::make_shared<DataQueue<std::string>>())
    , configs(std::make_shared<SchwabConfigs>(configFolder))
    , sClient(std::make_shared<SchwabClient>(configs, std::make_shared<RestClientCurl>(), logFile))
    , manager(std::make_shared<SchwabConnectionManager>(configs, sClient, repliesQueue, logFile))
{
    infologprint(logFile, "%s: init", __func__);

    auto influxConf = configs->getInfluxConnectionConfig();
    influxConnectionInfo = InfluxConnectionInfo{
        influxConf.user, influxConf.pass, influxConf.host, influxConf.dbname, influxConf.authToken};

    databank = std::make_shared<SchwabDatabank>(sClient, std::make_shared<SchwabDatabaseHandler>(influxConnectionInfo),
        repliesQueue, logFile);

    auto subConf = configs->getSubscribeConfig();
    for(const auto& symbol : subConf.chartEquities.symbols)
    {
        chartSymbols.insert(symbol);
    }

    databank->initializeData(chartSymbols);

}

void TradingService::start()
{
    manager->startThreadFuncThread();

    databank->startParsing();

    manager->reconnectingStreamThread.join();
}

} // namespace tradingservice