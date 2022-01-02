#include "function.h"
#include "goods.h"
main()
{
    Goods operate;
    initial_data();
    initial_log();
    initial_statistic();
    while (1)
    {
        int func = menu_out();
        system("cls");
        if (func == 1)
        {
            operate.G_Add(); //进货
        }
        else if (func == 2)
        {
            operate.G_Out(); //出货功能
        }
        else if (func == 3)
        {
            operate.G_Profit(); //查询信息
        }
        else if (func == 4)
        {
            gover_menu_out();
        }
        else if (func == 5)
        {
            operate.G_Statistics();
            system("pause");
        }
        else
        {
            break;
        }
        system("cls");
    }
}