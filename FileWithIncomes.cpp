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

    xml.Save(getFileName());
}


