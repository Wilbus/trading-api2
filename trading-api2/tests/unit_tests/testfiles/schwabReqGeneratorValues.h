#pragma once

#include <string>

//clang-format off
const std::string testlogin =
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

const std::string qosRequest =
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

const std::string accountAcitivtyRequest =
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
//clang-format on