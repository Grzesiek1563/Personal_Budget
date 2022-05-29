#include "DateOperations.h"

int DateOperations::provideDate(int oldestPermittedDate)
{
    string providedDate;
    int convertedDate;
    bool providedDateIsCorrect = false;
    const int CORRECT_NUMBER_OF_CHARACTERS_IN_DATE = 10;
    int numberOfCharactersInProvidedDate = 0;
    cout << "Wprowadz date w formacie rrrr-mm-dd (max 2000-01-01): ";
    while (true)
    {
        providedDate = AuxiliaryMethods::loadLine();
        numberOfCharactersInProvidedDate = providedDate.length();
        if(numberOfCharactersInProvidedDate == CORRECT_NUMBER_OF_CHARACTERS_IN_DATE)
        {
            providedDateIsCorrect = DateOperations::checkIfProvidedDateIsCorrect(providedDate, oldestPermittedDate);
            if (providedDateIsCorrect)
                break;
        }
        cout << endl << "Wprowadzono niepoprawna date. Sprobuj ponownie: ";
    }
    convertedDate = DateOperations::convertDateStringToIntegerDate(providedDate);
    return convertedDate;
}


bool DateOperations::isItTodaysTransaction()
{
    char choice;
    cout << "Czy transakcja dotyczy dnia dzisiejszego? Y/N: ";
    while (true)
    {
        choice = AuxiliaryMethods::loadChar();
        if(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
            break;
        cout << endl << "Wprowadzono nieprawidlowy znak. Sprobuj ponownie: ";
    }
    if(choice == 'y' || choice == 'Y')
        return true;
    else
        return false;
}

int DateOperations::getCurrentDate()
{
    string currentDate;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char date_string[50];
    strftime(date_string, 50, "%Y-%m-%d", ltm);
    currentDate = date_string;
    int convertedDate = DateOperations::convertDateStringToIntegerDate(currentDate);
    return convertedDate;
}

int DateOperations::getDayFromDate (int date)
{
    string fullDate = AuxiliaryMethods::convertIntigerToString(date);
    string day = fullDate.substr(6,2);
    int convertedDay = AuxiliaryMethods::convertStringToIntiger(day);
    return convertedDay;
}

int DateOperations::getDayFromDate (string date)
{
    string day = date.substr(8,2);
    int convertedDay = AuxiliaryMethods::convertStringToIntiger(day);
    return convertedDay;
}

int DateOperations::getMonthFromDate (int date)
{
    string fullDate = AuxiliaryMethods::convertIntigerToString(date);
    string month = fullDate.substr(4,2);
    int convertedMonth = AuxiliaryMethods::convertStringToIntiger(month);
    return convertedMonth;
}

int DateOperations::getMonthFromDate (string date)
{
    string month = date.substr(5,2);
    int convertedMonth = AuxiliaryMethods::convertStringToIntiger(month);
    return convertedMonth;
}

int DateOperations::getYearFromDate (int date)
{
    string fullDate = AuxiliaryMethods::convertIntigerToString(date);
    string year = fullDate.substr(0,4);
    int convertedYear = AuxiliaryMethods::convertStringToIntiger(year);
    return convertedYear;
}

int DateOperations::getYearFromDate (string date)
{
    string year = date.substr(0,4);
    int convertedYear = AuxiliaryMethods::convertStringToIntiger(year);
    return convertedYear;
}

bool DateOperations::checkIfProvidedYearIsCorrect (string providedDate, int oldestPermittedDate)
{
    bool providedYearIsCorrect = false;
    int providedYear = DateOperations::getYearFromDate(providedDate);
    int oldestPermittedYear = DateOperations::getYearFromDate(oldestPermittedDate);
    int currentYear = DateOperations::getYearFromDate(DateOperations::getCurrentDate());
    if(providedYear >= oldestPermittedYear && providedYear <= currentYear)
    {
        providedYearIsCorrect = true;
    }
    return providedYearIsCorrect;
}

bool DateOperations::checkIfProvidedDateIsCurrentYearDate (string providedDate)
{
    int currentYear = DateOperations::getYearFromDate(DateOperations::getCurrentDate());
    int providedYear = DateOperations::getYearFromDate(providedDate);
    if(currentYear == providedYear)
        return true;
    else
        return false;
}

bool DateOperations::checkIfProvidedMonthIsCorrect (string providedDate)
{
    bool providedMonthIsCorrect = false;
    bool itIsCurrentYear = DateOperations::checkIfProvidedDateIsCurrentYearDate(providedDate);
    int providedMonth = DateOperations::getMonthFromDate(providedDate);
    if(itIsCurrentYear)
    {
        int currentMonth = DateOperations::getMonthFromDate(DateOperations::getCurrentDate());
        if (providedMonth >= 1 && providedMonth <= currentMonth)
            providedMonthIsCorrect = true;
    }
    else
    {
        if (providedMonth >= 1 && providedMonth <= 12)
            providedMonthIsCorrect = true;
    }
    return providedMonthIsCorrect;
}

int DateOperations::checkNumberOfDaysInMonth (int month, int year)
{
    int numberOfDaysInMonth = 0;
    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            numberOfDaysInMonth = 31;
        break;
        case 4: case 6: case 9: case 11:
            numberOfDaysInMonth = 30;
        break;
        case 2:
        {
            if (((year%4==0)&&(year%100!=0))||(year%400==0))
            numberOfDaysInMonth = 29;
            else
            numberOfDaysInMonth = 28;
        }
        break;
    }
    return numberOfDaysInMonth;
}

