#pragma once

#include "CandleStick.h"
#include "TradierStructs.h"

#include <ctime>
#include <iomanip>
#include <map>
#include <optional>

namespace charting {

using namespace tradierstructs;

enum NewCandleInterval
{
    ONE_MINUTE = 0,
    FIVE_MINUTE,
};

class CandleSampler
{
public:
    CandleSampler();
    CandleSampler(std::string product_id);
    CandleSampler(NewCandleInterval updateInterval, uint64_t previousUnixTime);
    std::optional<CandleStick> sampleTicker(Trade matchdata);
    CandleStick finishCandle();

private:
    std::vector<Trade> orderedMatches;
    uint64_t currentCandleUnixMs{0};
    uint64_t expectedNextCandleUnixMs{0};
    std::string product_id;
    // CandleStick bufferCandle;
};
} // namespace charting