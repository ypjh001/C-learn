#include<iostream>
using namespace std;
//������⣺
//������ԣ�����Ȩ��ȥʹ������ĲƲ�����Ա����
class Base
{
public:
	virtual void func() = 0;//�麯�����黯��

};

class Son1 :public Base
{

	void func()
	{
		cout << "������ø���Ĵ��麯������" << endl;
	}
};

void test_chun_vir()
{
	Base* S1 = new Son1;
	S1->func();

}