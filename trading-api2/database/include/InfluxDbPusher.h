#pragma once

#include <InfluxDBFactory.h>
#include <InfluxDBBuilder.h>
#include <Logger.h>
#include <unordered_map>

namespace database {

using namespace std::chrono_literals;

using Clock = std::chrono::high_resolution_clock;
using Ms = std::chrono::milliseconds;
using Sec = std::chrono::seconds;
using Ns = std::chrono::nanoseconds;

template <class Duration>
using TimePoint = std::chrono::time_point<Clock, Duration>;

/*
-Dbname is the name of the database to connect to
-PointName is the name of the measurement
-Each pointName can have multiple fields of different types
Dbname
    PointName[0..n]
        - FieldName1: FieldValue1
        - FieldName2: FieldValue2
        - ..etc
        - timestamp: timestamp
    AnotherPointName[0..n]
        - FieldName1: FieldValue1
        - FieldName2: FieldValue2
        - ..etc
        - timestamp: timestamp
    ..etc
*/

struct InfluxConnectionInfo
{
    std::string user;
    std::string pass;
    std::string host;
    std::string dbname;
    std::string authToken;
};

typedef std::unordered_map<std::string, influxdb::Point::FieldValue>
    // std::variant<int, long long int, std::string, double, bool, unsigned int, unsigned long long int>>
    FieldValueMap;

class InfluxDbPusher
{
public:
    InfluxDbPusher(std::string dbname, unsigned batchSize = 100, std::string logfile = "");
    // as of 5/29/2024 we are now using influxdb 2.0
    InfluxDbPusher(std::string user, std::string pass, std::string host, std::string dbname, std::string authToken, unsigned batchSize = 100, std::string logfile = "");

    void setBatchSize(unsigned size);

    void flushBatch();

    ~InfluxDbPusher();

    void pushRaw(const std::string& pointName, const FieldValueMap& valueMap);

    void pushRaw(const int64_t& timestamp, const std::string& pointName, const FieldValueMap& valueMap);

    std::vector<FieldValueMap> pullRaw(
        const std::string& pointName, const std::string& fromTime, const std::string& toTime);

private:
    std::string buildConnectionURI(std::string user, std::string pass, std::string host, std::string dbname)
    {
        std::string uri = "http://" + user + ":" + pass + "@" + host + "?db=" + dbname;
        std::cout << uri << "\n";
        return uri;
    }

    std::unique_ptr<influxdb::InfluxDB> db;
    std::string logfile;
};
} // namespace database