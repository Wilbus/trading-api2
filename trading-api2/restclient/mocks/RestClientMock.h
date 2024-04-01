#pragma once

#include "IRestClient.h"

#include <gmock/gmock.h>

using namespace restclient;

class RestClientMock : public IRestClient
{
public:
    MOCK_METHOD1(setBaseEndpoint, void(std::string));
    MOCK_CONST_METHOD2(getResponse, std::string(std::string, httplib::Headers));
    MOCK_CONST_METHOD2(postResponse, std::string(std::string, httplib::Headers));
    MOCK_CONST_METHOD4(postResponse, std::string(std::string, httplib::Headers, std::string, std::string));
};