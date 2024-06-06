#pragma once

#include <string>

static std::string createAccessTokenRespExample =
    R"({ 
	"expires_in": 1800,
	"token_type": "Bearer",
	"scope": "api",
	"refresh_token": "REFRESH_TOKEN_HERE",
	"access_token": "ACCESS_TOKEN_HERE",
	"id_token": "JWT_HERE"
})";

static std::string userPreferenceRespExample = R"({
  "accounts": [
    {
      "accountNumber": "123456789",
      "primaryAccount": true,
      "type": "BROKERAGE",
      "nickName": "Individual",
      "displayAcctId": "...249",
      "autoPositionEffect": true,
      "accountColor": "Green"
    },
    {
      "accountNumber": "444555666",
      "primaryAccount": false,
      "type": "BROKERAGE",
      "nickName": "Individual",
      "displayAcctId": "...742",
      "autoPositionEffect": false,
      "accountColor": "Blue"
    }
  ],
  "streamerInfo": [
    {
      "streamerSocketUrl": "wss://streamer-api.schwab.com/ws",
      "schwabClientCustomerId": "some-customer-id",
      "schwabClientCorrelId": "some-correl-id",
      "schwabClientChannel": "N9",
      "schwabClientFunctionId": "APIAPP"
    }
  ],
  "offers": [
    {
      "level2Permissions": false
    }
  ]
})";