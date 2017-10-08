#include <iostream>
#include <vector>
#include <unordered_map>

/*
 * format code    ctrl+alt+L
 * 多行注释 ctrl+/
 */

using namespace std;

void test_string_copy_on_write();

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(5);

    for (auto i: vec)
        cout << i << "_";
    cout << endl;

    test_string_copy_on_write();

    return 0;
}

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
// 我去，说好的写时复制呢
//str1's address: 28febc
//str2's address: 28fea4
//str3's address: 28fe8c