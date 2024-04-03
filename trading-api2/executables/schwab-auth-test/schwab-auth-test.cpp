#include "RestClientCurl.h"
#include "SchwabClient.h"

#include <iostream>

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    std::shared_ptr<RestClientCurl> restClient = std::make_shared<RestClientCurl>();
    std::shared_ptr<SchwabConfigs> configs = std::make_shared<SchwabConfigs>("/datadisk0/sambashare0/coding/configs/");
    std::shared_ptr<SchwabClient> sclient = std::make_shared<SchwabClient>(configs, restClient);
    auto quotes = sclient->getEquityQuotes(std::set<std::string>{"SPY"});
    std::cout << quotes.at("SPY").quote.yearHigh << "\n";

    // quotes = sclient->getEquityQuotes(std::set<std::string>{"AAPL"});
    sclient->createAccessToken("refreshtoken123", true);
}