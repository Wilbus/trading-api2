#pragma once

#include "CandleStick.h"
#include "FileWriter.hpp"
#include "IndicatorTypes.h"
#include "Logger.h"

#include <map>
#include <memory>
#include <mutex>

namespace charting {
using namespace utils;
// TODO: maybe combine indicators + chart into one structure?
typedef uint64_t TimeStamp;
typedef std::map<TimeStamp, IndicatorValue> IndicatorChartData;
typedef std::map<TimeStamp, CandleStick> CandleStickChartData;
typedef std::map<IndicatorType, IndicatorChartData> IndicatorsChartDataMap;

class ChartData
{
public:
    ChartData()
    {
    }

    ChartData(std::shared_ptr<Logger> logger, uint32_t maxTicks = 1000000);

    ChartData(std::shared_ptr<Logger> logger, std::shared_ptr<CandleStickChartData>& chartData,
        uint32_t maxDataTicks = 100000);

    // copy constructor
    ChartData(const ChartData& other)
    {
        logger = other.getLogger();
        maxDataTicks = other.getMaxDataTicks();
        chartData = other.getChartData();
        indicatorsDataMap = other.getIndicatorsDataMap();
        chartSize = other.getChartData()->size();
    }

    ChartData& operator=(const ChartData& other) // copy assignment
    {
        /*guard self assignment*/
        if (this == &other)
        {
            return *this;
        }

        chartData = other.getChartData();
        chartSize = other.getChartData()->size();
        indicatorsDataMap = other.getIndicatorsDataMap();
        logger = other.getLogger();
        maxDataTicks = other.getMaxDataTicks();
        // TODO: should probably delete other instance

        return *this;
    }

    void addIndicatorData(IndicatorType indicatortype);
    void addCandle(CandleStick candle);
    void setChartData(std::shared_ptr<CandleStickChartData> chartdata);
    void setChartDataByVector(std::vector<CandleStick> candles);

    void dumpToCSV(std::string csvfilePath);
    std::shared_ptr<CandleStickChartData> getChartData() const;
    CandleStickChartData getChartDataCopy();
    uint64_t getChartSize() const;
    std::set<IndicatorType> getIndicatorsTypes();
    IndicatorChartData getIndicatorData(IndicatorType indicatorName);
    IndicatorsChartDataMap getIndicatorsDataMap() const;

    void setIndicatorsDataMap(IndicatorsChartDataMap indicatorsChartDataMap)
    {
        indicatorsDataMap = indicatorsChartDataMap;
    }

    CandleStick getRecentCandle(int periodsBack);
    IndicatorValue getRecentIndicatorValue(std::string indicatorName, int periodsBack);

    /*indicators begin*/
    IndicatorChartData calculateSMA(unsigned periods, std::shared_ptr<CandleStickChartData> chartData);
    IndicatorChartData calculateBB(
        unsigned periods, std::shared_ptr<CandleStickChartData> chartData, IndicatorTypes bbtype);
    IndicatorChartData calculateStochasticMomentum(int64_t highlowPeriods, int64_t emaPeriods, int64_t firstLevel,
        int64_t secondLevel, std::shared_ptr<CandleStickChartData> chartData);
    IndicatorChartData calculateEMA(
        unsigned periods, unsigned smoothing, std::shared_ptr<CandleStickChartData> chartData);
    IndicatorChartData calculateStochasticIndicator(int64_t periods);
    IndicatorChartData calculateStochoasticUpper(int64_t upperlevel);
    IndicatorChartData calculateStochoasticLower(int64_t lowerlevel);

    void setLogger(std::shared_ptr<Logger> logger)
    {
        logger = logger;
    }

    void setMaxDataTicks(uint32_t ticks)
    {
        maxDataTicks = ticks;
    }

    std::shared_ptr<Logger> getLogger() const
    {
        return logger;
    }

    uint32_t getMaxDataTicks() const
    {
        return maxDataTicks;
    }

private:
    void updateIndicators(CandleStick candle);
    IndicatorChartData indicatorDataCalculator(IndicatorType indicatortype);
    bool checkTimestamps(IndicatorChartData indicatorsData)
    {
        if (chartData->size() != indicatorsData.size())
        {
            std::cout << "new indicator chart of length " << indicatorsData.size()
                      << " being added doesn't match expected length of " << chartData->size();
            return false;
        }

        unsigned count = 0;
        auto indicatorItr = indicatorsData.begin();
        for (auto chartItr = chartData->begin(); chartItr != chartData->end(); ++chartItr)
        {
            if (chartItr->first != indicatorItr->first)
            {
                std::cout << "original timestamp at index: " << count << " which is " << chartItr->first
                          << " doesn't match new indicator timestamp: " << indicatorItr->first;
                return false;
            }
            ++indicatorItr;
            count++;
        }
        return true;
    }
    std::shared_ptr<CandleStickChartData> chartData; // TODO TOP: combine chart data and indicatorsdatamap into one
                                                     // object
    IndicatorsChartDataMap indicatorsDataMap;        // doesn't need to be a pointer. Can live only within
                                                     // ChartData for now
    uint32_t maxDataTicks;
    std::shared_ptr<Logger> logger;
    uint64_t chartSize;
    std::mutex mtx;
};
} // namespace charting