#pragma once
#include <string>

namespace charting {

class ICandleStick
{
    virtual void reset() = 0;

    virtual std::string toString() = 0;
};

} // namespace charting