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
#if 0 // re-enable when needed to reduce WUnused-function warnings
static std::string unixTimeToString(std::time_t& t, std::string format)
{
    std::tm tmtime = *std::localtime(&t);
    std::stringstream buff;
    buff << std::put_time(&tmtime, format.c_str());
    return buff.str();
}
#endif
}; // namespace timefuncs