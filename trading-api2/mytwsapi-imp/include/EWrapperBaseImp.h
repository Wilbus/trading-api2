#pragma once

#include "EWrapper.h"
#include "EWrapperFuncStructs.h"

#include <functional>

class EWrapperBaseImp : public EWrapper
{
public:
    //clang-format off
    void tickPrice(TickerId tickerId, TickType field, double price, const TickAttrib& attrib) override
    {
        (void)tickerId;
        (void)field;
        (void)price;
        (void)attrib;
    }

    void tickSize(TickerId tickerId, TickType field, Decimal size) override
    {
        (void)tickerId;
        (void)field;
        (void)size;
    }

    void tickOptionComputation(TickerId tickerId, TickType tickType, int tickAttrib, double impliedVol, double delta,
        double optPrice, double pvDividend, double gamma, double vega, double theta, double undPrice) override
    {
        (void)tickerId;
        (void)tickType;
        (void)tickAttrib;
        (void)impliedVol;
        (void)delta;
        (void)optPrice;
        (void)pvDividend;
        (void)gamma;
        (void)vega;
        (void)theta;
        (void)undPrice;
    }

    void tickGeneric(TickerId tickerId, TickType tickType, double value) override
    {
        (void)tickerId;
        (void)tickType;
        (void)value;
    }

    void tickString(TickerId tickerId, TickType tickType, const std::string& value) override
    {
        (void)tickerId;
        (void)tickType;
        (void)value;
    }

    void tickEFP(TickerId tickerId, TickType tickType, double basisPoints, const std::string& formattedBasisPoints,
        double totalDividends, int holdDays, const std::string& futureLastTradeDate, double dividendImpact,
        double dividendsToLastTradeDate) override
    {
        (void)tickerId;
        (void)tickType;
        (void)basisPoints;
        (void)formattedBasisPoints;
        (void)totalDividends;
        (void)holdDays;
        (void)futureLastTradeDate;
        (void)dividendImpact;
        (void)dividendsToLastTradeDate;
    }

    void orderStatus(OrderId orderId, const std::string& status, Decimal filled, Decimal remaining, double avgFillPrice,
        int permId, int parentId, double lastFillPrice, int clientId, const std::string& whyHeld,
        double mktCapPrice) override
    {
        (void)orderId;
        (void)status;
        (void)filled;
        (void)remaining;
        (void)avgFillPrice;
        (void)permId;
        (void)parentId;
        (void)lastFillPrice;
        (void)clientId;
        (void)whyHeld;
        (void)mktCapPrice;
    }

    void openOrder(OrderId orderId, const Contract& contract, const Order& order, const OrderState& orderstate) override
    {
        (void)orderId;
        (void)contract;
        (void)order;
        (void)orderstate;
    }

    void openOrderEnd() override{};

    void winError(const std::string& str, int lastError) override
    {
        (void)str;
        (void)lastError;
    }

    void connectionClosed() override{};

    void updateAccountValue(const std::string& key, const std::string& val, const std::string& currency,
        const std::string& accountName) override
    {
        (void)key;
        (void)val;
        (void)currency;
        (void)accountName;
    }

    void updatePortfolio(const Contract& contract, Decimal position, double marketPrice, double marketValue,
        double averageCost, double unrealizedPNL, double realizedPNL, const std::string& accountName) override
    {
        (void)contract;
        (void)position;
        (void)marketPrice;
        (void)marketValue;
        (void)averageCost;
        (void)unrealizedPNL;
        (void)realizedPNL;
        (void)accountName;
    }

    void updateAccountTime(const std::string& timeStamp) override
    {
        (void)timeStamp;
    }

    void accountDownloadEnd(const std::string& accountName) override
    {
        (void)accountName;
    }

    void nextValidId(OrderId orderId) override
    {
        (void)orderId;
    }

    void contractDetails(int reqId, const ContractDetails& contractDetails) override
    {
        (void)reqId;
        (void)contractDetails;
    }

