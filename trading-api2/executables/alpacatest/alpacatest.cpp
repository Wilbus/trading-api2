#include "AlpacaClient.h"
#include "AlpacaStreamHandler.h"
#include "RestClient.h"

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    auto restclient = std::make_shared<RestClient>("api.tradier.com");
    std::string url = "stream.data.alpaca.markets/v2/iex";
    std::string apikey = "AKAHR3N818LOWBATOT6Q";
    std::string apisecret = "VlLbb6D5V7ebuFKWxu1g3ciU0XC0ta4y2TVBv8O9";
    auto streamhandler = std::make_shared<AlpacaStreamHandler>(url, apikey, apisecret);

    std::set<std::string> ids{"SPY"};
    auto alpacaclient = std::make_shared<AlpacaClient>(restclient, streamhandler);
    alpacaclient->startMarketStream();
}