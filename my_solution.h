//
// Created by skystar on 2017/10/9.
//

#ifndef TEST_GIT_WIN7_MY_SOLUTION_H
#define TEST_GIT_WIN7_MY_SOLUTION_H


class my_solution {
public:
    template <class T>
    inline const T& mymax(const T&a, const T&b)
    {
        return a>b?a:b;
    }

    template <class T>
    inline void myswap(T&a, T&b)
    {
        T tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
};


#endif //TEST_GIT_WIN7_MY_SOLUTION_H
