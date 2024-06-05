#pragma once

#include "ChartsAggregator.h"
#include "Option.h"

namespace databank {
using namespace charting;

using OptionChain = charting::OptionChain;

class IDatabank
{
public:
    // TODO: combine initialize functions into one
    virtual void initializeData(std::set<std::string> symbols) = 0;
    virtual void initializeDataFromDb(std::set<std::string> symbols, std::string fromTime, std::string toTime) = 0;
    virtual void startParsing() = 0;
    virtual ChartTimeframesMap getChart(std::string symbol) = 0;
    virtual std::vector<CandleStick> getCandlesFromDb(const std::string& symbol, const Timeframe& timeframe,
        const std::string& fromTime, const std::string& toTime) = 0;
    virtual std::vector<std::string> getJsonDataFromDb(const std::string& fromTime, const std::string& toTime) = 0;
    virtual std::vector<CandleStick> getCandlesFromClient(const std::string& symbol, const Timeframe timeframe,
        const std::string& fromTime, const std::string& toTime) = 0;
    virtual std::vector<CandleStick> getCandlesFromClient(
        const std::string& symbol, const Timeframe timeframe, const uint64_t& fromTime, const uint64_t& toTime) = 0;
    virtual void pushCandleToDb(const std::string symbol, const Timeframe& timeframe, const CandleStick candle) = 0;
    virtual OptionChain getOptionChain(const std::string& symbol, unsigned strikes) = 0;
};
} // namespace databank