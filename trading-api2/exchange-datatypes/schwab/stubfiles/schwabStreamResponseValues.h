#pragma once

#include <string>

static std::string loginResponse = R"({
  "response": [
    {
      "service": "ADMIN",
      "command": "LOGIN",
      "requestid": "0",
      "SchwabClientCorrelId": "abcd-1234",
      "timestamp": 1712381288369,
      "content": {
        "code": 0,
        "msg": "server=s6969-1;status=PN"
      }
    }
  ]
})";

static std::string loginDeniedResponse = R"({
  "response": [
    {
      "service": "ADMIN",
      "command": "LOGIN",
      "requestid": "0",
      "SchwabClientCorrelId": "abcd-1234",
      "timestamp": 1712381288369,
      "content": {
        "code": 3,
        "msg": "Login denied"
      }
    }
  ]
})";

static std::string acccountActivityResponse = R"({
  "response": [
    {
      "service": "ACCT_ACTIVITY",
      "command": "SUBS",
      "requestid": "1",
      "SchwabClientCorrelId": "abcd-1234",
      "timestamp": 1712461126712,
      "content": {
        "code": 0,
        "msg": "SUBS command succeeded"
      }
    }
  ]
})";

static std::string levelOneEquitiesResponse = R"({
  "response": [
    {
      "service": "LEVELONE_EQUITIES",
      "command": "SUBS",
      "requestid": "1",
      "SchwabClientCorrelId": "abcd-1234",
      "timestamp": 1712461126712,
      "content": {
        "code": 0,
        "msg": "SUBS command succeeded"
      }
    }
  ]
})";

static std::string chartEquityResponse = R"({
  "response": [
    {
      "service": "CHART_EQUITY",
      "command": "SUBS",
      "requestid": "3",
      "SchwabClientCorrelId": "abcd-1234",
      "timestamp": 1712461126819,
      "content": {
        "code": 0,
        "msg": "SUBS command succeeded"
      }
    }
  ]
})";

static std::string optionResponse = R"({
  "response": [
    {
      "service": "OPTION",
      "command": "SUBS",
      "requestid": "4",
      "SchwabClientCorrelId": "abcd-1234",
      "timestamp": 1712461126869,
      "content": {
        "code": 0,
        "msg": "SUBS command succeeded"
      }
    }
  ]
})";

static std::string heartbeatResponse = R"({
  "notify": [
    {
      "heartbeat": "1712547393411"
    }
  ]
})";

