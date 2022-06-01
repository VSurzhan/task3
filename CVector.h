//
//  CVector.h
//  CVector
//
//  Created by Вася Суржан on 18.05.2022.
//

#ifndef CVector_h
#define CVector_h

#include <iostream>
#include <fstream>
#include <cassert>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

using namespace std;



class CVector {
    

public:
    vector<double> coords;
    
    string f;
    
    CVector();

    CVector(int size);

    CVector(int size, const char* file);

    CVector(const CVector &x);

    CVector &operator=(const CVector &x);

    double & operator[](int i);
    
    int size() const
    {
        return coords.size();
    }

    const double & operator[](int i)const;

    CVector &operator+=(const CVector &x);

    CVector &operator-=(const CVector &x);

    virtual int output()=0;
    
    CVector(string str, string file);
    
    virtual ~CVector();

    friend ostream &operator<<(ostream &out, const CVector &x);   
};

ostream &operator<<(ostream &out, const CVector &x);

#endif /* CVector_h */
