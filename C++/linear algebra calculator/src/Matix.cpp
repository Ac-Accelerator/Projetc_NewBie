#include "Matix.h"
Matix::Matix(string na, int m, int n, Fraction *list) : Base(na, m, n, list) {}
Matix::Matix() {}
Matix::Matix(string na, int n, Fraction num)
{
    m_m = n, m_n = n;
    m_name = na;
    Fraction temp(0);
    for (int i = 1; i <= m_m; i++)
    {
        for (int j = 1; j <= m_n; j++)
        {
            map[i][j] = temp;
        }
    }
    for (int i = 1; i <= n; i++)
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
        clog << "�˾�����ת��Ϊ����ʽ\n";
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
        clog << "�������������������������\n";
        return B;
    }
    B.m_name = this->m_name + "_Adj";
    B.m_m = this->m_m, B.m_n = this->m_n;
    Determinant temp = this->Det();
    for (int i = 1; i <= B.m_m; i++)
    {
        for (int j = 1; j <= B.m_n; j++)
        {
            B.map[j][i] = temp.cofactor(i, j).calculate();
            if ((i + j) % 2)
            {
                B.map[i][j] *= -1;
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
        clog << "�������������������������\n";
        return B;
    }
    Matix B = this->adjoint();
    Matix t("1/Detv", this->m_n, 1 / de);
    B *= t;
    return B;
}

Matix operator+(const Matix &a, const Matix &b)
{
    Matix B;
    if ((a.m_m != b.m_m) || (a.m_n != b.m_n))
    {
        clog << "�������������������������\n";
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
        clog << "�������������������������\n";
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
        clog << "�������������������������\n";
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

int Matix::rank()
{
    Matix B(*this); //��Ϊ�������
    bool sign[this->m_m + 1] = {};
    for (int i = 1; i <= this->m_n; i++) //����ÿһ��
    {
        for (int j = 1; j <= this->m_m; j++) //����ÿһ���ҷ�����Ԫ
        {
            if (B.map[j][i] != 0 && sign[j] != 1) //���㣬�Ҹ���û�з�����Ԫ
            {
                sign[j] = 1;                         //���
                for (int k = 1; k <= this->m_m; k++) //�Ը���ÿһ�з���Ԫ�ؽ�������
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
    //����
    int rank = min(B.m_m, B.m_n);
    for (int i = 1; i <= B.m_m; i++)
    {
        int sum = 0;
        for (int j = 1; j <= B.m_n; j++)
        {
            if (B.map[i][j] == 0)
            {
                sum++;
            }
        }
        if (sum == B.m_n)
        {
            rank--;
        }
    }
    return rank;
}

bool operator==(const Matix &a, const Matix &b)
{
    Matix c(a), d(b);
    return c.rank() == d.rank();
}

bool Equivalent(const Matix &a, const Matix &b)
{
    return a == b;
}

Matix operator*(const Matix &a, int b)
{
    Fraction temp(b);
    Matix B(a);
    for (int i = 1; i < a.m_m; i++)
        for (int j = 1; i < a.m_n; j++)
            B.map[i][j] *= temp;
    return B;
}