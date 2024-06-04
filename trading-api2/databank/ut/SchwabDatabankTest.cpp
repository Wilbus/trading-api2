#include "DatabaseHandlerMock.h"
#include "SchwabClientMock.h"
#include "SchwabDatabank.h"
#include "SystemTimerMock.h"
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
            std::shared_ptr<IDatabaseHandler> dbHandlerMockMock, std::shared_ptr<DataQueue<std::string>> streamqueue,
            std::string logfile = "")
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

    void setCurrTimeMsExpectation()
    {
        EXPECT_CALL(utils::mocks::SystemTimerMock::inst(), nowMs()).WillRepeatedly(testing::Return(mockCurrTimeMs));
    }

protected:
    std::shared_ptr<SchwabClientMock> sClientMock;
    std::shared_ptr<SchwabDatabankTester> databankTester;
    std::shared_ptr<DataQueue<std::string>> streamqueue;
    std::shared_ptr<DatabaseHandlerMock> dbHandlerMock;
    time_t mockCurrTimeMs{1717216292000};         // Sat, 01 Jun 2024 04:31:32 GMT
    time_t mockCurrTimeMsYearAgo{1685680292000};  // Sun, 01 Jun 2023 04:31:32 GMT
    time_t mockCurrTimeMsMonthAgo{1714624292000}; // Fri, 01 Jun 2023 04:31:32 GMT
    time_t mockCurrTimeMsWeekAgo{1716611492000};  // Fri, 25 May 2024 04:31:32 GMT
};


