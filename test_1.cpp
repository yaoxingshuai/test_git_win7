#include "test_1.h"
#include "mystruct.h"
#include "my_solution.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <fstream>
#include <sstream>
#include <cassert>
#include "pack1/mystring.h"
#include "pack1/show.h"
#include "pack1/player.h"
#include "json/json.h"
#include <queue>
#include <random>
#include <iomanip>
// #include <direct.h>  // this can be only used in windows, and use _getcwd
// #include <unistd.h>  // this is used for linux, also use getcwd
#include <memory>  //for auto_ptr unique_ptr share_ptr
#include <algorithm>  // for_each

#include "intro.h"
#include <functional>
#include <unordered_map>
#include <boost/any.hpp>
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

void test_hash() {
  cout << "__________test_hash________" << endl;
  hash<int> hint;
  hash<string> hstr;

  size_t x = hint(123);
  size_t y = hint(121234);
  size_t z1 = hstr("hello");
  size_t z2 = hstr("world");

  /*
      x: 123
      y: 121234
      z1: 235368941344721064
      z2: 6790229356339542235
   */

  cout << hex;   //接下来都是16进制
  cout.setf(ios::showbase | ios::uppercase);  //接下来都是 展示 OX，不然用户可能不知道是16进制

  cout.width(32);
  cout.fill('0');  // width，fill 这两个只能持续一次
  cout << "x: " << x << endl; //问题是出现如下情况，把 x: 也算到一起了   000000x: 7b

  cout << "y: " << setw(32) << setfill('0') << y << endl;    //这个也只出现一次，但是效果好得多    需要引入 <iomanip>
  cout << "z1: " << z1 << endl;
  cout << "z2: " << z2 << endl;


  /*
   * output
      00000000000000000000000000000x: 0X7B
      y: 00000000000000000000000000X1D992
      z1: 0X34432CE1C0308A8
      z2: 0X5E3BBD9F980C38DB
   */
  cout << "__________test_hash_end_______" << endl;
}

/*
#include <pthread.h>
#include <unistd.h>   //在linux中需要引入改文件, 并且编译的时候需要 -l pthread,   windows不能用pthread, mac 下直接通过

#define NUM_THREADS 5

// 线程的运行函数
void *say_hello(void *args) {
    cout << "Hello Runoob！" << endl;
    sleep(10);
    cout<<"-----exit"<<endl;
}

void test_thread() {
    pthread_t tids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i) {
        //参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (ret != 0) {
            cout << "pthread_create error: error_code=" << ret << endl;
        }
        sleep(1);
    }
    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
}
*/

void test_extend() {
  cout << "-------------test_extend-------" << endl;
  Base1 b1;
  Base2 b2;
  Base3 b3;

  cout << "base1.size: " << sizeof(b1) << endl;
  cout << "base2.size: " << sizeof(b2) << endl;
  cout << "base2.size: " << sizeof(b3) << endl;

  assert(sizeof(b1) == 4);
  assert(sizeof(b2) == 8);
  assert(sizeof(b3) == 12);

  cout << "-------------test_extend_end ------" << endl;
}


void test_tmp_everything() {
  mystruct_3 m3;
  assert(sizeof(m3) == 8);
  assert(sizeof(m3.x) == 4);
  assert(sizeof(m3.u) == 4);
  assert(sizeof(m3.u.st) == 2);   //虽然u.st size=2 , 但是作为联合体，按照大的算， u.a, u.b 占用一个int size=4
}

void test_str2vec() {
  cout << "-------------test_str2vec-------" << endl;
  my_solution sov;
  string string1 = "   1 23 5 32 42 234  654 64  45 \t 12 \n 123 ";
  vector<int> vector1 = sov.str2vec(string1);

  Show_Solution show_sov;
  show_sov.show_vec(vector1);

  int i = 123;
  string string2 = to_string(i);
  assert(string2 == "123");
  int i2 = stoi(string2, 0, 8);  //8 进制"123"  1*8^2 + 2*8 + 3 == 83
  assert(i2 == 83);

  cout << "-------------test_str2vec end-------" << endl;
}

