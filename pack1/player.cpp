//
// Created by sky on 2017/10/17.
//

#include "player.h"
#include <iostream>

using namespace std;


TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) {
    first_name = fn;
    last_name = ln;
    has_table = ht;
}

void TableTennisPlayer::Name() const {
    cout << "hello: " << first_name << "___" << last_name << endl;
}


//RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht) {
//    rating=r;
//    TableTennisPlayer(fn, ln, ht);
//}

RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht) :
        TableTennisPlayer(fn, ln, ht), rating(r) {

}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp) :
        TableTennisPlayer(tp) {
    rating = r;
}

