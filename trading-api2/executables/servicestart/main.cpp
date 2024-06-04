#include "TradingService.h"

using namespace tradingservice;

//./trading-service-start <config-folder> <mode> <logfile>
int main(int argc, char** argv)
{
    if(argc != 4)
    {
        std::cout << "Usage: ./trading-service-start <config-folder> <mode> <logfile>" << std::endl;
        return 1;
    }

    std::string configFolderPath = argv[1];
    TradingServiceMode mode = tradingServiceModeMap.at(argv[2]);
    std::string logFile = argv[3];

    std::unique_ptr<TradingService> service =
        std::make_unique<TradingService>(configFolderPath, mode, logFile);
    service->setup();
    service->start();
}