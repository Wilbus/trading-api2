#include "LiveMarketHandler.h"

#include "MarketDataSingleton.h"

void LiveMarketHandler::handleRealTimeBar(RealTimeBar b)
{
    auto symbol = reqIdtoSymbolMap.at(b.reqId);
    std::printf("%s %ld O: %.02f, H: %.02f, L: %.02f, C: %.02f, %s\n", symbol.c_str(), b.time, b.open, b.high, b.low,
        b.close, DecimalFunctions::decimalStringToDisplay(b.volume).c_str());

    auto c = CandleStick(b.time, b.low, b.high, b.open, b.close, DecimalFunctions::decimalToDouble(b.volume));
    storeCandle(symbol, c);
}

void LiveMarketHandler::handleHistoricalData(TickerId reqId, const Bar& bar)
{
    std::printf("%s: %ld, %s\n", __func__, reqId, bar.time.c_str());
}

void LiveMarketHandler::handleHistoricalDataEnd(int reqId, std::string& startDateStr, std::string& endDateStr)
{
    std::printf("%s: %d, %s, %s\n", __func__, reqId, startDateStr.c_str(), endDateStr.c_str());
}

void LiveMarketHandler::handleHistoricalDataUpdate(TickerId reqId, const Bar& bar)
{
    std::printf("%s: %ld, %s\n", __func__, reqId, bar.time.c_str());
}

void LiveMarketHandler::storeCandle(std::string symbol, CandleStick c)
{
    std::lock_guard<std::mutex> lock(candlesMapMutex);
    fiveSecondCandlesMap[symbol] = c;
}

CandleStick LiveMarketHandler::getCurrentCandle(std::string symbol)
{
    std::lock_guard<std::mutex> lock(candlesMapMutex);
    return fiveSecondCandlesMap[symbol];
}

void LiveMarketHandler::addSymbol(int id, std::string symbol)
{
    reqIdtoSymbolMap[id] = symbol;
    realTimeBarBuffRecord[symbol] = RealTimeBarBuff(0, 0, std::vector<RealTimeBar>{});
}

std::optional<CandleStick> LiveMarketHandler::sampleRealTimeBar(std::string symbol, RealTimeBar b)
{
    uint64_t unixtime = b.time;

    if (realTimeBarBuffRecord[symbol].currentUnixS == 0) // init first time
    {
        realTimeBarBuffRecord[symbol].currentUnixS = unixtime - (unixtime % 60);
        realTimeBarBuffRecord[symbol].expectedNextS = realTimeBarBuffRecord[symbol].currentUnixS + 60;
    }

    std::optional<CandleStick> newCandle;
    if (unixtime >= realTimeBarBuffRecord[symbol].expectedNextS)
    {
        newCandle = finishCandle(symbol);
        realTimeBarBuffRecord[symbol].barsBuff.clear();

        realTimeBarBuffRecord[symbol].barsBuff.push_back(b); // this is the start of next interval
        realTimeBarBuffRecord[symbol].currentUnixS = realTimeBarBuffRecord[symbol].expectedNextS;
        realTimeBarBuffRecord[symbol].expectedNextS = realTimeBarBuffRecord[symbol].currentUnixS + 60;

        return newCandle;
    }
    else
    {
        realTimeBarBuffRecord[symbol].barsBuff.push_back(b);
    }

    return {};
}

CandleStick LiveMarketHandler::finishCandle(std::string symbol)
{
    unsigned counter = 0;
    CandleStick newCandle;
    newCandle.reset();
    for (auto bar = realTimeBarBuffRecord[symbol].barsBuff.begin(); bar != realTimeBarBuffRecord[symbol].barsBuff.end();
         ++bar)
    {
        // infolog(logger, "finishing candle: %s, %.02f", bar->time.c_str(), bar->price);
        if (bar == realTimeBarBuffRecord[symbol].barsBuff.begin())
        {
            newCandle.price_open = bar->open;
            /*low or high can be open price*/
            // newCandle.price_low = std::min(newCandle.price_low, bar->second.price);
            // newCandle.price_high = std::max(newCandle.price_high, bar->second.price);
        }
        else if (bar == (--realTimeBarBuffRecord[symbol].barsBuff.end()))
        {
            newCandle.price_close = bar->close;
            // newCandle.price_low = std::min(newCandle.price_low, bar->second.price);
            // newCandle.price_high = std::max(newCandle.price_high, bar->second.price);
        }

        newCandle.price_low = std::min(newCandle.price_low, bar->low);
        newCandle.price_high = std::max(newCandle.price_high, bar->high);
        newCandle.volume += DecimalFunctions::decimalToDouble(bar->volume);
        counter++;
    }
    newCandle.timestamp = realTimeBarBuffRecord[symbol].currentUnixS; // start time of candlestick
    newCandle.product_id = symbol;

    return newCandle;
}