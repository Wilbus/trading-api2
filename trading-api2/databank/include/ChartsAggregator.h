#pragma once

//#include "AggregateTypes.h"
#include "ChartData3.h"
#include <set>
#include <map>

namespace databank
{

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

struct MultiTimeframeChartData3
{
    ChartData3 daily;
    ChartData3 hourly;
    ChartData3 thirty;
    ChartData3 fifteen;
    ChartData3 five;
    ChartData3 minute;
};

typedef std::map<Timeframe, ChartData3> ChartTimeframesMap;

class ChartsAggregator
{
public:
    
    ChartsAggregator();
    ChartsAggregator(std::map<std::string, ChartTimeframesMap> charts);

    void addChart(std::string symbol, ChartData3 chart, Timeframe timeframe);
    void addMinuteCandle(std::string symbol, CandleStick candle);
    ChartData3 getChartData(std::string symbol, Timeframe timeframe) const;
    void initializeMinuteChart(std::string symbol, ChartData3 chart);

private:
    void aggregateChartData(std::string symbol, Timeframe alignedOn);

    std::vector<MultiCandle> getLastNMinutes(std::string symbol, int n);

    std::map<std::string, ChartTimeframesMap> charts;
};

}