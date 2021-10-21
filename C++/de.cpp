#include<iostream>
#include<cstring>
using namespace std;
int n,a[101],b[101],ans,i;
void init(int a[])                                  //将数串s转化为整数数组a
{ 
	string s; 
  	cin>>n>>s;                                   //读入字符串s 
  	memset(a,0,sizeof(a));                 //数组a清0 
  	a[0]=s.length();                             //用a[0]计算字符串s的位数 
  	for(i=1;i<=a[0];i++)
    		if(s[a[0]-i]>='0'&&s[a[0]-i]<='9')     a[i]=s[a[0]-i]-'0';
      	else a[i]=s[a[0]-i]-'A'+10;
}
bool check(int a[])                           //判别整数数组a是否为回文数
{ 
	for(i=1;i<=a[0];i++)
    		if(a[i]!=a[a[0]-i+1])return false;
  	return true;
}
void  jia(int a[])                    //整数数组a与其反序数b进行n进制加法运算
{
	for(int i=1;i<=a[0];i++)b[i]=a[a[0]-i+1];      //反序数b
	for(int i=1;i<=a[0];i++) a[i]+=b[i];              //逐位相加
	for(int i=1;i<=a[0];i++)                             //处理进位
	{a[i+1]+=a[i]/n;
		a[i]%=n;
	} 
	if(a[a[0]+1]>0) a[0]++;    //修正新的a的位数（a+b最多只能的一个进位） 
}
int main()
{	init(a);
	if(check(a)){cout<<0<<endl;return 0;}
	ans=0;                                               //步数初始化为0
	while(ans++<=8)
	{       jia(a);
		if(check(a)){cout<<ans<<endl;return 0;}
	}
	cout<<"0";                           //输出无解信息
	return 0;
}