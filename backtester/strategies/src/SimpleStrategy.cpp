#include "SimpleStrategy.h"

namespace strategy
{
SimpleStrategy::SimpleStrategy()
{
    
}

void SimpleStrategy::setAccountBalance(double balance)
{
    this->accountBalance = balance;
}

double SimpleStrategy::getAccountBalance()
{
    return this->accountBalance;
}

Action SimpleStrategy::onBar(CandleStick candle)
{
    updateChartData(candle);

    Action action;
    if(chartData.getSize() < 5)
    {
        action.actionType = ActionType::HOLD;
        return action;
    }

    auto currBar = chartData.getBack(0);
    if(currBar.price_close > currBar.getIndByName("SMA5").value && !inPosition)
    {
        inPosition = true;
        action.actionType = ActionType::BUY;
        action.price = currBar.price_close;
        action.quantity = 1;
        return action;
    }
    else if(currBar.price_close < currBar.getIndByName("SMA5").value && inPosition)
    {
        inPosition = false;
        action.actionType = ActionType::SELL;
        action.price = currBar.price_close;
        action.quantity = 1;
        return action;
    }
    else
    {
        action.actionType = ActionType::HOLD;
        return action;
    }
}

void SimpleStrategy::updateChartData(CandleStick candle)
{
    MultiCandle mcandle(candle);

    if(chartData.getSize() == 0)
    {
        chartData.addMultiCandle(mcandle);

        chartData.addIndicator(IndicatorType{"SMA5", IndicatorTypes::SMA, {"5"}});
        return;
    }

    chartData.addMultiCandle(mcandle);
}

} // namespace strategy