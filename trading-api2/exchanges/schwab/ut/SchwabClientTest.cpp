#include "RestClientCurlMock.h"
#include "SchwabClient.h"
#include "SchwabConfigsMock.h"
#include "SystemTimerMock.h"
#include "UriEncodeDecode.h"
#include "base64.hpp"
#include "schwabErrorTestValues.h"
#include "schwabOptionsTestValues.h"
#include "schwabtestauthvalues.h"
#include "schwabtestvalues.h"

#include <gtest/gtest.h>

using namespace schwabMarketData;
using namespace schwabAccountData;
using namespace testing;
using ::testing::InSequence;

class SchwabClientTest : public ::testing::Test
{
public:
    SchwabClientTest()
    {
        configMock = std::make_shared<SchwabConfigsMock>();
        restClientCurlMock = std::make_shared<RestClientCurlMock>();
        client = std::make_shared<SchwabClient>(configMock, restClientCurlMock);
    }

    void SetUp() override
    {
        stubAuthConfig.app_key = "app_key123";
        stubAuthConfig.app_secret = "app_secret123";
        stubAuthConfig.redirect_uri = "https://127.0.0.1";

        authCode.code = "authcode1234%40";
        authCode.granted_at_time = 1711778400000;
        refreshToken.token = "refresh1234";
        refreshToken.granted_at_time = 2711778400000;
        refreshToken.expires_at_time = 3711778400000;
        accessToken.token = "access1234%40";
        accessToken.granted_at_time = 4711778400000;
        accessToken.expires_at_time = 5711778400000;

        stubAuthConfig.authorization_code = authCode;
        stubAuthConfig.refresh_token = refreshToken;
        stubAuthConfig.access_token = accessToken;
    }

    std::set<std::string> expectedHeaders()
    {
        return std::set<std::string>{"accept: application/json", "Authorization: Bearer access1234@"};
    }

