#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

class AuxiliaryMethods
{
    public:
    static char chooseMainMenuOption();
    static char loadChar();
    static char choseUserMenuOption();
    static string convertIntigerToString(int number);
    static int convertStringToIntiger(string number);
    static int convertDateStringToIntegerDate(string dateToConvert);
    static string loadLine();
    static string replaceFirstLetterWithUppercaseAndRestWithLowercase (string text);
    static bool isItTodaysTransaction();
    static int getCurrentDate();
    static int provideDate(int oldestPermittedDate);
    static bool checkIfProvidedDateIsCorrect(string providedDate, int oldestPermittedDate);
    static double provideAmonut();
    static bool checkIfProvidedDoubleIsCorrect(string providedDouble);
    static int getDayFromDate (int date);
    static int getDayFromDate (string date);
    static int getMonthFromDate (int date);
    static int getMonthFromDate (string date);
    static int getYearFromDate (int date);
    static int getYearFromDate (string date);
    static bool checkIfProvidedYearIsCorrect (string providedDate, int oldestPermittedDate);
    static bool checkIfProvidedDateIsCurrentYearDate (string providedDate);
    static bool checkIfProvidedMonthIsCorrect (string providedDate);
    static int checkNumberOfDaysInMonth (int month, int year);
    static bool checkIfProvidedDayIsCorrect (string providedDate);

};


#endif



