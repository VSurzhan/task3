//
//  CVector1.h
//  CVector
//
//  Created by Вася Суржан on 18.05.2022.
//

#ifndef CVector1_h
#define CVector1_h

#include "CVector.h"

class CVector1: public CVector
{
public:

    CVector1();
    
    CVector1(int size) : CVector (size){};
    
    CVector1(int size, const char* file) : CVector(size, file){};
    
    CVector1(const CVector &x) : CVector(x){};
    
    CVector1(string str, string file) : CVector(str, file){};
    
    using CVector :: operator=;
    
    ~CVector1(){}

    int output();    
};


#endif /* CVector1_h */
