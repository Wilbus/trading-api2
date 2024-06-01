#include "TradingService.h"

using namespace tradingservice;

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    std::unique_ptr<TradingService> service =
        std::make_unique<TradingService>("/home/wilbus/smbshare0/sambashare0/coding/configs/",
            "/home/wilbus/smbshare0/sambashare0/coding/trading-api2-logs/trading-service.log");
    service->start();
}