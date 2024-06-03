#include "SchwabDatabank.h"
#include "SchwabDatabaseHandler.h"
#include "RestClientCurl.h"

using namespace database;
using namespace databank;

void pushDataToDb(std::shared_ptr<SchwabDatabank>& databank, std::string symbol)
{
    auto candlesticksDaily = databank->getCandlesFromClient(symbol, Timeframe::DAILY, "2023-06-01", "2024-06-01");
    auto candlesticksThirty = databank->getCandlesFromClient(symbol, Timeframe::THIRTY, "2023-06-01", "2024-06-01");
    auto candlesticksFive = databank->getCandlesFromClient(symbol, Timeframe::FIVE, "2023-06-01", "2024-06-01");
    auto candlesticksMinute = databank->getCandlesFromClient(symbol, Timeframe::MINUTE, "2023-06-01", "2024-06-01");

    for (const auto& candlestick : candlesticksDaily)
    {
        databank->pushCandleToDb(symbol, Timeframe::DAILY, candlestick);
    }

    for (const auto& candlestick : candlesticksThirty)
    {
        databank->pushCandleToDb(symbol, Timeframe::THIRTY, candlestick);
    }

    for (const auto& candlestick : candlesticksFive)
    {
        databank->pushCandleToDb(symbol, Timeframe::FIVE, candlestick);
    }

    for (const auto& candlestick : candlesticksMinute)
    {
        databank->pushCandleToDb(symbol, Timeframe::MINUTE, candlestick);
    }
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    std::shared_ptr<SchwabConfigs> configs =
        std::make_shared<SchwabConfigs>("/home/wilbus/smbshare0/sambashare0/coding/configs/");
    
    auto influxConf = configs->getInfluxConnectionConfig();
    InfluxConnectionInfo influxConnectionInfo = InfluxConnectionInfo{
        influxConf.user, influxConf.pass, influxConf.host, influxConf.dbname, influxConf.authToken};

    std::shared_ptr<ISchwabClient> sClient =
        std::make_shared<SchwabClient>(configs, std::make_shared<RestClientCurl>(), "");

    std::shared_ptr<SchwabDatabank> databank = std::make_shared<SchwabDatabank>(
        sClient, std::make_shared<SchwabDatabaseHandler>(influxConnectionInfo), nullptr);

    auto subConf = configs->getSubscribeConfig();
    for (const auto& symbol : subConf.chartEquities.symbols)
    {
        pushDataToDb(databank, symbol);
    }

}