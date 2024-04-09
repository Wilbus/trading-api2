#pragma once

#include <string>

//clang-format off
static std::string testlogin =
    R"({
    "service": "ADMIN",
    "requestid": 0,
    "command": "LOGIN",
    "SchwabClientCustomerId": "customerId",
    "SchwabClientCorrelId": "correlId",
    "parameters": {
        "Authorization": "accessToken",
        "SchwabClientChannel": "clientChannel",
        "SchwabClientFunctionId": "clientFunctionId"
    }
})";

static std::string qosRequest =
    R"({
    "service": "ADMIN",
    "requestid": 1,
    "command": "QOS",
    "SchwabClientCustomerId": "customerId",
    "SchwabClientCorrelId": "correlId",
    "parameters": {
        "qoslevel": "0"
    }
})";

static std::string accountAcitivtyRequest =
    R"({
    "service": "ACCT_ACTIVITY",
    "requestid": 2,
    "command": "SUBS",
    "SchwabClientCustomerId": "customerId",
    "SchwabClientCorrelId": "correlId",
    "parameters": {
        "keys": "somekey",
        "fields": "0,1,2,3"
    }
})";

static std::string levelOneEquitiesRequest =
    R"({
    "service": "LEVELONE_EQUITIES",
    "requestid": 2,
    "command": "SUBS",
    "SchwabClientCustomerId": "customerId",
    "SchwabClientCorrelId": "correlId",
    "parameters": {
        "keys": "QQQ",
        "fields": "0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16"
    }
})";

static std::string chartEquityRequest =
    R"({
    "service": "CHART_EQUITY",
    "requestid": 2,
    "command": "SUBS",
    "SchwabClientCustomerId": "customerId",
    "SchwabClientCorrelId": "correlId",
    "parameters": {
        "keys": "QQQ",
        "fields": "0,1,2,3,4,5,6,7,8"
    }
})";

static std::string optionRequest =
    R"({
    "service": "OPTION",
    "requestid": 2,
    "command": "SUBS",
    "SchwabClientCustomerId": "customerId",
    "SchwabClientCorrelId": "correlId",
    "parameters": {
        "keys": "QQQ",
        "fields": "0,1,2,3,4,5,6,7,8,9,10,11,12,20,21,22,23,24,32,33,34,35,36,38,41"
    }
})";
//clang-format on