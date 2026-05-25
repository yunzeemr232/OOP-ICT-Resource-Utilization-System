#include "Resource.h"
#include <iostream>

using namespace std;

// Replaces Account::deposit() -> Frees up/returns resources back to the pool
void Resource::release(int amount)
{
    availableCapacity += amount;
}

// Replaces Account::withdraw() -> Deducts capacity safely if limits aren't exceeded
bool Resource::allocate(int amount)
{
    if (amount > availableCapacity) return false; // Guard clause to prevent system over-allocation
    availableCapacity -= amount;
    return true;
}

// Replaces Account::getBalance() -> Returns remaining infrastructure capacity
int Resource::getAvailableCapacity() const
{
    return availableCapacity;
}

// Replaces Account::printStatement() -> Generates the asset utilization overview
void Resource::printUtilizationReport() const
{
    cout << "\n--- ICT Resource Utilization Report ---\n"
         << "  Resource ID : " << resourceID                 << "\n"
         << "  Asset Name  : " << resourceName               << "\n"
         << "  Custodian   : " << assignedStaff.getName()    << "\n"
         << "  Staff ID    : " << assignedStaff.getStaffID() << "\n"
         << "  Available   : " << availableCapacity          << " units\n"
         << "---------------------------------------\n";
}