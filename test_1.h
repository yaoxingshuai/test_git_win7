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
void estimate(int x, double (*pf)(int));

//test new and delete
void test_new_and_delete();

//test climits
void test_all_limits();

#endif //CLION_PRO1_TEST_1_H
