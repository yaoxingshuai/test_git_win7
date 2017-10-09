test: main.cpp mystruct.cpp test_1.cpp pack1/show.cpp
	clang++ -std=c++11 main.cpp mystruct.cpp test_1.cpp pack1/show.cpp -o test
