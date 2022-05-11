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

    //zapis do pliku  plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}


User UserManager::provideNewUserData()
{
    User user;
    user.setUserId(getNewUserId());
    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (isThereALogin(user.getLogin()) == true);
    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

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


