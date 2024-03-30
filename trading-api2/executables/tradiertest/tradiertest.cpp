#include "RestClient.h"
#include "TradierData.h"
#include "TradierStreamHandler.h"

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    auto restclient = std::make_shared<RestClient>("api.tradier.com");
    auto streamhandler = std::make_shared<TradierStreamHandler>("ws.tradier.com/v1/markets/events");

    // eKtYC2m5aMxYIzfzrUGJAOehA8T8 prod
    // BgKunOsplhAVRNvHQnKAy2wdOs3x sandbox
    std::set<std::string> ids{"SPY"};
    auto tradierdata = std::make_shared<TradierData>(ids, "eKtYC2m5aMxYIzfzrUGJAOehA8T8", restclient, streamhandler);
    tradierdata->startMarketStream();
}