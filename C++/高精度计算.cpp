#include <algorithm>
#include <iostream>
using namespace std;
string bigadd(string, string);
string bigless(string, string);
string bigmuit(string, string);
string turnlongtostr(long long);
long long turnstrtolong(string);
bool dividedby2(string);
string factorial(string);
string fastpow(string, string);
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
bool dividedby2(string a)
{
    int num = a[a.length() - 1];
    return num % 2;
}
string bigless(string a, string b)
{
	int lena = a.length(), lenb = b.length(), jin = 0;
	int t = max(lena, lenb);
	int sum[t] = {0}, numa[t] = {0}, numb[t] = {0};
	for (int i = lena - 1, j = 0; i >= 0; i--, j++)
	{
		numa[j] = a[i] - 48;
	}
	for (int i = lenb - 1, j = 0; i >= 0; i--, j++)
	{
		numb[j] = b[i] - 48;
	}
	for (int i = 0; i < t; i++)
	{
		sum[i] = (10 + numa[i] - numb[i] + jin) % 10;
		if (numa[i] < numb[i])
		{
			jin = -1;
		}
		else
			jin = 0;
	}
	string sums;
	for (int i = 0; i < t; i++)
	{
		if (sum[t - i - 1] == 0 && i == 0)
		{
			continue;
		}
		sums += (sum[t - i - 1] + 48);
	}
	return sums;
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
string fastpow(string a, string b)
{
	if (b == "1")
	{
		return a;
	}
	if (b == "2")
	{
		return bigmuit(a, a);
	}
	if (dividedby2(b))
	{
		return bigmuit(a, fastpow(bigmuit(a, a), turnlongtostr(turnstrtolong(b) / 2)));
	}
	else
		return fastpow(bigmuit(a, a), turnlongtostr(turnstrtolong(b) / 2));
}
string turnlongtostr(long long a)
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
long long turnstrtolong(string a)
{
	int out = 0;
	for (unsigned long long i = 0; i < a.length(); i++)
	{
		out = (a[i] - '0') + 10 * out;
	}
	return out;
}
string factorial(string a)
{
	long long n = turnstrtolong(a);
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
