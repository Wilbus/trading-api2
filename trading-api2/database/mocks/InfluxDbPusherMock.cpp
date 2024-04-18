#include "InfluxDbPusherMock.h"

#include "InfluxDbPusher.h"

namespace database {

InfluxDbPusher::InfluxDbPusher(std::string dbname, unsigned batchSize, std::string logfile)
{
    (void)dbname;
    (void)batchSize;
    (void)logfile;
}

InfluxDbPusher::~InfluxDbPusher()
{
}

void InfluxDbPusher::setBatchSize(unsigned size)
{
    return mocks::InfluxDbPusherMock::inst().setBatchSize(size);
}

void InfluxDbPusher::flushBatch()
{
    return mocks::InfluxDbPusherMock::inst().flushBatch();
}

void InfluxDbPusher::pushRaw(const std::string& pointName, const FieldValueMap& valueMap)
{
    return mocks::InfluxDbPusherMock::inst().pushRaw(pointName, valueMap);
}

void InfluxDbPusher::pushRaw(const int64_t& timestamp, const std::string& pointName, const FieldValueMap& valueMap)
{
    return mocks::InfluxDbPusherMock::inst().pushRaw(timestamp, pointName, valueMap);
}

std::vector<FieldValueMap> InfluxDbPusher::pullRaw(
    const std::string& pointName, const std::string& fromTime, const std::string& toTime)
{
    return mocks::InfluxDbPusherMock::inst().pullRaw(pointName, fromTime, toTime);
}

namespace mocks {
InfluxDbPusherMock::InfluxDbPusherMock()
{
}

InfluxDbPusherMock::~InfluxDbPusherMock()
{
}

InfluxDbPusherMock& InfluxDbPusherMock::inst()
{
    static std::unique_ptr<InfluxDbPusherMock> mockPtr(new InfluxDbPusherMock());
    return *(mockPtr).get();
}
} // namespace mocks
} // namespace database