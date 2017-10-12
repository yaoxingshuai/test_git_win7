//
// Created by sky on 2017/10/12.
//

#ifndef TEST_GIT_WINDOWS_MYSTRING_H
#define TEST_GIT_WINDOWS_MYSTRING_H

#include <ostream>
#include <istream>

class Mystring {
private:
    char *str;
    int len;
    static int num_strings;
    static const int CIN_LIMIT = 80;
public:
    Mystring(const char *);

    Mystring();

    Mystring(const Mystring &);

    ~Mystring();

    int length() const { return len; };

    Mystring &operator=(const Mystring &);

    Mystring &operator=(const char *);

    char &operator[](int i);

    const char &operator[](int i) const;

    friend bool operator<(const Mystring &s1, const Mystring &s2);

//    bool operator< ( const Mystring &s2) const
//    {
//        return strcmp(this->str, s2.str) < 0;
//    }

    friend bool operator>(const Mystring &s1, const Mystring &s2);

    friend bool operator==(const Mystring &s1, const Mystring &s2);

    friend std::ostream &operator<<(std::ostream &os, const Mystring &s);

    friend std::istream &operator<<(std::istream &is, Mystring &s);
    static int HowMany();
};


#endif //TEST_GIT_WINDOWS_MYSTRING_H