void test_time() {
  cout << "-------------test_time-------" << endl;
  time_t now_time;
  now_time = time(NULL);
  cout << "now time: " << now_time << endl;

  time_t t = time(nullptr);
  char tmp[64];
  strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A  第 %j dayth %z", localtime(&t));
  cout << "str time: " << tmp << endl;

  cout << "-------------test_time end-------" << endl;
}

void test_default_args(int x, int y, int z) {
  cout << "x=" << x << "\t y=" << y << "\t z=" << z << endl;
}

void test_player() {
  TableTennisPlayer base_player;
  RatedPlayer rate_player;
  base_player.Name();  //hello: default_fname___default lname
  rate_player.Name();  //hello: ___
  assert(rate_player.Rating() == 0);

  RatedPlayer rate_player2(3, base_player);
  rate_player2.Name(); //hello: default_fname___default lname
  assert(rate_player2.HasTable() == false);
  assert(rate_player2.Rating() == 3);
}

void test_throw_exception() {
  cout << "hello, begin throw except" << endl;
  throw "---this is an exception---";
  cout << "throw end--- this cannot be reached" << endl;
}

void test_try_catch() {
  cout << "try begin---" << endl;
  try {
    test_throw_exception();
  } catch (const char *string1) {
    cout << "catch an exception: " << string1 << endl;
  }
  cout << "try end------" << endl;
/*
try begin---
hello, begin throw except
catch an exception: ---this is an exception---
try end------
*/
}


unique_ptr<string> check_tmp_unique_ptr() {
  unique_ptr<string> tmp_uni_ptr(new string("hello"));
  cout << *tmp_uni_ptr << endl;
  return tmp_uni_ptr;
}

void test_smart_ptr() {
  double *pDouble = new double;
  *pDouble = 25.6;
  delete (pDouble);

  /*----------------------*/

  // ***** unique_ptr<double > uni_ptr=new double;   // impor: 不能这样初始化，不知道为啥
  // *****       因为：   new double 返回的是一个普通指针，不能将一个普通指针赋值给智能指针

  unique_ptr<double> uni_ptr(new double); //只能这样，     但是可以用普通指针初始化智能指针
  *uni_ptr = 30.1;
  // delete is not needed

  shared_ptr<int> shr_ptr(new int);
  *shr_ptr = 3;

  cout << *uni_ptr << "__" << *shr_ptr << endl;

  // impor 这个行为需要避免
// *   string string1("it's dangerous");
// *   shared_ptr<string> danger_ptr(&string1);   //不把智能指针用于非堆内存

  unique_ptr<string> ps1(new string("this is unique str"));
  unique_ptr<string> ps2;
  // ps2=ps1; // unique_ptr cannot assign

  ps2 = check_tmp_unique_ptr();   //临时的unique_ptr，可以转移
  assert(*ps2 == "hello");

  //unique指针如果需要转移
  unique_ptr<string> ps3;
  ps3 = move(ps1);   //如果非要转移，用move， ps3获取权限，ps1指向空
  assert(*ps3 == "this is unique str");
  assert(ps1 == nullptr);


  // 下面介绍一下智能指针指向 数组
  unique_ptr<double[]> pds(new double[5]);
  for (int i = 0; i < 5; ++i) {
    pds.get()[i] = double(i) / 3;    // ps: not *pds[i]
  }
  for (int i = 0; i < 5; ++i)
    cout << pds.get()[i] << "\t";
  cout << endl;
}

unique_ptr<int> make_int(int n = 1) {
  return unique_ptr<int>(new int(n));
}

void show_ptr(unique_ptr<int> &unique_ptr1) {
  cout << *unique_ptr1 << "_-_";
}

void test_smart_ptr2() {
  unsigned int size = 10;
  vector<unique_ptr<int>> vp(size);
  for (int i = 0; i < size; ++i)
    vp[i] = make_int(i * i);
  vp.push_back(make_int());
  for_each(vp.begin(), vp.end(), show_ptr);   // include <algorithm>
}

void test_make_shared() {
  cout << "------begin test make shared--------" << endl;
  auto shr_ptr = make_shared<double>(1.1);
  cout << "*shr_ptr = " << *shr_ptr << endl;
  *shr_ptr = 3.3;
  cout << "*shr_ptr = " << *shr_ptr << endl;
  cout << "------end test make shared--------" << endl;

  {
    auto mystr_ptr = make_shared<mystruct_1>(1, 2, 3);   //创建一个mystruct的智能指针, 括号后面是构造函数的参数
    cout << "this is mystr-----------" << endl;
    cout << *mystr_ptr << "-------" << endl;
  }

}

