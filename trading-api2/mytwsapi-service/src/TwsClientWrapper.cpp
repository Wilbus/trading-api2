#include "TwsClientWrapper.h"

#include "ReqIdTypes.h"

TwsClientWrapper::TwsClientWrapper(std::string ip, int port, int clientId, EWrapper* ewrapper)
    : ip(ip)
    , port(port)
    , clientId(clientId)
    , ewrapper(ewrapper)
{
    signal = new EReaderOSSignal();
    clientSocket = new EClientSocket(ewrapper, signal);
}

TwsClientWrapper::~TwsClientWrapper()
{
    disconnect();
}

bool TwsClientWrapper::connect()
{
    bool conn = clientSocket->eConnect(ip.c_str(), port, clientId, false);
    if (conn)
    {
        reader = new EReader(clientSocket, signal);
        reader->start(); // reader thread start
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(500ms);

        // reqAccountUpdates("DU8491376");
        // reqPositionUpdates();
        // reqNextValidOrderId();
        connected = true;
    }
    return conn;
}

void TwsClientWrapper::disconnect()
{
    if (connected)
        clientSocket->eDisconnect();
}

void TwsClientWrapper::processMsg() // message process thread
{
    // reads from readerqueue when signaled
    // should call wrapperimp functions automatically
    while (true)
    {
        signal->waitForSignal();
        reader->processMsgs();
    }
}

void TwsClientWrapper::startMsgProcessing()
{
    msgProcessThread = std::thread(&TwsClientWrapper::processMsg, this);
}

void TwsClientWrapper::reqAccountSummary()
{
    clientSocket->reqAccountSummary(ReqIdType::reqAccountSummary, "All", "$LEDGER:USD");
}

void TwsClientWrapper::reqAccountUpdates(std::string accountNumber)
{
    this->accountNumber = accountNumber;
    clientSocket->reqAccountUpdates(true, accountNumber);
}

void TwsClientWrapper::reqPositionUpdates()
{
    // clientSocket->reqPositions();
    clientSocket->reqPositionsMulti(ReqIdType::reqPostionUpdates, accountNumber, "");
}

void TwsClientWrapper::reqPositionUpdates(int reqId)
{
    // clientSocket->reqPositions();
    clientSocket->reqPositionsMulti(reqId, accountNumber, "");
}

void TwsClientWrapper::cancelPositionUpdates()
{
    // clientSocket->cancelPositions();
    clientSocket->cancelPositionsMulti(ReqIdType::reqPostionUpdates);
}

void TwsClientWrapper::cancelPositionUpdates(int reqId)
{
    // clientSocket->cancelPositions();
    clientSocket->cancelPositionsMulti(reqId);
}

void TwsClientWrapper::cancelAccountSummary()
{
    clientSocket->cancelAccountSummary(ReqIdType::reqAccountSummary);
}

void TwsClientWrapper::cancelAccountUpdates()
{
    clientSocket->reqAccountUpdates(false, accountNumber);
}

void TwsClientWrapper::reqScannerSubscription(const ScannerSubscription& subscription,
    const TagValueListSPtr& scannerSubscriptionOptions,
    const TagValueListSPtr& scannerSubscriptionFilterOptions)
{
    clientSocket->reqScannerSubscription(
        ReqIdType::reqScannerSubscription, subscription, scannerSubscriptionOptions, scannerSubscriptionFilterOptions);
}

void TwsClientWrapper::cancelScannerSubscription()
{
    clientSocket->cancelScannerSubscription(ReqIdType::reqScannerSubscription);
}

void TwsClientWrapper::reqContractDetails(Contract contract)
{
    clientSocket->reqContractDetails(ReqIdType::reqContractDetails, contract);
}

void TwsClientWrapper::reqContractDetails(int reqId, Contract contract)
{
    clientSocket->reqContractDetails(reqId, contract);
}

