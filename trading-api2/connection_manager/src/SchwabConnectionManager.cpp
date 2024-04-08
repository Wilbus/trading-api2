#include "SchwabConnectionManager.h"

#include "Logger.h"

#include <chrono>

// testing
SchwabConnectionManager::SchwabConnectionManager(
    std::shared_ptr<ISchwabConfigs> configs, std::shared_ptr<ISchwabClient> sclient, std::string logfile)
    : configs(configs)
    , sclient(sclient)
    , logfile(logfile)
{
    infologprint(logfile, "%s init", __func__);
}
// production
SchwabConnectionManager::SchwabConnectionManager(std::string configfolder)
{
    infologprint(logfile, "%s init", __func__);
    configs = std::make_shared<SchwabConfigs>(configfolder);
    sclient = std::make_shared<SchwabClient>(configs, std::make_shared<RestClientCurl>());
}

// make this configurable
void SchwabConnectionManager::buildAllRequests()
{
    infologprint(logfile, "%s building request jsons to send", __func__);
    UserPreferences prefs = sclient->getUserPreferences();

    Request loginReq;
    loginReq.serviceType = ServiceType::ADMIN;
    loginReq.requestid = 0;
    loginReq.commandType = CommandType::LOGIN;
    loginReq.schwabClientCustomerId = prefs.streamerInfo[0].schwabClientCustomerId;
    loginReq.schwabClientCorrelId = prefs.streamerInfo[0].schwabClientCorrelId;
    loginReq.parameters.authorization = configs->getAccessToken().token;
    loginReq.parameters.schwabClientChannel = prefs.streamerInfo[0].schwabClientChannel;
    loginReq.parameters.schwabClientFunctionId = prefs.streamerInfo[0].schwabClientFunctionId;

    /*Request qosReq;
    qosReq.serviceType = ServiceType::ADMIN;
    qosReq.requestid = 1;
    qosReq.commandType = CommandType::QOS;
    qosReq.schwabClientCustomerId = prefs.streamerInfo[0].schwabClientCustomerId;
    qosReq.schwabClientCorrelId = prefs.streamerInfo[0].schwabClientCorrelId;
    qosReq.parameters.qoslevel = "0";*/

    Request acctActivityReq;
    acctActivityReq.serviceType = ServiceType::ACCT_ACTIVITY;
    acctActivityReq.requestid = 1;
    acctActivityReq.commandType = CommandType::SUBS;
    acctActivityReq.schwabClientCustomerId = prefs.streamerInfo[0].schwabClientCustomerId;
    acctActivityReq.schwabClientCorrelId = prefs.streamerInfo[0].schwabClientCorrelId;
    acctActivityReq.parameters.keys = "somekey";
    acctActivityReq.parameters.fields = "0,1,2,3";

    Request levelOneActivityReq;
    levelOneActivityReq.serviceType = ServiceType::LEVELONE_EQUITIES;
    levelOneActivityReq.requestid = 2;
    levelOneActivityReq.commandType = CommandType::SUBS;
    levelOneActivityReq.schwabClientCustomerId = prefs.streamerInfo[0].schwabClientCustomerId;
    levelOneActivityReq.schwabClientCorrelId = prefs.streamerInfo[0].schwabClientCorrelId;
    levelOneActivityReq.parameters.keys = "QQQ";
    levelOneActivityReq.parameters.fields = "0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16";

    Request chartEquityReq;
    chartEquityReq.serviceType = ServiceType::CHART_EQUITY;
    chartEquityReq.requestid = 3;
    chartEquityReq.commandType = CommandType::SUBS;
    chartEquityReq.schwabClientCustomerId = prefs.streamerInfo[0].schwabClientCustomerId;
    chartEquityReq.schwabClientCorrelId = prefs.streamerInfo[0].schwabClientCorrelId;
    chartEquityReq.parameters.keys = "QQQ";
    chartEquityReq.parameters.fields = "0,1,2,3,4,5,6,7,8";

    Request optionReq;
    optionReq.serviceType = ServiceType::OPTION;
    optionReq.requestid = 4;
    optionReq.commandType = CommandType::SUBS;
    optionReq.schwabClientCustomerId = prefs.streamerInfo[0].schwabClientCustomerId;
    optionReq.schwabClientCorrelId = prefs.streamerInfo[0].schwabClientCorrelId;
    optionReq.parameters.keys = "QQQ";
    optionReq.parameters.fields = "0,1,2,3,4,5,6,7,8,9,10,11,12,20,21,22,23,24,32,33,34,35,36,38,41";

    requestsMap.clear();
    requestsMap[0] = loginReq;
    // map[1] = qosReq;
    requestsMap[1] = acctActivityReq;
    requestsMap[2] = levelOneActivityReq;
    requestsMap[3] = chartEquityReq;
    requestsMap[4] = optionReq;

    streamer.reset();
    streamer = std::make_shared<SchwabStreamHandler>("wss://streamer-api.schwab.com/ws", requestsMap);
}

void SchwabConnectionManager::connectAndRunStream()
{
    try
    {
        infologprint(logfile, "%s Stream connect and run starting", __func__);
        streamer->connectStream();
        streamer->run();
    }
    catch (const std::exception& e)
    {
        infologprint(logfile, "%s: stream handler threw exception: %s", __func__, e.what());
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(5000ms);
    }
}

void SchwabConnectionManager::streamThreadFunc()
{
    infologprint(logfile, "%s: Begin the stream connection thread function", __func__);
    while (true)
    {
        connectAndRunStream();
        // if we fall out of connectAndRunStream(), rebuild requests and streamer instance
        infologprint(logfile,
            "%s: fell out of the stream handler run() loop. Rebuild requests and new instance of stream handler",
            __func__);
        buildAllRequests();
    }
}

void SchwabConnectionManager::startThreadFuncThread()
{
    infologprint(logfile, "%s: Spawn reconnecting stream thread", __func__);
    reconnectingStreamThread = std::thread(&SchwabConnectionManager::streamThreadFunc, this);
}

std::shared_ptr<IStreamHandler> SchwabConnectionManager::getStreamer()
{
    return streamer;
}