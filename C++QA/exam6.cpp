#include <iostream>
#include <map>
using namespace std;
struct node
{
    int sex;
    string firstname;
};
map<string, node> mp;
bool find(string, string );
main()
{
    int n, t;
    string firstname, b, secondname, d;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> firstname >> secondname;
        if (secondname[secondname.length() - 1] == 'f')
            mp[firstname].sex = 2;
        else if (secondname[secondname.length() - 1] == 'm')
            mp[firstname].sex = 1;
        else if (secondname[secondname.length() - 1] == 'n')
        {
            mp[firstname].sex = 1;
            string temp = secondname.substr(0, secondname.length() - 4);
            mp[firstname].firstname = temp;
        }
        else if (secondname[secondname.length() - 1] == 'r')
        {
            mp[firstname].sex = 2;
            string temp = secondname.substr(0, secondname.length() - 7);
            mp[firstname].firstname = temp;
        }
    }
    cin >> t;
    while (t--)
    {
        cin >> firstname >> b >> secondname >> d;
        if (mp.find(firstname) == mp.end() || mp.find(secondname) == mp.end())
        {
            cout << "NA" << endl;
        }
        else if (mp[firstname].sex == mp[secondname].sex)
        {
            cout << "Whatever" << endl;
        }
        else
        {
            if (find(firstname, secondname))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}

bool find(string firstname, string secondname)
{
    int fa = 1, fb = 1;
    for (string sa = firstname; !sa.empty(); sa = mp[sa].firstname, fa++)
    {
        fb = 1;
        for (string sb = secondname; !sb.empty(); sb = mp[sb].firstname, fb++)
        {
            if (fa >= 5 && fb >= 5)
                return 1;
            if (sa == sb && (fa < 5 || fb < 5))
            {
                return 0;
            }
        }
    }
    return 1;
}