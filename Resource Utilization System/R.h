#ifndef R_H
#define R_H
#include <iostream>

using namespace std;

class R
{
    public:
        R(string id, string name, string type, string status)
            : RId(id), RName(name), RType(type), status(status) {};

        void updateStatus(string newStatus);
        bool isAvailable() const;

        string getRId() const;
        string getRName() const;
        string getStatus() const;
        void printDetails() const;

    private:
        string RId;
        string RName;
        string RType; // e.g., "Machine", "Network", "Facility"
        string status;       // e.g., "Available", "In Use", "Damaged"
};

#endif // R_H
