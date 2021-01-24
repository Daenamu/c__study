#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account {
private:
    int accID;
    int balance;
    String cusName;
public:
    Account(int ID, int money, String name);
    int GetAccID() const;
    virtual void Deposit(int money);
    int WithDraw(int money);
    void ShowAccInfo() const;
};

#endif