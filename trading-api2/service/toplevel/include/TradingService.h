#pragma once

#include "Logger.h"
#include "SchwabClient.h"
#include "SchwabConnectionManager.h"
#include "SchwabDatabank.h"
#include "SchwabDatabaseHandler.h"
#include "SimpleAgent.h"

namespace tradingservice {

using namespace databank;
using namespace databasehandlers;
using namespace streamer;

class TradingService
{
public:
    TradingService(std::string configFolder, std::string logFile);

    void start();

private:
    std::string logFile;
    std::string configFolder;
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