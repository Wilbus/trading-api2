#include "RestClientMock.h"
#include "StreamHandlerMock.h"
#include "TradierData.h"

#include <gtest/gtest.h>

namespace {
using namespace testing;

class TradierDataTest : public ::testing::Test
{
public:
    TradierDataTest()
        : restClientMock(std::make_shared<RestClientMock>())
        , streamerMock(std::make_shared<StreamHandlerMock>())
        , tdata(product_ids, apiToken, restClientMock, streamerMock)
    {
    }

    httplib::Headers headers() const
    {
        std::string apiToken = "1234";
        std::string bearer = "Bearer " + apiToken;

        return {{"Accept", "application/json"}, {"Authorization", bearer.c_str()}};
    }

protected:
    std::set<std::string> product_ids{"MSFT", "SPY"};
    std::string apiToken{"1234"};
    std::shared_ptr<RestClientMock> restClientMock;
    std::shared_ptr<StreamHandlerMock> streamerMock;
    TradierData tdata;
};

TEST_F(TradierDataTest, getAccessTokenTest)
{
    std::string path = "/v1/oauth/accesstoken";
    // clang-format off
    std::string retVal = 
    R"({
    "access_token": "accesstoken",
    "expires_in": 86399,
    "issued_at": "2014-05-28T09:33:35-04:00",
    "scope": "read write trade market stream",
    "status": "approved"
    })";
    // clang=format on
    EXPECT_CALL(*(restClientMock.get()), postResponse(path, headers())).WillOnce(Return(retVal));
    AccessToken token = tdata.getAccessToken();
    EXPECT_EQ(token.access_token, "accesstoken");
    EXPECT_EQ(token.expires_in, 86399);
    EXPECT_EQ(token.issued_at, "2014-05-28T09:33:35-04:00");
}

TEST_F(TradierDataTest, getMarketSessionIdTest)
{
    std::string path = "/v1/markets/events/session";
    // clang-format off
    std::string retVal = 
    R"({
    "stream": {
        "url": "https://stream.tradier.com/v1/markets/events",
        "sessionid": "c8638963-a6d4-4fb9-9bc6-e25fbd8c60c3"
    }
    })";
    // clang=format on
    EXPECT_CALL(*(restClientMock.get()), postResponse(path, headers())).WillOnce(Return(retVal));
    auto seshid = tdata.getMarketSessionId();
    EXPECT_EQ(seshid, "c8638963-a6d4-4fb9-9bc6-e25fbd8c60c3");
}

TEST_F(TradierDataTest, getAccountSessionIdTest)
{
    std::string path = "/v1/accounts/events/session";
    // clang-format off
    std::string retVal = 
    R"({
    "stream": {
        "url": "https://stream.tradier.com/v1/accounts/events",
        "sessionid": "c8638963-a6d4-4fb9-9bc6-e25fbd8c60c3"
    }
    })";
    // clang=format on
    EXPECT_CALL(*(restClientMock.get()), postResponse(path, headers())).WillOnce(Return(retVal));
    auto seshid = tdata.getAccountSessionId();
    EXPECT_EQ(seshid, "c8638963-a6d4-4fb9-9bc6-e25fbd8c60c3");
}

TEST_F(TradierDataTest, startMarketStreamTest)
{
    std::string path = "/v1/markets/events/session";
    // clang-format off
    std::string retVal = 
    R"({
    "stream": {
        "url": "https://stream.tradier.com/v1/markets/events",
        "sessionid": "c8638963-a6d4-4fb9-9bc6-e25fbd8c60c3"
    }
    })";
    // clang-format on
    EXPECT_CALL(*(restClientMock.get()), postResponse(path, headers())).WillOnce(Return(retVal));
    EXPECT_CALL(*(streamerMock.get()), setSeshId("c8638963-a6d4-4fb9-9bc6-e25fbd8c60c3"));
    EXPECT_CALL(*(streamerMock.get()), setProductIds(product_ids));
    EXPECT_CALL(*(streamerMock.get()), run());
    tdata.startMarketStream();
}

TEST_F(TradierDataTest, parseMarketStreamTest)
{
    // clang-format off
    std::string quote =
    R"({
        "type": "quote",
        "symbol": "SPY",
        "bid": 281.84,
        "bidsz": 60,
        "bidexch": "M",
        "biddate": "1557757189000",
        "ask": 281.85,
        "asksz": 6,
        "askexch": "Z",
        "askdate": "1557757190000"
        })";
    std::string trade =
    R"({
        "type": "trade",
        "symbol": "SPY",
        "exch": "J",
        "price": "281.85",
        "size": "100",
        "cvol": "27978993",
        "date": "1557757190000",
        "last": "281.85"
        })";
    std::string summary =
    R"({
        "type": "summary",
        "symbol": "SPY",
        "open": "282.42",
        "high": "283.49",
        "low": "281.07",
        "prevClose": "288.1"
        })";
    std::string timesale =
    R"({
        "type": "timesale",
        "symbol": "SPY",
        "exch": "Q",
        "bid": "282.08",
        "ask": "282.09",
        "last": "282.09",
        "size": "100",
        "date": "1557758874355",
        "seq": 352795,
        "flag": "",
        "cancel": false,
        "correction": false,
        "session": "normal"
        })";
    std::string tradex =
    R"({
        "type": "tradex",
        "symbol": "SPY",
        "exch": "J",
        "price": "281.85",
        "size": "100",
        "cvol": "27978993",
        "date": "1557757190000",
        "last": "281.85"
        })";
    //clang-format on
    std::shared_ptr<DataQueue<std::string>> mockQueue = std::make_shared<DataQueue<std::string>>();
    mockQueue->push(quote);
    mockQueue->push(trade);
    mockQueue->push(summary);
    mockQueue->push(timesale);
    mockQueue->push(tradex);

    EXPECT_CALL(*(streamerMock.get()), repliesQueue).WillOnce(Return(mockQueue));

    tdata.parseMarketStream();
    auto tradexstruct = tdata.getTradexQueue()->front();
    EXPECT_EQ(tradexstruct.symbol, "SPY");
    EXPECT_EQ(tradexstruct.exch, "J");
    EXPECT_EQ(tradexstruct.price, 281.85);
    EXPECT_EQ(tradexstruct.size, 100);
    EXPECT_EQ(tradexstruct.cvol, 27978993);
    EXPECT_EQ(tradexstruct.date, 1557757190000);
    EXPECT_EQ(tradexstruct.last, 281.85);
    tdata.getTradexQueue()->pop();
    EXPECT_TRUE(tdata.getTradexQueue()->isEmpty());
}

};