    void bondContractDetails(int reqId, const ContractDetails& contractDetails) override
    {
        (void)reqId;
        (void)contractDetails;
    }

    void contractDetailsEnd(int reqId) override
    {
        (void)reqId;
    }

    void execDetails(int reqId, const Contract& contract, const Execution& execution) override
    {
        (void)reqId;
        (void)contract;
        (void)execution;
    }

    void execDetailsEnd(int reqId) override
    {
        (void)reqId;
    }

    void error(
        int id, int errorCode, const std::string& errorString, const std::string& advancedOrderRejectJson) override;

    void updateMktDepth(TickerId id, int position, int operation, int side, double price, Decimal size) override
    {
        (void)id;
        (void)position;
        (void)operation;
        (void)side;
        (void)price;
        (void)size;
    }

    void updateMktDepthL2(TickerId id, int position, const std::string& marketMaker, int operation, int side,
        double price, Decimal size, bool isSmartDepth) override
    {
        (void)id;
        (void)position;
        (void)marketMaker;
        (void)operation;
        (void)side;
        (void)price;
        (void)size;
        (void)isSmartDepth;
    }

    void updateNewsBulletin(
        int msgId, int msgType, const std::string& newsMessage, const std::string& originExch) override
    {
        (void)msgId;
        (void)msgType;
        (void)newsMessage;
        (void)originExch;
    }

    void managedAccounts(const std::string& accountsList) override
    {
        (void)accountsList;
    }

    void receiveFA(faDataType pFaDataType, const std::string& cxml) override
    {
        (void)pFaDataType;
        (void)cxml;
    }

    void historicalData(TickerId reqId, const Bar& bar) override;

    void historicalDataEnd(int reqId, const std::string& startDateStr, const std::string& endDateStr) override;

    void scannerParameters(const std::string& xml) override
    {
        (void)xml;
    }

    void scannerData(int reqId, int rank, const ContractDetails& contractDetails, const std::string& distance,
        const std::string& benchmark, const std::string& projection, const std::string& legsStr) override
    {
        (void)reqId;
        (void)rank;
        (void)contractDetails;
        (void)distance;
        (void)benchmark;
        (void)projection;
        (void)legsStr;
    }

    void scannerDataEnd(int reqId) override
    {
        (void)reqId;
    }

    void realtimeBar(TickerId reqId, long time, double open, double high, double low, double close, Decimal volume,
        Decimal wap, int count) override;

    void currentTime(long time) override
    {
        (void)time;
    }

    void fundamentalData(TickerId reqId, const std::string& data) override
    {
        (void)reqId;
        (void)data;
    }

    void deltaNeutralValidation(int reqId, const DeltaNeutralContract& deltaNeutralContract) override
    {
        (void)reqId;
        (void)deltaNeutralContract;
    }

    void tickSnapshotEnd(int reqId) override
    {
        (void)reqId;
    }

    void marketDataType(TickerId reqId, int marketDataType) override
    {
        (void)reqId;
        (void)marketDataType;
    }

    void commissionReport(const CommissionReport& commissionReport) override
    {
        (void)commissionReport;
    }

    void position(const std::string& account, const Contract& contract, Decimal position, double avgCost) override
    {
        (void)account;
        (void)contract;
        (void)position;
        (void)avgCost;
    }

    void positionEnd() override{};

    void accountSummary(int reqId, const std::string& account, const std::string& tag, const std::string& value,
        const std::string& curency) override
    {
        (void)reqId;
        (void)account;
        (void)tag;
        (void)value;
        (void)curency;
    }

    void accountSummaryEnd(int reqId) override
    {
        (void)reqId;
    }

    void verifyMessageAPI(const std::string& apiData) override
    {
        (void)apiData;
    }

    void verifyCompleted(bool isSuccessful, const std::string& errorText) override
    {
        (void)isSuccessful;
        (void)errorText;
    }

    void displayGroupList(int reqId, const std::string& groups) override
    {
        (void)reqId;
        (void)groups;
    }

    void displayGroupUpdated(int reqId, const std::string& contractInfo) override
    {
        (void)reqId;
        (void)contractInfo;
    }

