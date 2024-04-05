#pragma once

#include <string>

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