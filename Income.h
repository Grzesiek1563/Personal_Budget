#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "Transaction.h"
using namespace std;

class Income : public Transaction
{
    int incomeId;
    public:
    int getIncomeId();
    void setIncomeId(int newIncomeId);
};


#endif
