#include <iostream>
#include <vector>
#include "my_solution.h"

using namespace std;

void test_leetcode_1() {
  vector<int> vec{1, 2, 10, 11, 19};
  LeetcodeSolution leesove;
  vector<int> ret = leesove.twoSum(vec, 21);
  lee_show_vec_template(ret);
  lee_show_vec(ret);
}

void test_leedcode_2() {
  ListNode *m3 = new ListNode(3);
  ListNode *m2 = new ListNode(4, m3);
  ListNode *m1 = new ListNode(2, m2);

  ListNode *n3 = new ListNode(4);
  ListNode *n2 = new ListNode(6, n3);
  ListNode *n1 = new ListNode(5, n2);

  lee_show_listnode(m1);
  lee_show_listnode(n1);

  LeetcodeSolution solve;
  ListNode *ret = solve.addTwoNumbers(m1, n1);
  while (ret != nullptr) {
    cout << ret->val << "_";
    ret = ret->next;
  }
  cout << endl;
}

int main() {
  cout << "test leetcode ok" << endl;
  cout << "test leetcode 1----------" << endl;
  test_leetcode_1();
  cout << "test leetcode 2----------" << endl;
  test_leedcode_2();
  cout << "test leetcode ok end" << endl;

}
