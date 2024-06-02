#include "SimpleAgent.h"

SimpleAgent::SimpleAgent(std::shared_ptr<ISchwabClient> sClient, std::shared_ptr<IDatabank> databank,
    std::set<std::string> symbols, std::string agentName, std::string logFile)
    : sClient(sClient)
    , databank(databank)
    , symbols(symbols)
    , logFile(logFile)
    , agentName(agentName)
{
    infologprint(logFile, "%s: init", __func__);
}

void SimpleAgent::startAgent()
{
    infologprint(logFile, "%s: starting %s", __func__, agentName.c_str());
    agentThread = std::thread([this]() {
        while (true)
        {
            for (const auto& symbol : symbols)
            {
                ChartTimeframesMap timeframeCharts;

                this->fillIndicators(symbol, timeframeCharts);

                if (!this->InPostion())
                    this->checkEnterTrade(symbol, timeframeCharts);
                else
                    this->checkExitTrade(symbol, timeframeCharts);
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });
    // agentThread.join();
}

void SimpleAgent::fillIndicators(const std::string& symbol, ChartTimeframesMap& timeframeCharts)
{
    // std::cout << "SimpleAgent::fillIndicators" << std::endl;
    timeframeCharts = databank->getChart(symbol);
    timeframeCharts.at(Timeframe::MINUTE)
        .addIndicator(IndicatorType{"sma5", IndicatorTypes::SMA, std::vector<std::string>{"9"}});
    timeframeCharts.at(Timeframe::MINUTE)
        .addIndicator(IndicatorType{"sma50", IndicatorTypes::SMA, std::vector<std::string>{"50"}});
    timeframeCharts.at(Timeframe::MINUTE)
        .addIndicator(IndicatorType{"bbup21", IndicatorTypes::BBUP, std::vector<std::string>{"21"}});
    timeframeCharts.at(Timeframe::MINUTE)
        .addIndicator(IndicatorType{"bbmid21", IndicatorTypes::BBMID, std::vector<std::string>{"21"}});
    timeframeCharts.at(Timeframe::MINUTE)
        .addIndicator(IndicatorType{"bbdown21", IndicatorTypes::BBDOWN, std::vector<std::string>{"21"}});

    timeframeCharts.at(Timeframe::FIVE)
        .addIndicator(IndicatorType{"sma5", IndicatorTypes::SMA, std::vector<std::string>{"9"}});
    timeframeCharts.at(Timeframe::FIVE)
        .addIndicator(IndicatorType{"sma50", IndicatorTypes::SMA, std::vector<std::string>{"50"}});
    timeframeCharts.at(Timeframe::FIVE)
        .addIndicator(IndicatorType{"bbup21", IndicatorTypes::BBUP, std::vector<std::string>{"21"}});
    timeframeCharts.at(Timeframe::FIVE)
        .addIndicator(IndicatorType{"bbmid21", IndicatorTypes::BBMID, std::vector<std::string>{"21"}});
    timeframeCharts.at(Timeframe::FIVE)
        .addIndicator(IndicatorType{"bbdown21", IndicatorTypes::BBDOWN, std::vector<std::string>{"21"}});

    timeframeCharts.at(Timeframe::THIRTY)
        .addIndicator(IndicatorType{"sma5", IndicatorTypes::SMA, std::vector<std::string>{"9"}});
    timeframeCharts.at(Timeframe::THIRTY)
        .addIndicator(IndicatorType{"sma50", IndicatorTypes::SMA, std::vector<std::string>{"50"}});
    timeframeCharts.at(Timeframe::THIRTY)
        .addIndicator(IndicatorType{"bbup21", IndicatorTypes::BBUP, std::vector<std::string>{"21"}});
    timeframeCharts.at(Timeframe::THIRTY)
        .addIndicator(IndicatorType{"bbmid21", IndicatorTypes::BBMID, std::vector<std::string>{"21"}});
    timeframeCharts.at(Timeframe::THIRTY)
        .addIndicator(IndicatorType{"bbdown21", IndicatorTypes::BBDOWN, std::vector<std::string>{"21"}});

    timeframeCharts.at(Timeframe::DAILY)
        .addIndicator(IndicatorType{"sma5", IndicatorTypes::SMA, std::vector<std::string>{"9"}});
    timeframeCharts.at(Timeframe::DAILY)
        .addIndicator(IndicatorType{"sma50", IndicatorTypes::SMA, std::vector<std::string>{"50"}});
    timeframeCharts.at(Timeframe::DAILY)
        .addIndicator(IndicatorType{"bbup21", IndicatorTypes::BBUP, std::vector<std::string>{"21"}});
    timeframeCharts.at(Timeframe::DAILY)
        .addIndicator(IndicatorType{"bbmid21", IndicatorTypes::BBMID, std::vector<std::string>{"21"}});
    timeframeCharts.at(Timeframe::DAILY)
        .addIndicator(IndicatorType{"bbdown21", IndicatorTypes::BBDOWN, std::vector<std::string>{"21"}});
}

void SimpleAgent::checkEnterTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts)
{
    // std::cout << "test0\n";
    auto dailyChart = timeframeCharts.at(Timeframe::DAILY);
    auto thirtyChart = timeframeCharts.at(Timeframe::THIRTY);
    auto fiveChart = timeframeCharts.at(Timeframe::FIVE);
    auto minuteChart = timeframeCharts.at(Timeframe::MINUTE);

    int smaAboveCounts = 0;
    for (int i = 0; i < 2; i++)
    {
        if (dailyChart.getBack(i).price_close > dailyChart.getBack(i).getIndByName("sma5").value &&
            dailyChart.getBack(i).getIndByName("sma5").value > dailyChart.getBack(i).getIndByName("bbmid21").value &&
            dailyChart.getBack(i).getIndByName("bbmid21").value > dailyChart.getBack(i).getIndByName("sma50").value)
        {
            smaAboveCounts++;
        }
    }
    if (smaAboveCounts == 2)
    {
        threeConsecutiveDailyCloseAboveAllSmas = true;
    }

    if (thirtyChart.getBack(0).price_close <= thirtyChart.getBack(0).getIndByName("bbdown21").value)
    {
        thirtyCloseLessThanOrEqualBBDOWN = true;
    }

    if (fiveChart.getBack(0).price_close > fiveChart.getBack(0).getIndByName("sma5").value)
    {
        fiveClose_above_sma5 = true;
    }

    if (threeConsecutiveDailyCloseAboveAllSmas && thirtyCloseLessThanOrEqualBBDOWN && fiveClose_above_sma5)
    {
        // buy here
        infologprint(logFile, "%s: buy %s", __func__, symbol.c_str());
        inPosition = true;
    }
}

void SimpleAgent::checkExitTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts)
{
    // std::cout << "test0\n";
    auto dailyChart = timeframeCharts.at(Timeframe::DAILY);
    auto thirtyChart = timeframeCharts.at(Timeframe::THIRTY);
    auto fiveChart = timeframeCharts.at(Timeframe::FIVE);
    auto minuteChart = timeframeCharts.at(Timeframe::MINUTE);

    if (fiveChart.getBack(0).price_close < fiveChart.getBack(0).getIndByName("sma5").value)
    {
        fiveClose_under_sma5 = true;
    }

    if (fiveClose_under_sma5)
    {
        // sell here
        infologprint(logFile, "%s: sell %s", __func__, symbol.c_str());
        inPosition = false;
    }
}