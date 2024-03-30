#include "EWrapperBaseImp.h"

void EWrapperBaseImp::realtimeBar(TickerId reqId, long time, double open, double high, double low, double close,
    Decimal volume, Decimal wap, int count)
{
    RealTimeBar b(reqId, time, open, high, low, close, volume, wap, count);
    realtimeBarFunc(b);
}

void EWrapperBaseImp::error(
    int id, int errorCode, const std::string& errorString, const std::string& advancedOrderRejectJson)
{
    std::printf("%i %i %s %s\n", id, errorCode, errorString.c_str(), advancedOrderRejectJson.c_str());
}

void EWrapperBaseImp::historicalData(TickerId reqId, const Bar& bar)
{
    historicalDataFunc(reqId, bar);
}

void EWrapperBaseImp::historicalDataEnd(int reqId, const std::string& startDateStr, const std::string& endDateStr)
{
    historicalDataEnd(reqId, startDateStr, endDateStr);
}

void EWrapperBaseImp::historicalDataUpdate(TickerId reqId, const Bar& bar)
{
    historicalDataUpdate(reqId, bar);
}