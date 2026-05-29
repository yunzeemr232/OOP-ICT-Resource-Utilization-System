#include "RService.h"
#include <iostream>

using namespace std;

// ADD RESOURCE (FIXED: no shadowing bug)
void RService::addR(const R &res)
{
    resources.push_back(res);
}

// INPUT RESOURCE
void RService::inputR()
{
    string id, name, type, status;

    cout << "Enter Service ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Type: ";
    cin >> type;

    cout << "Enter Status: ";
    cin >> status;

    resources.push_back(R(id, name, type, status));

    cout << "\nResource Added Successfully!\n";
    system("pause");
}

// FIND RESOURCE
R* RService::findR(string id)
{
    for (auto &r : resources)
    {
        if (r.getRId() == id)
            return &r;
    }
    return nullptr;
}

// LIST ALL (🔥 MAIN FIX HERE)
void RService::listAllR() const
{
    cout << "\n===== ALL RESOURCES =====\n";

    if (resources.empty())
    {
        cout << "No resources in system.\n";
        system("pause");
        return;
    }

    for (const auto &r : resources)
    {
        r.printDetails();
        cout << "------------------------\n";
    }

    system("pause");
}

// LIST DAMAGED
void RService::listDamagedR() const
{
    bool found = false;

    cout << "\n===== DAMAGED RESOURCES =====\n";

    for (const auto &r : resources)
    {
        if (r.getStatus() == "Damaged")
        {
            r.printDetails();
            cout << "------------------------\n";
            found = true;
        }
    }

    if (!found)
        cout << "No damaged resources found.\n";

    system("pause");
}
