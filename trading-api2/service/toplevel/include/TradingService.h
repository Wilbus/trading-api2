#pragma once

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
    TradingService(std::string configFolder, std::string logFile);

    void start();

private:
    InfluxConnectionInfo influxConnectionInfo;
    std::string logFile;
    std::string configFolder;
    std::shared_ptr<SchwabConfigs> configs;
    std::shared_ptr<SchwabConnectionManager> manager;
    std::shared_ptr<SchwabDatabank> databank;
};

} // namespace tradingservice