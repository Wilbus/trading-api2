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
    if(loggerSingleton == nullptr)
    {
        loggerSingleton = new Logger(logFilePath);
    }
    return loggerSingleton;
}

std::string Logger::buildString(bool err, std::string buffer)
{
    std::thread::id threadId = std::this_thread::get_id();
    std::string message;
    std::stringstream ss;
    ss << threadId << " "
       << "<" << timefuncs::getCurrentLocalTimeStrNs(-6) << "> ";
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