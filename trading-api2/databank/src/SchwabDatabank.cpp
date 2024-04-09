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
    std::thread parseThread(&SchwabDatabank::parseStreamQueue, this);
}

void SchwabDatabank::parseStreamQueue()
{
    while (true)
    {
        if (!streamqueue->isEmpty())
        {
            SchwabServiceData data = parseServiceData(streamqueue->front());
            streamqueue->pop();

            for (const auto& [symbol, chartEqu] : data.chartEquities)
            {
                updateMinuteCharts(symbol, chartEqu);
            }

            for (const auto& [symbol, levelOneE] : data.levelOneEquities)
            {
                // update levelone equities databank
                (void)symbol;
                (void)levelOneE;
            }
        }
    }
}

void SchwabDatabank::updateMinuteCharts(const std::string symbol, const ChartEquity minuteCandle)
{
    std::lock_guard<std::mutex> lg(mtx);
    uint64_t timestamp =
        static_cast<uint64_t>(minuteCandle.time); // fractional part is lost but that is ok for timestmap

    if (minuteCharts.find(symbol) == minuteCharts.end())
    {
        std::vector<MultiCandle> mcandles;
        mcandles.push_back(MultiCandle(CandleStick(timestamp, minuteCandle.low, minuteCandle.high, minuteCandle.open,
            minuteCandle.close, minuteCandle.volume)));
        // ChartData2 needs refactoring to better accomadate being used in a map
        // minuteCharts[symbol] = ChartData2(mcandles);
    }
    else
    {
        // minuteCharts[symbol].addCandle(CandleStick(timestamp, minuteCandle.low, minuteCandle.high, minuteCandle.open,
        //     minuteCandle.close, minuteCandle.volume));
    }
}

ChartData2 SchwabDatabank::getChart(std::string symbol)
{
    std::lock_guard<std::mutex> lg(mtx);
    if (minuteCharts.find(symbol) != minuteCharts.end())
    {
        return minuteCharts.at(symbol);
    }
    throw std::runtime_error("symbol for chart not found");
}
} // namespace databank