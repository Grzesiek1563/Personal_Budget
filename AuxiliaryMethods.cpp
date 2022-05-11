#include "AuxiliaryMethods.h"

char AuxiliaryMethods::chooseMainMenuOption()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    //cout << "2. Logowanie" << endl;
    //cout << "3. Zmiana hasla" <<endl;
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
    //cout << "1. Dodaj przychod" << endl;
    //cout << "2. Dodaj wydatek" << endl;
    //cout << "3. Bilans z biezacego miesiaca" << endl;
    //cout << "4. Bilans z poprzedniego miesiaca" << endl;
    //cout << "5. Bilans z wybranego okresu" << endl;
    //cout << "---------------------------" << endl;
    //cout << "6. Zmien haslo" << endl;
    //cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}
