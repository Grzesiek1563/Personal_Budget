#include <iostream>
#include "PersonalBudget.h"
#include "UserManager.h"
#include "AuxiliaryMethods.h"
using namespace std;

int main()
{
    PersonalBudget personalBudget;
    char choice;
    while (true)
    {
        if (!personalBudget.isTheUserLoggedIn())
        {
            choice = AuxiliaryMethods::chooseMainMenuOption();

            switch (choice)
            {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                //ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '3':
                //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = AuxiliaryMethods::choseUserMenuOption();
            switch (choice)
            {
            case '1':
                //dodaj przychod();
                break;
            case '2':
                //dodaj wydatek();
                break;
            case '3':
                //bilans ten miesiac();
                break;
            case '4':
                //bilans poprzedni miesiac();
                break;
            case '5':
                //bilans wybrany okres();
                break;
            case '6':
                //zmiana hasla();
                break;
            case '7':
                //wyloguj sie();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
