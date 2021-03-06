//
// Created by stardan on 2017/10/8.
//

#ifndef CLION_PRO1_MYSTRUCT_H
#define CLION_PRO1_MYSTRUCT_H

#include <iostream>
#include <string>
#include <memory>

class mystruct_1 {
private:
  int _pz;
public:
  int _x, _y;

  mystruct_1() {
    _x = 1;
    _y = 2;
    _pz = 3;
  };

  mystruct_1(int x, int y, int pz = 0) : _x(x), _y(y), _pz(pz) {}

  ~mystruct_1();

  mystruct_1 operator+(const mystruct_1 &) const;

  friend mystruct_1 operator*(int, mystruct_1 &);

  friend std::ostream &operator<<(std::ostream &os, const mystruct_1 &);

  //ps: 不知道为什么，声明友元的时候，这个std::需要加上
  //否则在cpp里面就不是这个ostream了。。。
  mystruct_1 operator-() const { return mystruct_1(-_x, -_y, _pz); }
};

class mystruct_2 {
public:
  int _x, _y;
  union myunion {
    int _uid;
    char _uidstr[4];
  } _u;

  friend std::ostream &operator<<(std::ostream &os, const mystruct_2 &);
};


class Base1 {
private:
  int bx1;
};

class Base2 : public Base1 {
private:
  int bx2;
};

class Base3 : public Base2 {
private:
  int bx3;
};

class mystruct_3 {
public:
  int x;
  union {
    short st;
    int a:2, b:1;
  } u;
};

namespace myspace1 {
  class Kong;
}

class myclass_4_explicit;  //前向声明
class myclass_4 {
public:
  myclass_4(int x) : x_(x) {
    std::cout << "gouzao myclass_4, x=" << x << std::endl;
  }

  void intro() {
    std::cout << "myclass_4 x=" << x_ << std::endl;
  }

  int get_plus(int px) {
    return x_ + px;
  }

  void set_point(std::shared_ptr<myclass_4_explicit> me_exp_p) {
    me_p = me_exp_p;
  }

  ~myclass_4() {
    std::cout << "~myclass_4 x=" << x_ << std::endl;
  }

private:
  int x_;
  std::shared_ptr<myclass_4_explicit> me_p; //因为前向声明，所以可以用
};

class myclass_4_explicit {
public:
  explicit myclass_4_explicit(int x) : x_(x) {
    std::cout << "gouzao myclass_4_explicit, x=" << x << std::endl;
  }

  void intro() {
    std::cout << "myclass_4_explicit x=" << x_ << std::endl;
  }

  void set_point(std::shared_ptr<myclass_4> me_p) {
    me_exp_p = me_p;
  }

  ~myclass_4_explicit() {
    std::cout << "~myclass_4_explicit x=" << x_ << std::endl;
  }

private:
  int x_;
  std::shared_ptr<myclass_4> me_exp_p;
};

#endif //CLION_PRO1_MYSTRUCT_H
