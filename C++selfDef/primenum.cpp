//质因数分解
//传入要分解的数、要储存分解结果的数组
int primenum(int n, int A[])
{
    int x = 0;
    for (int i = 0; i <= (n + 1) / 2;)
    {
        if (n % i == 0)
        {
            A[x] =i;
            n /= i;
            x++;
        }
        else
            i++;
    }
    return x;
}