#include "AlpacaStreamHandler.h"

#include "AlpacaStreamParser.h"
#include "StreamReqGeneratorHelper.h"

#include <chrono>
#include <iostream>
#include <thread>

namespace streamer {

AlpacaStreamHandler::AlpacaStreamHandler(std::string url, std::string apiKey, std::string apiSecret)
    : group(hub.createGroup<uWS::CLIENT>())
    , streamUrl(url)
    , apiKey(apiKey)
    , apiSecret(apiSecret)
{
    repliesQue = std::make_shared<DataQueue<std::string>>();
    setupCallbacks();
}

AlpacaStreamHandler::AlpacaStreamHandler(std::string url)
    : group(hub.createGroup<uWS::CLIENT>())
    , streamUrl(url)
{
    repliesQue = std::make_shared<DataQueue<std::string>>();
    setupCallbacks();
}

AlpacaStreamHandler::~AlpacaStreamHandler()
{
    delete group;
}

void AlpacaStreamHandler::setupCallbacks()
{
    group->onConnection(
        [this](uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req) { this->onConnectionCallback(ws, req); });

    group->onMessage([this](uWS::WebSocket<uWS::CLIENT>* ws, char* message, size_t length, uWS::OpCode opCode) {
        (void)opCode; // TODO: do something with these
        this->onMessageCallback(ws, message, length);
    });

    group->onDisconnection([this](uWS::WebSocket<uWS::CLIENT>* ws, int code, char* message, size_t length) {
        (void)ws;
        this->onDisconnectionCallback(code, message, length);
    });

    // TODO: need to reconnect on eror
    group->onError([this](void* e) { this->onErrorCallback(e); });
}

void AlpacaStreamHandler::onConnectionCallback(uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req)
{
    (void)req; // TODO: do something with this
    // std::printf("onConnectionCallback\n");
    auto listen = getAlpacaAuthentication(apiKey, apiSecret);
    ws->send(listen.data(), listen.size(), uWS::OpCode::TEXT);
}

void AlpacaStreamHandler::onMessageCallback(uWS::WebSocket<uWS::CLIENT>* ws, char* message, size_t length)
{
    try
    {
        auto text = std::string(message, length);
        std::cout << text;
        // repliesQue->push(text);
        auto msgtype = alpacahelper::parseType(text);
        switch (msgtype)
        {
            case alpacahelper::MsgType::SUCCESS: {
                auto channels = getAlpacaChannelStreamsMsg({"SPY", "MSFT"});
                ws->send(channels.data(), channels.size(), uWS::OpCode::TEXT);
                break;
            }
        }
    }
    catch (const std::exception& e)
    {
        std::stringstream ss;
        ss << e.what();
        std::cout << ss.str() << "\n";
    }
}

void AlpacaStreamHandler::onDisconnectionCallback(int code, char* message, size_t length)
{
    std::printf("Received disconnection event: %s\n", std::string(message, length).c_str());
    std::printf("Code return: %d\n", code);
}

void AlpacaStreamHandler::onErrorCallback(void* e)
{
    (void)e;
    std::printf("Received error in stream handler.\n");
}

void AlpacaStreamHandler::run()
{
    std::ostringstream ss;
    ss << "wss://" << streamUrl;

    hub.connect(ss.str(), nullptr, {}, 5000, group);
    hub.run();
}

/*void AlpacaStreamHandler::poll()
{
    hub.poll();
}*/

void AlpacaStreamHandler::reconnectingStream()
{
    /*infolog(logger, "start reconnecting stream thread");
    while (true)
    {
        AlpacaStreamHandler stream(exchange, env, tickers, repliesQue, logger);
        stream.setStreamRequestGenerator(messageGenerator);
        stream.run();
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }*/
}

void AlpacaStreamHandler::connectStream()
{
    std::ostringstream ss;
    ss << "wss://" << streamUrl;

    hub.connect(ss.str(), nullptr, {}, 5000, group);
}

std::shared_ptr<DataQueue<std::string>> AlpacaStreamHandler::repliesQueue()
{
    return repliesQue;
}

} // namespace streamer