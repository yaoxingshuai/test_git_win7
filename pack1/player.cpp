//
// Created by sky on 2017/10/17.
//

#include "player.h"
#include <iostream>

using namespace std;


TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) {
  first_name = fn;
  last_name = ln;
  has_table = ht;
}

void TableTennisPlayer::Name() const {
  cout << "hello: " << first_name << "___" << last_name << endl;
}


//RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht) {
//    rating=r;
//    TableTennisPlayer(fn, ln, ht);
//}

RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht) :
    TableTennisPlayer(fn, ln, ht), rating(r) {

}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp) :
    TableTennisPlayer(tp) {
  rating = r;
}

/*
template <class T> Mytemplate_1107<T>::Mytemplate_1107() {
  cout<<"hello, this is constructor of Mytemplate---"<<endl;
}

template <class T> T Mytemplate_1107<T>::temp_add(const T &a, const T &b) {
  T c = a + b;
  cout<<"add a,b a="<<a<<"\t b="<<b<<",\t sum="<<c<<endl;
  return c;
}
  important:
  对于一般的函数，声明和定义可以分开放
  但是对于模板，最好是都放在.h文件中，因为有的编译器不支持分开放

  C++中模板不能把实现和声明放在两个不同的文件下
  既然是在编译的时候，根据套用的不同类型进行编译，那么，套用不同类型的模板类实际上就是两个不同的类型，
  也就是说，stack<int>和 stack<char>是两个不同的数据类型，他们共同的成员函数也不是同一个函数，
  只不过具有相似的功能罢了。用的是STL里面的stack，stack<int>和stack<char>的默认构造函数和push函数的
  入口地址是不一样的，而不同的stack<int>对象相同的函数入口地址是一样的，
  这个也反映了模板类在套用不同类型以后， 会被编译出不同代码的现象。

  所以模板类的实现，脱离具体的使用，是无法单独的编译的；把声明和实现分开的做法也是不可取的，
  必须把实现全部写在头文件里面。为了清晰，实现可以不写在class后面的花括号里面，可以写在class的外面。
*/