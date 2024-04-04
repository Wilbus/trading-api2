#pragma once

#include "CurlWrapperFuncs.h"
#include "IRestClientCurl.h"

namespace restclient {

class RestClientCurl : public IRestClientCurl
{
public:
    RestClientCurl();
    ~RestClientCurl();
    virtual void setBaseEndpoint(const std::string endpoint) override;
    virtual std::string getResponse(const std::string path, const std::set<std::string> headersList) override;
    virtual std::string postResponse(const std::string path, const std::set<std::string> headersList) override;
    virtual std::string postResponse(
        const std::string path, const std::set<std::string>& headersList, const std::string body) override;

protected:
    std::string readbuffer;

private:
    bool checkCURLcode(const CURLcode code);
    std::string baseEndpoint;
    CURL* curl;
    // std::string readbuffer;
};
} // namespace restclient