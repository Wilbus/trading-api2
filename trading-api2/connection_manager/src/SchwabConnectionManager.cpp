#include "SchwabConnectionManager.h"

// testing
SchwabConnectionManager::SchwabConnectionManager(std::shared_ptr<ISchwabConfigs> configs, std::shared_ptr<ISchwabClient> sclient)
    : configs(configs)
    , sclient(sclient)
{
}
// production
SchwabConnectionManager::SchwabConnectionManager(std::string configfolder)
{
    configs = std::make_shared<SchwabConfigs>(configfolder);
    sclient = std::make_shared<SchwabClient>(configs, std::make_shared<RestClientCurl>());
}