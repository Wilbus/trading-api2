#include "SchwabBackTester.h"
#include "SimpleStrategy.h"
#include <iostream>

using namespace tester;
using namespace strategy;

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    SchwabBackTester tester("/datadisk0/sambashare0/coding/configs/", 
        "/datadisk0/sambashare0/coding/trading-api2-backtester-logs/");
    
    auto strategy = std::make_shared<SimpleStrategy>();
    strategy->setAccountBalance(10000.0);
    
    tester.getSchwabData("2024-01-01", "", "SPY");
    tester.setStrategy(strategy);
    tester.run();
}