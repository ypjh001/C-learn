#include"stackջ.h"

void test_stack()
{
	//����һ��ջs1
	stack<int>s1;

	//������ջpush
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);

	
	cout << s1.size()<<endl;

	//��������--��������--��ջ--pop
	while (!s1.empty() )
	{
		//���ջ������
		cout << s1.top()<<"  ";
		//ջ����������
		s1.pop();
	}
	cout << endl;
	cout << s1.size()<<endl;
}
