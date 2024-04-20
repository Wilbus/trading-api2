#pragma once

#include "SchwabClient.h"
#include "IStrategy.h"

namespace tester
{

using namespace restclient;
using namespace strategy;

class SchwabBackTester
{
public:
    SchwabBackTester(std::string configsFolder, std::string backtesterLogFolder);
    void createClient();
    void setStrategy(std::shared_ptr<IStrategy> strategy);
    void run();
    void getSchwabData(std::string fromTime, std::string toTime, std::string symbol);

private:
    std::shared_ptr<ISchwabClient> client;
    std::shared_ptr<IStrategy> strategy;
    std::string configsFolder;
    std::string backtesterLogFolder;
    std::string logfile;
    PriceHistory priceHistory;
};
} // namespace tester