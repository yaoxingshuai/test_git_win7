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

# Include any dependencies generated for this target.
include CMakeFiles/LargeSchemaTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LargeSchemaTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LargeSchemaTests.dir/flags.make

CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.o: CMakeFiles/LargeSchemaTests.dir/flags.make
CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.o: ../test/LargeSchemaTests.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anzhuangbao/avro-cpp-1.8.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.o -c /home/anzhuangbao/avro-cpp-1.8.2/test/LargeSchemaTests.cc

CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anzhuangbao/avro-cpp-1.8.2/test/LargeSchemaTests.cc > CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.i

CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anzhuangbao/avro-cpp-1.8.2/test/LargeSchemaTests.cc -o CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.s

CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.o.requires:

.PHONY : CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.o.requires

CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.o.provides: CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.o.requires
	$(MAKE) -f CMakeFiles/LargeSchemaTests.dir/build.make CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.o.provides.build
.PHONY : CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.o.provides

CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.o.provides.build: CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.o


# Object files for target LargeSchemaTests
LargeSchemaTests_OBJECTS = \
"CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.o"

# External object files for target LargeSchemaTests
LargeSchemaTests_EXTERNAL_OBJECTS =

LargeSchemaTests: CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.o
LargeSchemaTests: CMakeFiles/LargeSchemaTests.dir/build.make
LargeSchemaTests: libavrocpp.so.1.8.2.0
LargeSchemaTests: /usr/lib64/libboost_filesystem-mt.so
LargeSchemaTests: /usr/lib64/libboost_system-mt.so
LargeSchemaTests: /usr/lib64/libboost_program_options-mt.so
LargeSchemaTests: /usr/lib64/libboost_iostreams-mt.so
LargeSchemaTests: /usr/lib64/libboost_regex-mt.so
LargeSchemaTests: CMakeFiles/LargeSchemaTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anzhuangbao/avro-cpp-1.8.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LargeSchemaTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LargeSchemaTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LargeSchemaTests.dir/build: LargeSchemaTests

.PHONY : CMakeFiles/LargeSchemaTests.dir/build

CMakeFiles/LargeSchemaTests.dir/requires: CMakeFiles/LargeSchemaTests.dir/test/LargeSchemaTests.cc.o.requires

.PHONY : CMakeFiles/LargeSchemaTests.dir/requires

CMakeFiles/LargeSchemaTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LargeSchemaTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LargeSchemaTests.dir/clean

CMakeFiles/LargeSchemaTests.dir/depend:
	cd /home/anzhuangbao/avro-cpp-1.8.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anzhuangbao/avro-cpp-1.8.2 /home/anzhuangbao/avro-cpp-1.8.2 /home/anzhuangbao/avro-cpp-1.8.2/build /home/anzhuangbao/avro-cpp-1.8.2/build /home/anzhuangbao/avro-cpp-1.8.2/build/CMakeFiles/LargeSchemaTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LargeSchemaTests.dir/depend

