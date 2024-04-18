#pragma once

#include "DataQueue.h"
#include "IDatabank.h"
#include "IDatabaseHandler.h"
#include "SchwabStreamDataTypes.h"

#include <memory>
#include <mutex>
#include <thread>

namespace databank {

using namespace utils;
using namespace charting;
using namespace databasehandlers;

class SchwabDatabank : public IDatabank
{
public:
    SchwabDatabank(std::shared_ptr<IDatabaseHandler> dbHandler, std::shared_ptr<DataQueue<std::string>> streamqueue,
        std::string logfile = "");

    virtual void startParsing() override;
    virtual ChartData3 getChart(std::string symbol) override;

protected:
    void parseStreamQueue(unsigned count);
    void pushJsonDataToDb(const std::string jsondata);
    void updateMinuteCharts(const std::string symbol, const ChartEquity minuteCandle);
    void pushCandleToDb(const std::string symbol, const CandleStick candle);
    void updateLevelOneEquities(const std::string symbol, const LevelOneEquity levelOneE);
    std::shared_ptr<DataQueue<std::string>> streamqueue;
    std::string logfile;
    std::shared_ptr<IDatabaseHandler> dbHandler;
    std::mutex mtx;

    std::thread parsingThread;
    std::map<std::string, ChartData3> minuteCharts;
};
} // namespace databank