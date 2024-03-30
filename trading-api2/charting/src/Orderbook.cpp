#include "Orderbook.h"

#include <iostream>

namespace charting {

OrderbookLvl2::OrderbookLvl2(std::string productId)
    : productId(productId)
{
}

OrderbookLvl2::OrderbookLvl2(std::shared_ptr<Config> env, std::string productId)
    : env(env)
    , productId(productId)
{
}

void OrderbookLvl2::printBook()
{
    std::lock_guard<std::mutex> lg(mtx);
    std::printf("BIDS\n");
    for (auto& bid : bids)
    {
        std::printf("BID %.02f, %.02f\n", bid.first, bid.second);
    }
    for (auto& ask : asks)
    {
        std::printf("ASK %.02f, %.02f\n", ask.first, ask.second);
    }

    // PricePoint highestBid;
    // PricePoint lowestAsk;
    // highestBid = (--bids.end())->first;
    // lowestAsk = (asks.begin())->first;

    // std::printf("Starting highestBid: %.02f, lowestAsk: %.02f\n", highestBid,
    // lowestAsk);
}

double OrderbookLvl2::getLowestAsk()
{
    return (asks.begin())->first;
}
double OrderbookLvl2::getHighestBid()
{
    return (--bids.end())->first;
}

double OrderbookLvl2::getMidMarketPrice()
{
    std::lock_guard<std::mutex> lg(mtx);
    PricePoint highestBid;
    PricePoint lowestAsk;
    if (bids.size() == 0 || asks.size() == 0)
    {
        printf("Error: orderbook bids or asks is empty\n");
        return 0;
    }

    highestBid = (--bids.end())->first;
    lowestAsk = (asks.begin())->first;

    // std::printf("bids size: %lu asks size: %lu\n", bids.size(), asks.size());
    // std::printf("highestBid: %.02f, lowestAsk: %.02f\n", highestBid,
    // lowestAsk);

    return (highestBid + lowestAsk) / 2;
}

// TODO TOP: investigate why alot of prices that dont exist in book?
void OrderbookLvl2::updateBid(PricePoint price, Size size)
{
    std::lock_guard<std::mutex> lg(mtx);
    if (size == 0)
    {
        auto bidsItr = bids.find(price);
        if (bidsItr != bids.end())
        {
            // std::cout << "erased price bid: " << price << "\n";
            bids.erase(bidsItr->first);
        }
        return;
        // DLOG(ERROR) << "price point in bids not found for: " << price << ", " <<
        // size.sizeStr;
    }
    // std::printf("updated price bid %s: with size %s\n", price.c_str(),
    // size.sizeStr.c_str());
    bids[price] = size;
}

void OrderbookLvl2::updateAsk(PricePoint price, Size size)
{
    std::lock_guard<std::mutex> lg(mtx);
    if (size == 0)
    {
        auto asksItr = asks.find(price);
        if (asksItr != asks.end())
        {
            // std::cout << "erased price ask: " << price << "\n";
            asks.erase(asksItr->first);
        }
        return;
        // DLOG(ERROR) << "price point in asks not found for: " << price << ", " <<
        // size.sizeStr;
    }
    // std::printf("updated price ask %s: with size %s\n", price.c_str(),
    // size.sizeStr.c_str());
    asks[price] = size;
}

size_t OrderbookLvl2::getNumOfBids()
{
    std::lock_guard<std::mutex> lg(mtx);
    return bids.size();
}

size_t OrderbookLvl2::getNumOfAsks()
{
    std::lock_guard<std::mutex> lg(mtx);
    return asks.size();
}

void OrderbookLvl2::setFirstSequence(uint64_t sequence)
{
    std::lock_guard<std::mutex> lg(mtx);
    firstSequence = sequence;
}

void OrderbookLvl2::setCurrTime(std::string timeStr)
{
    std::lock_guard<std::mutex> lg(mtx);
    currTime = timeStr;
}

std::string OrderbookLvl2::getCurrTime()
{
    std::lock_guard<std::mutex> lg(mtx);
    return currTime;
}

void OrderbookLvl2::updateBook(PricePoint price, Size size)
{
    (void)size;
    (void)price;
    std::lock_guard<std::mutex> lg(mtx);
    /*for (const auto& bid : bids)
    {
    }
    for (const auto& ask : asks)
    {
    }*/
}

void OrderbookLvl2::initBook(std::map<PricePoint, Size> newbids, std::map<PricePoint, Size> newasks)
{
    std::lock_guard<std::mutex> lg(mtx);
    bids = newbids;
    asks = newasks;
}

} // namespace charting