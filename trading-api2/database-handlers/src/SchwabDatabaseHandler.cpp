#include "SchwabDatabaseHandler.h"

#include "Logger.h"

namespace databasehandlers {
SchwabDatabaseHandler::SchwabDatabaseHandler(const std::string& dbname, const std::string& logfile)
    : logfile(logfile)
    , influxDbPusher(new InfluxDbPusher(dbname, 1, logfile))
{
    infologprint(logfile, "%s", __func__);
}

SchwabDatabaseHandler::~SchwabDatabaseHandler()
{
}

void SchwabDatabaseHandler::pushCandle(const std::string& symbol, const CandleStick& candle)
{
    try
    {
        FieldValueMap valueMap;
        valueMap["open"] = candle.price_open;
        valueMap["high"] = candle.price_high;
        valueMap["low"] = candle.price_low;
        valueMap["close"] = candle.price_close;
        valueMap["volume"] = candle.volume;
        valueMap["timestamp"] =
            static_cast<double>(candle.timestamp); // InfluxDB does not support pushing uint64_t for some reason
        influxDbPusher->pushRaw(static_cast<int64_t>(candle.timestamp), symbol, valueMap);
        infologprint(logfile, "%s: pushed candle for symbol: %s", __func__, symbol.c_str());
    }
    catch (const std::exception& e)
    {
        errorlogprint(logfile, "%s Exception caught: %s", __func__, e.what());
    }
}

std::vector<CandleStick> SchwabDatabaseHandler::getCandles(
    const std::string& symbol, const std::string& fromTime, const std::string& toTime)
{
    try
    {
        auto valueMap = influxDbPusher->pullRaw(symbol, fromTime, toTime);
        std::vector<CandleStick> candles;
        for (const auto& map : valueMap)
        {
            /*All numeric values in fieldSet are returned as doubles*/
            /*All values in the tagSet are strings*/
            CandleStick candle;
            candle.price_open = std::get<double>(map.at("open"));
            candle.price_high = std::get<double>(map.at("high"));
            candle.price_low = std::get<double>(map.at("low"));
            candle.price_close = std::get<double>(map.at("close"));
            candle.volume = std::get<double>(map.at("volume"));
            candle.timestamp = static_cast<uint64_t>(std::get<double>(map.at("timestamp")));
            candles.push_back(candle);
        }
        infologprint(logfile, "%s: retrieved %lu candles for symbol: %s", __func__, candles.size(), symbol.c_str());
        return candles;
    }
    catch (const std::exception& e)
    {
        errorlogprint(logfile, "%s Exception caught: %s", __func__, e.what());
        return {};
    }
}

void SchwabDatabaseHandler::pushJsonData(const std::string& data)
{
    try
    {
        FieldValueMap valueMap;
        valueMap["jsonfield"] = data;
        influxDbPusher->pushRaw(jsonPointName, valueMap);
    }
    catch (const std::exception& e)
    {
        errorlogprint(logfile, "%s Exception caught: %s", __func__, e.what());
    }
}

std::vector<std::string> SchwabDatabaseHandler::getJsonData(const std::string& fromTime, const std::string& toTime)
{
    try
    {
        auto valueMap = influxDbPusher->pullRaw(jsonPointName, fromTime, toTime);
        std::vector<std::string> jsonData;
        for (const auto& map : valueMap)
        {
            jsonData.push_back(std::get<std::string>(map.at(jsonFieldName)));
        }
        infologprint(logfile, "%s: retrieved %lu json data points", __func__, jsonData.size());
        return jsonData;
    }
    catch (const std::exception& e)
    {
        errorlogprint(logfile, "%s Exception caught: %s", __func__, e.what());
        return {};
    }
}

} // namespace databasehandlers