#include <iostream>
using namespace std;
unsigned long long fast(unsigned long long, unsigned long long,unsigned long long);
main()
{
    int n;
    cin >> n;
    unsigned long long a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        cout << fast(a, b,c)  << endl;
    }
}
unsigned long long fast(unsigned long long a, unsigned long long b,unsigned long long c)
{   if(b==0)
{
    return 1%c;
}
    if (b == 1)
    {
        return a%c;
    }
    if (b == 2)
    {
        return (a%c)*(a%c)%c;
    }
    if (b % 2)
    {
        return  fast((a%c)*(a%c), b / 2,999999999)*a%c;
    }
    else
        return fast((a%c)*(a%c), b / 2,c);
}