    void expectUpdateAccessTokenRequest()
    {
        std::string expectedPath = "/oauth/token";
        std::string content_type = "Content-Type: application/x-www-form-urlencoded";
        std::string authHeader =
            "Authorization: Basic " + base64::to_base64(stubAuthConfig.app_key + ":" + stubAuthConfig.app_secret);
        std::set<std::string> expectedHeaders{content_type, authHeader};
        std::string expectedBody = "grant_type=refresh_token&refresh_token=" + refreshToken.token;

        Token fakeSaveAccessToken;
        fakeSaveAccessToken.token = "ACCESS_TOKEN_HERE";
        fakeSaveAccessToken.granted_at_time = 1711937315000;
        fakeSaveAccessToken.expires_at_time = 1711937315000 + (1800 * 1000);

        {
            InSequence s;
            EXPECT_CALL(*configMock.get(), getAppKey()).WillOnce(Return(stubAuthConfig.app_key));
            EXPECT_CALL(*configMock.get(), getAppSecret()).WillOnce(Return(stubAuthConfig.app_secret));
            EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(authenticationEndpoint));
            EXPECT_CALL(*restClientCurlMock.get(), postResponse(expectedPath, expectedHeaders, expectedBody))
                .WillOnce(Return(createAccessTokenRespExample));
            EXPECT_CALL(utils::mocks::SystemTimerMock::inst(), nowMs()).Times(1).WillOnce(Return(1711937315000));
            EXPECT_CALL(*configMock.get(), saveAccessToken(fakeSaveAccessToken));
        }
    }

    void expectUpdateAccessTokenWhenInvalid()
    {
        std::string expectedPath = "/oauth/token";
        std::string content_type = "Content-Type: application/x-www-form-urlencoded";
        std::string authHeader =
            "Authorization: Basic " + base64::to_base64(stubAuthConfig.app_key + ":" + stubAuthConfig.app_secret);
        std::set<std::string> expectedHeaders{authHeader, content_type};
        std::string expectedBody = "grant_type=refresh_token&refresh_token=" + refreshToken.token;

        Token fakeSaveAccessToken;
        fakeSaveAccessToken.token = "ACCESS_TOKEN_HERE";
        fakeSaveAccessToken.granted_at_time = 1711937315000;
        fakeSaveAccessToken.expires_at_time = 1711937315000 + (1800 * 1000);

        {
            InSequence createAccessTokenSeq;

            EXPECT_CALL(*configMock.get(), getRefreshToken()).Times(1).WillOnce(Return(stubAuthConfig.refresh_token));
            EXPECT_CALL(*configMock.get(), getAppKey()).WillOnce(Return(stubAuthConfig.app_key));
            EXPECT_CALL(*configMock.get(), getAppSecret()).Times(1).WillOnce(Return(stubAuthConfig.app_secret));
            EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(authenticationEndpoint));
            EXPECT_CALL(*restClientCurlMock.get(), postResponse(expectedPath, expectedHeaders, expectedBody))
                .Times(1)
                .WillOnce(Return(createAccessTokenRespExample));
            EXPECT_CALL(utils::mocks::SystemTimerMock::inst(), nowMs()).Times(1).WillOnce(Return(1711937315000));

            EXPECT_CALL(*configMock.get(), saveAccessToken(fakeSaveAccessToken));
        }
    }

    void expectValidAccessToken()
    {
        {
            InSequence validAccessTokenSeq;
            EXPECT_CALL(utils::mocks::SystemTimerMock::inst(), nowMs())
                .WillOnce(Return(stubAuthConfig.access_token.expires_at_time - 305000));
            EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        }
    }

    void expectExpiredAccessToken()
    {
        {
            InSequence expiredAccessTokenSeq;
            EXPECT_CALL(utils::mocks::SystemTimerMock::inst(), nowMs())
                .Times(1)
                .WillOnce(Return(stubAuthConfig.access_token.expires_at_time - 295000));
            EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        }
    }

    void expectedGetOptionExpirations()
    {
        std::string expectedPath = "/expirationchain?symbol=AAPL";
        {
            InSequence getOptionExpirationSeq;

            EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
            EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
            EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
                .WillOnce(Return(expirationListExample));
            auto expirations = client->getOptionExpirations("AAPL");
            EXPECT_GT(expirations.size(), 0);
        }
    }

protected:
    std::shared_ptr<SchwabConfigsMock> configMock;
    std::shared_ptr<RestClientCurlMock> restClientCurlMock;
    std::shared_ptr<SchwabClient> client;

    AuthConfig stubAuthConfig;
    AuthorizationCode authCode;
    Token refreshToken;
    Token accessToken;

    std::string marketEndpoint{"https://api.schwabapi.com/marketdata/v1"};
    std::string authenticationEndpoint{"https://api.schwabapi.com/v1"};
    std::string accountsEndpoint{"https://api.schwabapi.com/trader/v1"};
};

