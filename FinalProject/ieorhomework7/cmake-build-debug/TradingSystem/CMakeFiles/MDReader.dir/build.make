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
include TradingSystem/CMakeFiles/MDReader.dir/depend.make

# Include the progress variables for this target.
include TradingSystem/CMakeFiles/MDReader.dir/progress.make

# Include the compile flags for this target's objects.
include TradingSystem/CMakeFiles/MDReader.dir/flags.make

TradingSystem/CMakeFiles/MDReader.dir/MDReader.cpp.o: TradingSystem/CMakeFiles/MDReader.dir/flags.make
TradingSystem/CMakeFiles/MDReader.dir/MDReader.cpp.o: ../TradingSystem/MDReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TradingSystem/CMakeFiles/MDReader.dir/MDReader.cpp.o"
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MDReader.dir/MDReader.cpp.o -c /Users/ruohanwu/Desktop/ieorhomework7/TradingSystem/MDReader.cpp

TradingSystem/CMakeFiles/MDReader.dir/MDReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MDReader.dir/MDReader.cpp.i"
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ruohanwu/Desktop/ieorhomework7/TradingSystem/MDReader.cpp > CMakeFiles/MDReader.dir/MDReader.cpp.i

TradingSystem/CMakeFiles/MDReader.dir/MDReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MDReader.dir/MDReader.cpp.s"
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ruohanwu/Desktop/ieorhomework7/TradingSystem/MDReader.cpp -o CMakeFiles/MDReader.dir/MDReader.cpp.s

# Object files for target MDReader
MDReader_OBJECTS = \
"CMakeFiles/MDReader.dir/MDReader.cpp.o"

# External object files for target MDReader
MDReader_EXTERNAL_OBJECTS =

TradingSystem/libMDReader.a: TradingSystem/CMakeFiles/MDReader.dir/MDReader.cpp.o
TradingSystem/libMDReader.a: TradingSystem/CMakeFiles/MDReader.dir/build.make
TradingSystem/libMDReader.a: TradingSystem/CMakeFiles/MDReader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMDReader.a"
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem && $(CMAKE_COMMAND) -P CMakeFiles/MDReader.dir/cmake_clean_target.cmake
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MDReader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TradingSystem/CMakeFiles/MDReader.dir/build: TradingSystem/libMDReader.a

.PHONY : TradingSystem/CMakeFiles/MDReader.dir/build

TradingSystem/CMakeFiles/MDReader.dir/clean:
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem && $(CMAKE_COMMAND) -P CMakeFiles/MDReader.dir/cmake_clean.cmake
.PHONY : TradingSystem/CMakeFiles/MDReader.dir/clean

TradingSystem/CMakeFiles/MDReader.dir/depend:
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ruohanwu/Desktop/ieorhomework7 /Users/ruohanwu/Desktop/ieorhomework7/TradingSystem /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem/CMakeFiles/MDReader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TradingSystem/CMakeFiles/MDReader.dir/depend
