#include "R.h"

R::R(string id, string name, string type, string stat)
{
    RId = id;
    RName = name;
    RType = type;
    status = stat;
}

void R::updateStatus(string newStatus)
{
    status = newStatus;
}

bool R::isAvailable() const
{
    return status == "Available";
}

string R::getRId() const
{
    return RId;
}

string R::getRName() const
{
    return RName;
}

string R::getRType() const
{
    return RType;
}

string R::getStatus() const
{
    return status;
}

void R::printDetails() const
{
    cout << "Service ID : " << RId << endl;
    cout << "Name       : " << RName << endl;
    cout << "Type       : " << RType << endl;
    cout << "Status     : " << status << endl;
}
