#include <iostream>
using namespace std;
class Test
{
public:
	Test() { cout << "构造函数" << endl; }
	~Test() { cout << "析构函数" << endl; }
};
void myfunc()
{
	Test obj;
}
int main()
{
	cout << "main开始" << endl;
	myfunc();
	cout << "main结束" << endl;
	return 0;
}