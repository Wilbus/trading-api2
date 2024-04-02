#include "SchwabConnection.h"

#include "RestClient.h"

// testing
SchwabConnection::SchwabConnection(std::shared_ptr<ISchwabConfigs> configs, std::shared_ptr<ISchwabClient> sclient)
    : configs(configs)
    , sclient(sclient)
{
}
// production
SchwabConnection::SchwabConnection(std::string configfolder)
{
    configs = std::make_shared<SchwabConfigs>(configfolder);
    sclient = std::make_shared<SchwabClient>(configs, std::make_shared<RestClient>());
}