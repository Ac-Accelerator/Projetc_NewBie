#include <algorithm>
#include <iostream>
using namespace std;
struct node
{
    int num = 0;
    bool done = 0;
};
node nodes[2002][2002];
void dfs(int, int);
int sum = 0;
main()
{
    cout << "我是中文";
}
void dfs(int i, int j)
{
    if (nodes[i][j].done == 1)
    {
        return;
    }
    nodes[i][j].done = 1;
    if (nodes[i + 1][j].num == 1)
    {
        dfs(i + 1, j);
    }
    if (nodes[i - 1][j].num == 1)
    {
        dfs(i - 1, j);
    }
    if (nodes[i][j + 1].num == 1)
    {
        dfs(i, j + 1);
    }
    if (nodes[i][j - 1].num == 1)
    {
        dfs(i, j - 1);
    }
}