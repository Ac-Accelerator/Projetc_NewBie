#include <cstring>
#include <iostream>
using namespace std;
int indexff[1111]={0};int datass[1111]={0};
main()
{
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int lelele = -10;
        if (i != 0)
        {
            cout << '\n';
        }
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            cin >> datass[j];
            indexff[j] = 1;
        }
        for (int j = 1; j <= n;j++)
        {
            for (int k = 1; k <= j;k++)
            {
                if(datass[k]<datass[j])
                {
                    indexff[j] = max(indexff[j], indexff[k] + 1);
                }
            }
        }
        for (int j = 1; j <= n;j++)
        {
            lelele = max(lelele, indexff[j]);
        }
        cout << lelele<<endl;
    }
}