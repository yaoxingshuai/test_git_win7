test: main.cpp mystruct.cpp test_1.cpp pack1/show.cpp pack1/mystring.cpp
	clang++ -std=c++11 main.cpp mystruct.cpp test_1.cpp pack1/show.cpp pack1/mystring.cpp -lpthread -o test
