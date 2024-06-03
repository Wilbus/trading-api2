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
}

TradingService::TradingService(std::string configFolder, bool isBacktest, std::string initializeFromTime, std::string intializeToTime, std::string logFile)
    : logFile(logFile)
    , configFolder(configFolder)
    , isBacktest(isBacktest)
    , initializeFromTime(initializeFromTime)
    , initializeToTime(intializeToTime)
    , repliesQueue(std::make_shared<DataQueue<std::string>>())
    , configs(std::make_shared<SchwabConfigs>(configFolder))
    , sClient(std::make_shared<SchwabClient>(configs, std::make_shared<RestClientCurl>(), logFile))
    , manager(std::make_shared<SchwabConnectionManager>(configs, sClient, repliesQueue, logFile))
{
    infologprint(logFile, "%s: init", __func__);
}

void TradingService::setup()
{
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

    if(!isBacktest)
    {
        databank->initializeData(chartSymbols);
    }
    else
    {
        if(initializeFromTime.empty() || initializeToTime.empty())
        {
            throw std::runtime_error("initializeFromTime and initializeToTime must be set for backtest");
        }
        databank->initializeDataFromDb(chartSymbols, initializeFromTime, initializeToTime);
    }

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