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
        std::set<std::string> symbols, std::string logFile = "");
    virtual void startAgent() override;
    virtual void waitForAgent() override
    {
        agentThread.join();
    }
    virtual bool InPostion() override
    {
        return inPosition;
    }

private:
    void checkEnterTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts);
    void checkExitTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts);

    std::shared_ptr<ISchwabClient> sClient;
    std::shared_ptr<IDatabank> databank;
    std::set<std::string> symbols;
    std::string logFile;
    std::thread agentThread;

    bool inPosition{false};

    bool threeConsecutiveDailyCloseAboveAllSmas{false};
    bool thirtyCloseLessThanOrEqualBBDOWN{false};
    bool minuteClose_under_sma5{false};
    bool fiveClose_under_sma5{false};
    bool fiveClose_above_sma5{false};
};