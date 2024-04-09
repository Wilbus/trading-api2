#pragma once

#include "ChartData2.h"

namespace databank {
using namespace charting;

class IDatabank
{
public:
    virtual void startParsing() = 0;
    virtual ChartData2 getChart(std::string symbol) = 0;
};
} // namespace databank