#include "Databank.h"
#include "Logger.h"

namespace databank
{
Databank::Databank(std::shared_ptr<DataQueue<std::string>> streamqueue, std::string logfile)
    : streamqueue(streamqueue)
    , logfile(logfile)
{
    infologprint(logfile, "%s: init", __func__);
}
}