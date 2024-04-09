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
    virtual ChartData2 getChart(std::string symbol) override;

private:
    void parseStreamQueue();
    void updateMinuteCharts(const std::string symbol, const ChartEquity minuteCandle);
    std::shared_ptr<DataQueue<std::string>> streamqueue;
    std::string logfile;
    std::mutex mtx;

    std::map<std::string, ChartData2> minuteCharts;
};
} // namespace databank