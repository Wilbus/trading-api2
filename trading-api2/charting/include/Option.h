#pragma once
#include <map>
#include <stdexcept>
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
    double bidSize;
    double askSize;
    double strike;
    double volatility;

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

class OptionPair
{
public:
    OptionPair() = default;
    OptionPair(Option call, Option put)
        : call(call)
        , put(put)
    {
        if (call.strike != put.strike)
        {
            throw std::invalid_argument("Call and put strikes must be equal");
        }
    }

    OptionPair(Option putOrCall)
    {
        if (putOrCall.option_type == "put")
        {
            put = putOrCall;
        }
        else if (putOrCall.option_type == "call")
        {
            call = putOrCall;
        }
        else
        {
            throw std::invalid_argument("Option type must be put or call");
        }
    }

    Option putOption() const
    {
        return put;
    }

    Option callOption() const
    {
        return call;
    }

    void setPut(const Option& put)
    {
        if (put.strike != this->call.strike)
        {
            throw std::invalid_argument("Put strike must be equal to call strike");
        }
        this->put = put;
    }

    void setCall(const Option& call)
    {
        if (call.strike != this->put.strike)
        {
            throw std::invalid_argument("Call strike must be equal to put strike");
        }
        this->call = call;
    }

private:
    Option call;
    Option put;
};

typedef std::map<std::string, std::map<double, OptionPair>> OptionChain;

} // namespace charting