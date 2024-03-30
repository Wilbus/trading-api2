
#pragma once

#include "AlpacaStreamHandler.h"
#include "IRestClient.h"

#include <memory>

using namespace restclient;
using namespace streamer;

// AKAHR3N818LOWBATOT6Q key
// VlLbb6D5V7ebuFKWxu1g3ciU0XC0t secret

class IAlpacaClient
{
public:
    virtual void startMarketStream() = 0;
};

class AlpacaClient : public IAlpacaClient
{
public:
    AlpacaClient(std::shared_ptr<IRestClient> restClient, std::shared_ptr<IAlpacaStreamHandler> streamHandler);

    virtual void startMarketStream() override;

private:
    std::shared_ptr<IRestClient> restClient;
    std::shared_ptr<IAlpacaStreamHandler> streamHandler;
};