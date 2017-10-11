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



#endif //CLION_PRO1_TEST_1_H
