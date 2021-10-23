#include<iostream>
using namespace std;
main()
{
    long long n,sum=0;
    cin >> n;
    long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n-1;i++)
    {
        for (int j = i + 1; j < n;j++)
        {
            if(a[i]>a[j])
            {
                sum++;
            }
        }
    }
    cout << sum;
}