namespace mortred {
  class Row; //是不是只声明了，没有具体定义啊
}

void test_kong_class() {

  shared_ptr<mortred::Row> ptr;
  mortred::Row *row;
  myspace1::Kong *kong1;   // 对于这种前向声明的类，不能声明对象实例，但是可以声明一个指针

  cout << "size of kong = " << sizeof(ptr) << endl;
}

void test_my_temp_class() {
  cout << "----------test_my_temp_class begin----" << endl;
//    MyTempClass myTempClass1(1, 'c', true);    //不能这样写
//    MyTempClass myTempClass2(2.0, "hello", false);
  MyTempClass<int, char> myTempClass1(1, 'c', true);  //需要这样声明类型
  MyTempClass<double, string> myTempClass2(2.0, "hello", false);
  myTempClass1.show();
  myTempClass2.show();
  /*
a=1	 b=c	 flag=1
a=2	 b=hello	 flag=0
   */
  cout << "----------test_my_temp_class end----" << endl;

}

void test_my_temp_class2() {
  cout << "----------test_my_temp_class2 begin----" << endl;

  MyTempClass_2<int, 10> myclass;
  myclass.put(3);
  myclass.put(6);
  myclass.show();
//3	6	capasity=10  size=2

  MyTempClass_2<double, 20> myclass2(1.1, 3);
  myclass2.put(1.5);
  myclass2.put(1.6);
  myclass2.show();
//1.1	1.1	1.1	1.5	1.6	capasity=20	size=5

  cout << "----------test_my_temp_class2 end----" << endl;

}


void test_virtual_method() {
  Child1019 child1019;
  Base1019 *pbase = &child1019;
  child1019.say();
  pbase->say();
  //hello, base1019
  //hello, base1019   子类没有覆盖，用父类的函数

  shared_ptr<Child1019_override> child_ptr = make_shared<Child1019_override>(1, 2);
  child_ptr->say();
  shared_ptr<Base1019> base_ptr = child_ptr;
  base_ptr->say();    //虚函数，子类覆盖了父类的函数， 即使用智能指针，也是动态绑定
  //this is child override a,b=1,2
  //this is child override a,b=1,2

  pbase->full_virtual_say();
  base_ptr->full_virtual_say();
/*
full virtual child1019
full virtual child1019 override a,b=1,2
 */
}

void test_enum() {
  cout << SUNDAY << "___" << SATRUDAY << endl;  //0___6
//    cout << WeekDaysClass1::SUNDAY << endl;
//    cout << WeekDaysClass2::MONDAY << endl;    //ps :不能直接转化
  cout << static_cast<int>(WeekDaysClass1::SUNDAY) << endl;  //0
  cout << static_cast<int>(WeekDaysClass2::MONDAY) << endl;  //1    //ps: 可以static_cast转int
  cout << "test enum end" << endl;
}


void test_json() {
  string test = "{\"id\":1,\t\n \"name\":\"kurama\"}"; //试试换行可以么?
  Json::Reader reader;
  Json::Value value;

  if (reader.parse(test, value)) {
    if (!value["id"].isNull()) {
      cout << "---id=" << value["id"].asInt() << endl;
      cout << "---name=" << value["name"].asString() << endl;
    }
  }
  cout << "-----------------more test----------" << endl;

  Json::Value root;
  root["name"] = Json::Value("jump");
  root["age"] = Json::Value(10);

  Json::Value child;
  child["c_name"] = Json::Value("c_sky");
  child["hot"] = Json::Value(true);

  root["child"] = Json::Value(child);

  root["li"].append("li_val1");
  root["li"].append("li_val2");
  root["li"].append("li_val3");

  //输出
  cout << "fast writer: " << endl;
  Json::FastWriter fw;
  cout << "---------root:\n" << fw.write(root) << endl;
  /*
      fast writer:
      ---------root:
      {"age":10,"child":{"c_name":"c_sky","hot":true},"li":["li_val1","li_val2","li_val3"],"name":"jump"}
   */

  cout << "styled writer: " << endl;
  Json::StyledWriter sw;
  cout << "--------root:\n" << sw.write(root) << endl;
  /*
      styled writer:
      --------root:
      {
         "age" : 10,
         "child" : {
               "c_name" : "c_sky",
               "hot" : true
         },
         "li" : [ "li_val1", "li_val2", "li_val3"  ],
         "name" : "jump"
  }
   */
  cout << "---test json end---" << endl;
}


