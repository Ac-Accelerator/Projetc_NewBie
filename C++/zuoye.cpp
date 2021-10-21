#include <iostream>
using namespace std;
int shun[1000000], ni[1000000], sign[100000], a[1000000],biggest=-1;
main()
{

    int n, j = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (!sign[a[i]])
        {
            j++;
        }
        shun[i] = j;
        sign[a[i]] = 521;
    }
    memset(sign, 0, sizeof(sign));
    int k = 0;
    for (int i = n; i > 0;i--)
    {
        if(!sign[a[i]])
        {
            k++;
        }
        sign[a[i]] = 520;
        ni[i] = k;
        biggest = max((shun[i-1] + ni[i]), biggest);
    }
    cout << biggest;
}