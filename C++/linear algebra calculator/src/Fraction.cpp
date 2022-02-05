#include "Fraction.h"
Fraction::Fraction() {}
Fraction::Fraction(const Fraction &a) //�������캯��
{
    denominator = a.denominator;
    molecular = a.molecular;
    positive = a.positive;
}
Fraction::Fraction(string a) //����"num1/num2"��ʽ����,���Ϸ��ķ����Զ�ת��Ϊ1���ұ���
{
    denominator = 1;
    molecular = 0;
    int i, len = a.length();  //ָ��
    for (i = 0; i < len; i++) //��ȡ����
    {
        if (isdigit(a[i]))
            molecular = molecular * 10 + a[i] - '0';
        else if (a[i] == '-')
        {
            positive = !positive;
        }
        else if (a[i] == '/')
            break;
    }
    if (i != len) //����з�ĸ
    {
        denominator = 0;
        for (; i < len; i++)
        {
            if (isdigit(a[i]))
            {
                denominator = denominator * 10 + a[i] - '0';
            }
            else if (a[i] == '-')
            {
                positive = !positive;
            }
        }
    }
    if (denominator != 0) //�����ĸ������0,Լ��
    {
        int GCD = GreatestCommonDivisor(molecular, denominator);
        if (GCD != 1)
        {
            molecular /= GCD;
            denominator /= GCD;
        }
    }
    else
    {
        clog << "���ڷ�ĸΪ0�ķ����������������\n";
        denominator = 1;
        molecular = 1;
    }
}

Fraction::Fraction(bool p, int m = 0, int d = 1) //���ӣ���ĸ��������
{
    positive = p;
    if (m * d < 0) //����
    {
        positive = !positive;
    }
    molecular = abs(m);
    denominator = abs(d);
    if (denominator != 0) //�����ĸ������0,Լ��
    {
        int GCD = GreatestCommonDivisor(molecular, denominator);
        if (GCD != 1)
        {
            molecular /= GCD;
            denominator /= GCD;
        }
    }
    else
    {
        clog << "���ڷ�ĸΪ0�ķ����������������\n";
        denominator = 1;
        molecular = 1;
    }
}

template <class T>
Fraction::Fraction(T a)
{
    positive = 1;
    if (a < 0)
    {
        positive = 0;
    }
    molecular = 0, denominator = 1;
    while (abs(a - int(a)) >= 0.000001) //����
    {
        a *= 10;
        denominator *= 10;
    }
    molecular = abs(a);
    int GCD = GreatestCommonDivisor(molecular, denominator);
    if (GCD != 1)
    {
        molecular /= GCD;
        denominator /= GCD;
    }
}

Fraction::Fraction(int a)
{
    positive = 1;
    if (a < 0)
        positive = 0;
    denominator = 1;
    molecular = abs(a);
}
double calculate(Fraction a)
{
    double t = double(a.molecular) / double(a.denominator);
    return t;
}

Fraction::~Fraction()
{
}

string Fraction::display()
{
    string ans = "";
    if ((!this->positive) && molecular != 0)
    {
        ans += '-';
    }
    ans += TurnIntToStr(this->molecular);
    if (this->denominator != 1 && molecular != 0)
    {
        ans += '/';
        ans += TurnIntToStr(this->denominator);
    }
    return ans;
}

Fraction operator+(const Fraction &a, const Fraction &b)
{
    int LCM = a.denominator * b.denominator / GreatestCommonDivisor(a.denominator, b.denominator); //����С������
    int m1 = LCM / a.denominator * a.molecular, m2 = LCM / b.denominator * b.molecular;            //ͬ��
    if (a.positive == 0)                                                                           //������ת����������
    {
        m1 = -m1;
    }
    if (b.positive == 0)
    {
        m2 = -m2;
    }
    bool p = 1;
    if (m1 + m2 < 0) //����Ǹ���
    {
        p = 0;
    }
    Fraction B(p, abs(m1 + m2), LCM);
    return B;
}