#include "Encoder.hh"
#include "Decoder.hh"

void test_avro_decode() {
  std::auto_ptr<avro::OutputStream> out = avro::memoryOutputStream();
  avro::EncoderPtr e = avro::binaryEncoder();
  e->init(*out);
  c::cpx c1;
  c1.re = 1.0;
  c1.im = 2.13;
  avro::encode(*e, c1);

  std::auto_ptr<avro::InputStream> in = avro::memoryInputStream(*out);
  avro::DecoderPtr d = avro::binaryDecoder();
  d->init(*in);

  c::cpx c2;
  avro::decode(*d, c2);
  std::cout << '(' << c2.re << ", " << c2.im << ')' << std::endl;
  return;
}

void test_avro() {
  cout<<"test avro begin---------------"<<endl;
  //std::auto_ptr<avro::OutputStream> out = avro::memoryOutputStream();
  //std::auto_ptr<avro::OutputStream> out = avro::ostreamOutputStream(cerr);
  
  ostringstream oss;

  std::auto_ptr<avro::OutputStream> out = avro::ostreamOutputStream(oss,3);

  avro::EncoderPtr e = avro::binaryEncoder();
  e->init(*out);
  c::cpx c1;
  c1.re = 1.0;
  c1.im = 2.13;
  avro::encode(*e, c1);
  out->flush();
  string tmp=oss.str();
  cout<<"tmp size="<<tmp.size()<<"\n tmp content="<<tmp<<endl;

  std::auto_ptr<avro::InputStream> in = avro::memoryInputStream((const uint8_t*)tmp.c_str(), tmp.size());
  avro::DecoderPtr d = avro::binaryDecoder();
  d->init(*in);
  c::cpx c2;
  avro::decode(*d, c2);
  std::cout << "decode ok-----------------(" << c2.re << ", " << c2.im << ')' << std::endl;
/*
  std::auto_ptr<avro::InputStream> in = avro::memoryInputStream(*out);
  avro::DecoderPtr d = avro::binaryDecoder();
  d->init(*in);

  c::cpx c2;
  avro::decode(*d, c2);
  std::cout << '(' << c2.re << ", " << c2.im << ')' << std::endl;
*/
  cout<<"test avro end---------------"<<endl;
  return;
}

void test_boost_any() {
  boost::any val; 
}

void test_explicit() {
  myclass_4 m_1(1);
  m_1.intro();

  m_1 = 3;   // 隐式转换 m_1 = myclass_4 tmp(3);  
  m_1.intro();

  m_1 = 'c';
  m_1.intro();  // 使用c的ascii码99作为构造函数的值
/*
gouzao myclass_4, x=1
myclass_4 x=1
gouzao myclass_4, x=3  
~myclass_4 x=3     //看样子是先构造了一个临时对象，赋值后，临时对象被析构
myclass_4 x=3
gouzao myclass_4, x=99
~myclass_4 x=99
myclass_4 x=99

 */

  myclass_4_explicit m_2(6);
  m_2.intro();
  //m_2 = 9; //not ok,  explicit 不能隐式转换
  //no known conversion for argument 1 from ‘int’ to ‘myclass_4_explicit&&’
  m_2 = myclass_4_explicit(7);
  m_2.intro();
  /*
gouzao myclass_4_explicit, x=6
myclass_4_explicit x=6
gouzao myclass_4_explicit, x=7
~myclass_4_explicit x=7  //可见也是先构造了一个临时对象，然后赋值,然后析构掉
myclass_4_explicit x=7
~myclass_4_explicit x=7

   */
}

