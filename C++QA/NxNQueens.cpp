#include <iostream>
#include <cstring>
using namespace std;
int N;
int queenpots[100];//存放放好的皇后的位置。第几行第几个
void Nqueen(int );
main()
{   
    cin >> N;
    Nqueen(0);//从第0行开始摆放皇后
    
}
void Nqueen(int k)//在0~k-1行皇后都已经摆好的情况下，摆第k行以及其后的皇后
{
    int i;
    if(k==N)//n个皇后已经摆好
    {
        for (i = 0; i < N;i++)
        {
            cout << queenpots[i] + 1 << ' ';
        }
        cout << endl;
        return;
    }
    for (i = 0; i < N;i++)//逐个尝试k个皇后的位置
    {
        int j;
        for (j = 0; j < k;j++)//和已经摆好的k个皇后作比较，看是否冲突
        {
            if(queenpots[j]==i||abs(queenpots[j]-i)==abs(k-j))//冲突的情况，break尝试下一次
            {
                break;
            }
        }
        if(j==k)//不冲突
        {
            queenpots[k] = i;//摆放
            Nqueen(k + 1);//继续开始
        }
    }
}