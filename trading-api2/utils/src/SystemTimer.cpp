#include "SystemTimer.h"

namespace utils
{
system_clock::time_point now()
{
    return std::chrono::system_clock::now();
}

time_t nowMs()
{
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto epoch = now_ms.time_since_epoch();
    return epoch.count();
}

}