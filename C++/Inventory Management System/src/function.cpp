#include <iostream>
#include <fstream>
#include <algorithm>
#include "function.h"
#include "goods.h"
using namespace std;
void initial_data()
{
    fstream exist("data");//
    if (!exist.good())
    {
        fstream exist("data", ios::out);
        streambuf *oldout = cout.rdbuf(exist.rdbuf());
        cout << '0' << endl;
        cout.rdbuf(oldout);
    }
    exist.close();
}
void initial_statistic()
{
    fstream sexist("statistic");
    if (!sexist.good())
    {
        fstream sexist("statistic", ios::out);
        streambuf *oldout = cout.rdbuf(sexist.rdbuf());
        cout << '0' << endl;
        cout.rdbuf(oldout);
    }
    sexist.close();
}
void initial_log()
{
    fstream lexist("log");
    if (!lexist.good())
    {
        fstream lexist("log", ios::out);
        streambuf *oldout = cout.rdbuf(lexist.rdbuf());
        cout << '0' << endl;
        cout.rdbuf(oldout);
    }
    lexist.close();
}
int menu_out()
{
    cout << "��ӭ����������ϵͳ���˵�\n1.����\n2.����\n3.����\n4.����\n5.ͳ��\n6.�˳�\n����������Ҫ��ɵĲ���:";
    int n;
    while (1)
    {
        cin >> n;
        if (n != 1 && n != 2 && n != 3 && n != 4 && n != 5 && n != 6)
        {
            cout << "�������������������" << endl;
        }
        else
        {
            break;
        }
    }
    return n;
}
void gover_menu_out()
{
    system("cls");
    int func;
    Goods gover;
    while (1)
    {
        cout << "1.��ӹ���\n2.��ѯ����\n3.ɾ������\n4.�޸Ĺ���\n5.�˳�\n��������Ҫ���еĲ���:";
        cin >> func;
        system("cls");
        if (func == 1)
        {
            gover.G_Add();
        }
        else if (func == 2)
        {
            gover.G_Search();
        }
        else if (func == 3)
        {
            gover.G_Delete();
        }
        else if (func == 4)
        {
            gover.G_Change();
        }
        else if (func == 5)
        {
            break;
        }
        else
        {
            cout << "δ����Ĳ���������������" << endl;
        }
    }
}