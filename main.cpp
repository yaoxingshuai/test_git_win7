#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "test_1.h"
#include "my_solution.h"
#include "pack1/show.h"

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
    map1[1] = string("hello");
    map1[2] = string("world");

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

    Show_Solution show_sov;
    show_sov.show_vec(vec);
    show_sov.show_vec_template(vec);
    // show_sov.show_vec_template_2(vec);  不知道为什么， 定义和声明都ok，但是调用不可以
    // show_sov.show_vec_template_2<int>(vec);
    
    //test_all_limits();
    //test_union();
    //test_ios_show();
    //test_input_values();

    test_show_xiaoshu();

    getchar();
    return 0;
}

