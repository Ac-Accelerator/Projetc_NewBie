#include<iostream>
using namespace std;
int zdh(int,int ,int ,int);
main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    cout << zdh(a,n,0,n-1);
}
int zdh(int a[],int n,int s,int e)
{
    if(n==1)
    {
        return a[s];
    }
    int m = n / 2;
    int sum1 = zdh(a, m, 0, m);
    int sum2 = zdh(a, n - m, m + 1, e);
    for (int i = ;)
}
