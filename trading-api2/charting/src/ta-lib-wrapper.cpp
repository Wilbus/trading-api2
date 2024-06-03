#include "ta-lib-wrapper.h"

namespace ta_lib_wrapper {

TALIB::TALIB()
{
    TA_Initialize();
}

TALIB::~TALIB()
{
    TA_Shutdown();
}

std::vector<IndicatorValue> TALIB::copyOutToIndicatorValues(
    const std::vector<MultiCandle>& mcandles, int startIdx, int endIdx, TA_Integer outBeg, TA_Real out[])
{
    std::vector<IndicatorValue> vals;
    for (int i = startIdx; i <= endIdx; i++)
    {
        if (i < outBeg)
        {
            IndicatorValue ivalue;
            ivalue.isNan = true;
            ivalue.timestamp = mcandles[i].timestamp;
            vals.push_back(ivalue);
        }
        else
        {
            IndicatorValue ivalue;
            ivalue.isNan = false;
            ivalue.value = out[i - outBeg];
            ivalue.timestamp = mcandles[i].timestamp;
            vals.push_back(ivalue);
        }
    }
    return vals;
}

std::vector<IndicatorValue> TALIB::copyOutToIndicatorValues(
    const std::vector<MultiCandle>& mcandles, int startIdx, int endIdx, TA_Integer outBeg, TA_Integer out[])
{
    std::vector<IndicatorValue> vals;
    for (int i = startIdx; i <= endIdx; i++)
    {
        if (i < outBeg)
        {
            IndicatorValue ivalue;
            ivalue.isNan = true;
            ivalue.timestamp = mcandles[i].timestamp;
            vals.push_back(ivalue);
        }
        else
        {
            IndicatorValue ivalue;
            ivalue.isNan = false;
            ivalue.value = out[i - outBeg];
            ivalue.timestamp = mcandles[i].timestamp;
            vals.push_back(ivalue);
        }
    }
    return vals;
}

std::vector<IndicatorValue> TALIB::SMA(const std::vector<MultiCandle>& mcandles, int startIdx, int endIdx, int periods)
{
    TA_Real closePrices[endIdx - startIdx + 1];
    TA_Real out[endIdx - startIdx + 1];
    TA_Integer outBeg;
    TA_Integer outNbElement;

    unsigned idx = 0;
    for (const auto& candle : mcandles)
    {
        closePrices[idx] = candle.price_close;
        idx++;
    }

    auto retCode = TA_MA(startIdx, endIdx, &closePrices[0], periods, TA_MAType_SMA, &outBeg, &outNbElement, &out[0]);

    if (retCode != 0)
    {
        std::string errMsg = "Error calculating SMA, retCode: " + std::to_string(retCode);
        throw std::runtime_error(errMsg.c_str());
    }

    return copyOutToIndicatorValues(mcandles, startIdx, endIdx, outBeg, out);
}

std::vector<IndicatorValue> TALIB::MACD(const std::vector<MultiCandle>& mcandles, IndicatorTypes macdType, int startIdx,
    int endIdx, int fastPeriods, int slowPeriods, int smoothing)
{
    TA_Real closePrices[endIdx - startIdx + 1];
    TA_Real outMACD[endIdx - startIdx + 1];
    TA_Real outMACDSignal[endIdx - startIdx + 1];
    TA_Real outMACDHist[endIdx - startIdx + 1];
    TA_Integer outBeg;
    TA_Integer outNbElement;

    unsigned idx = 0;
    for (const auto& candle : mcandles)
    {
        closePrices[idx] = candle.price_close;
        idx++;
    }

    auto retCode = TA_MACD(startIdx, endIdx, &closePrices[0], fastPeriods, slowPeriods, smoothing, &outBeg,
        &outNbElement, &outMACD[0], &outMACDSignal[0], &outMACDHist[0]);
    if (retCode != 0)
    {
        std::string errMsg = "Error calculating MACD, retCode: " + std::to_string(retCode);
        throw std::runtime_error(errMsg.c_str());
    }

    switch (macdType)
    {
        case IndicatorTypes::MACDSIGNAL: {
            return copyOutToIndicatorValues(mcandles, startIdx, endIdx, outBeg, outMACDSignal);
            break;
        }
        case IndicatorTypes::MACDHIST: {
            return copyOutToIndicatorValues(mcandles, startIdx, endIdx, outBeg, outMACDHist);
            break;
        }
        case IndicatorTypes::MACD: {
            return copyOutToIndicatorValues(mcandles, startIdx, endIdx, outBeg, outMACD);
            break;
        }
        default: {
            throw std::runtime_error("Invalid macdType given");
        }
    }
}

std::vector<IndicatorValue> TALIB::ADX(const std::vector<MultiCandle>& mcandles, int startIdx, int endIdx, int periods)
{
    TA_Real closePrices[endIdx - startIdx + 1];
    TA_Real highPrices[endIdx - startIdx + 1];
    TA_Real lowPrices[endIdx - startIdx + 1];
    TA_Real out[endIdx - startIdx + 1];
    TA_Integer outBeg;
    TA_Integer outNbElement;

    unsigned idx = 0;
    for (const auto& candle : mcandles)
    {
        closePrices[idx] = candle.price_close;
        highPrices[idx] = candle.price_high;
        lowPrices[idx] = candle.price_low;
        idx++;
    }

    auto retCode = TA_ADX(
        startIdx, endIdx, &highPrices[0], &lowPrices[0], &closePrices[0], periods, &outBeg, &outNbElement, &out[0]);
    if (retCode != 0)
    {
        std::string errMsg = "Error calculating ADX, retCode: " + std::to_string(retCode);
        throw std::runtime_error(errMsg.c_str());
    }

    return copyOutToIndicatorValues(mcandles, startIdx, endIdx, outBeg, out);
}

std::vector<IndicatorValue> TALIB::EMA(
    const std::vector<MultiCandle>& mcandles, int startIdx, int endIdx, int periods, int smoothing)
{
    TA_Real closePrices[endIdx - startIdx + 1];
    TA_Real out[endIdx - startIdx + 1];
    TA_Integer outBeg;
    TA_Integer outNbElement;

    unsigned idx = 0;
    for (const auto& candle : mcandles)
    {
        closePrices[idx] = candle.price_close;
        idx++;
    }

    auto retCode = TA_EMA(startIdx, endIdx, &closePrices[0], periods, &outBeg, &outNbElement, &out[0]);

    if (retCode != 0)
    {
        std::string errMsg = "Error calculating EMA, retCode: " + std::to_string(retCode);
        throw std::runtime_error(errMsg.c_str());
    }

    return copyOutToIndicatorValues(mcandles, startIdx, endIdx, outBeg, out);
}

std::vector<IndicatorValue> TALIB::BB(const std::vector<MultiCandle>& mcandles, IndicatorTypes bbtype, int startIdx,
    int endIdx, int periods, double devUp, double devDown)
{
    TA_Real closePrices[endIdx - startIdx + 1];
    TA_Real outUpper[endIdx - startIdx + 1];
    TA_Real outMid[endIdx - startIdx + 1];
    TA_Real outLower[endIdx - startIdx + 1];
    TA_Integer outBeg;
    TA_Integer outNbElement;

    unsigned idx = 0;
    for (const auto& candle : mcandles)
    {
        closePrices[idx] = candle.price_close;
        idx++;
    }

    auto retCode = TA_BBANDS(startIdx, endIdx, &closePrices[0], periods, devUp, devDown, TA_MAType_SMA, &outBeg,
        &outNbElement, &outUpper[0], &outMid[0], &outLower[0]);
    if (retCode != 0)
    {
        std::string errMsg = "Error calculating BB, retCode: " + std::to_string(retCode);
        throw std::runtime_error(errMsg.c_str());
    }

    switch (bbtype)
    {
        case IndicatorTypes::BBMID: {
            return copyOutToIndicatorValues(mcandles, startIdx, endIdx, outBeg, outMid);
            break;
        }
        case IndicatorTypes::BBUP: {
            return copyOutToIndicatorValues(mcandles, startIdx, endIdx, outBeg, outUpper);
            break;
        }
        case IndicatorTypes::BBDOWN: {
            return copyOutToIndicatorValues(mcandles, startIdx, endIdx, outBeg, outLower);
            break;
        }
        default: {
            throw std::runtime_error("Invalid bbtype given");
        }
    }
}

std::vector<IndicatorValue> TALIB::RSI(const std::vector<MultiCandle>& mcandles, int startIdx, int endIdx, int periods)
{
    TA_Real closePrices[endIdx - startIdx + 1];
    TA_Real out[endIdx - startIdx + 1];
    TA_Integer outBeg;
    TA_Integer outNbElement;

    unsigned idx = 0;
    for (const auto& candle : mcandles)
    {
        closePrices[idx] = candle.price_close;
        idx++;
    }

    auto retCode = TA_RSI(startIdx, endIdx, &closePrices[0], periods, &outBeg, &outNbElement, &out[0]);
    if (retCode != 0)
    {
        std::string errMsg = "Error calculating RSI, retCode: " + std::to_string(retCode);
        throw std::runtime_error(errMsg.c_str());
    }

    return copyOutToIndicatorValues(mcandles, startIdx, endIdx, outBeg, out);
}

std::vector<IndicatorValue> TALIB::CDL3WHITESOLDIERS(const std::vector<MultiCandle>& mcandles, int startIdx, int endIdx)
{
    TA_Real openPrices[endIdx - startIdx + 1];
    TA_Real highPrices[endIdx - startIdx + 1];
    TA_Real lowPrices[endIdx - startIdx + 1];
    TA_Real closePrices[endIdx - startIdx + 1];
    TA_Integer outBeg;
    TA_Integer outNbElement;
    TA_Integer outInteger[endIdx - startIdx + 1];

    unsigned idx = 0;
    for (const auto& candle : mcandles)
    {
        openPrices[idx] = candle.price_open;
        highPrices[idx] = candle.price_high;
        lowPrices[idx] = candle.price_low;
        closePrices[idx] = candle.price_close;
        idx++;
    }

    auto retCode = TA_CDL3WHITESOLDIERS(startIdx, endIdx, &openPrices[0], &highPrices[0], &lowPrices[0],
        &closePrices[0], &outBeg, &outNbElement, &outInteger[0]);
    if (retCode != 0)
    {
        std::string errMsg = "Error calculating CDL3WHITESOLDIERS, retCode: " + std::to_string(retCode);
        throw std::runtime_error(errMsg.c_str());
    }

    return copyOutToIndicatorValues(mcandles, startIdx, endIdx, outBeg, outInteger);
}

std::vector<IndicatorValue> TALIB::CDL3BLACKCROWS(const std::vector<MultiCandle>& mcandles, int startIdx, int endIdx)
{
    TA_Real openPrices[endIdx - startIdx + 1];
    TA_Real highPrices[endIdx - startIdx + 1];
    TA_Real lowPrices[endIdx - startIdx + 1];
    TA_Real closePrices[endIdx - startIdx + 1];
    TA_Integer outBeg;
    TA_Integer outNbElement;
    TA_Integer outInteger[endIdx - startIdx + 1];

    unsigned idx = 0;
    for (const auto& candle : mcandles)
    {
        openPrices[idx] = candle.price_open;
        highPrices[idx] = candle.price_high;
        lowPrices[idx] = candle.price_low;
        closePrices[idx] = candle.price_close;
        idx++;
    }

    auto retCode = TA_CDL3BLACKCROWS(startIdx, endIdx, &openPrices[0], &highPrices[0], &lowPrices[0], &closePrices[0],
        &outBeg, &outNbElement, &outInteger[0]);
    if (retCode != 0)
    {
        std::string errMsg = "Error calculating CDL3BLACKCROWS, retCode: " + std::to_string(retCode);
        throw std::runtime_error(errMsg.c_str());
    }

    return copyOutToIndicatorValues(mcandles, startIdx, endIdx, outBeg, outInteger);
}

} // namespace ta_lib_wrapper