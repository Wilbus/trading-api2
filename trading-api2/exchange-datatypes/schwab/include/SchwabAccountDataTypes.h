#pragma once

#include "NumericLimits.h"

#include <functional>
#include <string>

namespace schwabAccountData {

struct AuthTokens
{
    int64_t expires_in;
    std::string token_type;
    std::string scope;
    std::string refresh_token;
    std::string access_token;
    std::string id_token;
};

struct SchwabAuth
{
    std::string appkey;
    std::string appsecret;
    std::string token;
    std::string callbackUrl;
    AuthTokens authTokens;
};

typedef std::pair<std::string, std::string> AccountNumberHashPair;
typedef std::vector<AccountNumberHashPair> AccountNumbers;

struct Account
{
    std::string accountNumber;
    bool primaryAccount;
    std::string type;
    std::string nickName;
    std::string accountColor;
    std::string displayAcctId;
    std::string autoPositionEffect;
};

struct SchwabMarginBalance
{
    double accountValue{MAXDOUBLE};
    double availableFunds{MAXDOUBLE};
    double availableFundsNonMarginableTrade{MAXDOUBLE};
    double buyingPower{MAXDOUBLE};
    double buyingPowerNonMarginableTrade{MAXDOUBLE};
    double cashBalance{MAXDOUBLE};
    double cashReceipts{MAXDOUBLE};
    double dayTradingBuyingPower{MAXDOUBLE};
    double dayTradingBuyingPowerCall{MAXDOUBLE};
    double equity{MAXDOUBLE};
    double equityPercentage{MAXDOUBLE};
    double longMarginValue{MAXDOUBLE};
    double maintenanceCall{MAXDOUBLE};
    double maintenanceRequirement{MAXDOUBLE};
    double marginBalance{MAXDOUBLE};
    double regTCall{MAXDOUBLE};
    double shortBalance{MAXDOUBLE};
    double shortMarginValue{MAXDOUBLE};
    double sma{MAXDOUBLE};
    bool isInCall;
    double stockBuyingPower{MAXDOUBLE};
    double optionBuyingPower{MAXDOUBLE};
    double accruedInterest{MAXDOUBLE};
    double bondValue{MAXDOUBLE};
    double cashAvailableForTrading{MAXDOUBLE};
    double dayTradingEquityCall{MAXDOUBLE};
    double liquidationValue{MAXDOUBLE};
    double longOptionMarketValue{MAXDOUBLE};
    double longStockValue{MAXDOUBLE};
    double longMarketValue{MAXDOUBLE};
    double marginEquity{MAXDOUBLE};
    double moneyMarketFund{MAXDOUBLE};
    double mutualFundValue{MAXDOUBLE};
    double shortOptionMarketValue{MAXDOUBLE};
    double shortStockValue{MAXDOUBLE};
    double totalCash{MAXDOUBLE};
    double unsettledCash{MAXDOUBLE};
    double pendingDeposits{MAXDOUBLE};
    double margin{MAXDOUBLE};
    double savings{MAXDOUBLE};
    double shortMarketValue{MAXDOUBLE};
};

struct SchwabCashBalance
{
    double accruedInterest{MAXDOUBLE};
    double cashBalance{MAXDOUBLE};
    double cashAvailableForTrading{MAXDOUBLE};
    double cashAvailableForWithdrawal{MAXDOUBLE};
    double cashCall{MAXDOUBLE};
    double longNonMarginableMarketValue{MAXDOUBLE};
    double longMarketValue{MAXDOUBLE};
    double totalCash{MAXDOUBLE};
    double cashDebitCallValue{MAXDOUBLE};
    double unsettledCash{MAXDOUBLE};
    double bondValue{MAXDOUBLE};
    double cashReceipts{MAXDOUBLE};
    double liquidationValue{MAXDOUBLE};
    double longOptionMarketValue{MAXDOUBLE};
    double longStockValue{MAXDOUBLE};
    double moneyMarketFund{MAXDOUBLE};
    double mutualFundValue{MAXDOUBLE};
    double shortOptionMarketValue{MAXDOUBLE};
    double shortStockValue{MAXDOUBLE};
    bool isInCall;
    double pendingDeposits{MAXDOUBLE};
    double accountValue{MAXDOUBLE};
    double savings{MAXDOUBLE};
    double shortMarketValue{MAXDOUBLE};
};

struct SchwabInstrument
{
    // common
    std::string symbol;
    std::string description;
    int64_t instrumentId;
    double netChange{MAXDOUBLE};
    std::string assetType;
    std::string cusip;

    // AccountCashEquivalent
    std::string type;

    // AccountFixedIncome
    double factor{MAXDOUBLE};
    double variableRate{MAXDOUBLE};

    // AccountOption
    // TODO: add the optionDeliverables field if needed
    std::string putCall;
    int optionMultiplier;
    std::string underlyingSymbol;
};

struct SchwabPosition
{
    double shortQuantity{MAXDOUBLE};
    double averagePrice{MAXDOUBLE};
    double currentDayProfitLoss{MAXDOUBLE};
    double currentDayProfitLossPercentage{MAXDOUBLE};
    double longQuantity{MAXDOUBLE};
    double settledLongQuantity{MAXDOUBLE};
    double settledShortQuantity{MAXDOUBLE};
    double agedQuantity{MAXDOUBLE};
    SchwabInstrument instrument;
    double marketValue{MAXDOUBLE};
    double maintenanceRequirement{MAXDOUBLE};
    double averageLongPrice{MAXDOUBLE};
    double averageShortPrice{MAXDOUBLE};
    double taxLotAverageLongPrice{MAXDOUBLE};
    double taxLotAverageShortPrice{MAXDOUBLE};
    double longOpenProfitLoss{MAXDOUBLE};
    double shortOpenProfitLoss{MAXDOUBLE};
    double previousSessionLongQuantity{MAXDOUBLE};
    double previousSessionShortQuantity{MAXDOUBLE};
    double currentDayCost{MAXDOUBLE};
};

struct AccountPositionBalances
{
    std::string type;
    std::string accountType;
    std::string accountNumber;
    int roundTrips;
    bool isDayTrader;
    bool isClosingOnlyRestricted;
    bool pfcbFlag;
    std::vector<SchwabPosition> positions;
    SchwabMarginBalance initialMarginBalance;
    SchwabMarginBalance currentMarginAccountBalance;
    SchwabMarginBalance projectedMarginAccountBalance;
    SchwabCashBalance initialCashBalance;
    SchwabCashBalance currentCashAccountBalance;
    SchwabCashBalance projectedCashAccountBalance;
};

struct StreamerInfo
{
    std::string streamerSocketUrl;
    std::string schwabClientCustomerId;
    std::string schwabClientCorrelId;
    std::string schwabClientChannel;
    std::string schwabClientFunctionId;
};

struct Offers
{
    bool level2Permissions;
};

struct UserPreferences
{
    std::vector<Account> accounts;
    std::vector<StreamerInfo> streamerInfo;
    std::vector<Offers> offers;
};

} // namespace schwabAccountData