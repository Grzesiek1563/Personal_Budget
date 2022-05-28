#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile(Expense expense)
{
    CMarkup xml;
    bool fileExist = xml.Load(getFileName());

    if(!fileExist)
    {
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertDoubleToString(expense.getAmount()));
    lastExpenseId += 1;
    xml.Save(getFileName());

}


vector <Expense> FileWithExpenses::loadLoggedUserExpensesFromFile(int loggedUserId)
{
    Expense expense;
    vector <Expense> expenses;
    CMarkup xml;
    bool fileExist = xml.Load(getFileName());
    if(fileExist)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Expense"))
        {
            xml.IntoElem();
            xml.FindElem("ExpenseId");
            expense.setExpenseId(AuxiliaryMethods::convertStringToIntiger((xml.GetData())));
            xml.FindElem("UserId");
            expense.setUserId(AuxiliaryMethods::convertStringToIntiger((xml.GetData())));
            xml.FindElem("Date");
            expense.setDate(AuxiliaryMethods::convertStringToIntiger((xml.GetData())));
            xml.FindElem("Item");
            expense.setItem(xml.GetData());
            xml.FindElem("Amount");
            expense.setAmount(AuxiliaryMethods::convertStringToDouble((xml.GetData())));
            xml.OutOfElem();
            if(expense.getUserId() == loggedUserId)
                expenses.push_back(expense);
        }
        lastExpenseId = expense.getExpenseId();
    }
    else
        lastExpenseId = 0;
    return expenses;
}

int FileWithExpenses::getLastExpenseId()
{
    return lastExpenseId;
}