    void verifyAndAuthMessageAPI(const std::string& apiData, const std::string& xyzChallange) override
    {
        (void)apiData;
        (void)xyzChallange;
    }

    void verifyAndAuthCompleted(bool isSuccessful, const std::string& errorText) override
    {
        (void)isSuccessful;
        (void)errorText;
    }

    void connectAck() override{};

    void positionMulti(int reqId, const std::string& account, const std::string& modelCode, const Contract& contract,
        Decimal pos, double avgCost) override
    {
        (void)reqId;
        (void)account;
        (void)modelCode;
        (void)contract;
        (void)pos;
        (void)avgCost;
    }

    void positionMultiEnd(int reqId) override
    {
        (void)reqId;
    }

    void accountUpdateMulti(int reqId, const std::string& account, const std::string& modelCode, const std::string& key,
        const std::string& value, const std::string& currency) override
    {
        (void)reqId;
        (void)account;
        (void)modelCode;
        (void)key;
        (void)value;
        (void)currency;
    }

    void accountUpdateMultiEnd(int reqId) override
    {
        (void)reqId;
    }

    void securityDefinitionOptionalParameter(int reqId, const std::string& exchange, int underlyingConId,
        const std::string& tradingClass, const std::string& multiplier, const std::set<std::string>& expirations,
        const std::set<double>& strikes) override
    {
        (void)reqId;
        (void)exchange;
        (void)underlyingConId;
        (void)tradingClass;
        (void)multiplier;
        (void)expirations;
        (void)strikes;
    }

    void securityDefinitionOptionalParameterEnd(int reqId) override
    {
        (void)reqId;
    }

    void softDollarTiers(int reqId, const std::vector<SoftDollarTier>& tiers) override
    {
        (void)reqId;
        (void)tiers;
    }

    void familyCodes(const std::vector<FamilyCode>& familyCodes) override
    {
        (void)familyCodes;
    }

    void symbolSamples(int reqId, const std::vector<ContractDescription>& contractDescriptions) override
    {
        (void)reqId;
        (void)contractDescriptions;
    }

    void mktDepthExchanges(const std::vector<DepthMktDataDescription>& depthMktDataDescriptions) override
    {
        (void)depthMktDataDescriptions;
    }

    void tickNews(int tickerId, time_t timeStamp, const std::string& providerCode, const std::string& articleId,
        const std::string& headline, const std::string& extraData) override
    {
        (void)tickerId;
        (void)timeStamp;
        (void)providerCode;
        (void)articleId;
        (void)headline;
        (void)extraData;
    }

    void smartComponents(int reqId, const SmartComponentsMap& theMap) override
    {
        (void)reqId;
        (void)theMap;
    }

    void tickReqParams(int tickerId, double minTick, const std::string& bboExchange, int snapshotPermissions) override
    {
        (void)tickerId;
        (void)minTick;
        (void)bboExchange;
        (void)snapshotPermissions;
    }

    void newsProviders(const std::vector<NewsProvider>& newsProviders) override
    {
        (void)newsProviders;
    }

    void newsArticle(int requestId, int articleType, const std::string& articleText) override
    {
        (void)requestId;
        (void)articleType;
        (void)articleText;
    }

    void historicalNews(int requestId, const std::string& time, const std::string& providerCode,
        const std::string& articleId, const std::string& headline) override
    {
        (void)requestId;
        (void)time;
        (void)providerCode;
        (void)articleId;
        (void)headline;
    }

    void historicalNewsEnd(int requestId, bool hasMore) override
    {
        (void)requestId;
        (void)hasMore;
    }

    void headTimestamp(int reqId, const std::string& headTimestamp) override
    {
        (void)reqId;
        (void)headTimestamp;
    }

    void histogramData(int reqId, const HistogramDataVector& data) override
    {
        (void)reqId;
        (void)data;
    }

    void historicalDataUpdate(TickerId reqId, const Bar& bar) override;

