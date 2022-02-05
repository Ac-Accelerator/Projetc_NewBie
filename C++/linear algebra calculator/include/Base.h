#include "Fraction.h"
#include <iomanip>
#pragma once
class Base
{
public:
    int m_m, m_n;
    Fraction map[20][20];
    string m_name;
public:
    Base(/* args */);
    Base(const Base &);
    Base(string,int,int,Fraction*);
    void RowSwap(int, int);          //行交换
    void RowAdd(int, int);           //前一行+=后一行
    void RowMinus(int, int);         //前一行-=后一行
    void RowMultiply(int, Fraction); //该行乘以一个数
    void ColumSwap(int, int);
    void ColumAdd(int, int);
    void ColumMinus(int, int);
    void ColumMultiply(int, Fraction);
    void transpose();
    void display();
    ~Base();
};