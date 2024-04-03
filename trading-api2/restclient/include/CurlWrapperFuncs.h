#pragma once

#include <curl/curl.h>

#include <functional>
#include <string>

namespace restclient {

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

enum CurlHttpVersions
{
    MYCURL_HTTP_VERSION_NONE = CURL_HTTP_VERSION_NONE, /* setting this means we don't care, and that we'd
                             like the library to choose the best possible
                             for us! */
    MYCURL_HTTP_VERSION_1_0 = CURL_HTTP_VERSION_1_0,   /* please use HTTP 1.0 in the request */
    MYCURL_HTTP_VERSION_1_1 = CURL_HTTP_VERSION_1_1,   /* please use HTTP 1.1 in the request */
    MYCURL_HTTP_VERSION_2_0 = CURL_HTTP_VERSION_2_0,   /* please use HTTP 2 in the request */
    MYCURL_HTTP_VERSION_2TLS = CURL_HTTP_VERSION_2TLS, /* use version 2 for HTTPS, version 1.1 for HTTP */
    MYCURL_HTTP_VERSION_2_PRIOR_KNOWLEDGE = CURL_HTTP_VERSION_2_PRIOR_KNOWLEDGE, /* please use HTTP 2 without HTTP/1.1
                                           Upgrade */
    MYCURL_HTTP_VERSION_3 = CURL_HTTP_VERSION_3,         /* Use HTTP/3, fallback to HTTP/2 or HTTP/1 if
                                        needed. For HTTPS only. For HTTP, this option
                                        makes libcurl return error. */
    MYCURL_HTTP_VERSION_3ONLY = CURL_HTTP_VERSION_3ONLY, /* Use HTTP/3 without fallback. For HTTPS
                                    only. For HTTP, this makes libcurl
                                    return error. */

    MYCURL_HTTP_VERSION_LAST = CURL_HTTP_VERSION_LAST /* *ILLEGAL* http version */
};

CURLcode mycurl_global_init(long flags); // MUST call this at the very beginning or valgrind will throw errors
CURL* mycurl_easy_init();
struct curl_slist* mycurl_slist_append(curl_slist* list, std::string data);
void mycurl_slist_free_all(curl_slist* list);
CURLcode mycurl_easy_setopt_url(CURL* curl, std::string url);
CURLcode mycurl_easy_setopt_http_version(CURL* curl, CurlHttpVersions httpversion);
CURLcode mycurl_easy_setopt_httpget(CURL* curl, bool flag);
CURLcode mycurl_easy_setopt_httppost(CURL* curl, bool flag);
CURLcode mycurl_easy_setopt_httpheader(CURL* curl, curl_slist* list);
CURLcode mycurl_easy_setopt_copypostfields(CURL* curl, std::string data);
CURLcode mycurl_easy_setopt_writefunction(CURL* curl, size_t (*writefunction)(void*, size_t, size_t, void*));
CURLcode mycurl_easy_setopt_verbose(CURL* curl, bool flag);
CURLcode mycurl_easy_setopt_writedata(CURL* curl, void* readbuffer);
CURLcode mycurl_easy_perform(CURL* curl);
void mycurl_easy_cleanup(CURL* curl);
void mycurl_global_cleanup();

} // namespace restclient