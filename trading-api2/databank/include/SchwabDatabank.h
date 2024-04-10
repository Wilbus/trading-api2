#pragma once

#include "DataQueue.h"
#include "IDatabank.h"
#include "SchwabStreamDataTypes.h"

#include <memory>
#include <mutex>

namespace databank {

using namespace utils;
using namespace charting;

class SchwabDatabank : public IDatabank
{
public:
    SchwabDatabank(std::shared_ptr<DataQueue<std::string>> streamqueue, std::string logfile = "");

    virtual void startParsing() override;
    virtual ChartData3 getChart(std::string symbol) override;

protected:
    void parseStreamQueue(unsigned count);
    void updateMinuteCharts(const std::string symbol, const ChartEquity minuteCandle);
    void updateLevelOneEquities(const std::string symbol, const LevelOneEquity levelOneE);
    std::shared_ptr<DataQueue<std::string>> streamqueue;
    std::string logfile;
    std::mutex mtx;

    std::map<std::string, ChartData3> minuteCharts;
};
} // namespace databank