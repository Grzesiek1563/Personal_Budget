#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include "XmlFile.h"
#include "Markup.h"
#include "Income.h"
#include "AuxiliaryMethods.h"
using namespace std;

class FileWithIncomes : public XmlFile
{
    int lastIncomeId;
    public:
    FileWithIncomes(string FILEWITHINCOMESNAME) : XmlFile(FILEWITHINCOMESNAME)
    {
        lastIncomeId = 0;
    };
    void addIncomeToFile(Income income);
    vector <Income> loadLoggedUserIncomesFromFile(int loggedUserId);
    int getLastIncomeId();
};


#endif
