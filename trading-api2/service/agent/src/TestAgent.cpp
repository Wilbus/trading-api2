#include "TestAgent.h"

TestAgent::TestAgent(std::shared_ptr<ISchwabClient> sClient, std::shared_ptr<IDatabank> databank,
    std::set<std::string> symbols, std::string logFile)
    : SimpleAgent(sClient, databank, symbols, logFile)
{
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
}

void TestAgent::checkExitTrade(const std::string& symbol, const ChartTimeframesMap& timeframeCharts)
{
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
}