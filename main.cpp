#include <iostream>
#include <vector>
#include <unordered_map>
#include "test_1.h"
#include "my_solution.h"

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

    for (auto i: vec)
        cout << i << "_";
    cout << endl;

    unordered_map<int, string> map1;
    map1[1] = "hello";
    map1[2] = "world";

    for (auto iter = map1.begin(); iter != map1.end(); ++iter)
        cout << iter->first << "_" << iter->second << endl;

    test_string_copy_on_write();
    test_my_struct();
    test_copy();

    int x=3, y=6;
    my_solution sov;
    int z=sov.mymax(x, y);
    cout<<"z="<<z<<endl;

    estimate(3, test_func1);
    estimate(3, test_func2);

    test_new_and_delete();

    return 0;
}

