# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /datadisk0/sambashare0/coding/trading-api2/trading-api2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /datadisk0/sambashare0/coding/trading-api2/trading-api2/output

# Include any dependencies generated for this target.
include tests/CMakeFiles/trading-api2-tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/trading-api2-tests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/trading-api2-tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/trading-api2-tests.dir/flags.make

tests/CMakeFiles/trading-api2-tests.dir/main.cpp.o: tests/CMakeFiles/trading-api2-tests.dir/flags.make
tests/CMakeFiles/trading-api2-tests.dir/main.cpp.o: /datadisk0/sambashare0/coding/trading-api2/trading-api2/tests/main.cpp
tests/CMakeFiles/trading-api2-tests.dir/main.cpp.o: tests/CMakeFiles/trading-api2-tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/datadisk0/sambashare0/coding/trading-api2/trading-api2/output/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/trading-api2-tests.dir/main.cpp.o"
	cd /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/trading-api2-tests.dir/main.cpp.o -MF CMakeFiles/trading-api2-tests.dir/main.cpp.o.d -o CMakeFiles/trading-api2-tests.dir/main.cpp.o -c /datadisk0/sambashare0/coding/trading-api2/trading-api2/tests/main.cpp

tests/CMakeFiles/trading-api2-tests.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/trading-api2-tests.dir/main.cpp.i"
	cd /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /datadisk0/sambashare0/coding/trading-api2/trading-api2/tests/main.cpp > CMakeFiles/trading-api2-tests.dir/main.cpp.i

tests/CMakeFiles/trading-api2-tests.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/trading-api2-tests.dir/main.cpp.s"
	cd /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /datadisk0/sambashare0/coding/trading-api2/trading-api2/tests/main.cpp -o CMakeFiles/trading-api2-tests.dir/main.cpp.s

# Object files for target trading-api2-tests
trading__api2__tests_OBJECTS = \
"CMakeFiles/trading-api2-tests.dir/main.cpp.o"

# External object files for target trading-api2-tests
trading__api2__tests_EXTERNAL_OBJECTS =

tests/trading-api2-tests: tests/CMakeFiles/trading-api2-tests.dir/main.cpp.o
tests/trading-api2-tests: tests/CMakeFiles/trading-api2-tests.dir/build.make
tests/trading-api2-tests: exchanges/libtrading-api2-exchange.so
tests/trading-api2-tests: restclient/libtrading-api2-restclient.so
tests/trading-api2-tests: streaming/libtrading-api2-streaming.so
tests/trading-api2-tests: mytwsapi-service/libtrading-api2-service.so
tests/trading-api2-tests: lib/libgtest_main.a
tests/trading-api2-tests: charting/libtrading-api2-charting.so
tests/trading-api2-tests: mytwsapi-imp/libtrading-api2-mytwasapi-imp.so
tests/trading-api2-tests: utils/libtrading-api2-utils.so
tests/trading-api2-tests: /usr/lib/x86_64-linux-gnu/libssl.so
tests/trading-api2-tests: /usr/lib/x86_64-linux-gnu/libcrypto.so
tests/trading-api2-tests: /usr/local/lib/libz.so
tests/trading-api2-tests: /usr/local/lib/libInfluxDB.so.1.0.0
tests/trading-api2-tests: /usr/local/lib/libcpr.so.1.11.0
tests/trading-api2-tests: /usr/local/lib/libcurl.so.4.8.0
tests/trading-api2-tests: lib/libgmock.a
tests/trading-api2-tests: mytwsapi/client/libmytwsapi.so
tests/trading-api2-tests: /usr/lib/x86_64-linux-gnu/libbidgcc000.a
tests/trading-api2-tests: lib/libgtest.a
tests/trading-api2-tests: tests/CMakeFiles/trading-api2-tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/datadisk0/sambashare0/coding/trading-api2/trading-api2/output/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable trading-api2-tests"
	cd /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/trading-api2-tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/trading-api2-tests.dir/build: tests/trading-api2-tests
.PHONY : tests/CMakeFiles/trading-api2-tests.dir/build

tests/CMakeFiles/trading-api2-tests.dir/clean:
	cd /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/tests && $(CMAKE_COMMAND) -P CMakeFiles/trading-api2-tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/trading-api2-tests.dir/clean

tests/CMakeFiles/trading-api2-tests.dir/depend:
	cd /datadisk0/sambashare0/coding/trading-api2/trading-api2/output && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /datadisk0/sambashare0/coding/trading-api2/trading-api2 /datadisk0/sambashare0/coding/trading-api2/trading-api2/tests /datadisk0/sambashare0/coding/trading-api2/trading-api2/output /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/tests /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/tests/CMakeFiles/trading-api2-tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/trading-api2-tests.dir/depend