//测试智能制造的循环引用
void test_share_ptr_loop() {
  cout<<"---------test shared ptr loop  begin----------------"<<endl;
  {
    shared_ptr<myclass_4> m4_p = make_shared<myclass_4>(1);
    shared_ptr<myclass_4_explicit> m4_exp_p = make_shared<myclass_4_explicit>(6);
    /*
gouzao myclass_4, x=1
gouzao myclass_4_explicit, x=6
~myclass_4_explicit x=6
~myclass_4 x=1
     */
  }
  cout<<"---------test shared ptr loop  end----------------"<<endl;
}

void test_share_ptr_loop2() {
  cout<<"---------test shared ptr loop2  begin----------------"<<endl;
  {
    shared_ptr<myclass_4> m4_p = make_shared<myclass_4>(1);
    shared_ptr<myclass_4_explicit> m4_exp_p = make_shared<myclass_4_explicit>(6);
    m4_p->set_point(m4_exp_p);
    m4_exp_p->set_point(m4_p);
    //impor : 虽然智能制造可以计数并自动释放对象
    //但是两个指针互相指，导致两个都不能析构
  }
  cout<<"---------test shared ptr loop2  end----------------"<<endl;
  /*
---------test shared ptr loop2  begin----------------
gouzao myclass_4, x=1
gouzao myclass_4_explicit, x=6
---------test shared ptr loop2  end----------------
可见，两个都没有析构
   */
}

void test_bind() {
  sky_space::intro_test();
  sky_space::bind_a_func(3, 'a', 'b');
  std::function<void(int, char, char)> bb_func = sky_space::bind_a_func;
  bb_func(1, 'x', 'y');

  //std::function<void(int, char)> bb_func2 = sky_space::bind_a_func(std::placeholders::_1, 
  auto bb_func2 = std::bind(sky_space::bind_a_func, std::placeholders::_1, 
                            std::placeholders::_2, 'z');
  bb_func2(3, 'c');

  std::function<void(char, int)> bb_func3 = std::bind(sky_space::bind_a_func, std::placeholders::_2, 'a',
                                                      std::placeholders::_1);
  bb_func3('b', 1);

  std::function<void(char)> bb_func4 = std::bind(sky_space::bind_a_func, 3, std::placeholders::_1,
                                                 std::placeholders::_1);
  bb_func4('m');
  /*
hello, ------this is mylibfiles.   sky_space::intro_test()
hello bind_a_test----
a=a  b=b
a=a  b=b
a=a  b=b
hello bind_a_test----
a=x  b=y
hello bind_a_test----
a=c  b=z
a=c  b=z
a=c  b=z
hello bind_a_test----
a=a  b=b
hello bind_a_test----
a=m  b=m
a=m  b=m
a=m  b=m
   */
  myclass_4 mc4(3);
  std::function<void()> b_intro = std::bind(&myclass_4::intro, mc4); //intro 没有参数，后面就不用加参数列表了
  b_intro();
  
  cout<<"test --------------- class func bind"<<endl;
  std::function<int(int)> get_plus = std::bind(&myclass_4::get_plus, mc4, std::placeholders::_1);
//  auto get_plus = std::bind(&myclass_4::get_plus, mc4, std::placeholders::_1);
  int pp1 = get_plus(10);
  assert(pp1 == 13);

  auto get_plus_20 = std::bind(&myclass_4::get_plus, mc4, 20);
  int pp2 = get_plus_20();
  assert(pp2 == 23);
}

