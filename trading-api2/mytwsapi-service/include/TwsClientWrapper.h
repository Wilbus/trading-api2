#pragma once

#include "ITwsClientWrapper.h"

class TwsClientWrapper : public ITwsClientWrapper
{
public:
    TwsClientWrapper()
    {
    }
    TwsClientWrapper(std::string ip, int port, int clientId, EWrapper* ewrapper);
    TwsClientWrapper(std::string ip, int port, std::string accountId, int clientId);
    // TwsClientWrapper(QString ip, int port, int clientId, EWrapper* wrapperImp);
    // TwsClientWrapper(QString ip, int port, int clientId, std::shared_ptr<EWrapper> wrapperImp);
    ~TwsClientWrapper();

    virtual bool connect() override;
    virtual void disconnect() override;
    virtual void processMsg() override;
    virtual void startMsgProcessing() override;
    virtual void cancelAllReqs() override
    {
    }

    virtual void setReqIdStart(int id) override
    {
        (void)id;
    }

    virtual void reqNextValidOrderId() override
    {
    }

    virtual void reqAccountSummary() override;
    virtual void reqAccountUpdates(std::string accountNumber) override;
    // void reqAccountUpdates(std::string accountNumber, int reqId);
    virtual void reqPositionUpdates() override;
    virtual void reqPositionUpdates(int reqId) override;
    virtual void cancelPositionUpdates() override;
    virtual void cancelPositionUpdates(int reqId) override;
    virtual void cancelAccountSummary() override;
    virtual void cancelAccountUpdates() override;

    virtual void reqContractDetails(Contract contract) override;
    virtual void reqContractDetails(int reqId, Contract contract) override;

    virtual void reqHistoricalData(Contract contract, std::string endDateTime, std::string durationStr,
        std::string barSizeSetting, std::string whatToShow, int useRTH, int formatDate, bool keepUpToDate) override;
    virtual void cancelHistoricalData() override;
    virtual void reqHistoricalDataId(int reqId, Contract contract, std::string endDateTime, std::string durationStr,
        std::string barSizeSetting, std::string whatToShow, int useRTH, int formatDate, bool keepUpToDate) override;
    virtual void cancelHistoricalDataId(int reqId) override;

    virtual void reqScannerSubscription(const ScannerSubscription& subscription,
        const TagValueListSPtr& scannerSubscriptionOptions,
        const TagValueListSPtr& scannerSubscriptionFilterOptions) override;
    virtual void cancelScannerSubscription() override;

    virtual void reqMarketDataType(int typeId) override;
    // 5 second bars
    // whatToShow can be "TRADES, MIDPOINT, BID, ASK"
    virtual void reqRealTimeBars(int id, Contract contract, std::string whatToShow, bool useRTH) override;
    virtual void cancelRealTimeBars() override;

    virtual void reqMktData(int reqId, Contract contract, std::string ticklist, bool snapshot, bool regulatorySnapshot,
        TagValueListSPtr options) override;
    virtual void reqTickByTickDataBidAsk(Contract contract) override;
    virtual void reqTickByTickDataMid(int reqid, Contract contract, int ticks) override;
    virtual void cancelTickByTickData() override;
    virtual void cancelTickByTickData(int reqid) override;
    virtual void cancelReqMktData(int reqId) override;

    virtual void placeOrder(Contract con, Order order) override;
    virtual void placeOrder(OrderId id, Contract con, Order order) override;

    virtual void reqWshEventData(WshEventData eventData) override;
    virtual void reqWshMetaEventData() override;

    virtual void reqSecDefOptParams(int id, std::string underlyingSymbol, std::string futFopExchange,
        std::string underlyingSecType, int underlyingConId) override;

    /*reportType = ReportSnapshot, ReportsFinSummary, ReportRatios, ReportsFinStatements, RESC*/
    virtual void reqFundamentals(
        const Contract& con, const std::string& reportType, const TagValueListSPtr& fundamentalDataOptions) override;

    std::string ip;
    int port;
    int clientId;
    EWrapper* ewrapper;
    EReaderOSSignal* signal;
    EClientSocket* clientSocket;
    EReader* reader;

    std::thread msgProcessThread;

    // std::map<int, RequestType> reqIdMap;
    std::vector<unsigned> activeReqs;
    unsigned reqIdCounter{0};
    bool connected{false};
    std::string accountNumber;

    OrderId currOrderId;
    std::string accountId;
};
