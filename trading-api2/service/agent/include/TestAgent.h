#pragma once

#include "Logger.h"
#include "SchwabClient.h"
#include "SimpleAgent.h"

class TestAgent : public SimpleAgent
{
public:
    TestAgent(std::shared_ptr<ISchwabClient> sClient, std::shared_ptr<IDatabank> databank,
        std::set<std::string> symbols, std::string agentName, std::string logFile = "");

protected:
    void checkEnterTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts) override;
    void checkExitTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts) override;
    void fillIndicators(const std::string& symbol, ChartTimeframesMap& timeframeCharts) override;

private:
};