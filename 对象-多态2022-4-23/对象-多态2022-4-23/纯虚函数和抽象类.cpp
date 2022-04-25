#include<iostream>
using namespace std;
//个人理解：
//父类可以，且有权力去使用子类的财产（成员），
class Base
{
public:
	virtual void func() = 0;//虚函数纯虚化。

};

class Son1 :public Base
{

	void func()
	{
		cout << "子类调用父类的纯虚函数功能" << endl;
	}
};

void test_chun_vir()
{
	Base* S1 = new Son1;
	S1->func();

}