#pragma once

#include <string>

const std::string accountNumbersResponse = R"(
[
  {
    "accountNumber": "012340",
    "hashValue": "ABCDE1234"
  },
  {
    "accountNumber": "56789",
    "hashValue": "DEADBEEF123"
  }
]
)";

const std::string accountInfoMarginPositionsResponse = R"(
{
  "securitiesAccount": {
    "type": "MARGIN",
    "accountNumber": "123456789",
    "roundTrips": 0,
    "isDayTrader": false,
    "isClosingOnlyRestricted": false,
    "pfcbFlag": false,
    "positions": [
      {
        "shortQuantity": 0,
        "averagePrice": 162.12,
        "currentDayProfitLoss": 12.82,
        "currentDayProfitLossPercentage": 4.01,
        "longQuantity": 2,
        "settledLongQuantity": 2,
        "settledShortQuantity": 0,
        "instrument": {
          "assetType": "EQUITY",
          "cusip": "007903107",
          "symbol": "AMD",
          "netChange": 6.41
        },
        "marketValue": 300,
        "maintenanceRequirement": 99.84,
        "averageLongPrice": 162.12,
        "taxLotAverageLongPrice": 162.12,
        "longOpenProfitLoss": 8.56,
        "previousSessionLongQuantity": 2,
        "currentDayCost": 0
      },
      {
        "shortQuantity": 0,
        "averagePrice": 0.1066,
        "currentDayProfitLoss": 2.49,
        "currentDayProfitLossPercentage": 24900,
        "longQuantity": 1,
        "settledLongQuantity": 1,
        "settledShortQuantity": 0,
        "instrument": {
          "assetType": "OPTION",
          "cusip": "0ERIC.AH50015000",
          "symbol": "ERIC  250117C00015000",
          "description": "ERICSSON 01/17/2025 $15 Call",
          "netChange": 0.0299,
          "type": "VANILLA",
          "putCall": "CALL",
          "underlyingSymbol": "ERIC"
        },
        "marketValue": 2.5,
        "maintenanceRequirement": 0,
        "averageLongPrice": 0.1,
        "taxLotAverageLongPrice": 0.1066,
        "longOpenProfitLoss": -8.16,
        "previousSessionLongQuantity": 1,
        "currentDayCost": 0
      }
    ],
    "initialBalances": {
      "accruedInterest": 0,
      "availableFundsNonMarginableTrade": 100,
      "bondValue": 100,
      "buyingPower": 100,
      "cashBalance": 100,
      "cashAvailableForTrading": 0,
      "cashReceipts": 0,
      "dayTradingBuyingPower": 1000,
      "dayTradingBuyingPowerCall": 0,
      "dayTradingEquityCall": 0,
      "equity": 700,
      "equityPercentage": 100,
      "liquidationValue": 700,
      "longMarginValue": 400,
      "longOptionMarketValue": 0.01,
      "longStockValue": 400,
      "maintenanceCall": 0,
      "maintenanceRequirement": 96,
      "margin": 100,
      "marginEquity": 731.9,
      "moneyMarketFund": 0,
      "mutualFundValue": 100,
      "regTCall": 0,
      "shortMarginValue": 0,
      "shortOptionMarketValue": 0,
      "shortStockValue": 0,
      "totalCash": 0,
      "isInCall": false,
      "pendingDeposits": 0,
      "marginBalance": 0,
      "shortBalance": 0,
      "accountValue": 700
    },
    "currentBalances": {
      "availableFunds": 100,
      "accruedInterest": 0,
      "cashBalance": 100,
      "cashReceipts": 0,
      "longOptionMarketValue": 2.5,
      "liquidationValue": 700,
      "longMarketValue": 300,
      "moneyMarketFund": 0,
      "savings": 0,
      "shortMarketValue": 0,
      "pendingDeposits": 0,
      "mutualFundValue": 0,
      "bondValue": 0,
      "shortOptionMarketValue": 0,
      "availableFunds": 100,
      "availableFundsNonMarginableTrade": 100,
      "buyingPower": 100,
      "buyingPowerNonMarginableTrade": 100,
      "dayTradingBuyingPower": 2000,
      "equity": 744.72,
      "equityPercentage": 100,
      "longMarginValue": 300,
      "maintenanceCall": 0,
      "maintenanceRequirement": 99.84,
      "marginBalance": 0,
      "regTCall": 0,
      "shortBalance": 0,
      "shortMarginValue": 0,
      "sma": 1294
    },
    "projectedBalances": {
      "availableFunds": 100,
      "availableFundsNonMarginableTrade": 100,
      "buyingPower": 100,
      "dayTradingBuyingPower": 2000,
      "dayTradingBuyingPowerCall": 0,
      "maintenanceCall": 0,
      "regTCall": 0,
      "isInCall": false,
      "stockBuyingPower": 100
    }
  },
  "aggregatedBalance": {
    "currentLiquidationValue": 750,
    "liquidationValue": 750
  }
}
)";

