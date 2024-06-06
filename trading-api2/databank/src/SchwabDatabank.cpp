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
    , chartsAggregator(std::make_shared<ChartsAggregator>(logfile))
    , sClient(sClient)
{
    infologprint(logfile, "%s: init", __func__);
}

void SchwabDatabank::initializeData(std::set<std::string> symbols)
{
    infologprint(logfile, "%s: initialize data", __func__);

    time_t currMs = nowMs();

    time_t oneYearAgoMs = currMs - 31536000000; // 1000 * 60 * 60 * 24 * 365

    time_t oneMonthAgoMs = currMs - 2592000000; // 1000 * 60 * 60 * 24 * 30

    time_t oneWeekAgoMs = currMs - 604800000; // 1000 * 60 * 60 * 24 * 7

    for (const auto& symbol : symbols)
    {
        // year daily
        auto candleSticks = getCandlesFromClient(symbol, Timeframe::DAILY, oneYearAgoMs, currMs);
        ChartData3 dailyChart;
        for (const auto& candleStick : candleSticks)
        {
            dailyChart.addMultiCandle(candleStick);
        }
        chartsAggregator->addChart(symbol, dailyChart, Timeframe::DAILY);

        // thirty min month ago
        candleSticks = getCandlesFromClient(symbol, Timeframe::THIRTY, oneMonthAgoMs, currMs + 86400000);
        ChartData3 thirtyChart;
        for (const auto& candleStick : candleSticks)
        {
            thirtyChart.addMultiCandle(candleStick);
        }
        chartsAggregator->addChart(symbol, thirtyChart, Timeframe::THIRTY);

        // 5min week ago
        candleSticks = getCandlesFromClient(symbol, Timeframe::FIVE, oneWeekAgoMs, currMs + 86400000);
        ChartData3 fiveChart;
        for (const auto& candleStick : candleSticks)
        {
            fiveChart.addMultiCandle(candleStick);
        }
        chartsAggregator->addChart(symbol, fiveChart, Timeframe::FIVE);

        // minute week ago
        candleSticks = getCandlesFromClient(symbol, Timeframe::MINUTE, oneWeekAgoMs, currMs + 86400000);
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
    for (const auto& symbol : symbols)
    {
        for (const auto& [timeframe, timeframeStr] : timeFrameStrings)
        {
            std::string symbolAndTimeframe = symbol + "_" + timeframeStr;
            auto candleSticks = dbHandler->getCandles(symbolAndTimeframe, fromTime, toTime);
            ChartData3 chart;
            for (const auto& candle : candleSticks)
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

    /*infologprint(
        logfile, "%s:ADD symbol: %s, minuteCandle: %s", __func__, symbol.c_str(), minuteCandle.toString().c_str());*/

    uint64_t timestamp =
        static_cast<uint64_t>(minuteCandle.time); // fractional part is lost but that is ok for timestmap

    CandleStick candleStick(
        timestamp, minuteCandle.low, minuteCandle.high, minuteCandle.open, minuteCandle.close, minuteCandle.volume);
    pushCandleToDb(symbol, Timeframe::MINUTE, candleStick);

    chartsAggregator->addMinuteCandle(symbol, candleStick);
}

void SchwabDatabank::pushCandleToDb(const std::string symbol, const Timeframe& timeframe, const CandleStick candle)
{
    // dbHandler->pushCandle(symbol, candle);
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

std::vector<CandleStick> SchwabDatabank::getCandlesFromClient(
    const std::string& symbol, const Timeframe timeframe, const uint64_t& fromTime, const uint64_t& toTime)
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

charting::OptionChain SchwabDatabank::getOptionChain(const std::string& symbol, unsigned strikes)
{
    SchwabOptionChain schwabOptionChain = sClient->getOptionChain(symbol, strikes);

    OptionChain optionChain;

    for (const auto& [OptionExpDate, StrikesChain] : schwabOptionChain.callExpDateMap)
    {
        // find ":" because returned date has some extra number after colon in the dates
        auto colonIndex = OptionExpDate.find(":");
        std::string date = OptionExpDate;
        if (colonIndex != std::string::npos)
        {
            date = OptionExpDate.substr(0, colonIndex);
        }
        for (const auto& option : StrikesChain)
        {
            Option callOption;
            callOption.strike = option.strikePrice;
            callOption.bid = option.bidPrice;
            callOption.ask = option.askPrice;
            callOption.last = option.lastPrice;
            callOption.bidSize = option.bidSize;
            callOption.askSize = option.askSize;
            callOption.volume = option.totalVolume;
            callOption.open = option.openPrice;
            callOption.close = option.closePrice;
            callOption.option_type = "call";

            callOption.symbol = option.symbol;
            callOption.delta = option.delta;
            callOption.gamma = option.gamma;
            callOption.theta = option.theta;
            callOption.vega = option.vega;
            callOption.rho = option.rho;
            callOption.volatility = option.volatility;

            OptionPair optionpair = OptionPair(callOption);
            optionChain[date][option.strikePrice] = optionpair;
        }
    }

    for (const auto& [OptionExpDate, StrikesChain] : schwabOptionChain.putExpDateMap)
    {
        auto colonIndex = OptionExpDate.find(":");
        std::string date = OptionExpDate;
        if (colonIndex != std::string::npos)
        {
            date = OptionExpDate.substr(0, colonIndex);
        }
        for (const auto& option : StrikesChain)
        {
            Option putOption;
            putOption.strike = option.strikePrice;
            putOption.bid = option.bidPrice;
            putOption.ask = option.askPrice;
            putOption.last = option.lastPrice;
            putOption.bidSize = option.bidSize;
            putOption.askSize = option.askSize;
            putOption.volume = option.totalVolume;
            putOption.open = option.openPrice;
            putOption.close = option.closePrice;
            putOption.option_type = "put";

            putOption.symbol = option.symbol;
            putOption.delta = option.delta;
            putOption.gamma = option.gamma;
            putOption.theta = option.theta;
            putOption.vega = option.vega;
            putOption.rho = option.rho;
            putOption.volatility = option.volatility;

            optionChain[date][option.strikePrice].setPut(putOption);
        }
    }

    return optionChain;
}

} // namespace databank