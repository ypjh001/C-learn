#include<iostream>
#include<string>
using namespace std;

/*
	ע�⣺
		ʹ�ö�̬ʱ���������п����µĿռ䣬����ָ���ͷ�ʱ�޷����õ��������������
	���������
		�����������������Ϊ���������ߴ�������

	�������ʹ��������� ��ͬ�㣺
		1.���Խ������ָ���ͷ��������
		2.����Ҫ����ĺ���ʵ��
	�������ʹ��������� ����ͬ�㣺
		����Ǵ����������������ڳ����࣬�޷�ʵ��������

*/

class Animal1
{
public:
	Animal1();
	//virtual ~Animal1();//�黯�����������������Զ�������ʱ�����Ե��� ���� ������������
	virtual ~Animal1() = 0;//����������Ҫ��������Ҫ�ж���
	//�д�������֮����ǳ����࣬�޷�ʵ��������
	
	virtual void speak() = 0;
};
Animal1::~Animal1()
{
	cout << "Animal1�Ĵ���������" << endl;
}
Animal1::Animal1()
{
	cout << "Animal1�Ĺ��캯��" << endl;
}

//Animal1::~Animal1()
//{
//	cout << "Animal1����������" << endl;
//
//}
class Cat1 :public Animal1
{
public:

	~Cat1();
	string* cat_name;
	Cat1 (string c_name)
	{
		cout << "Cat1�Ĺ��캯��" << endl;
		cat_name = new string(c_name);
	}
	virtual void speak()
	{
		cout <<*cat_name<< "Сè˵��" << endl;
	}
	
};


void DoSpeak(Animal1 * speak)
{
	speak->speak();

}

Cat1::~Cat1()
{
	cout << "Cat1����������" << endl;
	//�ж������п��ٵ�cat_name�ѿռ䣬Ȼ���ͷ�cat_name�Ŀռ䡣
	if (cat_name!=NULL)
	{
		delete cat_name;
		cat_name = NULL;
	}
}
void test_speak()
{
	Animal1* animal = new Cat1("tony");//�������Ǵ����ĸ���ָ�룬��������
	//����ָ��������ʱ�� ���������������������������������ж������ԣ������ͷţ������ڴ�й¶.
	//����취���Ѹ�������������黯�������������
	animal->speak();
	//Animal1* C1 = new Cat1("hey");
	//C1->speak();
	delete animal; 
}


