# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "H:\programe\GitHub-project-warehouse-manager\c-cpp-algorithm\Inquire\Binary search for the right edge"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "H:\programe\GitHub-project-warehouse-manager\c-cpp-algorithm\Inquire\Binary search for the right edge\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Binary_search_for_the_right_edge.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Binary_search_for_the_right_edge.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Binary_search_for_the_right_edge.dir/flags.make

CMakeFiles/Binary_search_for_the_right_edge.dir/main.cpp.obj: CMakeFiles/Binary_search_for_the_right_edge.dir/flags.make
CMakeFiles/Binary_search_for_the_right_edge.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\programe\GitHub-project-warehouse-manager\c-cpp-algorithm\Inquire\Binary search for the right edge\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Binary_search_for_the_right_edge.dir/main.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Binary_search_for_the_right_edge.dir\main.cpp.obj -c "H:\programe\GitHub-project-warehouse-manager\c-cpp-algorithm\Inquire\Binary search for the right edge\main.cpp"

CMakeFiles/Binary_search_for_the_right_edge.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Binary_search_for_the_right_edge.dir/main.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\programe\GitHub-project-warehouse-manager\c-cpp-algorithm\Inquire\Binary search for the right edge\main.cpp" > CMakeFiles\Binary_search_for_the_right_edge.dir\main.cpp.i

CMakeFiles/Binary_search_for_the_right_edge.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Binary_search_for_the_right_edge.dir/main.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\programe\GitHub-project-warehouse-manager\c-cpp-algorithm\Inquire\Binary search for the right edge\main.cpp" -o CMakeFiles\Binary_search_for_the_right_edge.dir\main.cpp.s

# Object files for target Binary_search_for_the_right_edge
Binary_search_for_the_right_edge_OBJECTS = \
"CMakeFiles/Binary_search_for_the_right_edge.dir/main.cpp.obj"

# External object files for target Binary_search_for_the_right_edge
Binary_search_for_the_right_edge_EXTERNAL_OBJECTS =

Binary_search_for_the_right_edge.exe: CMakeFiles/Binary_search_for_the_right_edge.dir/main.cpp.obj
Binary_search_for_the_right_edge.exe: CMakeFiles/Binary_search_for_the_right_edge.dir/build.make
Binary_search_for_the_right_edge.exe: CMakeFiles/Binary_search_for_the_right_edge.dir/linklibs.rsp
Binary_search_for_the_right_edge.exe: CMakeFiles/Binary_search_for_the_right_edge.dir/objects1.rsp
Binary_search_for_the_right_edge.exe: CMakeFiles/Binary_search_for_the_right_edge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="H:\programe\GitHub-project-warehouse-manager\c-cpp-algorithm\Inquire\Binary search for the right edge\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Binary_search_for_the_right_edge.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Binary_search_for_the_right_edge.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Binary_search_for_the_right_edge.dir/build: Binary_search_for_the_right_edge.exe
.PHONY : CMakeFiles/Binary_search_for_the_right_edge.dir/build

CMakeFiles/Binary_search_for_the_right_edge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Binary_search_for_the_right_edge.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Binary_search_for_the_right_edge.dir/clean

CMakeFiles/Binary_search_for_the_right_edge.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "H:\programe\GitHub-project-warehouse-manager\c-cpp-algorithm\Inquire\Binary search for the right edge" "H:\programe\GitHub-project-warehouse-manager\c-cpp-algorithm\Inquire\Binary search for the right edge" "H:\programe\GitHub-project-warehouse-manager\c-cpp-algorithm\Inquire\Binary search for the right edge\cmake-build-debug" "H:\programe\GitHub-project-warehouse-manager\c-cpp-algorithm\Inquire\Binary search for the right edge\cmake-build-debug" "H:\programe\GitHub-project-warehouse-manager\c-cpp-algorithm\Inquire\Binary search for the right edge\cmake-build-debug\CMakeFiles\Binary_search_for_the_right_edge.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Binary_search_for_the_right_edge.dir/depend

