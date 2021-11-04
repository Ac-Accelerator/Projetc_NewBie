#include <iostream>
#include <ctime>
using namespace std;
long long mod_mul(long long a, long long b, long long mod);
long long mod_pow(long long a, long long n, long long mod);
bool isprime(long long n);
long long mod_mul(long long a, long long b, long long mod)//快速乘法取余
{
    long long res = 0;
    while (b)
    {
        if (b % 2)
            res = (res + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return res;
}

long long mod_pow(long long a, long long n, long long mod)//快速幂取余
{
    long long ans = 1;
    while (n > 0)
    {
        if (n % 2)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        n /= 2;
    }
    return ans;
}
bool Miller_Rabin(long long n)// Miller-Rabin随机算法检测n是否为素数
{
    srand((int)time(0));
    if (n == 2)//是2就返回true
        return true;
    if (n < 2 || !(n % 2))//小于2或者是2的倍数返回false
        return false;
    long long m = n - 1, k = 0;//对于给定的n，找到k、m使得"n-1=(2^k)*m"成立
    while (!(m % 2))//保证m是奇数
    {
        k++;
        m /=2;
    }
    for (int i = 1; i <= 4; i++) // Miller-Rabin测试4次
    {
        long long a = rand() % (n - 1) + 1;//随机从[1,n-1]中选取a
        long long x = mod_pow(a, m, n);//求出(a^m)%n
        long long y;
        for (int j = 1; j <= k; j++)//对x不断进行(平方后对n取模)操作，取遍[1,k]
        {
            y = mod_mul(x, x, n);
            if (y == 1 && x != 1 && x != n - 1)//只要得到1，就未能通过检验，是合数
                return false;
            x = y;//赋值并进行新一轮检验
        }
        if (y != 1)//取遍后如果y=1,则是合数
            return false;
    }
    return true;
}