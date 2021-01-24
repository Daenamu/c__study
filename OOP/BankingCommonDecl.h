#ifndef __BANKING__COMMON_H__
#define __BANKING__COMMON_H__

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int NAME_LEN = 20;

enum { // 선택 메뉴
    MAKE = 1,
    DEPOSIT,
    WITHDRAW,
    INQUIRE,
    EXIT
};

enum { // 신용 등급
    LEVEL_A = 7,
    LEVEL_B = 4,
    LEVEL_C = 2
};

enum { // 계좌의 종류
    NORMAL = 1,
    CREDIT = 2
};

#endif