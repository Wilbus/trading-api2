#pragma once

#include "FileWriter.hpp"

#include <iostream>
#include <mutex>
#include <stdarg.h>
#include <stdio.h>
#include <thread>

// there are probably more clever ways to include class name in logging. but seems to work well so far
#if 0
#define basiclog(loggername, msg, ...) loggername->log(msg __VA_OPT__(, ) __VA_ARGS__)
#define coutlog(loggername, msg, ...) loggername->coutprint(typeid(this).name(), msg __VA_OPT__(, ) __VA_ARGS__)
#define infolog(loggername, msg, ...) loggername->log2(false, typeid(this).name(), msg __VA_OPT__(, ) __VA_ARGS__)
#define infologprint(loggername, msg, ...) loggername->log2(true, typeid(this).name(), msg __VA_OPT__(, ) __VA_ARGS__)

#define errorlog(loggername, msg, ...) loggername->error2(false, typeid(this).name(), msg __VA_OPT__(, ) __VA_ARGS__)
#define errorlogprint(loggername, msg, ...) \
    loggername->error2(true, typeid(this).name(), msg __VA_OPT__(, ) __VA_ARGS__)
#endif

namespace utils {

#define infologprint(filepath, msg, ...) \
    utils::Logger::loggerInst(filepath)->log2(true, typeid(this).name(), msg __VA_OPT__(, ) __VA_ARGS__)

class Logger
{
protected:
    Logger(std::string logpath);
    Logger(std::string executableName, std::string logpath);

public:
    Logger(Logger& other) = delete;               // not cloneable
    void operator=(const Logger& other) = delete; // not assignable

    static Logger* loggerInst(std::string logFilePath);

    void error(const char* fmt, ...);

    void error2(bool cout, std::string classname, const char* fmt, ...);

    void log(const char* fmt, ...);

    /*SomeClass fmtmessage*/
    void log2(bool cout, std::string classname, const char* fmt, ...);

    /*SomeClass fmtmessage*/
    void logprint(std::string classname, const char* fmt, ...);

    /*SomeClass fmtmessage*/
    void coutprint(std::string classname, const char* fmt, ...);

private:
    std::string buildString(bool err, std::string buffer);

    static Logger* loggerSingleton;
    static std::mutex mtx;

    FileWriter filewriter;
};

} // namespace utils