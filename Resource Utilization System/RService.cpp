#include <iostream>
#include "RService.h"

using namespace std;


void RService::addR(R res)
{
    resources.push_back(res);
}


R* RService::findR(string id)
{
    for(auto &res : resources)
    {
        if(res.getRId() == id)
        {
            return &res;
        }
    }

    return nullptr;
}


void RService::listServiceNames() const
{
    for(const auto &res : resources)
    {
        cout << "Service ID   : "
             << res.getRId() << endl;

        cout << "Service Name : "
             << res.getRName() << endl;

        cout << "-----------------------------------\n";
    }
}


void RService::listAllR() const
{
    for(const auto &res : resources)
    {
        res.printDetails();

        cout << "-----------------------------------\n";
    }
}


void RService::listDamagedR() const
{
    bool found = false;

    for(const auto &res : resources)
    {
        if(res.getStatus() == "Damaged")
        {
            cout << "Service ID   : "
                 << res.getRId() << endl;

            cout << "Service Name : "
                 << res.getRName() << endl;

            cout << "Status       : "
                 << res.getStatus() << endl;

            cout << "-----------------------------------\n";

            found = true;
        }
    }

    if(!found)
    {
        cout << "No damaged services found.\n";
    }
}
