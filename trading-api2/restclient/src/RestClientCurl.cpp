#include "RestClientCurl.h"

#include "Logger.h"

#include <iostream>

namespace restclient {

RestClientCurl::RestClientCurl()
{
    mycurl_global_init(CURL_GLOBAL_ALL);
    curl = mycurl_easy_init();
}

RestClientCurl::RestClientCurl(std::string debugFileFolder, std::string logfile)
    : debugFileFolder(debugFileFolder)
    , logfile(logfile)
{
    mycurl_global_init(CURL_GLOBAL_ALL);
    curl = mycurl_easy_init();

    std::string debugFilePath = debugFileFolder + verboseInfoFileName;
    verboseInfoFilePtr = fopen(debugFilePath.c_str(), "a");
    if (verboseInfoFilePtr == nullptr)
    {
        throw std::runtime_error("could not open verboseInfoFile.txt");
    }
}

RestClientCurl::~RestClientCurl()
{
    mycurl_easy_cleanup(curl);
    mycurl_global_cleanup();
    if (verboseInfoFilePtr != nullptr)
    {
        fclose(verboseInfoFilePtr);
    }
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
    infologprint(logfile, "%s: %s", __func__, finalUrl.c_str());

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

#if 0
    code = mycurl_easy_setopt_debugfunction(curl, debugCallback);
    if (!checkCURLcode(code))
    {
        throw std::runtime_error("invalid curlcode");
    }
#endif

    code = mycurl_easy_setopt_stderr(curl, verboseInfoFilePtr);
    if (!checkCURLcode(code))
    {
        throw std::runtime_error("invalid curlcode");
    }

    code = mycurl_easy_setopt_verbose(curl, true); // TODO: make this configurable
    if (!checkCURLcode(code))
    {
        throw std::runtime_error("invalid curlcode");
    }

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
    return {};
}

std::string RestClientCurl::postResponse(
    const std::string path, const std::set<std::string>& headersList, const std::string body)
{
    if (curl == nullptr)
    {
        throw std::runtime_error("CURL* curl is nullptr");
    }
    std::string finalUrl = baseEndpoint + path;
    infologprint(logfile, "%s: %s", __func__, finalUrl.c_str());

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

    // consider using MIMEPOST because httppost is deprecated
    code = mycurl_easy_setopt_httppost(curl, true);
    if (!checkCURLcode(code))
    {
        throw std::runtime_error("invalid curlcode");
    }

    // data pointed to is NOT COPIED. Unless we set CURLOPT_COPYPOSTFIELDS
    // char local_buffer[1024]="data to send";
    // may need to url encode??
    code = mycurl_easy_setopt_copypostfields(curl, body);
    if (!checkCURLcode(code))
    {
        throw std::runtime_error("invalid curlcode");
    }
    // curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");

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

#if 0
    code = mycurl_easy_setopt_debugfunction(curl, debugCallback);
    if (!checkCURLcode(code))
    {
        throw std::runtime_error("invalid curlcode");
    }
#endif

    code = mycurl_easy_setopt_stderr(curl, verboseInfoFilePtr);
    if (!checkCURLcode(code))
    {
        throw std::runtime_error("invalid curlcode");
    }

    code = mycurl_easy_setopt_verbose(curl, true); // TODO: make this configurable
    if (!checkCURLcode(code))
    {
        throw std::runtime_error("invalid curlcode");
    }

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

} // namespace restclient