TEST_F(SchwabClientTest, createAccessToken)
{
    std::string expectedPath = "/oauth/token";
    std::string content_type = "Content-Type: application/x-www-form-urlencoded";
    std::string authHeader =
        "Authorization: Basic " + base64::to_base64(stubAuthConfig.app_key + ":" + stubAuthConfig.app_secret);
    std::set<std::string> expectedHeaders{authHeader, content_type};
    std::string expectedBody =
        "grant_type=authorization_code&code=" + utils::url_decode(authCode.code) + "&redirect_uri=https://127.0.0.1";

    Token fakeSaveAccessToken;
    fakeSaveAccessToken.token = "ACCESS_TOKEN_HERE";
    fakeSaveAccessToken.granted_at_time = 1711937315000;
    fakeSaveAccessToken.expires_at_time = 1711937315000 + (1800 * 1000);

    Token fakeSaveRefreshToken;
    fakeSaveRefreshToken.token = "REFRESH_TOKEN_HERE";
    fakeSaveRefreshToken.granted_at_time = 1711937315000;
    fakeSaveRefreshToken.expires_at_time = 1711937315000 + (60 * 60 * 24 * 7 * 1000);

    {
        InSequence createAccessTokenSeq;

        EXPECT_CALL(*configMock.get(), getAppKey()).WillOnce(Return(stubAuthConfig.app_key));
        EXPECT_CALL(*configMock.get(), getAppSecret()).WillOnce(Return(stubAuthConfig.app_secret));
        EXPECT_CALL(*configMock.get(), getRedirectUri()).WillOnce(Return(stubAuthConfig.redirect_uri));
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(authenticationEndpoint));
        EXPECT_CALL(*restClientCurlMock.get(), postResponse(expectedPath, expectedHeaders, expectedBody))
            .WillOnce(Return(createAccessTokenRespExample));
        EXPECT_CALL(utils::mocks::SystemTimerMock::inst(), nowMs()).WillOnce(Return(1711937315000));

        EXPECT_CALL(*configMock.get(), saveAccessToken(fakeSaveAccessToken));
        EXPECT_CALL(*configMock.get(), saveRefreshToken(fakeSaveRefreshToken));
    }
    EXPECT_TRUE(client->createAccessToken(authCode.code));
}

TEST_F(SchwabClientTest, createAccessTokenResponseInvalid)
{
    std::string expectedPath = "/oauth/token";
    std::string content_type = "Content-Type: application/x-www-form-urlencoded";
    std::string authHeader =
        "Authorization: Basic " + base64::to_base64(stubAuthConfig.app_key + ":" + stubAuthConfig.app_secret);
    std::set<std::string> expectedHeaders{authHeader, content_type};
    std::string expectedBody =
        "grant_type=authorization_code&code=" + utils::url_decode(authCode.code) + "&redirect_uri=https://127.0.0.1";

    Token fakeSaveAccessToken;
    fakeSaveAccessToken.token = "ACCESS_TOKEN_HERE";
    fakeSaveAccessToken.granted_at_time = 1711937315000;
    fakeSaveAccessToken.expires_at_time = 1711937315000 + (1800 * 1000);

    {
        InSequence createAccessTokenSeq;

        EXPECT_CALL(*configMock.get(), getAppKey()).WillOnce(Return(stubAuthConfig.app_key));
        EXPECT_CALL(*configMock.get(), getAppSecret()).WillOnce(Return(stubAuthConfig.app_secret));
        EXPECT_CALL(*configMock.get(), getRedirectUri()).WillOnce(Return(stubAuthConfig.redirect_uri));
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(authenticationEndpoint));
        EXPECT_CALL(*restClientCurlMock.get(), postResponse(expectedPath, expectedHeaders, expectedBody))
            .WillOnce(Return(postErrorInvalidClient));
    }
    EXPECT_FALSE(client->createAccessToken(authCode.code));
}

TEST_F(SchwabClientTest, updatehAccessTokenRequest)
{
    expectUpdateAccessTokenRequest();
    EXPECT_TRUE(client->updateAccessToken(refreshToken.token));
}

TEST_F(SchwabClientTest, checkAccessTokenTest)
{
    Token fakeAccessToken;
    fakeAccessToken.expires_at_time = 1712196000000;
    EXPECT_CALL(*configMock.get(), getAccessToken()).WillRepeatedly(Return(fakeAccessToken));

    EXPECT_CALL(utils::mocks::SystemTimerMock::inst(), nowMs()).WillOnce(Return(1712196000000 - 295000));
    EXPECT_FALSE(client->checkAccessToken());

    EXPECT_CALL(utils::mocks::SystemTimerMock::inst(), nowMs()).WillOnce(Return(1712196000000 - 305000));
    EXPECT_TRUE(client->checkAccessToken());
}

TEST_F(SchwabClientTest, getQuotesCaughtException)
{
    std::set<std::string> symbols = {"SPY", "AAPL"};
    std::string path = R"(/quotes?symbols=AAPL%2CSPY&fields=quote&indicative=false)";

    expectValidAccessToken();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(path, expectedHeaders()))
            .WillOnce(Throw(std::runtime_error("")));
    }
    auto quotesmap = client->getEquityQuotes(symbols);
    EXPECT_EQ(quotesmap.size(), 0);
}

