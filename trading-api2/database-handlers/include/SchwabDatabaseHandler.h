#pragma once

#include "IDatabaseHandler.h"
#include "InfluxDbPusher.h"

#include <memory>

namespace databasehandlers {
using namespace database;

class SchwabDatabaseHandler : public IDatabaseHandler
{
public:
    SchwabDatabaseHandler(const InfluxConnectionInfo& connInfo, const std::string& logfile = "");
    ~SchwabDatabaseHandler();

    virtual void pushCandle(const std::string& symbol, const CandleStick& candle) override;
    virtual std::vector<CandleStick> getCandles(
        const std::string& symbol, const std::string& fromTime, const std::string& toTime) override;

    virtual void pushJsonData(const std::string& data) override;
    virtual std::vector<std::string> getJsonData(const std::string& fromTime, const std::string& toTime) override;

private:
    std::string logfile;
    std::unique_ptr<InfluxDbPusher> influxDbPusher;
    const std::string jsonPointName = "json_data";
    const std::string jsonFieldName = "jsonfield";
};
} // namespace databasehandlers