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
include CMakeFiles/avrogencpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/avrogencpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/avrogencpp.dir/flags.make

CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.o: CMakeFiles/avrogencpp.dir/flags.make
CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.o: ../impl/avrogencpp.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anzhuangbao/avro-cpp-1.8.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -U_GLIBCXX_DEBUG -o CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.o -c /home/anzhuangbao/avro-cpp-1.8.2/impl/avrogencpp.cc

CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -U_GLIBCXX_DEBUG -E /home/anzhuangbao/avro-cpp-1.8.2/impl/avrogencpp.cc > CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.i

CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -U_GLIBCXX_DEBUG -S /home/anzhuangbao/avro-cpp-1.8.2/impl/avrogencpp.cc -o CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.s

CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.o.requires:

.PHONY : CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.o.requires

CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.o.provides: CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.o.requires
	$(MAKE) -f CMakeFiles/avrogencpp.dir/build.make CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.o.provides.build
.PHONY : CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.o.provides

CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.o.provides.build: CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.o


# Object files for target avrogencpp
avrogencpp_OBJECTS = \
"CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.o"

# External object files for target avrogencpp
avrogencpp_EXTERNAL_OBJECTS =

avrogencpp: CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.o
avrogencpp: CMakeFiles/avrogencpp.dir/build.make
avrogencpp: libavrocpp_s.a
avrogencpp: /usr/lib64/libboost_filesystem-mt.so
avrogencpp: /usr/lib64/libboost_system-mt.so
avrogencpp: /usr/lib64/libboost_program_options-mt.so
avrogencpp: /usr/lib64/libboost_iostreams-mt.so
avrogencpp: /usr/lib64/libboost_regex-mt.so
avrogencpp: CMakeFiles/avrogencpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anzhuangbao/avro-cpp-1.8.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable avrogencpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/avrogencpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/avrogencpp.dir/build: avrogencpp

.PHONY : CMakeFiles/avrogencpp.dir/build

CMakeFiles/avrogencpp.dir/requires: CMakeFiles/avrogencpp.dir/impl/avrogencpp.cc.o.requires

.PHONY : CMakeFiles/avrogencpp.dir/requires

CMakeFiles/avrogencpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/avrogencpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/avrogencpp.dir/clean

CMakeFiles/avrogencpp.dir/depend:
	cd /home/anzhuangbao/avro-cpp-1.8.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anzhuangbao/avro-cpp-1.8.2 /home/anzhuangbao/avro-cpp-1.8.2 /home/anzhuangbao/avro-cpp-1.8.2/build /home/anzhuangbao/avro-cpp-1.8.2/build /home/anzhuangbao/avro-cpp-1.8.2/build/CMakeFiles/avrogencpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/avrogencpp.dir/depend

