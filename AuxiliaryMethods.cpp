#include "AuxiliaryMethods.h"

char AuxiliaryMethods::chooseMainMenuOption()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

char AuxiliaryMethods::loadChar()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}


char AuxiliaryMethods::choseUserMenuOption()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    //cout << "2. Dodaj wydatek" << endl;
    //cout << "3. Bilans z biezacego miesiaca" << endl;
    //cout << "4. Bilans z poprzedniego miesiaca" << endl;
    //cout << "5. Bilans z wybranego okresu" << endl;
    //cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

string AuxiliaryMethods::convertIntigerToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToIntiger(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AuxiliaryMethods::loadLine()
{
    string input = "";
    getline(cin, input);
    return input;
}


int AuxiliaryMethods::convertDateStringToIntegerDate(string dateToConvert)
{
    string year = dateToConvert.substr(0,4);
    string month = dateToConvert.substr(5,2);
    string day = dateToConvert.substr(8,2);
    string fullDate = year + month + day;
    int convertedDate = AuxiliaryMethods::convertStringToIntiger(fullDate);
    return convertedDate;
}


string AuxiliaryMethods::replaceFirstLetterWithUppercaseAndRestWithLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

bool AuxiliaryMethods::isItTodaysTransaction()
{
    char choice;
    cout << "Czy przychod dotyczy dnia dzisiejszego? Y/N: ";
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


int AuxiliaryMethods::getCurrentDate()
{
    string currentDate;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char date_string[50];
    strftime(date_string, 50, "%Y-%m-%d", ltm);
    currentDate = date_string;
    int convertedDate = AuxiliaryMethods::convertDateStringToIntegerDate(currentDate);
    return convertedDate;
}

int AuxiliaryMethods::provideDate(int oldestPermittedDate)
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
            providedDateIsCorrect = AuxiliaryMethods::checkIfProvidedDateIsCorrect(providedDate, oldestPermittedDate);
            if (providedDateIsCorrect)
                break;
        }
        cout << endl << "Wprowadzono niepoprawna date. Sprobuj ponownie: ";
    }
    convertedDate = AuxiliaryMethods::convertDateStringToIntegerDate(providedDate);
    return convertedDate;
}

double AuxiliaryMethods::provideAmonut()
{
    string amount = "";
    string providedAmount;
    double convertedAmount;
    bool providedAmountIsCorrect;
    cout << endl << "Podaj kwote transakcji: ";
    while(true)
    {
        cin >> providedAmount;
        providedAmountIsCorrect = AuxiliaryMethods::checkIfProvidedDoubleIsCorrect(providedAmount);
        if(providedAmountIsCorrect)
        {
            for(int i = 0; i < providedAmount.length(); i++)
            {
                if (providedAmount[i] == ',')
                    amount += '.';
                else
                    amount += providedAmount[i];
            }
            break;
        }
        cout << endl << "Wprowadziles niepoprawna kwote. Sprobuj ponownie: ";
    }
    convertedAmount = stod(amount);
    return convertedAmount;
}


bool AuxiliaryMethods::checkIfProvidedDoubleIsCorrect (string providedDouble)
{
    int dotsAndCommasCount = 0;
    bool providedDoubleIsCorrect = true;
    int commaAsciiNumber = 44;
    int dotAsciiNumber = 46;
    int characterAsciiNumber;
    for (int i = 0; i < providedDouble.length(); i++)
    {
        characterAsciiNumber = (int)providedDouble[i];
        if (i == 0)
        {
            if(characterAsciiNumber < 49 || characterAsciiNumber > 57)
                providedDoubleIsCorrect = false;
        }
        else
        {
            if((characterAsciiNumber < 48 || characterAsciiNumber > 57) && characterAsciiNumber != dotAsciiNumber && characterAsciiNumber != commaAsciiNumber)
                providedDoubleIsCorrect = false;
            else if (characterAsciiNumber == dotAsciiNumber || characterAsciiNumber == commaAsciiNumber)
                dotsAndCommasCount++;
        }
        if(dotsAndCommasCount > 1)
        {
            providedDoubleIsCorrect = false;
        }
    }
    return providedDoubleIsCorrect;
}




//TUTAJ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


int AuxiliaryMethods::getDayFromDate (int date)
{
    string fullDate = AuxiliaryMethods::convertIntigerToString(date);
    string day = fullDate.substr(6,2);
    int convertedDay = AuxiliaryMethods::convertStringToIntiger(day);
    return convertedDay;
}

