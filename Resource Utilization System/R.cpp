#include "R.h"

void R::updateStatus(string newStatus)
{
    status = newStatus;
}

bool R::isAvailable() const
{
    return (status == "Available");
}

string R::getRId() const
{
    return RId;
}

string R::getRName() const
{
    return RName;
}

string R::getStatus() const
{
    return status;
}

void R::printDetails() const
{
    cout << "\n--- ICT Resource Record ---\n"
         << "  Resource ID : " << RId   << "\n"
         << "  Asset Name  : " << RName << "\n"
         << "  Category    : " << RType << "\n"
         << "  Current Stat: " << status       << "\n"
         << "---------------------------\n";
}
