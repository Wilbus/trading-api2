#include "Logger.h"

namespace utils {
Logger::Logger(std::string logpath)
{
    (void)logpath;
}

Logger::Logger(std::string executableName, std::string logpath)
{
    (void)executableName;
}

Logger* Logger::loggerInst(std::string logFilePath)
{
    std::lock_guard<std::mutex> lg(mtx);
    if (loggerSingleton == nullptr)
    {
        loggerSingleton = new Logger(logFilePath);
    }
    return loggerSingleton;
}

void Logger::error(const char* fmt, ...)
{
    (void)fmt;
}

void Logger::error2(bool cout, std::string classname, const char* fmt, ...)
{
    (void)cout;
    (void)classname;
    (void)fmt;
}

void Logger::log(const char* fmt, ...)
{
    (void)fmt;
}

/*SomeClass fmtmessage*/
void Logger::log2(bool cout, std::string classname, const char* fmt, ...)
{
    (void)cout;
    (void)classname;
    (void)fmt;
}

/*SomeClass fmtmessage*/
void Logger::logprint(std::string classname, const char* fmt, ...)
{
    (void)classname;
    (void)fmt;
}

/*SomeClass fmtmessage*/
void Logger::coutprint(std::string classname, const char* fmt, ...)
{
    (void)classname;
    (void)fmt;
}

std::string Logger::buildString(bool err, std::string buffer)
{
    (void)err;
    (void)buffer;   
}
} // namespace utils