#pragma once
#include "Base.h"
#include "Matix.h"
#include "Fraction.h"
#include "Determinant.h"
#include <map>
Matix expression_value(string, int &);
Matix term_value(string, int &);
Matix factor_value(string, int &);
map<string, pair<string, int>> cache;
int PM = 0, PD = 0;
Matix LM[100];
Determinant LD[100];
Matix expression_value(string a, int &p)
{
    Matix result = term_value(a, p);
    while (true)
    {
        if (p != a.length() && (a[p] == '+' || a[p] == '-'))
        {
            char op = a[p];
            p++;
            Matix value = term_value(a, p);
            if (op == '+')
                result += value;
            else
                result -= value;
        }
        else
            break;
    }
    return result;
}
Matix term_value(string a, int &p)
{
    Matix result = factor_value(a, p);
    while (true)
    {
        if (p != a.length() && a[p] == '*')
        {
            char op = a[p];
            p++;

            Matix value = factor_value(a, p);
            if (op == '*')
                result *= value;
        }
        else
            break;
    }
    return result;
}
Matix factor_value(string a, int &p)
{
    string na;
    Matix result("null", 1, 0);
    if (p != a.length() && a[p] == '(')
    {
        p++;
        result = expression_value(a, p);
        p++;
    }
    else
    {

        while (p != a.length() && a[p] != '+' && a[p] != '-' && a[p] != '*' && a[p] != ')')
        {
            na += a[p++];
        }
        if (!cache.count(na))
        {
            cout << "未找到使用此名字的变量:" << na << endl;
            return result;
        }
        if (cache[na].first != "Matix")
        {
            cout << "使用该名称的变量不属于矩阵:" << na << endl;
            return result;
        }
        result = LM[cache[na].second];
    }
    return result;
}