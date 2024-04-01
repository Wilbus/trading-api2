#include "SystemTimerMock.h"
#include "SystemTimer.h"
#include <memory>

namespace utils
{

system_clock::time_point now()
{
    return utils::mocks::SystemTimerMock::inst().now();
}

namespace mocks
{

SystemTimerMock::SystemTimerMock()
{

}

SystemTimerMock::~SystemTimerMock()
{

}

SystemTimerMock& SystemTimerMock::inst()
{
    static std::unique_ptr<SystemTimerMock> mockPtr(new SystemTimerMock());
    return *(mockPtr).get();
}

}
}