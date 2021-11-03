#include <iostream>
using namespace std;
bool notpri[2147483648] = {1, 1};
long long pri[21474];
main()
{
    int point = 0;
    for (int i = 2; i < 2147483648; i++)
    {
        if (notpri[i])
        {
            pri[point++];
        }
        for (int d = 1; d < 2147483648; d++)
        {
            if (i * pri[d] > 2147483648)
            {
                break;
            }
            notpri[i * pri[d]] = 1;
            if(i%pri[d]==0)
            {
                break;
            }
        }
    }
    int n;
    cin >> n;
    if(notpri[abs(n)])
    {
        cout << "No";
    }
    else
        cout << "Yes";
}
