#pragma once
#define CPPHTTPLIB_OPENSSL_SUPPORT // needed for SSLClient class

#include "IRestClient.h"

namespace restclient {

class RestClient : public IRestClient
{
public:
    RestClient();

    virtual void setBaseEndpoint(std::string endpoint) override;
    virtual std::string getResponse(std::string path, httplib::Headers headers) const override;
    virtual std::string postResponse(std::string path, httplib::Headers params) const override;
    virtual std::string postResponse(
        std::string path, httplib::Headers params, std::string body, std::string content_type) const override;

private:
    std::string baseEndpoint;
};
} // namespace restclient