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
        test_1.h pack1/player.cpp pack1/player.h)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -g -pipe -W -Wall -fPIC --std=c++11")
set(WORKSPACE ${PROJECT_SOURCE_DIR}/./)   #source_dir指的是当前工作目录

include_directories(.)
include_directories(pack1)
include_directories(tmpfiles)
include_directories(${WORKSPACE}/jsoncpp-src-0.5.0/include)   #json/json.h 头文件的位置
include_directories(${WORKSPACE}/avro-cpp-1.8.2/include)

link_directories(${WORKSPACE}/jsoncpp-src-0.5.0/libs/linux-gcc-4.8.5)  # libjson 库文件的位置
link_directories(${WORKSPACE}/avro-cpp-1.8.2/lib)


add_executable(test_git_win7 ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(test_git_win7 libjson_linux-gcc-4.8.5_libmt.a libavrocpp_s.a)  #把json.a库编译进来
