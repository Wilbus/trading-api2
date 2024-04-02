#pragma once

#include "SchwabClient.h"

#include <memory>

class SchwabConnection
{
public:
    // testing
    SchwabConnection(std::shared_ptr<ISchwabConfigs> configs, std::shared_ptr<ISchwabClient> sclient);
    // production
    SchwabConnection(std::string configfolder);

private:
    std::shared_ptr<ISchwabConfigs> configs;
    std::shared_ptr<ISchwabClient> sclient;
};