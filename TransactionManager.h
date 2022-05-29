#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <iomanip>
#include "Income.h"
#include "Expense.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "AuxiliaryMethods.h"
#include "DateOperations.h"
using namespace std;

class TransactionManager
{
    vector <Income> incomes;
    vector <Expense> expenses;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    const int LOGGED_USER_ID;
    const int OLDEST_PERMITTED_DATE;



    public:
    TransactionManager(string FIILEWITHINCOMESNAME, string FIILEWITHEXPENSESNAME, int LOGGEDUSERID, int OLDESTPERMITTEDDATE)
    : fileWithIncomes(FIILEWITHINCOMESNAME), fileWithExpenses(FIILEWITHEXPENSESNAME),
    LOGGED_USER_ID(LOGGEDUSERID), OLDEST_PERMITTED_DATE(OLDESTPERMITTEDDATE)
    {
        incomes = fileWithIncomes.loadLoggedUserIncomesFromFile(LOGGEDUSERID);
        expenses = fileWithExpenses.loadLoggedUserExpensesFromFile(LOGGEDUSERID);
    };
    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    //void displaySelectedPeriodBalance();
    vector <Income> getIncomesFromScope(int fromDate, int toDate);
    vector <Expense> getExpensesFromScope(int fromDate, int toDate);
    void displaySortedIncomes(vector <Income> incomesToDisplay);
    void displaySortedExpenses(vector <Expense> expensesToDisplay);
    void displayBalance(vector <Income> userIncomes, vector <Expense> userExpenses);

};


#endif
