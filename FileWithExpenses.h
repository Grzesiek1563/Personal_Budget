#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include "XmlFile.h"
#include "Markup.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "DateOperations.h"
using namespace std;

class FileWithExpenses : public XmlFile
{
    int lastExpenseId;
    public:
    FileWithExpenses(string FILEWITHEXPENSESNAME) : XmlFile(FILEWITHEXPENSESNAME)
    {
        lastExpenseId = 0;
    };
    void addExpenseToFile(Expense expense);
    vector <Expense> loadLoggedUserExpensesFromFile(int loggedUserId);
    int getLastExpenseId();
};

#endif
