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