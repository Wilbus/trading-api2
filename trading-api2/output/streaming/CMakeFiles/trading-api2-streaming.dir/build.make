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
include streaming/CMakeFiles/trading-api2-streaming.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include streaming/CMakeFiles/trading-api2-streaming.dir/compiler_depend.make

# Include the progress variables for this target.
include streaming/CMakeFiles/trading-api2-streaming.dir/progress.make

# Include the compile flags for this target's objects.
include streaming/CMakeFiles/trading-api2-streaming.dir/flags.make

streaming/CMakeFiles/trading-api2-streaming.dir/src/TradierStreamHandler.cpp.o: streaming/CMakeFiles/trading-api2-streaming.dir/flags.make
streaming/CMakeFiles/trading-api2-streaming.dir/src/TradierStreamHandler.cpp.o: /datadisk0/sambashare0/coding/trading-api2/trading-api2/streaming/src/TradierStreamHandler.cpp
streaming/CMakeFiles/trading-api2-streaming.dir/src/TradierStreamHandler.cpp.o: streaming/CMakeFiles/trading-api2-streaming.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/datadisk0/sambashare0/coding/trading-api2/trading-api2/output/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object streaming/CMakeFiles/trading-api2-streaming.dir/src/TradierStreamHandler.cpp.o"
	cd /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/streaming && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT streaming/CMakeFiles/trading-api2-streaming.dir/src/TradierStreamHandler.cpp.o -MF CMakeFiles/trading-api2-streaming.dir/src/TradierStreamHandler.cpp.o.d -o CMakeFiles/trading-api2-streaming.dir/src/TradierStreamHandler.cpp.o -c /datadisk0/sambashare0/coding/trading-api2/trading-api2/streaming/src/TradierStreamHandler.cpp

streaming/CMakeFiles/trading-api2-streaming.dir/src/TradierStreamHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/trading-api2-streaming.dir/src/TradierStreamHandler.cpp.i"
	cd /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/streaming && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /datadisk0/sambashare0/coding/trading-api2/trading-api2/streaming/src/TradierStreamHandler.cpp > CMakeFiles/trading-api2-streaming.dir/src/TradierStreamHandler.cpp.i

streaming/CMakeFiles/trading-api2-streaming.dir/src/TradierStreamHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/trading-api2-streaming.dir/src/TradierStreamHandler.cpp.s"
	cd /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/streaming && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /datadisk0/sambashare0/coding/trading-api2/trading-api2/streaming/src/TradierStreamHandler.cpp -o CMakeFiles/trading-api2-streaming.dir/src/TradierStreamHandler.cpp.s

streaming/CMakeFiles/trading-api2-streaming.dir/src/AlpacaStreamHandler.cpp.o: streaming/CMakeFiles/trading-api2-streaming.dir/flags.make
streaming/CMakeFiles/trading-api2-streaming.dir/src/AlpacaStreamHandler.cpp.o: /datadisk0/sambashare0/coding/trading-api2/trading-api2/streaming/src/AlpacaStreamHandler.cpp
streaming/CMakeFiles/trading-api2-streaming.dir/src/AlpacaStreamHandler.cpp.o: streaming/CMakeFiles/trading-api2-streaming.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/datadisk0/sambashare0/coding/trading-api2/trading-api2/output/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object streaming/CMakeFiles/trading-api2-streaming.dir/src/AlpacaStreamHandler.cpp.o"
	cd /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/streaming && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT streaming/CMakeFiles/trading-api2-streaming.dir/src/AlpacaStreamHandler.cpp.o -MF CMakeFiles/trading-api2-streaming.dir/src/AlpacaStreamHandler.cpp.o.d -o CMakeFiles/trading-api2-streaming.dir/src/AlpacaStreamHandler.cpp.o -c /datadisk0/sambashare0/coding/trading-api2/trading-api2/streaming/src/AlpacaStreamHandler.cpp

