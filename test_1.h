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

void test_mystring();

void test_string();

void test_priority_queue();

void test_pair();

void test_hash();

void test_thread();

void test_extend();

void test_tmp_everything();

void test_str2vec();

void test_time();

void test_default_args(int x, int y, int z = 3);  //默认参数需要放到最右边

void test_player();

void test_throw_exception();

void test_try_catch();

void test_smart_ptr();

void test_smart_ptr2();

void test_json();

void test_make_shared();

void test_kong_class();

void test_my_temp_class();

void test_my_temp_class2();

void test_virtual_method();   //子类必须实现父类的虚函数吗 , 不是必须

void test_enum();

void test_avro_decode();
void test_avro();

void test_boost_any();

void test_explicit(); //如果构造函数只有一个参数，或者除了这个参数都有默认值，则可能隐式转换

void test_share_ptr_loop(); //测试智能制造的循环引用
void test_share_ptr_loop2(); //测试智能制造的循环引用

void test_bind();
void test_lambda();

void test_progress_bar(); //测试c++标准进度条

void test_istreambuf(); //用istreambuf 的iterator读取文件

void test_glog();
#endif //CLION_PRO1_TEST_1_H



//#############################
//# cpx.hh
//#############################
#ifndef CPX_HH_1278398428__H_
#define CPX_HH_1278398428__H_

#include "boost/any.hpp"
#include "Specific.hh"
#include "Encoder.hh"
#include "Decoder.hh"

namespace c {
  struct cpx {
    double re;
    double im;
  };

}
namespace avro {
  template<>
  struct codec_traits<c::cpx> {
    static void encode(Encoder &e, const c::cpx &v) {
      avro::encode(e, v.re);
      avro::encode(e, v.im);
    }

    static void decode(Decoder &d, c::cpx &v) {
      avro::decode(d, v.re);
      avro::decode(d, v.im);
    }
  };

}
#endif

