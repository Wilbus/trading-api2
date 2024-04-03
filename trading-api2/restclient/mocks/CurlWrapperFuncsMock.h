#pragma once

#include "CurlWrapperFuncs.h"

#include <gmock/gmock.h>

namespace restclient {

namespace mocks {

class CurlWrapperFuncsMock
{
public:
    CurlWrapperFuncsMock();
    ~CurlWrapperFuncsMock();
    MOCK_METHOD1(mycurl_global_init, CURLcode(long));
    MOCK_METHOD0(mycurl_easy_init, CURL*());
    MOCK_METHOD2(mycurl_slist_append, struct curl_slist*(struct curl_slist*, std::string data));
    MOCK_METHOD1(mycurl_slist_free_all, void(curl_slist*));
    MOCK_METHOD2(mycurl_easy_setopt_url, CURLcode(CURL*, std::string));
    MOCK_METHOD2(mycurl_easy_setopt_http_version, CURLcode(CURL*, CurlHttpVersions));
    MOCK_METHOD2(mycurl_easy_setopt_httpget, CURLcode(CURL*, bool));
    MOCK_METHOD2(mycurl_easy_setopt_httppost, CURLcode(CURL*, bool));
    MOCK_METHOD2(mycurl_easy_setopt_copypostfields, CURLcode(CURL*, std::string));
    MOCK_METHOD2(mycurl_easy_setopt_httpheader, CURLcode(CURL*, curl_slist*));
    MOCK_METHOD2(
        mycurl_easy_setopt_writefunction, CURLcode(CURL*, size_t (*writefunction)(void*, size_t, size_t, void*)));
    MOCK_METHOD2(mycurl_easy_setopt_verbose, CURLcode(CURL*, bool));
    MOCK_METHOD2(mycurl_easy_setopt_writedata, CURLcode(CURL*, void*));
    MOCK_METHOD1(mycurl_easy_perform, CURLcode(CURL*));
    MOCK_METHOD1(mycurl_easy_cleanup, void(CURL*));
    MOCK_METHOD0(mycurl_global_cleanup, void());

    static CurlWrapperFuncsMock& inst();
};

} // namespace mocks
} // namespace restclient