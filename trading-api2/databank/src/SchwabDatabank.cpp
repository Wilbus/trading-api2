#include "SchwabDatabank.h"

#include "Logger.h"
#include "SchwabStreamDataParser.h"

namespace databank {
SchwabDatabank::SchwabDatabank(std::shared_ptr<DataQueue<std::string>> streamqueue, std::string logfile)
    : streamqueue(streamqueue)
    , logfile(logfile)
{
    infologprint(logfile, "%s: init", __func__);
}

void SchwabDatabank::startParsing()
{
    std::thread parseThread(&SchwabDatabank::parseStreamQueue, this);
}

void SchwabDatabank::parseStreamQueue()
{
    while (true)
    {
        if (!streamqueue->isEmpty())
        {
        }
    }
}
} // namespace databank