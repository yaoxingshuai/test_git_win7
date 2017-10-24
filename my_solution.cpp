//
// Created by skystar on 2017/10/9.
//

#include "my_solution.h"
#include <sstream>

using namespace std;

std::vector<int> my_solution::str2vec(const std::string &s) {
  vector<int> vec;
  stringstream ss(s);
  int tmp;
  while (ss >> tmp) {
    vec.push_back(tmp);
  }
  return vec;
  //ps: 如果要vector<string>也可以用同样的方法，只不过遇到space就会split
}