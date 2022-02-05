#include "Base.h"
#include "Determinant.h"
#pragma once
class Matix : public Base
{
public:
    Matix(string, int, int, Fraction *);
    Matix();
    Matix(const Matix &);
    Matix(string,int,Fraction);//阶数，常数
    Determinant Det();
    Matix adjoint();
    int rank();
    Matix inverse();
    friend Matix operator+(const Matix &, const Matix &);
    friend Matix operator-(const Matix &, const Matix &);
    friend Matix operator*(const Matix &, const Matix &);
    friend Matix operator*(const Matix &, int);
    friend bool operator==(const Matix &, const Matix &);
    Matix &operator+=(const Matix &);
    Matix &operator-=(const Matix &);
    Matix &operator*=(const Matix &);
};
Matix operator*(const Matix &, int);
Matix operator+(const Matix &, const Matix &);
Matix operator-(const Matix &, const Matix &);
Matix operator*(const Matix &, const Matix &);
bool operator==(const Matix &, const Matix &);
bool Equivalent(const Matix &, const Matix &);