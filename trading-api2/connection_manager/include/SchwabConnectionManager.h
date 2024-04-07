#pragma once

#include "RestClientCurl.h"
#include "SchwabClient.h"

#include <memory>

class SchwabConnectionManager
{
public:
    // testing
    SchwabConnectionManager(std::shared_ptr<ISchwabConfigs> configs, std::shared_ptr<ISchwabClient> sclient);
    // production
    SchwabConnectionManager(std::string configfolder);

private:
    std::shared_ptr<ISchwabConfigs> configs;
    std::shared_ptr<ISchwabClient> sclient;
};