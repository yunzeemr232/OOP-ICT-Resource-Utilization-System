#ifndef RSERVICE_H
#define RSERVICE_H

#include <vector>
#include "R.h"

using namespace std;

class RService
{
private:
    vector<R> resources;

public:
    void addR(const R &res);
    void inputR();

    R* findR(string id);

    void listAllR() const;
    void listDamagedR() const;
};

#endif
