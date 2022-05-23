#include "TransactionManager.h"

void TransactionManager::addIncome()
{
    Income income;
    system("cls");
    bool itIsTodaysTransaction;
    itIsTodaysTransaction = AuxiliaryMethods::isItTodaysTransaction();

    income.setIncomeId(getNewIncomeId());
    income.setUserId(LOGGED_USER_ID);

    if(itIsTodaysTransaction)
        income.setDate(AuxiliaryMethods::getCurrentDate());
    else
        income.setDate(AuxiliaryMethods::provideDate(OLDEST_PERMITTED_DATE));

    cout << "Podaj czego dotyczy przychod: ";
    income.setItem(AuxiliaryMethods::loadLine());
    income.setAmount(AuxiliaryMethods::provideAmonut());
    incomes.push_back(income);
    cout << "Dodano przychod.";
    Sleep(1500);
    //zapisywanie do pliku
}

int TransactionManager::getNewIncomeId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

void TransactionManager::wyswietl()
{
    for (int i = 0; i<incomes.size(); i++)
    {
        cout << endl << incomes[i].getItem() << endl << incomes[i].getAmount() <<endl<<endl<<endl;
    }
    system("pause");
}

