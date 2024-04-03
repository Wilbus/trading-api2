#include "SchwabMarketDataParser.h"
#include "UriEncodeDecode.h"
#include <functional>
#include <curl/curl.h>

#include <iostream>
#include <string>

// https://stackoverflow.com/questions/37997328/using-curl-for-get-request

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

CURLcode mycurl_easy_setopt_writefunction(CURL* curl, size_t (*writefunction)(void*, size_t, size_t, void*))
{
    return curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunction);
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl)
    {
        std::string baseUrl = "https://api.schwabapi.com/v1/oauth/token";
        //std::string path = "/quotes?symbols=SPY&fields=quote&indicative=false";
        //std::string path2 = "/expirationchain?symbol=AAPL";
        std::string finalUrl = baseUrl;
        // std::string encodedFinalUrl = utils::url_encode(finalUrl);

        struct curl_slist* list = nullptr;
        list = curl_slist_append(list, "Content-Type: application/x-www-form-urlencoded");
        list = curl_slist_append(
            list, "Authorization: Basic appsecret123"); //appsecret

        /*mimepost is the curl -F option*/
        /*
        curl_mime* multipart = curl_mime_init(curl);
        curl_mimepart* part = curl_mime_addpart(multipart);
        #if 0
        curl_mime_name(part, "grant_type");
        curl_mime_data(part, "b2F1dGgyLmJkYy5zY2h3YWIuY29t.ueE5t2bqNPJc6e6QIwbkDI5JOXipHbOj-WUERhj5lUQ@");
        curl_mime_name(part, "redirect_uri");
        curl_mime_data(part, "https://127.0.0.1");
        #endif
        curl_mime_name(part, "grant_type");
        curl_mime_data(part, "refresh1234", CURL_ZERO_TERMINATED); //refresh_token
        part = curl_mime_addpart(multipart);
        curl_easy_setopt(curl, CURLOPT_MIMEPOST, multipart);
        */

        curl_easy_setopt(curl, CURLOPT_URL, finalUrl.c_str()); // should be URLencoded
        curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_0);
        // data pointed to is NOT COPIED. Unless we set CURLOPT_COPYPOSTFIELDS
        // char local_buffer[1024]="data to send";
        std::string data = "grant_type=refresh_token&refresh_token=token1234";
        curl_easy_setopt(curl, CURLOPT_COPYPOSTFIELDS, data.c_str());
        // curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
        //curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        mycurl_easy_setopt_writefunction(curl, WriteCallback);

        /*we can use CURLOPT_VERBOSE for debugging purposes. It displays information about the curl operations.
        Automatically sent to stderr, or a stream set with CURLOPT_STDERR
        Ex)
        * Trying 104.117.244.82:443...
        * Connected to api.schwabapi.com (104.117.244.82) port 443
        * ALPN: curl offers http/1.0
        *  CAfile: /etc/ssl/certs/ca-certificates.crt
        *  CApath: /etc/ssl/certs
        * SSL connection using TLSv1.3 / TLS_AES_256_GCM_SHA384
        * ALPN: server accepted http/1.0
        * Server certificate:
        *  subject: C=US; ST=Texas; L=Westlake; O=Charles Schwab & Co., Inc.; CN=api.schwabapi.com
        *  start date: Jul 17 00:00:00 2023 GMT
        *  expire date: Jul 10 23:59:59 2024 GMT
        *  subjectAltName: host "api.schwabapi.com" matched cert's "api.schwabapi.com"
        *  issuer: C=US; O=DigiCert Inc; CN=DigiCert Global G2 TLS RSA SHA256 2020 CA1
        *  SSL certificate verify ok.
        * using HTTP/1.x
        > GET /marketdata/v1/expirationchain?symbol=AAPL HTTP/1.0
        Host: api.schwabapi.com
        accept: application/json
        Authorization: Bearer I0.b2F1dGgyLmJkYy5zY2h3YWIuY29t.x0xizIGSHbdYxYLIajZlTFaGrcB1t2zScRu5ZqutHb4@

        * old SSL session ID is stale, removing
        * HTTP 1.0, assume close after body
        < HTTP/1.0 200 OK
        < Content-Type: application/json;charset=UTF-8
        < Schwab-Client-Correlid: 526a15c5-592a-e997-c607-a21f38e93b9e
        < Schwab-Resource-Version: 1
        < F5IP: 162.93.119.26
        < Cache-Control: no-store
        < Pragma: no-cache
        < Expires: -1
        < Access-Control-Allow-Origin:
        < Access-Control-Allow-Headers: origin, x-requested-with, accept, content-type, authorization,
        Schwab-Client-CorrelId, Schwab-Resource-Version, Schwab-Client-IpAddress < Access-Control-Max-Age: 3628800 <
        Access-Control-Allow-Methods: GET, POST < Date: Tue, 02 Apr 2024 02:06:15 GMT < Content-Length: 2959 <
        Connection: close < Strict-Transport-Security: max-age=30
        <
        * Closing connection
        */
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        //curl_mime_free(multipart);
        curl_easy_cleanup(curl);

        std::cout << readBuffer << std::endl;
    }
}