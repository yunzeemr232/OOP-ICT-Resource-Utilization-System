#ifndef R_H
#define R_H

#include <iostream>
using namespace std;

class R
{
private:
    string RId;
    string RName;
    string RType;
    string status;

public:
    R(string id, string name, string type, string stat);

    void updateStatus(string newStatus);
    bool isAvailable() const;

    string getRId() const;
    string getRName() const;
    string getRType() const;
    string getStatus() const;

    void printDetails() const;
};

#endif
