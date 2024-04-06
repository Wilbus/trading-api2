#pragma once

#include <string>

std::string loginResponse = R"({
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

std::string loginDeniedResponse = R"({
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