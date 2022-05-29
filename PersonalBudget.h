#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "AuxiliaryMethods.h"
#include "DateOperations.h"
#include "UserManager.h"
#include "TransactionManager.h"
using namespace std;

class PersonalBudget
{
    UserManager userManager;
    TransactionManager *transactionManager;
    const string FILE_WITH_INCOMES_NAME;
    const string FILE_WITH_EXPENSES_NAME;
    int OLDEST_PERMITTED_DATE;

    public:
    PersonalBudget(string FILEWITHUSERSNAME, string FILEWITHINCOMESNAME, string FILEWITHEXPENSESNAME, string OLDESTPERMITTEDDATE)
    : userManager(FILEWITHUSERSNAME), FILE_WITH_INCOMES_NAME(FILEWITHINCOMESNAME), FILE_WITH_EXPENSES_NAME(FILEWITHEXPENSESNAME),
    OLDEST_PERMITTED_DATE(DateOperations::convertDateStringToIntegerDate(OLDESTPERMITTEDDATE))
    {
        transactionManager = NULL;
    };
    ~PersonalBudget()
    {
        delete transactionManager;
        transactionManager = NULL;
    }

    bool isTheUserLoggedIn ();
    void userRegistration();
    int userLogIn();
    int userLogOut();
    void changeLoggedUserPassword();
    void addIncome();
    void addExpense();
    int getOldestPermittedDate();
    void displayCurrentMonthBalance();


};

#endif


