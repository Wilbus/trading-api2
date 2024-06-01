#include "ChartsAggregator.h"
#include "SchwabDatabaseHandler.h"

#include <gtest/gtest.h>

using namespace databank;
using namespace databasehandlers;

class AggregateDBCandlesTest : public ::testing::Test
{
public:
    AggregateDBCandlesTest()
    {
        chartsAggregator = std::make_shared<ChartsAggregator>();
        schwabDatabaseHandler = std::make_shared<SchwabDatabaseHandler>(
            InfluxConnectionInfo{"devtesterv1", "123456789", "192.168.0.130:8086", "dev-testing-v1",
                "N-q3KQNK6HEmUqj2bDwflK_08BQINRLTLlGsZhBrjQyFIQjVAK9AgCZtDjPEHD7IF7AWh20PPhgwAOaSXxyswQ=="});
    }

    void SetUp() override
    {
    }

protected:
    std::shared_ptr<ChartsAggregator> chartsAggregator;
    std::shared_ptr<SchwabDatabaseHandler> schwabDatabaseHandler;
};

TEST_F(AggregateDBCandlesTest, aggregateCandlesFromDBTest)
{
    std::string fromtime = "2024-05-31 00:00:00";
    std::string totime = "2024-06-01 00:00:00";
    std::set<std::string> symbolSet = {"AAPL", "AMD", "AMZN", "BAC", "COIN", "COST", "CPB", "DAL", "DELL", "KR", "MARA",
        "MSFT", "MU", "NVDA", "ORCL", "OXY", "PYPL", "QQQ", "SNAP", "SPY", "SQ", "TGT", "TSM", "WMT", "XOM"};

    for (auto symbol : symbolSet)
    {
        std::vector<CandleStick> candles = schwabDatabaseHandler->getCandles(symbol, fromtime, totime);

        for (auto candle : candles)
        {
            chartsAggregator->addMinuteCandle(symbol, candle);
        }

        std::cout << "minutes\n";
        for (size_t i = 0; i < 10; i++)
        {
            std::cout << chartsAggregator->getChartData(symbol, MINUTE).getMultiCandles().at(i).toString() << std::endl;
        }

        std::cout << "fives\n";
        for (size_t i = 0; i < 10; i++)
        {
            std::cout << chartsAggregator->getChartData(symbol, FIVE).getMultiCandles().at(i).toString() << std::endl;
        }

        std::cout << "fifteens\n";
        for (size_t i = 0; i < 10; i++)
        {
            std::cout << chartsAggregator->getChartData(symbol, FIFTEEN).getMultiCandles().at(i).toString()
                      << std::endl;
        }

        std::cout << "thirty\n";
        for (size_t i = 0; i < 13; i++)
        {
            std::cout << chartsAggregator->getChartData(symbol, THIRTY).getMultiCandles().at(i).toString() << std::endl;
        }

        std::cout << "hourly\n";
        for (size_t i = 0; i < chartsAggregator->getChartData(symbol, HOURLY).getSize(); i++)
        {
            std::cout << chartsAggregator->getChartData(symbol, HOURLY).getMultiCandles().at(i).toString() << std::endl;
        }
    }
}