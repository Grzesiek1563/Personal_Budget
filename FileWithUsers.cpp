#include "FileWithUsers.h"

void FileWithUsers::addUserToFile (User user)
{
    CMarkup xml;
    bool fileExist = xml.Load(getFileName());

    if(!fileExist)
    {
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("UserLogin", user.getLogin());
    xml.AddElem("UserPassword", user.getPassword());
    xml.AddElem("UserName", user.getName());
    xml.AddElem("UserSurname", user.getSurname());

    xml.Save(getFileName());
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector<User> users;
    CMarkup xml;
    bool fileExist = xml.Load(getFileName());
    if(fileExist)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("UserId");
            user.setUserId(AuxiliaryMethods::convertStringToIntiger((xml.GetData())));
            xml.FindElem("UserLogin");
            user.setLogin(xml.GetData());
            xml.FindElem("UserPassword");
            user.setPassword(xml.GetData());
            xml.FindElem("UserName");
            user.setName(xml.GetData());
            xml.FindElem("UserSurname");
            user.setName(xml.GetData());
            xml.OutOfElem();
            users.push_back(user);
        }
    }
    return users;
}

void FileWithUsers::changeUserPasswordInFile(int loggedUserId, string newPassword)
{
    string loggedId = AuxiliaryMethods::convertIntigerToString(loggedUserId);
    CMarkup xml;
    xml.Load(getFileName());
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        if (xml.GetData() == loggedId)
        {
            xml.FindElem("UserPassword");
            xml.SetData(newPassword);
            break;
        }
        xml.OutOfElem();
    }
    xml.Save(getFileName());
}