void TwsClientWrapper::reqHistoricalData(Contract contract, std::string endDateTime, std::string durationStr,
    std::string barSizeSetting, std::string whatToShow, int useRTH, int formatDate, bool keepUpToDate)
{
    clientSocket->reqHistoricalData(ReqIdType::reqHistoricalData, contract, endDateTime, durationStr, barSizeSetting,
        whatToShow, useRTH, formatDate, keepUpToDate, TagValueListSPtr());
}

void TwsClientWrapper::cancelHistoricalData()
{
    clientSocket->cancelHistoricalData(ReqIdType::reqHistoricalData);
}

void TwsClientWrapper::reqHistoricalDataId(int id, Contract contract, std::string endDateTime, std::string durationStr,
    std::string barSizeSetting, std::string whatToShow, int useRTH, int formatDate, bool keepUpToDate)
{
    clientSocket->reqHistoricalData(id, contract, endDateTime, durationStr, barSizeSetting, whatToShow, useRTH,
        formatDate, keepUpToDate, TagValueListSPtr());
}

void TwsClientWrapper::cancelHistoricalDataId(int id)
{
    clientSocket->cancelHistoricalData(id);
}

void TwsClientWrapper::reqRealTimeBars(int id, Contract contract, std::string whatToShow, bool useRTH)
{
    clientSocket->reqRealTimeBars(id, contract, 5, whatToShow, useRTH, TagValueListSPtr());
}

void TwsClientWrapper::cancelRealTimeBars()
{
    clientSocket->cancelRealTimeBars(ReqIdType::reqRealTimeBars);
}

void TwsClientWrapper::reqMarketDataType(int type)
{
    clientSocket->reqMarketDataType(type);
}

void TwsClientWrapper::reqTickByTickDataBidAsk(Contract contract)
{
    clientSocket->reqTickByTickData(ReqIdType::reqTickByTickBidAsk, contract, "BidAsk", tickByTickCount, false);
}

void TwsClientWrapper::cancelTickByTickData()
{
    clientSocket->cancelTickByTickData(ReqIdType::reqTickByTickBidAsk);
}

void TwsClientWrapper::cancelTickByTickData(int reqid)
{
    clientSocket->cancelTickByTickData(reqid);
}

void TwsClientWrapper::reqTickByTickDataMid(int reqid, Contract contract, int ticks)
{
    clientSocket->reqTickByTickData(reqid, contract, "MidPoint", ticks, true);
}

void TwsClientWrapper::reqMktData(int reqId, Contract contract, std::string ticklist, bool snapshot,
    bool regulatorySnapshot, TagValueListSPtr options)
{
    clientSocket->reqMktData(reqId, contract, ticklist, snapshot, regulatorySnapshot, options);
}

void TwsClientWrapper::cancelReqMktData(int reqId)
{
    clientSocket->cancelMktData(reqId);
}

void TwsClientWrapper::placeOrder(Contract con, Order order)
{
    clientSocket->placeOrder(currOrderId, con, order);
    reqNextValidOrderId();
}

void TwsClientWrapper::placeOrder(OrderId id, Contract con, Order order)
{
    clientSocket->placeOrder(id, con, order);
}

void TwsClientWrapper::reqWshEventData(WshEventData eventData)
{
    clientSocket->reqWshEventData(ReqIdType::reqWshEventData, eventData);
}

void TwsClientWrapper::reqWshMetaEventData()
{
    clientSocket->reqWshMetaData(ReqIdType::reqWshEventData);
}

void TwsClientWrapper::reqFundamentals(
    const Contract& con, const std::string& reportType, const TagValueListSPtr& fundamentalDataOptions)
{
    clientSocket->reqFundamentalData(10, con, reportType, fundamentalDataOptions);
}

void TwsClientWrapper::reqSecDefOptParams(int id, std::string underlyingSymbol, std::string futFopExchange,
    std::string underlyingSecType, int underlyingConId)
{
    clientSocket->reqSecDefOptParams(id, underlyingSymbol, futFopExchange, underlyingSecType, underlyingConId);
}
