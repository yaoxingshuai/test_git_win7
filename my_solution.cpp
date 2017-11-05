//
// Created by skystar on 2017/10/9.
//

#include "my_solution.h"
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <glog/logging.h>

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

/*
 *    ps: 不知道为什么，放这里就不能用，必须要放到my_solution.h中才可以，不能分开
 *    但是模板不可以， 直接定义lee_show_vec就行
template<class T>
void lee_show_vec_template(const std::vector<T> &vec, const string& split) {
  for(const T& t: vec)
    cout<<t<<split;
  cout<<endl;
}
*/
void lee_show_vec(const std::vector<int> &vec, const string& split) {
  for(const int& i: vec)
    cout<<i<<split;
  cout<<endl;
}

// ps: 不知道为什么， template必须要放在.h中，但是这个又必须放在.cpp中，恶心
void lee_show_listnode(ListNode *first) {
  while(first != nullptr) {
    cout<<first->val<<"_";
    first = first->next;
  }
  cout<<endl;
}

vector<int> LeetcodeSolution::twoSum(vector<int> &nums, int target) {
  vector<int> ret;
  unordered_map<int, int> idx_num_map;
  for(int idx=0; idx<nums.size(); ++idx) {
    auto it = idx_num_map.find(target-nums[idx]);
    if(it==idx_num_map.end()) {
      idx_num_map[nums[idx]] = idx; 
    } else {
      ret.push_back(it->second);
      ret.push_back(idx);
      break;
    }
  }
  return ret;
}

ListNode* LeetcodeSolution::addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode *head=nullptr, *index=nullptr;    //ps: important   一定要初始化，不然 head != nullptr
  LOG(INFO)<<"head is null?"<<(head== nullptr);

  int jinwei = 0;
  ListNode *p1=l1, *p2=l2;
  while((p1 != nullptr) || (p2 != nullptr) || (jinwei != 0)) {
    int num = 0;
    if(p1 != nullptr) {
      num += p1->val;
      p1 = p1->next;
    }
    if(p2 != nullptr) {
      num += p2->val;
      p2 = p2->next;
    }
    num += jinwei;
    ListNode *tmp = new ListNode(num%10);
    if(head == nullptr) {
      head = tmp;
      index = tmp;
    } else {
      index->next = tmp;
      index = tmp;
    }
    jinwei = num/10;
  }
  return head;
}