void test_lambda() {

  auto f1 = [](){cout<<"hello, world-------this is lambda"<<endl;};
  f1();

  auto f2 = [](){return 111;};
  int a2 = f2();
  assert(a2==111);

  auto f3 = [](int a, int b=1){return a+b;};
  int a3_1 = f3(5);
  int a3_2 = f3(9, -3);
  assert(a3_1==a3_2);

  auto say = [=](){cout<<"a3_1="<<a3_1<<endl;};  //[=] 表示使用外部变量，且拷贝一份传入  (外部的都是只读变量，不能赋值)
  say();
  assert(a3_1==6);

  auto say2 = [&](){a3_1=2000; cout<<"a3_1="<<a3_1<<endl;};
  say2();
  assert(a3_1==2000);

  auto say3 = [a3_1, &a3_2](){a3_2=a3_1; cout<<"change a3_2 to a3_1="<<a3_1<<endl;}; //a3_2引用，可以修改  a3_1拷贝，只读
  say3();
  cout<<"now a3_2="<<a3_2<<"\t a3_1="<<a3_1<<endl;
  assert(a3_2==a3_1);
}    
#include <boost/progress.hpp>  
#include <fstream>  
#include <iterator> 
void test_progress_bar() {
  cout<<"test_progress_bar -------"<<endl;
  std::vector<std::string> v(100);  
  std::ofstream fs("test");  
  boost::progress_display pd(v.size());  
  std::vector<std::string>::iterator pos;  
  for(pos=v.begin();pos!=v.end();++pos) {  
    fs<<*pos<<std::endl;  
    ++pd;  
    sleep(1);  
    cout<<"hello, world"<<endl;
  }  
}
void test_istreambuf() {
  string filepath="../tmpfiles/kafka_source_schema.json";  
    //虽然test1.cpp在工程目录下，但是可执行文件在 build目录下,所以../tmpfiles
  ifstream conf_ifs(filepath);
  string conf_str((istreambuf_iterator<char>(conf_ifs)), istreambuf_iterator<char>());
  cout<<"-------------conf_str---------------------"<<endl;
  cout<<conf_str<<endl;

  Json::Value conf_json;
  Json::Reader reader;
  if(!reader.parse(conf_str, conf_json)) {
    cerr<<"json parse error"<<endl;
  }
  cout<<"type="<<conf_json["type"]<<endl;
  cout<<"type.type="<<typeid(conf_json["type"]).name()<<endl;
  cout<<"fields.type="<<typeid(conf_json["fields"]).name()<<endl;
  
  auto fields_list = conf_json["fields"];
  cout<<"fields_list size="<<fields_list.size()<<endl;

  // auto field0 = fields_list[0];  not ok, i dont know why

  for(const auto &field: fields_list) {
    cout<<"field name="<<field["name"]<<endl;
    cout<<"field type="<<field["type"]<<endl;
  }
  cout<<"------------------may i cout<<json::value------------\n"<<conf_json<<endl; //可以直接输出json

  //for(auto iter=field0.begin(); iter!=field0.end(); ++iter) {
  //  cout<<"fffff"<<endl;
  //}

  cout<<"------------test istreambuf end------------"<<endl;
}

#include <glog/logging.h>
void test_glog()
{
  // yum install glog_devel
  // locate logging.h|grep glog
  // locate glog |grep '\.so'
  //
  // /usr/include/glog/logging.h
  // /usr/lib64/libglog.so        so i add path to cmakefiles.txt
  cout<<"test_glog begin -----------------"<<endl;
  LOG(INFO)<<"hello=====";
  for(int i=1;i<100;++i) {
    LOG_EVERY_N(INFO, 16)<<"i = "<<i;  //1 17 33 49 ...
  }
  cout<<"++++++++++++++++++"<<endl;
  for(int i=1;i<100;++i) {
    LOG_IF_EVERY_N(INFO,(i%5)==0, 3)<<"i = "<<i; //5 20 35 ...
  }
  cout<<"test_glog end -----------------"<<endl;
}

void test_map_and_boost_any() {
  cout<<"test_map_and_boost_any begin------"<<endl;

  unordered_map<int, int> ii_map = {
      {1, 11},
      {9, 99},
  };

  boost::any val = 3;
  cout<<"any val.type="<<val.type().name()<<endl;

  unordered_map<char, boost::any> char_any_map = {
      {'a', (const char*)("const char")},  // important: "***" 不能用这个，会被认为是字符串数组, 需要转为const char*
      {'b', string("string")},
      {'c', 3},
      {'d', 4.1},
      {'e', 5.2f},
  };
  for(auto it=char_any_map.begin(); it!=char_any_map.end(); ++it) {
    cout<<"it->first="<<it->first<<"\t type="<<it->second.type().name()<<endl;
  }
  /*
it->first=e	 type=f     float
it->first=a	 type=PKc   const char*
it->first=b	 type=Ss    string
it->first=c	 type=i     int
it->first=d	 type=d     double
   */
  cout<<"test_map_and_boost_any end------"<<endl;
}

void test_mytemplate_1107() {
  Mytemplate_1107<int> mt;  //既然是模板，必须要说明是int还是说明类型
  mt.temp_add(3, 5);
}
