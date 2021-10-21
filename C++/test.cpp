#include <cstring>
#include <iostream>
using namespace std;
main()
{
    int n, m;
    cin >> n >> m;
    bool bianhao[n][n];
    memset(bianhao, 0, sizeof(bianhao));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        bianhao[a - 1][b - 1] = true;
        bianhao[b - 1][a - 1] = true;
    }
    int K;
    cin >> K;
    for (int p = 0; p < K; p++)
    {
        bool copys[n][n];
        memcpy(copys, bianhao, sizeof(copys));
        int num;
        bool boolss = 1;
        cin >> num;
        for (int y = 0; y < num; y++)
        {

            int NO;
            cin >> NO;
            for (int i = 0; i < n; i++)
            {
                copys[NO - 1][i] = false;
                copys[i][NO - 1] = false;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (copys[i][j])
                {
                    boolss = 0;
                }
            }
        }
        if (boolss)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}