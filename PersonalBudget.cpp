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
}

int PersonalBudget::userLogOut()
{
    userManager.userLogOut();
}
