# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/linux/AKprojects/MyTinySkipList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/linux/AKprojects/MyTinySkipList/build

# Include any dependencies generated for this target.
include CMakeFiles/TinySkipListLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TinySkipListLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TinySkipListLib.dir/flags.make

# Object files for target TinySkipListLib
TinySkipListLib_OBJECTS =

# External object files for target TinySkipListLib
TinySkipListLib_EXTERNAL_OBJECTS =

libTinySkipListLib.a: CMakeFiles/TinySkipListLib.dir/build.make
libTinySkipListLib.a: CMakeFiles/TinySkipListLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linux/AKprojects/MyTinySkipList/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library libTinySkipListLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/TinySkipListLib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TinySkipListLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TinySkipListLib.dir/build: libTinySkipListLib.a

.PHONY : CMakeFiles/TinySkipListLib.dir/build

CMakeFiles/TinySkipListLib.dir/requires:

.PHONY : CMakeFiles/TinySkipListLib.dir/requires

CMakeFiles/TinySkipListLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TinySkipListLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TinySkipListLib.dir/clean

CMakeFiles/TinySkipListLib.dir/depend:
	cd /home/linux/AKprojects/MyTinySkipList/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linux/AKprojects/MyTinySkipList /home/linux/AKprojects/MyTinySkipList /home/linux/AKprojects/MyTinySkipList/build /home/linux/AKprojects/MyTinySkipList/build /home/linux/AKprojects/MyTinySkipList/build/CMakeFiles/TinySkipListLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TinySkipListLib.dir/depend

