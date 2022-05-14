#include "PersonalBudget.h"

bool PersonalBudget::isTheUserLoggedIn()
{
    userManager.isTheUserLoggedIn();
}

void PersonalBudget::userRegistration()
{
    userManager.userRegistration();
}

int PersonalBudget::userLogin()
{
    userManager.userLogin();
}
