#pragma once

#include <map>
#include <string>
#include <vector>

namespace charting {

struct IndicatorValue
{
    bool isNan = true;
    double value;
    uint64_t timestamp;

    std::string toString()
    {
        if (isNan)
            return "";
        else
            return std::to_string(value);
    }
};

enum IndicatorTypes : unsigned int
{
    SMA = 0,
    EMA,
    BBUP,
    BBDOWN,
    BBMID,
    STOCH,
    STOCHUPPER,
    STOCHLOWER,
    ADX,
    RSI,
    THREEWHITESOLDIERS,
    THREEBLACKCROWS,

    LIMITBUY,
    LIMITSELL,
    STOPLIMIT,
    MARKET,
    BUYSIGNAL,
    SELLSIGNAL,
    UNKOWN
};

struct IndicatorType
{
    friend bool operator<(const IndicatorType& i1, const IndicatorType& i2);

    std::string name;
    IndicatorTypes type;
    std::vector<std::string> params;

    bool operator==(const IndicatorType& other)
    {
        return (this->name == other.name) && (this->type == other.type) && (this->params == other.params);
    }

    std::string toString()
    {
        char buff[64];
        std::sprintf(buff, "type: %u, name: %s\n", static_cast<unsigned>(type), name.c_str());
        return std::string(buff);
    }
};
} // namespace charting