//
// Created by stardan on 2017/10/8.
//

#ifndef CLION_PRO1_MYSTRUCT_H
#define CLION_PRO1_MYSTRUCT_H

#include <ostream>

class mystruct_1 {
private:
    int _pz;
public:
    int _x, _y;
    mystruct_1() { _x = 1; _y = 2; _pz = 3; };
    mystruct_1(int x, int y, int pz = 0) : _x(x), _y(y), _pz(pz) {}
    ~mystruct_1();

    mystruct_1 operator+(const mystruct_1 &) const;
    friend mystruct_1 operator*(int, mystruct_1 &);
    friend std::ostream& operator<<(std::ostream &os, const mystruct_1 &);
    //ps: ��֪��Ϊʲô��������Ԫ��ʱ�����std::��Ҫ����
    //������cpp����Ͳ������ostream�ˡ�����
    mystruct_1 operator-() const { return mystruct_1(-_x, -_y, _pz); }
};

class mystruct_2 {
public:
    int _x, _y;
    union myunion
    {
        int _uid;
        char _uidstr[4];
    }_u;
};

#endif //CLION_PRO1_MYSTRUCT_H
