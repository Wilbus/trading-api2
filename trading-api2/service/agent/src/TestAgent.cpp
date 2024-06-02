#include "TestAgent.h"

TestAgent::TestAgent(std::shared_ptr<ISchwabClient> sClient, std::shared_ptr<IDatabank> databank,
    std::set<std::string> symbols, std::string logFile)
    : SimpleAgent(sClient, databank, symbols, logFile)
{
}

void TestAgent::checkEnterTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts)
{
}

void TestAgent::checkExitTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts)
{
}

void TestAgent::fillIndicators(const std::string& symbol, ChartTimeframesMap& timeframeCharts)
{
    // std::cout << "TestAgent::fillIndicators" << std::endl;
}