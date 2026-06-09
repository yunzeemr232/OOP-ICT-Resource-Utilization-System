#ifndef RSERVICE_H
#define RSERVICE_H

#include <vector>
#include <string>
#include <iostream>

#include "R.h"

using namespace std;

class RService
{
private:
    vector<R> resources;

public:


    void addR(R res);


    R* findR(string id);


    void listServiceNames() const;


    void listAllR() const;


    void listDamagedR() const;
};

#endif
