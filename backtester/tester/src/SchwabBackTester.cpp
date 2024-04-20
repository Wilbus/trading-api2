#include "SchwabBackTester.h"
#include "RestClientCurl.h"
#include "SchwabConfigs.h"
#include "Logger.h"

namespace tester
{

using namespace restclient;
using namespace configs;

SchwabBackTester::SchwabBackTester(std::string configsFolder, std::string backtesterLogFolder)
    : configsFolder(configsFolder)
    , backtesterLogFolder(backtesterLogFolder)
{
    logfile = backtesterLogFolder + "tester.log";
    createClient();
    infologprint(logfile, "%s: init", __func__);
}

void SchwabBackTester::createClient()
{
    client = std::make_shared<SchwabClient>(std::make_shared<SchwabConfigs>(configsFolder),
        std::make_shared<RestClientCurl>(backtesterLogFolder, logfile), logfile);
}

void SchwabBackTester::setStrategy(std::shared_ptr<IStrategy> strategy)
{
    this->strategy = strategy;
}

void SchwabBackTester::getSchwabData(std::string fromTime, std::string toTime, std::string symbol)
{
    this->priceHistory = client->getPriceHistory(symbol, PriceHistoryPeriodType::YEAR, 1, PriceHistoryTimeFreq::DAILY, 1,
        fromTime, toTime, false, false);
    infologprint(logfile, "%s: Getting Schwab data for symbol: %s, %lu candles", __func__,
        symbol.c_str(), this->priceHistory.candles.size());
}

void SchwabBackTester::run()
{
    infologprint(logfile, "%s: Running backtester", __func__);
    for(const auto& candle : priceHistory.candles)
    {
        //std::cout << candle.close << "\n";
        CandleStick candleStick(candle.datetime, candle.low, candle.high, candle.open, candle.close, candle.volume);
        auto action = strategy->onBar(candleStick);

        if(action.actionType != ActionType::HOLD)
        {
            infologprint(logfile, "%s: Action: %s", __func__, action.toString().c_str());
        }
    }
}

} // namespace tester