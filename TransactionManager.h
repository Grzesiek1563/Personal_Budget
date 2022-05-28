#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "Income.h"
#include "Expense.h"
#include "FileWithIncomes.h"
#include "AuxiliaryMethods.h"
#include "DateOperations.h"
using namespace std;

class TransactionManager
{
    vector<Income> incomes;
    FileWithIncomes fileWithIncomes;
    const int LOGGED_USER_ID;
    const int OLDEST_PERMITTED_DATE;



    public:
    TransactionManager(string FIILEWITHINCOMESNAME, int LOGGEDUSERID, int OLDESTPERMITTEDDATE)
    : fileWithIncomes(FIILEWITHINCOMESNAME), LOGGED_USER_ID(LOGGEDUSERID), OLDEST_PERMITTED_DATE(OLDESTPERMITTEDDATE)
    {
        incomes = fileWithIncomes.loadLoggedUserIncomesFromFile(LOGGEDUSERID);

    };
    void addIncome();


    void wyswietl();

};


#endif