    void rerouteMktDataReq(int reqId, int conid, const std::string& exchange) override
    {
        (void)reqId;
        (void)conid;
        (void)exchange;
    }

    void rerouteMktDepthReq(int reqId, int conid, const std::string& exchange) override
    {
        (void)reqId;
        (void)conid;
        (void)exchange;
    }

    void marketRule(int marketRuleId, const std::vector<PriceIncrement>& priceIncrements) override
    {
        (void)marketRuleId;
        (void)priceIncrements;
    }

    void pnl(int reqId, double dailyPnL, double unrealizedPnL, double realizedPnL) override
    {
        (void)reqId;
        (void)dailyPnL;
        (void)unrealizedPnL;
        (void)realizedPnL;
    }

    void pnlSingle(
        int reqId, Decimal pos, double dailyPnL, double unrealizedPnL, double realizedPnL, double value) override
    {
        (void)reqId;
        (void)pos;
        (void)dailyPnL;
        (void)unrealizedPnL;
        (void)realizedPnL;
        (void)value;
    }

    void historicalTicks(int reqId, const std::vector<HistoricalTick>& ticks, bool done) override
    {
        (void)reqId;
        (void)ticks;
        (void)done;
    }

    void historicalTicksBidAsk(int reqId, const std::vector<HistoricalTickBidAsk>& ticks, bool done) override
    {
        (void)reqId;
        (void)ticks;
        (void)done;
    }

    void historicalTicksLast(int reqId, const std::vector<HistoricalTickLast>& ticks, bool done) override
    {
        (void)reqId;
        (void)ticks;
        (void)done;
    }

    void tickByTickAllLast(int reqId, int tickType, time_t time, double price, Decimal size,
        const TickAttribLast& tickAttribLast, const std::string& exchange,
        const std::string& specialConditions) override
    {
        (void)reqId;
        (void)tickType;
        (void)time;
        (void)price;
        (void)size;
        (void)tickAttribLast;
        (void)exchange;
        (void)specialConditions;
    }

    void tickByTickBidAsk(int reqId, time_t time, double bidPrice, double askPrice, Decimal bidSize, Decimal askSize,
        const TickAttribBidAsk& tickAttribBidAsk) override
    {
        (void)reqId;
        (void)time;
        (void)bidPrice;
        (void)askPrice;
        (void)bidSize;
        (void)askSize;
        (void)tickAttribBidAsk;
    }

    void tickByTickMidPoint(int reqId, time_t time, double midPoint) override
    {
        (void)reqId;
        (void)time;
        (void)midPoint;
    }

    void orderBound(long long orderId, int apiClientId, int apiOrderId) override
    {
        (void)orderId;
        (void)apiClientId;
        (void)apiOrderId;
    }

    void completedOrder(const Contract& contract, const Order& order, const OrderState& orderState) override
    {
        (void)contract;
        (void)order;
        (void)orderState;
    }

    void completedOrdersEnd() override{};

    void replaceFAEnd(int reqId, const std::string& text) override
    {
        (void)reqId;
        (void)text;
    }

    void wshMetaData(int reqId, const std::string& dataJson) override
    {
        (void)reqId;
        (void)dataJson;
    }

    void wshEventData(int reqId, const std::string& dataJson) override
    {
        (void)reqId;
        (void)dataJson;
    }

    void historicalSchedule(int reqId, const std::string& startDateTime, const std::string& endDateTime,
        const std::string& timeZone, const std::vector<HistoricalSession>& sessions) override
    {
        (void)reqId;
        (void)startDateTime;
        (void)endDateTime;
        (void)timeZone;
        (void)sessions;
    }

    void userInfo(int reqId, const std::string& whiteBrandingId) override
    {
        (void)reqId;
        (void)whiteBrandingId;
    }
    //clang-format on

    std::function<void(RealTimeBar)> realtimeBarFunc;
    std::function<void(TickerId, Bar)> historicalDataFunc;
    std::function<void(int, std::string&, std::string&)> historicalDataEndFunc;
    std::function<void(TickerId, Bar)> historicalDataUpdateFunc;
};