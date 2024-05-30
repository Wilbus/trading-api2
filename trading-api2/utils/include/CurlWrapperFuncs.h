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

#if 0
    static void dump(const char *text, FILE *stream, unsigned char *ptr, size_t size)
    {
        size_t i;
        size_t c;
        unsigned int width = 0x10;
        
        //fprintf(stream, "%s, %10.10ld bytes (0x%8.8lx)\n",
        //    text, (long)size, (long)size);
        
        /*for(i = 0; i < size; i += width)
        {
            fprintf(stream, "%4.4lx: ", (long)i);
        
            // show hex to the left
            for(c = 0; c < width; c++) {
            if(i + c < size)
                fprintf(stream, "%02x ", ptr[i + c]);
            else
                fputs("   ", stream);
            }
        
            // show data on the right
            for(c = 0; (c < width) && (i + c < size); c++) {
            char x = (ptr[i + c] >= 0x20 && ptr[i + c] < 0x80) ? ptr[i + c] : '.';
            fputc(x, stream);
            }
        
            fputc('\n', stream); // newline
        }*/
    }

    static int debugCallback(CURL* curl, curl_infotype type, char* data, size_t size, void* clientp)
    {
        const char *text;
        (void)curl; /* prevent compiler warning */
        (void)clientp;
        
        //TODO: write data to a file descriptor and have another thread pull from that to write to a file
        // so we arent blocking while writing to file
        switch(type) {
            case CURLINFO_TEXT:
            {
                fputs("== Info: ", stderr);
                fwrite(data, size, 1, stderr);
                break;
            }
            default: /* in case a new one is introduced to shock us */
            {
                return 0;
            }
            
            case CURLINFO_HEADER_OUT:
            {
                text = "=> Send header";
                break;
            }
            case CURLINFO_DATA_OUT:
            {
                text = "=> Send data";
                break;
            }
            case CURLINFO_SSL_DATA_OUT:
            {
                text = "=> Send SSL data";
                break;
            }
            case CURLINFO_HEADER_IN:
            {
                text = "<= Recv header";
                break;
            }
            case CURLINFO_DATA_IN:
            {
                text = "<= Recv data";
                break;
            }
            case CURLINFO_SSL_DATA_IN:
            {
                text = "<= Recv SSL data";
                break;
            }
        }
        
        dump(text, stderr, (unsigned char *)data, size);
        return 0;
    }
#endif

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
    MYCURL_HTTP_VERSION_3 = CURL_HTTP_VERSION_3         /* Use HTTP/3, fallback to HTTP/2 or HTTP/1 if
                                        needed. For HTTPS only. For HTTP, this option
                                        makes libcurl return error. */
    //MYCURL_HTTP_VERSION_3ONLY = CURL_HTTP_VERSION_3ONLY, /* Use HTTP/3 without fallback. For HTTPS
                                    //only. For HTTP, this makes libcurl
                                    //return error. */

    //MYCURL_HTTP_VERSION_LAST = CURL_HTTP_VERSION_LAST /* *ILLEGAL* http version */
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
CURLcode mycurl_easy_setopt_debugfunction(CURL* curl, int (*debugcallback)(CURL*, curl_infotype, char*, size_t, void*));
CURLcode mycurl_easy_setopt_debugdata(CURL* curl, void* pointer);
CURLcode mycurl_easy_setopt_stderr(CURL* curl, FILE* stream);
CURLcode mycurl_easy_setopt_verbose(CURL* curl, bool flag);
CURLcode mycurl_easy_setopt_writedata(CURL* curl, void* readbuffer);
CURLcode mycurl_easy_perform(CURL* curl);
void mycurl_easy_cleanup(CURL* curl);
void mycurl_global_cleanup();

} // namespace restclient