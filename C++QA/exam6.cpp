#include <iostream>
using namespace std;
int abss(int a)
{
    if (a < 0)
    {
        a = -a;
    }
    return a;
}
main()
{
    string s;
    cin >> s;
    int a, b, c;
    cin >> a >> b >> c;
    int sum = 0;
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '1')
            sum++;
    }
    int ans = 0;
    if (a <= b)
    {
        if (l - sum != sum)
        {
            ans += min(abss(l - 2 * sum) / 2 * (a + c), abss(l - 2 * sum) / 2 * (b));
            sum = min(sum, l - sum);
        }
        ans += sum * a;
    }
    else
    {
        if (l - sum != sum)
        {
            ans += min(a * min(sum, l - sum), min(sum, l - sum) * (c + b));
            sum = abss(l - 2 * sum);
            ans += sum + b;
        }
        else
        {
            if(sum%2==1)
            ans += min(a + (sum - 1) * b, c + sum * b);
            else
                ans += sum * b;
        }
    }

    cout << ans;
}