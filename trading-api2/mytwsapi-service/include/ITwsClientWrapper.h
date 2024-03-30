#pragma once

#include "Contract.h"
#include "EClientSocket.h"
#include "EReader.h"
#include "EReaderOSSignal.h"
#include "EWrapper.h"
#include "Order.h"

#include <thread>

class ITwsClientWrapper
{
    virtual bool connect() = 0;
    virtual void disconnect() = 0;
    virtual void processMsg() = 0;
    virtual void startMsgProcessing() = 0;
    virtual void cancelAllReqs() = 0;

    virtual void setReqIdStart(int id) = 0;

    virtual void reqNextValidOrderId() = 0;

    virtual void reqAccountSummary() = 0;
    virtual void reqAccountUpdates(std::string accountNumber) = 0;
    // void reqAccountUpdates(std::string accountNumber, int reqId);
    virtual void reqPositionUpdates() = 0;
    virtual void reqPositionUpdates(int reqId) = 0;
    virtual void cancelPositionUpdates() = 0;
    virtual void cancelPositionUpdates(int reqId) = 0;
    virtual void cancelAccountSummary() = 0;
    virtual void cancelAccountUpdates() = 0;

    virtual void reqContractDetails(Contract contract) = 0;
    virtual void reqContractDetails(int reqId, Contract contract) = 0;

    virtual void reqHistoricalData(Contract contract, std::string endDateTime, std::string durationStr,
        std::string barSizeSetting, std::string whatToShow, int useRTH, int formatDate, bool keepUpToDate) = 0;
    virtual void cancelHistoricalData() = 0;
    virtual void reqHistoricalDataId(int reqId, Contract contract, std::string endDateTime, std::string durationStr,
        std::string barSizeSetting, std::string whatToShow, int useRTH, int formatDate, bool keepUpToDate) = 0;
    virtual void cancelHistoricalDataId(int reqId) = 0;

    virtual void reqScannerSubscription(const ScannerSubscription& subscription,
        const TagValueListSPtr& scannerSubscriptionOptions,
        const TagValueListSPtr& scannerSubscriptionFilterOptions) = 0;
    virtual void cancelScannerSubscription() = 0;

    virtual void reqMarketDataType(int typeId) = 0;
    // 5 second bars
    // whatToShow can be "TRADES, MIDPOINT, BID, ASK"
    virtual void reqRealTimeBars(int id, Contract contract, std::string whatToShow, bool useRTH) = 0;
    virtual void cancelRealTimeBars() = 0;

    virtual void reqMktData(int reqId, Contract contract, std::string ticklist, bool snapshot, bool regulatorySnapshot,
        TagValueListSPtr options) = 0;
    virtual void reqTickByTickDataBidAsk(Contract contract) = 0;
    virtual void reqTickByTickDataMid(int reqid, Contract contract, int ticks) = 0;
    virtual void cancelTickByTickData() = 0;
    virtual void cancelTickByTickData(int reqid) = 0;
    virtual void cancelReqMktData(int reqId) = 0;

    virtual void placeOrder(Contract con, Order order) = 0;
    virtual void placeOrder(OrderId id, Contract con, Order order) = 0;

    virtual void reqWshEventData(WshEventData eventData) = 0;
    virtual void reqWshMetaEventData() = 0;

    virtual void reqSecDefOptParams(int id, std::string underlyingSymbol, std::string futFopExchange,
        std::string underlyingSecType, int underlyingConId) = 0;

    /*reportType = ReportSnapshot, ReportsFinSummary, ReportRatios, ReportsFinStatements, RESC*/
    virtual void reqFundamentals(
        const Contract& con, const std::string& reportType, const TagValueListSPtr& fundamentalDataOptions) = 0;
};