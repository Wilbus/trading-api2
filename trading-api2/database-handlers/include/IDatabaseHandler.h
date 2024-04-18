#pragma once

#include "CandleStick.h"

namespace databasehandlers {

using namespace charting;

class IDatabaseHandler
{
public:
    virtual void pushCandle(const std::string& symbol, const CandleStick& candle) = 0;
    virtual std::vector<CandleStick> getCandles(
        const std::string& symbol, const std::string& fromTime, const std::string& toTime) = 0;

    virtual void pushJsonData(const std::string& data) = 0;
    virtual std::vector<std::string> getJsonData(const std::string& fromTime, const std::string& toTime) = 0;
};
} // namespace databasehandlers