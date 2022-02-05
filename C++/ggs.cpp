#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cmath>
#include <ctime>
using namespace std;
main()
{
    unsigned long long n;
    cin >> n;
    unsigned long long  n_2 = n * n;
    unsigned long long n_sqrt2 = n / sqrt(2);
    // unsigned long long *map = new unsigned long long[n_2+1]();
    unsigned long long *_2 = new unsigned long long[n+1]();
    unordered_map<unsigned long long, unsigned long long> dict;
    unsigned long long a = 3, b = 3;
    double t1,t2;
    t1 = clock_t();
    fstream f("ggsgcc.txt",ios::out||ios::trunc);
    streambuf *p=cout.rdbuf(f.rdbuf());
    for (unsigned long long i = 1; i <= n; i++)
    {
        dict.insert({i * i, i});
        // map[i * i] = i;
    }
    for (unsigned long long i = 1; i <= n; i++)
    {
        // dict.insert({i * i, i});
        _2[i] = i*i;
    }
    while (a < n_sqrt2)
    {
        b += 1;
        unsigned long long c = _2[a]+_2[b];
        if (c <= n_2)
        {
            // if (dict.find(c) != dict.end())
            if(dict.find(c)!=dict.end())
            {
                cout << a << ' ' << b << ' ' << dict[c] << '\n';
            }
        }
        else
            a = a + 1, b = a;
    }
    t2 = clock_t();
    cout.rdbuf(p);
    cout
        << "end";
}