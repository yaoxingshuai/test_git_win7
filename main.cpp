#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    for (auto i: vec)
        cout<<i<<"_";
    cout<<endl;
    return 0;
}
