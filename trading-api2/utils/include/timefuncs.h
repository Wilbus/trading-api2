#pragma once

#include <iomanip>
#include <sstream>

namespace timefuncs {

static std::time_t stringTimeToUnix(std::string str, std::string format)
{
    std::tm t{};
    std::istringstream ss(str);

    ss >> std::get_time(&t, format.c_str());
    if (ss.fail())
    {
        throw std::runtime_error{"failed to parse time string"};
    }

    return mktime(&t);
}

// unix time in seconds
static std::string unixTimeToString(std::time_t& t, std::string format)
{
    std::tm tmtime = *std::gmtime(&t);
    std::stringstream buff;
    buff << std::put_time(&tmtime, format.c_str());
    return buff.str();
}

// return true if daylight savings is in effect
static bool isDaylightSavings()
{
    std::time_t t = std::time(nullptr);
    std::tm tmtime = *std::gmtime(&t);
    return tmtime.tm_isdst;
}

// return int value representing the local timezone offset in
// this seems to reliable and includes daylight savings
static int getLocalTimezone()
{
    time_t t = time(NULL);
    tm lt;
    localtime_r(&t, &lt);
    return lt.tm_gmtoff / 3600;
}

static std::string getCurrentLocalTimeStrNs(int64_t hours)
{
    auto t = std::chrono::high_resolution_clock::now();
    int64_t nsUnixTime = t.time_since_epoch().count() + (hours * 3600 * 1000000000);

    int nsFraction = nsUnixTime % 1'000'000'000;
    time_t seconds = nsUnixTime / 1'000'000'000;

    char timestr_sec[] = "YYYY-MM-DDThh:mm:ss.sssssssss";
    std::strftime(timestr_sec, sizeof(timestr_sec) - 1, "%FT%T", std::gmtime(&seconds));
    std::ostringstream tout;
    tout << timestr_sec << '.' << std::setfill('0') << std::setw(9) << nsFraction << "Z";
    std::string timestr_micro = tout.str();

    return timestr_micro;
}

}; // namespace timefuncs