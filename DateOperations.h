#ifndef DATEOPERATIONS_H
#define DATEOPERATIONS_H

#include <iostream>
#include "AuxiliaryMethods.h"

using namespace std;

class DateOperations
{
    public:
    static int provideDate(int oldestPermittedDate);
    static int convertDateStringToIntegerDate(string dateToConvert);
    static bool isItTodaysTransaction();
    static int getCurrentDate();
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
    static bool checkIfProvidedDateIsCorrect(string providedDate, int oldestPermittedDate);

};




#endif
