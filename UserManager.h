#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

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
    User provideNewUserData();

    public:
    UserManager(string FILEWITHUSERSNAME) : fileWithUsers(FILEWITHUSERSNAME)
    {
        users = fileWithUsers.loadUsersFromFile();
        loggedUserId = 0;
    };
    bool isTheUserLoggedIn();
    void userRegistration();
    int userLogIn();
    int userLogOut();
    void changeLoggedUserPassword();
    int getLoggedUserId();
};

#endif




