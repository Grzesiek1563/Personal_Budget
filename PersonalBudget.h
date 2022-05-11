#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"
using namespace std;

class PersonalBudget
{
    UserManager userManager;
    const string OLDEST_PERMITTED_DATE;

    public:
    PersonalBudget()
    {
        ;
    }
    bool isTheUserLoggedIn ();
    void userRegistration();


};

#endif
