test: main.cpp mystruct.cpp my_solution.cpp test_1.cpp pack1/show.cpp pack1/mystring.cpp pack1/player.cpp
	clang++ -std=c++11 main.cpp mystruct.cpp my_solution.cpp test_1.cpp pack1/show.cpp pack1/mystring.cpp pack1/player.cpp -lpthread -o test
