#include <iostream>
using namespace std;//////
int main()
{
    int n;      
    int grade;  
    int total=0;
    double avg; 
    int cnt=0;    

    cout<<"请输入学生数量:";
    cin>>n;

    int i;
    for (i = 1; i<=n; i++)
    {
        cout<<"请输入第"<<i<<"个学生的成绩:";
        cin>>grade;

        total = total + grade;

        if(grade < 60)
        {
            cnt++;
        }

    }

    avg = 1.0 * total / n;

    cout<<"该班共"<<n<<"名同学，平均分为:"<<avg<<endl;
    cout<<"不及格人数为:"<<cnt<<endl;
    return 0;
}
