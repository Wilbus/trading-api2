#include "TestAgent.h"

TestAgent::TestAgent(std::shared_ptr<ISchwabClient> sClient, std::shared_ptr<IDatabank> databank,
    std::set<std::string> symbols, std::string agentName, std::string logFile)
    : SimpleAgent(sClient, databank, symbols, agentName, logFile)
{
    infologprint(logFile, "%s: init", __func__);

    buySignalsQueue = std::queue<std::string>();
    buySignalsQueue.push(lowWentUnder_bbmid50SignalName);
    buySignalsQueue.push(macdHistCrossedOver0SignalName);

    sellSignalsQueue = std::queue<std::string>();
    sellSignalsQueue.push(closeCrossedUnderSma9SignalName);
}

void TestAgent::checkEnterTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts)
{
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

    if (timeframeCharts.at(Timeframe::FIVE).getBack(0).price_low <=
        timeframeCharts.at(Timeframe::FIVE).getBack(0).getIndByName("bbdown50").value)
    {
        if (buySignalsQueue.front() == lowWentUnder_bbmid50SignalName)
        {
            infologprint(logFile, "%s: %s: low went under bbdown50", __func__, symbol.c_str());
            buySignalsQueue.pop();
        }
        // infologprint(logFile, "%s: %s: low went under bbdown50", __func__, symbol.c_str());
        // lowWentUnder_bbmid50 = true;
    }

    if (timeframeCharts.at(Timeframe::FIVE).getBack(0).getIndByName("macdhist").value > 0 &&
        timeframeCharts.at(Timeframe::FIVE).getBack(1).getIndByName("macdhist").value < 0)
    {
        if (buySignalsQueue.front() == macdHistCrossedOver0SignalName)
        {
            infologprint(logFile, "%s: %s: macdhist crossed over 0", __func__, symbol.c_str());
            buySignalsQueue.pop();
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
    if (buySignalsQueue.empty())
    {
        auto lastMinClose = timeframeCharts.at(Timeframe::MINUTE).getBack(0).price_close;
        infologprint(logFile, "%s: received all signals in order to buy", __func__);
        infologprint(logFile, "%s: %s: buy", __func__, symbol.c_str());
        infologprint(logFile, "%s: %s: last minute close: %.02f", __func__, symbol.c_str(), lastMinClose);
        inPosition = true;

        // reset buy signals
        buySignalsQueue.push(lowWentUnder_bbmid50SignalName);
        buySignalsQueue.push(macdHistCrossedOver0SignalName);
    }
}

void TestAgent::checkExitTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts)
{
    if (timeframeCharts.at(Timeframe::FIVE).getBack(0).price_close <
        timeframeCharts.at(Timeframe::FIVE).getBack(0).getIndByName("sma5").value)
    {
        if (sellSignalsQueue.front() == closeCrossedUnderSma9SignalName)
        {
            infologprint(logFile, "%s: %s: close crossed under sma5", __func__, symbol.c_str());
            sellSignalsQueue.pop();
        }
        // infologprint(logFile, "%s: %s: close crossed under sma5", __func__, symbol.c_str());
        // closeCrossedUnderSma9 = true;
    }

    if (sellSignalsQueue.empty())
    {
        auto lastMinClose = timeframeCharts.at(Timeframe::MINUTE).getBack(0).price_close;
        infologprint(logFile, "%s: received all signals in order to sell", __func__);
        infologprint(logFile, "%s: %s: sell", __func__, symbol.c_str());
        infologprint(logFile, "%s: %s: last minute close: %.02f", __func__, symbol.c_str(), lastMinClose);
        inPosition = false;

        // reset sell signals
        sellSignalsQueue.push(closeCrossedUnderSma9SignalName);
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