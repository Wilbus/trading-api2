#include "EWrapper.h"
#include "EWrapperFuncStructs.h"

#include <gmock/gmock.h>

class EWrapperMock : public EWrapper
{
    MOCK_METHOD(
        void, tickPrice, (TickerId tickerId, TickType field, double price, const TickAttrib& attrib), (override));
    MOCK_METHOD(void, tickSize, (TickerId tickerId, TickType field, Decimal size), (override));
    MOCK_METHOD(void, tickOptionComputation,
        (TickerId tickerId, TickType tickType, int tickAttrib, double impliedVol, double delta, double optPrice,
            double pvDividend, double gamma, double vega, double theta, double undPrice),
        (override));
    MOCK_METHOD(void, tickGeneric, (TickerId tickerId, TickType tickType, double value), (override));
    MOCK_METHOD(void, tickString, (TickerId tickerId, TickType tickType, const std::string& value), (override));
    MOCK_METHOD(void, tickEFP,
        (TickerId tickerId, TickType tickType, double basisPoints, const std::string& formattedBasisPoints,
            double totalDividends, int holdDays, const std::string& futureLastTradeDate, double dividendImpact,
            double dividendsToLastTradeDate),
        (override));
    MOCK_METHOD(void, orderStatus,
        (OrderId orderId, const std::string& status, Decimal filled, Decimal remaining, double avgFillPrice, int permId,
            int parentId, double lastFillPrice, int clientId, const std::string& whyHeld, double mktCapPrice),
        (override));
    MOCK_METHOD(void, openOrder, (OrderId orderId, const Contract&, const Order&, const OrderState&), (override));
    MOCK_METHOD(void, openOrderEnd, (), (override));
    MOCK_METHOD(void, winError, (const std::string& str, int lastError), (override));
    MOCK_METHOD(void, connectionClosed, (), (override));
    MOCK_METHOD(void, updateAccountValue,
        (const std::string& key, const std::string& val, const std::string& currency, const std::string& accountName),
        (override));
    MOCK_METHOD(void, updatePortfolio,
        (const Contract& contract, Decimal position, double marketPrice, double marketValue, double averageCost,
            double unrealizedPNL, double realizedPNL, const std::string& accountName),
        (override));
    MOCK_METHOD(void, updateAccountTime, (const std::string& timeStamp), (override));
    MOCK_METHOD(void, accountDownloadEnd, (const std::string& accountName), (override));
    MOCK_METHOD(void, nextValidId, (OrderId orderId), (override));
    MOCK_METHOD(void, contractDetails, (int reqId, const ContractDetails& contractDetails), (override));
    MOCK_METHOD(void, bondContractDetails, (int reqId, const ContractDetails& contractDetails), (override));
    MOCK_METHOD(void, contractDetailsEnd, (int reqId), (override));
    MOCK_METHOD(void, execDetails, (int reqId, const Contract& contract, const Execution& execution), (override));
    MOCK_METHOD(void, execDetailsEnd, (int reqId), (override));
    MOCK_METHOD(void, error,
        (int id, int errorCode, const std::string& errorString, const std::string& advancedOrderRejectJson),
        (override));
    MOCK_METHOD(void, updateMktDepth, (TickerId id, int position, int operation, int side, double price, Decimal size),
        (override));
    MOCK_METHOD(void, updateMktDepthL2,
        (TickerId id, int position, const std::string& marketMaker, int operation, int side, double price, Decimal size,
            bool isSmartDepth),
        (override));
    MOCK_METHOD(void, updateNewsBulletin,
        (int msgId, int msgType, const std::string& newsMessage, const std::string& originExch), (override));
    MOCK_METHOD(void, managedAccounts, (const std::string& accountsList), (override));
    MOCK_METHOD(void, receiveFA, (faDataType pFaDataType, const std::string& cxml), (override));
    MOCK_METHOD(void, historicalData, (TickerId reqId, const Bar& bar), (override));
    MOCK_METHOD(void, historicalDataEnd, (int reqId, const std::string& startDateStr, const std::string& endDateStr),
        (override));
    MOCK_METHOD(void, scannerParameters, (const std::string& xml), (override));
    MOCK_METHOD(void, scannerData,
        (int reqId, int rank, const ContractDetails& contractDetails, const std::string& distance,
            const std::string& benchmark, const std::string& projection, const std::string& legsStr),
        (override));
    MOCK_METHOD(void, scannerDataEnd, (int reqId), (override));
    MOCK_METHOD(void, realtimeBar,
        (TickerId reqId, long time, double open, double high, double low, double close, Decimal volume, Decimal wap,
            int count),
        (override));
    MOCK_METHOD(void, currentTime, (long time), (override));
    MOCK_METHOD(void, fundamentalData, (TickerId reqId, const std::string& data), (override));
    MOCK_METHOD(
        void, deltaNeutralValidation, (int reqId, const DeltaNeutralContract& deltaNeutralContract), (override));
    MOCK_METHOD(void, tickSnapshotEnd, (int reqId), (override));
    MOCK_METHOD(void, marketDataType, (TickerId reqId, int marketDataType), (override));
    MOCK_METHOD(void, commissionReport, (const CommissionReport& commissionReport), (override));
    MOCK_METHOD(void, position,
        (const std::string& account, const Contract& contract, Decimal position, double avgCost), (override));
    MOCK_METHOD(void, positionEnd, (), (override));
    MOCK_METHOD(void, accountSummary,
        (int reqId, const std::string& account, const std::string& tag, const std::string& value,
            const std::string& curency),
        (override));
    MOCK_METHOD(void, accountSummaryEnd, (int reqId), (override));
    MOCK_METHOD(void, verifyMessageAPI, (const std::string& apiData), (override));
    MOCK_METHOD(void, verifyCompleted, (bool isSuccessful, const std::string& errorText), (override));
    MOCK_METHOD(void, displayGroupList, (int reqId, const std::string& groups), (override));
    MOCK_METHOD(void, displayGroupUpdated, (int reqId, const std::string& contractInfo), (override));
    MOCK_METHOD(
        void, verifyAndAuthMessageAPI, (const std::string& apiData, const std::string& xyzChallange), (override));
    MOCK_METHOD(void, verifyAndAuthCompleted, (bool isSuccessful, const std::string& errorText), (override));
    MOCK_METHOD(void, connectAck, (), (override));
    MOCK_METHOD(void, positionMulti,
        (int reqId, const std::string& account, const std::string& modelCode, const Contract& contract, Decimal pos,
            double avgCost),
        (override));
    MOCK_METHOD(void, positionMultiEnd, (int reqId), (override));
    MOCK_METHOD(void, accountUpdateMulti,
        (int reqId, const std::string& account, const std::string& modelCode, const std::string& key,
            const std::string& value, const std::string& currency),
        (override));
    MOCK_METHOD(void, accountUpdateMultiEnd, (int reqId), (override));
    MOCK_METHOD(void, securityDefinitionOptionalParameter,
        (int reqId, const std::string& exchange, int underlyingConId, const std::string& tradingClass,
            const std::string& multiplier, const std::set<std::string>& expirations, const std::set<double>& strikes),
        (override));
    MOCK_METHOD(void, securityDefinitionOptionalParameterEnd, (int reqId), (override));
    MOCK_METHOD(void, softDollarTiers, (int reqId, const std::vector<SoftDollarTier>& tiers), (override));
    MOCK_METHOD(void, familyCodes, (const std::vector<FamilyCode>& familyCodes), (override));
    MOCK_METHOD(
        void, symbolSamples, (int reqId, const std::vector<ContractDescription>& contractDescriptions), (override));
    MOCK_METHOD(
        void, mktDepthExchanges, (const std::vector<DepthMktDataDescription>& depthMktDataDescriptions), (override));
    MOCK_METHOD(void, tickNews,
        (int tickerId, time_t timeStamp, const std::string& providerCode, const std::string& articleId,
            const std::string& headline, const std::string& extraData),
        (override));
    MOCK_METHOD(void, smartComponents, (int reqId, const SmartComponentsMap& theMap), (override));
    MOCK_METHOD(void, tickReqParams,
        (int tickerId, double minTick, const std::string& bboExchange, int snapshotPermissions), (override));
    MOCK_METHOD(void, newsProviders, (const std::vector<NewsProvider>& newsProviders), (override));
    MOCK_METHOD(void, newsArticle, (int requestId, int articleType, const std::string& articleText), (override));
    MOCK_METHOD(void, historicalNews,
        (int requestId, const std::string& time, const std::string& providerCode, const std::string& articleId,
            const std::string& headline),
        (override));
    MOCK_METHOD(void, historicalNewsEnd, (int requestId, bool hasMore), (override));
    MOCK_METHOD(void, headTimestamp, (int reqId, const std::string& headTimestamp), (override));
    MOCK_METHOD(void, histogramData, (int reqId, const HistogramDataVector& data), (override));
    MOCK_METHOD(void, historicalDataUpdate, (TickerId reqId, const Bar& bar), (override));
    MOCK_METHOD(void, rerouteMktDataReq, (int reqId, int conid, const std::string& exchange), (override));
    MOCK_METHOD(void, rerouteMktDepthReq, (int reqId, int conid, const std::string& exchange), (override));
    MOCK_METHOD(void, marketRule, (int marketRuleId, const std::vector<PriceIncrement>& priceIncrements), (override));
    MOCK_METHOD(void, pnl, (int reqId, double dailyPnL, double unrealizedPnL, double realizedPnL), (override));
    MOCK_METHOD(void, pnlSingle,
        (int reqId, Decimal pos, double dailyPnL, double unrealizedPnL, double realizedPnL, double value), (override));
    MOCK_METHOD(void, historicalTicks, (int reqId, const std::vector<HistoricalTick>& ticks, bool done), (override));
    MOCK_METHOD(void, historicalTicksBidAsk, (int reqId, const std::vector<HistoricalTickBidAsk>& ticks, bool done),
        (override));
    MOCK_METHOD(
        void, historicalTicksLast, (int reqId, const std::vector<HistoricalTickLast>& ticks, bool done), (override));
    MOCK_METHOD(void, tickByTickAllLast,
        (int reqId, int tickType, time_t time, double price, Decimal size, const TickAttribLast& tickAttribLast,
            const std::string& exchange, const std::string& specialConditions),
        (override));
    MOCK_METHOD(void, tickByTickBidAsk,
        (int reqId, time_t time, double bidPrice, double askPrice, Decimal bidSize, Decimal askSize,
            const TickAttribBidAsk& tickAttribBidAsk),
        (override));
    MOCK_METHOD(void, tickByTickMidPoint, (int reqId, time_t time, double midPoint), (override));
    MOCK_METHOD(void, orderBound, (long long orderId, int apiClientId, int apiOrderId), (override));
    MOCK_METHOD(
        void, completedOrder, (const Contract& contract, const Order& order, const OrderState& orderState), (override));
    MOCK_METHOD(void, completedOrdersEnd, (), (override));
    MOCK_METHOD(void, replaceFAEnd, (int reqId, const std::string& text), (override));
    MOCK_METHOD(void, wshMetaData, (int reqId, const std::string& dataJson), (override));
    MOCK_METHOD(void, wshEventData, (int reqId, const std::string& dataJson), (override));
    MOCK_METHOD(void, historicalSchedule,
        (int reqId, const std::string& startDateTime, const std::string& endDateTime, const std::string& timeZone,
            const std::vector<HistoricalSession>& sessions),
        (override));
    MOCK_METHOD(void, userInfo, (int reqId, const std::string& whiteBrandingId), (override));
};