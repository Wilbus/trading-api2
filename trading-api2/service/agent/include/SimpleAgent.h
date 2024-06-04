#pragma once

#include "IAgent.h"
#include "IDatabank.h"
#include "Logger.h"
#include "SchwabClient.h"

using namespace databank;

class SimpleAgent : public IAgent
{
public:
    SimpleAgent(std::shared_ptr<ISchwabClient> sClient, std::shared_ptr<IDatabank> databank,
        std::set<std::string> symbols, std::string agentName, std::string logFile = "");
    virtual void startAgent() override;
    virtual void startBackTest() override;
    virtual void waitForAgent() override
    {
        agentThread.join();
    }
    virtual bool InPostion() override
    {
        return inPosition;
    }

    virtual bool inSpecificPosition(const std::string& symbol) const override
    {
        return inPosition;
    }

protected:
    virtual void checkEnterTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts);
    virtual void checkExitTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts);
    virtual void fillIndicators(const std::string& symbol, ChartTimeframesMap& timeframeCharts);

    std::shared_ptr<ISchwabClient> sClient;
    std::shared_ptr<IDatabank> databank;
    std::set<std::string> symbols;
    std::string logFile;
    std::thread agentThread;
    bool inPosition{false};
    std::string agentName;

private:
    bool threeConsecutiveDailyCloseAboveAllSmas{false};
    bool thirtyCloseLessThanOrEqualBBDOWN{false};
    bool minuteClose_under_sma5{false};
    bool fiveClose_under_sma5{false};
    bool fiveClose_above_sma5{false};
};