#include<iostream>
#include"��̬����-�����.h"
#include"���麯���ͳ�����.h"
#include"��̬����-��������.h"
#include"�������ʹ�������.h"
#include"��̬����-������װ.h"
using namespace std;


/*
	��̬��OOP����������֮һ
	���ࣺ
		��̬��̬���������ء��������أ����ú�����
		��̬��̬�������ࣨ���ࣩ���麯������ʱ��̬

	����̬����
		��̬��ַ��󶨣��������ȷ��������ַ
		��̬��ַ��󶨣����н׶�ȷ��������ַ
*/


/*
	��̬��̬����������
		1.�м̳й�ϵ��
		2.������д������麯�����������п��Բ�дvirtual��Ҳ����д������

	ע�⣺
		1.�������أ���һ��������������������ֵ��ͬ��������ͬ��������ͬ��
		2.������д���ڼ̳й�ϵ�У�������дһ�鸸����麯����
*/
//���︸�ࣨ���ࣩ
class Animal
{
public:
	virtual void speak()//virtual �������黯--����麯��
	{
		cout << "�Ƕ�����˵��\n";
	}
};
//Сè���ࣨ�����ࣩ
class Cat :public Animal
{
public:
	virtual void speak()
	{
		cout << "��Сè��˵��\n";
	}
};
//С�����ࣨ�����ࣩ
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "��С����˵��\n";
	}
};
//ִ��˵����
void DoSpeak(Animal &animal)//�������ֱ��ָ��֮�����--cat or dog
{
	animal.speak();
}
//����˵��
void test()
{
	Cat cat;
	Dog dog;
	//DoSpeak(cat);//���Ĭ�ϵ���˭��Animal����Cat����Ȼ��Animal����Animal�ഴ����Աvoid speak��ʱ��ϵͳ�Ѿ������ַ��speak����DoSpeak����animal�ĵ�ַ������ִ��Animal��speak��
				//��Ƣ�������Ҫ�������������Cat���spea�أ������ڸ���ĳ�Աspeakǰ�Ӹ�virtual��ʹ������麯��
	DoSpeak(cat);
	DoSpeak(dog);
	cat.speak();//��è
	dog.speak();//����
	cat.Animal::speak();//���߼Ӹ�������--������
	dog.Animal::speak();//���߼Ӹ�������--������
}

int main()
{
	//test();

	//cout<<add(3, 5)<<endl;
	//
	//test_Calculator();
	//
	//test_Add_Abs_traCalculator();//+
	//
	//test_Sub_Abs_traCalculator();//-
	//
	//test_Mul_Abs_traCalculator();//*

	//test_Div_Abs_traCalculator();///

	//test_Pow_Abs_traCalculator();//^

	//test_chun_vir();

	////=======================================
	//MakeCoffee();
	//cout << "==========�ָ���===========" << endl;
	//MakeAssam();
	//cout << "==========�ָ���===========" << endl;
	//DoTea();

	//test_speak();

	 test_leven_computer();
	 test_inter_computer();
	//cout << "ѧϰ";
	return 0;
}