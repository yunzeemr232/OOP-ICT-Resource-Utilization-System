#include <iostream>
#include "R.h"
#include "RService.h"

using namespace std;

int main()
{
    cout << "=== ICT Utilization Resource Center System ===\n\n";

    RService center;

    // Register initial assets into the service vector layer
    center.addR(R("RES-001", "Lab PC 05", "Machine", "Available"));
    center.addR(R("RES-002", "Server Rack A", "Machine", "In Use"));
    center.addR(R("RES-003", "Main Switch", "Network", "Operational"));
    center.addR(R("RES-004", "Library Wi-Fi AP", "Network", "Damaged"));
    center.addR(R("RES-005", "Projector Lab 2", "Facility", "Damaged"));

    // Display basic tracking roster
    cout << "[ Processing All Registered Assets ]\n";
    center.listAllR();

    // Isolate damaged units for system logs
    center.listDamagedR();

    // Test a simulation of allocating a resource
    cout << "\n=== Simulating Lab Allocation Check ===\n";
    string targetId = "RES-001";
    R* target = center.findR(targetId);

    if (target != nullptr) {
        cout << "Found Asset: " << target->getRName() << "\n";
        if (target->isAvailable()) {
            cout << "Status: Available! Allocating to student now...\n";
            target->updateStatus("In Use");
        } else {
            cout << "Allocation Failed: Asset status is currently '" << target->getStatus() << "'\n";
        }
    } else {
        cout << "Error: Resource ID not found.\n";
    }

    // Verify status update worked successfully
    cout << "\n[ Updated Verification Record ]\n";
    if (target != nullptr) target->printDetails();

    return 0;
}
