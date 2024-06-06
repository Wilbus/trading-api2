#include "SchwabAccountDataParser.h"
#include "schwabAccountTestValues.h"

#include <gtest/gtest.h>

using namespace schwabAccountData;

class SchwabAccountReqParserTest : public ::testing::Test
{
public:
    SchwabAccountReqParserTest()
    {
    }
};

TEST_F(SchwabAccountReqParserTest, parseAccountNumbers)
{
    auto accountNumbers = parseAccountNumbers(accountNumbersResponse);
    ASSERT_EQ(accountNumbers.size(), 2);
    ASSERT_EQ(accountNumbers[0].first, "012340");
    ASSERT_EQ(accountNumbers[0].second, "ABCDE1234");
    ASSERT_EQ(accountNumbers[1].first, "56789");
    ASSERT_EQ(accountNumbers[1].second, "DEADBEEF123");
}

TEST_F(SchwabAccountReqParserTest, parseAccountPositionBalancesMarginAccount)
{
    auto accountPositionBalances = parseAccountPositionBalances(accountInfoMarginPositionsResponse);
    EXPECT_EQ(accountPositionBalances.type, "MARGIN");
    EXPECT_EQ(accountPositionBalances.positions.size(), 2);
    EXPECT_EQ(accountPositionBalances.accountNumber, "123456789");
    EXPECT_EQ(accountPositionBalances.roundTrips, 0);
    EXPECT_EQ(accountPositionBalances.isDayTrader, false);
    EXPECT_EQ(accountPositionBalances.isClosingOnlyRestricted, false);
    EXPECT_EQ(accountPositionBalances.pfcbFlag, false);
    EXPECT_EQ(accountPositionBalances.positions[0].shortQuantity, 0);
    EXPECT_EQ(accountPositionBalances.positions[0].averagePrice, 162.12);
    EXPECT_EQ(accountPositionBalances.positions[0].currentDayProfitLoss, 12.82);
    EXPECT_EQ(accountPositionBalances.positions[0].currentDayProfitLossPercentage, 4.01);
    EXPECT_EQ(accountPositionBalances.positions[0].longQuantity, 2);
    EXPECT_EQ(accountPositionBalances.positions[0].settledLongQuantity, 2);
    EXPECT_EQ(accountPositionBalances.positions[0].settledShortQuantity, 0);
    EXPECT_EQ(accountPositionBalances.positions[0].instrument.assetType, "EQUITY");
    EXPECT_EQ(accountPositionBalances.positions[0].instrument.cusip, "007903107");
    EXPECT_EQ(accountPositionBalances.positions[0].instrument.symbol, "AMD");
    EXPECT_EQ(accountPositionBalances.positions[0].instrument.netChange, 6.41);
    EXPECT_EQ(accountPositionBalances.positions[0].marketValue, 300);
    EXPECT_EQ(accountPositionBalances.positions[0].maintenanceRequirement, 99.84);
    EXPECT_EQ(accountPositionBalances.positions[0].averageLongPrice, 162.12);
    EXPECT_EQ(accountPositionBalances.positions[0].taxLotAverageLongPrice, 162.12);
    EXPECT_EQ(accountPositionBalances.positions[0].longOpenProfitLoss, 8.56);
    EXPECT_EQ(accountPositionBalances.positions[0].previousSessionLongQuantity, 2);
    EXPECT_EQ(accountPositionBalances.positions[0].currentDayCost, 0);
    EXPECT_EQ(accountPositionBalances.positions[1].shortQuantity, 0);
    EXPECT_EQ(accountPositionBalances.positions[1].averagePrice, 0.1066);
    EXPECT_EQ(accountPositionBalances.positions[1].currentDayProfitLoss, 2.49);
    EXPECT_EQ(accountPositionBalances.positions[1].currentDayProfitLossPercentage, 24900);
    EXPECT_EQ(accountPositionBalances.positions[1].longQuantity, 1);
    EXPECT_EQ(accountPositionBalances.positions[1].settledLongQuantity, 1);
    EXPECT_EQ(accountPositionBalances.positions[1].settledShortQuantity, 0);
    EXPECT_EQ(accountPositionBalances.positions[1].instrument.assetType, "OPTION");
    EXPECT_EQ(accountPositionBalances.positions[1].instrument.cusip, "0ERIC.AH50015000");
    EXPECT_EQ(accountPositionBalances.positions[1].instrument.symbol, "ERIC  250117C00015000");
    EXPECT_EQ(accountPositionBalances.positions[1].instrument.netChange, .0299);
    EXPECT_EQ(accountPositionBalances.positions[1].marketValue, 2.5);
    EXPECT_EQ(accountPositionBalances.positions[1].maintenanceRequirement, 0);
    EXPECT_EQ(accountPositionBalances.positions[1].averageLongPrice, 0.1);
    EXPECT_EQ(accountPositionBalances.positions[1].taxLotAverageLongPrice, 0.1066);
    EXPECT_EQ(accountPositionBalances.positions[1].longOpenProfitLoss, -8.16);
    EXPECT_EQ(accountPositionBalances.positions[1].previousSessionLongQuantity, 1);
    EXPECT_EQ(accountPositionBalances.positions[1].currentDayCost, 0);
    EXPECT_EQ(accountPositionBalances.positions[1].instrument.putCall, "CALL");
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.accruedInterest, 0);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.availableFundsNonMarginableTrade, 100);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.bondValue, 100);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.buyingPower, 100);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.cashBalance, 100);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.cashAvailableForTrading, 0);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.cashReceipts, 0);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.dayTradingBuyingPower, 1000);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.dayTradingBuyingPowerCall, 0);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.dayTradingEquityCall, 0);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.equity, 700);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.equityPercentage, 100);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.liquidationValue, 700);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.longMarginValue, 400);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.longOptionMarketValue, 0.01);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.longStockValue, 400);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.maintenanceCall, 0);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.maintenanceRequirement, 96);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.margin, 100);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.marginEquity, 731.9);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.moneyMarketFund, 0);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.mutualFundValue, 100);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.regTCall, 0);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.shortMarginValue, 0);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.shortOptionMarketValue, 0);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.shortStockValue, 0);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.totalCash, 0);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.isInCall, false);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.pendingDeposits, 0);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.marginBalance, 0);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.shortBalance, 0);
    EXPECT_EQ(accountPositionBalances.initialMarginBalance.accountValue, 700);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.accruedInterest, 0);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.cashBalance, 100);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.cashReceipts, 0);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.longOptionMarketValue, 2.5);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.liquidationValue, 700);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.longMarketValue, 300);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.moneyMarketFund, 0);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.savings, 0);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.shortMarketValue, 0);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.pendingDeposits, 0);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.mutualFundValue, 0);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.bondValue, 0);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.shortOptionMarketValue, 0);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.availableFunds, 100);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.availableFundsNonMarginableTrade, 100);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.buyingPower, 100);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.buyingPowerNonMarginableTrade, 100);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.dayTradingBuyingPower, 2000);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.equity, 744.72);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.equityPercentage, 100);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.longMarginValue, 300);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.maintenanceCall, 0);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.maintenanceRequirement, 99.84);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.marginBalance, 0);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.regTCall, 0);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.shortBalance, 0);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.shortMarginValue, 0);
    EXPECT_EQ(accountPositionBalances.currentMarginAccountBalance.sma, 1294);
}

