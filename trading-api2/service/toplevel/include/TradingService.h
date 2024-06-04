#pragma once

#include "IAgent.h"
#include "Logger.h"
#include "SchwabClient.h"
#include "SchwabConnectionManager.h"
#include "SchwabDatabaseHandler.h"
#include "IDatabank.h"

namespace tradingservice {

using namespace databank;
using namespace databasehandlers;
using namespace streamer;

enum class TradingServiceMode
{
    Backtest,
    Live,
    RecordData
};

const std::map<std::string, TradingServiceMode> tradingServiceModeMap = {
    {"Backtest", TradingServiceMode::Backtest},
    {"Live", TradingServiceMode::Live},
    {"RecordData", TradingServiceMode::RecordData},
};

class TradingService
{
public:
    TradingService(std::string configFolder, TradingServiceMode tradingServiceMode, std::string logFile);
    TradingService(std::string configFolder, TradingServiceMode tradingServiceMode, std::string initializeFromTime,
        std::string initializeToTime, std::string logFile);

    void setup();
    void start();

private:
    void startTrading();
    void startBacktest();

    void setupForLive();
    void setupForBacktest();
    void setupForRecordData();

    std::string logFile;
    std::string configFolder;
    TradingServiceMode tradingServiceMode;
    std::string initializeFromTime;
    std::string initializeToTime;
    std::shared_ptr<DataQueue<std::string>> repliesQueue;
    std::shared_ptr<SchwabConfigs> configs;
    std::shared_ptr<SchwabClient> sClient;
    std::shared_ptr<SchwabConnectionManager> manager;
    InfluxConnectionInfo influxConnectionInfo;
    std::shared_ptr<IDatabank> databank;
    std::set<std::string> chartSymbols;

    std::vector<std::shared_ptr<IAgent>> agents;
};

} // namespace tradingservice