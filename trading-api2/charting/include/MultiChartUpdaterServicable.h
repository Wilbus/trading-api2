#pragma once

#include "CandleSampler.h"
#include "ChartData2.h"
#include "DataQueueContainer.h"
#include "InfluxDbDataPusher.h"

#include <thread>

namespace charting {

using namespace datatypes;
using namespace database;

class MultiChartUpdaterServicable
{
    /*
    -updates chart + orderbook for multiple tickers
    -should be able to handle different time granularities for diff tickers
    */
public:
    MultiChartUpdaterServicable(std::shared_ptr<Config>& config, std::shared_ptr<Logger>& logger,
        std::shared_ptr<DataQueueContainer>& incomingData)
        : config(config)
        , logger(logger)
        , incomingData(incomingData)
    {
        infolog(logger, "%s() Starting MultiChartUpdaterServicable()", __func__);
    }

    ~MultiChartUpdaterServicable()
    {
    }

    std::string removeForbiddenInfluxChars(std::string str, std::string chars)
    {
        std::size_t found = str.find_first_of(chars.c_str());
        while (found != std::string::npos)
        {
            str[found] = '_';
            found = str.find_first_of(chars.c_str(), found);
        }

        return str;
    }

    void addNewOrderBook(std::string product_id)
    {
        OrderbookLvl2 newbook(product_id);
        orderbookMap[product_id] = newbook;
    }

    void pushNewChartToDb(std::string influxTicker, ChartData2 chartData)
    {
        dbMap[influxTicker]->setBatchSize(300);
        /*for (auto c : *(chartData.getChartData().get()))
        {
            dbMap[influxTicker]->pushCandleData(c.second);
        }*/
        for (const auto& c : chartData.getMCandles())
        {
            CandleStick candle;
            candle.timestamp = c.timestamp;
            candle.price_open = c.price_open;
            candle.price_high = c.price_high;
            candle.price_low = c.price_low;
            candle.price_close = c.price_close;
            candle.product_id = c.product_id;
            dbMap[influxTicker]->pushCandleData(candle);
        }
        dbMap[influxTicker]->flushBatch();
        dbMap[influxTicker]->setBatchSize(1); // to resume adding candles min by min
    }

    void addNewChart(std::string ticker, ChartData2 chartData)
    {
        if (tickerChartUpdaterMap.find(ticker) != tickerChartUpdaterMap.end())
        {
            return; // don't add if ticker already exists
        }

        // add ticker chart data
        tickerChartUpdaterMap[ticker] = chartData;
        infologprint(logger, "%s() ticker %s chart added with size %d", __func__, ticker.c_str(),
            tickerChartUpdaterMap[ticker].getSize());

        // add ticker to candlesampler map
        candleSamplerMap[ticker] = CandleSampler(logger, ticker);
        auto lastTimestamp = chartData[0].timestamp;
        std::cout << "lasttimetsamp : " << lastTimestamp << "\n";
        candleSamplerMap[ticker].setPreviousUnixTime(lastTimestamp);

        // influxdb cannot have '-' in the dbname or queries
        ticker = removeForbiddenInfluxChars(ticker, "-");

        std::string candlesDb = config->getInfluxDbName() + "_" + ticker;
        infologprint(logger, "%s() connecting to DB: %s", __func__, candlesDb.c_str());
        dbMap[ticker] = std::make_shared<InfluxDbDataPusher>(candlesDb, 1);

        pushNewChartToDb(ticker, chartData);
    }

    ChartData2 getChart(std::string ticker)
    {
        return tickerChartUpdaterMap.at(ticker);
    }

    void startUpdateThread()
    {
        infologprint(logger, "%s()", __func__);
        multiChartsUpdatingThread = std::thread(&MultiChartUpdaterServicable::doUpdates, this);
    }

    void startTickersTimersThread()
    {
    }

    void startPeriodicDbPushThread()
    {
    }

    void startOrderbooksThread()
    {
        infologprint(logger, "%s()", __func__);
        orderBooksThread = std::thread(&MultiChartUpdaterServicable::doLevel2Updates, this);
    }

    void doLevel2Updates()
    {
        while (true)
        {
            try
            {
                if (!incomingData->level2Que->isEmpty())
                {
                    const auto& level2 = incomingData->level2Que->front();

                    if (orderbookMap.find(level2.product_id) != orderbookMap.end())
                    {
                        // only process for tickers that the updater has level2 data for
                        for (const auto& l2update : level2.updates)
                        {
                            if (l2update.side == L2TradeSide::bid)
                                orderbookMap[level2.product_id].updateBid(l2update.price_level, l2update.new_quantity);
                            else if (l2update.side == L2TradeSide::ask)
                                orderbookMap[level2.product_id].updateAsk(l2update.price_level, l2update.new_quantity);
                            else
                                std::printf("level2updates has invalid trade side\n");
                        }
                    }
                    incomingData->level2Que->pop();
                }
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }

    void doUpdates()
    {
        while (true)
        {
            try
            {
                if (!incomingData->marketTradesQue->isEmpty())
                {
                    const auto& marketTrade = incomingData->marketTradesQue->front();

                    if (candleSamplerMap.find(marketTrade.product_id) == candleSamplerMap.end())
                    {
                        // only process for tickers that the updater has chart data for
                        // std::cout << marketTrade.product_id << "\n";
                        incomingData->marketTradesQue->pop();
                        continue;
                    }

                    auto newCandleOptional = candleSamplerMap.at(marketTrade.product_id).sampleTicker(marketTrade);
                    if (newCandleOptional.has_value()) // we got new candle
                    {
                        infologprint(logger, "%s New candle: %s", marketTrade.product_id.c_str(),
                            newCandleOptional.value().toString().c_str());

                        // tickersTimers[marketTrade.product_id]->getTimer()->resetCounter();

                        tickerChartUpdaterMap[marketTrade.product_id].addCandle(newCandleOptional.value());
                        toDbCandlesQueue.push(newCandleOptional.value());

                        std::string csvfilepath =
                            config->getChartCsvDataOutputPath() + "_" + marketTrade.product_id + ".csv";
                        tickerChartUpdaterMap[marketTrade.product_id].dumpToCSV(csvfilepath);
                    }
                    incomingData->marketTradesQue->pop();
                }
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }

    void periodicDbPush()
    {
        try
        {
            while (!toDbCandlesQueue.isEmpty())
            {
                auto candle = toDbCandlesQueue.front();
                std::cout << candle.product_id << "\n";
                std::string influx_product_id = removeForbiddenInfluxChars(candle.product_id, "-");
                dbMap[influx_product_id]->pushCandleData(candle);
                toDbCandlesQueue.pop();
            }
        }
        catch (const std::exception& e)
        {
            std::stringstream ss;
            ss << e.what();
            errorlogprint(logger, "%s() %s", __func__, ss.str().c_str());
        }
    }

public:
    std::shared_ptr<Config> config;
    std::shared_ptr<Logger> logger;
    std::map<std::string, ChartData2> tickerChartUpdaterMap;
    std::map<std::string, CandleSampler> candleSamplerMap;
    std::map<std::string, OrderbookLvl2> orderbookMap;
    std::shared_ptr<DataQueueContainer> incomingData;

    std::thread multiChartsUpdatingThread;
    std::thread periodicDbThread;
    std::thread orderBooksThread;

    std::map<std::string, std::shared_ptr<InfluxDbDataPusher>> dbMap;
    DataQueue<CandleStick> toDbCandlesQueue;
};
} // namespace charting