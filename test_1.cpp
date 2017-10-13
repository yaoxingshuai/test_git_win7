#include "test_1.h"
#include "mystruct.h"
#include "my_solution.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <fstream>
#include <cassert>
#include "pack1/mystring.h"
#include <queue>
#include <random>
// #include <direct.h>  // this can be only used in windows, and use _getcwd
// #include <unistd.h>  // this is used for linux, also use getcwd

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

void estimate(int x, double(*pf)(int)) {
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
    cout << "flag = " << flag << "\t ~flag = " << !flag << 1 << 0 << endl;
    cout << "1<2:" << (1 < 2) << "\t 1>2:" << (1 > 2) << endl;
    cout.unsetf(ios_base::boolalpha);
    cout << "flag = " << flag << "\t ~flag = " << !flag << endl;
    cout << "1<2:" << (1 < 2) << "\t 1>2:" << (1 > 2) << endl;
    // ps: 注意了， flag=true， 但是 ~flag==-2, !flag 才是 false
    // 虽然设置了boolalpha，但是如果不是布尔值，依然显示1，0
}

void test_input_values() {
    int arr[5];
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
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

void test_write_file(const char *s) {
    ofstream outfile;
    outfile.open(s, ios::app);
    for (int i = 0; i < 10; ++i)
        outfile << "_" << i;
    outfile << endl;
    outfile.close();

    char buffer[50];
    //_getcwd(buffer, 50);
    //getcwd(buffer, 50);
    //cout << "directory = " << buffer << endl;
}


int value1 = 5;

void test_plus_value() {
    ++value1;
    cout << "value1 plus ok, now value1=" << value1 << endl;
}

void test_friend_and_operator() {
    mystruct_1 ms1{1, 2, 3};
    mystruct_1 ms2{5, 6, 7};
    cout << "ms1 and ms2 : " << ms1 << ms2 << endl;
    mystruct_1 ms = ms1 + ms2;  //用了一次析构函数
    assert(ms._x == 6);
    assert(ms._y == 8);
    cout << "add ------- ms = " << ms;

    ms = 5 * ms;   //这里会用两次析构函数
    cout << "plus ------- ms = " << ms;
    assert(ms._x == 30);
    assert(ms._y == 40);

    ms = -ms;
    cout << " -ms = " << ms;
    assert(ms._x == -30);
    assert(ms._y == -40);

}


void test_cout_struct() {
    mystruct_1 ms1;
    mystruct_2 ms2;
    cout << "ms1 = " << ms1 << endl;
    cout << "ms2 = " << ms2 << endl;
}

void test_mystring() {
    Mystring ms2("hello");  //+++++++ gouzao from char*
    Mystring ms1(ms2);//+++++++ copy gouzao from mystring&
    char a = ms2[1];//+++++++ char []
    const char b = ms1[1];//+++++++ char []
    const char &c = ms1[1];//+++++++ char []

    const Mystring ms3(ms1);//+++++++ copy gouzao from mystring&
    char d = ms3[1];//+++++++ const char[]
    const char &e = ms3[1];//+++++++ const char[]

    assert(a == b);
    //xigou ms3,ms1,ms2
}

void test_string() {
    string s = "hello, world";
    string s1 = s.substr(0, -1);
    assert(s1 == s);
    string s2 = s.substr(0, -2);
    assert(s2 == s1);
    string s3 = s.substr(0, 3);
    assert(s3 == "hel");
    string s4 = s.substr(3, 3);
    assert(s4 == "lo,");

    size_t index = s.find_first_of('o', 6); //从s[6]开始找'o'；
    assert(8 == index);

    index = s.find_first_of("rd", 0);   // 找 rd 中任何一个出现的地方， 从index=0开始找
    assert(9 == index);

    cout << "test string ok" << endl;
}

void test_priority_queue() {
    priority_queue<int> pque;  // 默认会创建大顶堆
    priority_queue<int, vector<int>, greater<int>> litque; // 小顶堆

    std::default_random_engine generator;
    std::uniform_int_distribution<int> dis(0, 100);
    std::normal_distribution<float> dis2(0, 10);  //应该是 均值0， 方差10  的正态分布
//    随机数由生成器和分布器结合产生
//    生成器generator：能够产生离散的等可能分布数值
//    分布器distributions: 能够把generator产生的均匀分布值映射到其他常见分布，如
//    均匀分布uniform，正态分布normal，二项分布binomial，泊松分布poisson

    for (int i = 0; i < 10; ++i) {
        int tmp = dis(generator);
        pque.push(tmp);
        litque.push(tmp);
    }

    while (!pque.empty()) {
        cout << "_" << pque.top();
        pque.pop();
    }
    cout << endl;

    while (!litque.empty()) {
        cout << "_" << litque.top();
        litque.pop();
    }
    cout << endl;

    //下面测试结构体的优先队列，需要结构体实现了 < 符号
    vector<Mystring> mstrs = {"hello", "world", "ipad"};
    //Mystring mstrs[] = {"hello", "world", "ipad"};
    cout << "___________" << endl;
    priority_queue<Mystring> strque;
    for (const auto &s: mstrs) {
        strque.push(s);
        //cout<<"s="<<s<<endl;
    }

    while (!strque.empty())   // 弹出顺序 world, ipad, hello 也是大顶堆
    {
        cout << strque.top() << "+++++" << endl;
        strque.pop();
    }

    //测试结构体的小顶堆
    cout << "___________" << endl;
    priority_queue<Mystring, vector<Mystring>, greater<Mystring>> lit_strque;
    //使用重载的 > 符号，创建小顶堆
    //弹出顺序 hello, ipad, world
    for (const auto &s: mstrs)
        lit_strque.push(s);
    while (!lit_strque.empty()) {
        cout << lit_strque.top() << "_________" << endl;
        lit_strque.pop();
    }
    /*   可以看到，在使用的时候，会多次调用 拷贝构造函数，赋值函数，析构函数 。。。
    hello_________
    +++++++ copy gouzao from mystring&
    +++++++ fuzhi from mystring&
    +++++++ fuzhi from mystring&
    +++++++ xigou
            +++++++ xigou
    ipad_________
    +++++++ copy gouzao from mystring&
    +++++++ fuzhi from mystring&
    +++++++ fuzhi from mystring&
     ...
     */

}


void test_pair() {
    cout << "---------test_pair-------" << endl;
    //pair 默认大顶堆，安装pair.first排序
    vector<pair<int, int>> pairvec;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> dis(0, 100);
    for (int i = 0; i < 10; ++i) {
        int first = dis(generator);
        int second = dis(generator);
        pairvec.emplace_back(pair<int, int>(first, second));
    }

    priority_queue<pair<int, int>> pque1;
    for (const pair<int, int> &p : pairvec)
        pque1.push(p);
    while (!pque1.empty()) {
        cout << "pop pque1: " << pque1.top().first << "\t" << pque1.top().second << endl;
        pque1.pop();
    }

    cout << "----------------------" << endl;

    // 下面创建大顶堆 , 默认也是按照 pair.first 排序的
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque2;
    for (const auto &p: pairvec)
        pque2.push(p);
    while (!pque2.empty()) {
        cout << "pop pque2: " << pque2.top().first << "\t" << pque2.top().second << endl;
        pque2.pop();
    }
    cout << "----------------------" << endl;

    // 下面创建小顶堆，且按照pair.second 排序
    priority_queue<pair<int, int>, vector<pair<int, int>>, my_solution> litpque3;
    for (const auto &p:pairvec)
        litpque3.push(p);
    while (!litpque3.empty()) {
        cout << "pop litpque3: " << litpque3.top().first << "\t" << litpque3.top().second << endl;
        litpque3.pop();
    }
    cout << "----------------------" << endl;

}
