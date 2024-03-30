# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/datadisk0/sambashare0/coding/trading-api2/trading-api2/output/_deps/googletest-src"
  "/datadisk0/sambashare0/coding/trading-api2/trading-api2/output/_deps/googletest-build"
  "/datadisk0/sambashare0/coding/trading-api2/trading-api2/output/_deps/googletest-subbuild/googletest-populate-prefix"
  "/datadisk0/sambashare0/coding/trading-api2/trading-api2/output/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/datadisk0/sambashare0/coding/trading-api2/trading-api2/output/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/datadisk0/sambashare0/coding/trading-api2/trading-api2/output/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/datadisk0/sambashare0/coding/trading-api2/trading-api2/output/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/datadisk0/sambashare0/coding/trading-api2/trading-api2/output/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/datadisk0/sambashare0/coding/trading-api2/trading-api2/output/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