int AuxiliaryMethods::getDayFromDate (string date)
{
    string day = date.substr(8,2);
    int convertedDay = AuxiliaryMethods::convertStringToIntiger(day);
    return convertedDay;
}

int AuxiliaryMethods::getMonthFromDate (int date)
{
    string fullDate = AuxiliaryMethods::convertIntigerToString(date);
    string month = fullDate.substr(4,2);
    int convertedMonth = AuxiliaryMethods::convertStringToIntiger(month);
    return convertedMonth;
}

int AuxiliaryMethods::getMonthFromDate (string date)
{
    string month = date.substr(5,2);
    int convertedMonth = AuxiliaryMethods::convertStringToIntiger(month);
    return convertedMonth;
}

int AuxiliaryMethods::getYearFromDate (int date)
{
    string fullDate = AuxiliaryMethods::convertIntigerToString(date);
    string year = fullDate.substr(0,4);
    int convertedYear = AuxiliaryMethods::convertStringToIntiger(year);
    return convertedYear;
}

int AuxiliaryMethods::getYearFromDate (string date)
{
    string year = date.substr(0,4);
    int convertedYear = AuxiliaryMethods::convertStringToIntiger(year);
    return convertedYear;
}

bool AuxiliaryMethods::checkIfProvidedYearIsCorrect (string providedDate, int oldestPermittedDate)
{
    bool providedYearIsCorrect = false;
    int providedYear = AuxiliaryMethods::getYearFromDate(providedDate);
    int oldestPermittedYear = AuxiliaryMethods::getYearFromDate(oldestPermittedDate);
    int currentYear = AuxiliaryMethods::getYearFromDate(AuxiliaryMethods::getCurrentDate());
    if(providedYear >= oldestPermittedYear && providedYear <= currentYear)
    {
        providedYearIsCorrect = true;
    }
    return providedYearIsCorrect;
}

bool AuxiliaryMethods::checkIfProvidedDateIsCurrentYearDate (string providedDate)
{
    int currentYear = AuxiliaryMethods::getYearFromDate(AuxiliaryMethods::getCurrentDate());
    int providedYear = AuxiliaryMethods::getYearFromDate(providedDate);
    if(currentYear == providedYear)
        return true;
    else
        return false;
}

bool AuxiliaryMethods::checkIfProvidedMonthIsCorrect (string providedDate)
{
    bool providedMonthIsCorrect = false;
    bool itIsCurrentYear = AuxiliaryMethods::checkIfProvidedDateIsCurrentYearDate(providedDate);
    int providedMonth = AuxiliaryMethods::getMonthFromDate(providedDate);
    if(itIsCurrentYear)
    {
        int currentMonth = AuxiliaryMethods::getMonthFromDate(AuxiliaryMethods::getCurrentDate());
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


int AuxiliaryMethods::checkNumberOfDaysInMonth (int month, int year)
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

bool AuxiliaryMethods::checkIfProvidedDayIsCorrect (string providedDate)
{
    bool providedDayIsCorrect = false;
    bool itIsCurrentYear = AuxiliaryMethods::checkIfProvidedDateIsCurrentYearDate(providedDate);
    int providedMonth = AuxiliaryMethods::getMonthFromDate(providedDate);
    int providedDay = AuxiliaryMethods::getDayFromDate(providedDate);
    int currentDay = AuxiliaryMethods::getDayFromDate(AuxiliaryMethods::getCurrentDate());
    if(itIsCurrentYear)
    {
        if(providedDay >=1 && providedDay <= currentDay)
            providedDayIsCorrect = true;
    }
    else
    {
        int providedYear = AuxiliaryMethods::getYearFromDate(providedDate);
        int numberOfDaysInProvidedMonth = AuxiliaryMethods::checkNumberOfDaysInMonth(providedMonth, providedYear);
        if (providedDay >=1 && providedDay <= numberOfDaysInProvidedMonth)
            providedDayIsCorrect = true;
    }
    return providedDayIsCorrect;
}

bool AuxiliaryMethods::checkIfProvidedDateIsCorrect(string providedDate, int oldestPermittedDate)
{
    bool providedYearIsCorrect = AuxiliaryMethods::checkIfProvidedYearIsCorrect(providedDate, oldestPermittedDate);
    bool providedMonthIsCorrect = AuxiliaryMethods::checkIfProvidedMonthIsCorrect(providedDate);
    bool providedDayIsCorrect = AuxiliaryMethods::checkIfProvidedDayIsCorrect(providedDate);
    if (providedDayIsCorrect && providedMonthIsCorrect && providedYearIsCorrect)
        return true;
    else
        return false;
}