const std::string accountInfoCashPositionsResponse = R"(
{
  "securitiesAccount": {
    "type": "CASH",
    "accountNumber": "123456789",
    "roundTrips": 0,
    "isDayTrader": false,
    "isClosingOnlyRestricted": false,
    "pfcbFlag": false,
    "positions": [
      {
        "shortQuantity": 0,
        "averagePrice": 1.48,
        "currentDayProfitLoss": 74.5,
        "currentDayProfitLossPercentage": 50.34,
        "longQuantity": 1,
        "settledLongQuantity": 0,
        "settledShortQuantity": 0,
        "instrument": {
          "assetType": "OPTION",
          "cusip": "0CAVA.FS40100000",
          "symbol": "CAVA  240628C00100000",
          "description": "CAVA GROUP INC 06/28/2024 $100 Call",
          "netChange": 1.035,
          "type": "VANILLA",
          "putCall": "CALL",
          "underlyingSymbol": "CAVA"
        },
        "marketValue": 222.5,
        "maintenanceRequirement": 0,
        "averageLongPrice": 1.48,
        "taxLotAverageLongPrice": 1.48,
        "longOpenProfitLoss": 74.5,
        "previousSessionLongQuantity": 0,
        "currentDayCost": 148
      },
      {
        "shortQuantity": 0,
        "averagePrice": 413.305,
        "currentDayProfitLoss": 15.04,
        "currentDayProfitLossPercentage": 1.81,
        "longQuantity": 2,
        "settledLongQuantity": 2,
        "settledShortQuantity": 0,
        "instrument": {
          "assetType": "EQUITY",
          "cusip": "594918104",
          "symbol": "MSFT",
          "netChange": 7.43
        },
        "marketValue": 847.18,
        "maintenanceRequirement": 0,
        "averageLongPrice": 413.305,
        "taxLotAverageLongPrice": 413.305,
        "longOpenProfitLoss": 20.57,
        "previousSessionLongQuantity": 2,
        "currentDayCost": 0
      },
      {
        "shortQuantity": 0,
        "averagePrice": 77.2175,
        "currentDayProfitLoss": 9.28,
        "currentDayProfitLossPercentage": 1.31,
        "longQuantity": 8,
        "settledLongQuantity": 8,
        "settledShortQuantity": 0,
        "instrument": {
          "assetType": "EQUITY",
          "cusip": "148929102",
          "symbol": "CAVA",
          "netChange": 0.56
        },
        "marketValue": 716,
        "maintenanceRequirement": 0,
        "averageLongPrice": 77.2175,
        "taxLotAverageLongPrice": 77.2175,
        "longOpenProfitLoss": 98.26,
        "previousSessionLongQuantity": 8,
        "currentDayCost": 0
      },
      {
        "shortQuantity": 0,
        "averagePrice": 120.91,
        "currentDayProfitLoss": 36.35,
        "currentDayProfitLossPercentage": 5.74,
        "longQuantity": 5,
        "settledLongQuantity": 5,
        "settledShortQuantity": 0,
        "instrument": {
          "assetType": "EQUITY",
          "cusip": "595112103",
          "symbol": "MU",
          "netChange": 7.47
        },
        "marketValue": 669.55,
        "maintenanceRequirement": 0,
        "averageLongPrice": 120.91,
        "taxLotAverageLongPrice": 120.91,
        "longOpenProfitLoss": 65,
        "previousSessionLongQuantity": 5,
        "currentDayCost": 0
      },
      {
        "shortQuantity": 0,
        "averagePrice": 0.1299333333,
        "currentDayProfitLoss": 13.26,
        "currentDayProfitLossPercentage": 123.46,
        "longQuantity": 3,
        "settledLongQuantity": 3,
        "settledShortQuantity": 0,
        "instrument": {
          "assetType": "OPTION",
          "cusip": "0XOM..HG40145000",
          "symbol": "XOM   240816C00145000",
          "description": "Exxon Mobil Corp 08/16/2024 $145 Call",
          "netChange": 0.0142,
          "type": "VANILLA",
          "putCall": "CALL",
          "underlyingSymbol": "XOM"
        },
        "marketValue": 24,
        "maintenanceRequirement": 0,
        "averageLongPrice": 0.123333333333,
        "taxLotAverageLongPrice": 0.1299333333,
        "longOpenProfitLoss": -14.97999999,
        "previousSessionLongQuantity": 3,
        "currentDayCost": 0
      }
    ],
    "initialBalances": {
      "accruedInterest": 0,
      "cashAvailableForTrading": 1000.8,
      "cashAvailableForWithdrawal": 1000.8,
      "cashBalance": 1000.8,
      "bondValue": 0,
      "cashReceipts": 0,
      "liquidationValue": 3000.6,
      "longOptionMarketValue": 10.74,
      "longStockValue": 1000.06,
      "moneyMarketFund": 0,
      "mutualFundValue": 1000.8,
      "shortOptionMarketValue": 0,
      "shortStockValue": 0,
      "isInCall": false,
      "unsettledCash": 0,
      "cashDebitCallValue": 0,
      "pendingDeposits": 0,
      "accountValue": 3000.6
    },
    "currentBalances": {
      "accruedInterest": 0,
      "cashBalance": 1000.14,
      "cashReceipts": 0,
      "longOptionMarketValue": 250.5,
      "liquidationValue": 1000.37,
      "longMarketValue": 1000.73,
      "moneyMarketFund": 0,
      "savings": 0,
      "shortMarketValue": 0,
      "pendingDeposits": 0,
      "mutualFundValue": 0,
      "bondValue": 0,
      "shortOptionMarketValue": 0,
      "cashAvailableForTrading": 1000.14,
      "cashAvailableForWithdrawal": 1000.14,
      "cashCall": 0,
      "longNonMarginableMarketValue": 1000.14,
      "totalCash": 1000.14,
      "cashDebitCallValue": 0,
      "unsettledCash": 0
    },
    "projectedBalances": {
      "cashAvailableForTrading": 1000.14,
      "cashAvailableForWithdrawal": 1000.14
    }
  },
  "aggregatedBalance": {
    "currentLiquidationValue": 1000.37,
    "liquidationValue": 1000.37
  }
}
)";