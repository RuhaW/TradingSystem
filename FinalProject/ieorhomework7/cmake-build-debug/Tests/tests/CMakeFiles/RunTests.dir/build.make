# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ruohanwu/Desktop/ieorhomework7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug

# Include any dependencies generated for this target.
include Tests/tests/CMakeFiles/RunTests.dir/depend.make

# Include the progress variables for this target.
include Tests/tests/CMakeFiles/RunTests.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/tests/CMakeFiles/RunTests.dir/flags.make

Tests/tests/CMakeFiles/RunTests.dir/SomeTests.cpp.o: Tests/tests/CMakeFiles/RunTests.dir/flags.make
Tests/tests/CMakeFiles/RunTests.dir/SomeTests.cpp.o: ../Tests/tests/SomeTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Tests/tests/CMakeFiles/RunTests.dir/SomeTests.cpp.o"
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/Tests/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RunTests.dir/SomeTests.cpp.o -c /Users/ruohanwu/Desktop/ieorhomework7/Tests/tests/SomeTests.cpp

Tests/tests/CMakeFiles/RunTests.dir/SomeTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RunTests.dir/SomeTests.cpp.i"
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/Tests/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ruohanwu/Desktop/ieorhomework7/Tests/tests/SomeTests.cpp > CMakeFiles/RunTests.dir/SomeTests.cpp.i

Tests/tests/CMakeFiles/RunTests.dir/SomeTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RunTests.dir/SomeTests.cpp.s"
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/Tests/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ruohanwu/Desktop/ieorhomework7/Tests/tests/SomeTests.cpp -o CMakeFiles/RunTests.dir/SomeTests.cpp.s

# Object files for target RunTests
RunTests_OBJECTS = \
"CMakeFiles/RunTests.dir/SomeTests.cpp.o"

# External object files for target RunTests
RunTests_EXTERNAL_OBJECTS =

Tests/tests/RunTests: Tests/tests/CMakeFiles/RunTests.dir/SomeTests.cpp.o
Tests/tests/RunTests: Tests/tests/CMakeFiles/RunTests.dir/build.make
Tests/tests/RunTests: lib/libgtestd.a
Tests/tests/RunTests: lib/libgtest_maind.a
Tests/tests/RunTests: TradingSystem/libAppBase.a
Tests/tests/RunTests: TradingSystem/libBookBuilder.a
Tests/tests/RunTests: TradingSystem/libBookUpdate.a
Tests/tests/RunTests: TradingSystem/libMarketSimulator.a
Tests/tests/RunTests: TradingSystem/libMDReader.a
Tests/tests/RunTests: TradingSystem/libOrder.a
Tests/tests/RunTests: TradingSystem/libOrderManager.a
Tests/tests/RunTests: TradingSystem/libTradingStrategy.a
Tests/tests/RunTests: /usr/local/lib/libboost_date_time-mt.dylib
Tests/tests/RunTests: /usr/local/lib/libboost_program_options-mt.dylib
Tests/tests/RunTests: /usr/local/lib/libboost_thread-mt.dylib
Tests/tests/RunTests: /usr/local/lib/libboost_filesystem-mt.dylib
Tests/tests/RunTests: /usr/local/lib/libboost_system-mt.dylib
Tests/tests/RunTests: /usr/local/lib/libboost_unit_test_framework-mt.dylib
Tests/tests/RunTests: /usr/local/lib/libboost_chrono-mt.dylib
Tests/tests/RunTests: /usr/local/lib/libboost_atomic-mt.dylib
Tests/tests/RunTests: lib/libgtestd.a
Tests/tests/RunTests: Tests/tests/CMakeFiles/RunTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RunTests"
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/Tests/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RunTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tests/tests/CMakeFiles/RunTests.dir/build: Tests/tests/RunTests

.PHONY : Tests/tests/CMakeFiles/RunTests.dir/build

Tests/tests/CMakeFiles/RunTests.dir/clean:
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/Tests/tests && $(CMAKE_COMMAND) -P CMakeFiles/RunTests.dir/cmake_clean.cmake
.PHONY : Tests/tests/CMakeFiles/RunTests.dir/clean

Tests/tests/CMakeFiles/RunTests.dir/depend:
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ruohanwu/Desktop/ieorhomework7 /Users/ruohanwu/Desktop/ieorhomework7/Tests/tests /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/Tests/tests /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/Tests/tests/CMakeFiles/RunTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tests/tests/CMakeFiles/RunTests.dir/depend

