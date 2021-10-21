#include <algorithm>
#include <functional>
#include <string>
using namespace std;
//排序函数
//传入数组（int、string、unsigned long long）、开始位置(0)、结束位置(0)、顺序（+为从小到大）
void order(int A[], int start = 0, int end = 0, char T = '+')
{
    if (T == '+')
        sort(A + start, A + (end + 1));
    if (T == '-')
        sort(A + start, A + (end + 1), greater<int>());
}
void order(string A[], int start = 0, int end = 0, char T = '+')
{
    if (T == '+')
        sort(A + start, A + (end + 1));
    if (T == '-')
        sort(A + start, A + (end + 1), greater<int>());
}
void order(unsigned long long A[], int start = 0, int end = 0, char T = '+')
{
    if (T == '+')
        sort(A + start, A + (end + 1));
    if (T == '-')
        sort(A + start, A + (end + 1), greater<int>());
}