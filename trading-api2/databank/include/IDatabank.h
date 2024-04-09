#pragma once

namespace databank {
class IDatabank
{
public:
    virtual void startParsing() = 0;
};
} // namespace databank