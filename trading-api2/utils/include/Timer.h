#pragma once

#include <chrono>
#include <condition_variable>
#include <functional>
#include <thread>

namespace utils {
// https://stackoverflow.com/questions/41152393/c-non-blocking-async-timer
class Timer
{
public:
    Timer(size_t waitMs, std::function<void(void)>& callback);

protected:
    void wait_then_call()
    {
        std::unique_lock<std::mutex> lk(cv_m);
        cv.wait_for(lk, waitMs);

        callback();
    }

    std::chrono::milliseconds waitMs;
    std::function<void(void)> callback;
    std::thread waitThread{[this] { wait_then_call(); }};
    std::condition_variable cv;
    std::mutex cv_m;
};
} // namespace utils