#pragma once

#include "FileWriter.hpp"
#include "IndicatorTypes.h"
#include "MultiCandle.h"
#include "ta-lib-wrapper.h"

#include <any>
#include <map>
#include <memory>
#include <mutex>
#include <unordered_map>

namespace charting {
using namespace utils;
using ta_lib_wrapper::TALIB;

typedef std::vector<MultiCandle> MCandles;

class ChartData2
{
public:
    ChartData2()
    {
    }

    ChartData2(uint32_t maxTicks = 1000000);

    ChartData2(MCandles chartData, uint32_t maxDataTicks = 100000);

    ChartData2(const ChartData2& other)
    {
        mcandles = other.getMCandles();
        maxTicks = other.getMaxTicks();
    }

    ChartData2& operator=(const ChartData2& other)
    {
        if (this == &other)
        {
            return *this;
        }

        mcandles = other.getMCandles();
        maxTicks = other.getMaxTicks();
        return *this;
    }

    MultiCandle& operator[](std::size_t idx)
    {
        return mcandles[mcandles.size() - 1 - idx];
    }

    MultiCandle& at(unsigned i)
    {
        return mcandles[i];
    }

    MCandles getMCandles() const
    {
        return mcandles;
    }

    void setMCandles(std::vector<MultiCandle> mcandlevec)
    {
        if (mcandlevec.size() == 0)
        {
            throw std::runtime_error("cannot set an chartdata to empty vec");
        }
        mcandles = mcandlevec;
        sortMCandles();
    }

    void setChartDataByVector(std::vector<CandleStick> candles)
    {
        if (candles.size() == 0)
        {
            throw std::runtime_error("cannot set an chartdata to empty vec");
        }
        for (unsigned i = 0; i < candles.size(); i++)
        {
            MultiCandle mcandle(candles[i]);
            mcandles.push_back(mcandle);
        }
        sortMCandles();
    }

    unsigned getSize()
    {
        return mcandles.size();
    }

    unsigned getMaxTicks() const
    {
        return maxTicks;
    }

    void addIndicatorData(IndicatorType indicatortype);
    void addCandle(CandleStick candle);

    void dumpToCSV(std::string csvfilePath);

    void setIndicatorValueAtIndex(unsigned idx, IndicatorType indicatortype, IndicatorValue value);

    /*indicators begin*/
    std::vector<IndicatorValue> calculateSMA(unsigned periods);
    std::vector<IndicatorValue> calculateBB(unsigned periods, IndicatorTypes bbtype);
    std::vector<IndicatorValue> calculateStochasticMomentum(
        int64_t highlowPeriods, int64_t emaPeriods, int64_t firstLevel, int64_t secondLevel);
    std::vector<IndicatorValue> calculateEMA(unsigned periods, unsigned smoothing);
    std::vector<IndicatorValue> calculateStochasticIndicator(int64_t periods);
    std::vector<IndicatorValue> calculateStochoasticUpper(int64_t upperlevel);
    std::vector<IndicatorValue> calculateStochoasticLower(int64_t lowerlevel);

private:
    std::vector<IndicatorValue> indicatorDataCalculator(IndicatorType indicatortype);
    bool checkTimestampAlignment(std::vector<IndicatorValue> ivalues);
    void sortMCandles();
    void updateIndicators();

    std::vector<MultiCandle> mcandles;
    unsigned maxTicks;

    std::mutex mtx;

    TALIB talib;
};
} // namespace charting