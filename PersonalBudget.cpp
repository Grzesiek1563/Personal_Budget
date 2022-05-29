#include "PersonalBudget.h"

bool PersonalBudget::isTheUserLoggedIn()
{
    userManager.isTheUserLoggedIn();
}

void PersonalBudget::userRegistration()
{
    userManager.userRegistration();
}

int PersonalBudget::userLogIn()
{
    userManager.userLogIn();
    if (userManager.isTheUserLoggedIn())
    {
        transactionManager = new TransactionManager(FILE_WITH_INCOMES_NAME, FILE_WITH_EXPENSES_NAME,
        userManager.getLoggedUserId(), OLDEST_PERMITTED_DATE);
    }
}

int PersonalBudget::userLogOut()
{
    userManager.userLogOut();
}

void PersonalBudget::changeLoggedUserPassword()
{
    userManager.changeLoggedUserPassword();
}


void PersonalBudget::addIncome()
{
    if(userManager.isTheUserLoggedIn())
    {
        transactionManager -> addIncome();
    }
    else
    {
        cout<<"Aby dodac przychod, nalezy najpierw sie zalogowac"<<endl;
        system("pause");
    }
}

void PersonalBudget::addExpense()
{
    if(userManager.isTheUserLoggedIn())
    {
        transactionManager -> addExpense();
    }
    else
    {
        cout<<"Aby dodac wydatek, nalezy najpierw sie zalogowac"<<endl;
        system("pause");
    }
}

void PersonalBudget::displayCurrentMonthBalance()
{
    transactionManager -> displayCurrentMonthBalance();
}

void PersonalBudget::displayPreviousMonthBalance()
{
    transactionManager -> displayPreviousMonthBalance();
}

void PersonalBudget::displaySelectedPeriodBalance()
{
    transactionManager -> displaySelectedPeriodBalance();
}

