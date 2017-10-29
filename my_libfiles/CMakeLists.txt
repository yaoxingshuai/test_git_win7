cmake_minimum_required(VERSION 3.8)


message(STATUS "mylib++++++++++++++++++")

message(STATUS ${PROJECT_SOURCE_DIR} "--------mylib workspace")

AUX_SOURCE_DIRECTORY(. MYLIBFILES)

#ADD_LIBRARY(my_func ${MYLIBFILES})
add_library(my_func ${MYLIBFILES})

message(STATUS "mylib end++++++++++++++++++")
