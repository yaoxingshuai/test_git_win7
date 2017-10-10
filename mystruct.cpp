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

mystruct_1 mystruct_1::operator+(const mystruct_1 &ms2) const
{
    mystruct_1 ms;
    ms._x = this->_x + ms2._x;
    ms._y = this->_y + ms2._y;
    ms._pz = this->_pz + ms2._pz;
    return ms;  
    //�������������mystruct_1����������
    //�Ǹ����⣺����һ���ֲ���ʱ���������غ��൱�ڵ����˸�ֵ������Ȼ���������
}

mystruct_1 operator*(int m, mystruct_1 &ms)
{
    mystruct_1 ret;
    ret._x = ms._x * m;
    ret._y = ms._y * m;
    ret._pz = ms._pz * m;
    return ret;
    //����Ҳ�������������
}


ostream & operator<<(ostream & os, const mystruct_1& ms)
{
    os << "ms.x = " << ms._x << '\t';
    os << "ms.y = " << ms._y << '\t';
    os << "ms.pz = " << ms._pz << endl;
    // TODO: �ڴ˴����� return ���
    return os;
}
