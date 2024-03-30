#ifndef MARKETDATASINGLETON_H
#define MARKETDATASINGLETON_H

#include "EWrapper.h"
#include "MultiCandle.h"
#include "ta-lib-wrapper.h"

#include <mutex>

using namespace charting;

struct MktData
{
    MktData()
    {
        for (int type = TickType::BID_SIZE; type < TickType::NOT_SET; type++)
        {
            tickTypes[static_cast<TickType>(type)] = -99;
        }
    }
    std::map<TickType, double> tickTypes;
    std::vector<MultiCandle> mCandles;
};

class MarketDataSingleton
{
public:
    MarketDataSingleton()
    {
    }
    ~MarketDataSingleton()
    {
    }
    /**
     * Singletons should not be cloneable.
     */
    MarketDataSingleton(MarketDataSingleton& other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const MarketDataSingleton&) = delete;
    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */
    static MarketDataSingleton* GetInstance();

    // data accessors
    void resetMktData(std::string symbol)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        mktDataMap[symbol] = MktData();
    }

    void updateMkData(std::string symbol, TickType field, double price)
    {
        // mutex_.lock();
        std::lock_guard<std::mutex> lock(mutex_);
        if (mktDataMap.find(symbol) == mktDataMap.end())
        {
            mktDataMap[symbol] = MktData();
            mktDataMap[symbol].tickTypes[field] = price;
        }
        else
        {
            mktDataMap[symbol].tickTypes[field] = price;
        }

        // mutex_.unlock();
    }

    void copyMCandles(std::string symbol, std::vector<MultiCandle> mcandles)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (mktDataMap.find(symbol) == mktDataMap.end())
        {
            mktDataMap[symbol] = MktData();
            mktDataMap[symbol].mCandles = mcandles;
        }
        else
        {
            mktDataMap[symbol].mCandles = mcandles;
        }
    }

    void addMCandle(std::string symbol, MultiCandle mcandle)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (mktDataMap.find(symbol) == mktDataMap.end())
        {
            throw std::runtime_error("mcandles not initialized for this symbol");
        }
        else
        {
            mktDataMap[symbol].mCandles.push_back(mcandle);
        }
    }

    void addMCandleIndicator(std::string symbol, IndicatorType indicator)
    {
        ta_lib_wrapper::TALIB talib;
        auto mcandles = mktDataMap[symbol].mCandles;
        auto size = mcandles.size();

        std::vector<IndicatorValue> indicatorValues;
        switch (indicator.type)
        {
            case SMA: {
                indicatorValues = talib.SMA(mcandles, 0, size - 1, std::stoi(indicator.params[0]));
                break;
            }
            case ADX: {
                indicatorValues = talib.ADX(mcandles, 0, mcandles.size() - 1, std::stoi(indicator.params[0]));
                break;
            }
            case RSI: {
                indicatorValues = talib.RSI(mcandles, 0, mcandles.size() - 1, std::stoi(indicator.params[0]));
                break;
            }
            default: {
                break;
            }
        }

        addIndicatorData(mktDataMap[symbol].mCandles, indicatorValues, indicator);
    }

    double getMktData(std::string symbol, TickType field)
    {
        // mutex_.lock();
        std::lock_guard<std::mutex> lock(mutex_);
        double price = mktDataMap[symbol].tickTypes[field];
        // mutex_.unlock();
        return price;
    }

    std::vector<MultiCandle> getMCandles(std::string symbol)
    {
        // mutex_.lock();
        std::lock_guard<std::mutex> lock(mutex_);
        return mktDataMap[symbol].mCandles;
    }

    // data structs
    std::map<std::string, MktData> mktDataMap;

private:
    static MarketDataSingleton* singleton_;
    static std::mutex mutex_;

    void addIndicatorData(std::vector<MultiCandle>& mCandles, std::vector<IndicatorValue> ivalues, IndicatorType type)
    {
        for (unsigned i = 0; i < mCandles.size(); i++)
        {
            if (mCandles[i].getTimestamp() != ivalues[i].timestamp)
            {
                throw std::runtime_error("Misaligned timestamps in new indicators vector");
            }
            mCandles[i].setInd(type, ivalues[i]);
        }
    }
};

#endif // MARKETDATASINGLETON_H
