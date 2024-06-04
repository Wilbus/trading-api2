#pragma once

#include "ChartAggregatorTypes.h"

using namespace databank;

class IAgent
{
public:
    virtual void startAgent() = 0;
    virtual void startBackTest() = 0;
    virtual void waitForAgent() = 0;
    virtual bool InPostion() = 0;
    virtual bool inSpecificPosition(const std::string& symbol) const = 0;
};