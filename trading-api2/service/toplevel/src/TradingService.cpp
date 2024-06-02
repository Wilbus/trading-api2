#include "TradingService.h"

#include "SimpleAgent.h"
#include "TestAgent.h"

namespace tradingservice {

TradingService::TradingService(std::string configFolder, bool isBacktest, std::string logFile)
    : logFile(logFile)
    , configFolder(configFolder)
    , isBacktest(isBacktest)
    , repliesQueue(std::make_shared<DataQueue<std::string>>())
    , configs(std::make_shared<SchwabConfigs>(configFolder))
    , sClient(std::make_shared<SchwabClient>(configs, std::make_shared<RestClientCurl>(), logFile))
    , manager(std::make_shared<SchwabConnectionManager>(configs, sClient, repliesQueue, logFile))
{
    infologprint(logFile, "%s: init", __func__);

    auto influxConf = configs->getInfluxConnectionConfig();
    influxConnectionInfo = InfluxConnectionInfo{
        influxConf.user, influxConf.pass, influxConf.host, influxConf.dbname, influxConf.authToken};

    databank = std::make_shared<SchwabDatabank>(
        sClient, std::make_shared<SchwabDatabaseHandler>(influxConnectionInfo), repliesQueue, logFile);

    auto subConf = configs->getSubscribeConfig();
    for (const auto& symbol : subConf.chartEquities.symbols)
    {
        chartSymbols.insert(symbol);
    }

    databank->initializeData(chartSymbols);

    agents.push_back(std::make_shared<SimpleAgent>(sClient, databank, chartSymbols, "simpleAgent", logFile));
    agents.push_back(std::make_shared<TestAgent>(sClient, databank, chartSymbols, "testAgent", logFile));
}

void TradingService::start()
{
    if(!isBacktest)
    {
        startTrading();
    }
    else
    {
        startBacktest();
    }
}

void TradingService::startTrading()
{
    manager->startThreadFuncThread();

    databank->startParsing();
    for (auto& agent : agents)
    {
        agent->startAgent();
    }

    manager->reconnectingStreamThread.join();
    for (auto& agent : agents)
    {
        agent->waitForAgent();
    }
}

void TradingService::startBacktest()
{
    for (auto& agent : agents)
    {
        agent->startBackTest();
    }
}

} // namespace tradingservice