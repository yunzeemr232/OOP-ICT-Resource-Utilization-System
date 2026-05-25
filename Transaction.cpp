#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

class Transaction {
private:
    std::string type;   // e.g., "ALLOCATED", "RELEASED", "DENIED"
    std::string details;

public:
    Transaction(std::string type, std::string details) : type(type), details(details) {}

    void print() const {
        std::cout << "  -> [" << type << "] " << details << "\n";
    }
};

#endif