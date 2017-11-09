cmake_minimum_required(VERSION 3.8)
project(test_git_win7)
message(STATUS "main++++++++++")

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_VERBOSE_MAKEFILE on)   #输出详细的编译和链接信息

set(WORKSPACE ${PROJECT_SOURCE_DIR})
message(STATUS ${WORKSPACE} "-------main workspace")



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
        test_1.h pack1/player.cpp pack1/player.h
        my_thread.h
        )
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -g -pipe -W -Wall -fPIC --std=c++11")
set(WORKSPACE ${PROJECT_SOURCE_DIR}/./)   #source_dir指的是当前工作目录

include_directories(.)
include_directories(pack1)
include_directories(tmpfiles)
include_directories(my_libfiles)  #弄了个局部动态库
include_directories(${WORKSPACE}/jsoncpp-src-0.5.0/include)   #json/json.h 头文件的位置
include_directories(${WORKSPACE}/avro-cpp-1.8.2/include)
include_directories(/usr/include)
#include_directories(${WORKSPACE}/third/glog/include)

link_directories(${WORKSPACE}/jsoncpp-src-0.5.0/libs/linux-gcc-4.8.5)  # libjson 库文件的位置
link_directories(${WORKSPACE}/avro-cpp-1.8.2/lib)
link_directories(/usr/lib64/)
#link_directories(${WORKSPACE}/third/glog/lib)

link_directories(${WORKSPACE}/build/my_libfiles)  #这里有my_libfiles产生的.a


add_executable(test_git_win7 ${SOURCE_FILES})
#TARGET_LINK_LIBRARIES(test_git_win7 libjson_linux-gcc-4.8.5_libmt.a libavrocpp_s.a)  #把json.a库编译进来
target_link_libraries(test_git_win7 libjson_linux-gcc-4.8.5_libmt.a libavrocpp_s.a  #把json.a库编译进来
        libmy_func.a   # 需要先到  test_git_win7/build/my_libfiles git:(master) ✗ >make    产生libmy_func.a
        glog #libglog.a
        boost_thread
        boost_system boost_timer #对‘boost::timer::cpu_timer::elapsed() const’未定义的引用
        )

add_subdirectory(my_libfiles)
add_subdirectory(test)
message(STATUS "main end++++++++++")

#  -- main++++++++++
#  -- /home/test_cpp/test_git_win7-------main workspace
#  -- mylib++++++++++++++++++
#  -- /home/test_cpp/test_git_win7--------mylib workspace
#  -- mylib end++++++++++++++++++
#  -- test+++++++++++
#  -- /home/test_cpp/test_git_win7/---------test workspace
#  -- test end+++++++++++
#  -- main end++++++++++
#  -- Configuring done
#  -- Generating done
#  -- Build files have been written to: /home/test_cpp/test_git_win7/build
