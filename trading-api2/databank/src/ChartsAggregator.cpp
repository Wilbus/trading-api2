#include "ChartsAggregator.h"

namespace databank {

ChartsAggregator::ChartsAggregator(std::string logfile)
{
}

ChartsAggregator::ChartsAggregator(std::map<std::string, ChartTimeframesMap> charts, std::string logfile)
    : logfile(logfile)
{
    this->charts = charts;
}

void ChartsAggregator::addMinuteCandle(std::string symbol, CandleStick candle)
{
    // charts[symbol].minute.addMultiCandle(MultiCandle{candle});
    charts[symbol][Timeframe::MINUTE].addMultiCandle(MultiCandle{candle});
    aggregateChartData(symbol, FIVE);
    aggregateChartData(symbol, FIFTEEN);
    aggregateChartData(symbol, THIRTY);
    aggregateChartData(symbol, HOURLY);
    aggregateChartData(symbol, DAILY);
}

ChartData3 ChartsAggregator::getChartData(std::string symbol, Timeframe timeframe) const
{
    return charts.at(symbol).at(timeframe);
}

ChartTimeframesMap ChartsAggregator::getTimeframeCharts(std::string symbol) const
{
    return charts.at(symbol);
}

void ChartsAggregator::initializeMinuteChart(std::string symbol, ChartData3 chart)
{
    charts[symbol][Timeframe::MINUTE] = chart;
}

void ChartsAggregator::addChart(std::string symbol, ChartData3 chart, Timeframe timeframe)
{
    charts[symbol][timeframe] = chart;
}

std::vector<MultiCandle> ChartsAggregator::getLastNMinutes(std::string symbol, int n)
{
    try
    {
        std::vector<MultiCandle> minutes;
        for (int i = n; i > 0; i--)
        {
            auto minute = charts.at(symbol).at(Timeframe::MINUTE).getBack(i);
            minutes.push_back(minute);
        }

        return minutes;
    }
    catch (const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
        return {};
    }
}

// assuming timestamps in charts are already aligned to minutes
// previousFive is the last five minute candle
// we have added a minute candle, so now we need to check if we have received enough data to create a new candle aligned
// to timeframe
void ChartsAggregator::aggregateChartData(std::string symbol, Timeframe alignedOn)
{
    size_t numberOfMinutes = alignedOn / 60;
    auto lastNMinutes = getLastNMinutes(symbol, numberOfMinutes);
    if (lastNMinutes.size() < numberOfMinutes)
    {
        return;
    }

    // if((lastNMinutes.back().timestamp - lastNMinutes.front().timestamp) % (alignedOn - 60) == 0)
    // Timestamps in ms!!!
    if (lastNMinutes.front().timestamp != 0 && (lastNMinutes.front().timestamp / 1000) % (alignedOn) == 0)
    {
        // calculate the new five minute candle
        double open = lastNMinutes.front().price_open;
        double close = lastNMinutes.back().price_close;
        double high = std::numeric_limits<double>::min();
        double low = std::numeric_limits<double>::max();
        double volume = 0;
        for (auto minute : lastNMinutes)
        {
            if (minute.price_high > high)
            {
                high = minute.price_high;
            }
            if (minute.price_low < low)
            {
                low = minute.price_low;
            }
            volume += minute.volume;
        }
        uint64_t timestamp = lastNMinutes.front().timestamp;

        CandleStick nextAggregateCandle(timestamp, low, high, open, close, volume);
        // charts.at(symbol).five.addMultiCandle(MultiCandle(nextAggregateCandle));
        charts[symbol][alignedOn].addMultiCandle(MultiCandle(nextAggregateCandle));
        infologprint(logfile, "%s: %s: added new candle in %d timeframe, timestamp = %lu", __func__, symbol.c_str(),
            alignedOn, timestamp);
        // charts.at(symbol).at(alignedOn).addMultiCandle(MultiCandle(nextAggregateCandle));
    }
}

} // namespace databank