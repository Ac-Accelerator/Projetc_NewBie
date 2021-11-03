#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double x;
	cin >> x;
	if(x>=0)
	{
		cout <<fixed<<setprecision(2)<< "f("<<x<<") = "<<sqrt(x);
	}
	else
		cout <<fixed<<setprecision(2)<<"f("<<x<<") = " <<(pow(x + 1, 2) + 2 * x + 1 / x);
	return 0;
}
