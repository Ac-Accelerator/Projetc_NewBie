#include <iostream>
using namespace std;

int a[9][9];
bool exist = 0;
main()
{
    int i, j;
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    int max=0,min=0;
    for (int p = 0; p < i;p++)
    {
        for (int q = 0; q < j-1;q++)
        {
            if(a[p][q]<a[p][q+1])
            {
                max = q + 1;
            }
        }
        int k;
        for (k = 0; k < i-1 ;k++)
        {
            if(a[k][max]>a[k+1][max])
            {
                min = k + 1;
            }
        }
        if(min==p)
        {
            cout << "Saddle point:a[" << min << "][" <<max << "]=" << a[min][max];
            exist = 1;
        }
        max = 0;
        min = 0;
    }
    if(!exist)
    {
        cout << "There is no saddle point";
    }
}