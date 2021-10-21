#include <iostream>
using namespace std;
string bigmuit(string a, string b)
{
    int lena = a.length(), lenb = b.length();
    int t = max(lena, lenb);
	int sum[lena + lenb] = {0}, numa[t] = {0}, numb[t] = {0};
	for (int i = lena - 1, j = 0; i >= 0; i--, j++)
	{
		numa[j] = a[i] - 48;
	}
	for (int i = lenb - 1, j = 0; i >= 0; i--, j++)
	{
		numb[j] = b[i] - 48;
	}
	for (int i = 0; i < lena;i++)
	{
		for (int j = 0; j < lenb;j++)
		{
			sum[i + j] += numa[i] * numb[j];
		}
	}
	for (int i = 0; i < lena + lenb;i++)
	{
		sum[i + 1] += sum[i] / 10;
		sum[i] %= 10;
	}
		string sums;
	bool bools = 0;
	for (int i = 0; i < lena + lenb; i++)
	{
		if (sum[lena + lenb - i - 1] != 0)
		{
			bools = 1;
		}
		if (bools)
			sums += (sum[lena + lenb - i - 1] + 48);
	}
	return sums;
}
main()
{
    string n, m;

    while(cin>>n>>m)
    {
        cout << bigmuit(n, m)<<endl;
    }
}