#include "SchwabMarketDataParser.h"
#include "UriEncodeDecode.h"

#include <curl/curl.h>

#include <iostream>
#include <string>

// https://stackoverflow.com/questions/37997328/using-curl-for-get-request

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
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
        std::string baseUrl = "https://api.schwabapi.com/marketdata/v1";
        std::string path = "/quotes?symbols=SPY&fields=quote&indicative=false";
        std::string path2 = "/expirationchain?symbol=AAPL";
        std::string finalUrl = baseUrl + path2;
        // std::string encodedFinalUrl = utils::url_encode(finalUrl);

        struct curl_slist* list = nullptr;
        list = curl_slist_append(list, "accept: application/json");
        list = curl_slist_append(
            list, "Authorization: Bearer I0.b2F1dGgyLmJkYy5zY2h3YWIuY29t.x0xizIGSHbdYxYLIajZlTFaGrcB1t2zScRu5ZqutHb4@");

        curl_easy_setopt(curl, CURLOPT_URL, finalUrl.c_str()); // should be URLencoded
        curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_0);
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        // curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L); //automataically sets CURLOPT_NOBODY to 0

        // data pointed to is NOT COPIED. Unless we set CURLOPT_COPYPOSTFIELDS
        // char local_buffer[1024]="data to send";
        // curl_easy_setopt(curl, CURLOPT_COPYPOSTFIELDS, local_buffer);
        // curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

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
        curl_easy_cleanup(curl);

        std::cout << readBuffer << std::endl;
        auto expirations = schwabMarketData::parseOptionExpirations(readBuffer);
        std::cout << expirations.size() << "\n";
        std::cout << expirations[0].expirationDate << "\n";
    }
}