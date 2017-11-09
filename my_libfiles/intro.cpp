#include "intro.h"

#include <iostream>

using namespace std;

void sky_space::intro_test() {
  cout << "hello, ------this is mylibfiles.   sky_space::intro_test()" << endl;
  cout << "hello, test make" << endl;
}

void sky_space::bind_a_func(int x, char a, char b) {
  cout << "hello bind_a_test----" << endl;
  for (int i = 0; i < x; ++i) {
    cout << "a=" << a << "\t b=" << b << endl;
  }
}

