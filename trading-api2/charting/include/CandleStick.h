#pragma once
#include "ICandleStick.h"
#include "IndicatorTypes.h"

#include <map>
#include <string>

namespace charting {

class CandleStick : public ICandleStick
{
public:
    CandleStick();

    CandleStick(
        uint64_t timestamp, double price_low, double price_high, double price_open, double price_close, double volume);

    CandleStick(std::string product_id, uint64_t timestamp, double price_low, double price_high, double price_open,
        double price_close, double volume);

    virtual void reset() override;

    virtual std::string toString() override;

    std::string product_id;
    uint64_t timestamp;
    double price_low;
    double price_high;
    double price_open;
    double price_close;
    double volume;
};

} // namespace charting