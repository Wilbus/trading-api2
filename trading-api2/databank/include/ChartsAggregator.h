#pragma once

#include "ChartAggregatorTypes.h"

#include <set>

namespace databank {

using namespace utils;

/*Keeps track of different timeframe charts
 Only updates by minute candles, and will update other timeframes accordingly*/
class ChartsAggregator
{
public:
    ChartsAggregator();
    ChartsAggregator(std::map<std::string, ChartTimeframesMap> charts);

    void addChart(std::string symbol, ChartData3 chart, Timeframe timeframe);
    void addMinuteCandle(std::string symbol, CandleStick candle);
    ChartData3 getChartData(std::string symbol, Timeframe timeframe) const;
    void initializeMinuteChart(std::string symbol, ChartData3 chart);
    ChartTimeframesMap getTimeframeCharts(std::string symbol) const;

private:
    void aggregateChartData(std::string symbol, Timeframe alignedOn);

    std::vector<MultiCandle> getLastNMinutes(std::string symbol, int n);

    std::map<std::string, ChartTimeframesMap> charts;
};

} // namespace databank