#include "SchwabDatabank.h"

#include "Logger.h"
#include "SchwabStreamDataParser.h"

namespace databank {
using namespace schwabStreamParser;

SchwabDatabank::SchwabDatabank(std::shared_ptr<DataQueue<std::string>> streamqueue, std::string logfile)
    : streamqueue(streamqueue)
    , logfile(logfile)
{
    infologprint(logfile, "%s: init", __func__);
}

void SchwabDatabank::startParsing()
{
    infologprint(logfile, "%s: start parsing thread", __func__);
    std::thread parseThread(&SchwabDatabank::parseStreamQueue, this, 0);
}

void SchwabDatabank::parseStreamQueue(unsigned count)
{
    infologprint(logfile, "%s: start parsing", __func__);
    unsigned pops = 0;
    while (true)
    {
        if (!streamqueue->isEmpty())
        {
            SchwabServiceData data = parseServiceData(streamqueue->front());
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

void SchwabDatabank::updateMinuteCharts(const std::string symbol, const ChartEquity minuteCandle)
{
    std::lock_guard<std::mutex> lg(mtx);

    if (minuteCandle.low < 0 || minuteCandle.high < 0 || minuteCandle.open < 0 || minuteCandle.close < 0 ||
        minuteCandle.volume < 0 || minuteCandle.time < 0)
    {
        errorlogprint(logfile, "%s: negative value in minuteCandle: %s", __func__, minuteCandle.toString().c_str());
        return;
    }

    uint64_t timestamp =
        static_cast<uint64_t>(minuteCandle.time); // fractional part is lost but that is ok for timestmap

    if (minuteCharts.find(symbol) == minuteCharts.end())
    {
        minuteCharts[symbol] = ChartData3();
        minuteCharts[symbol].addMultiCandle(MultiCandle(CandleStick(timestamp, minuteCandle.low, minuteCandle.high,
            minuteCandle.open, minuteCandle.close, minuteCandle.volume)));
    }
    else
    {
        minuteCharts[symbol].addMultiCandle(MultiCandle(CandleStick(timestamp, minuteCandle.low, minuteCandle.high,
            minuteCandle.open, minuteCandle.close, minuteCandle.volume)));
    }
}

void SchwabDatabank::updateLevelOneEquities(const std::string symbol, const LevelOneEquity levelOneE)
{
    std::lock_guard<std::mutex> lg(mtx);
    (void)symbol;
    (void)levelOneE;
}

ChartData3 SchwabDatabank::getChart(std::string symbol)
{
    std::lock_guard<std::mutex> lg(mtx);
    if (minuteCharts.find(symbol) != minuteCharts.end())
    {
        return minuteCharts.at(symbol);
    }
    throw std::runtime_error("symbol for chart not found");
}
} // namespace databank