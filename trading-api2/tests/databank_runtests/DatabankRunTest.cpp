#include "RestClientCurl.h"
#include "SchwabClient.h"
#include "SchwabConnectionManager.h"
#include "SchwabDatabank.h"
#include "SchwabStreamHandler.h"

#include <gtest/gtest.h>

#include <thread>

using namespace databank;
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
    std::string configFolder = "/datadisk0/sambashare0/coding/configs/";
    std::string logfile = "/datadisk0/sambashare0/coding/trading-api2-endpoint-test-logs/databank_testlog.txt";
};

TEST_F(SchwabDatabankRunTest, testStartParsing)
{
    manager->buildAllRequests();
    manager->startThreadFuncThread();

    databank = std::make_shared<SchwabDatabank>(manager->getStreamer()->repliesQueue(), logfile);
    databank->startParsing();
    manager->reconnectingStreamThread.join();
}