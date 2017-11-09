//
// Created by yaoxing5 on 2017/11/9.
//
#include <iostream>
#include <string>
#include <sstream>
#include <ostream>

#include "test_avro/jdwdata.h"


void test_avro_decode();

int main() {
  std::cout<<"test third.cpp"<<std::endl;
  test_avro_decode();
  return 0;
}



void test_avro_decode() {

  JdwData jdata1;
  jdata1.mid = 123;
  jdata1.db = "db_name";
  jdata1.ddl.set_string("ddl_string");

  auto map = jdata1.src.get_map();
  map["subkey1"].set_string("subval1");
  map["subkey2"].set_null();
  map["subkey3"];
  jdata1.src.set_map(map);

  std::cout<<"subkey1-->"<<map["subkey1"].get_string()<<std::endl;


  std::ostringstream oss;
  std::auto_ptr<avro::OutputStream> out = avro::ostreamOutputStream(oss, 13);   //设置初始buf大小，不足会自动扩张, defalut buf is 1024*8
  avro::EncoderPtr e = avro::binaryEncoder();
  e->init(*out);
  avro::encode(*e, jdata1);
  out->flush();
  std::string serialized_str = oss.str();

  std::cout<<"serialized_str size="<<serialized_str.size()<<"\t content="<<serialized_str<<"~~~"<<std::endl;

  JdwData jdata2;

  auto in = avro::memoryInputStream( (uint8_t*)serialized_str.c_str(), serialized_str.size());
  auto d = avro::binaryDecoder();
  d->init(*in);

  avro::decode(*d, jdata2);

  assert(jdata2.mid==123);
  assert(jdata2.db==jdata1.db);

  assert(!jdata2.src.is_null());
  map = jdata2.src.get_map();
  for(auto item: map){
    std::cout<<"item first="<<item.first<<std::endl;
    if(item.second.is_null()) {
      std::cout<<"------second is null"<<std::endl;
    } else {
      std::cout<<"------second = "<<item.second.get_string()<<std::endl;
    }
  }

  /*
subkey1-->subval1
serialized_str size=65	 content=࣢_nameddl_stringsubkey1subval1subkey2subkey32~~~
item first=subkey1
------second = subval1
item first=subkey2
------second is null
item first=subkey3
------second =
ddl=ddl_string

   */

  std::cout<<"ddl="<<jdata2.ddl.get_string()<<std::endl;
  assert(!jdata2.err.is_null());
  assert(jdata2.err.get_string()=="");  //如果不显示set_null， 会设置为空串

  return;
}