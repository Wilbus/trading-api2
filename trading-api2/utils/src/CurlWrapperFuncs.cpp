#include "CurlWrapperFuncs.h"

#include <iostream>

namespace restclient {

CURLcode mycurl_global_init(long flags) // MUST call this at the very beginning or valgrind will throw errors
{
    return curl_global_init(flags);
}

CURL* mycurl_easy_init()
{
    return curl_easy_init();
}

struct curl_slist* mycurl_slist_append(curl_slist* list, std::string data)
{
    return curl_slist_append(list, data.c_str());
}

void mycurl_slist_free_all(curl_slist* list)
{
    curl_slist_free_all(list);
}

CURLcode mycurl_easy_setopt_url(CURL* curl, std::string url)
{
    return curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
}

CURLcode mycurl_easy_setopt_http_version(CURL* curl, CurlHttpVersions httpversion)
{
    return curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, httpversion);
}

CURLcode mycurl_easy_setopt_httpget(CURL* curl, bool flag)
{
    return curl_easy_setopt(curl, CURLOPT_HTTPGET, flag);
}

CURLcode mycurl_easy_setopt_httppost(CURL* curl, bool flag)
{
    return curl_easy_setopt(curl, CURLOPT_HTTPPOST, flag);
}

CURLcode mycurl_easy_setopt_copypostfields(CURL* curl, std::string data)
{
    return curl_easy_setopt(curl, CURLOPT_COPYPOSTFIELDS, data.c_str());
}

CURLcode mycurl_easy_setopt_httpheader(CURL* curl, curl_slist* list)
{
    return curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
}

CURLcode mycurl_easy_setopt_writefunction(CURL* curl, size_t (*writefunction)(void*, size_t, size_t, void*))
{
    return curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunction);
}

CURLcode mycurl_easy_setopt_debugfunction(CURL* curl, int (*debugcallback)(CURL*, curl_infotype, char*, size_t, void*))
{
    return curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, debugcallback);
}

CURLcode mycurl_easy_setopt_debugdata(CURL* curl, void* pointer)
{
    return curl_easy_setopt(curl, CURLOPT_DEBUGDATA, pointer);
}

CURLcode mycurl_easy_setopt_stderr(CURL* curl, FILE* stream)
{
    return curl_easy_setopt(curl, CURLOPT_STDERR, stream);
}

CURLcode mycurl_easy_setopt_verbose(CURL* curl, bool flag)
{
    return curl_easy_setopt(curl, CURLOPT_VERBOSE, flag);
}

CURLcode mycurl_easy_setopt_writedata(CURL* curl, void* readbuffer)
{
    return curl_easy_setopt(curl, CURLOPT_WRITEDATA, readbuffer);
}

CURLcode mycurl_easy_perform(CURL* curl)
{
    return curl_easy_perform(curl);
}

void mycurl_easy_cleanup(CURL* curl)
{
    return curl_easy_cleanup(curl);
}

void mycurl_global_cleanup() // MUST call this at the very end of program
{
    return curl_global_cleanup();
}

} // namespace restclient