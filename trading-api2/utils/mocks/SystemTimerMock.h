#pragma once

#include "SystemTimer.h"

#include <gmock/gmock.h>

namespace utils {
namespace mocks {

class SystemTimerMock
{
public:
    SystemTimerMock();
    ~SystemTimerMock();
    MOCK_METHOD0(now, system_clock::time_point());
    MOCK_METHOD0(nowMs, time_t());

    static SystemTimerMock& inst();
};

} // namespace mocks
} // namespace utils