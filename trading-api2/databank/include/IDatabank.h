#pragma once

#include "ChartData3.h"

namespace databank {
using namespace charting;

class IDatabank
{
public:
    virtual void startParsing() = 0;
    virtual ChartData3 getChart(std::string symbol) = 0;
};
} // namespace databank