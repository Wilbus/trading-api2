#pragma once

#include "ChartData3.h"

#include <map>

namespace databank {
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

static const std::map<Timeframe, std::string> timeFrameStrings = {
    {Timeframe::MINUTE, "minute"},
    {Timeframe::FIVE, "five"},
    {Timeframe::FIFTEEN, "fifteen"},
    {Timeframe::THIRTY, "thirty"},
    {Timeframe::HOURLY, "hourly"},
    {Timeframe::DAILY, "daily"}
};

typedef std::map<Timeframe, ChartData3> ChartTimeframesMap;
} // namespace databank