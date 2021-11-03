#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
main()
{
    double a,sum=0,num=1;
    cin >> a;
    while (true)
    {
        sum += (1 / (num*2-1)) * pow(-1, num-1);
        num++;
        if ((1 / (num * 2 - 1))*4 < a)
        {
            break;
        }
    }
    sum *= 4;
    cout << "Pi = " <<fixed<<setprecision(4)<<sum;
}
