//
// Created by sky on 2017/10/12.
//

#include "mystring.h"
#include <cstring>
#include <iostream>

using namespace std;

// 这里需要先声明，不然后面都不能用这个静态变量
int Mystring::num_strings=0;

Mystring::Mystring(const char *s) {
    cout<<"+++++++ gouzao from char*"<<endl;
    this->len = strlen(s);
    this->str = new char(len + 1);
    strcpy(str, s);
    num_strings++;
}

Mystring::Mystring() {
    cout<<"+++++++ default gouzao"<<endl;
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

//这是拷贝构造函数
Mystring::Mystring(const Mystring &st) {
    cout<<"+++++++ copy gouzao from mystring&"<<endl;
    ++num_strings;
    this->len = st.len;
    this->str = new char(this->len + 1);
    strcpy(this->str, st.str);
}

Mystring::~Mystring() {
    cout<<"+++++++ xigou"<<endl;
    --num_strings;
    delete[]str;
}

//这是赋值函数
Mystring &Mystring::operator=(const Mystring &st) {
    cout<<"+++++++ fuzhi from mystring&"<<endl;
    if (this == &st)
        return *this;
    delete[]this->str;
    this->len = st.len;
    this->str = new char[this->len + 1];
    strcpy(this->str, st.str);
    return *this;
}

Mystring &Mystring::operator=(const char *st) {
    cout<<"+++++++ fuzhi from char*"<<endl;
    delete[]str;
    len = strlen(st);
    str = new char(len + 1);
    strcpy(str, st);
    return *this;
}

char &Mystring::operator[](int i) {
    cout<<"+++++++ char []"<<endl;
    if (i < 0) i = 0;
    if (i >= len) i = len - 1;

    return str[i]; // todo 其实应该判断i是否在区间内
}

const char &Mystring::operator[](int i) const
{
    cout<<"+++++++ const char[]"<<endl;
    if (i < 0) i = 0;
    if (i >= len) i = len - 1;
    return str[i];
}

bool operator<(const Mystring &s1, const Mystring &s2)
{
    return strcpy(s1.str, s2.str)<0;
}

bool operator>(const Mystring &s1, const Mystring &s2)
{
    return s2<s1;
}

bool operator==(const Mystring &s1, const Mystring &s2)
{
    return strcpy(s1.str, s2.str)==0;
}

std::ostream &operator<<(std::ostream &os, const Mystring &s)
{
    os<<s.str;
    return os;
}

std::istream &operator<<(std::istream &is, Mystring &s)
{
    char tmp[Mystring::CIN_LIMIT];
    is.getline(tmp, Mystring::CIN_LIMIT);
    if(is)
        s=tmp; //这里使用了 已经 重载过的   赋值运算符
    while(is && is.get()!='\n');
    return is;
}


//this is static method
int Mystring::HowMany() {
    return num_strings;
}
