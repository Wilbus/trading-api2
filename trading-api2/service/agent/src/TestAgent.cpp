#include "TestAgent.h"

TestAgent::TestAgent(std::shared_ptr<ISchwabClient> sClient, std::shared_ptr<IDatabank> databank,
    std::set<std::string> symbols, std::string agentName, std::string logFile)
    : SimpleAgent(sClient, databank, symbols, agentName, logFile)
{
    infologprint(logFile, "%s: init", __func__);
}

void TestAgent::startAgent()
{
    infologprint(logFile, "%s: starting %s", __func__, agentName.c_str());

    for(const auto& symbol : symbols)
    {
        positionsMap[symbol] = false;

        buySignalsQueueMap[symbol].push(lowWentUnder_bbmid50SignalName);
        buySignalsQueueMap[symbol].push(macdHistCrossedOver0SignalName);

        sellSignalsQueueMap[symbol].push(closeCrossedUnderSma9SignalName);
    }

    agentThread = std::thread([this]() {
        while (true)
        {
            for (const auto& symbol : symbols)
            {
                ChartTimeframesMap timeframeCharts;

                this->fillIndicators(symbol, timeframeCharts);

                if (!this->inSpecificPosition(symbol))
                {
                    this->checkEnterTrade(symbol, timeframeCharts);
                }
                else
                {
                    this->checkExitTrade(symbol, timeframeCharts);
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });
    // agentThread.join();
}

bool TestAgent::inSpecificPosition(const std::string& symbol) const
{
    return positionsMap.at(symbol);
}

void TestAgent::checkEnterTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts)
{
#if 0
    if (timeframeCharts.at(Timeframe::MINUTE).getBack(0).getIndByName("3whitesolders").value > 50)
    {
        infologprint(logFile, "%s: %s: 3whitesolders value: %.02f", __func__, symbol.c_str(),
            timeframeCharts.at(Timeframe::MINUTE).getBack(0).getIndByName("3whitesolders").value);
    }
    if (timeframeCharts.at(Timeframe::MINUTE).getBack(0).getIndByName("3blackcrows").value > 50)
    {
        infologprint(logFile, "%s: %s: 3blackcrows value: %.02f", __func__, symbol.c_str(),
            timeframeCharts.at(Timeframe::MINUTE).getBack(0).getIndByName("3blackcrows").value);
    }

    if (timeframeCharts.at(Timeframe::FIVE).getBack(0).getIndByName("3whitesolders").value > 50)
    {
        infologprint(logFile, "%s: %s: 3whitesolders value: %.02f", __func__, symbol.c_str(),
            timeframeCharts.at(Timeframe::FIVE).getBack(0).getIndByName("3whitesolders").value);
    }
    if (timeframeCharts.at(Timeframe::FIVE).getBack(0).getIndByName("3blackcrows").value > 50)
    {
        infologprint(logFile, "%s: %s: 3blackcrows value: %.02f", __func__, symbol.c_str(),
            timeframeCharts.at(Timeframe::FIVE).getBack(0).getIndByName("3blackcrows").value);
    }

    if (timeframeCharts.at(Timeframe::THIRTY).getBack(0).getIndByName("3whitesolders").value > 50)
    {
        infologprint(logFile, "%s: %s: 3whitesolders value: %.02f", __func__, symbol.c_str(),
            timeframeCharts.at(Timeframe::THIRTY).getBack(0).getIndByName("3whitesolders").value);
    }
    if (timeframeCharts.at(Timeframe::THIRTY).getBack(0).getIndByName("3blackcrows").value > 50)
    {
        infologprint(logFile, "%s: %s: 3blackcrows value: %.02f", __func__, symbol.c_str(),
            timeframeCharts.at(Timeframe::THIRTY).getBack(0).getIndByName("3blackcrows").value);
    }

    if (timeframeCharts.at(Timeframe::DAILY).getBack(0).getIndByName("3whitesolders").value > 50)
    {
        infologprint(logFile, "%s: %s: 3whitesolders value: %.02f", __func__, symbol.c_str(),
            timeframeCharts.at(Timeframe::DAILY).getBack(0).getIndByName("3whitesolders").value);
    }
    if (timeframeCharts.at(Timeframe::DAILY).getBack(0).getIndByName("3blackcrows").value > 50)
    {
        infologprint(logFile, "%s: %s: 3blackcrows value: %.02f", __func__, symbol.c_str(),
            timeframeCharts.at(Timeframe::DAILY).getBack(0).getIndByName("3blackcrows").value);
    }
#endif
    if (timeframeCharts.at(Timeframe::FIVE).getBack(0).price_low <=
        timeframeCharts.at(Timeframe::FIVE).getBack(0).getIndByName("bbdown50").value)
    {
        if (buySignalsQueueMap.at(symbol).front() == lowWentUnder_bbmid50SignalName)
        {
            infologprint(logFile, "%s: %s: low went under bbdown50", __func__, symbol.c_str());
            buySignalsQueueMap.at(symbol).pop();
        }
        // infologprint(logFile, "%s: %s: low went under bbdown50", __func__, symbol.c_str());
        // lowWentUnder_bbmid50 = true;
    }

    if (timeframeCharts.at(Timeframe::FIVE).getBack(0).getIndByName("macdhist").value > 0 &&
        timeframeCharts.at(Timeframe::FIVE).getBack(1).getIndByName("macdhist").value < 0)
    {
        if (buySignalsQueueMap.at(symbol).front() == macdHistCrossedOver0SignalName)
        {
            infologprint(logFile, "%s: %s: macdhist crossed over 0", __func__, symbol.c_str());
            auto macdhist = timeframeCharts.at(Timeframe::FIVE).getBack(0).getIndByName("macdhist").value;
            buySignalsQueueMap.at(symbol).pop();
        }
        // infologprint(logFile, "%s: %s: macdhist crossed over 0", __func__, symbol.c_str());
        // macdHistCrossedOver0 = true;
    }

    /*if(lowWentUnder_bbmid50 && macdHistCrossedOver0)
    {
        auto lastMinClose = timeframeCharts.at(Timeframe::MINUTE).getBack(0).price_close;
        infologprint(logFile, "%s: %s: buy", __func__, symbol.c_str());
        infologprint(logFile, "%s: %s: last minute close: %.02f", __func__, symbol.c_str(), lastMinClose);
        inPosition = true;

        //reset buy signals
        lowWentUnder_bbmid50 = false;
        macdHistCrossedOver0 = false;
    }*/
    if (buySignalsQueueMap.at(symbol).empty())
    {
        auto lastMinClose = timeframeCharts.at(Timeframe::MINUTE).getBack(0).price_close;
        infologprint(logFile, "%s: %s: buy signal achieved. Last minute close: %.02f",
            __func__, symbol.c_str(), lastMinClose);
        positionsMap[symbol] = true;
        balance -= lastMinClose;

        // reset buy signals
        buySignalsQueueMap[symbol].push(lowWentUnder_bbmid50SignalName);
        buySignalsQueueMap[symbol].push(macdHistCrossedOver0SignalName);
    }
}

void TestAgent::checkExitTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts)
{
    if (timeframeCharts.at(Timeframe::FIVE).getBack(0).price_close <
        timeframeCharts.at(Timeframe::FIVE).getBack(0).getIndByName("sma5").value)
    {
        if (sellSignalsQueueMap.at(symbol).front() == closeCrossedUnderSma9SignalName)
        {
            infologprint(logFile, "%s: %s: close crossed under sma5", __func__, symbol.c_str());
            sellSignalsQueueMap.at(symbol).pop();
        }
        // infologprint(logFile, "%s: %s: close crossed under sma5", __func__, symbol.c_str());
        // closeCrossedUnderSma9 = true;
    }

    if (sellSignalsQueueMap.at(symbol).empty())
    {
        auto lastMinClose = timeframeCharts.at(Timeframe::MINUTE).getBack(0).price_close;
        infologprint(logFile, "%s: %s sell signal achieved. Last minute close: %.02f",
            __func__, symbol.c_str(), lastMinClose);
        positionsMap[symbol] = false;
        balance += lastMinClose;

        // reset sell signals
        sellSignalsQueueMap.at(symbol).push(closeCrossedUnderSma9SignalName);
    }

    /*if(closeCrossedUnderSma9)
    {
        auto lastMinClose = timeframeCharts.at(Timeframe::MINUTE).getBack(0).price_close;
        infologprint(logFile, "%s: %s: sell", __func__, symbol.c_str());
        infologprint(logFile, "%s: %s: last minute close: %.02f", __func__, symbol.c_str(), lastMinClose);
        inPosition = false;

        //reset sell signals
        closeCrossedUnderSma9 = false;
    }*/
}

void TestAgent::fillIndicators(const std::string& symbol, ChartTimeframesMap& timeframeCharts)
{
    // std::cout << "TestAgent::fillIndicators" << std::endl;
    timeframeCharts = databank->getChart(symbol);
    timeframeCharts.at(Timeframe::MINUTE)
        .addIndicator(IndicatorType{"3whitesolders", IndicatorTypes::THREEWHITESOLDIERS, std::vector<std::string>{}});
    timeframeCharts.at(Timeframe::FIVE)
        .addIndicator(IndicatorType{"3whitesolders", IndicatorTypes::THREEWHITESOLDIERS, std::vector<std::string>{}});
    timeframeCharts.at(Timeframe::THIRTY)
        .addIndicator(IndicatorType{"3whitesolders", IndicatorTypes::THREEWHITESOLDIERS, std::vector<std::string>{}});
    timeframeCharts.at(Timeframe::DAILY)
        .addIndicator(IndicatorType{"3whitesolders", IndicatorTypes::THREEWHITESOLDIERS, std::vector<std::string>{}});

    timeframeCharts.at(Timeframe::MINUTE)
        .addIndicator(IndicatorType{"3blackcrows", IndicatorTypes::THREEBLACKCROWS, std::vector<std::string>{}});
    timeframeCharts.at(Timeframe::FIVE)
        .addIndicator(IndicatorType{"3blackcrows", IndicatorTypes::THREEBLACKCROWS, std::vector<std::string>{}});
    timeframeCharts.at(Timeframe::THIRTY)
        .addIndicator(IndicatorType{"3blackcrows", IndicatorTypes::THREEBLACKCROWS, std::vector<std::string>{}});
    timeframeCharts.at(Timeframe::DAILY)
        .addIndicator(IndicatorType{"3blackcrows", IndicatorTypes::THREEBLACKCROWS, std::vector<std::string>{}});

    timeframeCharts.at(Timeframe::FIVE)
        .addIndicator(IndicatorType{"macdhist", IndicatorTypes::MACDHIST, std::vector<std::string>{"12", "26", "9"}});
    timeframeCharts.at(Timeframe::FIVE)
        .addIndicator(IndicatorType{"bbup50", IndicatorTypes::BBUP, std::vector<std::string>{"50"}});
    timeframeCharts.at(Timeframe::FIVE)
        .addIndicator(IndicatorType{"bbmid50", IndicatorTypes::BBMID, std::vector<std::string>{"50"}});
    timeframeCharts.at(Timeframe::FIVE)
        .addIndicator(IndicatorType{"bbdown50", IndicatorTypes::BBDOWN, std::vector<std::string>{"50"}});
    timeframeCharts.at(Timeframe::FIVE)
        .addIndicator(IndicatorType{"sma5", IndicatorTypes::SMA, std::vector<std::string>{"9"}});
    timeframeCharts.at(Timeframe::FIVE)
        .addIndicator(IndicatorType{"sma50", IndicatorTypes::SMA, std::vector<std::string>{"50"}});
}