#include<iostream>
#include<string>
#include "多态案例-计算机.h"
using namespace std;
//分文件
/*
	1.头文件
	2.源原件
	3.源文件中定义函数
	4.头文件中声明函数
*/

/*
	多态好处：
		1.代码组织结构清晰
		2.可读性强
		3.利于前期和后期的发展以及维护


	注意：
		后期维护尽量不要碰原码

	
*/

//--------------------------------
//int add(int a,int b)
//{
//	return a + b;
//}
//--------------------------------

//普通写法：
class Calculator_1
{
public:
	int get_Result(string oper,int num1,int num2)
	{
		
		m_Num1 = num1;
		m_Num2 = num2;
		//+
		if (oper == "+")
			return m_Num1 + m_Num2;
		//-
		if (oper == "-")
			return m_Num1 - m_Num2;
		//*
		if (oper == "*")
			return m_Num1 * m_Num2;
		//假设后期加/
		if (oper == "/")
			return m_Num1 / m_Num2;
		else - 1;
	}
	int m_Num1;
	int m_Num2;
};

void test_Calculator()
{
	Calculator_1 C1{};
	//int temp1=C1.get_Result("*",98,6);
	//cout << temp1<< endl;
	cout << "10" << "+" << "2=" << C1.get_Result("+", 10, 2) << endl;
	cout << "10" << "-" << "2=" << C1.get_Result("-", 10, 2) << endl;
	cout << "10" << "*" << "2=" << C1.get_Result("*", 10, 2) << endl;
	cout << "10" << "/" << "2=" << C1.get_Result("/", 10, 2) << endl;
}




//--------------------------------------------------
//多态抽象实现计算机：
//父类
class AbstractCalculator
{
public:
	virtual int Get_Result()
	{
		return 0;
	}
	long m_num1=0;
	long m_num2=0;

};
//子类--加法
class AddAbstract :public AbstractCalculator
{
	//重写父类虚函数
public:
	//子类要重写父类成员函数（虚函数），否则也不能实例化，或者说不能实现实例化功能.
	 int Get_Result()
	{
		return m_num1 + m_num2;
	}
	 /*int Add()
	 {
		 return m_num1 + m_num2;
	 }*/
};
//子类--减法
class SubAbstract :public AbstractCalculator
{
	//重写父类虚函数
public:
	int Get_Result()
	{
		return m_num1 - m_num2;
	}
};
//子类--乘法
class MulAbstract :public AbstractCalculator
{
	//重写父类虚函数
public:
	int Get_Result()
	{
		return m_num1 * m_num2;
	}
};
//实例化加法并调用加法
void test_Add_Abs_traCalculator()
{
	AbstractCalculator* Add = new AddAbstract;//划出一块空间存放AddAbstract

	Add->m_num1=20;
	Add->m_num2=5;
	cout << Add->m_num1 << "+" << Add->m_num2 << "=" << Add->Get_Result() << endl;
}

//减法
void test_Sub_Abs_traCalculator()
{
	AbstractCalculator* Sub = new SubAbstract;//划出一块空间存放AddAbstract

	Sub->m_num1 = 20;
	Sub->m_num2 = 5;
	cout << Sub->m_num1 << "-" << Sub->m_num2 << "=" << Sub->Get_Result() << endl;
}
//乘法
void test_Mul_Abs_traCalculator()
{
	AbstractCalculator* Mul = new MulAbstract;//划出一块空间存放AddAbstract

	Mul->m_num1 = 20;
	Mul->m_num2 = 5;
	cout << Mul->m_num1 << "*" << Mul->m_num2 << "=" << Mul->Get_Result() << endl;
}

//此时后期再维护加个除法和一个平方
class DivAbstract :public AbstractCalculator
{
public:
	int Get_Result()
	{
		return m_num1 / m_num2;
	}
};

void test_Div_Abs_traCalculator()
{
	AbstractCalculator* Div = new DivAbstract;
	Div->m_num1 = 20;
	Div->m_num2 = 5;
	cout << Div->m_num1 << "/" << Div->m_num2 << "=" << Div->Get_Result() << endl;
}

class PowAbstract :public AbstractCalculator
{
public:
	int Get_Result()
	{
		int temp = 1;
		for (int i = 0;i < m_num2;i++)
		{
			temp *= m_num1;
		}
		return temp;
	}
};

void test_Pow_Abs_traCalculator()
{
	AbstractCalculator* Pow = new PowAbstract;
	Pow->m_num1 = 20;
	Pow->m_num2 = 5;
	cout << Pow->m_num1 << "^" << Pow->m_num2 << "=" << Pow->Get_Result() << endl;
}

int add(int a, int b)
{
	return 0;
}

/*
	小结：
		1.父类的虚函数屁用没有（没有调用到），可以把他纯虚化——纯虚函数。此时这类（父类）发生了变化，变成了抽象类，所以无法实例化对象
		2.子类要重写父类的成员函数（虚函数），否则也无法实例化对象.

*/