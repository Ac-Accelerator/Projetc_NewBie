#include <iostream>
using namespace std;
main()
{
    int n, c;
    while(cin>>n>>c)
    {
        int weight[n] = {0}, value[n] = {0}, sum[n*n] = {0};
        for (int i = 0; i < n;i++)
        {
            cin >> weight[i];
        }
        for (int i = 0; i < n;i++)
        {
            cin >> value[i];
        }
        for (int i = 0; i < n;i++)
        {
            for (int k = c; k >= weight[i];k--)
            {
                sum[k] = max(sum[k], sum[k - weight[i]] + value[i]);
            }
        }
        cout << sum[c] << endl;
    }
}