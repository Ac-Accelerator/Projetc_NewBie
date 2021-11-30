#include "goods.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
Goods::Goods(string G_class, string G_names, string G_brand, double G_prize, double G_num)
{
    m_class = G_class, m_names = G_names, m_prize = G_prize, m_num = G_num, m_brand = G_brand;
}
Goods::Goods() {}
void Goods::G_Add() //��ӣ���������done
{
    string Class, name, brand;
    long long num, time;
    double prize, cost;
    fstream data("data", ios::out | ios::in); //�򿪴�����ݵ��ļ�
    int n;
    streambuf *oldin = cin.rdbuf(data.rdbuf());
    data.seekg(0, ios::beg);
    cin >> n;
    cin.rdbuf(oldin);
    data.seekg(0, ios::end);
    cout << "���������룺��� ���� Ʒ�� �۸� ���� ����ʱ�� �ɱ��������ݼ��Կո������#ֹͣ��" << endl;
    while (1)
    {
        cin >> Class;
        if (Class == "#")
        {
            break;
        }
        cin >> name >> brand >> prize >> num >> time >> cost;
        streambuf *oldout = cout.rdbuf(data.rdbuf()); //��ָ��ָ���µĻ����������ҷ��ؾɵĻ�����ָ��
        cout << Class << ' ' << name << ' ' << brand << fixed << setprecision(0) << ' ' << prize << ' ' << num << ' ' << time << ' ' << cost << endl;
        n++;
        data.seekg(0, ios::beg);
        data.flush();
        cout << n;
        data.seekg(0, ios::end);
        cout.rdbuf(oldout); //��ԭ��Ļ���
        cout << "�ɹ������Ʒ��Ϣ!" << endl;
    }
    data.close();
}
void Goods::G_Statistics() //ˢ��ͳ���ļ�done
{
    map<string, long long> listcache;
    int point = 0;
    long long n;
    Goods *g = G_Readd(&n);
    string *newcache = new string[n];
    for (int i = 0; i < n; i++) //���ݺ���ѹ��
    {
        newcache[i] += g[i].m_class;
        newcache[i] += g[i].m_names;
        newcache[i] += g[i].m_brand;
    }
    datas *lastcache = new datas[n];
    for (int i = 0; i < n; i++) //����ѹ��
    {
        if (listcache.find(newcache[i]) != listcache.end())
        {
            lastcache[listcache[newcache[i]]].numb += g[i].m_num;
        }
        else
        {
            listcache[newcache[i]] = point++;
            lastcache[listcache[newcache[i]]].Class = g[i].m_class;
            lastcache[listcache[newcache[i]]].name = g[i].m_names;
            lastcache[listcache[newcache[i]]].brand = g[i].m_brand;
            lastcache[listcache[newcache[i]]].numb += g[i].m_num;
        }
    }
    fstream eco("statistic", ios::in | ios::out | ios::trunc); //��ͳ���ļ�
    streambuf *oldout = cout.rdbuf(eco.rdbuf());
    cout << point << endl;
    for (int i = 0; i < point; i++)
    {
        cout << lastcache[i].Class << ' ' << lastcache[i].name << ' ' << lastcache[i].brand << ' ' << fixed << setprecision(0) << lastcache[i].numb << endl;
    }
    cout.rdbuf(oldout);
    eco.close();
    cout << "���ݿ��Ѹ���" << endl;
    cout << "���" << ' ' << "����" << ' ' << "Ʒ��" << ' ' << "����" << endl;
    for (int i = 0; i < point; i++)
    {
        cout << lastcache[i].Class << ' ' << lastcache[i].name << ' ' << lastcache[i].brand << ' ' << lastcache[i].numb << endl;
    }
    delete[] g;
    delete[] lastcache;
    delete[] newcache;
}
void Goods::G_Out() //��������done
{
    G_Statistics();
    string Class, name;
    cout << "������Ҫ��������Ʒ���:";
    cin >> Class;
    cout << "������Ҫ������Ʒ��������:";
    cin >> name;
    long long n, num = 0;
    Goods *t = G_Reads(&n);
    for (int i = 0; i < n; i++)
    {
        if (t[i].m_class == Class && t[i].m_names == name)
        {
            num = t[i].m_num;
        }
    }
    if (num != 0)
    {
        int outnums;
        long long time;
        cout << "��ʣ��" << num << "�������������������:";
        while (1)
        {
            cin >> outnums;
            if (num < outnums)
            {
                cout << "����������������:";
            }
            else
            {
                cout << "�������������:";
                cin >> time;
                Goods *g = G_Readd(&n);
                bool *sign = new bool[n]{0}; //����������飬��ֵΪ0���ֲ��䣬��ֵΪ1ɾ������ֵΪ2�޸ġ�
                long long deletenum = 0;
                double money = 0;
                for (int i = 0; i < n; i++)
                {
                    if (g[i].m_class == Class && g[i].m_names == name)
                    {
                        if (g[i].m_num <= outnums)
                        {
                            sign[i] = 1;
                            money += g[i].m_cost * m_num;
                            deletenum++;
                            outnums -= g[i].m_num;
                        }
                        else
                        {
                            money += g[i].m_cost * outnums;
                            g[i].m_num -= outnums;
                            break;
                        }
                    }
                }
                fstream data("data", ios::in | ios::out | ios::trunc);
                streambuf *oldout = cout.rdbuf(data.rdbuf());
                cout << n - deletenum << endl;
                for (int i = 0; i < n; i++)
                {
                    if (sign[i] == 0)
                    {
                        cout << g[i].m_class << ' ' << g[i].m_names << ' ' << g[i].m_brand << ' ' << fixed << setprecision(0) << g[i].m_prize << ' ' << g[i].m_num << ' ' << g[i].m_time << ' ' << g[i].m_cost << endl;
                    }
                }
                cout.rdbuf(oldout);
                data.close();
                fstream log("log", ios::in | ios::out);
                streambuf *oldin = cin.rdbuf(log.rdbuf());
                log.seekg(0, ios::beg);
                int snum;
                cin >> snum;
                cin.rdbuf(oldin);
                streambuf *oldout1 = cout.rdbuf(log.rdbuf());
                log.seekg(0, ios::beg);
                cout << snum + 1 << endl;
                log.seekg(0, ios::end);
                cout << time << ' ' << Class << ' ' << name << ' ' << money << ' ' << outnums << endl;
                cout.rdbuf(oldout1);
                break;
                delete[] g;
                delete[] sign;
            }
        }
        G_Statistics();
    }
    else
        cout << "û�и���Ʒ" << endl;
    cout << endl;
    system("pause");
    delete[] t;
}
void Goods::G_Delete() //ɾ������done
{
    string Class, name;
    cout << "������Ҫɾ������Ʒ���:";
    cin >> Class;
    cout << "������Ҫɾ����Ʒ��������:";
    cin >> name;
    long long n;
    Goods *g = G_Readd(&n);
    int num = 0;
    bool sign[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if (g[i].m_class == Class && g[i].m_names == name)
        {
            sign[i] = 1, num++;
        }
    }
    if (num == 0)
    {
        cout << "��Ʒ������" << endl;
        system("pause");
        system("cls");
        return;
    }
    fstream newdata("data", ios::in | ios::out | ios::trunc);
    streambuf *oldout = cout.rdbuf(newdata.rdbuf());
    cout << n - num << endl;
    for (int i = 0; i < n; i++)
    {
        if (sign[i] == 0)
        {
            cout << g[i].m_class << ' ' << g[i].m_names << ' ' << g[i].m_brand << ' ' << fixed << setprecision(0) << g[i].m_prize << ' ' << g[i].m_num << ' ' << g[i].m_time << ' ' << g[i].m_cost << endl;
        }
    }
    cout.rdbuf(oldout); //���ָ�뷵����Ļ
    newdata.close();
    cout << "ɾ���ɹ�" << endl;
    system("pause");
    system("cls");
    delete[] g;
}
void Goods::G_Search() //���ҹ���done
{
    string Class, name, brand;
    long long n;
    Goods *g = G_Readd(&n);
    Goods *cache = new Goods[n];
    int choice;
    while (1)
    {
        system("cls");
        cout << "��ѡ����ҵķ�ʽ" << endl
             << "1.��Ʒ���" << endl
             << "2.��Ʒ����" << endl
             << "3.Ʒ��" << endl
             << "4.��������" << endl
             << "5.����" << endl;
        cin >> choice; //����ѡ��
        if (choice == 5)
        {
            system("cls");
            break;
        }
        else if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
        {
            system("cls");
            cout << "������Ҫ���ҵ���Ϣ��";
            string target;
            cin >> target;
            while (target != "#")
            {
                int num = 0, point = 0;
                if (choice == 1)
                {
                    for (int i = 0; i < n; i++)
                    {
                        if (g[i].m_class == target)
                        {
                            num++, cache[point++] = g[i];
                        }
                    }
                }
                else if (choice == 2)
                {
                    for (int i = 0; i < n; i++)
                    {
                        if (g[i].m_names == target)
                        {
                            num++, cache[point++] = g[i];
                        }
                    }
                }
                else if (choice == 3)
                {
                    for (int i = 0; i < n; i++)
                    {
                        if (g[i].m_brand == target)
                        {
                            num++, cache[point++] = g[i];
                        }
                    }
                }
                else if (choice == 4)
                {
                    int l = target.length();
                    long long date = 0;
                    for (int i = 0; i < l; i++)
                    {
                        date = date * 10 + target[i] - '0';
                    }
                    for (int i = 0; i < n; i++)
                    {

                        if (g[i].m_time == date)
                        {
                            num++, cache[point++] = g[i];
                        }
                    }
                }
                if (num == 0)
                {
                    cout << "�Ҳ��������Ϣ" << endl;
                }
                else
                {
                    cout << "��ѯ��" << num << "����Ϣ,����" << endl;
                    cout << "����" << ' ' << "����" << ' ' << "Ʒ��" << ' ' << "�۸�" << ' ' << "���" << ' ' << "��������" << ' ' << "�ɱ�" << endl;
                    for (int i = 0; i < point; i++)
                    {
                        cout << cache[i].m_class << ' ' << cache[i].m_names << ' ' << cache[i].m_brand << ' ' << cache[i].m_prize << ' ' << cache[i].m_num << ' ' << cache[i].m_time << ' ' << cache[i].m_cost << endl;
                    }
                }
                cout << "��Ϣ��ʾ��ϣ������Լ�������������������������#���ز˵���" << endl;
                cin >> target;
                system("cls");
            }
        }
        else
        {
            cout << "����Ĳ˵�ѡ��,����������" << endl;
            system("pause");
        }
    }
    delete[] cache;
    delete[] g;
}
void Goods::G_Profit()
{

    long long n, time1, time2, point = 0;
    map<string, long long> pointlist;
    Goods *l = G_Readl(&n);
    Goods *newlist = new Goods[n]; //�����������ݵ�����
    if (n == 0)
    {
        cout << "�޼�¼" << endl;
    }
    else
    {
        cout << "��������Ҫͳ�Ƶ�ʱ�䷶Χ\n�Ѿ����ص�ʱ�䷶Χ��" << fixed << setprecision(0) << l[0].m_time << '-' << l[n - 1].m_time << endl;
        cin >> time1 >> time2;
        for (int i = 0; i < n; i++)
        {
            if (l[i].m_time >= time1)
            {
                string cache;
                cache = cache + l[i].m_class + l[i].m_names;
                if (pointlist.find(cache) != pointlist.end())
                {
                    newlist[pointlist[cache]].m_profit += l[i].m_profit;
                    newlist[pointlist[cache]].m_num += l[i].m_num;
                }
                else
                {
                    pointlist[cache] = point++;
                    newlist[pointlist[cache]].m_num = l[i].m_num;
                    newlist[pointlist[cache]].m_class = l[i].m_class;
                    newlist[pointlist[cache]].m_names = l[i].m_names;
                    newlist[pointlist[cache]].m_profit = l[i].m_profit;
                }
                if (l[i + 1].m_time > time2)
                {
                    break;
                }
            }
        }
        sort(newlist, newlist + point, profit_compare);
        cout << "��ѯ������" << point << "����Ϣ" << endl;
        cout << "����  ����  ����  ����\n";
        for (int i = 0; i < point; i++)
        {
            cout << newlist[i].m_class << ' ' << newlist[i].m_names << ' ' << newlist[i].m_num << ' ' << newlist[i].m_profit << endl;
        }
        cout << "��Ϣ��ʾ����" << endl;
    }
    system("pause");
    delete[] newlist;
    delete[] l;
}
bool time_compare(Goods first, Goods second)
{
    return first.m_time < second.m_time;
}
bool profit_compare(Goods first, Goods second)
{
    return first.m_profit > second.m_profit;
}
void Goods::G_Change()
{
    string Class, name, brand;
    long long time, n, num;
    G_Statistics();
    cout << "������Ҫ���ĵ���Ʒ���:";
    cin >> Class;
    cout << "������Ҫ������Ʒ������:";
    cin >> name;
    cout << "������Ҫ���ĵ���Ʒ��Ʒ��:";
    cin >> brand;
    cout << "������Ҫ���ĵ���Ʒ�Ľ�������:";
    cin >> time;
    bool exist = 0;
    Goods *g = G_Readd(&n);
    bool *sign = new bool[n]{0};
    int deletenum = 0;
    for (int i = 0; i < n; i++)
    {
        if (g[i].m_class == Class && g[i].m_names == name && g[i].m_brand == brand && g[i].m_time == time)
        {
            cout << "�Ѿ���ѯ�������Ʒ:\n";
            cout << g[i].m_class << ' ' << g[i].m_names << ' ' << g[i].m_brand << ' ' << g[i].m_prize << ' ' << g[i].m_num << ' ' << g[i].m_time << ' ' << g[i].m_cost << endl;
            exist = 1;
            cout << "��������ݣ���� ���� Ʒ�� �۸� ���� ����ʱ�� �ɱ�\n";
            cin >> g[i].m_class >> g[i].m_names >> g[i].m_brand >> g[i].m_prize >> g[i].m_num >> g[i].m_time >> g[i].m_cost;
            cout << "���³ɹ�\n";
            if (g[i].m_num <= 0)
            {
                sign[i] = 1;
                deletenum++;
            }
        }
    }
    if (exist == 0)
    {
        cout << "δ��ѯ�������Ϣ" << endl;
    }
    else
    {
        fstream newdata("data", ios::in | ios::out | ios::trunc);
        streambuf *oldout = cout.rdbuf(newdata.rdbuf());
        newdata.seekg(0, ios::beg);
        cout << n - deletenum << endl;
        for (int i = 0; i < n; i++)
        {
            if (sign[i] == 0)
            {
                cout << g[i].m_class << ' ' << g[i].m_names << ' ' << g[i].m_brand << ' ' << fixed << setprecision(0) << g[i].m_prize << ' ' << g[i].m_num << ' ' << g[i].m_time << ' ' << g[i].m_cost << endl;
            }
        }
        cout.rdbuf(oldout);
        cout << "������Ϣ�޸����\n";
    }

    system("pause");
    system("cls");
    delete[] sign;
    delete[] g;
}