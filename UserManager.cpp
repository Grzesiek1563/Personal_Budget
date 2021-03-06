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
    system("cls");
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
    do
    {
        cout << "Podaj login: ";
        user.setLogin(AuxiliaryMethods::loadLine());
    } while (isThereALogin(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods::loadLine());

    cout << "Podaj imie: ";
    user.setName(AuxiliaryMethods::loadLine());
    user.setName(AuxiliaryMethods::replaceFirstLetterWithUppercaseAndRestWithLowercase(user.getName()));

    cout << "Podaj nazwisko: ";
    user.setSurname(AuxiliaryMethods::loadLine());
    user.setSurname(AuxiliaryMethods::replaceFirstLetterWithUppercaseAndRestWithLowercase(user.getSurname()));

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
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl << endl;
            return true;
        }
    }
    return false;
}

int UserManager::userLogIn()
{
    system("cls");
    User user;
    string login = "", password = "";
    if(users.empty() == false)
    {
        cout << "Podaj login: ";
        login = AuxiliaryMethods::loadLine();
        vector <User>::iterator itr = users.begin();
        while (itr != users.end())
        {
            if (itr -> getLogin() == login)
            {
                for (int attemptsNumber = 3; attemptsNumber > 0; attemptsNumber--)
                {
                    cout << "Podaj haslo. Pozostalo prob: " << attemptsNumber << ": ";
                    password = AuxiliaryMethods::loadLine();

                    if (itr -> getPassword() == password)
                    {
                        cout << endl << "Zalogowales sie." << endl << endl;
                        system("pause");
                        loggedUserId = itr -> getUserId();
                        return 0;
                    }
                }
                cout << "Wprowadzono 3 razy bledne haslo." << endl;
                system("pause");
                loggedUserId = 0;
                return 0;
            }
            itr++;
        }
        cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
        system("pause");
        loggedUserId = 0;
    }
    else
    {
        cout << "Aby sie zalogowac dodaj konto. ";
        Sleep(3000);
    }
    return 0;
}

int UserManager::userLogOut()
{
    loggedUserId = 0;
    cout << endl << "Wylogowano. " << endl;
    system("pause");
}

void UserManager::changeLoggedUserPassword()
{
    system("cls");
    string newPassword;
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getUserId() == loggedUserId)
        {
            while(itr -> getPassword() == newPassword)
            {
                cout << "Nowe haslo musi roznic sie od starego. Wprowadz nowe haslo ponownie: ";
                newPassword = AuxiliaryMethods::loadLine();
            }
            itr -> setPassword(newPassword);
            cout << endl << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.changeUserPasswordInFile(loggedUserId, newPassword);
}

int UserManager::getLoggedUserId()
{
    return loggedUserId;
}



