#include <cstring>
#include <iostream>
using namespace std;
#define MAX_CHAR 256
void GetNext(string &p, int &ot, int *Next, unsigned long long sizes);
int Sunday(string &origin, int &ol, string &target, int &tl);
void GetNext(string &p, int &ot, int *Next, unsigned long long sizes) //标记各个字符所在的最大位置
{
    memset(Next, 0, sizes);
    for (int i = 1; i <= ot; i++) //标记
        Next[int(p[i - 1])] = i;
}
int Sunday(string &origin, int &ol, string &target, int &tl)
{
    int Next[MAX_CHAR], //声明next数组，用于存放字符位移量
        sum = 0;        //匹配的数量
    unsigned long long sizes = sizeof(Next);
    GetNext(target, tl, Next, sizes);

    int j, k; // origin 的下标 . target 的下标
    int i = 0;
    while (i <= ol - tl) //走到尾部退出循环
    {
        j = i, k = 0;                                      //origin的下标指向最新的位置                                             //target的下标重置，指向首位
        while (j < ol && k < tl && origin[j] == target[k]) //如果相同，且未越界，则进行下一个字符的比对
            j++, k++;

        if (k == tl) //如果比对成功，则有k= target的长度，可进行操作
        {
            sum++;
        }
        if (i + tl < ol)                               //如果在范围内，则重新将i定义为
            i += (tl - Next[int(origin[i + tl])] + 1); ////////****算法核心****////////
        /*  origin[i+tl]  指的是原字符串下一个字符，next[]是储存该字符位移量的数组。
            如果target里有该字符，则进行指定长度的位移，没有则位移 (target的长度 +1)   */
        else
            break; //优化
    }
    return sum;
}