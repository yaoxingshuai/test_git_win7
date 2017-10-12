cmake_minimum_required(VERSION 3.8)
project(test_git_win7)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        pack1/show.cpp
        pack1/show.h
        pack1/mystring.cpp
        pack1/mystring.h
        tmpfiles/vimrc
        main.cpp
        makefile
        my_solution.cpp
        my_solution.h
        mystruct.cpp
        mystruct.h
        test_1.cpp
        test_1.h)

include_directories(.)
include_directories(pack1)
include_directories(tmpfiles)

add_executable(test_git_win7 ${SOURCE_FILES})