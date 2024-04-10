#include "SchwabDatabank.h"
#include "schwabStreamResponseValues.h"

#include <gtest/gtest.h>

#include <thread>

using namespace databank;

class SchwabDatabankTest : public ::testing::Test
{
public:
    class SchwabDatabankTester : public SchwabDatabank
    {
    public:
        SchwabDatabankTester(std::shared_ptr<DataQueue<std::string>> streamqueue, std::string logfile = "")
            : SchwabDatabank(streamqueue, logfile)
        {
        }

        void parseStreamQueue(unsigned count)
        {
            SchwabDatabank::parseStreamQueue(count);
        }
    };

    SchwabDatabankTest()
    {
        streamqueue = std::make_shared<DataQueue<std::string>>();
        databankTester = std::make_shared<SchwabDatabankTester>(streamqueue);
    }

    void pushStreamData(unsigned pushes, std::string data)
    {
        for (unsigned i = 0; i < pushes; i++)
        {
            streamqueue->push(data);
        }
    }

protected:
    std::shared_ptr<SchwabDatabankTester> databankTester;
    std::shared_ptr<DataQueue<std::string>> streamqueue;
};

TEST_F(SchwabDatabankTest, testStartParsing)
{
    std::thread pushThread(&SchwabDatabankTest::pushStreamData, this, 10, bigLevelOneDataResponse);
    databankTester->parseStreamQueue(10);

    pushThread.join();

    EXPECT_EQ(databankTester->getChart("DELL").getMultiCandles().size(), 10);
    EXPECT_EQ(databankTester->getChart("SPY").getMultiCandles().size(), 10);
}