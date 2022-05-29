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

void TransactionManager::addExpense()
{
    Expense expense;
    system("cls");
    bool itIsTodaysTransaction;
    itIsTodaysTransaction = DateOperations::isItTodaysTransaction();

    expense.setExpenseId(fileWithExpenses.getLastExpenseId() + 1);
    expense.setUserId(LOGGED_USER_ID);

    if(itIsTodaysTransaction)
        expense.setDate(DateOperations::getCurrentDate());
    else
        expense.setDate(DateOperations::provideDate(OLDEST_PERMITTED_DATE));

    cout << "Podaj czego dotyczy wydatek: ";
    expense.setItem(AuxiliaryMethods::loadLine());
    expense.setAmount(AuxiliaryMethods::provideAmonut());
    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);
    cout << "Dodano wydatek.";
    Sleep(1500);
}

void TransactionManager::displayCurrentMonthBalance()
{
    vector <Income> currentMonthIncomes;
    vector <Expense> currentMonthExpenses;
    int firstDayOfCurrentMonthDate = DateOperations::getFirstDayOfCurrentMonthDate();
    int currentDate = DateOperations::getCurrentDate();

    currentMonthIncomes = getIncomesFromScope(firstDayOfCurrentMonthDate, currentDate);
    currentMonthExpenses = getExpensesFromScope(firstDayOfCurrentMonthDate, currentDate);

    if(currentMonthIncomes.empty() == true && currentMonthExpenses.empty() == true)
    {
        cout << "W tym miesiacu nie wygenerowano zadnych przychodow ani wydatkow. ";
        Sleep(1500);
    }
    else
    {
        system("cls");
        displaySortedExpenses(currentMonthExpenses);
        displaySortedIncomes(currentMonthIncomes);
        displayBalance(currentMonthIncomes, currentMonthExpenses);
        system("pause");
    }

}

vector <Income> TransactionManager::getIncomesFromScope(int fromDate, int toDate)
{
    vector <Income> incomesFromScope;
    for (int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getDate() >= fromDate && incomes[i].getDate() <= toDate)
        {
            incomesFromScope.push_back(incomes[i]);
        }
    }
    return incomesFromScope;
}

vector <Expense> TransactionManager::getExpensesFromScope(int fromDate, int toDate)
{
    vector <Expense> expensesFromScope;
    for (int i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getDate() >= fromDate && expenses[i].getDate() <= toDate)
        {
            expensesFromScope.push_back(expenses[i]);
        }
    }
    return expensesFromScope;
}

void TransactionManager::displaySortedIncomes(vector <Income> incomesToDisplay)
{
    sort(incomesToDisplay.begin(), incomesToDisplay.end());
    cout << "--------------- PRZYCHODY ---------------" << endl;
    for (int i = 0; i < incomesToDisplay.size(); i++)
    {
        cout << i+1 <<". Data przychodu: " << DateOperations::convertIntegerDateToStringDate(incomesToDisplay[i].getDate()) << endl;
        cout << "Rodzaj przychodu: " << incomesToDisplay[i].getItem() << endl;
        cout << "Kwota przychodu: " << setprecision(2) << fixed << incomesToDisplay[i].getAmount() << endl << endl;
    }
}

void TransactionManager::displaySortedExpenses(vector <Expense> expensesToDisplay)
{
    sort(expensesToDisplay.begin(), expensesToDisplay.end());
    cout << "--------------- WYDATKI ---------------" << endl;
    for (int i = 0; i < expensesToDisplay.size(); i++)
    {
        cout << i+1 <<". Data wydatku: " << DateOperations::convertIntegerDateToStringDate(expensesToDisplay[i].getDate()) << endl;
        cout << "Rodzaj wydatku: " << expensesToDisplay[i].getItem() << endl;
        cout << "Kwota wydatku: " << setprecision(2) << fixed << expensesToDisplay[i].getAmount() << endl << endl;
    }
}

void TransactionManager::displayBalance(vector <Income> userIncomes, vector <Expense> userExpenses)
{
    double incomesSum = 0;
    double expensesSum = 0;
    double balance = 0;
    for(int i = 0; i < userIncomes.size(); i++)
    {
        incomesSum += userIncomes[i].getAmount();
    }
    for(int i = 0; i < userExpenses.size(); i++)
    {
        expensesSum += userExpenses[i].getAmount();
    }
    balance = incomesSum - expensesSum;
    cout << "--------------- PODSUMOWANIE ---------------" << endl;
    cout << "Suma przychodow: " << setprecision(2) << fixed << incomesSum << endl;
    cout << "Suma wydatkow: " << setprecision(2) << fixed << expensesSum << endl;
    cout << "Bilans: " << setprecision(2) << fixed << balance << endl;
}


