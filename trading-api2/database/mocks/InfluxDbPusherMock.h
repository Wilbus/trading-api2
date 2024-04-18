#pragma once

#include "InfluxDbPusher.h"

#include <gmock/gmock.h>

namespace database {
namespace mocks {

class InfluxDbPusherMock
{
public:
    InfluxDbPusherMock();
    ~InfluxDbPusherMock();

    MOCK_METHOD1(setBatchSize, void(unsigned size));
    MOCK_METHOD0(flushBatch, void());
    MOCK_METHOD2(pushRaw, void(const std::string& pointName, const FieldValueMap& valueMap));
    MOCK_METHOD3(pushRaw, void(time_t timestamp, const std::string& pointName, const FieldValueMap& valueMap));
    MOCK_METHOD3(pullRaw, std::vector<FieldValueMap>(
                              const std::string& pointName, const std::string& fromTime, const std::string& toTime));

    static InfluxDbPusherMock& inst();
};

} // namespace mocks
} // namespace database