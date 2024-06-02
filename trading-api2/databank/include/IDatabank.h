#pragma once

#include "ChartsAggregator.h"

namespace databank {
using namespace charting;

class IDatabank
{
public:
    virtual void initializeData(std::set<std::string> symbols) = 0;
    virtual void startParsing() = 0;
    virtual ChartTimeframesMap getChart(std::string symbol) = 0;
    virtual std::vector<CandleStick> getCandlesFromDb(
        const std::string& symbol, const Timeframe& timeframe, const std::string& fromTime, const std::string& toTime) = 0;
    virtual std::vector<std::string> getJsonDataFromDb(const std::string& fromTime, const std::string& toTime) = 0;
    virtual std::vector<CandleStick> getCandlesFromClient(const std::string& symbol, const Timeframe timeframe,
        const std::string& fromTime, const std::string& toTime) = 0;
    virtual void pushCandleToDb(const std::string symbol, const Timeframe& timeframe, const CandleStick candle) = 0;
};
} // namespace databank