TEST_F(SchwabClientTest, getQuotesErrorResponse)
{
    std::set<std::string> symbols = {"SPY", "AAPL"};
    std::string path = R"(/quotes?symbols=AAPL%2CSPY&fields=quote&indicative=false)";

    expectValidAccessToken();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(path, expectedHeaders())).WillOnce(Return(genericError400));
    }
    auto quotesmap = client->getEquityQuotes(symbols);
    EXPECT_EQ(quotesmap.size(), 0);
}

TEST_F(SchwabClientTest, getQuotes)
{
    std::set<std::string> symbols = {"SPY", "AAPL"};
    std::string path = R"(/quotes?symbols=AAPL%2CSPY&fields=quote&indicative=false)";

    expectValidAccessToken();
    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(path, expectedHeaders()))
            .WillOnce(Return(multiEquityQuotesExample));
    }
    auto quotesmap = client->getEquityQuotes(symbols);
}

TEST_F(SchwabClientTest, getQuotesWithRefreshingAccessToken)
{
    std::set<std::string> symbols = {"SPY", "AAPL"};
    std::string path = R"(/quotes?symbols=AAPL%2CSPY&fields=quote&indicative=false)";

    expectExpiredAccessToken();
    expectUpdateAccessTokenWhenInvalid();

    {
        InSequence getQuotesSeq;

        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(path, expectedHeaders()))
            .WillOnce(Return(multiEquityQuotesExample));
    }
    auto quotesmap = client->getEquityQuotes(symbols);
}

TEST_F(SchwabClientTest, getOptionExpirationsCaughtException)
{
    std::string expectedPath = "/expirationchain?symbol=AAPL";

    expectValidAccessToken();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
            .WillOnce(Throw(std::runtime_error("")));
    }
    auto expirations = client->getOptionExpirations("AAPL");
    EXPECT_EQ(expirations.size(), 0);
}

TEST_F(SchwabClientTest, getOptionExpirationsErrorResponse)
{
    expectValidAccessToken();
    std::string expectedPath = "/expirationchain?symbol=AAPL";
    {
        InSequence getOptionExpirationSeq;

        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
            .WillOnce(Return(genericError400));
        auto expirations = client->getOptionExpirations("AAPL");
        EXPECT_EQ(expirations.size(), 0);
    }
}

TEST_F(SchwabClientTest, getOptionExpirations)
{
    expectValidAccessToken();
    expectedGetOptionExpirations();
}

TEST_F(SchwabClientTest, getOptionExpirationsWithUpdateAccessToken)
{
    std::string expectedPath = "/expirationchain?symbol=AAPL";

    expectExpiredAccessToken();
    expectUpdateAccessTokenWhenInvalid();
    expectedGetOptionExpirations();
}

TEST_F(SchwabClientTest, getPriceHistoryCaughtException)
{
    /*'https://api.schwabapi.com/marketdata/v1/pricehistory?symbol=SPY&periodType=year&period=1&frequencyType=daily&frequency=1&startDate=1710954774000&needExtendedHoursData=true&needPreviousClose=true'*/
    std::string expectedPath =
        "/pricehistory?symbol=SPY&periodType=year&period=1&frequencyType=daily&frequency=1&startDate="
        "1710892800000&needExtendedHoursData=true&needPreviousClose=true";

    expectValidAccessToken();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
            .WillOnce(Throw(std::runtime_error("")));
    }
    auto priceHistory = client->getPriceHistory(
        "SPY", PriceHistoryPeriodType::YEAR, 1, PriceHistoryTimeFreq::DAILY, 1, "2024-03-20", "", true, true);
    EXPECT_EQ(priceHistory.candles.size(), 0);
}

