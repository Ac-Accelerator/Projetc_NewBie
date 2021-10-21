#include <iostream>
using namespace std;
long long jc(int);
main()
{
    int n;
    cin >> n;
    cout<<"product = " << jc(n);
}
long long jc(int n)
{
    if(n==0)
    {
        return 1;
    
    }
    return jc(n - 1) * n;
}