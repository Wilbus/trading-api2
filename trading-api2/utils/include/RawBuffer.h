#pragma once

#include <cstdint>
#include <vector>

namespace utils

{
class RawBuffer : public std::vector<uint8_t>
{
public:
    RawBuffer(const uint8_t* ptr, uint32_t size)
        : std::vector<uint8_t>(ptr, ptr + size)
    {
    }
    RawBuffer()
        : std::vector<uint8_t>()
    {
    }
};
} // namespace utils