#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
string fastpow(string, long);
string bigmuit(string, string);
string turnlongtostr(long);
bool dividedby2(string);
long mod(string, long);
main()
{
    int n;
    cin >> n;
    long a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        cout << fastpow(turnlongtostr(a), b);
    }
}
string fastpow(string a, long b)
{
    if (b == 1)
    {
        return a;
    }
    if (b == 2)
    {
        return bigmuit(a, a);
    }
    if (b % 2)
    {
        return bigmuit(a, fastpow(bigmuit(a, a), b / 2));
    }
    else
        return fastpow(bigmuit(a, a), b / 2);
}
string turnlongtostr(long a)
{
    string d = "";
    while (a != 0)
    {
        d += (a % 10) + '0';
        a /= 10;
    }
    reverse(d.begin(), d.end());
    return d;
}
bool dividedby2(string a)
{
    int num = a[a.length() - 1];
    return num % 2;
}
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
	for (int i = 0; i < lena; i++)
	{
		for (int j = 0; j < lenb; j++)
		{
			sum[i + j] += numa[i] * numb[j];
		}
	}
	for (int i = 0; i < lena + lenb; i++)
	{
		sum[i + 1] += sum[i] / 10;
		sum[i] %= 10;
	}
	string sums;
	bool bools = 0;
	for (int i = 0; i < lena + lenb; i++)
	{
		if (sum[lena + lenb - i - 1] != 0 && bools == 0)
		{
			bools = 1;
		}
		if (bools)
			sums += (sum[lena + lenb - i - 1] + 48);
	}
	return sums;
}
long mod(string a,long b)
{
    int n = turnlongtostr(b).length();
    
}