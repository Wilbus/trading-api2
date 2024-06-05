#include "RestClientCurl.h"
#include "SchwabClient.h"
#include "SchwabDatabank.h"
#include "SchwabDatabaseHandler.h"
#include "SystemTimer.h"
#include "timefuncs.h"

#include <gtest/gtest.h>

using namespace databank;
using namespace restclient;
using namespace timefuncs;
using namespace utils;

class SchwabDatabankRealDataTest : public ::testing::Test
{
public:
    SchwabDatabankRealDataTest()
    {
        configs = std::make_shared<SchwabConfigs>(configsPath);

        sClient = std::make_shared<SchwabClient>(configs, std::make_shared<RestClientCurl>());

        streamqueue = std::make_shared<DataQueue<std::string>>();

        auto influxConf = configs->getInfluxConnectionConfig();
        influxConnectionInfo = InfluxConnectionInfo{
            influxConf.user, influxConf.pass, influxConf.host, influxConf.dbname, influxConf.authToken};
        schwabDatabaseHandler = std::make_shared<SchwabDatabaseHandler>(influxConnectionInfo);

        databank = std::make_shared<SchwabDatabank>(sClient, schwabDatabaseHandler, streamqueue);
    }

    void SetUp() override
    {
    }

    void applyIndicators(ChartTimeframesMap& timeframeCharts)
    {
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

        std::cout << timeframeCharts.at(Timeframe::MINUTE).getBack(0).getIndByName("sma5").value << std::endl;
    }

protected:
    std::string configsPath{"/home/wilbus/smbshare0/sambashare0/coding/configs/"};
    InfluxConnectionInfo influxConnectionInfo;
    std::shared_ptr<SchwabConfigs> configs;
    std::shared_ptr<SchwabDatabank> databank;
    std::shared_ptr<ISchwabClient> sClient;
    std::shared_ptr<SchwabDatabaseHandler> schwabDatabaseHandler;
    std::shared_ptr<DataQueue<std::string>> streamqueue;
};

TEST_F(SchwabDatabankRealDataTest, getCandlesFromClientTestAndApplyIndicators)
{
    time_t currS = nowMs() / 1000;
    std::string currTimeStr = unixTimeToString(currS, "%Y-%m-%d");

    time_t oneYearAgoMs = currS - 31536000; // 1000 * 60 * 60 * 24 * 365
    std::string oneYearAgoStr = unixTimeToString(oneYearAgoMs, "%Y-%m-%d");

    time_t oneMonthAgoMs = currS - 2592000; // 1000 * 60 * 60 * 24 * 30
    std::string oneMonthAgoStr = unixTimeToString(oneMonthAgoMs, "%Y-%m-%d");

    time_t oneWeekAgoMs = currS - 604800; // 1000 * 60 * 60 * 24 * 7
    std::string oneWeekAgoStr = unixTimeToString(oneWeekAgoMs, "%Y-%m-%d");

    std::set<std::string> symbols{"AAPL", "GOOGL", "MSFT", "SPY"};
    // databank->getCandlesFromClient("AAPL", Timeframe::DAILY, oneYearAgoStr, currTimeStr);
    // databank->getCandlesFromClient("AAPL", Timeframe::THIRTY, oneMonthAgoStr, currTimeStr);
    databank->initializeData(symbols);

    for (const auto& symbol : symbols)
    {
        auto chart = databank->getChart(symbol);
        time_t frontTimestamp = chart[Timeframe::DAILY].getMultiCandles().front().timestamp / 1000;
        time_t backTimestamp = chart[Timeframe::DAILY].getMultiCandles().back().timestamp / 1000;
        std::printf("symbol: %s, year daily chart size: %lu, first timestamp: %s, last timestamp: %s\n", symbol.c_str(),
            chart[Timeframe::DAILY].getMultiCandles().size(),
            unixTimeToString(frontTimestamp, "%Y-%m-%d %H:%M:%S").c_str(),
            unixTimeToString(backTimestamp, "%Y-%m-%d %H:%M:%S").c_str());

        frontTimestamp = chart[Timeframe::THIRTY].getMultiCandles().front().timestamp / 1000;
        backTimestamp = chart[Timeframe::THIRTY].getMultiCandles().back().timestamp / 1000;
        std::printf("symbol: %s, thirty chart size: %lu, first timestamp: %s, last timestamp: %s\n", symbol.c_str(),
            chart[Timeframe::THIRTY].getMultiCandles().size(),
            unixTimeToString(frontTimestamp, "%Y-%m-%d %H:%M:%S").c_str(),
            unixTimeToString(backTimestamp, "%Y-%m-%d %H:%M:%S").c_str());

        frontTimestamp = chart[Timeframe::FIVE].getMultiCandles().front().timestamp / 1000;
        backTimestamp = chart[Timeframe::FIVE].getMultiCandles().back().timestamp / 1000;
        std::printf("symbol: %s, five chart size: %lu, first timestamp: %s, last timestamp: %s\n", symbol.c_str(),
            chart[Timeframe::FIVE].getMultiCandles().size(),
            unixTimeToString(frontTimestamp, "%Y-%m-%d %H:%M:%S").c_str(),
            unixTimeToString(backTimestamp, "%Y-%m-%d %H:%M:%S").c_str());

        frontTimestamp = chart[Timeframe::MINUTE].getMultiCandles().front().timestamp / 1000;
        backTimestamp = chart[Timeframe::MINUTE].getMultiCandles().back().timestamp / 1000;
        std::printf("symbol: %s, minute chart size: %lu, first timestamp: %s, last timestamp: %s\n", symbol.c_str(),
            chart[Timeframe::MINUTE].getMultiCandles().size(),
            unixTimeToString(frontTimestamp, "%Y-%m-%d %H:%M:%S").c_str(),
            unixTimeToString(backTimestamp, "%Y-%m-%d %H:%M:%S").c_str());

        applyIndicators(chart);
    }
}

TEST_F(SchwabDatabankRealDataTest, getOptionsTest)
{
    std::string symbol = "AAPL";
    unsigned strikes = 5;

    auto options = databank->getOptionChain(symbol, strikes);

    for(const auto& [expirationDate, strikesMap] : options)
    {
        for(const auto& [strike, optionPair] : strikesMap)
        {
            std::printf("expiration date: %s, strike: %.02f, call: %.02f, put: %.02f\n",
                expirationDate.c_str(), strike, optionPair.callOption().last, optionPair.putOption().last);
        }
    }
}