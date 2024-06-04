#pragma once

#include "Logger.h"
#include "SchwabClient.h"
#include "SimpleAgent.h"

#include <queue>

class TestAgent : public SimpleAgent
{
public:
    TestAgent(std::shared_ptr<ISchwabClient> sClient, std::shared_ptr<IDatabank> databank,
        std::set<std::string> symbols, std::string agentName, std::string logFile = "");

    virtual void startAgent() override;
    virtual bool inSpecificPosition(const std::string& symbol) const override;

protected:
    void checkEnterTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts) override;
    void checkExitTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts) override;
    void fillIndicators(const std::string& symbol, ChartTimeframesMap& timeframeCharts) override;

private:
    std::map<std::string, std::queue<std::string>> buySignalsQueueMap;
    std::map<std::string, std::queue<std::string>> sellSignalsQueueMap;
    std::string lowWentUnder_bbmid50SignalName{"lowWentUnder_bbmid50"};
    std::string macdHistCrossedOver0SignalName{"macdHistCrossedOver0"};
    std::string macdHistCrossedUnder0SignalName{"macdHistCrossedUnder0"};
    std::string closeCrossedUnderSma9SignalName{"closeCrossedUnderSma9"};

    std::map<std::string, bool> positionsMap;

    bool lowWentUnder_bbmid50{false};
    bool macdHistCrossedOver0{false};
    bool macdHistCrossedUnder0{false};
    bool closeCrossedUnderSma9{false};
};