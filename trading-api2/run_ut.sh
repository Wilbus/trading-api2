#!/bin/bash
cwd=$(pwd)

cd ${cwd}/output/configs/ut && ctest --stop-on-failure --output-on-failure --progress
cd ${cwd}/output/exchanges/schwab/ut && ctest --stop-on-failure --output-on-failure --progress
cd ${cwd}/output/restclient/ut/ && ctest --stop-on-failure --output-on-failure --progress
cd ${cwd}/output/streaming/ut/ && ctest --stop-on-failure --output-on-failure --progress
cd ${cwd}/output/utils/ut/ && ctest --stop-on-failure --output-on-failure --progress
cd ${cwd}/output/connection_manager/ut/ && ctest --stop-on-failure --output-on-failure --progress