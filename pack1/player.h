//
// Created by sky on 2017/10/17.
//

#ifndef TEST_GIT_WINDOWS_PLAYER_H
#define TEST_GIT_WINDOWS_PLAYER_H

#include <string>
#include <iostream>

using std::string;

class TableTennisPlayer {
private:
  string first_name;
  string last_name;
  bool has_table;

public:
  TableTennisPlayer(const string &fn = "default_fname", const string &ln = "default lname",
                    bool ht = false);

  void Name() const;

  bool HasTable() const { return has_table; }

  void ResetTable(bool v) { has_table = v; }
};

class RatedPlayer : public TableTennisPlayer {
private:
  unsigned int rating;
public:
  RatedPlayer(unsigned int r = 0, const string &fn = "", const string &ln = "", bool ht = false);

  RatedPlayer(unsigned int r, const TableTennisPlayer &tp);

  unsigned int Rating() const { return rating; }

  void ResetRating(unsigned int r) { rating = r; }
};

class Bird {
private:
  string bird_name_;
public:
  void Name() const {
    std::cout << "hello, bird_name = " << bird_name_ << std::endl;
  }

  void sing() const {
    std::cout << "hello, bird saying......" << std::endl;
  }

  Bird(const string &bird_name = "default bird name") : bird_name_(bird_name) {}
};

#endif //TEST_GIT_WINDOWS_PLAYER_H


#ifndef MY_TEMPLATE_1107
#define MY_TEMPLATE_1107

#include <iostream>

template<class T>
class Mytemplate_1107 {
public:
  T temp_add(const T &a, const T &b);

  Mytemplate_1107();
};

template<class T>
Mytemplate_1107<T>::Mytemplate_1107() {
  std::cout << "hello, this is constructor of Mytemplate---" << std::endl;
}

template<class T>
T Mytemplate_1107<T>::temp_add(const T &a, const T &b) {
  T c = a + b;
  std::cout << "add a,b a=" << a << "\t b=" << b << ",\t sum=" << c << std::endl;
  return c;
}


// 我试试从带有Name()函数的类模板，使用父类的Name()函数  player::Name(),   Bird::Name()
template<class NameClass>
class ShowName_1107 : public NameClass {
public:
  void show_template_name() {
    NameClass::Name();
  }
};


#endif

