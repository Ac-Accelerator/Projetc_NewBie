#include <iostream>
#include <fstream>
#include <algorithm>
#include "function.h"
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
Goods *Goods::G_Readd(long long *n) //��������done
{
    string Class, name, brand;
    long long num, time;
    double prize, cost;
    fstream data("data", ios::in);
    streambuf *oldin = cin.rdbuf(data.rdbuf());
    cin >> *n; //��ȡ���ݴ�С
    Goods *g = new Goods[*n];
    for (int i = 0; i < *n; i++) //��������
    {
        cin >> Class >> name >> brand >> prize >> num >> time >> cost;
        g[i].m_class = Class;
        g[i].m_names = name;
        g[i].m_brand = brand;
        g[i].m_prize = prize;
        g[i].m_num = num;
        g[i].m_time = time;
        g[i].m_cost = cost;
    }
    cin.rdbuf(oldin); //������ָ�뷵�ظ�����
    data.close();
    return g;
}
Goods *Goods::G_Reads(long long *n) //��ȡͳ��done
{
    string Class, name, brand;
    long long num;
    fstream data("statistic", ios::in);
    streambuf *oldin = cin.rdbuf(data.rdbuf());
    cin >> *n; //��ȡ���ݴ�С
    Goods *g = new Goods[*n];
    for (int i = 0; i < *n; i++) //��������
    {
        cin >> Class >> name >> brand >> num;
        g[i].m_class = Class;
        g[i].m_names = name;
        g[i].m_brand = brand;
        g[i].m_num = num;
    }
    cin.rdbuf(oldin); //������ָ�뷵�ظ�����
    data.close();
    return g;
}
Goods *Goods::G_Readl(long long *n)
{
    long long time, profit, num;
    string Class, name;
    fstream log("log", ios::in);
    streambuf *oldin = cin.rdbuf(log.rdbuf());
    cin >> *n; //��ȡ���ݴ�С
    Goods *g = new Goods[*n];
    for (int i = 0; i < *n; i++) //��������
    {
        cin >> time >> Class >> name >> profit >> num;
        g[i].m_class = Class;
        g[i].m_names = name;
        g[i].m_time = time;
        g[i].m_profit = profit;
        g[i].m_num = num;
    }
    sort(g, g + *n, time_compare); //��ʱ������
    cin.rdbuf(oldin);              //������ָ�뷵�ظ�����
    log.close();
    return g;
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