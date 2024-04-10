#include "ChartData3.h"

#include <algorithm>

namespace charting {

ChartData3::ChartData3()
{
}

void ChartData3::addMultiCandles(std::vector<MultiCandle> mcandlevec)
{
    mcandles.insert(mcandles.end(), mcandlevec.begin(), mcandlevec.end());
}

void ChartData3::addMultiCandle(MultiCandle mcandle)
{
    // add candle to end, then sort from least to greatest timestamp
    mcandles.push_back(mcandle);

    std::sort(mcandles.begin(), mcandles.end(),
        [](const MultiCandle& a, const MultiCandle& b) { return a.timestamp < b.timestamp; });
}

std::vector<MultiCandle> ChartData3::getMultiCandles() const
{
    return mcandles;
}

void ChartData3::dumpToCSV(std::string csvfilePath) const
{
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
            auto indicatorValue = mcandles.at(i).getIndByName(indicatorKeyVec[j].name);
            if (!indicatorValue.isNan)
                snprintf(indicatorbuffer, 128, "%.02f,", indicatorValue.value);
            else
                snprintf(indicatorbuffer, 128, ",");

            filewriter.write(indicatorbuffer);
        }
        filewriter.write("\n");
    }
}

void ChartData3::addIndicator(IndicatorType indicatortype)
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
            // auto periods = std::stoi(indicatortype.params[0]);
            break;
        }
        case STOCHUPPER: {
            // auto level = std::stoi(indicatortype.params[0]);
            break;
        }
        case STOCHLOWER: {
            // auto level = std::stoi(indicatortype.params[0]);
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

    if (!checkTimestampAlignment(indicatorsVec))
    {
        throw std::runtime_error("Timestamps of indicators are not aligned");
    }

    for (unsigned i = 0; i < mcandles.size(); i++)
    {
        mcandles[i].setInd(indicatortype, indicatorsVec[i]);
    }
}

bool ChartData3::checkTimestampAlignment(std::vector<IndicatorValue> ivalues)
{
    if (mcandles.size() != ivalues.size())
    {
        return false;
    }

    for (unsigned i = 0; i < mcandles.size(); i++)
    {
        if (mcandles[i].timestamp != ivalues[i].timestamp)
        {
            return false;
        }
    }
    return true;
}

std::vector<IndicatorValue> ChartData3::calculateSMA(unsigned periods)
{
    TALIB talib;
    return talib.SMA(mcandles, 0, mcandles.size() - 1, periods);
}

std::vector<IndicatorValue> ChartData3::calculateBB(unsigned periods, IndicatorTypes bbtype)
{
    TALIB talib;
    return talib.BB(mcandles, bbtype, 0, mcandles.size() - 1, periods, 2.0, 2.0);
}

std::vector<IndicatorValue> ChartData3::calculateEMA(unsigned periods, unsigned smoothing)
{
    TALIB talib;
    return talib.EMA(mcandles, 0, mcandles.size() - 1, periods, 2);
}

} // namespace charting