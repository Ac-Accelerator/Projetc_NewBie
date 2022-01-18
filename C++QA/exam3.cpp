#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int map[10000][1000];
bool dfsdone[10010][10011];
void dj(int a, int b, int c, int d);
bool dfs(int, int, int, int);
bool isout(int, int);
int n, m, deep;
int p = 1;
struct obj
{
    int a, b, c, d;
};
obj list[100];
main()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = -1;
    }
    cin >> m;
    int point = 1;
    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        list[point].a = x1, list[point].b = y1, list[point].c = x2, list[point].d = y2;
        map[x1][y1] = point;
        map[x2][y2] = point++;
    }
    for (int i = 1; i < point; i++)
    {
        memset(dfsdone, 0, sizeof(dfsdone));
        deep = 0;
        p = map[list[i].c][list[i].d];
        if (dfs(list[i].a, list[i].b, list[i].c, list[i].d))
        {
            cout << deep << endl;
        }
        else
            cout << -1 << endl;
    }
}
bool notout(int a, int b)
{
    return a >= 0 && b >= 0 && a < n && b < n;
}
bool dfs(int a, int b, int c, int d)
{
    if (a == c && b == d)
    {
        return true;
    }
    if (dfsdone[a][b])
    {
        return false;
    }
    dfsdone[a][b] = 1;
    int ctrl1[4] = {1, 0, -1, 0}, p1 = 0;
    int ctrl2[4] = {0, 1, 0, -1}, p2 = 0;
    for (; p1 < 4; p1++, p2++)
    {
        if (p == map[a + ctrl1[p1]][b + ctrl2[p2]])
        {
            deep++;
            if (dfs(a + ctrl1[p1], b + ctrl2[p2], c, d))
            {
                return true;
            }
        }
        else if (notout(a + ctrl1[p1], b + ctrl2[p2]) && map[a + ctrl1[p1]][b + ctrl2[p2]] == 0)
        {
            deep++;
            if (dfs(a + ctrl1[p1], b + ctrl2[p2], c, d))
            {
                return true;
            }
        }
    }
    return false;
}
