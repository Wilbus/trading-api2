#include "TwsLiveMarketService.h"

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    std::shared_ptr<TwsLiveMarketService> service = std::make_shared<TwsLiveMarketService>();
    service->setupHandlers();
    service->setupStreams();
    while (true)
    {
    }
}