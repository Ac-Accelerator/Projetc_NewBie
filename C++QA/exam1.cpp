#include <algorithm>
#include <iostream>
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
#include <iomanip>
class Base
{
protected:
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
class Determinant :public Base
{
private:
    int m_rank;//阶数
public:
    Determinant(/* args */);
    Determinant(const Determinant &); 
    Determinant(string ,int ,Fraction*);
    Determinant cofactor(int, int);
    Determinant triangular();
    Fraction calculate();
    ~Determinant();
};
#include <cstring>
class Matix : public Base
{
public:
    Matix(string, int, int, Fraction *);
    Matix();
    Matix(const Matix &);
    Matix(string,int,Fraction);//阶数，常数
    Determinant Det();
    Matix adjoint();
    Matix inverse();
    int rank();
    friend Matix operator+(const Matix &, const Matix &);
    friend Matix operator-(const Matix &, const Matix &);
    friend Matix operator*(const Matix &, const Matix &);
    Matix &operator+=(const Matix &);
    Matix &operator-=(const Matix &);
    Matix &operator*=(const Matix &);
};
Matix operator+(const Matix &, const Matix &);
Matix operator-(const Matix &, const Matix &);
Matix operator*(const Matix &, const Matix &);

Matix::Matix(string na, int m, int n, Fraction *list) : Base(na, m, n, list) {}
Matix::Matix() {}
Matix::Matix(string na,int n,Fraction num)
{
    m_m = n, m_n = n;
    m_name = na;
    Fraction temp(0);
    for (int i = 1; i <= m_m; i++)
    {
        for (int j = 1; j <= m_n; j++)
        {
            map[i][j] =temp ;
        }
    }
    for (int i = 1; i <= n;i++)
    {
        map[i][i] = num;
    }
}
Matix::Matix(const Matix &a)
{
    m_name = a.m_name, m_m = a.m_m, m_n = a.m_n;
    for (int i = 1; i <= m_m; i++)
    {
        for (int j = 1; j <= m_n; j++)
        {
            map[i][j] = a.map[i][j];
        }
    }
}
Determinant Matix::Det()
{
    if (m_m != m_n)
    {
        Determinant f;
        clog << "此矩阵不能转化为行列式\n";
        return f;
    }
    Fraction list[m_n * m_m];
    int point = 0;
    for (int i = 1; i <= m_m; i++)
    {
        for (int j = 1; j <= m_n; j++)
        {
            list[point++] = map[i][j];
        }
    }
    Determinant B(m_name + "_det", m_m, list);
    return B;
}

Matix Matix::adjoint()
{
    Matix B;
    if (this->m_m != this->m_n)
    {
        clog << "矩阵不满足条件，请进行输入检查\n\n";
        return B;
    }
    B.m_name = this->m_name + "_adj";
    B.m_m = this->m_m, B.m_n = this->m_n;
    Determinant temp = this->Det();
    for (int i = 1; i <= B.m_m; i++)
    {
        for (int j = 1; j <= B.m_n; j++)
        {
            B.map[j][i] = temp.cofactor(i, j).calculate();
            if ((i + j) % 2)
            {
                B.map[j][i] *= -1;
            }
        }
    }
    return B;
}

Matix Matix::inverse()
{
    Fraction de = this->Det().calculate();
    if (this->m_m != this->m_n || de == 0)
    {
        Matix B;
        clog << "矩阵不满足条件，请进行输入检查\n";
        return B;
    }
    Matix B = this->adjoint();
    Matix t("_Detv", this->m_n, 1/de);
    B *= t;
    return B;
}

Matix operator+(const Matix &a, const Matix &b)
{
    Matix B;
    if ((a.m_m != b.m_m) || (a.m_n != b.m_n))
    {
        clog << "矩阵不满足条件，请进行输入检查\n";
        return B;
    }
    B.m_name = "[" + a.m_name + "+" + b.m_name + "]";
    B.m_m = a.m_m, B.m_n = a.m_n;
    for (int i = 1; i <= B.m_m; i++)
    {
        for (int j = 1; j <= B.m_n; j++)
        {
            B.map[i][j] = a.map[i][j] + b.map[i][j];
        }
    }
    return B;
}

Matix operator-(const Matix &a, const Matix &b)
{
    Matix B;
    if ((a.m_m != b.m_m) || (a.m_n != b.m_n))
    {
        clog << "矩阵不满足条件，请进行输入检查\n";
        return B;
    }
    B.m_name = "[" + a.m_name + "-" + b.m_name + "]";
    B.m_m = a.m_m, B.m_n = a.m_n;
    for (int i = 1; i <= B.m_m; i++)
    {
        for (int j = 1; j <= B.m_n; j++)
        {
            B.map[i][j] = a.map[i][j] - b.map[i][j];
        }
    }
    return B;
}

Matix operator*(const Matix &a, const Matix &b)
{
    Matix B;
    if (a.m_n != b.m_m)
    {
        clog << "矩阵不满足条件，请进行输入检查\n";
        return B;
    }
    B.m_name = "[" + a.m_name + "*" + b.m_name + "]";
    B.m_m = a.m_m, B.m_n = b.m_n;
    for (int i = 1; i <= B.m_m; i++)
    {
        for (int j = 1; j <= B.m_n; j++)
        {
            Fraction sum(0);
            for (int k = 1; k <= a.m_n; k++)
            {
                sum += a.map[i][k] * b.map[k][j];
            }
            B.map[i][j] = sum;
        }
    }
    return B;
}

Matix &Matix::operator+=(const Matix &a)
{
    *this = *this + a;
    return *this;
}

Matix &Matix::operator-=(const Matix &a)
{
    *this = *this - a;
    return *this;
}

Matix &Matix::operator*=(const Matix &a)
{
    *this = *this * a;
    return *this;
}

Base::Base(/* args */)
{
}

Base::Base(const Base &a) //拷贝构造函数
{
    m_name = a.m_name;
    m_m = a.m_m, m_n = a.m_n;
    for (int i = 1; i <= m_m; i++)
    {
        for (int j = 1; j <= m_n; j++)
        {
            map[i][j] = a.map[i][j];
        }
    }
}

Base::Base(string na, int m, int n, Fraction *a)
{
    m_m = m, m_n = n;
    m_name = na;
    int point = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[i][j] = a[point++];
        }
    }
}

