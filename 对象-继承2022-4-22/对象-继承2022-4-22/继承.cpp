//对象继承
#include<iostream>
using namespace std;

//父类I
class Base1
{
	friend void test1();
public:
	Base1();
	~Base1();
	int A=0;
	void func_test()
	{
		cout << "Base1的函数调用" << endl;
	}
	void func_test(int a)
	{
		cout << "Base1的函数重载调用" << endl;
	}
protected:
	int B=0;
private:
	int C=0;

};

Base1::Base1()
{
}

Base1::~Base1()
{
}

//子类I继承父类I,public继承时，除了父类的私有成员不能继承之外，其他的都是public类型的成员
class Son1 :public  Base1
{
public:
	friend void test1();
	Son1();
	~Son1();
	void fangwen();
	int A = 100;
	void func_test()
	{
		cout << "Son1的函数调用" << endl;
	}
private:

};

Son1::Son1()
{

}

Son1::~Son1()
{
}

void Son1::fangwen()
{
	Son1 S1;
	S1.A = 10;		//公共	父类在子类继承时也属于	公共权限，类外		可以 访问
	S1.B = 20;		//保护	父类在子类继承时也属于	保护权限，类外函数	不能 访问，但可以通过友元访问。
	//S1.C = 30;	//erro,C是父类的私有成员，具有私有属性，子类不能继承，但会在子类中生成成员C，但不能调用和显示（被系统隐藏）,同样的友元可以访问父类的私有成员
	cout << "fangwen";
	
}
void test1()
{
	Son1 S1;
	S1.A = 10;
	S1.B = 20;
	S1.C = 30;
	cout <<"Son1：" << S1.A << endl;
	cout << "Son1：" << S1.B << endl;
	cout << "Son1：" << S1.C << endl;
	S1.fangwen();
}

void tongchengyuan_test4()
{
	//当有父类的成员与子类的成员名字相同时，直接放问只能访问子类的成员。
	//如果要访问父类的成员时，要加作用域	Base1::
	Son1 S4;
	cout <<"Sone1:" << S4.A << endl;
	cout << "Base1:" << S4.Base1::A << endl;
}

void tonghanshu_test5()
{
	//当子类函数与父类函数同名是，直接调用优先调用子类函数（子类函数隐藏父类所有与子类同名的函数）(包括函数重载）
	//要访问父类与子类的同名函数，需要用作用域 Base::
	//
	Son1 S5;
	//S5.func_test(5);//erro,如果直接怎么调用void func_test(int a),当子类没有该函数的重载时，不报错，否则报错。那么要访问父类与子类同名的重载函数，需要加作用域 Base::
	S5.func_test();
	S5.Base1::func_test();
	S5.Base1::func_test(5);
}

//---------------------------------------------------
//父类II
class Base2
{
	friend void test2();//友元void test2（）
public:
	Base2();
	~Base2();
	int A=0;
protected:
	int B=0;
private:
	int C=0;
};

Base2::Base2()
{
}

Base2::~Base2()
{
}
//子类II继承父类II
class Son2:protected Base2
{
	friend void test2();//友元void test2（）
public:
	Son2();
	~Son2();
private:

};

Son2::Son2()
{
}

Son2::~Son2()
{
}

void test2()
{
	Son2 S2;
	S2.A = 10;//保护继承----父类为公共	子类继承时是	保护属性	但友元可以访问
	S2.B = 20;//保护继承----父类为保护	子类继承时是	保护属性	但友元可以访问
	S2.C = 30;//保护继承----父类为私人	子类继承时是	私人属性	但友元可以访问
	cout << "Son2：" << S2.A << endl;
	cout << "Son2：" << S2.B << endl;
	cout << "Son2：" << S2.C << endl;
}

//-------------------------------------------
//父类III
class Base3
{
	friend void test3();//友元void test3（）
public:
	Base3();
	~Base3();
	int A=0;
protected:
	int B=0;
private:
	int C=0;
};

Base3::Base3()
{
	cout << "Base3的构造函数调用" << endl;
}

Base3::~Base3()
{
	cout << "Base3的析构函数调用" << endl;
}

//子类3继承父类3
class Son3:private Base3
{
	friend void test3();//友元void test3（）
public:
	Son3();
	~Son3();

private:

};

Son3::Son3()
{
	cout << "Son3的构造函数调用" << endl;
}

Son3::~Son3()
{
	cout << "Son3的析构函数调用" << endl;
}

void test3()
{
	/*
		子类创造对象时，先调用父类的构造函数，在调用子类本身的构造函数；
		子类销毁对象时，先调用子类的析构函数，在调用父类的析构函数；
	*/
	Son3 S3;
	S3.A = 10;//私人继承---父类为公共	子类继承时是	私人属性	但友元可以访问
	S3.B = 20;//私人继承---父类为保护	子类继承时是	私人属性	但友元可以访问
	S3.C = 30;//私人继承---父类为私人	子类继承时是	私人属性	但友元可以访问
	cout << "Son3：" << S3.A << endl;
	cout << "Son3：" << S3.B << endl;
	cout << "Son3：" << S3.C << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	//tongchengyuan_test4();
	tonghanshu_test5();
	return 0;
}