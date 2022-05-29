#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToFile(Income income)
{
    CMarkup xml;
    bool fileExist = xml.Load(getFileName());

    if(!fileExist)
    {
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertDoubleToString(income.getAmount()));
    lastIncomeId += 1;
    xml.Save(getFileName());

}

vector <Income> FileWithIncomes::loadLoggedUserIncomesFromFile(int loggedUserId)
{
    Income income;
    vector <Income> incomes;
    CMarkup xml;
    bool fileExist = xml.Load(getFileName());
    if(fileExist)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Income"))
        {
            xml.IntoElem();
            xml.FindElem("IncomeId");
            income.setIncomeId(AuxiliaryMethods::convertStringToIntiger((xml.GetData())));
            xml.FindElem("UserId");
            income.setUserId(AuxiliaryMethods::convertStringToIntiger((xml.GetData())));
            xml.FindElem("Date");
            income.setDate(AuxiliaryMethods::convertStringToIntiger((xml.GetData())));
            xml.FindElem("Item");
            income.setItem(xml.GetData());
            xml.FindElem("Amount");
            income.setAmount(AuxiliaryMethods::convertStringToDouble((xml.GetData())));
            xml.OutOfElem();
            if(income.getUserId() == loggedUserId)
                incomes.push_back(income);
        }
        lastIncomeId = income.getIncomeId();
    }
    else
        lastIncomeId = 0;
    return incomes;
}

int FileWithIncomes::getLastIncomeId()
{
    return lastIncomeId;
}

