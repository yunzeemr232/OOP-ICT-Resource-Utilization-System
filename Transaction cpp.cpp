#include "Transaction.h"
#include <iostream>

using namespace std;

// Replaces the financial display with an ICT allocation/utilization display
void Transaction::display() const
{
    cout << "  [" << type << "] " << unitsAllocated << " units\n";
}