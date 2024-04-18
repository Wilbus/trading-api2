#include "SchwabStreamHandler.h"

#include "Logger.h"
#include "SchwabStreamParser.h"
#include "SchwabStreamReqGenerator.h"
#include "timefuncs.h"

#include <iostream>
#include <sstream>

namespace streamer {
using namespace schwabStreamParser;
// TODO: consider moving callback functions outside of this class to for example SchwabConnection class
SchwabStreamHandler::SchwabStreamHandler(std::string url, SchwabRequestsIdMap requestsIdMap, std::string logfile)
    : group(hub.createGroup<uWS::CLIENT>())
    , streamUrl(url)
    , logfile(logfile)
    , requestsIdMap(requestsIdMap)
{
    infologprint(logfile, "%s init", __func__);
    repliesQue = std::make_shared<DataQueue<std::string>>();
    for (const auto& [id, req] : requestsIdMap)
    {
        requestsIdStrMap[id] = schwabStreamReq::buildRequestString(req);
        requestsQueue.push(req);
    }
    setupCallbacks();
}

SchwabStreamHandler::~SchwabStreamHandler()
{
    group->close();
    delete group;
}

void SchwabStreamHandler::setupCallbacks()
{
    infologprint(logfile, "%s: setup callbacks", __func__);
    group->onConnection([this](uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req) {
        onConnectionCallback(ws, req);
        // onConnection(ws, req);
    });

    group->onMessage([this](uWS::WebSocket<uWS::CLIENT>* ws, char* message, size_t length, uWS::OpCode opCode) {
        onMessageCallback(ws, message, length, opCode);
    });

    group->onDisconnection([this](uWS::WebSocket<uWS::CLIENT>* ws, int code, char* message, size_t length) {
        onDisconnectionCallback(ws, code, message, length);
    });

    group->onError([this](void* e) { onErrorCallback(e); });
}

void SchwabStreamHandler::run()
{
    infologprint(logfile, "SchwabStreamHandler start run()\n");
    hub.run();
}

void SchwabStreamHandler::onConnectionCallback(uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest req)
{
    // use 0 as the special requestId for login request
    if (requestsIdMap.find(0) == requestsIdMap.end())
    {
        throw std::runtime_error("no login request was requested");
    }

    infologprint(logfile, "%s: connected. Send login request: %s", __func__, requestsIdStrMap.at(0).c_str());

    ws->send(requestsIdStrMap.at(0).data(), requestsIdStrMap.at(0).size(), uWS::OpCode::TEXT), nullptr, nullptr,
        nullptr;
    currentReqId += 1;
}

void SchwabStreamHandler::onMessageCallback(
    uWS::WebSocket<uWS::CLIENT>* ws, char* message, size_t length, uWS::OpCode opCode)
{
    (void)ws;
    (void)opCode;
    std::string text = std::string(message, length);

    // coutlog(logfile, "%s: %s", __func__, text.c_str()); //ONLY 1024 BYTES MAX FOR LOGGER COUTLOG function
    // std::cout << "RAW DATA: " << text << "\n";

    Heartbeat heartbeat = parseHeartbeat(text);
    if (heartbeat.timestamp > 0)
    {
        time_t inSeconds = heartbeat.timestamp / 1000;
        infologprint(logfile, "%s: heartbeat timestamp recved: %s", __func__,
            timefuncs::unixTimeToString(inSeconds, "%Y-%m-%dT%H:%M:%S").c_str());
        lastReceivedHeartbeat = heartbeat.timestamp;
    }
    std::vector<Response> responses = schwabStreamParser::parseResponse(text);

    if (responses.size() > 0)
    {
        Response resp = responses[0]; // assuming we only get 1 response element per json text
                                      // if (resp.content.code >= 0)
        //{
        infologprint(logfile, "%s: Response is: %s", __func__, text.c_str());
        // special case for for failed login
        if (resp.command == CommandType::LOGIN && resp.content.code != 0)
        {
            std::stringstream failmsgss;
            std::string erromsg = "Failed login: " + resp.content.msg;
            failmsgss << erromsg;
            throw std::runtime_error(failmsgss.str().c_str());
        }
        else if (resp.content.code != 0)
        {
            std::string serviceTypeStr;
            if (requestsIdMap.find(resp.requestid) != requestsIdMap.end())
            {
                serviceTypeStr = serviceTypeToStringMap.at(requestsIdMap.at(resp.requestid).serviceType);
            }
            std::stringstream failmsgss;
            std::string erromsg = "Failed request: SERVICE: " + serviceTypeStr + "MSG: " + resp.content.msg;
            failmsgss << erromsg;
            throw std::runtime_error(failmsgss.str().c_str());
        }

        // TODO: maybe we can use a queue instead, so we can easily reattempt sending by re-pushing the same message
        //  if the request failed
        // For now just error out if any message failed
        if (requestsIdStrMap.find(currentReqId) != requestsIdStrMap.end()) // we have pending requests to be made
        {
            // requestsIdStrMap.erase(resp.requestid); //remove the request from the map that this response belongs
            // to

            // std::string nextRequest = requestsIdStrMap[currentReqId];
            // ws->send(nextRequest.data(), nextRequest.size(), uWS::OpCode::TEXT);
            // ws->send(requestsIdStrMap.begin()->second.data(), requestsIdStrMap.begin()->second.size(),
            // uWS::OpCode::TEXT);
            ws->send(requestsIdStrMap[currentReqId].data(), requestsIdStrMap[currentReqId].size(), uWS::OpCode::TEXT);
            currentReqId += 1;
        }
        //}
        // else
        //{
        // response was never parsed. could be data response instead of a regular response
        //}
    }
    else // no responses to request parsed, could be data response instead
    {
        repliesQue->push(text);
    }
}

void SchwabStreamHandler::onDisconnectionCallback(
    uWS::WebSocket<uWS::CLIENT>* ws, int code, char* message, size_t length)
{
    (void)ws;
    (void)code;
    (void)message;
    (void)length;
    std::string msg = std::string(message, length);
    infologprint(logfile, "%s: Disconnected: code = %d, message: %s", __func__, code, msg.c_str());
}

void SchwabStreamHandler::onErrorCallback(void* e)
{
    (void)e; // TODO: what is this pointer for?
    infologprint(logfile, "%s: Error occured", __func__);
}

void SchwabStreamHandler::reconnectingStream()
{
}

void SchwabStreamHandler::connectStream()
{
    infologprint(logfile, "%s: connecting to %s", __func__, streamUrl.c_str());
    hub.connect(streamUrl, nullptr, {}, 5000, group);
}

std::shared_ptr<DataQueue<std::string>> SchwabStreamHandler::repliesQueue()
{
    return repliesQue;
}

} // namespace streamer