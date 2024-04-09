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

static std::string bigLevelOneDataResponse = R"({"data":[{"service":"LEVELONE_EQUITIES", "timestamp":1712595046811,"command":"SUBS","content":[{"key":"QQQ","delayed":true,"assetMainType":"EQUITY","assetSubType":"ETF","cusip":"46090E103","1":440.78,"2":440.79,"3":440.78,"4":1,"5":19,"6":"Z","7":"Q","8":15456387,"9":100,"10":442.5,"11":439.2,"12":440.47,"13":"Q","14":false,"15":"INVSC QQQ TRUST SRS 1 ETF IV","16":"L"},{"key":"AMD","delayed":true,"assetMainType":"EQUITY","assetSubType":"COE","cusip":"007903107","1":169.73,"2":169.75,"3":169.7201,"4":1,"5":0,"6":"Z","7":"Q","8":29619002,"9":200,"10":171.6599,"11":166.82,"12":170.42,"13":"Q","14":false,"15":"Advanced Micro Devic","16":"L"},{"key":"SPY","delayed":true,"assetMainType":"EQUITY","assetSubType":"ETF","cusip":"78462F103","1":519.08,"2":519.09,"3":519.08,"4":3,"5":6,"6":"Z","7":"Q","8":21421274,"9":100,"10":520.18,"11":517.89,"12":518.43,"13":"P","14":false,"15":"SPDR S&P 500 ETF","16":"Q"},{"key":"CAVA","delayed":true,"assetMainType":"EQUITY","assetSubType":"COE","cusip":"148929102","1":64.89,"2":64.93,"3":64.89,"4":0,"5":5,"6":"Z","7":"Z","8":403310,"9":100,"10":65.3999,"11":64.24,"12":64.65,"13":"N","14":false,"15":"CAVA GROUP INC","16":"L"}]}]})";