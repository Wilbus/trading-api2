#pragma once
#include "IOrderbook.h"
#include "config.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

#include <mutex>

namespace charting {

using namespace config;

class OrderbookLvl2 : public IOrderbook
{
public:
    OrderbookLvl2()
    {
    }
    OrderbookLvl2(std::string productId);
    OrderbookLvl2(std::shared_ptr<Config> env, std::string productId);
    void updateBid(PricePoint price, Size size) override;
    void updateAsk(PricePoint price, Size size) override;
    void updateBook(PricePoint price, Size size) override;
    size_t getNumOfBids() override;
    size_t getNumOfAsks() override;
    void setCurrTime(std::string timeStr) override;
    std::string getCurrTime() override;
    void setFirstSequence(uint64_t sequence) override;
    void initBook(std::map<PricePoint, Size> bids, std::map<PricePoint, Size> asks) override;
    void printBook() override;

    double getLowestAsk();
    double getHighestBid();

    void setBids(std::map<PricePoint, Size> bidss)
    {
        bids = bidss;
    }

    void setAsks(std::map<PricePoint, Size> askss)
    {
        asks = askss;
    }

    std::map<PricePoint, Size> getBids() const
    {
        return bids;
    }

    std::map<PricePoint, Size> getAsks() const
    {
        return asks;
    }

    double getMidMarketPrice();

    OrderbookLvl2(const OrderbookLvl2& other)
    {
        bids = other.getBids();
        asks = other.getAsks();
    }

    OrderbookLvl2& operator=(const OrderbookLvl2& other)
    {
        /*guard self assignment*/
        if (this == &other)
        {
            return *this;
        }

        bids = other.getBids();
        asks = other.getAsks();
        return *this;
    }

private:
    std::shared_ptr<Config> env;
    std::string productId;
    std::map<PricePoint, Size> bids;
    std::map<PricePoint, Size> asks;
    uint64_t firstSequence{0};
    std::string currTime;
    bool auctionMode; // do we need these??
    bool auction;     // do we need these??
    std::mutex mtx;
};
} // namespace charting