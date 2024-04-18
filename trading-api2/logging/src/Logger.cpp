#include "Logger.h"

#include "timefuncs.h"

namespace utils {

Logger* Logger::loggerSingleton = nullptr;
std::mutex Logger::mtx;

Logger::Logger(std::string logpath)
    : filewriter(FileWriter(logpath, false, FileExt::TXT, ""))
{
}

Logger::Logger(std::string executableName, std::string logpath)
    : filewriter(FileWriter(logpath, false, FileExt::TXT, ""))
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
    std::lock_guard<std::mutex> lg(mtx);

    char buffer[65536];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);

    std::string message = buildString(true, buffer);

    filewriter.write(message);

    va_end(args);
}

void Logger::error2(bool cout, std::string classname, const char* fmt, ...)
{
    std::lock_guard<std::mutex> lg(mtx);

    char buffer[65536];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);

    std::string classNameAppend = classname + "::" + buffer;
    std::string message = buildString(true, classNameAppend);

    if (cout)
        std::cout << message;
    filewriter.write(message);

    va_end(args);
}

void Logger::log(const char* fmt, ...)
{
    std::lock_guard<std::mutex> lg(mtx);

    char buffer[65536];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);

    std::string message = buildString(false, buffer);

    filewriter.write(message);

    va_end(args);
}

/*SomeClass fmtmessage*/
void Logger::log2(bool cout, std::string classname, const char* fmt, ...)
{
    std::lock_guard<std::mutex> lg(mtx);
    char buffer[65536];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);

    std::string classNameAppend = classname + "::" + buffer;
    std::string message = buildString(false, classNameAppend);
    if (cout)
        std::cout << message;

    filewriter.write(message);

    va_end(args);
}

/*SomeClass fmtmessage*/
void Logger::logprint(std::string classname, const char* fmt, ...)
{
    std::lock_guard<std::mutex> lg(mtx);
    char buffer[65536];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);

    std::string classNameAppend = classname + "::" + buffer;
    std::string message = buildString(false, classNameAppend);

    std::cout << message;
    filewriter.write(message);

    va_end(args);
}

/*SomeClass fmtmessage*/
void Logger::coutprint(std::string classname, const char* fmt, ...)
{
    std::lock_guard<std::mutex> lg(mtx);
    char buffer[65536];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);

    std::string classNameAppend = classname + "::" + buffer;
    std::string message = buildString(false, classNameAppend);

    std::cout << message;

    va_end(args);
}

std::string Logger::buildString(bool err, std::string buffer)
{
    std::thread::id threadId = std::this_thread::get_id();
    std::string message;
    std::stringstream ss;
    ss << threadId << " "
       << "<" << timefuncs::getCurrentLocalTimeStrNs(timefuncs::getLocalTimezone()) << "> ";
    if (err)
    {
        ss << "ERR, ";
    }
    else
    {
        ss << "INFO, ";
    }
    ss << buffer;
    ss << "\n";
    return ss.str();
}
} // namespace utils