TEST_F(SchwabAccountReqParserTest, parseAccountPositionBalancesCashAccount)
{
    auto accountPositionBalances = parseAccountPositionBalances(accountInfoCashPositionsResponse);
    EXPECT_EQ(accountPositionBalances.type, "CASH");
    EXPECT_EQ(accountPositionBalances.accountNumber, "123456789");
    EXPECT_EQ(accountPositionBalances.roundTrips, 0);
    EXPECT_EQ(accountPositionBalances.isDayTrader, false);
    EXPECT_EQ(accountPositionBalances.isClosingOnlyRestricted, false);
    EXPECT_EQ(accountPositionBalances.pfcbFlag, false);
    EXPECT_EQ(accountPositionBalances.positions.size(), 5);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.accruedInterest, 0);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.cashAvailableForTrading, 1000.8);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.cashAvailableForWithdrawal, 1000.8);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.cashBalance, 1000.8);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.bondValue, 0);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.cashReceipts, 0);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.liquidationValue, 3000.6);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.longOptionMarketValue, 10.74);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.longStockValue, 1000.06);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.moneyMarketFund, 0);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.mutualFundValue, 1000.8);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.shortOptionMarketValue, 0);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.shortStockValue, 0);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.isInCall, false);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.unsettledCash, 0);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.cashDebitCallValue, 0);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.pendingDeposits, 0);
    EXPECT_EQ(accountPositionBalances.initialCashBalance.accountValue, 3000.6);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.accruedInterest, 0);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.cashBalance, 1000.14);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.cashReceipts, 0);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.longOptionMarketValue, 250.5);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.liquidationValue, 1000.37);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.longMarketValue, 1000.73);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.moneyMarketFund, 0);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.savings, 0);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.shortMarketValue, 0);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.cashAvailableForTrading, 1000.14);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.cashAvailableForWithdrawal, 1000.14);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.cashCall, 0);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.longNonMarginableMarketValue, 1000.14);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.totalCash, 1000.14);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.cashDebitCallValue, 0);
    EXPECT_EQ(accountPositionBalances.currentCashAccountBalance.unsettledCash, 0);
}