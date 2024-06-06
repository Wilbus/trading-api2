#include "TestOptionsAgent.h"

TestOptionsAgent::TestOptionsAgent(std::shared_ptr<ISchwabClient> sClient, std::shared_ptr<IDatabank> databank,
    std::set<std::string> symbols, std::string agentName, std::string logFile)
    : SimpleAgent(sClient, databank, symbols, agentName, logFile)
{
}

void TestOptionsAgent::startAgent()
{
    infologprint(logFile, "%s: starting %s", __func__, agentName.c_str());

    // check if we are in a position, if we are,
    // then start the thread to monitor the position
    // else, short weekly put, buy long put 120 days out

    agentThread = std::thread(&TestOptionsAgent::threadFunc, this);
}

void TestOptionsAgent::threadFunc()
{
    while (true)
    {
    }
}

void TestOptionsAgent::isAgentPositionIntialized()
{
    // here we assume this agent only trades one symbol at a time
}

bool TestOptionsAgent::inSpecificPosition(const std::string& symbol) const
{
    return positionsMap.at(symbol);
}

void TestOptionsAgent::checkEnterTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts)
{
}

void TestOptionsAgent::checkExitTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts)
{
}

void TestOptionsAgent::fillIndicators(const std::string& symbol, ChartTimeframesMap& timeframeCharts)
{
}