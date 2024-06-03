#include "ChartData3.h"

#include <algorithm>

namespace charting {

ChartData3::ChartData3()
{
}

void ChartData3::addMultiCandles(std::vector<MultiCandle> mcandlevec)
{
    // sort the vector from least to greatest timestamp just in case we pass something out of order
    std::sort(mcandlevec.begin(), mcandlevec.end(),
        [](const MultiCandle& a, const MultiCandle& b) { return a.timestamp < b.timestamp; });

    mcandles.insert(mcandles.end(), mcandlevec.begin(), mcandlevec.end());

    // finally, sort the whole mcandle vector after just in case
    std::sort(mcandles.begin(), mcandles.end(),
        [](const MultiCandle& a, const MultiCandle& b) { return a.timestamp < b.timestamp; });

    for (const auto& indicatorType : indicatorTypes)
    {
        updateIndicatorsData(indicatorType);
    }
}

void ChartData3::addMultiCandle(MultiCandle mcandle)
{
    // add candle to end, then sort from least to greatest timestamp
    mcandles.push_back(mcandle);

    std::sort(mcandles.begin(), mcandles.end(),
        [](const MultiCandle& a, const MultiCandle& b) { return a.timestamp < b.timestamp; });

    for (const auto& indicatorType : indicatorTypes)
    {
        updateIndicatorsData(indicatorType);
    }
}

std::vector<MultiCandle> ChartData3::getMultiCandles() const
{
    return mcandles;
}

void ChartData3::dumpToCSV(std::string& csvString) const
{
    char csvkeybuffer[1024];

    std::string indicatorKeys;

    auto indicatorKeyVec = mcandles[0].listIndicators();

    csvString.clear();
    csvString += "timestamp,price_open,price_high,price_low,price_close,volume,";

    for (unsigned i = 0; i < indicatorKeyVec.size(); i++)
    {
        indicatorKeys += indicatorKeyVec[i].name + ",";
    }

    csvString += indicatorKeys + "\n";

    for (unsigned i = 0; i < mcandles.size(); i++)
    {
        char databuffer[1024]; // might need to increase

        snprintf(databuffer, 1024, "%ld,%.02f,%.02f,%.02f,%.02f,%.09f,", mcandles[i].timestamp, mcandles[i].price_open,
            mcandles[i].price_high, mcandles[i].price_low, mcandles[i].price_close, mcandles[i].volume);

        csvString += std::string(databuffer);

        for (unsigned j = 0; j < indicatorKeyVec.size(); j++)
        {
            char indicatorbuffer[1024];
            auto indicatorValue = mcandles.at(i).getIndByName(indicatorKeyVec[j].name);
            if (!indicatorValue.isNan)
                snprintf(indicatorbuffer, 1024, "%.02f,", indicatorValue.value);
            else
                snprintf(indicatorbuffer, 1024, ",");

            csvString += std::string(indicatorbuffer);
        }
        csvString += "\n";
    }
}

void ChartData3::addIndicator(IndicatorType indicatortype)
{
    indicatorTypes.push_back(indicatortype);
    updateIndicatorsData(indicatortype);
}

void ChartData3::updateIndicatorsData(IndicatorType indicatortype)
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
        case MACD:{
            auto fastPeriods = std::stoi(indicatortype.params[0]);
            auto slowPeriods = std::stoi(indicatortype.params[1]);
            auto smoothing = std::stoi(indicatortype.params[2]);
            indicatorsVec = calculateMACD(fastPeriods, indicatortype.type, slowPeriods, smoothing);
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
        case THREEWHITESOLDIERS: {
            indicatorsVec = calculate3WhiteSoldiers();
            break;
        }
        case THREEBLACKCROWS: {
            indicatorsVec = calculate3BlackCrows();
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

std::vector<IndicatorValue> ChartData3::calculateMACD(unsigned fastPeriods, IndicatorTypes macdType, unsigned slowPeriods, unsigned smoothing)
{
    TALIB talib;
    return talib.MACD(mcandles, macdType, 0, mcandles.size() - 1, fastPeriods, slowPeriods, smoothing);
}

std::vector<IndicatorValue> ChartData3::calculateEMA(unsigned periods, unsigned smoothing)
{
    TALIB talib;
    return talib.EMA(mcandles, 0, mcandles.size() - 1, periods, 2);
}

std::vector<IndicatorValue> ChartData3::calculate3WhiteSoldiers()
{
    TALIB talib;
    return talib.CDL3WHITESOLDIERS(mcandles, 0, mcandles.size() - 1);
}

std::vector<IndicatorValue> ChartData3::calculate3BlackCrows()
{
    TALIB talib;
    return talib.CDL3BLACKCROWS(mcandles, 0, mcandles.size() - 1);
}

} // namespace charting