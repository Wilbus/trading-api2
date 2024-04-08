#!/bin/bash
MEMCHECK=$1

cwd=$(pwd)


if [[ $MEMCHECK -gt 0 ]]
then
    cd ${cwd}/output/configs/ut && valgrind ctest --stop-on-failure --output-on-failure --progress
    cd ${cwd}/output/exchanges/schwab/ut && valgrind ctest --stop-on-failure --output-on-failure --progress
    cd ${cwd}/output/restclient/ut/ && valgrind ctest --stop-on-failure --output-on-failure --progress
    cd ${cwd}/output/streaming/ut/ && valgrind ctest --stop-on-failure --output-on-failure --progress
    cd ${cwd}/output/utils/ut/ && valgrind ctest --stop-on-failure --output-on-failure --progress
    cd ${cwd}/output/connection_manager/ut/ && valgrind ctest --stop-on-failure --output-on-failure --progress
else
    cd ${cwd}/output/configs/ut && ctest --stop-on-failure --output-on-failure --progress
    cd ${cwd}/output/exchanges/schwab/ut && ctest --stop-on-failure --output-on-failure --progress
    cd ${cwd}/output/restclient/ut/ && ctest --stop-on-failure --output-on-failure --progress
    cd ${cwd}/output/streaming/ut/ && ctest --stop-on-failure --output-on-failure --progress
    cd ${cwd}/output/utils/ut/ && ctest --stop-on-failure --output-on-failure --progress
    cd ${cwd}/output/connection_manager/ut/ && ctest --stop-on-failure --output-on-failure --progress
fi