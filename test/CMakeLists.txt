cmake_minimum_required(VERSION 3.8)

message(STATUS "test+++++++++++")

set(WORKSPACE ${PROJECT_SOURCE_DIR}/)   #source_dir指的是当前工作目录

message(STATUS ${WORKSPACE} "---------test workspace")   # -- /home/test_cpp/test_git_win7/---------test workspace

#include_directories(${WORKSPACE}/my_libfiles)

include_directories(/usr/include/)

link_directories(${WORKSPACE}/build/my_libfiles/
        /usr/lib64/)

ADD_EXECUTABLE(test_mylib test_mylib.cpp)
TARGET_LINK_LIBRARIES(test_mylib libmy_func.a glog)

ADD_EXECUTABLE(test_leetcode test_leetcode.cpp ${WORKSPACE}/my_solution.cpp)
TARGET_LINK_LIBRARIES(test_leetcode glog)
#TARGET_LINK_LIBRARIES(test_leetcode )

#include_directories(${WORKSPACE}/avro-cpp-1.8.2/include)
#link_directories(${WORKSPACE}/avro-cpp-1.8.2/lib)   #  不需要了，在上游的cmakelists.txt中已经添加该路径了
ADD_EXECUTABLE(test_third test_third.cpp)
target_link_libraries(test_third libavrocpp_s.a  #把json.a库编译进来
        )

message(STATUS "test end+++++++++++")
