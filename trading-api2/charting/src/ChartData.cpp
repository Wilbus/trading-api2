#include "ChartData.h"

#include <math.h>

namespace charting {
using namespace utils;

ChartData::ChartData(std::shared_ptr<Logger> logger, uint32_t maxTicks)
    : maxDataTicks(maxTicks)
    , logger(logger)
{
    infolog(logger, "%s() Start ChartData", __func__);
    chartData = std::make_shared<CandleStickChartData>();
    chartSize = chartData->size();
    infolog(logger, "%s() new ChartData size %d", __func__, chartSize);
}

ChartData::ChartData(
    std::shared_ptr<Logger> logger, std::shared_ptr<CandleStickChartData>& chartData, uint32_t maxTicks)
    : chartData(chartData)
    , maxDataTicks(maxTicks)
    , logger(logger)
{
    chartSize = chartData->size();
}

uint64_t ChartData::getChartSize() const
{
    return chartSize;
}

CandleStick ChartData::getRecentCandle(int periodsBack)
{
    std::lock_guard<std::mutex> lg(mtx);
    for (auto candle = chartData->rbegin(); candle != chartData->rend(); ++candle)
    {
        if (periodsBack == 0)
        {
            return candle->second;
        }
        periodsBack--;
    }
    throw std::runtime_error("ChartData::getRecentCandle() error");
}

IndicatorValue ChartData::getRecentIndicatorValue(std::string indicatorName, int periodsBack)
{
    std::lock_guard<std::mutex> lg(mtx);
    for (auto indicatorType : indicatorsDataMap)
    {
        if (indicatorType.first.name == indicatorName)
        {
            auto indicatorData = indicatorType.second;
            IndicatorChartData indicatorsData;

            for (auto indicatorValue = indicatorData.rbegin(); indicatorValue != indicatorData.rend(); ++indicatorValue)
            {
                if (periodsBack == 0)
                {
                    return indicatorValue->second;
                }
                periodsBack--;
            }
        }
    }
    throw std::runtime_error("ChartData::getRecentIndicatorValue() indicator value doesn't exist");
}

IndicatorChartData ChartData::indicatorDataCalculator(IndicatorType indicatortype)
{
    IndicatorChartData newIndicatorData;

    switch (indicatortype.type)
    {
        case BBMID:
        case SMA: {
            auto periods = std::stoi(indicatortype.params[0]);
            newIndicatorData = calculateSMA(periods, chartData);
            break;
        }
        case BBDOWN: {
            auto periods = std::stoi(indicatortype.params[0]);
            newIndicatorData = calculateBB(periods, chartData, indicatortype.type);
            break;
        }
        case BBUP: {
            auto periods = std::stoi(indicatortype.params[0]);
            newIndicatorData = calculateBB(periods, chartData, indicatortype.type);
            break;
        }
        case EMA: {
            auto periods = std::stoi(indicatortype.params[0]);
            auto smoothing = std::stoi(indicatortype.params[1]);
            newIndicatorData = calculateEMA(periods, smoothing, chartData);
            break;
        }
        case STOCH: {
            auto periods = std::stoi(indicatortype.params[0]);
            newIndicatorData = calculateStochasticIndicator(periods);
            break;
        }
        case STOCHUPPER: {
            auto level = std::stoi(indicatortype.params[0]);
            newIndicatorData = calculateStochoasticUpper(level);
            break;
        }
        case STOCHLOWER: {
            auto level = std::stoi(indicatortype.params[0]);
            newIndicatorData = calculateStochoasticLower(level);
            break;
        }
        default: {
            errorlog(logger, "%s() Unknown indicator type %d", __func__, indicatortype.type);
            throw std::runtime_error("Unknown indicator type encountered when updating indicators data");
        }
    }
    return newIndicatorData;
}

void ChartData::addIndicatorData(IndicatorType indicatortype)
{
    std::lock_guard<std::mutex> lg(mtx);
    IndicatorChartData newIndicatorData = indicatorDataCalculator(indicatortype);
    if (!checkTimestamps(newIndicatorData))
    {
        throw std::runtime_error("new indicators timestamps don't match when "
                                 "tryign to add to a ChartData");
    }
    indicatorsDataMap[indicatortype] = newIndicatorData;
}

void ChartData::addCandle(CandleStick candle)
{
    std::lock_guard<std::mutex> lg(mtx);

    /*
        1) add candle to end of chart, remove first candle of chart
        2) clear and recalculate any indicators
            for keys in indicatorsDataMap
    */
    // std::cout << "test\n";
    /*timestamp can already exist, so total length of data becomes 1 less*/
    if (chartData->size() > maxDataTicks)
    {
        auto chartItrBegin = chartData->begin();
        chartData->erase(chartItrBegin);
        // std::cout << maxDataTicks << "\n";
    }

    (*chartData.get())[candle.timestamp] = candle;
    chartSize = chartData->size();
    updateIndicators(candle);
}

void ChartData::updateIndicators(CandleStick candle)
{
    for (auto& indicatorData : indicatorsDataMap)
    {
        // std::printf("%s\n", indicatorData.first.name.c_str());
        IndicatorValue placeholderValue;
        indicatorData.second[candle.timestamp] = placeholderValue; //
        indicatorData.second.clear();
        auto indicatorType = indicatorData.first;

        indicatorData.second = indicatorDataCalculator(indicatorType);
    }
}

IndicatorChartData ChartData::getIndicatorData(IndicatorType indicatorName)
{
    std::lock_guard<std::mutex> lg(mtx);
    return indicatorsDataMap[indicatorName];
}

// NOT thread-safe probably
IndicatorsChartDataMap ChartData::getIndicatorsDataMap() const
{
    return indicatorsDataMap;
}

std::set<IndicatorType> ChartData::getIndicatorsTypes()
{
    std::set<IndicatorType> typeset;
    for (const auto& indicatorData : indicatorsDataMap)
    {
        typeset.insert(indicatorData.first);
    }
    return typeset;
}

// NOT thread-safe probably
std::shared_ptr<CandleStickChartData> ChartData::getChartData() const
{
    return chartData;
}

// TODO: is this valid copy??
CandleStickChartData ChartData::getChartDataCopy()
{
    std::lock_guard<std::mutex> lg(mtx);
    return (*chartData.get());
}

void ChartData::setChartData(std::shared_ptr<CandleStickChartData> chartdata)
{
    std::lock_guard<std::mutex> lg(mtx);
    chartData = chartdata;
}

void ChartData::setChartDataByVector(std::vector<CandleStick> candles)
{
    std::lock_guard<std::mutex> lg(mtx);
    for (auto c : candles)
    {
        (*chartData.get())[c.timestamp] = c;
        // timestamps.push_back(c.timestamp);
    }
    chartSize = chartData->size();
    infologprint(logger, "%s() new chart size is %ld", __func__, chartSize);
}

void ChartData::dumpToCSV(std::string csvfilePath)
{
    std::lock_guard<std::mutex> lg(mtx);
    infolog(logger, "%s() dumping chart and indicators to csv", __func__);
    char csvkeybuffer[100];

    std::string startingCsvKeys = "timestamp,low,high,open,close,volume,";
    std::string indicatorsKeys = "";

    for (auto indicator = indicatorsDataMap.begin(); indicator != indicatorsDataMap.end(); ++indicator)
    {
        indicatorsKeys += indicator->first.name + ",";
    }

    std::string finalCsvKey = startingCsvKeys + indicatorsKeys + "\n";
    std::sprintf(csvkeybuffer, "%s", finalCsvKey.c_str());

    auto filewriter = FileWriter(csvfilePath, true, FileExt::CSV, csvkeybuffer);

    for (auto itr = chartData->begin(); itr != chartData->end(); ++itr)
    {
        // default data columns
        char databuffer[1024]; // might need to increase
        snprintf(databuffer, 1024, "%lu,%.02f,%.02f,%.02f,%.02f,%.09f,", itr->first, itr->second.price_low,
            itr->second.price_high, itr->second.price_open, itr->second.price_close, itr->second.volume);
        filewriter.write(databuffer);

        for (auto indicator = indicatorsDataMap.begin(); indicator != indicatorsDataMap.end(); ++indicator)
        {
            // add on indicators
            auto indicatorChartData = indicator->second;
            try
            {
                auto ivalue = indicatorChartData[itr->first];
                char indicatorbuffer[20];
                if (ivalue.isNan)
                {
                    snprintf(indicatorbuffer, 20, ",");
                    filewriter.write(indicatorbuffer);
                }
                else
                {
                    snprintf(indicatorbuffer, 20, "%02f,", ivalue.value);
                    filewriter.write(indicatorbuffer);
                }
            }
            catch (const std::exception& e)
            {
                std::printf("%s\n", e.what());
            }
        }

        filewriter.write("\n");
    }
}

IndicatorChartData ChartData::calculateSMA(unsigned periods, std::shared_ptr<CandleStickChartData> chartData)
{
    // infolog(logger, "%s()", __func__);
    IndicatorChartData indicatorData;

    //  copy over timestamps
    std::vector<TimeStamp> timestamps;
    for (auto& c : *chartData.get())
    {
        timestamps.push_back(c.first);
    }

    for (unsigned i = 0; i < timestamps.size(); i++)
    {
        if (i < periods - 1)
        {
            IndicatorValue ivalue;
            ivalue.isNan = true;
            indicatorData[timestamps[i]] = ivalue;
        }
        else
        {
            // calculate average with last n periods
            double closeAccum = 0;
            unsigned startIndex = i - (periods - 1);
            while (startIndex <= i)
            {
                closeAccum += (*chartData.get())[timestamps[startIndex]].price_close;
                startIndex += 1;
            }
            double sma = closeAccum / periods;
            IndicatorValue ivalue;
            ivalue.isNan = false;
            ivalue.value = sma;
            indicatorData[timestamps[i]] = ivalue;
        }
    }

    return indicatorData;
}

IndicatorChartData ChartData::calculateBB(
    unsigned periods, std::shared_ptr<CandleStickChartData> chartData, IndicatorTypes bbtype)
{
    // infolog(logger, "%s()", __func__);
    IndicatorChartData indicatorData;

    //  copy over timestamps
    std::vector<TimeStamp> timestamps;
    for (auto& c : *chartData.get())
    {
        timestamps.push_back(c.first);
    }

    for (unsigned i = 0; i < timestamps.size(); i++)
    {
        if (i < periods - 1)
        {
            IndicatorValue ivalue;
            ivalue.isNan = true;
            indicatorData[timestamps[i]] = ivalue;
        }
        else
        {
            // calculate average with last n periods
            double closeAccum = 0;
            unsigned startIndex = i - (periods - 1);
            while (startIndex <= i)
            {
                closeAccum += (*chartData.get())[timestamps[startIndex]].price_close;
                startIndex += 1;
            }
            double sma = closeAccum / periods;

            // calculate variance over last n periods
            startIndex = i - (periods - 1);
            double varianceSum = 0;
            while (startIndex <= i)
            {
                double val = (*chartData.get())[timestamps[startIndex]].price_close;
                double variance = val - sma;
                double variance2 = std::pow(variance, 2);
                varianceSum += variance2;
                startIndex += 1;
            }

            double stddev = sqrt(varianceSum / (periods - 1));

            IndicatorValue ivalue;
            ivalue.isNan = false;
            if (bbtype == IndicatorTypes::BBUP)
            {
                ivalue.value = sma + (stddev * 2);
            }
            else if (bbtype == IndicatorTypes::BBDOWN)
            {
                ivalue.value = sma - (stddev * 2);
            }
            else
            {
                throw std::runtime_error("wrong bbtype");
            }
            indicatorData[timestamps[i]] = ivalue;
        }
    }

    return indicatorData;
}

IndicatorChartData ChartData::calculateEMA(
    unsigned periods, unsigned smoothing, std::shared_ptr<CandleStickChartData> chartData)
{
    // infolog(logger, "%s()", __func__);
    /*emaToday = (valueToday * (smoothing/(1+periods))) + emaPrev * (1 - (smoothing/1+periods)))*/
    /*emaToday = (priceToday * multiplier) + emaPrev * (1 - multiplier)*/
    // DLOG(INFO) << "calcualteEMA() start";
    IndicatorChartData smaData = calculateSMA(periods, chartData);

    IndicatorChartData emaData;

    std::vector<TimeStamp> timestamps;
    for (auto& c : smaData)
    {
        timestamps.push_back(c.first);
    }
    for (unsigned i = 0; i < timestamps.size(); i++)
    {
        if (i < periods)
        {
            IndicatorValue ivalue;
            ivalue.isNan = true;
            emaData[timestamps[i]] = ivalue;
        }
        else if (i == periods)
        {
            double emaTodayTerm =
                (*chartData.get())[timestamps[i]].price_close * ((double)smoothing / (1 + (double)periods));
            double emaPrevTerm = smaData[timestamps[i - 1]].value * (1 - ((double)smoothing / (1 + (double)periods)));
            IndicatorValue ivalue;
            ivalue.value = emaTodayTerm + emaPrevTerm;
            ivalue.isNan = false;
            emaData[timestamps[i]] = ivalue;
        }
        else
        {
            double emaTodayTerm =
                (*chartData.get())[timestamps[i]].price_close * ((double)smoothing / (1 + (double)periods));
            double emaPrevTerm = emaData[timestamps[i - 1]].value * (1 - ((double)smoothing / (1 + (double)periods)));
            IndicatorValue ivalue;
            ivalue.value = emaTodayTerm + emaPrevTerm;
            ivalue.isNan = false;
            emaData[timestamps[i]] = ivalue;
        }
    }

    return emaData;
}

IndicatorChartData ChartData::calculateStochasticMomentum(int64_t highlowPeriods, int64_t emaPeriods,
    int64_t firstLevel, int64_t secondLevel, std::shared_ptr<CandleStickChartData> chartData)
{
    (void)highlowPeriods;
    (void)emaPeriods;
    (void)firstLevel;
    (void)secondLevel;
    (void)chartData;
    return {};
}

IndicatorChartData ChartData::calculateStochasticIndicator(int64_t periods)
{
    /*%K = ((C - L14) / (H14 - L 14)) * 100*/
    /*C = most recent closing price, L14 = lowest out of last 14 periods, H14 = highest out of last 14 periods*/
    // infolog(logger, "%s()", __func__);
    IndicatorChartData stochData;

    std::vector<TimeStamp> timestamps;
    for (auto& c : *chartData.get())
    {
        timestamps.push_back(c.first);
    }
    for (unsigned i = 0; i < timestamps.size(); i++)
    {
        if (i < periods - 1)
        {
            IndicatorValue ivalue;
            ivalue.isNan = true;
            stochData[timestamps[i]] = ivalue;
        }
        else
        {
            unsigned periodsIndex = i - (periods - 1);
            double C = (*chartData.get())[timestamps[i]].price_close;

            double Lperiod = 2147000000; // some bigass number to start with
            double Hperiod = 0;          // some negative number to start with

            while (periodsIndex <= i)
            {
                if ((*chartData.get())[timestamps[periodsIndex]].price_close < Lperiod)
                {
                    Lperiod = (*chartData.get())[timestamps[periodsIndex]].price_close;
                }

                if ((*chartData.get())[timestamps[periodsIndex]].price_close > Hperiod)
                {
                    Hperiod = (*chartData.get())[timestamps[periodsIndex]].price_close;
                }
                // std::cout << C << ", " << Lperiod << ", " << Hperiod << "\n";
                periodsIndex += 1;
            }
            double K = ((C - Lperiod) / (Hperiod - Lperiod)) * 100.0;
            IndicatorValue ivalue;
            ivalue.isNan = false;
            ivalue.value = K;
            stochData[timestamps[i]] = ivalue;
        }
    }
    return stochData;
}

IndicatorChartData ChartData::calculateStochoasticUpper(int64_t upperlevel)
{
    // infolog(logger, "%s()", __func__);
    IndicatorChartData stochData;

    std::vector<TimeStamp> timestamps;

    for (auto& c : *chartData.get())
    {
        timestamps.push_back(c.first);
    }
    for (unsigned i = 0; i < timestamps.size(); i++)
    {
        IndicatorValue ivalue;
        ivalue.isNan = false;
        ivalue.value = upperlevel;
        stochData[timestamps[i]] = ivalue;
    }
    return stochData;
}

IndicatorChartData ChartData::calculateStochoasticLower(int64_t lowerlevel)
{
    // infolog(logger, "%s()", __func__);
    IndicatorChartData stochData;

    std::vector<TimeStamp> timestamps;

    for (auto& c : *chartData.get())
    {
        timestamps.push_back(c.first);
    }
    for (unsigned i = 0; i < timestamps.size(); i++)
    {
        IndicatorValue ivalue;
        ivalue.isNan = false;
        ivalue.value = lowerlevel;
        stochData[timestamps[i]] = ivalue;
    }
    return stochData;
}

} // namespace charting