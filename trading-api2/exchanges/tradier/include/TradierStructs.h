#pragma once

#include <string>

namespace tradierstructs {

struct AccessToken
{
    std::string access_token;
    uint64_t expires_in;
    std::string issued_at;
};

/*The quote event is issued when a viable quote has been created an exchange.
This represents the most current bid/ask pricing available.*/

struct Quote
{
    std::string symbol;
    double bid;
    uint64_t bidsz;
    std::string bidexch;
    uint64_t biddate;
    double ask;
    uint64_t asksz;
    std::string askexch;
    uint64_t askdate;
};

/*The trade event is sent for all trade events at exchanges.
By default, the trade event is filtered to only include valid
ticks (removing trade corrections, errors, etc).*/

struct Trade
{
    std::string symbol;
    std::string exch;
    double price;
    uint64_t size;
    uint64_t cvol;
    uint64_t date;
    double last;
};

/*The summary event is triggered when a market session high,
low, open, or close event is triggered.*/

struct Summary
{
    std::string symbol;
    double open;
    double high;
    double low;
    double prevClose;
};

/*Time and Sale represents a trade or other market event with price,
like market open/close price, etc. Time and Sales are intended to provide
information about trades in a continuous time slice (unlike Trade events
which are supposed to provide snapshot about the current last trade).
Timesale events are uniquely sequenced.*/

struct TimeSale
{
    std::string symbol;
    std::string exch;
    double bid;
    double ask;
    double last;
    uint64_t size;
    uint64_t date;
    uint64_t seq;
    std::string flag;
    bool cancel;
    bool correction;
    std::string session;
};

/*The trade event is sent for all trade events at exchanges.
This payload has more accurate information during the pre/post market sessions.
If you plan streaming market data during these sessions, you should use this payload
over the trade payload.*/

struct Tradex
{
    std::string symbol;
    std::string exch;
    double price;
    uint64_t size;
    uint64_t cvol;
    uint64_t date;
    double last;
};

}; // namespace tradierstructs