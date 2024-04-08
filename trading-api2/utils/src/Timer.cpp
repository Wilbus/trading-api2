#include "Timer.h"

namespace utils {

Timer::Timer(size_t waitMs, std::function<void(void)>& callback)
{
    this->waitMs = std::chrono::milliseconds(waitMs);
    this->callback = callback;
}
} // namespace utils