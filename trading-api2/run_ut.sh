#!/bin/bash
cd "$(dirname "$0")"

cd output/configs/ut && ctest

cd output/exchanges/schwab/ut && ctest
#./output/restclient/ut/trading-api2-restclient-ut
#./output/streaming/ut/trading-api2-streaming-ut
#./output/utils/ut/trading-api2-utils-ut