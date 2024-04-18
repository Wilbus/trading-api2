#include "InfluxDbPusherMock.h"
#include "SchwabDatabaseHandler.h"

#include <gtest/gtest.h>

using namespace databasehandlers;
using namespace database::mocks;

class SchwabDatabaseHandlerTest : public ::testing::Test
{
public:
    SchwabDatabaseHandlerTest()
    {
    }

protected:
    std::shared_ptr<SchwabDatabaseHandler> dbHandler;
    const std::string jsonPointName{"json_data"};
};

TEST_F(SchwabDatabaseHandlerTest, initTest)
{
    dbHandler = std::make_shared<SchwabDatabaseHandler>("testdb");
}

TEST_F(SchwabDatabaseHandlerTest, pushCandleTest)
{
    CandleStick candle;
    candle.price_open = 1.0;
    candle.price_high = 2.0;
    candle.price_low = 4.0;
    candle.price_close = 3.0;
    candle.volume = 5.0;
    candle.timestamp = 1713398340000;

    FieldValueMap expectedValueMap;
    expectedValueMap["open"] = 1.0;
    expectedValueMap["high"] = 2.0;
    expectedValueMap["low"] = 4.0;
    expectedValueMap["close"] = 3.0;
    expectedValueMap["volume"] = 5.0;
    expectedValueMap["timestamp"] = static_cast<uint64_t>(1234);

    EXPECT_CALL(InfluxDbPusherMock::inst(), pushRaw(1713398340000, "testSymbol", expectedValueMap));

    dbHandler = std::make_shared<SchwabDatabaseHandler>("testdb");
    dbHandler->pushCandle("testSymbol", candle);
}

TEST_F(SchwabDatabaseHandlerTest, getCandlesTest)
{
    FieldValueMap valueMap;
    valueMap["open"] = 1.0;
    valueMap["high"] = 2.0;
    valueMap["low"] = 4.0;
    valueMap["close"] = 3.0;
    valueMap["volume"] = 5.0;
    valueMap["timestamp"] = 1234.0;

    std::vector<FieldValueMap> valueMapVec;
    valueMapVec.push_back(valueMap);
    valueMapVec.push_back(valueMap);

    CandleStick expectedCandle;
    expectedCandle.price_open = 1.0;
    expectedCandle.price_high = 2.0;
    expectedCandle.price_low = 4.0;
    expectedCandle.price_close = 3.0;
    expectedCandle.volume = 5.0;
    expectedCandle.timestamp = 1234;

    EXPECT_CALL(InfluxDbPusherMock::inst(), pullRaw("testSymbol", "2024-04-15 00:00:00", "2024-04-17 00:00:00"))
        .WillOnce(testing::Return(valueMapVec));

    dbHandler = std::make_shared<SchwabDatabaseHandler>("testdb");
    auto candles = dbHandler->getCandles("testSymbol", "2024-04-15 00:00:00", "2024-04-17 00:00:00");

    ASSERT_EQ(candles.size(), 2);
    EXPECT_EQ(candles[0].price_open, expectedCandle.price_open);
    EXPECT_EQ(candles[0].price_high, expectedCandle.price_high);
    EXPECT_EQ(candles[0].price_low, expectedCandle.price_low);
    EXPECT_EQ(candles[0].price_close, expectedCandle.price_close);
    EXPECT_EQ(candles[0].volume, expectedCandle.volume);
    EXPECT_EQ(candles[0].timestamp, expectedCandle.timestamp);
}

TEST_F(SchwabDatabaseHandlerTest, pushJsonDataTest)
{
    std::string jsonData = "{\"key\":\"value\"}";

    FieldValueMap expectedValueMap;
    expectedValueMap["jsonfield"] = jsonData;

    EXPECT_CALL(InfluxDbPusherMock::inst(), pushRaw(jsonPointName, expectedValueMap));

    dbHandler = std::make_shared<SchwabDatabaseHandler>("testdb");
    dbHandler->pushJsonData(jsonData);
}

TEST_F(SchwabDatabaseHandlerTest, getJsonDataTest)
{
    FieldValueMap valueMap;
    valueMap["jsonfield"] = "{\"key\":\"value\"}";

    std::vector<FieldValueMap> valueMapVec;
    valueMapVec.push_back(valueMap);
    valueMapVec.push_back(valueMap);

    EXPECT_CALL(InfluxDbPusherMock::inst(), pullRaw(jsonPointName, "2024-04-15 00:00:00", "2024-04-17 00:00:00"))
        .WillOnce(testing::Return(valueMapVec));

    dbHandler = std::make_shared<SchwabDatabaseHandler>("testdb");
    auto jsonData = dbHandler->getJsonData("2024-04-15 00:00:00", "2024-04-17 00:00:00");

    ASSERT_EQ(jsonData.size(), 2);
    EXPECT_EQ(jsonData[0], "{\"key\":\"value\"}");
}