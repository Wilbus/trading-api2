#pragma once

#include "ChartData3.h"

#include <map>
#include <set>

namespace databank {

using namespace utils;
using namespace charting;

enum Timeframe
{
    MINUTE = 60,
    FIVE = 300,
    FIFTEEN = 900,
    THIRTY = 1800,
    HOURLY = 3600,

    /*DAILY doesn't work at the moment.
    This is a special case because we only have 8 hours in a trading session day
    and we need to align the candles to the trading session from 8:30am to 3:00pm*/
    DAILY = 28800
};

typedef std::map<Timeframe, ChartData3> ChartTimeframesMap;

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