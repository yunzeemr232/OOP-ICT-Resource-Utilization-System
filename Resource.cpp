#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <vector>
#include <iostream>
#include "Staff.h"
#include "Transaction.h"

class Resource {
private:
    std::string resourceID;
    std::string resourceName;
    Staff assignedStaff;
    int availableCapacity; // e.g., Percentage of Server RAM, or number of units available
    std::vector<Transaction> history;

public:
    Resource(std::string id, std::string name, Staff staff, int initialCapacity) 
        : resourceID(id), resourceName(name), assignedStaff(staff), availableCapacity(initialCapacity) {}

    void allocate(int demand) {
        if (demand <= availableCapacity) {
            availableCapacity -= demand;
            std::cout << "Success: Allocated " << demand << " units of " << resourceName << ".\n";
            history.push_back(Transaction("ALLOCATED", std::to_string(demand) + " units taken."));
        } else {
            std::cout << "Failure: Insufficient capacity on " << resourceName << " to fulfill demand of " << demand << " units!\n";
            history.push_back(Transaction("DENIED", "Requested " + std::to_string(demand) + " units but capacity insufficient."));
        }
    }

    void release(int returnAmount) {
        availableCapacity += returnAmount;
        std::cout << "Success: Released " << returnAmount << " units back to " << resourceName << ".\n";
        history.push_back(Transaction("RELEASED", std::to_string(returnAmount) + " units returned."));
    }

    void printUtilizationReport() const {
        std::cout << "\n====================================\n";
        std::cout << "ICT UTILIZATION REPORT: " << resourceID << " (" << resourceName << ")\n";
        std::cout << "Primary Custodian: " << assignedStaff.getName() << " (ID: " << assignedStaff.getStaffID() << ")\n";
        std::cout << "Remaining Available Capacity: " << availableCapacity << " units\n";
        std::cout << "Transaction Log:\n";
        for (const auto& tx : history) {
            tx.print();
        }
        std::cout << "====================================\n";
    }
};

#endif