Fraction operator-(const Fraction &a, const Fraction &b)
{
    int LCM = a.denominator * b.denominator / GreatestCommonDivisor(a.denominator, b.denominator);
    int m1 = LCM / a.denominator * a.molecular, m2 = LCM / b.denominator * b.molecular;
    if (a.positive == 0)
    {
        m1 = -m1;
    }
    if (b.positive == 0)
    {
        m2 = -m2;
    }
    bool p = 1;
    if (m1 - m2 < 0)
    {
        p = 0;
    }
    Fraction B(p, abs(m1 - m2), LCM);
    return B;
}

Fraction operator*(const Fraction &a, const Fraction &b)
{
    bool p = 1;
    if (a.positive != b.positive) //���ȣ����Ϊ����
    {
        p = 0;
    }
    Fraction B(p, a.molecular * b.molecular, a.denominator * b.denominator);
    return B;
}

Fraction operator/(const Fraction &a, const Fraction &b)
{
    bool p = 1;
    if (a.positive != b.positive) //���ȣ����Ϊ����
    {
        p = 0;
    }
    Fraction B(p, a.molecular * b.denominator, a.denominator * b.molecular);
    return B;
}

Fraction &Fraction::operator+=(const Fraction &a)
{
    *this = *this + a;
    return *this;
}

Fraction &Fraction::operator-=(const Fraction &a)
{
    *this = *this - a;
    return *this;
}

Fraction &Fraction::operator*=(const Fraction &a)
{
    *this = *this * a;
    return *this;
}

Fraction &Fraction::operator/=(const Fraction &a)
{
    *this = *this / a;
    return *this;
}

int GreatestCommonDivisor(int a, int b)
{
    if (a == 0 || b == 0)
        return 1;
    int tmp;
    while (a % b != 0)
    {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return b;
}

string TurnIntToStr(int a)
{
    if (a == 0)
    {
        return "0";
    }
    string d = "";
    while (a != 0)
    {
        d += (a % 10) + '0';
        a /= 10;
    }
    reverse(d.begin(), d.end());
    return d;
}

bool operator>(const Fraction &a, const Fraction &b)
{
    int LCM = a.denominator * b.denominator / GreatestCommonDivisor(a.denominator, b.denominator);
    int m1 = LCM / a.denominator * a.molecular, m2 = LCM / b.denominator * b.molecular;
    if (a.positive == 0) //������ת����������
    {
        m1 = -m1;
    }
    if (b.positive == 0)
    {
        m2 = -m2;
    }
    return m1 > m2;
}
bool operator<(const Fraction &a, const Fraction &b)
{
    int LCM = a.denominator * b.denominator / GreatestCommonDivisor(a.denominator, b.denominator);
    int m1 = LCM / a.denominator * a.molecular, m2 = LCM / b.denominator * b.molecular;
    if (a.positive == 0) //������ת����������
    {
        m1 = -m1;
    }
    if (b.positive == 0)
    {
        m2 = -m2;
    }
    return m1 < m2;
}
bool operator>=(const Fraction &a, const Fraction &b)
{
    int LCM = a.denominator * b.denominator / GreatestCommonDivisor(a.denominator, b.denominator);
    int m1 = LCM / a.denominator * a.molecular, m2 = LCM / b.denominator * b.molecular;
    if (a.positive == 0) //������ת����������
    {
        m1 = -m1;
    }
    if (b.positive == 0)
    {
        m2 = -m2;
    }
    return m1 >= m2;
}
bool operator<=(const Fraction &a, const Fraction &b)
{
    int LCM = a.denominator * b.denominator / GreatestCommonDivisor(a.denominator, b.denominator);
    int m1 = LCM / a.denominator * a.molecular, m2 = LCM / b.denominator * b.molecular;
    if (a.positive == 0) //������ת����������
    {
        m1 = -m1;
    }
    if (b.positive == 0)
    {
        m2 = -m2;
    }
    return m1 <= m2;
}

bool operator==(const Fraction &a, const Fraction &b)
{
    return calculate(a) == calculate(b);
}

bool operator!=(const Fraction &a, const Fraction &b)
{
    return calculate(a) != calculate(b);
}