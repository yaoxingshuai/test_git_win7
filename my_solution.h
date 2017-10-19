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
template<typename MyType, int Capasity>
class MyTempClass_2 {
private:
    std::vector<MyType> vec;
public:
    void put(const MyType &x) { vec.push_back(x); }

    void show() {
        for (const auto &x: vec)
            std::cout << x << '\t';
        std::cout << "capasity=" << Capasity << '\t';
        std::cout << "size=" << vec.size() << std::endl;
    }

    MyTempClass_2() = default;

    MyTempClass_2(const MyType &t, int size) {
        vec = std::vector<MyType>(size, t);
    }
};

//虚函数必须实现吗
class Base1019 {
public:
    virtual void say() {
        std::cout << "hello, base1019" << std::endl;
    }

    virtual void full_virtual_say()=0;
};

class Child1019 : public Base1019 {
    //子类不重载父类的虚函数
    void full_virtual_say() override {
        std::cout<<"full virtual child1019"<<std::endl;
    }
};

class Child1019_override : public Base1019 {
public:
    void say() override {   // 子类覆盖虚函数， ps 编译器提示用override 显示说明
        std::cout << "this is child override a,b=" << _a << ',' << _b << std::endl;
    }

    void full_virtual_say() override {    //ps : 如果子类没有重载父类所有的纯虚函数，则子类也是抽象类，抽象类就不能实例化对象
        std::cout << "full virtual child1019 override a,b=" << _a << ',' << _b << std::endl;
    }

    Child1019_override(int a, int b) : _a(a), _b(b) {}

private:
    int _a, _b;
};

#endif //TEST_GIT_WIN7_MY_SOLUTION_H
