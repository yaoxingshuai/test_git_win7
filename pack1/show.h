//
// Created by skystar on 2017/10/9.
//

#ifndef TEST_GIT_WIN7_SHOW_H
#define TEST_GIT_WIN7_SHOW_H

#include <vector>
#include <iostream>


class Show_Solution {
public:
    template <class T>
    void show_vec_template(const std::vector<T> &vec)
    {
        for (const auto x : vec)
            std::cout << x << "_";
        std::cout << std::endl;
    }

    template <class T>
    void show_vec_template_2(const std::vector<T> &vec);

    void show_vec(const std::vector<int> &vec);
};


#endif //TEST_GIT_WIN7_SHOW_H
