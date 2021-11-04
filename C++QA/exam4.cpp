#include <iostream>
#include <iomanip>
using namespace std;
string factorial(long double n)
{
    string ans = "1";
    for (int i = 1; i <= n; i++)
    {

        int jw = 0;
        for (int j = ans.size() - 1; j >= 0; j--)
        {
            int n = (ans[j] - 48) * i + jw;
            jw = n / 10;
            n = n % 10;
            ans[j] = n + 48;
        }
        while (jw)
        {
            ans = char(jw % 10 + 48) + ans;
            jw /= 10;
        }
    }
    return ans;
}
string bigadd(string, string);
main()
{   
    

}
string bigadd(string a, string b)
{
	int lena = a.length(), lenb = b.length(), jin = 0;
	int t = max(lena, lenb);
	int sum[t + 1] = {0}, numa[t + 1] = {0}, numb[t + 1] = {0};
	for (int i = lena - 1, j = 0; i >= 0; i--, j++)
	{
		numa[j] = a[i] - 48;
	}
	for (int i = lenb - 1, j = 0; i >= 0; i--, j++)
	{
		numb[j] = b[i] - 48;
	}
	for (int i = 0; i <= t; i++)
	{
		sum[i] = (numa[i] + numb[i] + jin) % 10;
		jin = (numa[i] + numb[i] + jin) / 10;
	}
	string sums;
	for (int i = 0; i < t + 1; i++)
	{
		if (sum[t - i] == 0 && i == 0)
		{
			continue;
		}
		sums += (sum[t - i] + 48);
	}
	return sums;
}

