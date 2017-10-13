//
// Created by stardan on 2017/10/8.
//

#include "mystruct.h"
#include <iostream>

using namespace std;

mystruct_1::~mystruct_1() {
    cout << "~ mystruct xigou ----------" << endl;
    cout << "x = " << this->_x << "\t y = " << this->_y << endl;
    cout << "-----" << endl;
}

mystruct_1 mystruct_1::operator+(const mystruct_1 &ms2) const {
    mystruct_1 ms;
    ms._x = this->_x + ms2._x;
    ms._y = this->_y + ms2._y;
    ms._pz = this->_pz + ms2._pz;
    return ms;
    //这里会立即调用mystruct_1的析构函数
    //星哥的理解：这是一个局部临时变量，返回后相当于调用了赋值函数，然后就析构了
}

mystruct_1 operator*(int m, mystruct_1 &ms) {
    mystruct_1 ret;
    ret._x = ms._x * m;
    ret._y = ms._y * m;
    ret._pz = ms._pz * m;
    return ret;
    //这里也会调用析构函数
}


ostream &operator<<(ostream &os, const mystruct_1 &ms) {
    os << "ms.x = " << ms._x << '\t';
    os << "ms.y = " << ms._y << '\t';
    os << "ms.pz = " << ms._pz << endl;
    return os;
}

ostream &operator<<(ostream &os, const mystruct_2 &ms) {
    os << "ms.x: " << ms._x << '\t';
    os << "ms.y: " << ms._y << '\t';
    os << "ms.uid: " << ms._u._uid << endl;
    return os;
}