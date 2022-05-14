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
