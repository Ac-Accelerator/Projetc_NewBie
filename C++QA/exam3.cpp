#include <iostream>
using namespace std;
string bds(string);
string xiang(string);
int point = 0;
int lengths;
string outcome;
main()
{
    string compressed;
    cin >> compressed;
    lengths = compressed.length();
    cout << bds(compressed);
}
string bds(string a)
{
    string result;
    result += xiang(a);
    while (point < lengths)
    {
        while (((a[point] >= 'a' && a[point] <= 'z') || (a[point] >= 'A' && a[point] <= 'Z')))
        {
            result += a[point++];
        }
        if (a[point] == '[')
        {
            result += xiang(a);
        }
        if (a[point] == ']')
        {
            point++;
            break;
        }
    }
    return result;
}
string xiang(string a)
{
    if (a[point] == '[')
    {
        point++;
        int num = 0;
        while (a[point] >= '0' && a[point] <= '9')
        {
            num = num * 10 + a[point] - '0';
            point++;
        }
        string cache = bds(a);
        string result;
        for (int i = 0; i < num; i++)
        {
            result += cache;
        }
        return result;
    }
    return "";
}