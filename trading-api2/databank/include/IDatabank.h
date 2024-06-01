#pragma once

#include "ChartsAggregator.h"

namespace databank {
using namespace charting;

class IDatabank
{
public:
    virtual void startParsing() = 0;
    virtual ChartTimeframesMap getChart(std::string symbol) = 0;
};
} // namespace databank