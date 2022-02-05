#include "Base.h"
#include "Matix.h"
#include "Fraction.h"
#include "Determinant.h"
#include "Calculate.h"
#include <fstream>
void De();
void Mat();
void cal();
void look(string);
void man();
main()
{

    int a;
    system("chcp 936");
    while (true)
    {
        system("cls");
        cout << "欢迎来到线性代数计算器\n提示：此计算器有变量储存功能，输入过的变量都储存在缓存区，程序退出时自动清空\n";
        cout << "功能:\n1.行列式相关功能\n2.矩阵相关功能\n3.表达式计算(暂有缺点)\n4.变量查看（管理）\n5.退出\n请输入序号进入对应功能:";
        cin >> a;
        if (a == 1)
        {
            De();
        }
        else if (a == 2)
        {
            Mat();
        }
        else if (a == 3)
        {
            cal();
        }
        else if (a == 4)
        {
            look("");
            cout << "是否进入管理功能[Y]";
            string cho;
            cin >> cho;
            if (cho == "y" || cho == "Y")
            {
                man();
            }
        }
        else if (a == 5)
        {
            return 0;
        }
        else
        {
            cout << "错误，请重新输入:";
        }
    }
}
void De()
{
    int n;
    while (true)
    {
        system("cls");
        cout << "行列式\n";
        cout << "1.输入行列式\n2.查看储存的行列式\n3.转置\n4.求值\n5.求余子式\n6.退出\n请输入:";
        cin >> n;
        if (n == 1)
        {
            system("cls");
            cout << "单独输入#退出\n";
            string na;
            int n;
            cout << "请输入行列式名字:";
            cin >> na;
            while (cache.count(na) && na != "#")
            {
                cout << "已存在使用此名字的变量，请重新输入:";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            cout << "请输入阶数:";
            cin >> n;
            Fraction list[n * n];
            cout << "请输入行列式内容:\n";
            string t;
            for (int i = 0; i < n * n; i++)
            {
                cin >> t;
                if (t == "#")
                {
                    cout << "添加终止\n";
                    system("pause");
                    return;
                }
                list[i] = Fraction(t);
            }
            cache[na] = pair<string, int>("Determinant", PD);
            LD[PD++] = Determinant(na, n, list);
            cout << "添加成功\n";
            LD[PD - 1].display();
            system("pause");
        }
        else if (n == 2)
        {
            look("Determinant");
            system("pause");
        }
        else if (n == 3)
        {
            system("cls");
            cout << "单独输入#退出\n";
            cout << "请输入要进行转置的行列式的名称:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "未找到使用此名字的变量，请重新输入:";
                cin >> na;
            }
            while (cache[na].first != "Determinant" && na != "#")
            {
                cout << "使用该名称的变量不属于行列式,请重新输入\n";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            LD[cache[na].second].transpose();
            cout << "操作成功\n";
            LD[cache[na].second].display();
            system("pause");
        }
        else if (n == 4)
        {
            system("cls");
            cout << "单独输入#退出\n";
            cout << "请输入要进行求值的行列式的名称:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "未找到使用此名字的变量，请重新输入:";
                cin >> na;
            }
            while (cache[na].first != "Determinant" && na != "#")
            {
                cout << "使用该名称的变量不属于行列式,请重新输入\n";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            cout << "计算结果:" << LD[cache[na].second].calculate().display() << endl;
            system("pause");
        }
        else if (n == 5)
        {
            system("cls");
            cout << "单独输入#退出\n";
            cout << "请输入要进行求余子式的行列式的名称:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "未找到使用此名字的变量，请重新输入:";
                cin >> na;
            }
            while (cache[na].first != "Determinant" && na != "#")
            {
                cout << "使用该名称的变量不属于行列式,请重新输入\n";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            int m, n;
            cout << "行:";
            cin >> m;
            cout << "列:";
            cin >> n;
            LD[PD++] = LD[cache[na].second].cofactor(m, n);
            cache[LD[PD - 1].m_name] = pair<string, int>("Determinant", PD - 1);
            cout << "操作成功\n";
            LD[PD - 1].display();
            system("pause");
        }
        else if (n == 6)
        {
            break;
        }
        else
            cout << "错误，请重新输入:";
    }
}
void Mat()
{
    int n;
    while (true)
    {
        system("cls");
        cout << "矩阵\n";
        cout << "1.输入矩阵\n2.查看储存的矩阵\n3.转置\n4.计算\n5.求行列式的值\n6.求秩\n7.求逆\n8.求伴随\n9.退出\n请输入:";
        cin >> n;
        if (n == 1)
        {
            system("cls");
            cout << "单独输入#退出\n";
            string na;
            int m, n;
            cout << "请输入矩阵名字:";
            cin >> na;
            while (cache.count(na) && na != "#")
            {
                cout << "已存在使用此名字的变量，请重新输入:";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            cout << "请输入行数:";
            cin >> m;
            cout << "请输入列数:";
            cin >> n;
            Fraction list[m * n];
            cout << "请输入行列式内容:\n";
            string t;
            for (int i = 0; i < m * n; i++)
            {
                cin >> t;
                if (t == "#")
                {
                    cout << "添加终止\n";
                    system("pause");
                    return;
                }
                list[i] = Fraction(t);
            }
            cache[na] = pair<string, int>("Matix", PM);
            LM[PM++] = Matix(na, m, n, list);
            cout << "添加成功\n";
            LM[PM - 1].display();
            system("pause");
        }
        else if (n == 2)
        {
            look("Matix");
            system("pause");
        }
        else if (n == 3)
        {
            system("cls");
            cout << "单独输入#退出\n";
            cout << "请输入要进行转置的矩阵的名称:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "未找到使用此名字的变量，请重新输入:";
                cin >> na;
            }
            while (cache[na].first != "Matix" && na != "#")
            {
                cout << "使用该名称的变量不属于矩阵,请重新输入:";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            LM[cache[na].second].transpose();
            cout << "操作成功\n";
            LM[cache[na].second].display();
            system("pause");
        }
        else if (n == 4)
        {
            system("cls");
            cal();
        }
        else if (n == 5)
        {
            system("cls");
            cout << "单独输入#退出\n";
            cout << "请输入要进行计算的矩阵的名称:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "未找到使用此名字的变量，请重新输入:";
                cin >> na;
            }
            while (cache[na].first != "Matix" && na != "#")
            {
                cout << "使用该名称的变量不属于矩阵,请重新输入:";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            if (LM[cache[na].second].m_n != LM[cache[na].second].m_m)
            {
                cout << "不能转换为行列式";
                system("pause");
                continue;
            }
            cout << "行列式的值为:" << LM[cache[na].second].Det().calculate().display() << endl;
            system("pause");
        }
        else if (n == 6)
        {
            system("cls");
            cout << "单独输入#退出\n";
            cout << "请输入要进行计算的矩阵的名称:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "未找到使用此名字的变量，请重新输入:";
                cin >> na;
            }
            while (cache[na].first != "Matix" && na != "#")
            {
                cout << "使用该名称的变量不属于矩阵,请重新输入:";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            cout << "矩阵的秩为:" << LM[cache[na].second].rank() << endl;
            system("pause");
        }
        else if (n == 7)
        {
            system("cls");
            cout << "单独输入#退出\n";
            cout << "请输入要进行计算的矩阵的名称:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "未找到使用此名字的变量，请重新输入:";
                cin >> na;
            }
            while (cache[na].first != "Matix" && na != "#")
            {
                cout << "使用该名称的变量不属于矩阵,请重新输入:";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            LM[PM++] = LM[cache[na].second].inverse();
            cache[LM[PM - 1].m_name] = pair<string, int>("Matix", PM - 1);
            LM[PM - 1].display();
            system("pause");
        }
        else if (n == 8)
        {
            system("cls");
            cout << "单独输入#退出\n";
            cout << "请输入要进行计算的矩阵的名称:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "未找到使用此名字的变量，请重新输入:";
                cin >> na;
            }
            while (cache[na].first != "Matix" && na != "#")
            {
                cout << "使用该名称的变量不属于矩阵,请重新输入:";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            LM[PM++] = LM[cache[na].second].adjoint();
            cache[LM[PM - 1].m_name] = pair<string, int>("Matix", PM - 1);
            LM[PM - 1].display();
            system("pause");
        }
        else if (n == 9)
        {
            system("cls");
            break;
        }
        else
            cout << "错误，请重新输入:";
    }
}
void cal()
{
    look("Matix");
    cout << "以上是储存的变量的信息\n\n请输入想要计算的表达式(功能未完善，仅支持简单的矩阵运算)\n";
    string str;
    int p = 0;
    string t;
    cin >> t;
    getline(cin, str);
    str += t;
    cout << str;
    cout << "计算结果\n";
    expression_value(str, p).display();
    system("pause");
}
void look(string a = "")
{
    system("cls");
    cout << "储存的变量展示\n";
    if (a == "")
        for (auto it = cache.begin(); it != cache.end(); it++)
        {
            cout << "类型:" << it->second.first << endl;
            if (it->second.first == "Determinant")
            {
                LD[it->second.second].display();
            }
            if (it->second.first == "Matix")
            {
                LM[it->second.second].display();
            }
            cout << endl;
        }
    else
    {
        for (auto it = cache.begin(); it != cache.end(); it++)
        {
            if (it->second.first == a)
            {
                cout << "类型:" << it->second.first << endl;
                if (a == "Determinant")
                    LD[it->second.second].display();
                else
                    LM[it->second.second].display();
                cout << endl;
            }
        }
    }
}
void man()
{
    system("cls");
    fstream exist("data"); //
    if (!exist.good())
    {
        fstream exist("data", ios::out);
        streambuf *oldout = cout.rdbuf(exist.rdbuf());
        cout << '0' << endl;
        cout.rdbuf(oldout);
    }
    exist.close();
    int c;
    while (1)
    {
        system("cls");
        cout << "管理界面\n此功能依赖文件“data”请尽可能不要去直接修改此文件，否则可能导致文件的数据错误";
        cout << "\n如果此功能不正常，请检查并修复data文件，如果无法修复，请删除此文件。";
        cout << "文件第一行为保存变量的数量，之后每行一个变量的相关信息:类型，名字，大小，内容\n";
        cout << "1.载入内存(如果内存中有重名的将直接覆盖)\n2.备份信息(覆写data文件)\n3.退出\n请输入:";
        cin >> c;
        if (c == 1)
        {
            fstream data("data", ios::in);
            streambuf *oldin = cin.rdbuf(data.rdbuf());
            int num;
            cin >> num;
            string vcalss, na, fractions;
            int n, m;
            for (int i = 0; i < num; i++)
            {
                cin>>vcalss;
                if (vcalss == "Matix")
                {
                    cin >> na;
                    cin >> m >> n;
                    Fraction list[m * n];
                    for (int i = 0; i < n * m; i++)
                    {
                        cin >> fractions;
                        list[i] = Fraction(fractions);
                    }
                    cache[na] = pair<string, int>("Matix", PM);
                    LM[PM++] = Matix(na, m, n, list);
                    cout << "添加成功\n";
                    LM[PM - 1].display();
                }
                else if (vcalss == "Determinant")
                {
                    cin >> na;
                    cin >> n;
                    Fraction list[n * n];
                    for (int i = 0; i < n * n; i++)
                    {
                        cin >> fractions;
                        list[i] = Fraction(fractions);
                    }
                    cache[na] = pair<string, int>("Determinant", PD);
                    LD[PD++] = Determinant(na, n, list);
                    cout << "添加成功\n";
                    LD[PD - 1].display();
                }
            }
            cin.rdbuf(oldin);
            system("pause");
        }
        else if (c == 2)
        {
            fstream data("data", ios::in | ios::out | ios::trunc);
            streambuf *oldout = cout.rdbuf(data.rdbuf());
            cout << cache.size() << endl;
            int m, n;
            for (auto it = cache.begin(); it != cache.end(); it++)
            {
                cout << it->second.first << ' ' << it->first << ' ';
                if (it->second.first == "Matix")
                {
                    cout << LM[it->second.second].m_m << ' ' << LM[it->second.second].m_n << ' ';
                    m = LM[it->second.second].m_m;
                    n = LM[it->second.second].m_n;
                    for (int i = 1; i <= m; i++)
                        for (int j = 1; j <= n; j++)
                            cout << LM[it->second.second].map[i][j].display() << ' ';
                }
                else
                {
                    cout << LD[it->second.second].m_rank << ' ';
                    m = n = LD[it->second.second].m_rank;
                    for (int i = 1; i <= m; i++)
                        for (int j = 1; j <= n; j++)
                            cout << LD[it->second.second].map[i][j].display() << ' ';
                }
                cout << endl;
            }
            cout.rdbuf(oldout);
            cout << "备份完成\n";
            system("pause");
        }
        else if (c == 3)
        {
            break;
        }
        else
        {
            cout << "错误，请重新输入:";
        }
    }
}