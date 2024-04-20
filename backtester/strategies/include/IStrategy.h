#pragma once
#include "CandleStick.h"

namespace strategy
{
using namespace charting;
enum ActionType
{
    BUY,
    SELL,
    HOLD //can also mean do nothing
};

struct Action
{
    ActionType actionType;
    double price{-1};
    double quantity{-1};
    std::string symbol;
    std::string time;

    std::string toString()
    {
        char buffer[1024];
        std::string actionString;
        switch(actionType)
        {
            case ActionType::BUY:
                actionString = "BUY";
                snprintf(buffer, sizeof(buffer), "Action: %s, Price: %.02f, Quantity: %.02f, Symbol: %s, Time: %s",
                    actionString.c_str(), price, quantity, symbol.c_str(), time.c_str());
                break;
            case ActionType::SELL:
                actionString = "SELL";
                snprintf(buffer, sizeof(buffer), "Action: %s, Price: %.02f, Quantity: %.02f, Symbol: %s, Time: %s",
                    actionString.c_str(), price, quantity, symbol.c_str(), time.c_str());
                break;
            case ActionType::HOLD:
                actionString = "HOLD";
                snprintf(buffer, sizeof(buffer), "Action: %s, Symbol: %s, Time: %s",
                    actionString.c_str(), symbol.c_str(), time.c_str());
                break;
        }
    
        return std::string(buffer);
    }
};

enum Periods
{
    M1,
    M5,
    M15,
    M30,
    H1,
    H4,
    D1,
    W1,
    MN1

};

class IStrategy
{
public:
    virtual void setAccountBalance(double balance) = 0;
    virtual double getAccountBalance() = 0;
    virtual Action onBar(CandleStick candle) = 0;
};
}