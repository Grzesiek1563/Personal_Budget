#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
using namespace std;

class Transaction
{
    int userId;
    int date;
    string item;
    double amount;
    public:
    //GETTERS
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();
    //SETTERS
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);
    bool operator < (const Transaction &x) const
    {
        return date < x.date;
    }

};


#endif
