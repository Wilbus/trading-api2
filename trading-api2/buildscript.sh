#!/bin/bash

REBUILD=$1
BUILD_TESTS=$2

if [[ $REBUILD -gt 0 ]]
then
    rm -rf output/
    mkdir output/
    cmake -DBUILD_TESTS=$BUILD_TESTS -S . -B output/
    cmake --build output/ -j 6
else
    echo "normal build\n"
    cmake --build output/ -j 6
    rm -rf runfiles/
    mkdir runfiles/
fi
