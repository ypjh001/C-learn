#include"stack栈.h"

void test_stack()
{
	//创建一个栈s1
	stack<int>s1;

	//数据入栈push
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);

	
	cout << s1.size()<<endl;

	//访问数据--弹出数据--出栈--pop
	while (!s1.empty() )
	{
		//输出栈顶数据
		cout << s1.top()<<"  ";
		//栈顶弹出数据
		s1.pop();
	}
	cout << endl;
	cout << s1.size()<<endl;
}
