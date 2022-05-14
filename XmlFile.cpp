#include "XmlFile.h"

bool XmlFile::isTheFileEmpty()
{
    CMarkup xml;
    bool fileExist = xml.Load(FILE_NAME);
    if (fileExist)
        return false;
    else
        return true;
}
