#include <cstdio>
#include <iostream>
using namespace std;
int isprime(int n)
{
    int a = 1;
    int i;
    if (n == 1)
    {
        a = 0;
    }
    else
        for (i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                a = a - 1;
                break;
            }
        }
    return a;
}
int main()
{
    int i;
    int c;
    while (i <= 100)
    {
        c = isprime(i);
        if (c == 0)
        {
            continue;
        }
        printf("%6d", i);
        i++;
    }

    return 0;
}