#include "SchwabJsonDataRecorder.h"

using namespace databank;

SchwabJsonDataRecorder::SchwabJsonDataRecorder(std::shared_ptr<ISchwabClient> sclient,
    std::shared_ptr<IDatabaseHandler> dbHandler, std::shared_ptr<DataQueue<std::string>> streamqueue, std::string logfile)
    : SchwabDatabank(sclient, dbHandler, streamqueue, logfile)
{
    infologprint(logfile, "%s init", __func__);
}

void SchwabJsonDataRecorder::startParsing()
{
    infologprint(logfile, "%s: begin parsing and record data", __func__);
    while (true)
    {
        if (!streamqueue->isEmpty())
        {
            parseStreamQueue(0);
        }
    }
}

void SchwabJsonDataRecorder::parseStreamQueue(unsigned count)
{
    std::string jsondata = streamqueue->front();
    streamqueue->pop();
    pushJsonDataToDb(jsondata);
}