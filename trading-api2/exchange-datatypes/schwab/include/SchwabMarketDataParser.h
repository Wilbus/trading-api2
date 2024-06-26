#pragma once

#include "SchwabMarketDataTypes.h"
#include "json.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#include <set>

namespace schwabMarketData {
// TODO: use json.h macros for all responses and ensure checking if member exists before accessing

std::map<std::string, QuoteEquityResponse> parseEquityQuotes(std::set<std::string> symbols, std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    std::map<std::string, QuoteEquityResponse> quotesMap;

    for (const auto& symbol : symbols)
    {
        // TODO: add parsing fundamentals, extended market quotes
        QuoteEquityResponse quoteresp;

        if (d[symbol.c_str()].IsObject())
        {
            auto equityresp = d[symbol.c_str()].GetObject();

            std::string assetMainTypeStr;
            std::string assetSubtypeStr;
            PARSE_STRING(assetMainTypeStr, "assetMainType", equityresp);
            PARSE_STRING(assetSubtypeStr, "assetSubType", equityresp);
            quoteresp.assetMainType = stringToAssetMainType.at(assetMainTypeStr);
            quoteresp.assetSubType = stringToAssetSubType.at(assetSubtypeStr);
            // quoteresp.ssid = equityresp["ssid"].GetInt64();
            PARSE_UINT64(quoteresp.ssid, "ssid", equityresp);
            // quoteresp.symbol = equityresp["symbol"].GetString();
            PARSE_STRING(quoteresp.symbol, "symbol", equityresp);

            if (equityresp["quote"].IsObject())
            {
                auto quotejson = equityresp["quote"].GetObject();

                // quoteresp.quote.yearHigh = quotejson["52WeekHigh"].GetDouble();
                PARSE_DOUBLE(quoteresp.quote.yearHigh, "52WeekHigh", quotejson);
                // quoteresp.quote.yearLow = quotejson["52WeekLow"].GetDouble();
                PARSE_DOUBLE(quoteresp.quote.yearLow, "52WeekLow", quotejson);
                // quoteresp.quote.askMICId = quotejson["askMICId"].GetString();
                PARSE_STRING(quoteresp.quote.askMICId, "askMICId", quotejson);
                // quoteresp.quote.askPrice = quotejson["askPrice"].GetDouble();
                PARSE_DOUBLE(quoteresp.quote.askPrice, "askPrice", quotejson);
                // quoteresp.quote.askSize = quotejson["askSize"].GetUint();
                PARSE_UINT(quoteresp.quote.askSize, "askSize", quotejson);
                // quoteresp.quote.askTime = quotejson["askTime"].GetUint64();
                PARSE_UINT64(quoteresp.quote.askTime, "askTime", quotejson);
                // quoteresp.quote.bidMICId = quotejson["bidMICId"].GetString();
                PARSE_STRING(quoteresp.quote.bidMICId, "bidMICId", quotejson);
                // quoteresp.quote.bidPrice = quotejson["bidPrice"].GetDouble();
                PARSE_DOUBLE(quoteresp.quote.bidPrice, "bidPrice", quotejson);
                // quoteresp.quote.bidSize = quotejson["bidSize"].GetUint();
                PARSE_UINT(quoteresp.quote.bidSize, "bidSize", quotejson);
                // quoteresp.quote.bidTime = quotejson["bidTime"].GetUint64();
                PARSE_UINT64(quoteresp.quote.bidTime, "bidTime", quotejson);
                // quoteresp.quote.closePrice = quotejson["closePrice"].GetDouble();
                PARSE_DOUBLE(quoteresp.quote.closePrice, "closePrice", quotejson);
                // quoteresp.quote.highPrice = quotejson["highPrice"].GetDouble();
                PARSE_DOUBLE(quoteresp.quote.highPrice, "highPrice", quotejson);
                // quoteresp.quote.lastMICId = quotejson["lastMICId"].GetString();
                PARSE_STRING(quoteresp.quote.lastMICId, "lastMICId", quotejson);
                // quoteresp.quote.lastPrice = quotejson["lastPrice"].GetDouble();
                PARSE_DOUBLE(quoteresp.quote.lastPrice, "lastPrice", quotejson);
                // quoteresp.quote.lastSize = quotejson["lastSize"].GetUint();
                PARSE_UINT(quoteresp.quote.lastSize, "lastSize", quotejson);
                // quoteresp.quote.lowPrice = quotejson["lowPrice"].GetDouble();
                PARSE_DOUBLE(quoteresp.quote.lowPrice, "lowPrice", quotejson);
                // quoteresp.quote.mark = quotejson["mark"].GetDouble();
                PARSE_DOUBLE(quoteresp.quote.mark, "mark", quotejson);
                // quoteresp.quote.markChange = quotejson["markChange"].GetDouble();
                PARSE_DOUBLE(quoteresp.quote.markChange, "markChange", quotejson);
                // quoteresp.quote.markPercentChange = quotejson["markPercentChange"].GetDouble();
                PARSE_DOUBLE(quoteresp.quote.markPercentChange, "markPercentChange", quotejson);
                // quoteresp.quote.openPrice = quotejson["openPrice"].GetDouble();
                PARSE_DOUBLE(quoteresp.quote.openPrice, "openPrice", quotejson);
                // quoteresp.quote.postMarketChange = quotejson["postMarketChange"].GetDouble();
                PARSE_DOUBLE(quoteresp.quote.postMarketChange, "postMarketChange", quotejson);
                // quoteresp.quote.quoteTime = quotejson["quoteTime"].GetUint64();
                PARSE_UINT64(quoteresp.quote.quoteTime, "quoteTime", quotejson);
                // quoteresp.quote.securityStatus = quotejson["securityStatus"].GetString();
                PARSE_STRING(quoteresp.quote.securityStatus, "securityStatus", quotejson);
                // quoteresp.quote.totalVolume = quotejson["totalVolume"].GetUint64();
                PARSE_UINT64(quoteresp.quote.totalVolume, "totalVolume", quotejson);
                // quoteresp.quote.tradeTime = quotejson["tradeTime"].GetUint64();
                PARSE_UINT64(quoteresp.quote.tradeTime, "tradeTime", quotejson);

                quotesMap[symbol] = quoteresp;
            }
        }
    }

    return quotesMap;
}

PriceHistory parsePriceHistory(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    PriceHistory prices;
    // prices.symbol = d["symbol"].GetString();
    PARSE_STRING(prices.symbol, "symbol", d);
    // prices.empty = d["empty"].GetBool();
    PARSE_BOOL(prices.empty, "empty", d);
    // prices.previousClose = d["previousClose"].GetDouble();
    PARSE_DOUBLE(prices.previousClose, "previousClose", d);
    // prices.previousCloseDate = d["previousCloseDate"].GetUint64();
    PARSE_UINT64(prices.previousCloseDate, "previousCloseDate", d);
    auto candlesjson = d["candles"].GetArray();
    for (const auto& cand : candlesjson)
    {
        Candle c;
        // c.open = cand["open"].GetDouble();
        PARSE_DOUBLE(c.open, "open", cand);
        // c.high = cand["high"].GetDouble();
        PARSE_DOUBLE(c.high, "high", cand);
        // c.low = cand["low"].GetDouble();
        PARSE_DOUBLE(c.low, "low", cand);
        // c.close = cand["close"].GetDouble();
        PARSE_DOUBLE(c.close, "close", cand);
        // c.volume = cand["volume"].GetUint64();
        PARSE_UINT64(c.volume, "volume", cand);
        // c.datetime = cand["datetime"].GetUint64();
        PARSE_UINT64(c.datetime, "datetime", cand);

        prices.candles.push_back(c);
    }

    return prices;
}

std::vector<OptionExpiration> parseOptionExpirations(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    if (!d.IsObject())
    {
        return {};
    }

    std::vector<OptionExpiration> exps;

    if (d.HasMember("expirationList") && d["expirationList"].IsArray())
    {
        auto expsjson = d["expirationList"].GetArray();
        for (const auto& expjson : expsjson)
        {
            OptionExpiration oe;
            // oe.expirationDate = expjson["expirationDate"].GetString();
            PARSE_STRING(oe.expirationDate, "expirationDate", expjson);
            // oe.daysToExpiration = expjson["daysToExpiration"].GetInt();
            PARSE_INT(oe.daysToExpiration, "daysToExpiration", expjson);
            // oe.expirationType = expjson["expirationType"].GetString();
            PARSE_STRING(oe.expirationType, "expirationType", expjson);
            // oe.standard = expjson["standard"].GetBool();
            PARSE_BOOL(oe.standard, "standard", expjson);

            exps.push_back(oe);
        }
    }

    return exps;
}

OptionContract parseOptionContract(const rapidjson::Value& optionContractObj)
{
    OptionContract optionContract;
    PARSE_STRING(optionContract.putCall, "putCall", optionContractObj);
    PARSE_STRING(optionContract.symbol, "symbol", optionContractObj);
    PARSE_STRING(optionContract.exchangeName, "exchangeName", optionContractObj);
    PARSE_DOUBLE(optionContract.bidPrice, "bid", optionContractObj);
    PARSE_DOUBLE(optionContract.askPrice, "ask", optionContractObj);
    PARSE_DOUBLE(optionContract.lastPrice, "last", optionContractObj);
    PARSE_DOUBLE(optionContract.markPrice, "mark", optionContractObj);
    PARSE_UINT(optionContract.bidSize, "bidSize", optionContractObj);
    PARSE_UINT(optionContract.askSize, "askSize", optionContractObj);
    PARSE_STRING(optionContract.bidAskSize, "bidAskSize", optionContractObj);
    PARSE_UINT(optionContract.lastSize, "lastSize", optionContractObj);
    PARSE_DOUBLE(optionContract.highPrice, "highPrice", optionContractObj);
    PARSE_DOUBLE(optionContract.lowPrice, "lowPrice", optionContractObj);
    PARSE_DOUBLE(optionContract.openPrice, "openPrice", optionContractObj);
    PARSE_DOUBLE(optionContract.closePrice, "closePrice", optionContractObj);
    PARSE_UINT64(optionContract.totalVolume, "totalVolume", optionContractObj);
    PARSE_UINT64(optionContract.quoteTimeInLong, "quoteTimeInLong", optionContractObj);
    PARSE_UINT64(optionContract.tradeTimeInlong, "tradeTimeInLong", optionContractObj);
    PARSE_DOUBLE(optionContract.netChange, "netChange", optionContractObj);
    PARSE_DOUBLE(optionContract.volatility, "volatility", optionContractObj);
    PARSE_DOUBLE(optionContract.delta, "delta", optionContractObj);
    PARSE_DOUBLE(optionContract.gamma, "gamma", optionContractObj);
    PARSE_DOUBLE(optionContract.theta, "theta", optionContractObj);
    PARSE_DOUBLE(optionContract.vega, "vega", optionContractObj);
    PARSE_DOUBLE(optionContract.rho, "rho", optionContractObj);
    PARSE_DOUBLE(optionContract.openInterest, "openInterest", optionContractObj);
    PARSE_DOUBLE(optionContract.timeValue, "timeValue", optionContractObj);
    PARSE_DOUBLE(optionContract.theoreticalOptionValue, "theoreticalOptionValue", optionContractObj);
    PARSE_DOUBLE(optionContract.theoreticalVolatility, "theoreticalVolatility", optionContractObj);
    PARSE_DOUBLE(optionContract.strikePrice, "strikePrice", optionContractObj);
    PARSE_STRING(optionContract.expirationDate, "expirationDate", optionContractObj);
    PARSE_UINT(optionContract.daysToExpiration, "daysToExpiration", optionContractObj);
    PARSE_STRING(optionContract.expirationType, "expirationType", optionContractObj);
    PARSE_UINT64(optionContract.lastTradingDay, "lastTradingDay", optionContractObj);
    PARSE_DOUBLE(optionContract.multiplier, "multiplier", optionContractObj);
    PARSE_DOUBLE(optionContract.percentChange, "percentChange", optionContractObj);
    PARSE_DOUBLE(optionContract.markChange, "markChange", optionContractObj);
    PARSE_DOUBLE(optionContract.markPercentChange, "markPercentChange", optionContractObj);
    PARSE_DOUBLE(optionContract.intrinsicValue, "intrinsicValue", optionContractObj);
    PARSE_DOUBLE(optionContract.extrinsicValue, "extrinsicValue", optionContractObj);
    PARSE_STRING(optionContract.optionRoot, "optionRoot", optionContractObj);
    PARSE_DOUBLE(optionContract.high52Week, "high52Week", optionContractObj);
    PARSE_DOUBLE(optionContract.low52Week, "low52Week", optionContractObj);
    PARSE_BOOL(optionContract.pennyPilot, "pennyPilot", optionContractObj);
    PARSE_BOOL(optionContract.nonStandard, "nonStandard", optionContractObj);
    PARSE_BOOL(optionContract.inTheMoney, "inTheMoney", optionContractObj);
    PARSE_BOOL(optionContract.pennyPilot, "pennyPilot", optionContractObj);
    return optionContract;
}

OptionChain parseOptionChain(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    OptionChain optionChain;

    PARSE_STRING(optionChain.symbol, "symbol", d);
    PARSE_STRING(optionChain.status, "status", d);
    std::string strategy;
    PARSE_STRING(strategy, "strategy", d);
    optionChain.strategy = optionStrategyMap.at(strategy);
    PARSE_DOUBLE(optionChain.interval, "interval", d);
    PARSE_BOOL(optionChain.isDelayed, "isDelayed", d);
    PARSE_BOOL(optionChain.isIndex, "isIndex", d);
    PARSE_DOUBLE(optionChain.daysToExpiration, "daysToExpiration", d);
    PARSE_DOUBLE(optionChain.interestRate, "interestRate", d);
    PARSE_DOUBLE(optionChain.underlyingPrice, "underlyingPrice", d);
    PARSE_DOUBLE(optionChain.volatility, "volatility", d);

    auto optionCallMapObj = d["callExpDateMap"].GetObject();
    for (rapidjson::Value::ConstMemberIterator callExpDateObj = optionCallMapObj.MemberBegin();
         callExpDateObj != optionCallMapObj.MemberEnd();
         ++callExpDateObj)
    {
        if (callExpDateObj->name.GetType() != rapidjson::kStringType)
        {
            throw std::runtime_error("callExpDateObjMap keys are not strings");
        }
        if (callExpDateObj->value.GetType() != rapidjson::kObjectType)
        {
            throw std::runtime_error("callExpDateObjMap key to value is not an obj");
        }

        OptionExpDate expdate = callExpDateObj->name.GetString();
        StrikesChain strikes;
        auto strikesObj = callExpDateObj->value.GetObject();

        for (const auto& strikeObj : strikesObj)
        {
            if (strikeObj.name.GetType() != rapidjson::kStringType)
            {
                throw std::runtime_error("strikeobj key is not a string");
            }
            if (strikeObj.value.GetType() != rapidjson::kArrayType)
            {
                throw std::runtime_error("strikeobj key to value is not an array");
            }

            // assuming only 1 element per strike array for SINGLE strategy type
            for (const auto& optionContractObj : strikeObj.value.GetArray())
            {
                auto contract = parseOptionContract(optionContractObj);
                strikes.emplace(contract);
                break;
            }
        }

        optionChain.callExpDateMap[expdate] = strikes;
    }

    auto optionPutMapObj = d["putExpDateMap"].GetObject();
    for (rapidjson::Value::ConstMemberIterator putExpDateObj = optionPutMapObj.MemberBegin();
         putExpDateObj != optionPutMapObj.MemberEnd();
         ++putExpDateObj)
    {
        if (putExpDateObj->name.GetType() != rapidjson::kStringType)
        {
            throw std::runtime_error("putExpDateObjMap keys are not strings");
        }
        if (putExpDateObj->value.GetType() != rapidjson::kObjectType)
        {
            throw std::runtime_error("putExpDateObjMap key to value is not an obj");
        }

        OptionExpDate expdate = putExpDateObj->name.GetString();
        StrikesChain strikes;
        auto strikesObj = putExpDateObj->value.GetObject();

        for (const auto& strikeObj : strikesObj)
        {
            if (strikeObj.name.GetType() != rapidjson::kStringType)
            {
                throw std::runtime_error("strikeobj key is not a string");
            }
            if (strikeObj.value.GetType() != rapidjson::kArrayType)
            {
                throw std::runtime_error("strikeobj key to value is not an array");
            }

            // assuming only 1 element per strike array for SINGLE strategy type
            for (const auto& optionContractObj : strikeObj.value.GetArray())
            {
                auto contract = parseOptionContract(optionContractObj);
                strikes.emplace(contract);
                break;
            }
        }

        optionChain.putExpDateMap[expdate] = strikes;
    }

    return optionChain;
}
#if 0
std::vector<MarketHours> parseMarketHours(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    std::vector<MarketHours> marketHoursVec;

    if(!d.IsObject())
    {
        return {};
    }

    for (rapidjson::Value::ConstMemberIterator hoursObj = d.MemberBegin();
         hoursObj != d.MemberEnd();
         ++hoursObj)
    {
        if(hoursObj->name.GetType() != rapidjson::kStringType)
        {
            throw std::runtime_error("market hours key is not a string");
        }
        if(hoursObj->value.GetType() != rapidjson::kObjectType)
        {
            throw std::runtime_error("market hours value is not an object");
        }


        auto hoursObjValue = hoursObj->value.GetObject();
        for(rapidjson::Value::ConstMemberIterator specificMarketTypeHours = hoursObjValue.MemberBegin();
            specificMarketTypeHours != hoursObjValue.MemberEnd();
            ++specificMarketTypeHours)
        {
            if(specificMarketTypeHours->name.GetType() != rapidjson::kStringType)
            {
                throw std::runtime_error("specific market hours key is not a string");
            }
            if(specificMarketTypeHours->value.GetType() != rapidjson::kObjectType)
            {
                throw std::runtime_error("specific market hours value is not an object");
            }

            MarketHours marketHour;
            marketHour.marketType = stringToMarketTypeMap.at(hoursObj->name.GetString());
            PARSE_STRING(marketHour.date, "date", specificMarketTypeHours->value);
            PARSE_STRING(marketHour.productSymbol, "product", specificMarketTypeHours->value);
            PARSE_STRING(marketHour.productName, "productName", specificMarketTypeHours->value);
            PARSE_STRING(marketHour.isOpen, "isOpen", specificMarketTypeHours->value);

            if(specificMarketTypeHours->value.HasMember("sessionHours") && specificMarketTypeHours->value["sessionHours"].IsObject())
            {
                auto sessionHours = specificMarketTypeHours->value["sessionHours"].GetObject();
                for(rapidjson::Value::ConstMemberIterator session = sessionHours.MemberBegin();
                    session != sessionHours.MemberEnd();
                    ++session)
                {
                    if(session->name.GetType() != rapidjson::kStringType)
                    {
                        throw std::runtime_error("session hours key is not a string");
                    }
                    if(session->value.GetType() != rapidjson::kArrayType)
                    {
                        throw std::runtime_error("session hours value is not an array");
                    }

                    MarketSessionHours marketSessionHours;
                    //assuming only one start/end per marketsession type
                    for(const auto& sessionTimes : session->value.GetArray())
                    {
                        // marketSessionHours.start = sessionTimes["start"].GetString();
                        PARSE_STRING(marketSessionHours.start, "start", sessionTimes);
                        // marketSessionHours.end = sessionTimes["end"].GetString();
                        PARSE_STRING(marketSessionHours.end, "end", sessionTimes);
                        marketHour.sessionHours[stringToMarketSessionHourTypesMap.at(session->name.GetString())]
                            = marketSessionHours;
                        break;
                    }
                }
            }
            marketHoursVec.push_back(marketHour);
        }
    }

    return marketHoursVec;
}
#endif
} // namespace schwabMarketData