#pragma once

#include "FileWriter.hpp"
#include "IndicatorTypes.h"
#include "MultiCandle.h"
#include "ta-lib-wrapper.h"

namespace charting {
using namespace utils;
using ta_lib_wrapper::TALIB;

class ChartData3
{
public:
    ChartData3();

    void addMultiCandle(
        MultiCandle mcandle); // ensure that the candle is added to the end of the vector and sorted by timestamp
    void addMultiCandles(std::vector<MultiCandle> mcandles);

    std::vector<MultiCandle> getMultiCandles() const;

    size_t getSize() const
    {
        return mcandles.size();
    }
    MultiCandle getBack(size_t index) const
    {
        if (index >= mcandles.size())
        {
            throw std::runtime_error("ChartData3::getBack: index out of range");
        }
        return mcandles.at(mcandles.size() - 1 - index);
    }

    MultiCandle getFront(size_t index) const
    {
        if (index >= mcandles.size())
        {
            throw std::runtime_error("ChartData3::getFront: index out of range");
        }
        return mcandles.at(index);
    }

    void dumpToCSV(std::string& csvString) const;

    void addIndicator(IndicatorType indicatortype);

private:
    bool checkTimestampAlignment(std::vector<IndicatorValue> ivalues);
    void updateIndicatorsData(IndicatorType indicatorType);

    std::vector<IndicatorValue> calculateSMA(unsigned periods);
    std::vector<IndicatorValue> calculateBB(unsigned periods, IndicatorTypes bbtype);
    std::vector<IndicatorValue> calculateStochasticMomentum(
        int64_t highlowPeriods, int64_t emaPeriods, int64_t firstLevel, int64_t secondLevel);
    std::vector<IndicatorValue> calculateEMA(unsigned periods, unsigned smoothing);
    std::vector<IndicatorValue> calculate3WhiteSoldiers();
    std::vector<IndicatorValue> calculate3BlackCrows();

    std::vector<MultiCandle> mcandles;
    std::vector<IndicatorType> indicatorTypes;
    uint32_t maxTicks{1000000};
};

} // namespace charting
