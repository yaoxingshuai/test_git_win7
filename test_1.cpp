#include "test_1.h"
#include "mystruct.h"
#include "stdio.h"
#include <iostream>
#include <string>
#include "string.h"
#include <climits>

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

void test_copy() {
    const char *s = "hello, world!";
    char d[20];
    memset(d, '\0', 20);
    memcpy(d, s, 10);
    cout << d << "___" << endl;
    memcpy(d, s, 19);
    cout << d << "___" << endl;

    memset(d, '\0', 20);
    strncpy(d, s, 10);
    cout << d << "___" << endl;

    cout << s << endl;
}


double test_func1(int x) {
    return x * 2;
}

double test_func2(int x) {
    return x * x;
}

void estimate(int x, double (*pf)(int)) {
    double result = pf(x);
    cout << "result = " << result << endl;
}


void test_new_and_delete() {
    auto *p = new char[10];
    memcpy(p, "hello\0", 6);
    cout << "p = " << p << endl;
    delete[]p;
    cout << "delete ok" << endl;
}


void test_all_limits() {
    cout << "char bit:" << CHAR_BIT << endl;
    cout << "char max:" << CHAR_MAX << endl;
    cout << "signed char max" << SCHAR_MAX << endl;
    cout << "unsigned char max" << UCHAR_MAX << endl;
    cout << "int max" << INT_MAX << endl;
    cout << "int min" << INT_MIN << endl;
    cout << "uint max" << UINT_MAX << endl;
}

void test_union() {
    mystruct_2 ms2;
    ms2._u._uid = 12;
    cout << "uid = " << ms2._u._uid << endl;
    strncpy(ms2._u._uidstr, "abc", 4);
    //strcpy(ms2._u._uidstr, "abc");
    cout << "uidstr = " << ms2._u._uidstr << endl;
    cout << "uidstr to uid may be wrong, uid = " << ms2._u._uid << endl;
}

void test_ios_show() {
    bool flag = true;
    cout << "flag = " << flag << "\t ~flag = " << ~flag << endl;
    cout.setf(ios_base::boolalpha);
    cout << "flag = " << flag << "\t ~flag = " << !flag << endl;
    cout << "flag = " << flag << "\t ~flag = " << !flag << 1<<0<< endl;
    cout << "1<2:" << (1 < 2) << "\t 1>2:" << (1 > 2) << endl;
    cout.unsetf(ios_base::boolalpha);
    cout << "flag = " << flag << "\t ~flag = " << !flag << endl;
    cout << "1<2:" << (1 < 2) << "\t 1>2:" << (1 > 2) << endl;
    // ps: 注意了， flag=true， 但是 ~flag==-2, !flag 才是 false
    // 虽然设置了boolalpha，但是如果不是布尔值，依然显示1，0
}

void test_input_values()
{
    int arr[5];
    for (int i = 0; i < sizeof(arr)/sizeof(int); ++i)
    {
        cout << "input a number:" << flush;
        while (!(cin >> arr[i])) {
            cin.clear();
            while (cin.get() != '\n')
                cout << "get one char" << endl;
            cout << "input a number:" << flush;     
        }
    }
    //ps :如果输入 12a， 12会成功放入arr，但是'a'会留在输入队列，下次读取失败
    //如果输入 a12， 会把'a', '1', '2'都cin.get()吸收掉
    while (cin.get() != '\n');
    for (const auto x : arr)
        cout << x << "_";
    cout << endl;
    
}

void test_show_xiaoshu() {
    double dd = 123.42312;
    cout << dd << endl;  // 123.423, 默认保留 6 位有效数字
    cout.precision(2);
    cout << dd << endl;  // 1.2e+02  保留 2 位有效数字
    cout.setf(ios::fixed);
    cout << dd << endl;   // 123.42  表示保留小数点后面的 2 位数字

    cout.unsetf(ios::fixed);
    cout.precision(9);
    cout << dd << endl;

}



