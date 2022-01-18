#include <iostream>
using namespace std;
int list[1024];
main()
{
	int a, b, point = 0;
	cin >> a >> b;
	cout << a << '=';
	while (a != 0)
	{
		if (a < 0)
		{
			list[point++] = (a - (a / b + 1) * b) % b;
			a = (a - list[point - 1]) / b;
		}
		else
		{
			list[point++] = a % b;
			a /= b;
		}
	}
	for (int i = point - 1; i >= 0; i--)
	{
		if (list[i] > 9)
		{
			char f = list[i] - 10 + 'A';
			cout << f;
			continue;
		}
		cout << list[i];
	}
	cout << "(base" << b << ")";
}