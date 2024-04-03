#include "RestClientCurl.h"

#include <iostream>

namespace restclient {

RestClientCurl::RestClientCurl()
{
    mycurl_global_init(CURL_GLOBAL_ALL);
    curl = mycurl_easy_init();
}

RestClientCurl::~RestClientCurl()
{
    mycurl_easy_cleanup(curl);
    mycurl_global_cleanup();
}

void RestClientCurl::setBaseEndpoint(const std::string endpoint)
{
    baseEndpoint = endpoint;
}

bool RestClientCurl::checkCURLcode(const CURLcode code)
{
    if (code != CURLE_OK)
    {
        // std::cout << "CURLcode not ok! " << static_cast<unsigned>(code) << "\n";
        return false;
    }
    return true;
}

// TODO: print the CURLcode if it is not valid
std::string RestClientCurl::getResponse(const std::string path, const std::set<std::string> headersList)
{
    if (curl == nullptr)
    {
        throw std::runtime_error("CURL* curl is nullptr");
    }
    std::string finalUrl = baseEndpoint + path;
    readbuffer.clear();

    CURLcode code;

    curl_slist* list = nullptr;
    for (const auto& header : headersList)
    {
        list = mycurl_slist_append(list, header);
    }

    code = mycurl_easy_setopt_url(curl, finalUrl);
    if (!checkCURLcode(code))
    {
        throw std::runtime_error("invalid curlcode");
    }

    code = mycurl_easy_setopt_http_version(curl, CurlHttpVersions::MYCURL_HTTP_VERSION_1_0);
    if (!checkCURLcode(code))
    {
        throw std::runtime_error("invalid curlcode");
    }

    code = mycurl_easy_setopt_httpget(curl, true);
    if (!checkCURLcode(code))
    {
        throw std::runtime_error("invalid curlcode");
    }

    code = mycurl_easy_setopt_httpheader(curl, list);
    if (!checkCURLcode(code))
    {
        throw std::runtime_error("invalid curlcode");
    }

    code = mycurl_easy_setopt_writefunction(curl, restclient::WriteCallback);
    if (!checkCURLcode(code))
    {
        throw std::runtime_error("invalid curlcode");
    }

    mycurl_easy_setopt_verbose(curl, true); //TODO: make this configurable

    code = mycurl_easy_setopt_writedata(curl, &readbuffer);
    if (!checkCURLcode(code))
    {
        throw std::runtime_error("invalid curlcode");
    }

    code = mycurl_easy_perform(curl);
    if (!checkCURLcode(code))
    {
        throw std::runtime_error("invalid curlcode");
    }

    return readbuffer;
}

std::string RestClientCurl::postResponse(const std::string path, const std::set<std::string> headersList)
{
}

std::string RestClientCurl::postResponse(
    const std::string path, const std::set<std::string>& headersList, const std::string body)
{
}

} // namespace restclient