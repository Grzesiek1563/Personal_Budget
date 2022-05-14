#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include "XmlFile.h"
#include "User.h"
#include "Markup.h"

using namespace std;

class FileWithUsers : public XmlFile
{

    public:
    FileWithUsers(string FILEWITHUSERSNAME) : XmlFile(FILEWITHUSERSNAME) {};
    void addUserToFile (User user);

};


#endif
