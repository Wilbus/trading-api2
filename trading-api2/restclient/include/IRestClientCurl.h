#pragma once

#include <set>
#include <string>

namespace restclient {

class IRestClientCurl
{
public:
    virtual void setBaseEndpoint(const std::string endpoint) = 0;
    virtual std::string getResponse(const std::string path, const std::set<std::string> headersList) = 0;
    virtual std::string postResponse(const std::string path, const std::set<std::string> headersList) = 0;
    virtual std::string postResponse(
        const std::string path, const std::set<std::string>& headersList, const std::string body) = 0;
};
} // namespace restclient