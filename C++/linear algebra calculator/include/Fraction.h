#include <algorithm>
#include <iostream>
#pragma once
using namespace std;
class Fraction
{
private:
    /* data */
    int molecular, denominator; //分子，分母
    bool positive = 1;          //是否正数

public:
    Fraction(string);         // string构造函数
    Fraction(bool, int, int); //是否正数，分子，分母
    template <class T>
    Fraction(T);
    Fraction(int);
    Fraction();
    Fraction(const Fraction &);//拷贝构造函数
    string display();
    friend double calculate(Fraction); //计算具体值
    friend Fraction operator+(const Fraction &, const Fraction &);
    friend Fraction operator-(const Fraction &, const Fraction &);
    friend Fraction operator*(const Fraction &, const Fraction &);
    friend Fraction operator/(const Fraction &, const Fraction &);
    friend bool operator>(const Fraction &, const Fraction &);
    friend bool operator<(const Fraction &, const Fraction &);
    friend bool operator>=(const Fraction &, const Fraction &);
    friend bool operator<=(const Fraction &, const Fraction &);
    friend bool operator==(const Fraction &, const Fraction &);
    friend bool operator!=(const Fraction &, const Fraction &);
    Fraction &operator+=(const Fraction &);
    Fraction &operator-=(const Fraction &);
    Fraction &operator*=(const Fraction &);
    Fraction &operator/=(const Fraction &);
    ~Fraction();
};
string TurnIntToStr(int);            //将整数转化为string
int GreatestCommonDivisor(int, int); //求最大公约数
Fraction operator+(const Fraction &, const Fraction &);
Fraction operator-(const Fraction &, const Fraction &);
Fraction operator*(const Fraction &, const Fraction &);
Fraction operator/(const Fraction &, const Fraction &);
bool operator>(const Fraction &, const Fraction &);
bool operator<(const Fraction &, const Fraction &);
bool operator>=(const Fraction &, const Fraction &);
bool operator<=(const Fraction &, const Fraction &);
bool operator==(const Fraction &, const Fraction &);
bool operator!=(const Fraction &, const Fraction &);
