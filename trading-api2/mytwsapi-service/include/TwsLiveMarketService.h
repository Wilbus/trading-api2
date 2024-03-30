#pragma once

#include "EWrapperBaseImp.h"
#include "LiveMarketHandler.h"
#include "TwsClientWrapper.h"

class TwsLiveMarketService
{
public:
    TwsLiveMarketService();
    void setupHandlers();
    void setupStreams();

private:
    EWrapperBaseImp* ewrapper;
    std::shared_ptr<TwsClientWrapper> client;
    std::shared_ptr<LiveMarketHandler> liveMarketDataHandler;
};