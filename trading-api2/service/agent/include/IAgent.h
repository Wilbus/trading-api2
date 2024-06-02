#pragma once

#include "ChartAggregatorTypes.h"

using namespace databank;

class IAgent
{
public:
    virtual void startAgent() = 0;
    virtual void startBackTest(const ChartTimeframesMap& timeframesChart) = 0;
    virtual void waitForAgent() = 0;
    virtual bool InPostion() = 0;
};