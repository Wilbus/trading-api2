#!/bin/bash

find . -type f ! -path "./googletest-1.14.0/*" ! -path "./output/*" -name *.h -o -name *.cpp | xargs clang-format -i --verbose


#find ./trading-api2 -iname *.h -o -iname *.cpp | xargs clang-format -i --verbose'''