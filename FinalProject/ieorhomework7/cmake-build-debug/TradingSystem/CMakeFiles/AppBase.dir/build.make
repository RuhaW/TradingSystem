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
include TradingSystem/CMakeFiles/AppBase.dir/depend.make

# Include the progress variables for this target.
include TradingSystem/CMakeFiles/AppBase.dir/progress.make

# Include the compile flags for this target's objects.
include TradingSystem/CMakeFiles/AppBase.dir/flags.make

TradingSystem/CMakeFiles/AppBase.dir/AppBase.cpp.o: TradingSystem/CMakeFiles/AppBase.dir/flags.make
TradingSystem/CMakeFiles/AppBase.dir/AppBase.cpp.o: ../TradingSystem/AppBase.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TradingSystem/CMakeFiles/AppBase.dir/AppBase.cpp.o"
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppBase.dir/AppBase.cpp.o -c /Users/ruohanwu/Desktop/ieorhomework7/TradingSystem/AppBase.cpp

TradingSystem/CMakeFiles/AppBase.dir/AppBase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppBase.dir/AppBase.cpp.i"
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ruohanwu/Desktop/ieorhomework7/TradingSystem/AppBase.cpp > CMakeFiles/AppBase.dir/AppBase.cpp.i

TradingSystem/CMakeFiles/AppBase.dir/AppBase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppBase.dir/AppBase.cpp.s"
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ruohanwu/Desktop/ieorhomework7/TradingSystem/AppBase.cpp -o CMakeFiles/AppBase.dir/AppBase.cpp.s

# Object files for target AppBase
AppBase_OBJECTS = \
"CMakeFiles/AppBase.dir/AppBase.cpp.o"

# External object files for target AppBase
AppBase_EXTERNAL_OBJECTS =

TradingSystem/libAppBase.a: TradingSystem/CMakeFiles/AppBase.dir/AppBase.cpp.o
TradingSystem/libAppBase.a: TradingSystem/CMakeFiles/AppBase.dir/build.make
TradingSystem/libAppBase.a: TradingSystem/CMakeFiles/AppBase.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libAppBase.a"
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem && $(CMAKE_COMMAND) -P CMakeFiles/AppBase.dir/cmake_clean_target.cmake
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AppBase.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TradingSystem/CMakeFiles/AppBase.dir/build: TradingSystem/libAppBase.a

.PHONY : TradingSystem/CMakeFiles/AppBase.dir/build

TradingSystem/CMakeFiles/AppBase.dir/clean:
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem && $(CMAKE_COMMAND) -P CMakeFiles/AppBase.dir/cmake_clean.cmake
.PHONY : TradingSystem/CMakeFiles/AppBase.dir/clean

TradingSystem/CMakeFiles/AppBase.dir/depend:
	cd /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ruohanwu/Desktop/ieorhomework7 /Users/ruohanwu/Desktop/ieorhomework7/TradingSystem /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem /Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/TradingSystem/CMakeFiles/AppBase.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TradingSystem/CMakeFiles/AppBase.dir/depend
