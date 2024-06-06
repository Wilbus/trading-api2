#pragma once

#include <string>
#include <map>
#include "NumericLimits.h"

namespace accounting
{

struct AccountBalance
{
    double cashBalance{MAXDOUBLE};
    double marginBalance{MAXDOUBLE};
    double cashAvailableForTrading{MAXDOUBLE};
    double cashAvailableForWithdrawal{MAXDOUBLE};
    double liquidationValue{MAXDOUBLE};
    double unsettleCash{MAXDOUBLE};
    double equityPercentage{MAXDOUBLE};
    double stockBuyingPower{MAXDOUBLE};
    double optionBuyingPower{MAXDOUBLE};
    double maintenenanceRequirement{MAXDOUBLE};
};

struct Instrument
{
    std::string symbol;
    std::string description;
    std::string assetType;
    std::string cusip;
    std::string putCall;
    std::string underlyingSymbol;
    int optionMultiplier;
};

struct Position
{
    Instrument instrument;
    double averagePrice{MAXDOUBLE};
    double marketValue{MAXDOUBLE};
    double quantity{MAXDOUBLE};
    double currentProfitLoss{MAXDOUBLE};
    double currentProfitLossPercentage{MAXDOUBLE};
    double settledQuantity{MAXDOUBLE};
};

struct AccountDetails
{
    AccountDetails() = default;
    AccountDetails(const std::string& accountNumber);

    std::string accountNumber;
    AccountBalance balance;
    std::map<std::string, Position> positions;
};

}