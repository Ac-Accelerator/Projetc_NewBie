#include <iostream>
using namespace std;
class area
{
public:
    int s, e;
};
main()
{
    int m, n;
    cin >> n >> m;
    area list[n];
    for (int i = 0; i < n; i++)
    {
        cin >> list[i].e;
        list[i].s = list[i].e - 1;
    }
    
}