#include "RService.h"

void RService::addR(R res)
{
    resources.push_back(res);
}

R* RService::findR(string id)
{
    for (auto &res : resources) {
        if (res.getRId() == id) {
            return &res; // Returns a pointer to the active resource asset
        }
    }
    return nullptr;
}

void RService::listDamagedR() const
{
    cout << "\n=== ALERT: DAMAGED ICT FACILITIES ===\n";
    bool found = false;
    for (const auto &res : resources) {
        if (res.getStatus() == "Damaged") {
            cout << " -> [REPAIR REQUIRED] ID: " << res.getRId()
                 << " | Name: " << res.getRName() << "\n";
            found = true;
        }
    }
    if (!found) cout << "No damaged resources reported.\n";
}

void RService::listAllR() const
{
    for (const auto &res : resources) {
        res.printDetails();
    }
}
