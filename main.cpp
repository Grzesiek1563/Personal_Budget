#include <iostream>
#include "PersonalBudget.h"
#include "UserManager.h"
#include "AuxiliaryMethods.h"
using namespace std;

int main()
{
    PersonalBudget personalBudget("Users.xml", "Incomes.xml", "Expenses.xml", "2000-01-01");
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
                personalBudget.userLogIn();
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
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.displayCurrentMonthBalance();
                break;
            case '4':
                personalBudget.displayPreviousMonthBalance();
                break;
            case '5':
                personalBudget.displaySelectedPeriodBalance();
                break;
            case '6':
                personalBudget.changeLoggedUserPassword();
                break;
            case '7':
                personalBudget.userLogOut();
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

