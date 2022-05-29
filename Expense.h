#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "Transaction.h"

using namespace std;

class Expense : public Transaction
{
    int expenseId;
    public:
    int getExpenseId();
    void setExpenseId(int newExpenseId);
    /*bool operator < (const Expense &x) const
    {
        return date < x.date;
    }*/
};


#endif
