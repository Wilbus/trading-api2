#pragma once

#include "DataQueue.h"
#include <memory>

namespace databank
{

using namespace utils;

class Databank
{
public:
    Databank(std::shared_ptr<DataQueue<std::string>> streamqueue, std::string logfile = "");

private:
    std::shared_ptr<DataQueue<std::string>> streamqueue;
    std::string logfile;
};
}