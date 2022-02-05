#include "Base.h"
#pragma once
class Determinant : public Base
{
public:
    int m_rank; //阶数
    Determinant(/* args */);
    Determinant(const Determinant &);
    Determinant(string, int, Fraction *);
    Determinant cofactor(int, int);
    Determinant triangular();
    Fraction calculate();
    ~Determinant();
};
