#include <algorithm>
#include <iostream>
#include <typeinfo>
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

Fraction::Fraction(string a) //按照"num1/num2"格式传入,不合法的分数自动转换为1并且报错。
{
    denominator = 1;
    molecular = 0;
    int i, len = a.length();  //指针
    for (i = 0; i < len; i++) //读取分子
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
    if (i != len) //如果有分母
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
    if (denominator != 0) //如果分母不等于0,约分
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
        cout << "存在分母为0的分数，请进行输入检查\n";
        denominator = 1;
        molecular = 1;
    }
}

Fraction::Fraction(bool p, int m = 0, int d = 1) //分子，分母，正负号
{
    positive = p;
    if (m * d < 0) //负的
    {
        positive = !positive;
    }
    molecular = abs(m);
    denominator = abs(d);
    if (denominator != 0) //如果分母不等于0,约分
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
        cout << "存在分母为0的分数，请进行输入检查\n";
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
    while (a - int(a)>= 0.000001)//精度
    {
        a *= 10;
        denominator *= 10;
    }
    molecular = a;
    int GCD = GreatestCommonDivisor(molecular, denominator);
    if (GCD != 1)
    {
        molecular /= GCD;
        denominator /= GCD;
    }
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
    if ((!this->positive)&&molecular!=0)
    {
        ans += '-';
    }
    ans += TurnIntToStr(this->molecular);
    if (this->denominator != 1&&molecular!=0)
    {
        ans += '/';
        ans += TurnIntToStr(this->denominator);
    }
    return ans;
}

Fraction operator+(const Fraction &a, const Fraction &b)
{
    int LCM = a.denominator * b.denominator / GreatestCommonDivisor(a.denominator, b.denominator); //算最小公倍数
    int m1 = LCM / a.denominator * a.molecular, m2 = LCM / b.denominator * b.molecular;            //同分
    if (a.positive == 0)                                                                           //正负号转换到分子上
    {
        m1 = -m1;
    }
    if (b.positive == 0)
    {
        m2 = -m2;
    }
    bool p = 1;
    if (m1 + m2 < 0) //如果是负的
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
    if (a.positive != b.positive) //不等，相乘为负数
    {
        p = 0;
    }
    Fraction B(p, a.molecular * b.molecular, a.denominator * b.denominator);
    return B;
}

Fraction operator/(const Fraction &a, const Fraction &b)
{
    bool p = 1;
    if (a.positive != b.positive) //不等，相乘为负数
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
    if (a.positive == 0) //正负号转换到分子上
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
    if (a.positive == 0) //正负号转换到分子上
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
    if (a.positive == 0) //正负号转换到分子上
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
    if (a.positive == 0) //正负号转换到分子上
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
    return a.denominator == b.denominator && a.molecular == b.molecular && a.positive == b.positive;
}

bool operator!=(const Fraction &a, const Fraction &b)
{
    return a.denominator != b.denominator || a.molecular != b.molecular || a.positive != b.positive;
}

