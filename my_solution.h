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

//正确的类模板使用姿势
template<typename T1, typename T2>
class MyTempClass {
private:
    T1 a;
    T2 b;
    bool flag;
public:
    MyTempClass(const T1 &t1, const T2 &t2, bool f) {
        a = t1;
        b = t2;
        flag = f;
    }

    void show() {
        std::cout << "a=" << a << "\t b=" << b << "\t flag=" << flag << std::endl;
    }
};

//还可以带非模板类型参数哦
template<typename MyType, int MYSIZE>
class MyTempClass_2 {
private:
    std::vector<MyType> vec;
public:
    void put(const MyType &x) { vec.push_back(x); }

    void show() {
        for (const auto &x: vec)
            std::cout << x << '\t';
        std::cout << "capasity=" << MYSIZE << std::endl;
    }
};

#endif //TEST_GIT_WIN7_MY_SOLUTION_H
