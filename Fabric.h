//
//  Fabric.h
//  CVector
//
//  Created by Вася Суржан on 28.05.2022.
//

#ifndef Fabric_h
#define Fabric_h

#include "CVector.h"
#include "CVector0.h"
#include "CVector1.h"

using namespace std;

class Fabric{
public:
    virtual CVector* createCVector(string str, string file) = 0;
};

class Fabric0: public Fabric
{
public:
    CVector* createCVector(string str, string file)
    {
        return new CVector0(str, file);
    }
};

class Fabric1: public Fabric
{
public:
    CVector* createCVector(string str, string file)
    {
        return new CVector1(str, file);
    }
};

#endif /* Fabric_h */
