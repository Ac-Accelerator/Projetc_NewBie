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
        cout << "��ӭ�������Դ���������\n��ʾ���˼������б������湦�ܣ�������ı����������ڻ������������˳�ʱ�Զ����\n";
        cout << "����:\n1.����ʽ��ع���\n2.������ع���\n3.���ʽ����(����ȱ��)\n4.�����鿴������\n5.�˳�\n��������Ž����Ӧ����:";
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
            cout << "�Ƿ���������[Y]";
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
            cout << "��������������:";
        }
    }
}
void De()
{
    int n;
    while (true)
    {
        system("cls");
        cout << "����ʽ\n";
        cout << "1.��������ʽ\n2.�鿴���������ʽ\n3.ת��\n4.��ֵ\n5.������ʽ\n6.�˳�\n������:";
        cin >> n;
        if (n == 1)
        {
            system("cls");
            cout << "��������#�˳�\n";
            string na;
            int n;
            cout << "����������ʽ����:";
            cin >> na;
            while (cache.count(na) && na != "#")
            {
                cout << "�Ѵ���ʹ�ô����ֵı���������������:";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            cout << "���������:";
            cin >> n;
            Fraction list[n * n];
            cout << "����������ʽ����:\n";
            string t;
            for (int i = 0; i < n * n; i++)
            {
                cin >> t;
                if (t == "#")
                {
                    cout << "�����ֹ\n";
                    system("pause");
                    return;
                }
                list[i] = Fraction(t);
            }
            cache[na] = pair<string, int>("Determinant", PD);
            LD[PD++] = Determinant(na, n, list);
            cout << "��ӳɹ�\n";
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
            cout << "��������#�˳�\n";
            cout << "������Ҫ����ת�õ�����ʽ������:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "δ�ҵ�ʹ�ô����ֵı���������������:";
                cin >> na;
            }
            while (cache[na].first != "Determinant" && na != "#")
            {
                cout << "ʹ�ø����Ƶı�������������ʽ,����������\n";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            LD[cache[na].second].transpose();
            cout << "�����ɹ�\n";
            LD[cache[na].second].display();
            system("pause");
        }
        else if (n == 4)
        {
            system("cls");
            cout << "��������#�˳�\n";
            cout << "������Ҫ������ֵ������ʽ������:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "δ�ҵ�ʹ�ô����ֵı���������������:";
                cin >> na;
            }
            while (cache[na].first != "Determinant" && na != "#")
            {
                cout << "ʹ�ø����Ƶı�������������ʽ,����������\n";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            cout << "������:" << LD[cache[na].second].calculate().display() << endl;
            system("pause");
        }
        else if (n == 5)
        {
            system("cls");
            cout << "��������#�˳�\n";
            cout << "������Ҫ����������ʽ������ʽ������:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "δ�ҵ�ʹ�ô����ֵı���������������:";
                cin >> na;
            }
            while (cache[na].first != "Determinant" && na != "#")
            {
                cout << "ʹ�ø����Ƶı�������������ʽ,����������\n";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            int m, n;
            cout << "��:";
            cin >> m;
            cout << "��:";
            cin >> n;
            LD[PD++] = LD[cache[na].second].cofactor(m, n);
            cache[LD[PD - 1].m_name] = pair<string, int>("Determinant", PD - 1);
            cout << "�����ɹ�\n";
            LD[PD - 1].display();
            system("pause");
        }
        else if (n == 6)
        {
            break;
        }
        else
            cout << "��������������:";
    }
}
void Mat()
{
    int n;
    while (true)
    {
        system("cls");
        cout << "����\n";
        cout << "1.�������\n2.�鿴����ľ���\n3.ת��\n4.����\n5.������ʽ��ֵ\n6.����\n7.����\n8.�����\n9.�˳�\n������:";
        cin >> n;
        if (n == 1)
        {
            system("cls");
            cout << "��������#�˳�\n";
            string na;
            int m, n;
            cout << "�������������:";
            cin >> na;
            while (cache.count(na) && na != "#")
            {
                cout << "�Ѵ���ʹ�ô����ֵı���������������:";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            cout << "����������:";
            cin >> m;
            cout << "����������:";
            cin >> n;
            Fraction list[m * n];
            cout << "����������ʽ����:\n";
            string t;
            for (int i = 0; i < m * n; i++)
            {
                cin >> t;
                if (t == "#")
                {
                    cout << "�����ֹ\n";
                    system("pause");
                    return;
                }
                list[i] = Fraction(t);
            }
            cache[na] = pair<string, int>("Matix", PM);
            LM[PM++] = Matix(na, m, n, list);
            cout << "��ӳɹ�\n";
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
            cout << "��������#�˳�\n";
            cout << "������Ҫ����ת�õľ��������:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "δ�ҵ�ʹ�ô����ֵı���������������:";
                cin >> na;
            }
            while (cache[na].first != "Matix" && na != "#")
            {
                cout << "ʹ�ø����Ƶı��������ھ���,����������:";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            LM[cache[na].second].transpose();
            cout << "�����ɹ�\n";
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
            cout << "��������#�˳�\n";
            cout << "������Ҫ���м���ľ��������:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "δ�ҵ�ʹ�ô����ֵı���������������:";
                cin >> na;
            }
            while (cache[na].first != "Matix" && na != "#")
            {
                cout << "ʹ�ø����Ƶı��������ھ���,����������:";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            if (LM[cache[na].second].m_n != LM[cache[na].second].m_m)
            {
                cout << "����ת��Ϊ����ʽ";
                system("pause");
                continue;
            }
            cout << "����ʽ��ֵΪ:" << LM[cache[na].second].Det().calculate().display() << endl;
            system("pause");
        }
        else if (n == 6)
        {
            system("cls");
            cout << "��������#�˳�\n";
            cout << "������Ҫ���м���ľ��������:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "δ�ҵ�ʹ�ô����ֵı���������������:";
                cin >> na;
            }
            while (cache[na].first != "Matix" && na != "#")
            {
                cout << "ʹ�ø����Ƶı��������ھ���,����������:";
                cin >> na;
            }
            if (na == "#")
            {
                continue;
            }
            cout << "�������Ϊ:" << LM[cache[na].second].rank() << endl;
            system("pause");
        }
        else if (n == 7)
        {
            system("cls");
            cout << "��������#�˳�\n";
            cout << "������Ҫ���м���ľ��������:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "δ�ҵ�ʹ�ô����ֵı���������������:";
                cin >> na;
            }
            while (cache[na].first != "Matix" && na != "#")
            {
                cout << "ʹ�ø����Ƶı��������ھ���,����������:";
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
            cout << "��������#�˳�\n";
            cout << "������Ҫ���м���ľ��������:";
            string na;
            cin >> na;
            while (!cache.count(na) && na != "#")
            {
                cout << "δ�ҵ�ʹ�ô����ֵı���������������:";
                cin >> na;
            }
            while (cache[na].first != "Matix" && na != "#")
            {
                cout << "ʹ�ø����Ƶı��������ھ���,����������:";
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
            cout << "��������������:";
    }
}
void cal()
{
    look("Matix");
    cout << "�����Ǵ���ı�������Ϣ\n\n��������Ҫ����ı��ʽ(����δ���ƣ���֧�ּ򵥵ľ�������)\n";
    string str;
    int p = 0;
    string t;
    cin >> t;
    getline(cin, str);
    str += t;
    cout << str;
    cout << "������\n";
    expression_value(str, p).display();
    system("pause");
}
void look(string a = "")
{
    system("cls");
    cout << "����ı���չʾ\n";
    if (a == "")
        for (auto it = cache.begin(); it != cache.end(); it++)
        {
            cout << "����:" << it->second.first << endl;
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
                cout << "����:" << it->second.first << endl;
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
        cout << "�������\n�˹��������ļ���data���뾡���ܲ�Ҫȥֱ���޸Ĵ��ļ���������ܵ����ļ������ݴ���";
        cout << "\n����˹��ܲ����������鲢�޸�data�ļ�������޷��޸�����ɾ�����ļ���";
        cout << "�ļ���һ��Ϊ���������������֮��ÿ��һ�������������Ϣ:���ͣ����֣���С������\n";
        cout << "1.�����ڴ�(����ڴ����������Ľ�ֱ�Ӹ���)\n2.������Ϣ(��дdata�ļ�)\n3.�˳�\n������:";
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
                    cout << "��ӳɹ�\n";
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
                    cout << "��ӳɹ�\n";
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
            cout << "�������\n";
            system("pause");
        }
        else if (c == 3)
        {
            break;
        }
        else
        {
            cout << "��������������:";
        }
    }
}