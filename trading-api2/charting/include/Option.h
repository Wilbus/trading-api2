#pragma once
#include <string>

namespace charting {

class Option
{
public:
    std::string symbol;
    std::string underlying;
    std::string description;
    std::string option_type;

    double volume;
    double last;
    double change;
    double open;
    double high;
    double low;
    double close;
    double bid;
    double ask;
    double strike;

    // greeks
    double delta;
    double gamma;
    double theta;
    double vega;
    double rho;
    double phi;
    double bid_iv;
    double mid_iv;
    double ask_iv;
    double smv_vol;
    uint64_t updated_at;

    double average_volume;
    double week_52_high;
    double week_52_low;
    double open_interest;
    double contract_size;

    uint64_t expiration_date;
};
} // namespace charting