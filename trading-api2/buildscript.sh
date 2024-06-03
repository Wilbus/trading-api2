#!/bin/bash

REBUILD=$1
COPYFILESTO=$2

if [[ $REBUILD -gt 0 ]]
then
    rm -rf output/
    mkdir output/
    cmake -S . -B output/
    cmake --build output/ -j 16
    cp -rf output/* $COPYFILESTO
else
    echo "normal build\n"
    cmake --build output/ -j 16
fi