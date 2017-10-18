//
// Created by stardan on 2017/10/8.
//

#ifndef CLION_PRO1_TEST_1_H
#define CLION_PRO1_TEST_1_H


void test_string_copy_on_write();

void test_my_struct();

void test_copy();

//test function pointer
double test_func1(int x);

double test_func2(int x);

void estimate(int x, double(*pf)(int));

//test new and delete
void test_new_and_delete();

//test climits
void test_all_limits();

void test_union();

//用true flase显示bool值
void test_ios_show();

void test_input_values();

void test_show_xiaoshu();

void test_write_file(const char *s);

void test_plus_value();


//测试友元函数访问私有变量pz，重载运算符
void test_friend_and_operator();

void test_cout_struct();

void test_mystring();

void test_string();

void test_priority_queue();

void test_pair();

void test_hash();

void test_thread();

void test_extend();

void test_tmp_everything();

void test_str2vec();

void test_time();

void test_default_args(int x, int y, int z = 3);  //默认参数需要放到最右边

void test_player();

void test_throw_exception();

void test_try_catch();

void test_smart_ptr();

void test_smart_ptr2();

void test_json();

void test_make_shared();

#endif //CLION_PRO1_TEST_1_H
