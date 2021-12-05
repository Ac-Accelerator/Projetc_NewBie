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
    cout << "欢迎来到库存管理系统主菜单\n1.进货\n2.出货\n3.利润\n4.管理\n5.统计\n6.退出\n请输入你想要完成的操作:";
    int n;
    while (1)
    {
        cin >> n;
        if (n != 1 && n != 2 && n != 3 && n != 4 && n != 5 && n != 6)
        {
            cout << "错误操作，请重新输入" << endl;
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
        cout << "1.添加功能\n2.查询功能\n3.删除功能\n4.修改功能\n5.退出\n请输入想要进行的操作:";
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
            cout << "未定义的操作，请重新输入" << endl;
        }
    }
}