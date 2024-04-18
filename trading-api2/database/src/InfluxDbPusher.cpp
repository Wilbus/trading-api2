#include "InfluxDbPusher.h"

#include "Logger.h"
#include "SystemTimer.h"
#include "timefuncs.h"

namespace database {
InfluxDbPusher::InfluxDbPusher(std::string dbname, unsigned batchSize, std::string logfile)
    : logfile(logfile)
{
    try
    {
        std::string getstring = "http://localhost:8086?db=" + dbname;
        // infolog(logger, "%s() connecting to %s", __func__, getstring.c_str());
        db = influxdb::InfluxDBFactory::Get(getstring.c_str());
        db->createDatabaseIfNotExists();
        db->batchOf(batchSize);
    }
    catch (const std::exception& e)
    {
        errorlogprint(logfile, "%s InfluxDbPusher wasn't initialized! Exception caught: %s", __func__, e.what());
    }
}

InfluxDbPusher::~InfluxDbPusher()
{
    db->flushBatch();
}

void InfluxDbPusher::setBatchSize(unsigned batchSize)
{
    db->batchOf(batchSize);
}

void InfluxDbPusher::flushBatch()
{
    db->flushBatch();
}

void InfluxDbPusher::pushRaw(const std::string& pointName, const FieldValueMap& valueMap)
{
    auto currTimeMs = utils::nowMs();
    std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp{
        std::chrono::milliseconds{currTimeMs}};

    auto point = influxdb::Point{pointName}.setTimestamp(tp);
    for (const auto& [key, value] : valueMap)
    {
        point.addField(key, value);
    }

    db->write(std::move(point));
}

void InfluxDbPusher::pushRaw(const int64_t& timestamp, const std::string& pointName, const FieldValueMap& valueMap)
{
    std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp{
        std::chrono::milliseconds{timestamp}};

    auto point = influxdb::Point{pointName}.setTimestamp(tp);
    for (const auto& [key, value] : valueMap)
    {
        point.addField(key, value);
    }

    db->write(std::move(point));
}

// db->query("SELECT * FROM full where time > '2023-11-13
//  19:00:00' and time < '2023-11-13 19:00:01'"))
/*All numeric values in fieldSet are returned as doubles*/
/*All values in the tagSet are strings*/
std::vector<FieldValueMap> InfluxDbPusher::pullRaw(
    const std::string& pointName, const std::string& fromTime, const std::string& toTime)
{
    std::vector<FieldValueMap> temp;
    std::string queryString =
        "SELECT * FROM " + pointName + " WHERE time >= '" + fromTime + "' AND time <= '" + toTime + "'";

    // std::cout << queryString << std::endl;
    auto result = db->query(queryString);
    for (const auto& res : result)
    {
        FieldValueMap fieldsMap;
        const auto fieldSet = res.getFieldSet();
        for (const auto& fieldpair : fieldSet)
        {
            fieldsMap[fieldpair.first] = fieldpair.second;
        }

        const auto tagSet = res.getTagSet();
        for (const auto& tag : tagSet)
        {
            fieldsMap[tag.first] = tag.second;
        }
        temp.push_back(fieldsMap);
    }

    return temp;
}

} // namespace database