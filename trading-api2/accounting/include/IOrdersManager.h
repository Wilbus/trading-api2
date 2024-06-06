#pragma once

#include <string>
namespace accounting
{

enum OrderType
{
    MARKET,
    LIMIT,
    STOP,
    STOP_LIMIT
};

enum OrderAction
{
    BUY,
    SELL
};

class IOrdersManager
{
public:
    virtual ~IOrdersManager() = default;

    virtual void handleOrderStatusUpdates() = 0;
    virtual void placeLimitOrder(const std::string& accountNumber, const OrderAction& action, const std::string& symbol, double quantity, double price) = 0;
    virtual void placeMktOrder(const std::string& accountNumber, const OrderAction& action, const std::string& symbol, double quantitye) = 0;
};
}