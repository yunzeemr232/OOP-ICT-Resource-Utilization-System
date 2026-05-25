#ifndef STAFF_H
#define STAFF_H

#include <string>

class Staff {
private:
    std::string name;
    std::string staffID;

public:
    Staff() : name("Unknown"), staffID("N/A") {}
    Staff(std::string name, std::string staffID) : name(name), staffID(staffID) {}

    std::string getName() const { return name; }
    std::string getStaffID() const { return staffID; }
};

#endif