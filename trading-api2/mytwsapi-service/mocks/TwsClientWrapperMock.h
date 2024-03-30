#pragma once

#include "ITwsClientWrapper.h"

#include <gmock/gmock.h>

class TwsClientWrapperMock : public ITwsClientWrapper
{
public:
    MOCK_METHOD0(connect, bool());
    MOCK_METHOD0(disconnect, void());
    MOCK_METHOD0(processMsg, void());
    MOCK_METHOD0(startMsgProcessing, void());
    MOCK_METHOD0(cancelAllReqs, void());
    MOCK_METHOD1(setReqIdStart, void(int));
    MOCK_METHOD0(reqNextValidOrderId, void());
    MOCK_METHOD0(reqAccountSummary, void());
    MOCK_METHOD1(reqAccountUpdates, void(std::string));
    MOCK_METHOD0(reqPositionUpdates, void());
    MOCK_METHOD1(reqPositionUpdates, void(int));
    MOCK_METHOD0(cancelPositionUpdates, void());
    MOCK_METHOD1(cancelPositionUpdates, void(int));
    MOCK_METHOD0(cancelAccountSummary, void());
    MOCK_METHOD0(cancelAccountUpdates, void());
    MOCK_METHOD1(reqContractDetails, void(Contract));
    MOCK_METHOD2(reqContractDetails, void(int, Contract));
    MOCK_METHOD8(reqHistoricalData, void(Contract, std::string, std::string, std::string, std::string, int, int, bool));
    MOCK_METHOD0(cancelHistoricalData, void());
    MOCK_METHOD9(
        reqHistoricalDataId, void(int, Contract, std::string, std::string, std::string, std::string, int, int, bool));
    MOCK_METHOD1(cancelHistoricalDataId, void(int));
    MOCK_METHOD3(
        reqScannerSubscription, void(const ScannerSubscription&, const TagValueListSPtr&, const TagValueListSPtr&));
    MOCK_METHOD0(cancelScannerSubscription, void());
    MOCK_METHOD1(reqMarketDataType, void(int));
    MOCK_METHOD4(reqRealTimeBars, void(int, Contract, std::string, bool));
    MOCK_METHOD0(cancelRealTimeBars, void());
    MOCK_METHOD6(reqMktData, void(int, Contract, std::string, bool, bool, TagValueListSPtr));
    MOCK_METHOD1(reqTickByTickDataBidAsk, void(Contract));
    MOCK_METHOD3(reqTickByTickDataMid, void(int, Contract, int));
    MOCK_METHOD0(cancelTickByTickData, void());
    MOCK_METHOD1(cancelTickByTickData, void(int));
    MOCK_METHOD1(cancelReqMktData, void(int));
    MOCK_METHOD2(placeOrder, void(Contract, Order));
    MOCK_METHOD3(placeOrder, void(OrderId, Contract, Order));
    MOCK_METHOD1(reqWshEventData, void(WshEventData));
    MOCK_METHOD0(reqWshMetaEventData, void());
    MOCK_METHOD5(reqSecDefOptParams, void(int, std::string, std::string, std::string, int));
    MOCK_METHOD3(reqFundamentals, void(const Contract&, const std::string&, const TagValueListSPtr&));
};