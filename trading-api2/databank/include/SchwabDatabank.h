#pragma once

#include "DataQueue.h"
#include "IDatabank.h"
#include "IDatabaseHandler.h"
#include "SchwabClient.h"
#include "SchwabStreamDataTypes.h"

#include <memory>
#include <mutex>
#include <thread>

namespace databank {

using namespace utils;
using namespace charting;
using namespace databasehandlers;
using SchwabOptionChain = schwabMarketData::OptionChain;

class SchwabDatabank : public IDatabank
{
public:
    SchwabDatabank(std::shared_ptr<ISchwabClient> sclient, std::shared_ptr<IDatabaseHandler> dbHandler,
        std::shared_ptr<DataQueue<std::string>> streamqueue, std::string logfile = "");

    virtual void initializeData(std::set<std::string> symbols) override;
    virtual void initializeDataFromDb(std::set<std::string> symbols, std::string fromTime, std::string toTime) override;
    virtual void startParsing() override;
    virtual ChartTimeframesMap getChart(std::string symbol) override;
    virtual std::vector<CandleStick> getCandlesFromDb(const std::string& symbol, const Timeframe& timeframe,
        const std::string& fromTime, const std::string& toTime) override;
    virtual std::vector<std::string> getJsonDataFromDb(const std::string& fromTime, const std::string& toTime) override;
    virtual std::vector<CandleStick> getCandlesFromClient(const std::string& symbol, const Timeframe timeframe,
        const std::string& fromTime, const std::string& toTime) override;
    virtual std::vector<CandleStick> getCandlesFromClient(const std::string& symbol, const Timeframe timeframe,
        const uint64_t& fromTime, const uint64_t& toTime) override;
    virtual void pushCandleToDb(
        const std::string symbol, const Timeframe& timeframe, const CandleStick candle) override;
    virtual OptionChain getOptionChain(const std::string& symbol, unsigned strikes) override;

protected:
    virtual void parseStreamQueue(unsigned count);
    void pushJsonDataToDb(const std::string jsondata);
    void updateMinuteCharts(const std::string symbol, const ChartEquity minuteCandle);
    void pushCandleToDb(const std::string symbol, const CandleStick candle);
    void updateLevelOneEquities(const std::string symbol, const LevelOneEquity levelOneE);
    std::shared_ptr<DataQueue<std::string>> streamqueue;
    std::string logfile;
    std::shared_ptr<IDatabaseHandler> dbHandler;
    std::shared_ptr<ChartsAggregator> chartsAggregator;
    std::shared_ptr<ISchwabClient> sClient;

    std::mutex mtx;
    std::thread parsingThread;
};
} // namespace databank