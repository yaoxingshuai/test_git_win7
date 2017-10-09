#include "test_1.h"
#include "mystruct.h"
#include "stdio.h"
#include <iostream>
#include <string>
#include "string.h"

using namespace std;
//
// Created by stardan on 2017/10/8.
//

void test_string_copy_on_write() {
    string s1 = "hello, world";
    string s2(s1);
    string s3;
    s3 = s1;
    printf("\tstr1's address: %x\n", s1.c_str());
    printf("\tstr2's address: %x\n", s2.c_str());
    printf("\tstr3's address: %x\n", s3.c_str());
    return;
}
// 我去，说好的写时复制呢 windows没有这个功能
//str1's address: 28febc
//str2's address: 28fea4
//str3's address: 28fe8c

// 在linux是没问题的
//str1's address: 1d34098
//str2's address: 1d34098
//str3's address: 1d34098

void test_my_struct() {
    mystruct_1 m1;
    mystruct_1 m2(3, 4);

    {
        mystruct_1 m3 = m1;
        m3._y += 100;
    }
    cout << "test_my_struct end" << endl;

}

void test_copy()
{
    char *s = "hello, world!";
    char d[20];
    memset(d, 20, '\0');
    memcpy(d, s, 10);
    cout<<d<<"___"<<endl;
    memcpy(d,s,19);
    cout<<d<<"___"<<endl;

    memset(d,20,'\0');
    strncpy(d,s,10);
    cout<<d<<"___"<<endl;

    cout<<s<<endl;
}