TEST_F(SchwabClientTest, getPriceHistoryNoEndDate)
{
    /*'https://api.schwabapi.com/marketdata/v1/pricehistory?symbol=SPY&periodType=year&period=1&frequencyType=daily&frequency=1&startDate=1710954774000&needExtendedHoursData=true&needPreviousClose=true'*/
    std::string expectedPath =
        "/pricehistory?symbol=SPY&periodType=year&period=1&frequencyType=daily&frequency=1&startDate="
        "1710892800000&needExtendedHoursData=true&needPreviousClose=true";

    expectValidAccessToken();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
            .WillOnce(Return(mockGetPriceHistoryResp));
    }
    auto priceHistory = client->getPriceHistory(
        "SPY", PriceHistoryPeriodType::YEAR, 1, PriceHistoryTimeFreq::DAILY, 1, "2024-03-20", "", true, true);
    EXPECT_EQ(priceHistory.candles.size(), 7);
}

TEST_F(SchwabClientTest, getPriceHistoryErrorResponse)
{
    /*'https://api.schwabapi.com/marketdata/v1/pricehistory?symbol=SPY&periodType=year&period=1&frequencyType=daily&frequency=1&startDate=1710954774000&needExtendedHoursData=true&needPreviousClose=true'*/
    std::string expectedPath =
        "/pricehistory?symbol=SPY&periodType=year&period=1&frequencyType=daily&frequency=1&startDate="
        "1710892800000&needExtendedHoursData=true&needPreviousClose=true";

    expectValidAccessToken();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
            .WillOnce(Return(genericError400));
    }
    auto priceHistory = client->getPriceHistory(
        "SPY", PriceHistoryPeriodType::YEAR, 1, PriceHistoryTimeFreq::DAILY, 1, "2024-03-20", "", true, true);
    EXPECT_EQ(priceHistory.candles.size(), 0);
}

TEST_F(SchwabClientTest, getPriceHistoryStartAndEndDates)
{
    std::string expectedPath =
        "/pricehistory?symbol=SPY&periodType=year&period=1&frequencyType=daily&frequency=1&startDate="
        "1710892800000&endDate=1711756800000&needExtendedHoursData=true&needPreviousClose=true";

    expectValidAccessToken();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
            .WillOnce(Return(mockGetPriceHistoryResp));
    }
    auto priceHistory = client->getPriceHistory(
        "SPY", PriceHistoryPeriodType::YEAR, 1, PriceHistoryTimeFreq::DAILY, 1, "2024-03-20", "2024-03-30", true, true);
    EXPECT_EQ(priceHistory.candles.size(), 7);
}

TEST_F(SchwabClientTest, getPriceHistoryStartAndEndDatesMinutes)
{
    std::string expectedPath =
        "/pricehistory?symbol=AAPL&periodType=day&period=10&frequencyType=minute&frequency=30&startDate="
        "1710892800000&needExtendedHoursData=true&needPreviousClose=true";

    expectValidAccessToken();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
            .WillOnce(Return(mockGetPriceHistoryResp));
    }
    auto priceHistory = client->getPriceHistory(
        "AAPL", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 30, "2024-03-20", "", true, true);
    EXPECT_GT(priceHistory.candles.size(), 0);
}

TEST_F(SchwabClientTest, getPriceHistoryStartAndEndDatesMinutesWithUpdateAccessToken)
{
    std::string expectedPath =
        "/pricehistory?symbol=AAPL&periodType=day&period=10&frequencyType=minute&frequency=30&startDate="
        "1710892800000&needExtendedHoursData=true&needPreviousClose=true";

    expectExpiredAccessToken();
    expectUpdateAccessTokenWhenInvalid();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
            .WillOnce(Return(mockGetPriceHistoryResp));
    }
    auto priceHistory = client->getPriceHistory(
        "AAPL", PriceHistoryPeriodType::DAY, 10, PriceHistoryTimeFreq::MINUTE, 30, "2024-03-20", "", true, true);
    EXPECT_GT(priceHistory.candles.size(), 0);
}

