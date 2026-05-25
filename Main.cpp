#include <iostream>
#include "Staff.h"
#include "Resource.h"
#include "Transaction.h"

using namespace std;

int main()
{
    cout << "=== ICT Resources Utilization System ===\n\n";

    // 1. Create Staff Members (Analogous to creating Customers)
    Staff s1("Fodie",   "STF001");
    Staff s2("Fomba", "STF002");

    // 2. Instantiate Resources assigned to staff (Analogous to opening Bank Accounts with initial funds)
    // Here, 1000 and 500 represent resource capacities (like MBs of RAM, Compute cycles, or Storage blocks)
    Resource res1("SRV-1001", "Cloud Compute Node A", s1, 1000);
    Resource res2("SRV-1002", "Storage Server B",     s2,  500);

    // 3. Perform utilization actions on Resource 1
    cout << "[ SRV-1001 Allocations ]\n";
    res1.allocate(500);   // Consumes 500 units -> 500 remaining
    res1.release(200);    // Frees up 200 units -> 700 remaining
    res1.allocate(2000);  // Fails (Requested 2000, but only 700 is left)

    // 4. Perform utilization actions on Resource 2
    cout << "\n[ SRV-1002 Allocations ]\n";
    res2.allocate(300);   // Consumes 300 units -> 200 remaining
    res2.release(100);    // Frees up 100 units -> 300 remaining

    // 5. Print comprehensive system states (Analogous to printing Bank Statements)
    res1.printUtilizationReport();
    res2.printUtilizationReport();

    return 0;
}
