//
// Created by stardan on 2017/10/8.
//

#ifndef CLION_PRO1_MYSTRUCT_H
#define CLION_PRO1_MYSTRUCT_H


class mystruct_1 {
public:
    int _x, _y;
    mystruct_1(){_x=1; _y=2;};
    mystruct_1(int x, int y): _x(x), _y(y){}
    ~mystruct_1();
};


#endif //CLION_PRO1_MYSTRUCT_H
