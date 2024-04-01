#include "SystemTimer.h"

namespace utils
{
system_clock::time_point now()
{
    return std::chrono::system_clock::now();
}
}