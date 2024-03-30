#include "TradierData.h"

#include "json.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

TradierData::TradierData(std::shared_ptr<IRestClient> restClient, std::shared_ptr<IStreamHandler> streamHandler)
    : restClient(restClient)
    , streamHandler(streamHandler)
{
}

TradierData::TradierData(std::set<std::string> product_ids, std::string apiToken,
    std::shared_ptr<IRestClient> restClient, std::shared_ptr<IStreamHandler> streamHandler)
    : product_ids(product_ids)
    , apiToken(apiToken)
    , restClient(restClient)
    , streamHandler(streamHandler)
    , tradexQue(std::make_shared<DataQueue<Tradex>>())
{
}

httplib::Headers TradierData::headers() const
{
    //clang-format off
    std::string bearer = "Bearer " + apiToken;

    return {{"Accept", "application/json"}, {"Authorization", bearer.c_str()}};
    //clang-format on
}

AccessToken TradierData::getAccessToken()
{
    std::string path = "/v1/oauth/accesstoken";
    std::string resp = restClient->postResponse(path, headers());
    return parseGetAccessToken(resp);
}

AccessToken TradierData::parseGetAccessToken(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    AccessToken tok;
    PARSE_STRING(tok.access_token, "access_token", d);
    PARSE_INT(tok.expires_in, "expires_in", d);
    PARSE_STRING(tok.issued_at, "issued_at", d);
    return tok;
}

std::string TradierData::getMarketSessionId()
{
    std::string path = "/v1/markets/events/session";
    std::string resp = restClient->postResponse(path, headers());
    return parseSessionId(resp);
}

std::string TradierData::getAccountSessionId()
{
    std::string path = "/v1/accounts/events/session";
    std::string resp = restClient->postResponse(path, headers());
    return parseSessionId(resp);
}

std::string TradierData::parseSessionId(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    if (d.HasMember("stream") && d["stream"].IsObject())
    {
        auto streamObj = d["stream"].GetObject();
        std::string seshid = streamObj["sessionid"].GetString();
        return seshid;
    }
    else
    {
        throw std::runtime_error("couldn't parse sessionid response");
    }
}

void TradierData::startMarketStream()
{
    std::string seshId = getMarketSessionId();
    std::printf("%s\n", seshId.c_str());
    streamHandler->setSeshId(seshId);
    streamHandler->setProductIds(product_ids);
    streamHandler->run();
}

void TradierData::parseMarketStream()
{
    auto replies = streamHandler->repliesQueue();
    while (!replies->isEmpty())
    {
        try
        {
            auto jsonstring = replies->front();
            replies->pop();

            rapidjson::Document d;
            d.Parse(jsonstring.c_str());
            rapidjson::StringBuffer s;

            std::string type;
            PARSE_STRING(type, "type", d);
            if (type == "quote")
            {
            }
            else if (type == "trade")
            {
            }
            else if (type == "summary")
            {
            }
            else if (type == "timesale")
            {
            }
            else if (type == "tradex")
            {
                auto tradex = parseTradex(jsonstring);
                tradexQue->push(tradex);
            }
            else
            {
                std::printf("error parsing type\n");
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

Quote TradierData::parseQuote(std::string jsonstring)
{
    (void)jsonstring;
    return {};
}

Trade TradierData::parseTrade(std::string jsonstring)
{
    (void)jsonstring;
    return {};
}

Summary TradierData::parseSummary(std::string jsonstring)
{
    (void)jsonstring;
    return {};
}

TimeSale TradierData::parseTimeSale(std::string jsonstring)
{
    (void)jsonstring;
    return {};
}

Tradex TradierData::parseTradex(std::string jsonstring)
{
    Tradex tradex;
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    PARSE_STRING(tradex.symbol, "symbol", d);
    PARSE_STRING(tradex.exch, "exch", d);
    PARSE_DOUBLESTRING(tradex.price, "price", d);
    PARSE_STRING_TO_UINT64(tradex.size, "size", d);
    PARSE_STRING_TO_UINT64(tradex.cvol, "cvol", d);
    PARSE_STRING_TO_UINT64(tradex.date, "date", d);
    PARSE_DOUBLESTRING(tradex.last, "last", d);
    return tradex;
}

std::shared_ptr<DataQueue<Tradex>> TradierData::getTradexQueue()
{
    return tradexQue;
}

std::string TradierData::getUserProfile()
{
    std::string path = "/v1/user/profile";

    return "";
}