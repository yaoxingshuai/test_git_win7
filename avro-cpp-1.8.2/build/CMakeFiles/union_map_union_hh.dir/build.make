# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anzhuangbao/avro-cpp-1.8.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anzhuangbao/avro-cpp-1.8.2/build

# Utility rule file for union_map_union_hh.

# Include the progress variables for this target.
include CMakeFiles/union_map_union_hh.dir/progress.make

CMakeFiles/union_map_union_hh: union_map_union.hh


union_map_union.hh: avrogencpp
union_map_union.hh: ../jsonschemas/union_map_union
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/anzhuangbao/avro-cpp-1.8.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating union_map_union.hh"
	./avrogencpp -p - -i /home/anzhuangbao/avro-cpp-1.8.2/jsonschemas/union_map_union -o union_map_union.hh -n umu -U

union_map_union_hh: CMakeFiles/union_map_union_hh
union_map_union_hh: union_map_union.hh
union_map_union_hh: CMakeFiles/union_map_union_hh.dir/build.make

.PHONY : union_map_union_hh

# Rule to build all files generated by this target.
CMakeFiles/union_map_union_hh.dir/build: union_map_union_hh

.PHONY : CMakeFiles/union_map_union_hh.dir/build

CMakeFiles/union_map_union_hh.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/union_map_union_hh.dir/cmake_clean.cmake
.PHONY : CMakeFiles/union_map_union_hh.dir/clean

CMakeFiles/union_map_union_hh.dir/depend:
	cd /home/anzhuangbao/avro-cpp-1.8.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anzhuangbao/avro-cpp-1.8.2 /home/anzhuangbao/avro-cpp-1.8.2 /home/anzhuangbao/avro-cpp-1.8.2/build /home/anzhuangbao/avro-cpp-1.8.2/build /home/anzhuangbao/avro-cpp-1.8.2/build/CMakeFiles/union_map_union_hh.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/union_map_union_hh.dir/depend

