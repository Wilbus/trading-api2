#include "CandleSampler.h"

#include <algorithm>

namespace charting {

CandleSampler::CandleSampler()
{
}

std::optional<CandleStick> CandleSampler::sampleTicker(Trade match)
{
    uint64_t unixtime = match.date;

    if (currentCandleUnixMs == 0)
    {
        currentCandleUnixMs = unixtime - (unixtime % 60000);
        expectedNextCandleUnixMs = currentCandleUnixMs + 60000;
    }

    std::optional<CandleStick> newCandle;
    if (unixtime >= expectedNextCandleUnixMs)
    {
        newCandle = finishCandle();
        orderedMatches.clear();

        orderedMatches.push_back(match); // this is the start of next interval
        currentCandleUnixMs = expectedNextCandleUnixMs;
        expectedNextCandleUnixMs = currentCandleUnixMs + 60000;

        return newCandle;
    }
    else
    {
        orderedMatches.push_back(match);
    }

    return {};
}

CandleStick CandleSampler::finishCandle()
{
    unsigned counter = 0;
    CandleStick newCandle;
    newCandle.reset();
    for (auto match = orderedMatches.begin(); match != orderedMatches.end(); ++match)
    {
        // infolog(logger, "finishing candle: %s, %.02f", match->time.c_str(), match->price);
        if (match == orderedMatches.begin())
        {
            newCandle.price_open = match->price;
            /*low or high can be open price*/
            // newCandle.price_low = std::min(newCandle.price_low, match->second.price);
            // newCandle.price_high = std::max(newCandle.price_high, match->second.price);
        }
        else if (match == (--orderedMatches.end()))
        {
            newCandle.price_close = match->price;
            // newCandle.price_low = std::min(newCandle.price_low, match->second.price);
            // newCandle.price_high = std::max(newCandle.price_high, match->second.price);
        }

        newCandle.price_low = std::min(newCandle.price_low, match->price);
        newCandle.price_high = std::max(newCandle.price_high, match->price);
        newCandle.volume += match->size;
        counter++;
    }
    newCandle.timestamp = currentCandleUnixMs; // start time of candlestick
    newCandle.product_id = product_id;

    return newCandle;
}

} // namespace charting