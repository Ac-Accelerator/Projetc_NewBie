#include <iomanip>
#include <iostream>
using namespace std;
long double factor_value();
long double term_value();
long double expression_value();
long double factorial(long double);
main()
{
    cout << "-----------------------------" << endl;
    cout << "|  欢迎使用高级计算器(精度8) |" << endl;
    cout << "|      请输入数学表达式      |" << endl;
    cout << "|  样例输入:((2!+1)!+1)^2+3  |" << endl;
    cout << "----------------------------" << endl;
    while (true)
    {
        cout << fixed << expression_value() << endl
             << "您可以继续输入计算" << endl;
        fflush(stdin);
    }
}
long double expression_value() //算表达式
{
    long double result = term_value();
    while (true)
    {
        char op = cin.peek();
        if (op == '+' || op == '-')
        {
            cin.get();
            long double value = term_value();
            if (op == '+')
                result += value;

            else
                result -= value;
        }
        else
            break;
    }
    return result;
}
long double term_value() //算项
{
    long double result = factor_value();
    while (true)
    {
        char op = cin.peek();
        if (op == '!')
        {
            cin.get();
            result = factorial(result);
            continue;
        }
        if (cin.peek() == '^')
        {
            cin.get();
            long double cache_f = factor_value();
            long double cache = result;
            for (int i = 0; i < cache_f - 1; i++)
            {
                result = result * cache;
            }
            continue;
        }
        if (op == '*' || op == '/')
        {
            cin.get();
            long double value = factor_value();
            if (op == '*')
            {
                result *= value;
            }
            else if (op == '/')
                result /= value;
        }
        else
            break;
    }
    return result;
}
long double factor_value() //算因子
{
    long double result = 0;
    char c = cin.peek();
    if (c == '(')
    {
        cin.get();
        result = expression_value();
        cin.get();
    }
    else
    {
        while (isdigit(c))
        {
            result = 10 * result + c - 48;
            cin.get();
            c = cin.peek();
        }
    }

    return result;
}
long double factorial(long double n)
{
    string ans = "1";
    long double result = 0;
    for (int i = 1; i <= n; i++)
    {

        int jw = 0;
        for (int j = ans.size() - 1; j >= 0; j--)
        {
            int n = (ans[j] - 48) * i + jw;
            jw = n / 10;
            n = n % 10;
            ans[j] = n + 48;
        }
        while (jw)
        {
            ans = char(jw % 10 + 48) + ans;
            jw /= 10;
        }
    }
    int q = ans.length();
    for (int i = 0; i < q; i++)
    {
        result = result * 10 + ans[i] - 48;
    }
    if (n > 25)
    {
        cout << "-------------------阶乘过大产生错误，下面显示正确阶乘结果---------------------" << endl
             << setprecision(0) << n << "!= " << ans << endl
             << "---------------------------最终计算结果已经失效----------------------------" << endl;
    }
    return result;
}