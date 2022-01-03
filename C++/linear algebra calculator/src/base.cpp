#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
class matix
{
private:
    string name;
    int m, n;                   //分别是行数，列数
    long double square[20][20]; //最大就20x20吧，毕竟要输入400个数很累;
public:
    matix(/* args */);
    matix(string, int, int, long double *);
    long double ValueOfDeterminant(matix); //计算行列式的值
    void display();//展示此矩阵
};
matix::matix() {}
matix::matix(string na, int x, int y, long double *list)
{
    m = x, n = y, name = na;
    int point = 0;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            square[i][j] = list[point++];
}
long double matix::ValueOfDeterminant(matix a)
{
    if (a.m != a.n)
    {
        cout << "error" << endl;
        return 114514795634134; //如果真的是114514就是我的锅，可能是全程序唯一一个bug
    }
    int cache[n];
    int Factorial[n + 1] = {0, 1};
    for (int i = 2; i < n + 1; i++) //计算n的阶乘，以方便进行排列组合
    {
        Factorial[i] = i * Factorial[i - 1];
    }
    for (int i = 0; i < n; i++) //排列组合的第一种
    {
        cache[i] = i;
    }
    long double sum = 0;
    int Reverse_cache[n];
    for (int i = 0; i < Factorial[n]; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (Divide_and_conquer_Reverse(cache, 0, n - 1, Reverse_cache) / 2 == 0) //对逆序对奇偶进行判断
                sum += a.square[k][cache[k]];
            else
                sum -= a.square[k][cache[k]];
        }
        next_permutation(cache, cache + n);//排列组合
    }
    return sum;
}
void matix::display()
{
    cout << setw(8) << name;
    for (int i = 0; i < n;i++)
    {
        cout<<setw(5)<<
    }
}
void Reverse_Merge(int a[], int s, int m, int e, int cache[], int &sum)
{
    int p = 0;
    int i = s, j = m + 1;
    while (i <= m && j <= e)
    {
        if (a[i] > a[j]) //改变了这个符号，使它由大到小排列。
        {
            sum += e - j + 1; //另外增加这一行，每执行此判断语句都可以加上此数对应的逆序数。
            cache[p++] = a[i++];
        }
        else
        {
            cache[p++] = a[j++];
        }
    }
    while (i <= m)
    {
        cache[p++] = a[i++];
    }
    while (j <= e)
    {
        cache[p++] = a[j++];
    }
    for (int i = 0; i < e - s + 1; i++)
    {
        a[s + i] = cache[i];
    }
}
int Divide_and_conquer_Reverse(int a[], int s, int e, int cache[])
{
    int sum = 0;
    if (s < e)
    {
        int m = s + (e - s) / 2;
        Divide_and_conquer_Reverse(a, s, m, cache);
        Divide_and_conquer_Reverse(a, m + 1, e, cache);
        Reverse_Merge(a, s, m, e, cache, sum);
    }
    return sum;
}
