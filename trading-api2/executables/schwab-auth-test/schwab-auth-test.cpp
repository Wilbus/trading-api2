#include "RestClient.h"
#include "SchwabClient.h"

#include <curl/curl.h>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    std::shared_ptr<RestClient> restClient = std::make_shared<RestClient>();
/*std::shared_ptr<SchwabConfigs> configs = std::make_shared<SchwabConfigs>("/datadisk0/sambashare0/coding/configs/");
std::shared_ptr<SchwabClient> sclient = std::make_shared<SchwabClient>(configs, restClient);
auto quotes = sclient->getEquityQuotes(std::set<std::string>{"SPY"});
std::cout << quotes.at("SPY").quote.yearHigh << "\n";*/
#if 0
    restClient->setBaseEndpoint("api.schwabapi.com/marketdata/v1");

    std::string bearer = R"(Bearer I0.kC95zyI039S-YTEw=)";

    httplib::Headers headers = {
        {"accept", "application/json"},
        {"Authorization", bearer.c_str()}
    };
    auto resp = restClient->getResponse("/quotes?symbols=SPY&fields=quote&indicative=false", headers);
    std::cout << resp << "\n";
#endif

#if 0
    //works
    restClient->setBaseEndpoint("api.tradier.com");

    httplib::Headers headers = {
        {"accept", "application/json"},
        {"Authorization", "Bearer eKtYC2m5aMxYIzfzrUGJAOehA8T8"}
    };
    auto resp = restClient->getResponse("/v1/user/profile", headers);
    std::cout << resp << "\n";
#endif

    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl)
    {
        std::string baseUrl = "https://api.schwabapi.com/marketdata/v1";
        std::string path = "/quotes?symbols=SPY&fields=quote&indicative=false";
        std::string finalUrl = baseUrl + path;

        struct curl_slist* list = nullptr;
        list = curl_slist_append(list, "accept: application/json");
        list = curl_slist_append(
            list, "Authorization: Bearer I0.b2F1dGgyLmJkYy5zY2h3YWIuY29t.x0xizIGSHbdYxYLIajZlTFaGrcB1t2zScRu5ZqutHb4@");

        curl_easy_setopt(curl, CURLOPT_URL, finalUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_0);
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        std::cout << readBuffer << std::endl;
    }
}