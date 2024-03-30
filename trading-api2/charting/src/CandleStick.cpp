#include "CandleStick.h"

namespace charting {

const std::string typeString = "match";

CandleStick::CandleStick()
    : timestamp(0)
    , price_low(5000000)
    , price_high(-5000000)
    , price_open(0)
    , price_close(0)
    , volume(0)
{
}

CandleStick::CandleStick(
    uint64_t timestamp, double price_low, double price_high, double price_open, double price_close, double volume)
    : timestamp(timestamp)
    , price_low(price_low)
    , price_high(price_high)
    , price_open(price_open)
    , price_close(price_close)
    , volume(volume)
{
}

CandleStick::CandleStick(std::string product_id, uint64_t timestamp, double price_low, double price_high,
    double price_open, double price_close, double volume)
    : product_id(product_id)
    , timestamp(timestamp)
    , price_low(price_low)
    , price_high(price_high)
    , price_open(price_open)
    , price_close(price_close)
    , volume(volume)
{
}

void CandleStick::reset()
{
    timestamp = 0;
    price_low = 5000000;
    price_open = 0;
    price_close = 0;
    price_high = -5000000;
    volume = 0;
}

std::string CandleStick::toString()
{
    std::string out;
    char buffer[512];
    std::snprintf(buffer, 512,
        "CANDLESTICK - Timestamp: %lu, O: %.02f, H: %.02f, L: "
        "%.02f, C: %.02f, V: %.09f",
        timestamp, price_open, price_high, price_low, price_close, volume);
    return buffer;
}

} // namespace charting