TEST_F(SchwabClientTest, getOptionChainCaughtException)
{
    std::string expectedPath = "/chains?symbol=AAPL&contractType=ALL&strikeCount=5&strategy=SINGLE";

    expectValidAccessToken();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
            .WillOnce(Throw(std::runtime_error("")));
    }
    auto optionChain = client->getOptionChain("AAPL", 5);
    EXPECT_EQ(optionChain.callExpDateMap.size(), 0);
    EXPECT_EQ(optionChain.putExpDateMap.size(), 0);
}

TEST_F(SchwabClientTest, getOptionChain)
{
    std::string expectedPath = "/chains?symbol=AAPL&contractType=ALL&strikeCount=5&strategy=SINGLE";

    expectValidAccessToken();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
            .WillOnce(Return(schwabOptionsExample_ALL_5Strikes));
    }
    auto optionChain = client->getOptionChain("AAPL", 5);
    EXPECT_GT(optionChain.callExpDateMap.size(), 0);
    EXPECT_GT(optionChain.putExpDateMap.size(), 0);
}

TEST_F(SchwabClientTest, getOptionChainErrorResponse)
{
    std::string expectedPath = "/chains?symbol=AAPL&contractType=ALL&strikeCount=5&strategy=SINGLE";

    expectValidAccessToken();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
            .WillOnce(Return(genericError400));
    }
    auto optionChain = client->getOptionChain("AAPL", 5);
    EXPECT_EQ(optionChain.callExpDateMap.size(), 0);
    EXPECT_EQ(optionChain.putExpDateMap.size(), 0);
}

TEST_F(SchwabClientTest, getOptionChainWithUpdateAccessToken)
{
    std::string expectedPath = "/chains?symbol=AAPL&contractType=ALL&strikeCount=5&strategy=SINGLE";

    expectExpiredAccessToken();
    expectUpdateAccessTokenWhenInvalid();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(marketEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
            .WillOnce(Return(schwabOptionsExample_ALL_5Strikes));
    }
    auto optionChain = client->getOptionChain("AAPL", 5);
    EXPECT_GT(optionChain.callExpDateMap.size(), 0);
    EXPECT_GT(optionChain.putExpDateMap.size(), 0);
}

TEST_F(SchwabClientTest, getUserPreference)
{
    std::string expectedPath = "/userPreference";

    expectValidAccessToken();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(accountsEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
            .WillOnce(Return(userPreferenceRespExample));
    }
    auto prefs = client->getUserPreferences();
    EXPECT_GT(prefs.accounts.size(), 0);
    EXPECT_GT(prefs.streamerInfo.size(), 0);
}

TEST_F(SchwabClientTest, getUserPreferenceWithErroResponse)
{
    std::string expectedPath = "/userPreference";

    expectValidAccessToken();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(accountsEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
            .WillOnce(Return(genericError400));
    }
    auto prefs = client->getUserPreferences();
    EXPECT_EQ(prefs.accounts.size(), 0);
    EXPECT_EQ(prefs.streamerInfo.size(), 0);
}

TEST_F(SchwabClientTest, getUserPreferenceWithUpdateAccessToken)
{
    std::string expectedPath = "/userPreference";

    expectExpiredAccessToken();
    expectUpdateAccessTokenWhenInvalid();

    {
        InSequence s;
        EXPECT_CALL(*restClientCurlMock.get(), setBaseEndpoint(accountsEndpoint));
        EXPECT_CALL(*configMock.get(), getAccessToken()).Times(1).WillOnce(Return(stubAuthConfig.access_token));
        EXPECT_CALL(*restClientCurlMock.get(), getResponse(expectedPath, expectedHeaders()))
            .WillOnce(Return(userPreferenceRespExample));
    }
    auto prefs = client->getUserPreferences();
    EXPECT_GT(prefs.accounts.size(), 0);
    EXPECT_GT(prefs.streamerInfo.size(), 0);
}