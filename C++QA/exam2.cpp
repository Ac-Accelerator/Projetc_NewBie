#include <iostream>
using namespace std;
main()
{
	int n, m;
	cin >> n >> m;
	cout << max(n, m)<<' ';
	if(n+m>=0)
	{
		cout << n + m;
	}
	else if(n+m<0)
	{
		cout << 0;
	}
	cout << endl;
	if( max(n, m)>m+n)
	{
		cout << "T_T";
	}
	else if(max(n,m)<m+n)
	{
		cout << "^_^";
	}
	else
		cout << "-_-";
	cout << endl;
}