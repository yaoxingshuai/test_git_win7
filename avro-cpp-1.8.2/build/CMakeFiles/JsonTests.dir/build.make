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
include CMakeFiles/JsonTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/JsonTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/JsonTests.dir/flags.make

CMakeFiles/JsonTests.dir/test/JsonTests.cc.o: CMakeFiles/JsonTests.dir/flags.make
CMakeFiles/JsonTests.dir/test/JsonTests.cc.o: ../test/JsonTests.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anzhuangbao/avro-cpp-1.8.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/JsonTests.dir/test/JsonTests.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/JsonTests.dir/test/JsonTests.cc.o -c /home/anzhuangbao/avro-cpp-1.8.2/test/JsonTests.cc

CMakeFiles/JsonTests.dir/test/JsonTests.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JsonTests.dir/test/JsonTests.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anzhuangbao/avro-cpp-1.8.2/test/JsonTests.cc > CMakeFiles/JsonTests.dir/test/JsonTests.cc.i

CMakeFiles/JsonTests.dir/test/JsonTests.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JsonTests.dir/test/JsonTests.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anzhuangbao/avro-cpp-1.8.2/test/JsonTests.cc -o CMakeFiles/JsonTests.dir/test/JsonTests.cc.s

CMakeFiles/JsonTests.dir/test/JsonTests.cc.o.requires:

.PHONY : CMakeFiles/JsonTests.dir/test/JsonTests.cc.o.requires

CMakeFiles/JsonTests.dir/test/JsonTests.cc.o.provides: CMakeFiles/JsonTests.dir/test/JsonTests.cc.o.requires
	$(MAKE) -f CMakeFiles/JsonTests.dir/build.make CMakeFiles/JsonTests.dir/test/JsonTests.cc.o.provides.build
.PHONY : CMakeFiles/JsonTests.dir/test/JsonTests.cc.o.provides

CMakeFiles/JsonTests.dir/test/JsonTests.cc.o.provides.build: CMakeFiles/JsonTests.dir/test/JsonTests.cc.o


# Object files for target JsonTests
JsonTests_OBJECTS = \
"CMakeFiles/JsonTests.dir/test/JsonTests.cc.o"

# External object files for target JsonTests
JsonTests_EXTERNAL_OBJECTS =

JsonTests: CMakeFiles/JsonTests.dir/test/JsonTests.cc.o
JsonTests: CMakeFiles/JsonTests.dir/build.make
JsonTests: libavrocpp.so.1.8.2.0
JsonTests: /usr/lib64/libboost_filesystem-mt.so
JsonTests: /usr/lib64/libboost_system-mt.so
JsonTests: /usr/lib64/libboost_program_options-mt.so
JsonTests: /usr/lib64/libboost_iostreams-mt.so
JsonTests: /usr/lib64/libboost_regex-mt.so
JsonTests: CMakeFiles/JsonTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anzhuangbao/avro-cpp-1.8.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable JsonTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/JsonTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/JsonTests.dir/build: JsonTests

.PHONY : CMakeFiles/JsonTests.dir/build

CMakeFiles/JsonTests.dir/requires: CMakeFiles/JsonTests.dir/test/JsonTests.cc.o.requires

.PHONY : CMakeFiles/JsonTests.dir/requires

CMakeFiles/JsonTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/JsonTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/JsonTests.dir/clean

CMakeFiles/JsonTests.dir/depend:
	cd /home/anzhuangbao/avro-cpp-1.8.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anzhuangbao/avro-cpp-1.8.2 /home/anzhuangbao/avro-cpp-1.8.2 /home/anzhuangbao/avro-cpp-1.8.2/build /home/anzhuangbao/avro-cpp-1.8.2/build /home/anzhuangbao/avro-cpp-1.8.2/build/CMakeFiles/JsonTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/JsonTests.dir/depend

