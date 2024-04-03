#include "CurlWrapperFuncsMock.h"
#include "CurlWrapperFuncs.h"

#include <memory>

namespace restclient {

CURLcode mycurl_global_init(long flags)
{
    return restclient::mocks::CurlWrapperFuncsMock::inst().mycurl_global_init(flags);
}

CURL* mycurl_easy_init()
{
    return restclient::mocks::CurlWrapperFuncsMock::inst().mycurl_easy_init();
}

struct curl_slist* mycurl_slist_append(struct curl_slist* list, std::string data)
{
    return restclient::mocks::CurlWrapperFuncsMock::inst().mycurl_slist_append(list, data);
}

void mycurl_slist_free_all(curl_slist* list)
{
    return restclient::mocks::CurlWrapperFuncsMock::inst().mycurl_slist_free_all(list);
}

CURLcode mycurl_easy_setopt_url(CURL* curl, std::string url)
{
    return restclient::mocks::CurlWrapperFuncsMock::inst().mycurl_easy_setopt_url(curl, url);
}

CURLcode mycurl_easy_setopt_http_version(CURL* curl, CurlHttpVersions httpversion)
{
    return restclient::mocks::CurlWrapperFuncsMock::inst().mycurl_easy_setopt_http_version(curl, httpversion);
}

CURLcode mycurl_easy_setopt_httpget(CURL* curl, bool flag)
{
    return restclient::mocks::CurlWrapperFuncsMock::inst().mycurl_easy_setopt_httpget(curl, flag);
}

CURLcode mycurl_easy_setopt_httpheader(CURL* curl, curl_slist* list)
{
    return restclient::mocks::CurlWrapperFuncsMock::inst().mycurl_easy_setopt_httpheader(curl, list);
}

CURLcode mycurl_easy_setopt_writefunction(CURL* curl, size_t (*writefunction)(void*, size_t, size_t, void*))
{
    return restclient::mocks::CurlWrapperFuncsMock::inst().mycurl_easy_setopt_writefunction(curl, writefunction);
}

CURLcode mycurl_easy_setopt_verbose(CURL* curl, bool flag)
{
    return restclient::mocks::CurlWrapperFuncsMock::inst().mycurl_easy_setopt_verbose(curl, flag);
}

CURLcode mycurl_easy_setopt_writedata(CURL* curl, void* readbuffer)
{
    //TODO: only way I know of to mock a successful curl_easy_perform filling the readbuffer at the moment
    ((std::string*)readbuffer)->append("somejsondata");
    return restclient::mocks::CurlWrapperFuncsMock::inst().mycurl_easy_setopt_writedata(curl, readbuffer);
}

CURLcode mycurl_easy_perform(CURL* curl)
{
    return restclient::mocks::CurlWrapperFuncsMock::inst().mycurl_easy_perform(curl);
}

void mycurl_easy_cleanup(CURL* curl)
{
    return restclient::mocks::CurlWrapperFuncsMock::inst().mycurl_easy_cleanup(curl);
}

void mycurl_global_cleanup() // MUST call this at the very end of program
{
    return restclient::mocks::CurlWrapperFuncsMock::inst().mycurl_global_cleanup();
}

namespace mocks {

CurlWrapperFuncsMock::CurlWrapperFuncsMock()
{
}

CurlWrapperFuncsMock::~CurlWrapperFuncsMock()
{
}

CurlWrapperFuncsMock& CurlWrapperFuncsMock::inst()
{
    static std::unique_ptr<CurlWrapperFuncsMock> mockPtr(new CurlWrapperFuncsMock());
    return *(mockPtr).get();
}

} // namespace mocks
} // namespace restclient