#include "Staff.h"

// Replaces Customer::getCIF()
std::string Staff::getStaffID() const
{
    return staffID;
}

// Replaces Customer::getName()
std::string Staff::getName() const
{
    return name;
}