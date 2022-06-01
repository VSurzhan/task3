//
//  Cvector.cpp
//  CVector
//
//  Created by Вася Суржан on 18.05.2022.
//

#include "CVector.h"
#include "CVector0.h"
#include "CVector1.h"

#include <sstream>
#include <chrono>
using namespace std;


CVector:: CVector(){}

CVector:: CVector(int size)
{
    this->coords.resize(size);
        for (double i : this->coords) {
            i = 0;
        }
}

CVector:: CVector(int size, const char* file)
{
    this->coords.resize(size);
    ifstream in;
    in.open(file);
    if (!in.is_open())
        return;
    for (double i : this->coords)
        in >> i;
}

CVector:: CVector(const CVector &x)
{
    this->coords = x.coords;
}

CVector& CVector::operator=(const CVector &x)
{
    if (this == &x)
        return *this;
    this->coords = x.coords;
    return *this;
}

double& CVector:: operator[](int i){
    if (i >= this->coords.size())
    {
        int N;
        N = this->coords.size();
        vector <double> mas(N);
        for (int j = 0; j < N; ++j)
        {
            mas[j] = this->coords[j];
        }
        this->coords.resize(i + 1);
        for (int j = 0; j < i+1; ++j)
        {
            if(j < N)
                this->coords[j] = mas[j];
            else
                this->coords[j] = 0;
        }
    }
    return coords[i];
}

const double& CVector:: operator[](int i)const
{
    return coords[i];
}



CVector0 operator+(const CVector &a, const CVector &b)
{
    if (a.size() != b.size())
    {
        cout << "Error! In operator+: different size of vectors!" << endl;
        exit(1);
    }
    CVector0 c(a.size());
    auto first = std::chrono::steady_clock::now();
    #pragma omp parallel for
    for (int i = 0; i < a.size(); ++i)
        c.coords[i] = a.coords[i] + b.coords[i];
    auto second = std::chrono::steady_clock::now();
    auto t = std::chrono::duration_cast<std::chrono::milliseconds>(second - first);
    std::cout << "The time of operator+: " << t.count() << " ms\n";
    return c;
}



CVector0 operator-(const CVector &a, const CVector &b)
{
    if (a.size() != b.size())
    {
        cout << "Error! In operator-: different size of vectors!" << endl;
        exit(1);
    }
    CVector0 c(a.size());
    auto first = std::chrono::steady_clock::now();
    #pragma omp parallel for
    for (int i = 0; i < a.size(); ++i)
        c.coords[i] = a.coords[i] - b.coords[i];
    auto second = std::chrono::steady_clock::now();
    auto t = std::chrono::duration_cast<std::chrono::milliseconds>(second - first);
    std::cout << "The time of operator-: " << t.count() << " ms\n";
    return c;
}

CVector& CVector:: operator+=(const CVector &x)
{
    *this = *this + x;
    return *this;
}

CVector& CVector:: operator-=(const CVector &x)
{
    *this = *this - x;
    return *this;
}


CVector:: CVector(string str, string file)
{
    string s;
    istringstream in (str);
    while(!in.eof())
        {
            in >> s;
            this->coords.push_back(atof(s.c_str()));
        }
    this->f = file;
}


CVector::  ~CVector()
{
    coords.~vector();
}

CVector0:: CVector0(){}

int CVector0::output()
{
    ofstream out;
    out.open(this->f, fstream::out|fstream::app);
    if(!out.is_open())
        return -1;
    for(double i : this->coords)
            out << i << ' ';
    out << endl;
    out.close();
    return 0;
}


CVector1:: CVector1(){}


int CVector1::output()
{
    ofstream out;
    out.open(this->f, fstream::out|fstream::app);
    if(!out.is_open())
        return -1;
    for(double i : this->coords)
            out << i << '\n';
    out << endl;
    out.close();
    return 0;
}

ostream &operator<<(ostream &out, const CVector &x)
{
    for (double i : x.coords)
        cout << i << "\t";
    cout << endl << endl;
    return out;
}
