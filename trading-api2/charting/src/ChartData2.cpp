#include "ChartData2.h"

#include <algorithm>
#include <math.h>

namespace charting {

ChartData2::ChartData2(uint32_t maxTicks)
    : maxTicks(maxTicks)
{
}

ChartData2::ChartData2(MCandles mcandles, uint32_t maxDataTicks)
    : mcandles(mcandles)
    , maxTicks(maxDataTicks)
{
    sortMCandles();
}

void ChartData2::addIndicatorData(IndicatorType indicatortype)
{
    std::lock_guard<std::mutex> lg(mtx);
    if (mcandles.size() == 0)
    {
        throw std::runtime_error("Cannot calculate indicators on an empty chart");
    }

    const auto indicatorsVec = indicatorDataCalculator(indicatortype);

    if (mcandles.size() != indicatorsVec.size())
    {
        // throw std::runtime_error("Mismatching new indicators vector and mcandles vector");
        std::string msg = "Mismatching new indicators vector " + std::to_string(indicatorsVec.size()) +
                          " and mcandles vector " + std::to_string(mcandles.size());
        throw std::runtime_error(msg.c_str());
    }

    for (unsigned i = 0; i < mcandles.size(); i++)
    {
        if (mcandles[i].timestamp != indicatorsVec[i].timestamp)
        {
            throw std::runtime_error("Misaligned timestamps in new indicators vector");
        }
        mcandles[i].setInd(indicatortype, indicatorsVec[i]);
    }
    sortMCandles();
}

bool ChartData2::checkTimestampAlignment(std::vector<IndicatorValue> ivalues)
{
    if (mcandles.size() != ivalues.size())
    {
        throw std::runtime_error("Mismatching new indicators vector and mcandles vector");
    }

    for (unsigned i = 0; i < mcandles.size(); i++)
    {
        if (mcandles[i].timestamp != ivalues[i].timestamp)
        {
            throw std::runtime_error("Misaligned timestamps in new indicators vector");
        }
    }
    return true;
}

void ChartData2::addCandle(CandleStick candle)
{
    std::lock_guard<std::mutex> lg(mtx);
    MultiCandle newcandle(candle);

    for (signed i = mcandles.size() - 1; i > 0; i--)
    {
        if (mcandles[i].timestamp == candle.timestamp)
        {
            mcandles[i] = candle;
            updateIndicators();
            sortMCandles();
            return;
        }
    }

    mcandles.push_back(candle);
    updateIndicators();
    sortMCandles();
}

void ChartData2::updateIndicators()
{
    auto indicatorsVec = mcandles[0].listIndicators();
    for (unsigned i = 0; i < indicatorsVec.size(); i++)
    {
        auto valuesVec = indicatorDataCalculator(indicatorsVec[i]);

        checkTimestampAlignment(valuesVec);

        if (mcandles.size() != valuesVec.size())
        {
            std::string msg = "Mismatching new indicators vector " + std::to_string(valuesVec.size()) +
                              " and mcandles vector " + std::to_string(mcandles.size());
            throw std::runtime_error(msg.c_str());
        }

        unsigned idx = 0;
        for (auto& mcandle : mcandles)
        {
            if (mcandle.timestamp != valuesVec[idx].timestamp)
            {
                throw std::runtime_error("Misaligned timestamps in new indicators vector");
            }
            mcandle.setInd(indicatorsVec[i], valuesVec[idx++]);
        }
    }
    sortMCandles();
}

void ChartData2::sortMCandles()
{
    std::ranges::sort(mcandles, [](const MultiCandle& a, const MultiCandle& b) { return a.timestamp < b.timestamp; });
}

void ChartData2::setIndicatorValueAtIndex(unsigned idx, IndicatorType indicatortype, IndicatorValue value)
{
    mcandles[idx].setInd(indicatortype, value);
}

std::vector<IndicatorValue> ChartData2::indicatorDataCalculator(IndicatorType indicatortype)
{
    std::vector<IndicatorValue> indicatorsVec;
    switch (indicatortype.type)
    {
        case SMA: {
            auto periods = std::stoi(indicatortype.params[0]);
            indicatorsVec = calculateSMA(periods);
            break;
        }
        case BBMID:
        case BBDOWN:
        case BBUP: {
            auto periods = std::stoi(indicatortype.params[0]);
            indicatorsVec = calculateBB(periods, indicatortype.type);
            break;
        }
        case EMA: {
            if (indicatortype.params.size() < 2)
            {
                throw std::runtime_error("invalid params length for ema type");
            }
            auto periods = std::stoi(indicatortype.params[0]);
            auto smoothing = std::stoi(indicatortype.params[1]);
            indicatorsVec = calculateEMA(periods, smoothing);
            break;
        }
        case STOCH: {
            auto periods = std::stoi(indicatortype.params[0]);
            indicatorsVec = calculateStochasticIndicator(periods);
            break;
        }
        case STOCHUPPER: {
            auto level = std::stoi(indicatortype.params[0]);
            indicatorsVec = calculateStochoasticUpper(level);
            break;
        }
        case STOCHLOWER: {
            auto level = std::stoi(indicatortype.params[0]);
            indicatorsVec = calculateStochoasticLower(level);
            break;
        }
        case LIMITBUY:
        case LIMITSELL:
        case STOPLIMIT:
        case MARKET:
        case BUYSIGNAL:
        case SELLSIGNAL: {
            std::vector<IndicatorValue> ordersignalEmptyData;
            for (unsigned i = 0; i < mcandles.size(); i++)
            {
                IndicatorValue ivalue;
                ivalue.isNan = false;
                ivalue.value = 0;
                ivalue.timestamp = mcandles[i].timestamp;
                ordersignalEmptyData.push_back(ivalue);
            }
            indicatorsVec = ordersignalEmptyData;
            break;
        }
        default: {
            throw std::runtime_error("Unknown indicator type encountered when updating indicators data");
        }
    }
    return indicatorsVec;
}

std::vector<IndicatorValue> ChartData2::calculateSMA(unsigned periods)
{
    return talib.SMA(mcandles, 0, mcandles.size() - 1, periods);
}

std::vector<IndicatorValue> ChartData2::calculateBB(unsigned periods, IndicatorTypes bbtype)
{
    return talib.BB(mcandles, bbtype, 0, mcandles.size() - 1, periods, 2.0, 2.0);
}
std::vector<IndicatorValue> ChartData2::calculateStochasticMomentum(
    int64_t highlowPeriods, int64_t emaPeriods, int64_t firstLevel, int64_t secondLevel)
{
    (void)highlowPeriods;
    (void)emaPeriods;
    (void)firstLevel;
    (void)secondLevel;
    return {};
}

std::vector<IndicatorValue> ChartData2::calculateEMA(unsigned periods, unsigned smoothing)
{
    return talib.EMA(mcandles, 0, mcandles.size() - 1, periods, 2);
}

std::vector<IndicatorValue> ChartData2::calculateStochasticIndicator(int64_t periods)
{
    /*%K = ((C - L14) / (H14 - L 14)) * 100*/
    /*C = most recent closing price, L14 = lowest out of last 14 periods, H14 = highest out of last 14 periods*/

    std::vector<IndicatorValue> stochData;

    for (unsigned i = 0; i < mcandles.size(); i++)
    {
        if (i < periods - 1)
        {
            IndicatorValue ivalue;
            ivalue.isNan = true;
            ivalue.timestamp = mcandles[i].timestamp;
            stochData.push_back(ivalue);
        }
        else
        {
            unsigned periodsIndex = i - (periods - 1);
            double C = mcandles[i].price_close;

            double Lperiod = 2147000000; // some bigass number to start with
            double Hperiod = 0;          // some negative number to start with

            while (periodsIndex <= i)
            {
                if (mcandles[periodsIndex].price_close < Lperiod)
                {
                    Lperiod = mcandles[periodsIndex].price_close;
                }

                if (mcandles[periodsIndex].price_close > Hperiod)
                {
                    Hperiod = mcandles[periodsIndex].price_close;
                }
                // std::cout << C << ", " << Lperiod << ", " << Hperiod << "\n";
                periodsIndex += 1;
            }
            double K = ((C - Lperiod) / (Hperiod - Lperiod)) * 100.0;
            IndicatorValue ivalue;
            ivalue.isNan = false;
            ivalue.value = K;
            ivalue.timestamp = mcandles[i].timestamp;
            stochData.push_back(ivalue);
        }
    }
    return stochData;
}

std::vector<IndicatorValue> ChartData2::calculateStochoasticUpper(int64_t upperlevel)
{
    std::vector<IndicatorValue> stochData;

    for (unsigned i = 0; i < mcandles.size(); i++)
    {
        IndicatorValue ivalue;
        ivalue.isNan = false;
        ivalue.value = upperlevel;
        ivalue.timestamp = mcandles[i].timestamp;
        stochData.push_back(ivalue);
    }
    return stochData;
}

std::vector<IndicatorValue> ChartData2::calculateStochoasticLower(int64_t lowerlevel)
{
    std::vector<IndicatorValue> stochData;

    for (unsigned i = 0; i < mcandles.size(); i++)
    {
        IndicatorValue ivalue;
        ivalue.isNan = false;
        ivalue.value = lowerlevel;
        ivalue.timestamp = mcandles[i].timestamp;
        stochData.push_back(ivalue);
    }
    return stochData;
}

void ChartData2::dumpToCSV(std::string csvfilePath)
{
    std::lock_guard<std::mutex> lg(mtx);

    char csvkeybuffer[1024];

    std::string indicatorKeys;

    auto indicatorKeyVec = mcandles[0].listIndicators();

    std::string ohlcKeys = "timestamp,price_open,price_high,price_low,price_close,volume,";

    for (unsigned i = 0; i < indicatorKeyVec.size(); i++)
    {
        indicatorKeys += indicatorKeyVec[i].name + ",";
    }

    std::string finalCsvKey = ohlcKeys + indicatorKeys + "\n";
    // std::cout << finalCsvKey;
    std::sprintf(csvkeybuffer, "%s", finalCsvKey.c_str());

    auto filewriter = FileWriter(csvfilePath, true, FileExt::CSV, csvkeybuffer);

    for (unsigned i = 0; i < mcandles.size(); i++)
    {
        char databuffer[512]; // might need to increase

        snprintf(databuffer, 512, "%ld,%.02f,%.02f,%.02f,%.02f,%.09f,", mcandles[i].timestamp, mcandles[i].price_open,
            mcandles[i].price_high, mcandles[i].price_low, mcandles[i].price_close, mcandles[i].volume);
        filewriter.write(databuffer);

        for (unsigned j = 0; j < indicatorKeyVec.size(); j++)
        {
            char indicatorbuffer[128];
            auto indicatorValue = mcandles[i].getInd(indicatorKeyVec[j]);
            if (!indicatorValue.isNan)
                snprintf(indicatorbuffer, 128, "%.02f,", indicatorValue.value);
            else
                snprintf(indicatorbuffer, 128, ",");

            filewriter.write(indicatorbuffer);
        }
        filewriter.write("\n");
    }
}
} // namespace charting