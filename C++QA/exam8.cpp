#include <iostream>
#include <map>
using namespace std;
map<char, bool> chars;
int main()
{
    string a, b;
    while (getline(cin, a) && getline(cin, b))
    {
        int al = a.size();
        int bl = b.size();
        for (int i = 0; i < bl; i++)
        {
            chars[b[i]] = 1;
        }
        for (int i = 0; i < al; i++)
        {
            if (chars[a[i]])
                continue;
            cout << a[i];
        }
        cout << endl;
        chars.clear();
    }
}