bool DateOperations::checkIfProvidedDayIsCorrect (string providedDate)
{
    bool providedDayIsCorrect = false;
    bool itIsCurrentYear = DateOperations::checkIfProvidedDateIsCurrentYearDate(providedDate);
    int providedMonth = DateOperations::getMonthFromDate(providedDate);
    int providedDay = DateOperations::getDayFromDate(providedDate);
    int currentDay = DateOperations::getDayFromDate(DateOperations::getCurrentDate());
    if(itIsCurrentYear)
    {
        if(providedDay >=1 && providedDay <= currentDay)
            providedDayIsCorrect = true;
    }
    else
    {
        int providedYear = DateOperations::getYearFromDate(providedDate);
        int numberOfDaysInProvidedMonth = DateOperations::checkNumberOfDaysInMonth(providedMonth, providedYear);
        if (providedDay >=1 && providedDay <= numberOfDaysInProvidedMonth)
            providedDayIsCorrect = true;
    }
    return providedDayIsCorrect;
}

bool DateOperations::checkIfProvidedDateIsCorrect(string providedDate, int oldestPermittedDate)
{
    bool providedYearIsCorrect = DateOperations::checkIfProvidedYearIsCorrect(providedDate, oldestPermittedDate);
    bool providedMonthIsCorrect = DateOperations::checkIfProvidedMonthIsCorrect(providedDate);
    bool providedDayIsCorrect = DateOperations::checkIfProvidedDayIsCorrect(providedDate);
    if (providedDayIsCorrect && providedMonthIsCorrect && providedYearIsCorrect)
        return true;
    else
        return false;
}

int DateOperations::convertDateStringToIntegerDate(string dateToConvert)
{
    string year = dateToConvert.substr(0,4);
    string month = dateToConvert.substr(5,2);
    string day = dateToConvert.substr(8,2);
    string fullDate = year + month + day;
    int convertedDate = AuxiliaryMethods::convertStringToIntiger(fullDate);
    return convertedDate;
}

string DateOperations::convertIntegerDateToStringDate(int dateToConvert)
{
    string providedDate = AuxiliaryMethods::convertIntigerToString(dateToConvert);
    string convertedDate = providedDate.substr(0,4) + '-' + providedDate.substr(4,2) + '-' + providedDate.substr(6,2);
    return convertedDate;
}

int DateOperations::getFirstDayOfCurrentMonthDate()
{
    int firstDayOfCurrentMonthDate;
    string firstDayOfCurrentMonthDateAsString = "";
    const string firstDayOfMonth = "01";

    int currentDate = DateOperations::getCurrentDate();
    string currentDateAsString = AuxiliaryMethods::convertIntigerToString(currentDate);
    firstDayOfCurrentMonthDateAsString = currentDateAsString.substr(0,4) + '-' + currentDateAsString.substr(4,2) + '-' + firstDayOfMonth;
    firstDayOfCurrentMonthDate = DateOperations::convertDateStringToIntegerDate(firstDayOfCurrentMonthDateAsString);
    return firstDayOfCurrentMonthDate;
}


int DateOperations::getFirstDayOfPreviousMonthDate()
{
    string firstDayOfPreviousMonthDateAsString = "";
    int firstDayOfPreviousMonthDate;
    string previousMonthAsString = "";
    int previousMonth, calculatedYear;
    string currentDate = AuxiliaryMethods::convertIntigerToString(DateOperations::getCurrentDate());
    int currentYear = AuxiliaryMethods::convertStringToIntiger(currentDate.substr(0,4));
    int currentMonth = AuxiliaryMethods::convertStringToIntiger(currentDate.substr(4,2));
    if (currentMonth == 1)
    {
        previousMonth = 12;
        calculatedYear = currentYear - 1;
    }
    else
    {
        previousMonth = currentMonth - 1;
        calculatedYear = currentYear;
    }
    if (previousMonth < 10)
        previousMonthAsString = '0' + AuxiliaryMethods::convertIntigerToString(previousMonth);
    else
        previousMonthAsString = AuxiliaryMethods::convertIntigerToString(previousMonth);

    firstDayOfPreviousMonthDateAsString = AuxiliaryMethods::convertIntigerToString(calculatedYear) + previousMonthAsString + "01";
    firstDayOfPreviousMonthDate = AuxiliaryMethods::convertStringToIntiger(firstDayOfPreviousMonthDateAsString);
    return firstDayOfPreviousMonthDate;
}

int DateOperations::getLastDayOfPreviousMonthDate()
{
    string lastDayOfPreviousMonthDateAsString = "";
    int lastDayOfPreviousMonthDate;
    string firstDayOfPreviousMonthDate = AuxiliaryMethods::convertIntigerToString(DateOperations::getFirstDayOfPreviousMonthDate());
    string previousMonthAsString = firstDayOfPreviousMonthDate.substr(4,2);
    string yearOfPreviousMonth = firstDayOfPreviousMonthDate.substr(0,4);
    int previousMonth = AuxiliaryMethods::convertStringToIntiger(previousMonthAsString);
    int year = AuxiliaryMethods::convertStringToIntiger(yearOfPreviousMonth);
    int numberOfDaysInPreviousMonth = checkNumberOfDaysInMonth(previousMonth, year);
    lastDayOfPreviousMonthDateAsString = yearOfPreviousMonth + previousMonthAsString + AuxiliaryMethods::convertIntigerToString(numberOfDaysInPreviousMonth);
    lastDayOfPreviousMonthDate = AuxiliaryMethods::convertStringToIntiger(lastDayOfPreviousMonthDateAsString);
    return lastDayOfPreviousMonthDate;
}
