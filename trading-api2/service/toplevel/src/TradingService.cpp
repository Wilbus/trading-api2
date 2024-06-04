#include "TradingService.h"

#include "SimpleAgent.h"
#include "TestAgent.h"
#include "SchwabDatabank.h"
#include "SchwabJsonDataRecorder.h"
#include "Logger.h"

namespace tradingservice {

TradingService::TradingService(std::string configFolder, TradingServiceMode tradingServiceMode, std::string logFile)
    : logFile(logFile)
    , configFolder(configFolder)
    , tradingServiceMode(tradingServiceMode)
    , repliesQueue(std::make_shared<DataQueue<std::string>>())
    , configs(std::make_shared<SchwabConfigs>(configFolder))
    , sClient(std::make_shared<SchwabClient>(configs, std::make_shared<RestClientCurl>(), logFile))
    , manager(std::make_shared<SchwabConnectionManager>(configs, sClient, repliesQueue, logFile))
{
    infologprint(logFile, "%s: init", __func__);
}

TradingService::TradingService(std::string configFolder, TradingServiceMode tradingServiceMode, std::string initializeFromTime,
    std::string intializeToTime, std::string logFile)
    : logFile(logFile)
    , configFolder(configFolder)
    , tradingServiceMode(tradingServiceMode)
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

    switch(tradingServiceMode)
    {
        case TradingServiceMode::Backtest:
            setupForBacktest();
            break;
        case TradingServiceMode::Live:
            setupForLive();
            break;
        case TradingServiceMode::RecordData:
            setupForRecordData();
            break;
        default:
            throw std::runtime_error("Invalid TradingServiceMode");
            break;
    }
}

void TradingService::start()
{
    switch(tradingServiceMode)
    {
        case TradingServiceMode::Backtest:
            startBacktest();
            break;
        case TradingServiceMode::Live:
        case TradingServiceMode::RecordData:
            startTrading();
            break;
        default:
            throw std::runtime_error("Invalid TradingServiceMode");
            break;
    }
}

void TradingService::startTrading()
{
    infologprint(logFile, "%s: starting trading", __func__);
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

void TradingService::setupForLive()
{
    infologprint(logFile, "%s: setting up for live trading", __func__);
    databank = std::make_shared<SchwabDatabank>(
        sClient, std::make_shared<SchwabDatabaseHandler>(influxConnectionInfo), repliesQueue, logFile);

    auto subConf = configs->getSubscribeConfig();
    for (const auto& symbol : subConf.chartEquities.symbols)
    {
        chartSymbols.insert(symbol);
    }

    databank->initializeData(chartSymbols);

    //agents.push_back(std::make_shared<SimpleAgent>(sClient, databank, chartSymbols, "simpleAgent", logFile));
    agents.push_back(std::make_shared<TestAgent>(sClient, databank, chartSymbols, "testAgent", logFile));
}

void TradingService::setupForBacktest()
{
    databank = std::make_shared<SchwabDatabank>(
        sClient, std::make_shared<SchwabDatabaseHandler>(influxConnectionInfo), repliesQueue, logFile);

    auto subConf = configs->getSubscribeConfig();
    for (const auto& symbol : subConf.chartEquities.symbols)
    {
        chartSymbols.insert(symbol);
    }

    if (initializeFromTime.empty() || initializeToTime.empty())
    {
        throw std::runtime_error("initializeFromTime and initializeToTime must be set for backtest");
    }
    databank->initializeDataFromDb(chartSymbols, initializeFromTime, initializeToTime);

    //agents.push_back(std::make_shared<SimpleAgent>(sClient, databank, chartSymbols, "simpleAgent", logFile));
    agents.push_back(std::make_shared<TestAgent>(sClient, databank, chartSymbols, "testAgent", logFile));
}

void TradingService::setupForRecordData()
{
    databank = std::make_shared<SchwabJsonDataRecorder>(
        sClient, std::make_shared<SchwabDatabaseHandler>(influxConnectionInfo), repliesQueue, logFile);
} 

}// namespace tradingservice