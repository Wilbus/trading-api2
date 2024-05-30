#include "RestClientCurl.h"
#include "SchwabClient.h"
#include "SchwabConnectionManager.h"
#include "SchwabDatabank.h"
#include "SchwabDatabaseHandler.h"
#include "SchwabStreamHandler.h"

#include <gtest/gtest.h>

#include <thread>

using namespace databank;
using namespace databasehandlers;
using namespace streamer;

class SchwabDatabankRunTest : public ::testing::Test
{
public:
    SchwabDatabankRunTest()
    {
        manager = std::make_shared<SchwabConnectionManager>(configFolder, logfile);
    }

protected:
    std::shared_ptr<SchwabConnectionManager> manager;
    std::shared_ptr<SchwabDatabank> databank;
    std::shared_ptr<SchwabDatabaseHandler> dbHandler;
    std::string configFolder = "/home/wilbus/smbshare0/sambashare0/coding/configs/";
    std::string logfile = "/home/wilbus/smbshare0/sambashare0/coding/trading-api2-endpoint-test-logs/databank_testlog.txt";
    InfluxConnectionInfo influxConn{
        "devtesterv1",
        "123456789",
        "192.168.0.130:8086",
        "dev-testing-v1",
        "N-q3KQNK6HEmUqj2bDwflK_08BQINRLTLlGsZhBrjQyFIQjVAK9AgCZtDjPEHD7IF7AWh20PPhgwAOaSXxyswQ=="
    };
}; 

TEST_F(SchwabDatabankRunTest, testStartParsing)
{
    manager->buildAllRequests();
    manager->startThreadFuncThread();

    dbHandler = std::make_shared<SchwabDatabaseHandler>(influxConn);
    databank = std::make_shared<SchwabDatabank>(dbHandler, manager->getStreamer()->repliesQueue(), logfile);
    databank->startParsing();
    manager->reconnectingStreamThread.join();
}