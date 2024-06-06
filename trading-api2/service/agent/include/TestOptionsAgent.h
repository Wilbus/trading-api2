#include "SimpleAgent.h"

class TestOptionsAgent : public SimpleAgent
{
public:
    TestOptionsAgent(std::shared_ptr<ISchwabClient> sClient, std::shared_ptr<IDatabank> databank,
        std::set<std::string> symbols, std::string agentName, std::string logFile = "");

    virtual void startAgent() override;
    virtual bool inSpecificPosition(const std::string& symbol) const override;

protected:
    void checkEnterTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts) override;
    void checkExitTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts) override;
    void fillIndicators(const std::string& symbol, ChartTimeframesMap& timeframeCharts) override;

private:
    void threadFunc();
    void isAgentPositionIntialized();

    OptionContract longPut;
    OptionContract shortPut;
};