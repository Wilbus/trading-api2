#include "TwsLiveMarketService.h"

TwsLiveMarketService::TwsLiveMarketService()
    : ewrapper(new EWrapperBaseImp)
    , client(std::make_shared<TwsClientWrapper>("127.0.0.1", 7497, 0, ewrapper))
    , liveMarketDataHandler(std::make_shared<LiveMarketHandler>())
{
    client->connect();
    client->startMsgProcessing();
}

void TwsLiveMarketService::setupHandlers()
{
    using namespace std::placeholders;
    ewrapper->realtimeBarFunc = std::bind(&LiveMarketHandler::handleRealTimeBar, liveMarketDataHandler.get(), _1);
    ewrapper->historicalDataFunc =
        std::bind(&LiveMarketHandler::handleHistoricalData, liveMarketDataHandler.get(), _1, _2);
    ewrapper->historicalDataEndFunc =
        std::bind(&LiveMarketHandler::handleHistoricalDataEnd, liveMarketDataHandler.get(), _1, _2, _3);
    ewrapper->historicalDataUpdateFunc =
        std::bind(&LiveMarketHandler::handleHistoricalDataUpdate, liveMarketDataHandler.get(), _1, _2);
}

void TwsLiveMarketService::setupStreams()
{
    int reqIdCounter = 10;
    Contract c;
    c.symbol = "SPY";
    c.secType = "STK";
    c.exchange = "SMART";
    c.currency = "USD";

    liveMarketDataHandler->addSymbol(reqIdCounter, c.symbol);
    client->reqRealTimeBars(reqIdCounter, c, "TRADES", true);
}