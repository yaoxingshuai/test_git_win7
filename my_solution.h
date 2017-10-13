//
// Created by skystar on 2017/10/9.
//

#ifndef TEST_GIT_WIN7_MY_SOLUTION_H
#define TEST_GIT_WIN7_MY_SOLUTION_H

#include <iostream>
#include <vector>
#include <string>

class my_solution {
public:
    template<class T>
    inline const T &mymax(const T &a, const T &b) {
        return a > b ? a : b;
    }

    template<class T>
    inline void myswap(T &a, T &b) {
        T tmp;
        tmp = a;
        a = b;
        b = tmp;
    }

    inline bool operator()(const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
        if (p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second > p2.second;
    }

    //将字符串转为vector<int>     c++版split
    std::vector<int> str2vec(const std::string &);

};


#endif //TEST_GIT_WIN7_MY_SOLUTION_H
