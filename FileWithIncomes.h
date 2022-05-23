#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include "XmlFile.h"
using namespace std;

class FileWithIncomes : public XmlFile
{
    public:
    FileWithIncomes(string FILEWITHINCOMESNAME) : XmlFile(FILEWITHINCOMESNAME) {};
    void addIncomeToFile();
};


#endif
