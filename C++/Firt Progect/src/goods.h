#pragma once
#include <string>
class Goods
{
public:
    std::string m_class;
    std::string m_names;
    std::string m_brand;
    double m_prize;
    double m_num = 0;
    double m_time;
    double m_cost;
    double m_profit=0;

    Goods(/* args */);
    Goods(std::string, std::string, std::string, double, double);
    void G_Add();
    void G_Out();
    void G_Statistics();
    void G_Delete();
    void G_Search();
    Goods *G_Readd(long long *);
    Goods *G_Reads(long long *);
    Goods *G_Readl(long long *);
    void G_Change();
    void G_Profit();
};
struct datas
{
    std::string Class;
    std::string name;
    std::string brand;
    long long numb = 0;
};
bool time_compare(Goods first,Goods second);
bool profit_compare(Goods first,Goods second);