#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
class line
{
    public:
        int a, b, c; //节点，权
};
class node 
{
    public:
    int x, y, z;
};
line list[4000000];
node lis[2000];
int sign[4000000];
int doublm(int);
bool cmp(line a,line b)
{
    return a.c < b.c;
}
int find(int x)
{
    if(sign[x]!=x)
    {
        sign[x] = find(sign[x]);
    }
    return sign[x];
}
main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> lis[i].x >> lis[i].y >> lis[i].z;
    }
    int point = 0;
    for (int i = 0; i < n-1;i++)
    {
        for (int j = i + 1; j < n;j++)
        {
            list[point].c=ceil(sqrt(doublm(lis[i].x-lis[j].x)+doublm(lis[i].y-lis[j].y)+doublm(lis[i].z-lis[j].z)));
            list[point].a = i, list[point++].b = j;
        }
    }
    for (int i = 1; i <point;i++)
    {
        sign[i] = i;
    }
    sort(list, list + point, cmp);
    int num = 0,sum=0;
    for (int i = 0; i < n;i++)
    {
        int u = list[i].a, v = list[i].b;
        if(find(u)==find(v))
        {
            continue;
        }
        num++;
        sign[find(u)] = find(v);
        sum += list[i].c;    
    }
    cout << sum;
}
int doublm(int a)
{
    return a * a;
}