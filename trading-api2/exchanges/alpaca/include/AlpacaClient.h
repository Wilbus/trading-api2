
#pragma once

#include "AlpacaStreamHandler.h"
#include "IRestClient.h"

#include <memory>

using namespace restclient;
using namespace streamer;

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