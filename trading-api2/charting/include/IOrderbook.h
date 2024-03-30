#pragma once

#include "globalvars.h"

#include <map>
#include <string>

namespace charting {

typedef double PricePoint;
typedef double Size;
typedef uint64_t NumOrders;

#if 0
enum UpdateType
{
    Open, //The order is now open on the order book.
    Done, //The order is no longer on the order book.
    Received,
    Change,
}

enum ReceivedType
{
    Limit,
    Market
}

/*
A done message is sent for received orders that are fully filled or canceled due to self-trade prevention.
There are no open messages for such orders. 
done messages for orders that are not on the book should be ignored when maintaining a real-time order book.
*/
enum DoneReason
{

}
#endif

class IOrderbook
{
public:
    virtual void updateBid(PricePoint price, Size size) = 0;
    virtual void updateAsk(PricePoint price, Size size) = 0;
    virtual void updateBook(PricePoint price, Size size) = 0;
    virtual size_t getNumOfBids() = 0;
    virtual size_t getNumOfAsks() = 0;
    virtual void setCurrTime(std::string timeStr) = 0;
    virtual std::string getCurrTime() = 0;
    virtual void setFirstSequence(uint64_t sequence) = 0;
    virtual void initBook(std::map<PricePoint, Size> bids, std::map<PricePoint, Size> asks) = 0;
    virtual void printBook() = 0;
};
} // namespace charting