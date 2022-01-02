#include <deque>
#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int value;
    bool isdone = 0;
    int connection[100] = {}; //节点对边权值的索引
    int num = 0;
};
int n, e;
deque<Node> C;
void link(Node *); //开始连接
int sum = 0;
main()
{

    while (cin >> n)
    {
        cin >> e;
        Node list[n + 1];
        for (int i = 0; i < e; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            list[a].value = a;
            list[b].value = b;
            list[a].connection[b] = c;
            list[a].num++;
            list[b].connection[a] = b;
            list[b].num++;
        }
        int num = 0;
        for (; num < n; num++)
        {
            link(list);
        }
        if (C.size() != n)
            cout << "There is no minimum spanning tree." << endl;
        else
            cout << sum << endl;
        sum = 0;
        C.clear();
    }
}
void link(Node *list) // 向树添加下一个节点
{

    if (C.size() == 0)
    {
        C.push_back(list[1]);
        C.begin()->isdone = 1;
    }
    //找到集合中最小的边
    int min = 101;              //指向权最小的路径的权
    int mnode = 1;              //指向权最小路径对应的节点
    auto it = C.begin();        // it指向当前节点
    for (; it != C.end(); it++) //遍历集合中的元素
    {
        if (it->num != 0)
            for (int i = 0; i < n + 1; i++)
            {
                if (it->connection[i] != 0 && it->connection[i] < min)
                {
                    min = it->connection[i];
                    mnode = i;
                }
            }
    }
    bool is = 0;
    for (auto y = C.begin(); y != C.end(); y++)
    {
        if (y->value == mnode)
        {
            is = 1;
        }
    }
    if (is)
    {
        return;
    }
    int quan = min;
    sum += quan;              //计算权
    C.push_back(list[mnode]); //并入节点
    C.rbegin()->isdone = 1;
    for (auto f = C.begin(); f != C.end(); f++) //删除路径
    {
        for (auto t = C.begin(); t != C.end(); t++)
        {
            f->connection[t->value] = 0;
        }
    }
}