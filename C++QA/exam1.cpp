#include <iostream>
using namespace std;
main()
{
    int a;
    cin >> a;
    string origin;
    // int n[a], pn = 0;
    // int e[a], pe = 0;
    // int u[a], pu = 0;
    // int q[a], pq = 0;
    cin >> origin;
    // for (int i = 0; i < a; i++)
    // {
    //     if (origin[i] = 'N')
    //     {
    //         n[pn++] = i;
    //     }
    //     if (origin[i] = 'E')
    //     {
    //         e[pe++] = i;
    //     }
    //     if (origin[i] = 'U')
    //     {
    //         u[pu++] = i;
    //     }
    //     if (origin[i] = 'Q')
    //     {
    //         q[pq++] = i;
    //     }
    // }
    int sum=0;
    for (int i = 0; i < a; i++)
    {
        if(origin[i]=='N')
        {
            for (; i < a;i++)
            {
                if(origin[i]=='E')
                {
                    break;
                }
            }
            for (; i < a;i++)
            {
                if(origin[i]=='U')
                {
                    break;
                }
            }
            for (; i < a;i++)
            {
                if(origin[i]=='Q')
                {
                    break;
                }
            }
            sum++;
        }
    }
    cout << a-4*sum;
}