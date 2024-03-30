
#pragma once

#include "IRestClient.h"
#include "IStreamHandler.h"
#include "TradierStructs.h"

#include <memory>

using namespace restclient;
using namespace streamer;
using namespace tradierstructs;

class ITradierData
{
    virtual std::string getUserProfile() = 0;
    virtual AccessToken getAccessToken() = 0;
    virtual std::string getMarketSessionId() = 0;
    virtual std::string getAccountSessionId() = 0;
    virtual void startMarketStream() = 0;
    virtual void parseMarketStream() = 0;
    virtual Quote parseQuote(std::string jsonstring) = 0;
    virtual Trade parseTrade(std::string jsonstring) = 0;
    virtual Summary parseSummary(std::string jsonstring) = 0;
    virtual TimeSale parseTimeSale(std::string jsonstring) = 0;
    virtual Tradex parseTradex(std::string jsonstring) = 0;
    virtual std::shared_ptr<DataQueue<Tradex>> getTradexQueue() = 0;
};

class TradierData : ITradierData
{
public:
    TradierData(std::shared_ptr<IRestClient> restClient, std::shared_ptr<IStreamHandler> streamHandler);
    TradierData(std::set<std::string> product_ids, std::string apiToken, std::shared_ptr<IRestClient> restClient,
        std::shared_ptr<IStreamHandler> streamHandler);
    virtual std::string getUserProfile() override;
    virtual AccessToken getAccessToken() override;
    virtual std::string getMarketSessionId() override;
    virtual std::string getAccountSessionId() override;

    virtual void startMarketStream() override;
    virtual void parseMarketStream() override;
    virtual Quote parseQuote(std::string jsonstring) override;

    virtual Trade parseTrade(std::string jsonstring) override;

    virtual Summary parseSummary(std::string jsonstring) override;

    virtual TimeSale parseTimeSale(std::string jsonstring) override;

    virtual Tradex parseTradex(std::string jsonstring) override;
    virtual std::shared_ptr<DataQueue<Tradex>> getTradexQueue() override;

private:
    httplib::Headers headers() const;
    AccessToken parseGetAccessToken(std::string json);
    std::string parseSessionId(std::string json);

    std::set<std::string> product_ids;
    std::string apiToken;
    std::shared_ptr<IRestClient> restClient;
    std::shared_ptr<IStreamHandler> streamHandler;

    std::shared_ptr<DataQueue<Tradex>> tradexQue;
};