#include <fstream>
#include <iostream>
using namespace std;
void initial_data()
{
    fstream exist("data");
    if (!exist.good())
    {
        fstream exist("data", ios::out);
        streambuf *oldout = cout.rdbuf(exist.rdbuf());
        cout << '0' << endl;
        cout.rdbuf(oldout);
    }
    exist.close();
}
main()
{
    initial_data();
}