#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "test_1.h"
#include "my_solution.h"
#include "pack1/show.h"
#include <cassert>
#include <deque>
#include <bitset>

/* 在 settings keymap 中设置
 * format code    ctrl+alt+L  (win)         alt+command+L (mac)
 * 多行注释 ctrl+/
 */

/*
上面是clion的设置
这是vs的设置
选中   ALT+F8
*/

// g++ -std=c++11 -g main.cpp test_1.cpp -o gdb_main  产生gdb

using namespace std;


int main() {

//  test_string_copy_on_write();
//  test_my_struct();
//  test_copy();
//
//  estimate(3, test_func1);
//  estimate(3, test_func2);
//
//  test_new_and_delete();


  // show_sov.show_vec_template_2(vec);  不知道为什么， 定义和声明都ok，但是调用不可以
  // show_sov.show_vec_template_2<int>(vec);

  //test_all_limits();
  //test_union();
  //test_ios_show();
  //test_input_values();

  //test_show_xiaoshu();
  //test_write_file("./write_file.txt");

  //cout << "x=" << x << "\t y=" << y << endl;
  //sov.myswap(x, y);
  //cout << "x=" << x << "\t y=" << y << endl;

/*
    extern int value1;
    assert(value1 == 5);
    ++value1;
    assert(value1 == 6);
    test_plus_value();
    assert(value1 == 7);
*/
  //test_friend_and_operator();

//    deque<int> mydeq(3, 1);
//    cout << "my deque size=" << mydeq.size() << "\t capacity=" << mydeq.max_size() << endl;
//    bitset<16> bs(0xf);
//    cout << "bs=" << bs << endl;
//    long bs_long = bs.to_ulong();
//    cout<<"bs long="<<bs_long<<endl;

//    test_cout_struct();
//    test_mystring();
//    test_string();
//    test_priority_queue();
//    test_pair();
//    test_hash();

  // test_thread();   //only used for mac and linux
  //test_extend();

  //test_tmp_everything();
  //test_str2vec();

  //test_time();

  //test_default_args(x=1, y=5);
  //test_player();
  //test_try_catch();
  //test_smart_ptr();
  //test_smart_ptr2();
//    test_json();
//    test_make_shared();
  //test_kong_class();

  //test_my_temp_class();
  //test_my_temp_class2();
  //test_virtual_method();
  //test_enum();
  //test_json();
  //test_avro();
//  test_boost_any();
//  test_explicit();
//  test_share_ptr_loop();
//  test_share_ptr_loop2();
  //test_bind();
  //test_lambda();
//  test_progress_bar();
  //test_istreambuf();
  //test_glog();
  //test_map_and_boost_any();
//  test_mytemplate_1107();
//  test_class_bird();
//  test_template_public();
  //getchar();
  //test_boost_thread();
  test_my_blocking_queue();
  return 0;
}

