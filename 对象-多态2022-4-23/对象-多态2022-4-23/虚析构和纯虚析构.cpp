#include<iostream>
#include<string>
using namespace std;

/*
	注意：
		使用多态时，子类中有开辟新的空间，父类指针释放时无法调用到子类的析构代码
	解决方法：
		将父类的析构函数改为虚析构或者纯虚析构

	虚析构和纯虚析构的 共同点：
		1.可以解决父类指针释放子类对象
		2.都需要具体的函数实现
	虚析构和纯虚析构的 不共同点：
		如果是纯虚析构，该类属于抽象类，无法实例化对象。

*/

class Animal1
{
public:
	Animal1();
	//virtual ~Animal1();//虚化父类析构函数，可以对象销毁时，可以调用 子类 的析构函数。
	virtual ~Animal1() = 0;//纯虚析构，要有声明还要有定义
	//有纯虚析构之后就是抽象类，无法实例化对象。
	
	virtual void speak() = 0;
};
Animal1::~Animal1()
{
	cout << "Animal1的纯析构函数" << endl;
}
Animal1::Animal1()
{
	cout << "Animal1的构造函数" << endl;
}

//Animal1::~Animal1()
//{
//	cout << "Animal1的析构函数" << endl;
//
//}
class Cat1 :public Animal1
{
public:

	~Cat1();
	string* cat_name;
	Cat1 (string c_name)
	{
		cout << "Cat1的构造函数" << endl;
		cat_name = new string(c_name);
	}
	virtual void speak()
	{
		cout <<*cat_name<< "小猫说话" << endl;
	}
	
};


void DoSpeak(Animal1 * speak)
{
	speak->speak();

}

Cat1::~Cat1()
{
	cout << "Cat1的析构函数" << endl;
	//判断子类中开辟的cat_name堆空间，然后释放cat_name的空间。
	if (cat_name!=NULL)
	{
		delete cat_name;
		cat_name = NULL;
	}
}
void test_speak()
{
	Animal1* animal = new Cat1("tony");//在这里是创建的父类指针，不是子类
	//父类指针在析构时候 不会调用子类析构函数，导致子类如果有堆区属性，不能释放，出现内存泄露.
	//解决办法：把父类的析构函数虚化，变成虚析构。
	animal->speak();
	//Animal1* C1 = new Cat1("hey");
	//C1->speak();
	delete animal; 
}