static std::string bigLevelOneDataResponse =
    R"({
  "data": [
    {
      "service": "LEVELONE_EQUITIES",
      "timestamp": 1712624126116,
      "command": "SUBS",
      "content": [
        {
          "1": 169.6,
          "2": 169.93,
          "3": 169.51,
          "4": 0,
          "5": 0,
          "6": "Z",
          "7": "Z",
          "8": 2123077,
          "9": 3,
          "10": 172.13,
          "11": 169.62,
          "12": 171.77,
          "13": "N",
          "14": false,
          "15": "Target Corp",
          "16": "L",
          "key": "TGT",
          "delayed": true,
          "assetMainType": "EQUITY",
          "assetSubType": "COE",
          "cusip": "87612E106"
        },
        {
          "1": 870.05,
          "2": 870.38,
          "3": 870.1985,
          "4": 0,
          "5": 0,
          "6": "Z",
          "7": "Z",
          "8": 28322000,
          "9": 10,
          "10": 888.3,
          "11": 867.32,
          "12": 880.08,
          "13": "Q",
          "14": false,
          "15": "Nvidia Corp",
          "16": "L",
          "key": "NVDA",
          "delayed": true,
          "assetMainType": "EQUITY",
          "assetSubType": "COE",
          "cusip": "67066G104"
        },
        {
          "1": 124.41,
          "2": 124.64,
          "3": 124.62,
          "4": 5,
          "5": 1,
          "6": "Q",
          "7": "Z",
          "8": 6119225,
          "9": 4,
          "10": 125.115,
          "11": 123.76,
          "12": 124.9,
          "13": "N",
          "14": false,
          "15": "ORACLE CORP",
          "16": "L",
          "key": "ORCL",
          "delayed": true,
          "assetMainType": "EQUITY",
          "assetSubType": "COE",
          "cusip": "68389X105"
        },
        {
          "1": 143.47,
          "2": 143.5,
          "3": 143.01,
          "4": 0,
          "5": 3,
          "6": "Z",
          "7": "Z",
          "8": 16307401,
          "9": 20,
          "10": 146,
          "11": 142.76,
          "12": 141.36,
          "13": "N",
          "14": false,
          "15": "Taiwan Semiconductr ADR",
          "16": "L",
          "key": "TSM",
          "delayed": true,
          "assetMainType": "EQUITY",
          "assetSubType": "ADR",
          "cusip": "874039100"
        },
        {
          "1": 440.71,
          "2": 440.96,
          "3": 440.75,
          "4": 1,
          "5": 24,
          "6": "Z",
          "7": "Q",
          "8": 28144944,
          "9": 60,
          "10": 442.5,
          "11": 439.2,
          "12": 440.47,
          "13": "Q",
          "14": false,
          "15": "INVSC QQQ TRUST SRS 1 ETF IV",
          "16": "Q",
          "key": "QQQ",
          "delayed": true,
          "assetMainType": "EQUITY",
          "assetSubType": "ETF",
          "cusip": "46090E103"
        },
        {
          "1": 425.2,
          "2": 425.4,
          "3": 425.35,
          "4": 18,
          "5": 0,
          "6": "Z",
          "7": "Q",
          "8": 14272387,
          "9": 1,
          "10": 427.28,
          "11": 423.3,
          "12": 425.52,
          "13": "Q",
          "14": false,
          "15": "Microsoft Corp",
          "16": "L",
          "key": "MSFT",
          "delayed": true,
          "assetMainType": "EQUITY",
          "assetSubType": "COE",
          "cusip": "594918104"
        },
        {
          "1": 68.81,
          "2": 68.85,
          "3": 68.86,
          "4": 0,
          "5": 0,
          "6": "Z",
          "7": "Z",
          "8": 7830359,
          "9": 100,
          "10": 69.2,
          "11": 67.95,
          "12": 69.25,
          "13": "N",
          "14": false,
          "15": "Occidental Petrol Co",
          "16": "L",
          "key": "OXY",
          "delayed": true,
          "assetMainType": "EQUITY",
          "assetSubType": "COE",
          "cusip": "674599105"
        },
        {
          "1": 65,
          "2": 65.12,
          "3": 65.0481,
          "4": 0,
          "5": 1,
          "6": "Z",
          "7": "Z",
          "8": 889041,
          "9": 1,
          "10": 65.3999,
          "11": 64.24,
          "12": 64.65,
          "13": "N",
          "14": false,
          "15": "CAVA GROUP INC",
          "16": "L",
          "key": "CAVA",
          "delayed": true,
          "assetMainType": "EQUITY",
          "assetSubType": "COE",
          "cusip": "148929102"
        },
        {
          "1": 120.54,
          "2": 120.75,
          "3": 120.55,
          "4": 13,
          "5": 0,
          "6": "Z",
          "7": "Q",
          "8": 17513939,
          "9": 75,
          "10": 121.735,
          "11": 120.205,
          "12": 121.37,
          "13": "N",
          "14": false,
          "15": "Exxon Mobil Corp",
          "16": "L",
          "key": "XOM",
          "delayed": true,
          "assetMainType": "EQUITY",
          "assetSubType": "COE",
          "cusip": "30231G102"
        },
        {
          "1": 169.61,
          "2": 169.7,
          "3": 169.6893,
          "4": 1,
          "5": 0,
          "6": "Z",
          "7": "Z",
          "8": 43997546,
          "9": 20000,
          "10": 171.6599,
          "11": 166.82,
          "12": 170.42,
          "13": "Q",
          "14": false,
          "15": "Advanced Micro Devic",
          "16": "L",
          "key": "AMD",
          "delayed": true,
          "assetMainType": "EQUITY",
          "assetSubType": "COE",
          "cusip": "007903107"
        },
        {
          "1": 518.76,
          "2": 518.81,
          "3": 518.8099,
          "4": 22,
          "5": 22,
          "6": "Z",
          "7": "Z",
          "8": 48401752,
          "9": 1500,
          "10": 520.18,
          "11": 517.89,
          "12": 518.43,
          "13": "P",
          "14": false,
          "15": "SPDR S&P 500 ETF",
          "16": "L",
          "key": "SPY",
          "delayed": true,
          "assetMainType": "EQUITY",
          "assetSubType": "ETF",
          "cusip": "78462F103"
        },
        {
          "1": 126.72,
          "2": 127.03,
          "3": 126.72,
          "4": 1,
          "5": 0,
          "6": "Z",
          "7": "Q",
          "8": 11952250,
          "9": 50,
          "10": 133.4399,
          "11": 125.56,
          "12": 132.72,
          "13": "N",
          "14": false,
          "15": "DELL TECHNOLOGIES IN C",
          "16": "L",
          "key": "DELL",
          "delayed": true,
          "assetMainType": "EQUITY",
          "assetSubType": "COE",
          "cusip": "24703L202"
        }
      ]
    },
    {
      "service": "CHART_EQUITY",
      "timestamp": 1712624126116,
      "command": "SUBS",
      "content": [
        {
          "1": 776,
          "2": 169.51,
          "3": 169.51,
          "4": 169.51,
          "5": 169.51,
          "6": 18,
          "7": 1712620560000,
          "8": 19821,
          "seq": 0,
          "key": "TGT"
        },
        {
          "1": 779,
          "2": 870.335,
          "3": 870.335,
          "4": 870.1,
          "5": 870.1985,
          "6": 1149,
          "7": 1712620740000,
          "8": 19821,
          "seq": 0,
          "key": "NVDA"
        },
        {
          "1": 779,
          "2": 124.42,
          "3": 124.42,
          "4": 124.42,
          "5": 124.42,
          "6": 265,
          "7": 1712620740000,
          "8": 19821,
          "seq": 0,
          "key": "ORCL"
        },
        {
          "1": 779,
          "2": 143.5,
          "3": 143.5,
          "4": 143.01,
          "5": 143.01,
          "6": 140,
          "7": 1712620740000,
          "8": 19821,
          "seq": 0,
          "key": "TSM"
        },
        {
          "1": 779,
          "2": 440.74,
          "3": 440.78,
          "4": 440.71,
          "5": 440.75,
          "6": 3650,
          "7": 1712620740000,
          "8": 19821,
          "seq": 5,
          "key": "QQQ"
        },
        {
          "1": 779,
          "2": 425.4,
          "3": 425.4,
          "4": 425.35,
          "5": 425.35,
          "6": 11,
          "7": 1712620740000,
          "8": 19821,
          "seq": 0,
          "key": "MSFT"
        },
        {
          "1": 779,
          "2": 68.86,
          "3": 68.86,
          "4": 68.86,
          "5": 68.86,
          "6": 30,
          "7": 1712620740000,
          "8": 19821,
          "seq": 0,
          "key": "OXY"
        },
        {
          "1": 777,
          "2": 65.0481,
          "3": 65.0481,
          "4": 65.0481,
          "5": 65.0481,
          "6": 6,
          "7": 1712620620000,
          "8": 19821,
          "seq": 0,
          "key": "CAVA"
        },
        {
          "1": 777,
          "2": 120.75,
          "3": 120.75,
          "4": 120.55,
          "5": 120.55,
          "6": 475,
          "7": 1712620620000,
          "8": 19821,
          "seq": 0,
          "key": "XOM"
        },
        {
          "1": 779,
          "2": 169.65,
          "3": 169.6893,
          "4": 169.65,
          "5": 169.6893,
          "6": 120001,
          "7": 1712620740000,
          "8": 19821,
          "seq": 0,
          "key": "AMD"
        },
        {
          "1": 779,
          "2": 518.805,
          "3": 518.82,
          "4": 518.795,
          "5": 518.8099,
          "6": 9194,
          "7": 1712620740000,
          "8": 19821,
          "seq": 0,
          "key": "SPY"
        },
        {
          "1": 779,
          "2": 126.6985,
          "3": 126.72,
          "4": 126.6985,
          "5": 126.72,
          "6": 447,
          "7": 1712620740000,
          "8": 19821,
          "seq": 0,
          "key": "DELL"
        }
      ]
    }
  ]
})";

static std::string shortLevelOneData = R"({
  "data": [
    {
      "service": "LEVELONE_EQUITIES",
      "timestamp": 1712596160609,
      "command": "SUBS",
      "content": [
        {
          "1": 440.96,
          "4": 16,
          "5": 6,
          "7": "Z",
          "key": "QQQ"
        },
        {
          "2": 65.08,
          "5": 0,
          "6": "Z",
          "key": "CAVA"
        },
        {
          "1": 121.25,
          "2": 121.26,
          "3": 121.25,
          "4": 1,
          "5": 9,
          "6": "Z",
          "8": 8161486,
          "key": "XOM"
        },
        {
          "3": 519.205,
          "4": 0,
          "5": 7,
          "7": "Z",
          "8": 22421029,
          "key": "SPY"
        },
        {
          "1": 126.6,
          "2": 126.66,
          "3": 126.61,
          "5": 2,
          "8": 7621000,
          "key": "DELL"
        }
      ]
    }
  ]
})";