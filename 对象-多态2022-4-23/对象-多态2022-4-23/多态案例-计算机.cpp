#include<iostream>
#include<string>
#include "��̬����-�����.h"
using namespace std;
//���ļ�
/*
	1.ͷ�ļ�
	2.Դԭ��
	3.Դ�ļ��ж��庯��
	4.ͷ�ļ�����������
*/

/*
	��̬�ô���
		1.������֯�ṹ����
		2.�ɶ���ǿ
		3.����ǰ�ںͺ��ڵķ�չ�Լ�ά��


	ע�⣺
		����ά��������Ҫ��ԭ��

	
*/

//--------------------------------
//int add(int a,int b)
//{
//	return a + b;
//}
//--------------------------------

//��ͨд����
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
		//������ڼ�/
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
//��̬����ʵ�ּ������
//����
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
//����--�ӷ�
class AddAbstract :public AbstractCalculator
{
	//��д�����麯��
public:
	//����Ҫ��д�����Ա�������麯����������Ҳ����ʵ����������˵����ʵ��ʵ��������.
	 int Get_Result()
	{
		return m_num1 + m_num2;
	}
	 /*int Add()
	 {
		 return m_num1 + m_num2;
	 }*/
};
//����--����
class SubAbstract :public AbstractCalculator
{
	//��д�����麯��
public:
	int Get_Result()
	{
		return m_num1 - m_num2;
	}
};
//����--�˷�
class MulAbstract :public AbstractCalculator
{
	//��д�����麯��
public:
	int Get_Result()
	{
		return m_num1 * m_num2;
	}
};
//ʵ�����ӷ������üӷ�
void test_Add_Abs_traCalculator()
{
	AbstractCalculator* Add = new AddAbstract;//����һ��ռ���AddAbstract

	Add->m_num1=20;
	Add->m_num2=5;
	cout << Add->m_num1 << "+" << Add->m_num2 << "=" << Add->Get_Result() << endl;
}

//����
void test_Sub_Abs_traCalculator()
{
	AbstractCalculator* Sub = new SubAbstract;//����һ��ռ���AddAbstract

	Sub->m_num1 = 20;
	Sub->m_num2 = 5;
	cout << Sub->m_num1 << "-" << Sub->m_num2 << "=" << Sub->Get_Result() << endl;
}
//�˷�
void test_Mul_Abs_traCalculator()
{
	AbstractCalculator* Mul = new MulAbstract;//����һ��ռ���AddAbstract

	Mul->m_num1 = 20;
	Mul->m_num2 = 5;
	cout << Mul->m_num1 << "*" << Mul->m_num2 << "=" << Mul->Get_Result() << endl;
}

//��ʱ������ά���Ӹ�������һ��ƽ��
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
	С�᣺
		1.������麯��ƨ��û�У�û�е��õ��������԰������黯�������麯������ʱ���ࣨ���ࣩ�����˱仯������˳����࣬�����޷�ʵ��������
		2.����Ҫ��д����ĳ�Ա�������麯����������Ҳ�޷�ʵ��������.

*/