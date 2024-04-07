#!/bin/bash

find . -type f ! -path "./googletest-1.14.0/*" ! -path "./output/*" ! -path "./uWebSockets-v0.14/*" -name *.h -o \
-type f ! -path "./googletest-1.14.0/*" ! -path "./output/*" ! -path "./uWebSockets-v0.14/*" -name *.cpp | xargs clang-format -i --verbose