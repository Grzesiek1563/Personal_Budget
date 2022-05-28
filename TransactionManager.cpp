#include "TransactionManager.h"

void TransactionManager::addIncome()
{
    Income income;
    system("cls");
    bool itIsTodaysTransaction;
    itIsTodaysTransaction = DateOperations::isItTodaysTransaction();

    income.setIncomeId(fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(LOGGED_USER_ID);

    if(itIsTodaysTransaction)
        income.setDate(DateOperations::getCurrentDate());
    else
        income.setDate(DateOperations::provideDate(OLDEST_PERMITTED_DATE));

    cout << "Podaj czego dotyczy przychod: ";
    income.setItem(AuxiliaryMethods::loadLine());
    income.setAmount(AuxiliaryMethods::provideAmonut());
    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);
    cout << "Dodano przychod.";
    Sleep(1500);
}

void TransactionManager::wyswietl()
{
    for (int i = 0; i<incomes.size(); i++)
    {
        cout << endl << incomes[i].getItem() << endl << incomes[i].getAmount() <<endl<<endl<<endl;
    }
    system("pause");
}