streaming/CMakeFiles/trading-api2-streaming.dir/src/AlpacaStreamHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/trading-api2-streaming.dir/src/AlpacaStreamHandler.cpp.i"
	cd /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/streaming && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /datadisk0/sambashare0/coding/trading-api2/trading-api2/streaming/src/AlpacaStreamHandler.cpp > CMakeFiles/trading-api2-streaming.dir/src/AlpacaStreamHandler.cpp.i

streaming/CMakeFiles/trading-api2-streaming.dir/src/AlpacaStreamHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/trading-api2-streaming.dir/src/AlpacaStreamHandler.cpp.s"
	cd /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/streaming && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /datadisk0/sambashare0/coding/trading-api2/trading-api2/streaming/src/AlpacaStreamHandler.cpp -o CMakeFiles/trading-api2-streaming.dir/src/AlpacaStreamHandler.cpp.s

# Object files for target trading-api2-streaming
trading__api2__streaming_OBJECTS = \
"CMakeFiles/trading-api2-streaming.dir/src/TradierStreamHandler.cpp.o" \
"CMakeFiles/trading-api2-streaming.dir/src/AlpacaStreamHandler.cpp.o"

# External object files for target trading-api2-streaming
trading__api2__streaming_EXTERNAL_OBJECTS =

streaming/libtrading-api2-streaming.so: streaming/CMakeFiles/trading-api2-streaming.dir/src/TradierStreamHandler.cpp.o
streaming/libtrading-api2-streaming.so: streaming/CMakeFiles/trading-api2-streaming.dir/src/AlpacaStreamHandler.cpp.o
streaming/libtrading-api2-streaming.so: streaming/CMakeFiles/trading-api2-streaming.dir/build.make
streaming/libtrading-api2-streaming.so: utils/libtrading-api2-utils.so
streaming/libtrading-api2-streaming.so: /usr/lib/x86_64-linux-gnu/libssl.so
streaming/libtrading-api2-streaming.so: /usr/lib/x86_64-linux-gnu/libcrypto.so
streaming/libtrading-api2-streaming.so: /usr/local/lib/libz.so
streaming/libtrading-api2-streaming.so: /usr/local/lib/libInfluxDB.so.1.0.0
streaming/libtrading-api2-streaming.so: /usr/local/lib/libcpr.so.1.11.0
streaming/libtrading-api2-streaming.so: /usr/local/lib/libcurl.so.4.8.0
streaming/libtrading-api2-streaming.so: lib/libgmock.a
streaming/libtrading-api2-streaming.so: lib/libgtest.a
streaming/libtrading-api2-streaming.so: streaming/CMakeFiles/trading-api2-streaming.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/datadisk0/sambashare0/coding/trading-api2/trading-api2/output/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libtrading-api2-streaming.so"
	cd /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/streaming && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/trading-api2-streaming.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
streaming/CMakeFiles/trading-api2-streaming.dir/build: streaming/libtrading-api2-streaming.so
.PHONY : streaming/CMakeFiles/trading-api2-streaming.dir/build

streaming/CMakeFiles/trading-api2-streaming.dir/clean:
	cd /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/streaming && $(CMAKE_COMMAND) -P CMakeFiles/trading-api2-streaming.dir/cmake_clean.cmake
.PHONY : streaming/CMakeFiles/trading-api2-streaming.dir/clean

streaming/CMakeFiles/trading-api2-streaming.dir/depend:
	cd /datadisk0/sambashare0/coding/trading-api2/trading-api2/output && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /datadisk0/sambashare0/coding/trading-api2/trading-api2 /datadisk0/sambashare0/coding/trading-api2/trading-api2/streaming /datadisk0/sambashare0/coding/trading-api2/trading-api2/output /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/streaming /datadisk0/sambashare0/coding/trading-api2/trading-api2/output/streaming/CMakeFiles/trading-api2-streaming.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : streaming/CMakeFiles/trading-api2-streaming.dir/depend

