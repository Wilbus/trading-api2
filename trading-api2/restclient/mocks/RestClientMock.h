#pragma once

#include "IRestClient.h"

#include <gmock/gmock.h>

using namespace restclient;

class RestClientMock : public IRestClient
{
public:
    MOCK_CONST_METHOD2(getResponse, std::string(std::string, httplib::Headers));
    MOCK_CONST_METHOD2(postResponse, std::string(std::string, httplib::Headers));
};