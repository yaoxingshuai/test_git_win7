cmake_minimum_required(VERSION 3.8)

message(STATUS "test+++++++++++")

set(WORKSPACE ${PROJECT_SOURCE_DIR}/)   #source_dir指的是当前工作目录

message(STATUS ${WORKSPACE} "---------test workspace")
#include_directories(${WORKSPACE}/my_libfiles)


link_directories(${WORKSPACE}/build/my_libfiles/)

ADD_EXECUTABLE(test_mylib test_mylib.cpp)
TARGET_LINK_LIBRARIES(test_mylib libmy_func.a)

ADD_EXECUTABLE(test_leetcode test_leetcode.cpp ${WORKSPACE}/my_solution.cpp)
#TARGET_LINK_LIBRARIES(test_leetcode )


message(STATUS "test end+++++++++++")
