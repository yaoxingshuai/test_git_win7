#include <iostream>
#include <vector>
#include "my_solution.h"

using namespace std;

void test_leetcode_1() {
  vector<int> vec{1,2,10, 11, 19};
  LeetcodeSolution leesove;
  vector<int> ret = leesove.twoSum(vec, 21);
  lee_show_vec_template(ret);
}

int main() {
  cout<<"test leetcode ok"<<endl;
  test_leetcode_1();
  cout<<"test leetcode ok end"<<endl;

}