void Base::RowSwap(int a, int b)
{
    if (a > m_m || b > m_m || a < 1 || b < 1)
    {
        clog << "操作越出范围,不进行操作\n";
        return ;
    }
    for (int i = 1; i <= m_n; i++)
    {
        swap(this->map[a][i], this->map[b][i]);
    }
}

void Base::RowAdd(int a, int b)
{
    if (a > m_m || b > m_m || a < 1 || b < 1)
    {
        clog << "操作越出范围,不进行操作\n";
        return;
    }

    for (int i = 1; i <= m_n; i++)
    {
        this->map[a][i] += this->map[b][i];
    }

}

void Base::RowMinus(int a, int b)
{
    if (a > m_m || b > m_m || a < 1 || b < 1)
    {
        clog << "操作越出范围,不进行操作\n";
        return ;
    }
    for (int i = 1; i <= m_n; i++)
    {
        this->map[a][i] -= this->map[b][i];
    }

}

void Base::RowMultiply(int a, Fraction b)
{
    if (a > m_m || a < 1 )
    {
        clog << "操作越出范围,不进行操作\n";
        return;
    }

    for (int i = 1; i <= m_n; i++)
    {
        this->map[a][i] *= b;
    }

}
void Base::ColumSwap(int a, int b)
{
    if (a > m_n || b > m_n || a < 1 || b < 1)
    {
        clog << "操作越出范围,不进行操作\n";
        return ;
    }
    for (int i = 1; i <= m_m; i++)
    {
        swap(this->map[i][a], this->map[i][b]);
    }
}
void Base::ColumAdd(int a, int b)
{
    if (a > m_n || b > m_n || a < 1 || b < 1)
    {
        clog << "操作越出范围,不进行操作\n";
        return ;
    }
    for (int i = 1; i <= m_m; i++)
    {
        this->map[i][a] += this->map[i][b];
    }
}
void Base::ColumMinus(int a, int b)
{
    if (a > m_n || b > m_n || a < 1 || b < 1)
    {
        clog << "操作越出范围,不进行操作\n";
        return ;
    }
    for (int i = 1; i <= m_m; i++)
    {
        this->map[i][a] -= this->map[i][b];
    }
}
void Base::ColumMultiply(int a, Fraction b)
{
    if (a > m_n ||  a < 1)
    {
        clog << "操作越出范围,不进行操作\n";
        return ;
    }
    for (int i = 1; i <= m_m; i++)
    {
        this->map[i][a] *= b;
    }
}
void Base::transpose()
{
    int max_ = max(m_m, m_n);
    for (int i = 1; i < max_; i++)
    {
        for (int j = i + 1; j <= max_; j++)
        {
            swap(this->map[i][j], this->map[j][i]);
        }
    }
    swap(this->m_m, this->m_n);
}

