#pragma once

#include "SchwabDatabank.h"

namespace databank {

class SchwabJsonDataRecorder : public SchwabDatabank
{
public:
    SchwabJsonDataRecorder(std::shared_ptr<ISchwabClient> sclient, std::shared_ptr<IDatabaseHandler> dbHandler,
        std::shared_ptr<DataQueue<std::string>> streamqueue, std::string logfile = "");

    virtual void startParsing() override;

protected:
    virtual void parseStreamQueue(unsigned count) override;
};

} // namespace databank
