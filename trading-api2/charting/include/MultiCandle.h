#pragma once

#include "CandleStick.h"
#include "IndicatorTypes.h"

#include <any>
#include <map>
#include <memory>
#include <mutex>
#include <unordered_map>

namespace charting {

class MultiCandle : public CandleStick
{
public:
    MultiCandle()
    {
    }
    MultiCandle(CandleStick candle)
    {
        // labels["timestamp"] = candle.timestamp;
        // labels["price_open"] = candle.price_open;
        // labels["price_high"] = candle.price_high;
        // labels["price_low"] = candle.price_low;
        // labels["price_close"] = candle.price_close;
        // labels["volume"] = candle.volume;
        // labels["product_id"] = candle.product_id;
        timestamp = candle.timestamp;
        price_low = candle.price_low;
        price_high = candle.price_high;
        price_open = candle.price_open;
        price_close = candle.price_close;
        volume = candle.volume;
        product_id = candle.product_id;
    }

    uint64_t getTimestamp() const
    {
        return timestamp;
    }

    std::vector<IndicatorType> listIndicators() const
    {
        std::vector<IndicatorType> l;
        for (const auto& it : indicators)
        {
            l.push_back(it.first);
        }
        return l;
    }

    void setInd(IndicatorType type, IndicatorValue data)
    {
        indicators[type] = data;
    }

    IndicatorValue getInd(IndicatorType type)
    {
        auto it = indicators.find(type);
        if (it == indicators.end())
        {
            std::string msg = "getInd() indicatorname: " + type.name + " not found in multicandle\n";
            throw std::runtime_error(msg.c_str());
        }

        return std::any_cast<IndicatorValue>(it->second);
    }

    template <typename T>
    T getIndByName(std::string name)
    {
        for (const auto& it : indicators)
        {
            if (it.first.name == name)
            {
                return std::any_cast<T>(it.second);
            }
        }
        std::string msg = "getIndByName() indicatorname: " + name + " not found in multicandle\n";
        throw std::runtime_error(msg.c_str());
    }

    std::any getAnyInd(IndicatorType type) const
    {
        auto it = indicators.find(type);
        if (it == indicators.end())
        {
            std::string msg = "getInd() indicatorname: " + type.name + " not found in multicandle\n";
            throw std::runtime_error(msg.c_str());
        }
        return it->second;
    }

private:
    std::map<IndicatorType, std::any> indicators;
};
} // namespace charting