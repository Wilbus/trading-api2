#include "RestClient.h"

#include <iostream>
#include <stdio.h>
#include <utility>

namespace restclient {

RestClient::RestClient(std::string baseEnd)
{
    baseEndpoint = baseEnd;
}

std::string RestClient::getResponse(std::string path, httplib::Headers headers) const
{
    httplib::SSLClient client(baseEndpoint.c_str());
    auto resp = client.Get(path.c_str(), headers);

    if (!resp)
    {
        return "";
    }

    if (resp->status != 200)
    {
        // TODO: print status of error
        throw std::runtime_error("RestClient GET error");
    }

    return resp->body;
}

std::string RestClient::postResponse(std::string path, httplib::Headers params) const
{
    httplib::SSLClient client(baseEndpoint.c_str());
    auto resp = client.Post(path.c_str(), params);

    if (!resp)
    {
        return "";
    }

    if (resp->status != 200)
    {
        // TODO: print status of error
        throw std::runtime_error("RestClient POST error");
    }

    return resp->body;
}

std::string RestClient::postResponse(std::string path, httplib::Headers params, std::string body, std::string content_type) const
{
    httplib::SSLClient client(baseEndpoint.c_str());
    auto resp = client.Post(path.c_str(), params, body, content_type);

    if (!resp)
    {
        return "";
    }

    if (resp->status != 200)
    {
        // TODO: print status of error
        throw std::runtime_error("RestClient POST error");
    }

    return resp->body;
}

} // namespace restclient