#include <iostream>
#include <vector>
#include <unordered_map>
#include "test_1.h"
/* 在 settings keymap 中设置
 * format code    ctrl+alt+L
 * 多行注释 ctrl+/
 */

using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(9);
    vec.push_back(8);
    vec.push_back(10);

    for (auto i: vec)
        cout << i << "_";
    cout << endl;

    test_string_copy_on_write();

    return 0;
}

