#include "goods.h"
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;
Goods::Goods(string G_class, string G_names, string G_brand, double G_prize, double G_num = 0)
{
    m_class = G_class, m_names = G_names, m_prize = G_prize, m_num = G_num, m_brand = G_brand;
}
Goods::Goods() {}
Goods *Goods::G_Readd(long long *n) //载入数据done
{
    string Class, name, brand;
    long long num, time;
    double prize, cost;
    fstream data("data", ios::in);
    streambuf *oldin = cin.rdbuf(data.rdbuf());
    cin >> *n; //读取数据大小
    Goods *g = new Goods[*n];
    for (int i = 0; i < *n; i++) //载入数据
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
    cin.rdbuf(oldin); //将输入指针返回给键盘
    data.close();
    return g;
}
Goods *Goods::G_Reads(long long *n) //读取统计done
{
    string Class, name, brand;
    long long num;
    fstream data("statistic", ios::in);
    streambuf *oldin = cin.rdbuf(data.rdbuf());
    cin >> *n; //读取数据大小
    Goods *g = new Goods[*n];
    for (int i = 0; i < *n; i++) //载入数据
    {
        cin >> Class >> name >> brand >> num;
        g[i].m_class = Class;
        g[i].m_names = name;
        g[i].m_brand = brand;
        g[i].m_num = num;
    }
    cin.rdbuf(oldin); //将输入指针返回给键盘
    data.close();
    return g;
}
Goods *Goods::G_Readl(long long *n)
{
    long long time, profit, num;
    string Class, name;
    fstream log("log", ios::in);
    streambuf *oldin = cin.rdbuf(log.rdbuf());
    cin >> *n; //读取数据大小
    Goods *g = new Goods[*n];
    for (int i = 0; i < *n; i++) //载入数据
    {
        cin >> time >> Class >> name >> profit >> num;
        g[i].m_class = Class;
        g[i].m_names = name;
        g[i].m_time = time;
        g[i].m_profit = profit;
        g[i].m_num = num;
    }
    sort(g, g + *n, time_compare); //按时间排序
    cin.rdbuf(oldin);              //将输入指针返回给键盘
    log.close();
    return g;
}
void Goods::G_Add() //添加，进货功能done
{
    string Class, name, brand;
    long long num, time;
    double prize, cost;
    fstream data("data", ios::out | ios::in); //打开存放数据的文件
    int n;
    streambuf *oldin = cin.rdbuf(data.rdbuf());
    data.seekg(0, ios::beg);
    cin >> n;
    cin.rdbuf(oldin);
    data.seekg(0, ios::end);
    cout << "请依次输入：类别 名称 品牌 价格 数量 进货时间 成本。（数据间以空格隔开，#停止）" << endl;
    while (1)
    {
        cin >> Class;
        if (Class == "#")
        {
            break;
        }
        cin >> name >> brand >> prize >> num >> time >> cost;
        streambuf *oldout = cout.rdbuf(data.rdbuf()); //将指针指向新的缓冲区，并且返回旧的缓冲区指针
        cout << Class << ' ' << name << ' ' << brand << fixed << setprecision(0) << ' ' << prize << ' ' << num << ' ' << time << ' ' << cost << endl;
        n++;
        data.seekg(0, ios::beg);
        data.flush();
        cout << n;
        data.seekg(0, ios::end);
        cout.rdbuf(oldout); //还原屏幕输出
        cout << "成功添加商品信息!" << endl;
    }
    data.close();
}
void Goods::G_Statistics() //刷新统计文件done
{
    map<string, long long> listcache;
    int point = 0;
    long long n;
    Goods *g = G_Readd(&n);
    string *newcache = new string[n];
    for (int i = 0; i < n; i++) //数据横向压缩
    {
        newcache[i] += g[i].m_class;
        newcache[i] += g[i].m_names;
        newcache[i] += g[i].m_brand;
    }
    datas *lastcache = new datas[n];
    for (int i = 0; i < n; i++) //纵向压缩
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
    fstream eco("statistic", ios::in | ios::out | ios::trunc); //打开统计文件
    streambuf *oldout = cout.rdbuf(eco.rdbuf());
    cout << point << endl;
    for (int i = 0; i < point; i++)
    {
        cout << lastcache[i].Class << ' ' << lastcache[i].name << ' ' << lastcache[i].brand << ' ' << fixed << setprecision(0) << lastcache[i].numb << endl;
    }
    cout.rdbuf(oldout);
    eco.close();
    cout << "数据库已更新" << endl;
    cout << setw(15) << left << "类别" << setw(15) << left << "名称" << setw(15) << left << "品牌" << setw(15) << left << "数量" << endl;
    for (int i = 0; i < point; i++)
    {
        cout << setw(15) << left << lastcache[i].Class << setw(15) << left << lastcache[i].name << setw(15) << left << lastcache[i].brand << setw(15) << left << lastcache[i].numb << endl;
    }
    delete[] g;
    delete[] lastcache;
    delete[] newcache;
}
void Goods::G_Out() //出货功能done
{
    G_Statistics();
    string Class, name;
    cout << "请输入要出货的商品类别:";
    cin >> Class;
    cout << "请输入要出货商品类别的名字:";
    cin >> name;
    long long n, num = 0;
    Goods *t = G_Reads(&n);
    for (int i = 0; i < n; i++)
    {
        if (t[i].m_class == Class && t[i].m_names == name)
        {
            num += t[i].m_num;
        }
    }
    if (num != 0)
    {
        int outnums;
        long long time;
        cout << "还剩余" << num << "个，请输入出货的数量:";
        while (1)
        {
            cin >> outnums;
            if (num < outnums)
            {
                cout << "超出！请重新输入:";
            }
            else
            {
                cout << "请输入出货日期:";
                cin >> time;
                Goods *g = G_Readd(&n);
                bool *sign = new bool[n]{0}; //用作标记数组，数值为0保持不变，数值为1删
                long long deletenum = 0;
                double money = 0;
                for (int i = 0; i < n; i++)
                {
                    if (g[i].m_class == Class && g[i].m_names == name)
                    {
                        if (g[i].m_num <= outnums)
                        {
                            sign[i] = 1;
                            money += (g[i].m_prize - g[i].m_cost) * m_num;
                            deletenum++;
                            outnums -= g[i].m_num;
                        }
                        else
                        {
                            money += (g[i].m_prize - g[i].m_cost) * outnums;
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
        cout << "没有该商品" << endl;
    cout << endl;
    system("pause");
    delete[] t;
}
void Goods::G_Delete() //删除功能
{
    string Class, name;
    cout << "请输入要删除的商品类别:";
    cin >> Class;
    cout << "请输入要删除商品类别的名字:";
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
        cout << "商品不存在" << endl;
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
    cout.rdbuf(oldout); //输出指针返回屏幕
    newdata.close();
    cout << "删除成功" << endl;
    system("pause");
    system("cls");
    delete[] g;
}
void Goods::G_Search() //查找功能done
{
    string Class, name, brand;
    long long n;
    Goods *g = G_Readd(&n);
    Goods *cache = new Goods[n];
    int choice;
    while (1)
    {
        system("cls");
        cout << "请选择查找的方式" << endl
             << "1.商品类别" << endl
             << "2.商品名称" << endl
             << "3.品牌" << endl
             << "4.进货日期" << endl
             << "5.返回" << endl;
        cin >> choice; //输入选择
        if (choice == 5)
        {
            system("cls");
            break;
        }
        else if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
        {
            system("cls");
            cout << "请输入要查找的信息：";
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
                    cout << "找不到相关信息" << endl;
                }
                else
                {
                    cout << "查询到" << num << "条信息,如下" << endl;
                    cout << setw(15) << left << "类型" << setw(15) << left << "名称" << setw(15) << left << "品牌" << setw(15) << left << "价格" << setw(15) << left << "库存" << setw(15) << left << "进货日期" << setw(15) << left << "成本" << endl;
                    for (int i = 0; i < point; i++)
                    {
                        cout << setw(15) << left << cache[i].m_class << setw(15) << left << cache[i].m_names << setw(15) << left << cache[i].m_brand << setw(15) << left << cache[i].m_prize << setw(15) << left << cache[i].m_num << setw(15) << left << cache[i].m_time << setw(15) << left << cache[i].m_cost << endl;
                    }
                }
                cout << "信息显示完毕（您可以继续输入内容来检索，或输入#返回菜单）" << endl;
                cin >> target;
                system("cls");
            }
        }
        else
        {
            cout << "错误的菜单选项,请重新输入" << endl;
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
    Goods *newlist = new Goods[n]; //保存最终数据的数组
    if (n == 0)
    {
        cout << "无记录" << endl;
    }
    else
    {
        cout << "请输入你要统计的时间范围\n已经记载的时间范围是" << fixed << setprecision(0) << l[0].m_time << '-' << l[n - 1].m_time << endl;
        cout << "请输入时间下限:";
        cin >> time1;
        cout << "请输入时间上限:";
        cin >> time2;
        if (time1 > time2)
        {
            cout << "错误";
        }
        for (int i = 0; i < n; i++)
        {
            if (time1 > time2)
            {
                cout << "错误" << endl;
                system("pause");
                break;
            }
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
            }
        }
        sort(newlist, newlist + point, profit_compare);
        cout << "查询到以下" << point << "个信息" << endl;
        cout << setw(15) << left << "类型" << setw(15) << left << "名称" << setw(15) << left << "销量" << setw(15) << left << "利润" << endl;
        for (int i = 0; i < point; i++)
        {
            cout << setw(15) << left << newlist[i].m_class << setw(15) << left << newlist[i].m_names << setw(15) << left << newlist[i].m_num << setw(15) << left << newlist[i].m_profit << endl;
        }
        cout << "信息显示结束" << endl;
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
    cout << "请输入要更改的商品类别:";
    cin >> Class;
    cout << "请输入要更改商品的名字:";
    cin >> name;
    cout << "请输入要更改的商品的品牌:";
    cin >> brand;
    cout << "请输入要更改的商品的进货日期:";
    cin >> time;
    bool exist = 0;
    Goods *g = G_Readd(&n);
    bool *sign = new bool[n]{0};
    int deletenum = 0;
    for (int i = 0; i < n; i++)
    {
        if (g[i].m_class == Class && g[i].m_names == name && g[i].m_brand == brand && g[i].m_time == time)
        {
            cout << "已经查询到相关商品:\n";
            cout << setw(15) << left << g[i].m_class << setw(15) << left << g[i].m_names << setw(15) << left << g[i].m_brand << setw(15) << left << g[i].m_prize << setw(15) << left << g[i].m_num << setw(15) << left << g[i].m_time << setw(15) << left << g[i].m_cost << endl;
            exist = 1;
            cout << "请更新数据：类别 名称 品牌 价格 数量 进货时间 成本\n";
            cin >> g[i].m_class >> g[i].m_names >> g[i].m_brand >> g[i].m_prize >> g[i].m_num >> g[i].m_time >> g[i].m_cost;
            cout << "更新成功\n";
            if (g[i].m_num <= 0)
            {
                sign[i] = 1;
                deletenum++;
            }
        }
    }
    if (exist == 0)
    {
        cout << "未查询到相关信息" << endl;
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
        cout << "所有信息修改完毕\n";
    }
    system("pause");
    system("cls");
    delete[] sign;
    delete[] g;
}