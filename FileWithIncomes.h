#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include "XmlFile.h"
#include "Markup.h"
#include "Income.h"
#include "AuxiliaryMethods.h"
using namespace std;

class FileWithIncomes : public XmlFile
{
    public:
    FileWithIncomes(string FILEWITHINCOMESNAME) : XmlFile(FILEWITHINCOMESNAME) {};
    void addIncomeToFile(Income income);
};


#endif
