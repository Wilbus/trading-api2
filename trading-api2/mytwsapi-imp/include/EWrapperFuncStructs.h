#pragma once

#include "CommonDefs.h"

struct RealTimeBar
{
    TickerId reqId;
    long time;
    double open;
    double high;
    double low;
    double close;
    Decimal volume;
    Decimal wap;
    int count;
};