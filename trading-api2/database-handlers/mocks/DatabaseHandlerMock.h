#pragma once

#include "IDatabaseHandler.h"

#include <gmock/gmock.h>

namespace databasehandlers {
namespace mocks {
class DatabaseHandlerMock : public IDatabaseHandler
{
public:
    MOCK_METHOD2(pushCandle, void(const std::string& symbol, const CandleStick& candle));
    MOCK_METHOD3(getCandles,
        std::vector<CandleStick>(const std::string& symbol, const std::string& fromTime, const std::string& toTime));

    MOCK_METHOD1(pushJsonData, void(const std::string& data));
    MOCK_METHOD2(getJsonData, std::vector<std::string>(const std::string& fromTime, const std::string& toTime));
};
} // namespace mocks
} // namespace databasehandlers