TEST_F(SchwabDatabankTest, testStartParsing)
{
    EXPECT_CALL(*dbHandlerMock.get(), pushJsonData(testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("TGT_minute", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("NVDA_minute", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("ORCL_minute", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("TSM_minute", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("QQQ_minute", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("MSFT_minute", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("OXY_minute", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("CAVA_minute", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("XOM_minute", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("AMD_minute", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("SPY_minute", testing::_)).WillRepeatedly(testing::Return());
    EXPECT_CALL(*dbHandlerMock.get(), pushCandle("DELL_minute", testing::_)).WillRepeatedly(testing::Return());

    std::thread pushThread(&SchwabDatabankTest::pushStreamData, this, 10, bigLevelOneDataResponse);
    databankTester->parseStreamQueue(10);

    pushThread.join();

    //one because data is the same timestamps and databank chartaggregator replaces candles with the same timestamp
    EXPECT_EQ(databankTester->getChart("DELL").at(Timeframe::MINUTE).getMultiCandles().size(), 1);
    EXPECT_EQ(databankTester->getChart("SPY").at(Timeframe::MINUTE).getMultiCandles().size(), 1);
    EXPECT_EQ(databankTester->getChart("TGT").at(Timeframe::MINUTE).getMultiCandles().size(), 1);
}

TEST_F(SchwabDatabankTest, getCandlesFromDbTest)
{
    EXPECT_CALL(*dbHandlerMock.get(), getCandles("TGT_minute", "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z"))
        .WillOnce(testing::Return(std::vector<CandleStick>()));
    EXPECT_CALL(*dbHandlerMock.get(), getCandles("AMZN_minute", "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z"))
        .WillOnce(testing::Return(std::vector<CandleStick>{CandleStick()}));

    EXPECT_EQ(databankTester->getCandlesFromDb("TGT", Timeframe::MINUTE, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z")
                  .size(),
        0);
    EXPECT_EQ(
        databankTester->getCandlesFromDb("AMZN", Timeframe::MINUTE, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z")
            .size(),
        1);
}

TEST_F(SchwabDatabankTest, getJsonDataFromDb)
{
    EXPECT_CALL(*dbHandlerMock.get(), getJsonData("2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z"))
        .WillOnce(testing::Return(std::vector<std::string>()));
    EXPECT_CALL(*dbHandlerMock.get(), getJsonData("2021-01-01 00:00:00Z", "2021-01-02 00:00:00Z"))
        .WillOnce(testing::Return(std::vector<std::string>{"data"}));

    EXPECT_EQ(databankTester->getJsonDataFromDb("2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z").size(), 0);
    EXPECT_EQ(databankTester->getJsonDataFromDb("2021-01-01 00:00:00Z", "2021-01-02 00:00:00Z").size(), 1);
}

TEST_F(SchwabDatabankTest, getCandlesFromClientTest)
{
    EXPECT_CALL(
        *sClientMock.get(), getPriceHistory("AMZN", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 1,
                                "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z", true, false))
        .WillOnce(testing::Return(PriceHistory{"AMZN", false, 0, 0, std::vector<Candle>{Candle()}}));

    EXPECT_EQ(
        databankTester->getCandlesFromClient("AMZN", Timeframe::MINUTE, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z")
            .size(),
        1);

    EXPECT_CALL(
        *sClientMock.get(), getPriceHistory("AMZN", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 5,
                                "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z", true, false))
        .WillOnce(testing::Return(PriceHistory{"AMZN", false, 0, 0, std::vector<Candle>{Candle()}}));

    EXPECT_EQ(
        databankTester->getCandlesFromClient("AMZN", Timeframe::FIVE, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z")
            .size(),
        1);

    EXPECT_CALL(
        *sClientMock.get(), getPriceHistory("AMZN", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 15,
                                "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z", true, false))
        .WillOnce(testing::Return(PriceHistory{"AMZN", false, 0, 0, std::vector<Candle>{Candle()}}));

    EXPECT_EQ(
        databankTester->getCandlesFromClient("AMZN", Timeframe::FIFTEEN, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z")
            .size(),
        1);

    EXPECT_CALL(
        *sClientMock.get(), getPriceHistory("AMZN", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 30,
                                "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z", true, false))
        .WillOnce(testing::Return(PriceHistory{"AMZN", false, 0, 0, std::vector<Candle>{Candle()}}));

    EXPECT_EQ(
        databankTester->getCandlesFromClient("AMZN", Timeframe::THIRTY, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z")
            .size(),
        1);

    EXPECT_CALL(
        *sClientMock.get(), getPriceHistory("AMZN", PriceHistoryPeriodType::YEAR, 1, PriceHistoryTimeFreq::DAILY, 1,
                                "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z", false, false))
        .WillOnce(testing::Return(PriceHistory{"AMZN", false, 0, 0, std::vector<Candle>{Candle()}}));

    EXPECT_EQ(
        databankTester->getCandlesFromClient("AMZN", Timeframe::DAILY, "2021-01-01 00:00:00Z", "2021-01-01 00:00:00Z")
            .size(),
        1);
}

TEST_F(SchwabDatabankTest, initializeDataTest)
{
    setCurrTimeMsExpectation();

    PriceHistory mockedSPYHistory;
    mockedSPYHistory.symbol = "SPY";
    mockedSPYHistory.candles.push_back(Candle());
    mockedSPYHistory.candles.push_back(Candle());

    PriceHistory mockedQQQHistory;
    mockedQQQHistory.symbol = "QQQ";
    mockedQQQHistory.candles.push_back(Candle());
    mockedQQQHistory.candles.push_back(Candle());

    EXPECT_CALL(*sClientMock.get(), getPriceHistory("SPY", PriceHistoryPeriodType::YEAR, 1, PriceHistoryTimeFreq::DAILY,
                                        1, mockCurrTimeMsYearAgo, mockCurrTimeMs, false, false))
        .WillOnce(testing::Return(mockedSPYHistory));
    EXPECT_CALL(*sClientMock.get(), getPriceHistory("QQQ", PriceHistoryPeriodType::YEAR, 1, PriceHistoryTimeFreq::DAILY,
                                        1, mockCurrTimeMsYearAgo, mockCurrTimeMs, false, false))
        .WillOnce(testing::Return(mockedQQQHistory));

    EXPECT_CALL(
        *sClientMock.get(), getPriceHistory("SPY", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 30,
                                mockCurrTimeMsMonthAgo, mockCurrTimeMs + 86400000, true, false))
        .WillOnce(testing::Return(mockedSPYHistory));
    EXPECT_CALL(
        *sClientMock.get(), getPriceHistory("QQQ", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 30,
                                mockCurrTimeMsMonthAgo, mockCurrTimeMs + 86400000, true, false))
        .WillOnce(testing::Return(mockedQQQHistory));

    EXPECT_CALL(
        *sClientMock.get(), getPriceHistory("SPY", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 5,
                                mockCurrTimeMsWeekAgo, mockCurrTimeMs + 86400000, true, false))
        .WillOnce(testing::Return(mockedSPYHistory));
    EXPECT_CALL(
        *sClientMock.get(), getPriceHistory("QQQ", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 5,
                                mockCurrTimeMsWeekAgo, mockCurrTimeMs + 86400000, true, false))
        .WillOnce(testing::Return(mockedQQQHistory));

    EXPECT_CALL(
        *sClientMock.get(), getPriceHistory("SPY", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 1,
                                mockCurrTimeMsWeekAgo, mockCurrTimeMs + 86400000, true, false))
        .WillOnce(testing::Return(mockedSPYHistory));
    EXPECT_CALL(
        *sClientMock.get(), getPriceHistory("QQQ", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 1,
                                mockCurrTimeMsWeekAgo, mockCurrTimeMs + 86400000, true, false))
        .WillOnce(testing::Return(mockedQQQHistory));

    EXPECT_NO_THROW(databankTester->initializeData(std::set<std::string>{"SPY", "QQQ"}));

    EXPECT_EQ(databankTester->getChart("SPY").at(Timeframe::DAILY).getMultiCandles().size(), 2);
    EXPECT_EQ(databankTester->getChart("QQQ").at(Timeframe::DAILY).getMultiCandles().size(), 2);

    EXPECT_EQ(databankTester->getChart("SPY").at(Timeframe::THIRTY).getMultiCandles().size(), 2);
    EXPECT_EQ(databankTester->getChart("QQQ").at(Timeframe::THIRTY).getMultiCandles().size(), 2);

    EXPECT_EQ(databankTester->getChart("SPY").at(Timeframe::FIVE).getMultiCandles().size(), 2);
    EXPECT_EQ(databankTester->getChart("QQQ").at(Timeframe::FIVE).getMultiCandles().size(), 2);

    EXPECT_EQ(databankTester->getChart("SPY").at(Timeframe::MINUTE).getMultiCandles().size(), 2);
    EXPECT_EQ(databankTester->getChart("QQQ").at(Timeframe::MINUTE).getMultiCandles().size(), 2);
}

TEST_F(SchwabDatabankTest, initializeFromDbTest)
{
    std::string fromTime = "2023-06-01 00:00:00";
    std::string toTime = "2024-06-01 00:00:00";

    EXPECT_CALL(*dbHandlerMock.get(), getCandles("QQQ_minute", fromTime, toTime))
        .WillOnce(testing::Return(std::vector<CandleStick>{CandleStick()}));
    EXPECT_CALL(*dbHandlerMock.get(), getCandles("SPY_minute", fromTime, toTime))
        .WillOnce(testing::Return(std::vector<CandleStick>{CandleStick()}));
    EXPECT_CALL(*dbHandlerMock.get(), getCandles("QQQ_five", fromTime, toTime))
        .WillOnce(testing::Return(std::vector<CandleStick>{CandleStick()}));
    EXPECT_CALL(*dbHandlerMock.get(), getCandles("SPY_five", fromTime, toTime))
        .WillOnce(testing::Return(std::vector<CandleStick>{CandleStick()}));
    EXPECT_CALL(*dbHandlerMock.get(), getCandles("QQQ_fifteen", fromTime, toTime))
        .WillOnce(testing::Return(std::vector<CandleStick>{CandleStick()}));
    EXPECT_CALL(*dbHandlerMock.get(), getCandles("SPY_fifteen", fromTime, toTime))
        .WillOnce(testing::Return(std::vector<CandleStick>{CandleStick()}));
    EXPECT_CALL(*dbHandlerMock.get(), getCandles("QQQ_thirty", fromTime, toTime))
        .WillOnce(testing::Return(std::vector<CandleStick>{CandleStick()}));
    EXPECT_CALL(*dbHandlerMock.get(), getCandles("SPY_thirty", fromTime, toTime))
        .WillOnce(testing::Return(std::vector<CandleStick>{CandleStick()}));
    EXPECT_CALL(*dbHandlerMock.get(), getCandles("QQQ_hourly", fromTime, toTime))
        .WillOnce(testing::Return(std::vector<CandleStick>{CandleStick()}));
    EXPECT_CALL(*dbHandlerMock.get(), getCandles("SPY_hourly", fromTime, toTime))
        .WillOnce(testing::Return(std::vector<CandleStick>{CandleStick()}));
    EXPECT_CALL(*dbHandlerMock.get(), getCandles("QQQ_daily", fromTime, toTime))
        .WillOnce(testing::Return(std::vector<CandleStick>{CandleStick()}));
    EXPECT_CALL(*dbHandlerMock.get(), getCandles("SPY_daily", fromTime, toTime))
        .WillOnce(testing::Return(std::vector<CandleStick>{CandleStick()}));

    EXPECT_NO_THROW(databankTester->initializeDataFromDb(std::set<std::string>{"SPY", "QQQ"}, fromTime, toTime));

    EXPECT_EQ(databankTester->getChart("SPY").at(Timeframe::MINUTE).getMultiCandles().size(), 1);
    EXPECT_EQ(databankTester->getChart("QQQ").at(Timeframe::MINUTE).getMultiCandles().size(), 1);
    EXPECT_EQ(databankTester->getChart("SPY").at(Timeframe::FIVE).getMultiCandles().size(), 1);
    EXPECT_EQ(databankTester->getChart("QQQ").at(Timeframe::FIVE).getMultiCandles().size(), 1);
    EXPECT_EQ(databankTester->getChart("SPY").at(Timeframe::FIFTEEN).getMultiCandles().size(), 1);
    EXPECT_EQ(databankTester->getChart("QQQ").at(Timeframe::FIFTEEN).getMultiCandles().size(), 1);
    EXPECT_EQ(databankTester->getChart("SPY").at(Timeframe::THIRTY).getMultiCandles().size(), 1);
    EXPECT_EQ(databankTester->getChart("QQQ").at(Timeframe::THIRTY).getMultiCandles().size(), 1);
    EXPECT_EQ(databankTester->getChart("SPY").at(Timeframe::HOURLY).getMultiCandles().size(), 1);
    EXPECT_EQ(databankTester->getChart("QQQ").at(Timeframe::HOURLY).getMultiCandles().size(), 1);
    EXPECT_EQ(databankTester->getChart("SPY").at(Timeframe::DAILY).getMultiCandles().size(), 1);
    EXPECT_EQ(databankTester->getChart("QQQ").at(Timeframe::DAILY).getMultiCandles().size(), 1);
}