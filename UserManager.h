#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "FileWithUsers.h"
using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    int getNewUserId();
    bool isThereALogin(string login);

    public:
    UserManager(string FILEWITHUSERSNAME) : fileWithUsers(FILEWITHUSERSNAME)
    {
        users = fileWithUsers.loadUsersFromFile();
        loggedUserId = 0;
    };
    bool isTheUserLoggedIn ();
    void userRegistration();
    User provideNewUserData();
    int userLogIn();
    int userLogOut();
};

#endif




