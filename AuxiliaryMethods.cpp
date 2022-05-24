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
        else
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

string AuxiliaryMethods::replaceFirstLetterWithUppercaseAndRestWithLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

double AuxiliaryMethods::provideAmonut()
{
    string input = "";
    string inputWithChangedCommasIntoDots = "";
    double amount = 0;
    cout << "Podaj kwote transakcji: ";
    while (true)
    {
        getline(cin, input);
        inputWithChangedCommasIntoDots = "";
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == ',')
                inputWithChangedCommasIntoDots += '.';
            else
                inputWithChangedCommasIntoDots += input[i];
        }
        stringstream myStream(inputWithChangedCommasIntoDots);
        if (myStream >> amount)
            break;
        cout << "Niepoprawna kwota. Wpisz ponownie. " << endl;
    }
    amount = convertDoubleIntoDoubleWithTwoDecimalPlaces(amount);
    return amount;
}


string AuxiliaryMethods::convertDoubleToString(double number)
{
    stringstream stream;
    stream << number;
    string str = stream.str();
    return str;
}

double AuxiliaryMethods::convertDoubleIntoDoubleWithTwoDecimalPlaces (double number)
{
    double convertedNumber = 0;
    stringstream stream;
    stream.precision(2);
    stream << fixed;
    stream << number;
    string str = stream.str();
    convertedNumber = stod (str);
    return convertedNumber;
}



