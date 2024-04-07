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

#define infologprint(filepath, msg, ...) utils::Logger::loggerInst(filepath)->log2(true, typeid(this).name(), msg __VA_OPT__(, ) __VA_ARGS__)

class Logger
{
protected:
    Logger(std::string logpath);
    Logger(std::string executableName, std::string logpath);

public:
    Logger(Logger& other) = delete; //not cloneable
    void operator=(const Logger& other) = delete; //not assignable

    static Logger* loggerInst(std::string logFilePath);
    
    void error(const char* fmt, ...)
    {
        //std::lock_guard<std::mutex> lg(mtx);

        char buffer[1024];
        va_list args;
        va_start(args, fmt);
        vsprintf(buffer, fmt, args);

        std::string message = buildString(true, buffer);

        filewriter.write(message);

        va_end(args);
    }

    void error2(bool cout, std::string classname, const char* fmt, ...)
    {
        //std::lock_guard<std::mutex> lg(mtx);

        char buffer[1024];
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

    void log(const char* fmt, ...)
    {
        //std::lock_guard<std::mutex> lg(mtx);

        char buffer[1024];
        va_list args;
        va_start(args, fmt);
        vsprintf(buffer, fmt, args);

        std::string message = buildString(false, buffer);

        filewriter.write(message);

        va_end(args);
    }

    /*SomeClass fmtmessage*/
    void log2(bool cout, std::string classname, const char* fmt, ...)
    {
        //std::lock_guard<std::mutex> lg(mtx);
        char buffer[1024];
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
    void logprint(std::string classname, const char* fmt, ...)
    {
        //std::lock_guard<std::mutex> lg(mtx);
        char buffer[1024];
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
    void coutprint(std::string classname, const char* fmt, ...)
    {
        //std::lock_guard<std::mutex> lg(mtx);
        char buffer[1024];
        va_list args;
        va_start(args, fmt);
        vsprintf(buffer, fmt, args);

        std::string classNameAppend = classname + "::" + buffer;
        std::string message = buildString(false, classNameAppend);

        std::cout << message;

        va_end(args);
    }

private:
    std::string buildString(bool err, std::string buffer);

    static Logger* loggerSingleton;
    static std::mutex mtx;

    FileWriter filewriter;
};

} // namespace utils