#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <ctime>
#include "DateOperations.h"
using namespace std;

class AuxiliaryMethods
{
    public:
    static char chooseMainMenuOption();
    static char loadChar();
    static char choseUserMenuOption();
    static string convertIntigerToString(int number);
    static int convertStringToIntiger(string number);
    static string convertDoubleToString(double number);
    static double convertDoubleIntoDoubleWithTwoDecimalPlaces (double number);
    static string loadLine();
    static string replaceFirstLetterWithUppercaseAndRestWithLowercase (string text);
    static double provideAmonut();


};


#endif



