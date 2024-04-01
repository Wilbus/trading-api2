#pragma once

#define CPPHTTPLIB_OPENSSL_SUPPORT // httplib ssl suppoer flag
#include "httplib.h"

#include <string>

namespace restclient {

class IRestClient
{
public:
    virtual std::string getResponse(std::string path, httplib::Headers headers) const = 0;
    virtual std::string postResponse(std::string path, httplib::Headers params) const = 0;
    virtual std::string postResponse(
        std::string path, httplib::Headers params, std::string body, std::string content_type) const = 0;
};
} // namespace restclient