void Base::display()
{
    cout << "名称:" << left << setw(5) << this->m_name << "大小:" << this->m_m << 'X' << this->m_n << endl;
    for (int i = 1; i <= m_m; i++)
    {
        for (int j = 1; j <= m_n; j++)
        {
            cout << left << setw(7) << map[i][j].display();
        }
        cout << endl;
    }
}

Base::~Base()
{
}
Determinant::Determinant(/* args */)
{
}

Determinant::Determinant(const Determinant & a)
{
    m_name = a.m_name;
    m_rank = a.m_rank;
    m_m = m_rank, m_n = m_rank;
    for (int i = 1; i <= m_rank; i++)
    {
        for (int j = 1; j <= m_rank; j++)
        {
            map[i][j] = a.map[i][j];
        }
    }
}

Determinant::Determinant(string na,int n,Fraction* list):Base(na,n,n,list),m_rank(n){}

Determinant Determinant::cofactor(int x=0, int y=0)
{
    if(x>this->m_m||y>this->m_n||x<1||y<1)
    {
        Determinant t(*this);
        return t;
    }
    Determinant B;
    char a=x+'0', b=y+'0';
    B.m_name = this->m_name + "_co_" + a + '&' + b;
    B.m_m = this->m_m - 1, B.m_n = this->m_n - 1,B.m_rank=this->m_rank-1;
    int px = 1;
    for (int i = 1; i <= m_rank; i++)
    {
        if(x==i)
            continue;
        int py = 1;
        for (int j = 1; j <= m_rank; j++)
        {
            if(y==j)
                continue;
            B.map[px][py] = this->map[i][j];
            py++;
        }
        px++;
    }
    return B;
}

Determinant Determinant::triangular()
{
    Determinant B(*this);
    for (int i = 1; i < m_rank; i++)
    {
        for (int j = i + 1; j <= m_rank; j++)
        {
            if (B.map[j][i] != 0)
            {
                Fraction temp = B.map[j][i] / B.map[i][i];
                B.RowMultiply(j, B.map[i][i] / B.map[j][i]);
                B.RowMinus(j, i);
                B.RowMultiply(j, temp);
            }
        }
    }
    return B;
}

Fraction Determinant::calculate()
{
    Determinant B(this->triangular());
    Fraction a(1);
    for (int i = 1; i <= m_rank;i++)
    {
        a *= B.map[i][i];
    }
    return a;
}

Determinant::~Determinant()
{
}
Fraction::Fraction(){}
Fraction::Fraction(const Fraction & a)//拷贝构造函数
{
    denominator = a.denominator;
    molecular = a.molecular;
    positive = a.positive;
}
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
        clog << "存在分母为0的分数，请进行输入检查\n";
        denominator = 1;
        molecular = 1;
    }
}

Fraction::Fraction(bool p , int m = 0, int d = 1) //正负号,分子，分母，
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
        clog << "存在分母为0的分数，请进行输入检查\n";
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
    while (abs(a - int(a)) >= 0.000001) //精度
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
    return calculate(a)==calculate(b);
}

bool operator!=(const Fraction &a, const Fraction &b)
{
    return calculate(a)!=calculate(b);
}
int Matix::rank()
{
    Matix B(*this);//化为行最简形
    bool sign[this->m_m + 1] = {};
    for (int i = 1; i <= this->m_n; i++) //迭代每一列
    {
        for (int j = 1; j <= this->m_m; j++) //迭代每一行找非零主元
        {
            if (B.map[j][i] != 0 && sign[j] != 1) //非零，且该行没有非零主元
            {
                sign[j] = 1; //标记
                for (int k = 1; k <= this->m_m; k++)//对该列每一行非零元素进行清零
                {
                    if (k != j && B.map[k][i] != 0)
                    {
                        Fraction temp = B.map[k][i] / B.map[j][i];
                        B.RowMultiply(k, B.map[j][i] / B.map[k][i]);
                        B.RowMinus(k, j);
                        B.RowMultiply(k, temp);
                    }
                }
                break;
            }
        }
    }
    //计数
    int rank=min(B.m_m,B.m_n);
    for (int i = 1; i <= B.m_m;i++)
    {
        int sum = 0;
        for (int j = 1; j <= B.m_n;j++)
        {
            if(B.map[i][j]==0)
            {
                sum++;
            }
        }
        if(sum==B.m_n)
        {
            rank--;
        }
    }
    return rank;
}
main()
{
    int ls[9] = {2, 5, 8, 2, 5, 1,5,6,7};
    Fraction lis[9];
    for (int i = 0; i < 9;i++)
    {
        lis[i] = Fraction(ls[i]);
        // lis[i] *= -1;
        // cout<<lis[i].display();
    }
    
    Matix m("test", 3, 3, lis);
    m.inverse().display();
    cout << m.rank();
}

