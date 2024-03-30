#!/bin/bash

REBUILD=$1

if [[ $REBUILD -gt 0 ]]
then
    #./clangformatter.sh

    flatc --cpp --strict-json --scoped-enums --gen-name-strings --gen-object-api --gen-compare --cpp-std c++17 --gen-mutable --force-empty -o utils/flatbuffers utils/flatbuffers/*.fbs

    #flatc --binary --strict-json -o schemas schemas/cbauths.fbs ../cbauths.json
    #flatc --binary --strict-json -o schemas schemas/cbauths.fbs ../cbadvauths.json
    #flatc --binary --strict-json -o schemas schemas/auxpaths.fbs ../auxpaths.json
    #flatc --binary --strict-json -o schemas schemas/auxpaths.fbs ../cbadv_auxpaths.json
    #flatc --binary --strict-json -o schemas schemas/indicators.fbs ../indicators.json
    #flatc --binary --strict-json -o schemas schemas/masterconfig.fbs ../masterconfig.json
    #flatc --binary --strict-json -o schemas schemas/masterconfig.fbs ../masterconfig-pro.json
    rm -rf output/
    mkdir output/
    cmake -S . -B output/
    cmake --build output/ -j 6

    #cp -rf ./output ../trading-api-executables
else
    echo "normal build\n"
    cmake --build output/ -j 6
    rm -rf runfiles/
    mkdir runfiles/
    #cp -rf output/trading-api/executables runfiles/
    #cp -rf output/trading-api/unit_tests runfiles/
fi
