#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include "AuxiliaryMethods.h"
#include "Markup.h"
using namespace std;

class XmlFile
{
    const string FILE_NAME;
    public:
    XmlFile(string fileName) : FILE_NAME(fileName) {};
    string getFileName()
    {
        return FILE_NAME;
    }
    bool isTheFileEmpty();
};


#endif

