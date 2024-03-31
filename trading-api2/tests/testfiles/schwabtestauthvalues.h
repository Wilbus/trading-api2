#pragma once

#include <string>

std::string createAccessTokenRespExample =
R"({ 
	"expires_in": 1800,
	"token_type": "Bearer",
	"scope": "api",
	"refresh_token": "REFRESH_TOKEN_HERE",
	"access_token": "ACCESS_TOKEN_HERE",
	"id_token": "JWT_HERE"
})";