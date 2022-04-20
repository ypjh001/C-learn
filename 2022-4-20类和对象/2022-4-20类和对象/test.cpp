#include<iostream>

using namespace std;
//创建Person的类
class Person
{
public:
	//系统默人构造函数
	Person();

	//构造函数-函数重载
	Person(int age,int height);

	//析构函数
	~Person();

	//程序员创建一个自己的深拷贝函数
	Person(const Person& p);

	//创建一个可以访问peivate内部的函数
	int P_age=0;
	//创建一个身高的地址
	int* P_height=0;
private:
	
};


//构造函数，没有返回值，可有可无参,创建对象时运行一次构造函数
Person::Person()
{
	cout << "对象建立，引用默认wu参的构造函数" << endl;
}


Person::Person( int age,int height)
{
	P_age = age;
	//在堆区中开辟一个空间，来存放P_height的地址。（堆中的空间有程序员自己开辟和释放，因为对象销毁时，自动调用一次析构函数，所以可以在析构函数里释放开辟的空间）
	P_height = new int(height);
	cout << "对象建立，且调用是带参引用自定义的you参的构造函数"<<endl;
}


//析构函数，没有返回值，没有参数,对象销毁时运行一次默认的析构函数
Person::~Person()
{
	//释放程序员自己在堆区中开辟的空间
	
	//判断P_height是否为空指针，如果不是，则给他释放；
	if (P_height!=NULL)
	{
		//释放P_height
		delete P_height;
		//并将P_height指向空指针，防止出现野指针的情况。
		P_height = NULL;
		//由于先调用、销毁P1，所以P1会先运行构造函数、再运行析构函数，此时已经把P_height给释放
		//到调用、销毁P2时，再次执行析构函数的时候会重复释放P_height的地址，造成错误。
		//这就是浅拷贝的弊端。
		//解决办法就是不用系统自带的默认拷贝函数，运用自己创造出来的拷贝函数---深拷贝
	}
	
	cout << "对象销毁引用默认的析构函数"<<endl;
}


//程序员定义的拷贝函数
Person::Person(const Person& p)
{
	cout << "拷贝构造函数的调用" << endl;
	P_age = p.P_age;
	//P_height = p.P_height;		//系统默认执行的是这个东西
	//深拷贝操作,在堆区中开批一个空间出来，给P2存放。
	//---------------------------
	//个人理解：调用P2时会再次调用析构函数，而析构函数中会被P1调用并销毁开辟出来的空间，到P2的时候没有空间给释放，所以要开辟一个新的空间给P2存放数据并释放空间。
	
	P_height = new int(*p.P_height);
}

void test()
{
	//带参默认引用带参的构造函数 Person::Person( int age)
	//创建一个对象P1
	Person P1(18,164);
	cout << "P1的数值" << P1.P_age << endl;
	//将P1复制给P2，引用系统默认的拷贝函数
	Person P2(P1);
	cout << "P2的数值" << P2.P_age << endl;
}

int main()
{
	//对象属性-深拷贝与浅拷贝
	test();
	
	
	return 0;
}