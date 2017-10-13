//
// Created by skystar on 2017/10/9.
//

#include "show.h"
#include <iostream>

using namespace std;

template<class T>
void Show_Solution::show_vec_template_2(const vector<T> &vec) {
    for (const auto x : vec)
        cout << x << "_";
    cout << endl;
}

void Show_Solution::show_vec(const vector<int> &vec) {
    for (const auto x : vec)
        cout << x << '_';
    cout << "\n-----show vector ok" << endl;
}