#include "SchwabDatabank.h"

#include "Logger.h"
#include "SchwabDatabaseHandler.h"
#include "SchwabStreamDataParser.h"
#include "SystemTimer.h"
#include "timefuncs.h"

namespace databank {
using namespace schwabStreamParser;
using namespace utils;
using namespace timefuncs;

SchwabDatabank::SchwabDatabank(std::shared_ptr<ISchwabClient> sClient, std::shared_ptr<IDatabaseHandler> dbHandler,
    std::shared_ptr<DataQueue<std::string>> streamqueue, std::string logfile)
    : streamqueue(streamqueue)
    , logfile(logfile)
    , dbHandler(dbHandler)
    , chartsAggregator(std::make_shared<ChartsAggregator>())
    , sClient(sClient)
{
    infologprint(logfile, "%s: init", __func__);
}

void SchwabDatabank::initializeData(std::set<std::string> symbols)
{
    infologprint(logfile, "%s: initialize data", __func__);

    time_t currS = nowMs() / 1000;
    std::string currTimeStr = unixTimeToString(currS, "%Y-%m-%d");

    time_t oneYearAgoMs = currS - 31536000; // 1000 * 60 * 60 * 24 * 365
    std::string oneYearAgoStr = unixTimeToString(oneYearAgoMs, "%Y-%m-%d");

    time_t oneMonthAgoMs = currS - 2592000; // 1000 * 60 * 60 * 24 * 30
    std::string oneMonthAgoStr = unixTimeToString(oneMonthAgoMs, "%Y-%m-%d");

    time_t oneWeekAgoMs = currS - 604800; // 1000 * 60 * 60 * 24 * 7
    std::string oneWeekAgoStr = unixTimeToString(oneWeekAgoMs, "%Y-%m-%d");

    for (const auto& symbol : symbols)
    {
        // year daily
        auto candleSticks = getCandlesFromClient(symbol, Timeframe::DAILY, oneYearAgoStr, currTimeStr);
        ChartData3 dailyChart;
        for (const auto& candleStick : candleSticks)
        {
            dailyChart.addMultiCandle(candleStick);
        }
        chartsAggregator->addChart(symbol, dailyChart, Timeframe::DAILY);

        // thirty min month ago
        candleSticks = getCandlesFromClient(symbol, Timeframe::THIRTY, oneMonthAgoStr, currTimeStr);
        ChartData3 thirtyChart;
        for (const auto& candleStick : candleSticks)
        {
            thirtyChart.addMultiCandle(candleStick);
        }
        chartsAggregator->addChart(symbol, thirtyChart, Timeframe::THIRTY);

        // 5min week ago
        candleSticks = getCandlesFromClient(symbol, Timeframe::FIVE, oneWeekAgoStr, currTimeStr);
        ChartData3 fiveChart;
        for (const auto& candleStick : candleSticks)
        {
            fiveChart.addMultiCandle(candleStick);
        }
        chartsAggregator->addChart(symbol, fiveChart, Timeframe::FIVE);

        // minute week ago
        candleSticks = getCandlesFromClient(symbol, Timeframe::MINUTE, oneWeekAgoStr, currTimeStr);
        ChartData3 minuteChart;
        for (const auto& candleStick : candleSticks)
        {
            minuteChart.addMultiCandle(candleStick);
        }
        chartsAggregator->addChart(symbol, minuteChart, Timeframe::MINUTE);
    }
}

void SchwabDatabank::initializeDataFromDb(std::set<std::string> symbols, std::string fromTime, std::string toTime)
{
    for(const auto& symbol : symbols)
    {
        for(const auto& [timeframe, timeframeStr] : timeFrameStrings)
        {
            std::string symbolAndTimeframe = symbol + "_" + timeframeStr;
            auto candleSticks = dbHandler->getCandles(symbolAndTimeframe, fromTime, toTime);
            ChartData3 chart;
            for(const auto& candle : candleSticks)
            {
                chart.addMultiCandle(candle);
            }
            chartsAggregator->addChart(symbol, chart, timeframe);
        }
    }
}

void SchwabDatabank::startParsing()
{
    infologprint(logfile, "%s: start parsing thread", __func__);
    parsingThread = std::thread(&SchwabDatabank::parseStreamQueue, this, 0);
}

void SchwabDatabank::parseStreamQueue(unsigned count)
{
    infologprint(logfile, "%s: start parsing", __func__);
    unsigned pops = 0;
    while (true)
    {
        if (!streamqueue->isEmpty())
        {
            auto jsondata = streamqueue->front();
            pushJsonDataToDb(jsondata);

            SchwabServiceData data = parseServiceData(jsondata);
            streamqueue->pop();
            pops++;

            for (const auto& [symbol, chartEqu] : data.chartEquities)
            {
                updateMinuteCharts(symbol, chartEqu);
            }

            for (const auto& [symbol, levelOneE] : data.levelOneEquities)
            {
                updateLevelOneEquities(symbol, levelOneE);
            }
        }
        if (pops >= count && count != 0)
        {
            break;
        }
    }
}

void SchwabDatabank::pushJsonDataToDb(const std::string jsondata)
{
    dbHandler->pushJsonData(jsondata);
}

void SchwabDatabank::updateMinuteCharts(const std::string symbol, const ChartEquity minuteCandle)
{
    std::lock_guard<std::mutex> lg(mtx);

    if (minuteCandle.low < 0 || minuteCandle.high < 0 || minuteCandle.open < 0 || minuteCandle.close < 0 ||
        minuteCandle.volume < 0 || minuteCandle.time < 0)
    {
        errorlogprint(logfile, "%s: negative value in minuteCandle: %s", __func__, minuteCandle.toString().c_str());
        return;
    }

    infologprint(
        logfile, "%s:ADD symbol: %s, minuteCandle: %s", __func__, symbol.c_str(), minuteCandle.toString().c_str());

    uint64_t timestamp =
        static_cast<uint64_t>(minuteCandle.time); // fractional part is lost but that is ok for timestmap

    CandleStick candleStick(
        timestamp, minuteCandle.low, minuteCandle.high, minuteCandle.open, minuteCandle.close, minuteCandle.volume);
    pushCandleToDb(symbol, Timeframe::MINUTE, candleStick);

    chartsAggregator->addMinuteCandle(symbol, candleStick);
}

void SchwabDatabank::pushCandleToDb(const std::string symbol, const Timeframe& timeframe, const CandleStick candle)
{
    //dbHandler->pushCandle(symbol, candle);
    std::string symbolAndTimeframe = symbol + "_" + timeFrameStrings.at(timeframe);
    dbHandler->pushCandle(symbolAndTimeframe, candle);
}

void SchwabDatabank::pushCandleToDb(const std::string symbol, const CandleStick candle)
{
    dbHandler->pushCandle(symbol, candle);
}

void SchwabDatabank::updateLevelOneEquities(const std::string symbol, const LevelOneEquity levelOneE)
{
    std::lock_guard<std::mutex> lg(mtx);
    (void)symbol;
    (void)levelOneE;
}

ChartTimeframesMap SchwabDatabank::getChart(std::string symbol)
{
    std::lock_guard<std::mutex> lg(mtx);
    return chartsAggregator->getTimeframeCharts(symbol);
}

std::vector<CandleStick> SchwabDatabank::getCandlesFromDb(
    const std::string& symbol, const Timeframe& timeframe, const std::string& fromTime, const std::string& toTime)
{
    std::string symbolAndTimeframe = symbol + "_" + timeFrameStrings.at(timeframe);
    return dbHandler->getCandles(symbolAndTimeframe, fromTime, toTime);
}

std::vector<std::string> SchwabDatabank::getJsonDataFromDb(const std::string& fromTime, const std::string& toTime)
{
    return dbHandler->getJsonData(fromTime, toTime);
}

/*if fromTime is not specified, SchwabClient api will use fromTime = toTime - period*/
std::vector<CandleStick> SchwabDatabank::getCandlesFromClient(
    const std::string& symbol, const Timeframe timeframe, const std::string& fromTime, const std::string& toTime)
{
    PriceHistory priceHistory;
    switch (timeframe)
    {
        case Timeframe::MINUTE:
            priceHistory = sClient->getPriceHistory(
                symbol, PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 1, fromTime, toTime, true);
            break;
        case Timeframe::FIVE:
            priceHistory = sClient->getPriceHistory(
                symbol, PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 5, fromTime, toTime, true);
            break;
        case Timeframe::FIFTEEN:
            priceHistory = sClient->getPriceHistory(
                symbol, PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 15, fromTime, toTime, true);
            break;
        case Timeframe::THIRTY:
            priceHistory = sClient->getPriceHistory(
                symbol, PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 30, fromTime, toTime, true);
            break;
        case Timeframe::DAILY:
            priceHistory = sClient->getPriceHistory(
                symbol, PriceHistoryPeriodType::YEAR, 1, PriceHistoryTimeFreq::DAILY, 1, fromTime, toTime);
            break;
        case Timeframe::HOURLY:
        default:
            errorlogprint(logfile, "%s: invalid timeframe", __func__);
            break;
    }

    std::vector<CandleStick> candleSticks;
    for (const auto& candle : priceHistory.candles)
    {
        candleSticks.push_back(
            CandleStick(candle.datetime, candle.low, candle.high, candle.open, candle.close, candle.volume));
    }

    return candleSticks;
}
} // namespace databank