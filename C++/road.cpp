#include <cstring>
#include <iostream>
using namespace std;
struct road
{
    int a;
    int b;
    bool bools = 1;
};
main()
{
    int n, m;
    cin >> n >> m;
    road ro[m];
    for (int i = 0; i < m; i++)
    {
        cin >> ro[i].a >> ro[i].b;
    }
    int k;
    cin >> k;
    for (int p = 0; p < k; p++)
    {
        int num;
        cin >> num;
        road copys[m];
        memcpy(copys, ro, sizeof(ro));
        for (int o = 0; o < num; o++)
        {
            int city;
            cin >> city;
            for (int i = 0; i < m; i++)
            {
                if (ro[i].a == city || ro[i].b == city)
                {
                    copys[i].bools = 0;
                }
            }
        }
        int boolsss = 1;
        for (int i = 0; i < m; i++)
        {
            if (copys[i].bools == 1)
            {
                boolsss = 0;
            }
        }
        if (!boolsss)
        {
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }
}
