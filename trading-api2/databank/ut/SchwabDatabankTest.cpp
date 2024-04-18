#include "DatabaseHandlerMock.h"
#include "SchwabDatabank.h"
#include "schwabStreamResponseValues.h"

#include <gtest/gtest.h>

#include <thread>

using namespace databank;
using namespace databasehandlers::mocks;

class SchwabDatabankTest : public ::testing::Test
{
public:
    class SchwabDatabankTester : public SchwabDatabank
    {
    public:
        SchwabDatabankTester(std::shared_ptr<IDatabaseHandler> dbHandler,
            std::shared_ptr<DataQueue<std::string>> streamqueue, std::string logfile = "")
            : SchwabDatabank(dbHandler, streamqueue, logfile)
        {
        }

        void parseStreamQueue(unsigned count)
        {
            SchwabDatabank::parseStreamQueue(count);
        }
    };

    SchwabDatabankTest()
    {
        dbHandler = std::make_shared<DatabaseHandlerMock>();
        streamqueue = std::make_shared<DataQueue<std::string>>();
        databankTester = std::make_shared<SchwabDatabankTester>(dbHandler, streamqueue);
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
    std::shared_ptr<DatabaseHandlerMock> dbHandler;
};

TEST_F(SchwabDatabankTest, testStartParsing)
{
    EXPECT_CALL(*dbHandler.get(), pushJsonData(testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandler.get(), pushCandle("TGT", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandler.get(), pushCandle("NVDA", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandler.get(), pushCandle("ORCL", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandler.get(), pushCandle("TSM", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandler.get(), pushCandle("QQQ", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandler.get(), pushCandle("MSFT", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandler.get(), pushCandle("OXY", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandler.get(), pushCandle("CAVA", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandler.get(), pushCandle("XOM", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandler.get(), pushCandle("AMD", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandler.get(), pushCandle("SPY", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandler.get(), pushCandle("DELL", testing::_)).WillRepeatedly(testing::Return());

    std::thread pushThread(&SchwabDatabankTest::pushStreamData, this, 10, bigLevelOneDataResponse);
    databankTester->parseStreamQueue(10);

    pushThread.join();

    EXPECT_EQ(databankTester->getChart("DELL").getMultiCandles().size(), 10);
    EXPECT_EQ(databankTester->getChart("SPY").getMultiCandles().size(), 10);
}