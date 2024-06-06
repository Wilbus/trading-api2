#pragma once

#include "SchwabAccountDataTypes.h"
#include "json.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#include <iostream>

namespace schwabAccountData {

AuthTokens parseAuthTokens(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    AuthTokens auth;
    PARSE_UINT64(auth.expires_in, "expires_in", d);
    PARSE_STRING(auth.token_type, "token_type", d);
    PARSE_STRING(auth.scope, "scope", d);
    PARSE_STRING(auth.refresh_token, "refresh_token", d);
    PARSE_STRING(auth.access_token, "access_token", d);
    PARSE_STRING(auth.id_token, "id_token", d);

    return auth;
}

UserPreferences parseUserPreferences(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    if (!d.IsObject())
    {
        return {};
    }

    UserPreferences pref;

    if (d.HasMember("accounts") && d["accounts"].IsArray())
    {
        Account acc;
        for (const auto& accountObj : d["accounts"].GetArray())
        {
            PARSE_STRING(acc.accountNumber, "accountNumber", accountObj);
            PARSE_BOOL(acc.primaryAccount, "primaryAccount", accountObj);
            PARSE_STRING(acc.type, "type", accountObj);
            PARSE_STRING(acc.displayAcctId, "displayAcctId", accountObj);
            PARSE_BOOL(acc.autoPositionEffect, "autoPositionEffect", accountObj);
            PARSE_STRING(acc.accountColor, "accountColor", accountObj);
            pref.accounts.push_back(acc);
        }
    }
    if (d.HasMember("streamerInfo") && d["streamerInfo"].IsArray())
    {
        for (const auto& streamerObj : d["streamerInfo"].GetArray())
        {
            StreamerInfo streamerInfo;
            PARSE_STRING(streamerInfo.streamerSocketUrl, "streamerSocketUrl", streamerObj);
            PARSE_STRING(streamerInfo.schwabClientCustomerId, "schwabClientCustomerId", streamerObj);
            PARSE_STRING(streamerInfo.schwabClientCorrelId, "schwabClientCorrelId", streamerObj);
            PARSE_STRING(streamerInfo.schwabClientChannel, "schwabClientChannel", streamerObj);
            PARSE_STRING(streamerInfo.schwabClientFunctionId, "schwabClientFunctionId", streamerObj);
            pref.streamerInfo.push_back(streamerInfo);
        }
    }
    if (d.HasMember("offers") && d["offers"].IsArray())
    {
        for (const auto& offersObj : d["offers"].GetArray())
        {
            Offers offers;
            PARSE_STRING(offers.level2Permissions, "level2Permissions", offersObj);
            pref.offers.push_back(offers);
        }
    }
    return pref;
}

AccountNumbers parseAccountNumbers(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    AccountNumbers accNum;

    if (d.IsArray())
    {
        for (const auto& accountObj : d.GetArray())
        {
            std::string accountNumber;
            std::string hashValue;
            PARSE_STRING(accountNumber, "accountNumber", accountObj);
            PARSE_STRING(hashValue, "hashValue", accountObj);
            AccountNumberHashPair numberHash = std::make_pair(accountNumber, hashValue);
            accNum.push_back(numberHash);
        }
    }

    return accNum;
}

SchwabMarginBalance parseSchwabMarginBalance(const rapidjson::Value& marginBalanceObj)
{
    SchwabMarginBalance marginBalance;
    PARSE_DOUBLE(marginBalance.accruedInterest, "accruedInterest", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.availableFundsNonMarginableTrade, "availableFundsNonMarginableTrade", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.bondValue, "bondValue", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.buyingPower, "buyingPower", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.cashBalance, "cashBalance", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.cashAvailableForTrading, "cashAvailableForTrading", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.cashReceipts, "cashReceipts", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.dayTradingBuyingPower, "dayTradingBuyingPower", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.dayTradingBuyingPowerCall, "dayTradingBuyingPowerCall", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.dayTradingEquityCall, "dayTradingEquityCall", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.equity, "equity", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.equityPercentage, "equityPercentage", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.liquidationValue, "liquidationValue", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.longMarginValue, "longMarginValue", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.longOptionMarketValue, "longOptionMarketValue", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.longStockValue, "longStockValue", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.maintenanceCall, "maintenanceCall", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.maintenanceRequirement, "maintenanceRequirement", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.margin, "margin", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.marginEquity, "marginEquity", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.moneyMarketFund, "moneyMarketFund", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.mutualFundValue, "mutualFundValue", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.regTCall, "regTCall", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.shortMarginValue, "shortMarginValue", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.shortOptionMarketValue, "shortOptionMarketValue", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.shortStockValue, "shortStockValue", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.shortMarketValue, "shortMarketValue", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.totalCash, "totalCash", marginBalanceObj);
    PARSE_BOOL(marginBalance.isInCall, "isInCall", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.unsettledCash, "unsettledCash", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.pendingDeposits, "pendingDeposits", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.marginBalance, "marginBalance", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.shortBalance, "shortBalance", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.accountValue, "accountValue", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.availableFunds, "availableFunds", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.buyingPowerNonMarginableTrade, "buyingPowerNonMarginableTrade", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.sma, "sma", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.stockBuyingPower, "stockBuyingPower", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.optionBuyingPower, "optionBuyingPower", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.longMarketValue, "longMarketValue", marginBalanceObj);
    PARSE_DOUBLE(marginBalance.savings, "savings", marginBalanceObj);
    return marginBalance;
}

SchwabCashBalance parseSchwabCashBalance(const rapidjson::Value& cashBalanceObj)
{
    SchwabCashBalance currentBalance;
    PARSE_DOUBLE(currentBalance.cashAvailableForTrading, "cashAvailableForTrading", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.cashAvailableForWithdrawal, "cashAvailableForWithdrawal", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.cashCall, "cashCall", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.cashBalance, "cashBalance", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.longNonMarginableMarketValue, "longNonMarginableMarketValue", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.totalCash, "totalCash", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.cashDebitCallValue, "cashDebitCallValue", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.unsettledCash, "unsettledCash", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.accruedInterest, "accruedInterest", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.bondValue, "bondValue", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.cashReceipts, "cashReceipts", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.liquidationValue, "liquidationValue", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.longOptionMarketValue, "longOptionMarketValue", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.longStockValue, "longStockValue", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.longMarketValue, "longMarketValue", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.moneyMarketFund, "moneyMarketFund", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.mutualFundValue, "mutualFundValue", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.savings, "savings", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.shortOptionMarketValue, "shortOptionMarketValue", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.shortStockValue, "shortStockValue", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.shortMarketValue, "shortMarketValue", cashBalanceObj);
    PARSE_BOOL(currentBalance.isInCall, "isInCall", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.pendingDeposits, "pendingDeposits", cashBalanceObj);
    PARSE_DOUBLE(currentBalance.accountValue, "accountValue", cashBalanceObj);
    return currentBalance;
}

AccountPositionBalances parseAccountPositionBalances(std::string jsonstring)
{
    rapidjson::Document d;
    d.Parse(jsonstring.c_str());
    rapidjson::StringBuffer s;

    AccountPositionBalances accPos;

    if (!d.IsObject())
    {
        return {};
    }

    if (d.HasMember("securitiesAccount") && d["securitiesAccount"].IsObject())
    {
        auto securitiesAccount = d["securitiesAccount"].GetObject();

        PARSE_STRING(accPos.type, "type", securitiesAccount);
        PARSE_STRING(accPos.accountNumber, "accountNumber", securitiesAccount);
        PARSE_INT(accPos.roundTrips, "roundTrips", securitiesAccount);
        PARSE_BOOL(accPos.isDayTrader, "isDayTrader", securitiesAccount);
        PARSE_BOOL(accPos.isClosingOnlyRestricted, "isClosingOnlyRestricted", securitiesAccount);
        PARSE_BOOL(accPos.pfcbFlag, "pfcbFlag", securitiesAccount);

        if (securitiesAccount.HasMember("positions") && securitiesAccount["positions"].IsArray())
        {
            SchwabPosition pos;
            for (const auto& positionObj : securitiesAccount["positions"].GetArray())
            {
                PARSE_DOUBLE(pos.shortQuantity, "shortQuantity", positionObj);
                PARSE_DOUBLE(pos.averagePrice, "averagePrice", positionObj);
                PARSE_DOUBLE(pos.currentDayProfitLoss, "currentDayProfitLoss", positionObj);
                PARSE_DOUBLE(pos.currentDayProfitLossPercentage, "currentDayProfitLossPercentage", positionObj);
                PARSE_DOUBLE(pos.longQuantity, "longQuantity", positionObj);
                PARSE_DOUBLE(pos.settledLongQuantity, "settledLongQuantity", positionObj);
                PARSE_DOUBLE(pos.settledShortQuantity, "settledShortQuantity", positionObj);
                PARSE_DOUBLE(pos.agedQuantity, "agedQuantity", positionObj);

                if (positionObj.HasMember("instrument") && positionObj["instrument"].IsObject())
                {
                    SchwabInstrument instrument;
                    PARSE_STRING(instrument.assetType, "assetType", positionObj["instrument"]);
                    PARSE_STRING(instrument.cusip, "cusip", positionObj["instrument"]);
                    PARSE_STRING(instrument.symbol, "symbol", positionObj["instrument"]);
                    PARSE_DOUBLE(instrument.netChange, "netChange", positionObj["instrument"]);
                    PARSE_STRING(instrument.description, "description", positionObj["instrument"]);
                    PARSE_STRING(instrument.type, "type", positionObj["instrument"]);
                    PARSE_STRING(instrument.putCall, "putCall", positionObj["instrument"]);
                    PARSE_STRING(instrument.underlyingSymbol, "underlyingSymbol", positionObj["instrument"]);
                    pos.instrument = instrument;
                }

                PARSE_DOUBLE(pos.marketValue, "marketValue", positionObj);
                PARSE_DOUBLE(pos.maintenanceRequirement, "maintenanceRequirement", positionObj);
                PARSE_DOUBLE(pos.averageLongPrice, "averageLongPrice", positionObj);
                PARSE_DOUBLE(pos.taxLotAverageLongPrice, "taxLotAverageLongPrice", positionObj);
                PARSE_DOUBLE(pos.longOpenProfitLoss, "longOpenProfitLoss", positionObj);
                PARSE_DOUBLE(pos.previousSessionLongQuantity, "previousSessionLongQuantity", positionObj);
                PARSE_DOUBLE(pos.currentDayCost, "currentDayCost", positionObj);

                accPos.positions.push_back(pos);
            }
        }

        if (securitiesAccount.HasMember("initialBalances") && securitiesAccount["initialBalances"].IsObject() &&
            accPos.type == "MARGIN")
        {
            accPos.initialMarginBalance = parseSchwabMarginBalance(securitiesAccount["initialBalances"].GetObject());
        }
        else if (securitiesAccount.HasMember("initialBalances") && securitiesAccount["initialBalances"].IsObject() &&
                 accPos.type == "CASH")
        {
            accPos.initialCashBalance = parseSchwabCashBalance(securitiesAccount["initialBalances"].GetObject());
        }
        if (securitiesAccount.HasMember("currentBalances") && securitiesAccount["currentBalances"].IsObject() &&
            accPos.type == "MARGIN")
        {
            accPos.currentMarginAccountBalance =
                parseSchwabMarginBalance(securitiesAccount["currentBalances"].GetObject());
        }
        else if (securitiesAccount.HasMember("currentBalances") && securitiesAccount["currentBalances"].IsObject() &&
                 accPos.type == "CASH")
        {
            accPos.currentCashAccountBalance = parseSchwabCashBalance(securitiesAccount["currentBalances"].GetObject());
        }
        // TODO: add projectedBalances
    }

    return accPos;
}

} // namespace schwabAccountData