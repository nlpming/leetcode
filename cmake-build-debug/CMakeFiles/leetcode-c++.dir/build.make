# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /Users/chenzhiming/Documents/OneDrive/leetcode/leetcode-c++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chenzhiming/Documents/OneDrive/leetcode/leetcode-c++/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/leetcode-c++.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/leetcode-c++.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/leetcode-c++.dir/flags.make

CMakeFiles/leetcode-c++.dir/array_problem/704_binary_search.cpp.o: CMakeFiles/leetcode-c++.dir/flags.make
CMakeFiles/leetcode-c++.dir/array_problem/704_binary_search.cpp.o: ../array_problem/704_binary_search.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chenzhiming/Documents/OneDrive/leetcode/leetcode-c++/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/leetcode-c++.dir/array_problem/704_binary_search.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/leetcode-c++.dir/array_problem/704_binary_search.cpp.o -c /Users/chenzhiming/Documents/OneDrive/leetcode/leetcode-c++/array_problem/704_binary_search.cpp

CMakeFiles/leetcode-c++.dir/array_problem/704_binary_search.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/leetcode-c++.dir/array_problem/704_binary_search.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chenzhiming/Documents/OneDrive/leetcode/leetcode-c++/array_problem/704_binary_search.cpp > CMakeFiles/leetcode-c++.dir/array_problem/704_binary_search.cpp.i

CMakeFiles/leetcode-c++.dir/array_problem/704_binary_search.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/leetcode-c++.dir/array_problem/704_binary_search.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chenzhiming/Documents/OneDrive/leetcode/leetcode-c++/array_problem/704_binary_search.cpp -o CMakeFiles/leetcode-c++.dir/array_problem/704_binary_search.cpp.s

# Object files for target leetcode-c++
leetcode__c_______OBJECTS = \
"CMakeFiles/leetcode-c++.dir/array_problem/704_binary_search.cpp.o"

# External object files for target leetcode-c++
leetcode__c_______EXTERNAL_OBJECTS =

leetcode-c++: CMakeFiles/leetcode-c++.dir/array_problem/704_binary_search.cpp.o
leetcode-c++: CMakeFiles/leetcode-c++.dir/build.make
leetcode-c++: CMakeFiles/leetcode-c++.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chenzhiming/Documents/OneDrive/leetcode/leetcode-c++/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable leetcode-c++"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/leetcode-c++.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/leetcode-c++.dir/build: leetcode-c++

.PHONY : CMakeFiles/leetcode-c++.dir/build

CMakeFiles/leetcode-c++.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/leetcode-c++.dir/cmake_clean.cmake
.PHONY : CMakeFiles/leetcode-c++.dir/clean

CMakeFiles/leetcode-c++.dir/depend:
	cd /Users/chenzhiming/Documents/OneDrive/leetcode/leetcode-c++/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chenzhiming/Documents/OneDrive/leetcode/leetcode-c++ /Users/chenzhiming/Documents/OneDrive/leetcode/leetcode-c++ /Users/chenzhiming/Documents/OneDrive/leetcode/leetcode-c++/cmake-build-debug /Users/chenzhiming/Documents/OneDrive/leetcode/leetcode-c++/cmake-build-debug /Users/chenzhiming/Documents/OneDrive/leetcode/leetcode-c++/cmake-build-debug/CMakeFiles/leetcode-c++.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/leetcode-c++.dir/depend

