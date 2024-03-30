#include "AlpacaClient.h"

AlpacaClient::AlpacaClient(std::shared_ptr<IRestClient> restClient, std::shared_ptr<IAlpacaStreamHandler> streamHandler)
    : restClient(restClient)
    , streamHandler(streamHandler)
{
}

void AlpacaClient::startMarketStream()
{
    streamHandler->run();
}