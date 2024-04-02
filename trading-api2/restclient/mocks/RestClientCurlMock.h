#pragma once

#include "IRestClientCurl.h"

class RestClientCurlMock : public IRestClientCurl
{
public:
    MOCK_METHOD1(setBaseEndpoint, void(const std::string));
    MOCK_METHOD2(getResponse, std::string(const std::string, const std::set<std::string>));
    MOCK_METHOD2(postResponse, std::string(const std::string, const std::set<std::string>));
    MOCK_METHOD3(postResponse, std::string(const std::string, const std::set<std::string>&, const std::string));
};