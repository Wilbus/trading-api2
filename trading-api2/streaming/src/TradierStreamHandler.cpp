#include "TradierStreamHandler.h"

#include "StreamReqGeneratorHelper.h"

#include <chrono>
#include <iostream>
#include <thread>

namespace streamer {

TradierStreamHandler::TradierStreamHandler(std::string url, std::set<std::string> product_ids, std::string seshId)
    : group(hub.createGroup<uWS::CLIENT>())
    , streamUrl(url)
    , product_ids(product_ids)
    , seshId(seshId)
{
    repliesQue = std::make_shared<DataQueue<std::string>>();
    setupCallbacks();
}

TradierStreamHandler::TradierStreamHandler(std::string url)
    : group(hub.createGroup<uWS::CLIENT>())
    , streamUrl(url)
{
    repliesQue = std::make_shared<DataQueue<std::string>>();
    setupCallbacks();
}

TradierStreamHandler::~TradierStreamHandler()
{
    delete group;
}

void TradierStreamHandler::setupCallbacks()
{
    group->onConnection(
        [this](uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req) { this->onConnectionCallback(ws, req); });

    group->onMessage([this](uWS::WebSocket<uWS::CLIENT>* ws, char* message, size_t length, uWS::OpCode opCode) {
        (void)ws;
        (void)opCode; // TODO: do something with these
        this->onMessageCallback(message, length);
    });

    group->onDisconnection([this](uWS::WebSocket<uWS::CLIENT>* ws, int code, char* message, size_t length) {
        (void)ws;
        this->onDisconnectionCallback(code, message, length);
    });

    // TODO: need to reconnect on eror
    group->onError([this](void* e) { this->onErrorCallback(e); });
}

void TradierStreamHandler::onConnectionCallback(uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req)
{
    (void)req; // TODO: do something with this
    // std::printf("onConnectionCallback\n");
    auto listen = getTradierSubscribeChannelReq(product_ids, seshId);
    ws->send(listen.data(), listen.size(), uWS::OpCode::TEXT);
}

void TradierStreamHandler::onMessageCallback(char* message, size_t length)
{
    try
    {
        auto text = std::string(message, length);
        repliesQue->push(text);
        std::cout << text;
    }
    catch (const std::exception& e)
    {
        std::stringstream ss;
        ss << e.what();
        std::cout << ss.str() << "\n";
    }
}

void TradierStreamHandler::onDisconnectionCallback(int code, char* message, size_t length)
{
    std::printf("Received disconnection event: %s\n", std::string(message, length).c_str());
    std::printf("Code return: %d\n", code);
}

void TradierStreamHandler::onErrorCallback(void* e)
{
    (void)e;
    std::printf("Received error in stream handler.\n");
}

void TradierStreamHandler::run()
{
    std::ostringstream ss;
    ss << "wss://" << streamUrl;

    hub.connect(ss.str(), nullptr, {}, 5000, group);
    hub.run();
}

/*void TradierStreamHandler::poll()
{
    hub.poll();
}*/

void TradierStreamHandler::reconnectingStream()
{
    /*infolog(logger, "start reconnecting stream thread");
    while (true)
    {
        TradierStreamHandler stream(exchange, env, tickers, repliesQue, logger);
        stream.setStreamRequestGenerator(messageGenerator);
        stream.run();
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }*/
}

void TradierStreamHandler::connectStream()
{
    std::ostringstream ss;
    ss << "wss://" << streamUrl;

    hub.connect(ss.str(), nullptr, {}, 5000, group);
}

std::shared_ptr<DataQueue<std::string>> TradierStreamHandler::repliesQueue()
{
    return repliesQue;
}

void TradierStreamHandler::setSeshId(std::string id)
{
    seshId = id;
}

void TradierStreamHandler::setProductIds(std::set<std::string> ids)
{
    product_ids = ids;
}

} // namespace streamer