#include "DatabaseHandlerMock.h"
#include "SchwabClientMock.h"
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
        SchwabDatabankTester(std::shared_ptr<ISchwabClient> sClientMock,
            std::shared_ptr<IDatabaseHandler> dbHandlerMockMock,
            std::shared_ptr<DataQueue<std::string>> streamqueue, std::string logfile = "")
            : SchwabDatabank(sClientMock, dbHandlerMockMock, streamqueue, logfile)
        {
        }

        void parseStreamQueue(unsigned count)
        {
            SchwabDatabank::parseStreamQueue(count);
        }
    };

    SchwabDatabankTest()
    {
        sClientMock = std::make_shared<SchwabClientMock>();
        dbHandlerMock = std::make_shared<DatabaseHandlerMock>();
        streamqueue = std::make_shared<DataQueue<std::string>>();
        databankTester = std::make_shared<SchwabDatabankTester>(sClientMock, dbHandlerMock, streamqueue);
    }

    void pushStreamData(unsigned pushes, std::string data)
    {
        for (unsigned i = 0; i < pushes; i++)
        {
            streamqueue->push(data);
        }
    }

protected:
    std::shared_ptr<SchwabClientMock> sClientMock;
    std::shared_ptr<SchwabDatabankTester> databankTester;
    std::shared_ptr<DataQueue<std::string>> streamqueue;
    std::shared_ptr<DatabaseHandlerMock> dbHandlerMock;
};

TEST_F(SchwabDatabankTest, testStartParsing)
{
    EXPECT_CALL(*dbHandlerMock.get(), pushJsonData(testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("TGT", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("NVDA", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("ORCL", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("TSM", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("QQQ", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("MSFT", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("OXY", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("CAVA", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("XOM", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("AMD", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("SPY", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("DELL", testing::_)).WillRepeatedly(testing::Return());

    std::thread pushThread(&SchwabDatabankTest::pushStreamData, this, 10, bigLevelOneDataResponse);
    databankTester->parseStreamQueue(10);

    pushThread.join();

    EXPECT_EQ(databankTester->getChart("DELL").at(Timeframe::MINUTE).getMultiCandles().size(), 10);
    EXPECT_EQ(databankTester->getChart("SPY").at(Timeframe::MINUTE).getMultiCandles().size(), 10);
    EXPECT_EQ(databankTester->getChart("TGT").at(Timeframe::MINUTE).getMultiCandles().size(), 10);
}

TEST_F(SchwabDatabankTest, getCandlesFromDbTest)
{
    EXPECT_CALL(*dbHandlerMock.get(), getCandles("TGT", "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z")).WillOnce(testing::Return(std::vector<CandleStick>()));
    EXPECT_CALL(*dbHandlerMock.get(), getCandles("AMZN", "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z")).WillOnce(testing::Return(std::vector<CandleStick>{CandleStick()}));

    EXPECT_EQ(databankTester->getCandlesFromDb("TGT", "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z").size(), 0);
    EXPECT_EQ(databankTester->getCandlesFromDb("AMZN", "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z").size(), 1);
}

TEST_F(SchwabDatabankTest, getJsonDataFromDb)
{
    EXPECT_CALL(*dbHandlerMock.get(), getJsonData("2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z")).WillOnce(testing::Return(std::vector<std::string>()));
    EXPECT_CALL(*dbHandlerMock.get(), getJsonData("2021-01-01 00:00:00Z", "2021-01-02 00:00:00Z")).WillOnce(testing::Return(std::vector<std::string>{"data"}));

    EXPECT_EQ(databankTester->getJsonDataFromDb("2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z").size(), 0);
    EXPECT_EQ(databankTester->getJsonDataFromDb("2021-01-01 00:00:00Z", "2021-01-02 00:00:00Z").size(), 1);
}

TEST_F(SchwabDatabankTest, getCandlesFromClientTest)
{
    EXPECT_CALL(*sClientMock.get(), getPriceHistory("AMZN", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::DAILY, 1, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z", true, false))
        .WillOnce(testing::Return(PriceHistory{"AMZN", false, 0, 0, std::vector<Candle>{Candle()}}));

    EXPECT_EQ(databankTester->getCandlesFromClient("AMZN", Timeframe::MINUTE, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z").size(), 1);

    EXPECT_CALL(*sClientMock.get(), getPriceHistory("AMZN", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::DAILY, 5, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z", true, false))
        .WillOnce(testing::Return(PriceHistory{"AMZN", false, 0, 0, std::vector<Candle>{Candle()}}));

    EXPECT_EQ(databankTester->getCandlesFromClient("AMZN", Timeframe::FIVE, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z").size(), 1);

    EXPECT_CALL(*sClientMock.get(), getPriceHistory("AMZN", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::DAILY, 15, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z", true, false))
        .WillOnce(testing::Return(PriceHistory{"AMZN", false, 0, 0, std::vector<Candle>{Candle()}}));

    EXPECT_EQ(databankTester->getCandlesFromClient("AMZN", Timeframe::FIFTEEN, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z").size(), 1);

    EXPECT_CALL(*sClientMock.get(), getPriceHistory("AMZN", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::DAILY, 30, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z", true, false))
        .WillOnce(testing::Return(PriceHistory{"AMZN", false, 0, 0, std::vector<Candle>{Candle()}}));

    EXPECT_EQ(databankTester->getCandlesFromClient("AMZN", Timeframe::THIRTY, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z").size(), 1);

    EXPECT_CALL(*sClientMock.get(), getPriceHistory("AMZN", PriceHistoryPeriodType::YEAR, 1, PriceHistoryTimeFreq::DAILY, 1, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z", false, false))
        .WillOnce(testing::Return(PriceHistory{"AMZN", false, 0, 0, std::vector<Candle>{Candle()}}));

    EXPECT_EQ(databankTester->getCandlesFromClient("AMZN", Timeframe::DAILY, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z").size(), 1);

}