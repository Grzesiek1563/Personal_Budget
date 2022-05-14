#include "UserManager.h"


bool UserManager::isTheUserLoggedIn()
{
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

void UserManager::userRegistration()
{
    User user = provideNewUserData();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}


User UserManager::provideNewUserData()
{
    User user;
    user.setUserId(getNewUserId());
    string login, password, name, surname;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (isThereALogin(user.getLogin()) == true);
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}


int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::isThereALogin(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}




