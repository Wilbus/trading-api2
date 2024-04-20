#include "IStrategy.h"
#include "ChartData3.h"

namespace strategy
{
using namespace charting;
class SimpleStrategy : public IStrategy
{
public:
    SimpleStrategy();
    void setAccountBalance(double balance) override;
    double getAccountBalance() override;
    Action onBar(CandleStick candle) override;

private:
    void updateChartData(CandleStick candle);

    ChartData3 chartData;
    double accountBalance{0.0};

    bool inPosition{false};
};
}