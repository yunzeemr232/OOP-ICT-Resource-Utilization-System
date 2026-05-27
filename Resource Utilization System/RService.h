#ifndef RService_H
#define RService_H
#include <vector>
#include <iostream>
#include "R.h"

using namespace std;

class RService
{
    public:
        RService() {}

        void addR(R res);
        R* findR(string id);
        void listDamagedR() const;
        void listAllR() const;

    private:
        vector<R> resources;
};

#endif // RService_H
