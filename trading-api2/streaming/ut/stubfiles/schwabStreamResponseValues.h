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