# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "D:\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/List.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/List.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/List.dir/flags.make

CMakeFiles/List.dir/main.cpp.obj: CMakeFiles/List.dir/flags.make
CMakeFiles/List.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/List.dir/main.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\List.dir\main.cpp.obj -c "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\main.cpp"

CMakeFiles/List.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/List.dir/main.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\main.cpp" > CMakeFiles\List.dir\main.cpp.i

CMakeFiles/List.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/List.dir/main.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\main.cpp" -o CMakeFiles\List.dir\main.cpp.s

CMakeFiles/List.dir/ListNode.cpp.obj: CMakeFiles/List.dir/flags.make
CMakeFiles/List.dir/ListNode.cpp.obj: ../ListNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/List.dir/ListNode.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\List.dir\ListNode.cpp.obj -c "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\ListNode.cpp"

CMakeFiles/List.dir/ListNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/List.dir/ListNode.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\ListNode.cpp" > CMakeFiles\List.dir\ListNode.cpp.i

CMakeFiles/List.dir/ListNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/List.dir/ListNode.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\ListNode.cpp" -o CMakeFiles\List.dir\ListNode.cpp.s

CMakeFiles/List.dir/List.cpp.obj: CMakeFiles/List.dir/flags.make
CMakeFiles/List.dir/List.cpp.obj: ../List.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/List.dir/List.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\List.dir\List.cpp.obj -c "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\List.cpp"

CMakeFiles/List.dir/List.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/List.dir/List.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\List.cpp" > CMakeFiles\List.dir\List.cpp.i

CMakeFiles/List.dir/List.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/List.dir/List.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\List.cpp" -o CMakeFiles\List.dir\List.cpp.s

# Object files for target List
List_OBJECTS = \
"CMakeFiles/List.dir/main.cpp.obj" \
"CMakeFiles/List.dir/ListNode.cpp.obj" \
"CMakeFiles/List.dir/List.cpp.obj"

# External object files for target List
List_EXTERNAL_OBJECTS =

List.exe: CMakeFiles/List.dir/main.cpp.obj
List.exe: CMakeFiles/List.dir/ListNode.cpp.obj
List.exe: CMakeFiles/List.dir/List.cpp.obj
List.exe: CMakeFiles/List.dir/build.make
List.exe: CMakeFiles/List.dir/linklibs.rsp
List.exe: CMakeFiles/List.dir/objects1.rsp
List.exe: CMakeFiles/List.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable List.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\List.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/List.dir/build: List.exe

.PHONY : CMakeFiles/List.dir/build

CMakeFiles/List.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\List.dir\cmake_clean.cmake
.PHONY : CMakeFiles/List.dir/clean

CMakeFiles/List.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List" "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List" "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\cmake-build-debug" "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\cmake-build-debug" "E:\programe\GitHub project warehouse manager\c-cpp-algorithm\STL\List\cmake-build-debug\CMakeFiles\List.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/List.dir/depend

