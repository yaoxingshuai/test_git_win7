//
// Created by yaoxing5 on 2017/11/9.
//
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>

void test_split();
void test_lower_bound();

int main() {
  test_split();
  test_lower_bound();
  return 0;
}

void test_split() {
  std::cout<<"test_split  begin-----------"<<std::endl;
  std::string sss("asosdf asdf weof  sdf    asdf");
  std::vector<std::string> vec;
  boost::split(vec, sss, boost::is_any_of(" "));
  for(const std::string &s: vec) {
    std::cout<<"~"<<s<<"~"<<std::endl;
  }
  /*
~asosdf~
~asdf~
~weof~
~~
~sdf~
~~
~~
~~
~asdf~
   */
  std::cout<<"-----------------------"<<std::endl;

  std::sort(vec.begin(), vec.end());
  for(const std::string &s: vec) {
    std::cout<<"~"<<s<<"~"<<std::endl;
  }
  std::cout<<"-----------------------"<<std::endl;
  /*
~~
~~
~~
~~
~asdf~
~asdf~
~asosdf~
~sdf~
~weof~
   */

  auto iter1 = std::lower_bound(vec.begin(), vec.end(), "asdf");
  while(iter1!=vec.end()) {
    std::cout<<"~"<<*iter1<<"~"<<std::endl;
    ++iter1;
  }
  std::cout<<"-----------------------"<<std::endl;
  /*
~asdf~
~asdf~
~asosdf~
~sdf~
~weof~
   */

  auto iter2 = std::upper_bound(vec.begin(), vec.end(), "asdf");
  while(iter2!=vec.end()) {
    std::cout<<"~"<<*iter2<<"~"<<std::endl;
    ++iter2;
  }
  std::cout<<"-----------------------"<<std::endl;
/*
~asosdf~
~sdf~
~weof~
 */


  std::cout<<"test_split  end-----------"<<std::endl;
}

void test_lower_bound() {

  std::vector<std::pair<int, char>> pair_vec;
  pair_vec.push_back(std::pair<int, char>(1, 'a'));
  pair_vec.push_back(std::pair<int, char>(2, 'e'));
  pair_vec.push_back(std::pair<int, char>(5, 'c'));
  pair_vec.push_back(std::pair<int, char>(4, 'z'));
  pair_vec.push_back(std::pair<int, char>(3, 'h'));

  std::sort(pair_vec.begin(), pair_vec.end(), [](const std::pair<int, char>& x, const std::pair<int, char>& y){return x.first<y.first;});

  for(const auto item: pair_vec) {
    std::cout<<item.first<<"\t"<<item.second<<std::endl;
  }
  /*
1	a
2	e
3	h
4	z
5	c
   */

  std::cout<<"1-----------------------"<<std::endl;




  std::sort(pair_vec.begin(), pair_vec.end(), [](const std::pair<int, char>& x, const std::pair<int, char>& y){return x.second<y.second;});
  for(const auto &item: pair_vec) {
    std::cout<<item.first<<"\t"<<item.second<<std::endl;
  }
  /*
1	a
5	c
2	e
3	h
4	z
   */
  std::cout<<"2-----------------------"<<std::endl;

  auto it1 = std::lower_bound(pair_vec.begin(), pair_vec.end(), 'e', [](const std::pair<int, char>& item, const char& c) { return item.second < c;});
  while(it1!=pair_vec.end()) {
    std::cout<<it1->first<<"\t"<<it1->second<<std::endl;
    ++it1;
  }
  /*
2	e
3	h
4	z
   */
  std::cout<<"3-----------------------"<<std::endl;

  //it1 = std::upper_bound(pair_vec.begin(), pair_vec.end(), 'e', [](const std::pair<int, char>& item, const char& c) { return item.second < c;});
  it1 = std::upper_bound(pair_vec.begin(), pair_vec.end(), 'e', [](const char& c, const std::pair<int, char>& item) { return c<item.second;});   //important: 不知道为啥，需要把位置反过来
  while(it1!=pair_vec.end()) {
    std::cout<<it1->first<<"\t"<<it1->second<<std::endl;
    ++it1;
  }
  /*
3	h
4	z
   */
  std::cout<<"4-----------------------"<<std::endl;

//  it1 = std::lower_bound(pair_vec.begin(), pair_vec.end(), 'e', [](const char& c, const std::pair<int, char>& item) { return c<item.second;});   //not ok, 必须[](pair, char) {}

}
