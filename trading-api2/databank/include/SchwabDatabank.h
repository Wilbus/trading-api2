#pragma once

#include "DataQueue.h"
#include "IDatabank.h"

#include <memory>

namespace databank {

using namespace utils;

class SchwabDatabank : public IDatabank
{
public:
    SchwabDatabank(std::shared_ptr<DataQueue<std::string>> streamqueue, std::string logfile = "");

    virtual void startParsing() override;

private:
    void parseStreamQueue();
    std::shared_ptr<DataQueue<std::string>> streamqueue;
    std::string logfile;
};
} // namespace databank