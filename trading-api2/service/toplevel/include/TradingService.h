#pragma once

#include "IAgent.h"
#include "Logger.h"
#include "SchwabClient.h"
#include "SchwabConnectionManager.h"
#include "SchwabDatabank.h"
#include "SchwabDatabaseHandler.h"

namespace tradingservice {

using namespace databank;
using namespace databasehandlers;
using namespace streamer;

class TradingService
{
public:
    TradingService(std::string configFolder, bool isBacktest, std::string logFile);
    TradingService(std::string configFolder, bool isBacktest, std::string initializeFromTime, std::string initializeToTime, std::string logFile);

    void setup();
    void start();

private:
    void startTrading();
    void startBacktest();

    std::string logFile;
    std::string configFolder;
    bool isBacktest;
    std::string initializeFromTime;
    std::string initializeToTime;
    std::shared_ptr<DataQueue<std::string>> repliesQueue;
    std::shared_ptr<SchwabConfigs> configs;
    std::shared_ptr<SchwabClient> sClient;
    std::shared_ptr<SchwabConnectionManager> manager;
    InfluxConnectionInfo influxConnectionInfo;
    std::shared_ptr<SchwabDatabank> databank;
    std::set<std::string> chartSymbols;

    std::vector<std::shared_ptr<IAgent>> agents;
};

} // namespace tradingservice