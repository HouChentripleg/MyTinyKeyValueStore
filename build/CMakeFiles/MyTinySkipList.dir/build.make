# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/tripleg/myCodes/MyTinyKeyValueStore

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tripleg/myCodes/MyTinyKeyValueStore/build

# Include any dependencies generated for this target.
include CMakeFiles/MyTinySkipList.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MyTinySkipList.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MyTinySkipList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyTinySkipList.dir/flags.make

CMakeFiles/MyTinySkipList.dir/main.cpp.o: CMakeFiles/MyTinySkipList.dir/flags.make
CMakeFiles/MyTinySkipList.dir/main.cpp.o: ../main.cpp
CMakeFiles/MyTinySkipList.dir/main.cpp.o: CMakeFiles/MyTinySkipList.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tripleg/myCodes/MyTinyKeyValueStore/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyTinySkipList.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyTinySkipList.dir/main.cpp.o -MF CMakeFiles/MyTinySkipList.dir/main.cpp.o.d -o CMakeFiles/MyTinySkipList.dir/main.cpp.o -c /home/tripleg/myCodes/MyTinyKeyValueStore/main.cpp

CMakeFiles/MyTinySkipList.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyTinySkipList.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tripleg/myCodes/MyTinyKeyValueStore/main.cpp > CMakeFiles/MyTinySkipList.dir/main.cpp.i

CMakeFiles/MyTinySkipList.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyTinySkipList.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tripleg/myCodes/MyTinyKeyValueStore/main.cpp -o CMakeFiles/MyTinySkipList.dir/main.cpp.s

# Object files for target MyTinySkipList
MyTinySkipList_OBJECTS = \
"CMakeFiles/MyTinySkipList.dir/main.cpp.o"

# External object files for target MyTinySkipList
MyTinySkipList_EXTERNAL_OBJECTS =

MyTinySkipList: CMakeFiles/MyTinySkipList.dir/main.cpp.o
MyTinySkipList: CMakeFiles/MyTinySkipList.dir/build.make
MyTinySkipList: libTinySkipListLib.a
MyTinySkipList: CMakeFiles/MyTinySkipList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tripleg/myCodes/MyTinyKeyValueStore/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MyTinySkipList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyTinySkipList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyTinySkipList.dir/build: MyTinySkipList
.PHONY : CMakeFiles/MyTinySkipList.dir/build

CMakeFiles/MyTinySkipList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyTinySkipList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyTinySkipList.dir/clean

CMakeFiles/MyTinySkipList.dir/depend:
	cd /home/tripleg/myCodes/MyTinyKeyValueStore/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tripleg/myCodes/MyTinyKeyValueStore /home/tripleg/myCodes/MyTinyKeyValueStore /home/tripleg/myCodes/MyTinyKeyValueStore/build /home/tripleg/myCodes/MyTinyKeyValueStore/build /home/tripleg/myCodes/MyTinyKeyValueStore/build/CMakeFiles/MyTinySkipList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyTinySkipList.dir/depend

