#include<iostream>
using namespace std;

/*
	�������ϣ�
		1.��ˮ
		2.����
		3.���뱭��
		4.��Ӹ���
*/

class Abst_Drink
{
public:
	//1.��ˮ
	virtual void Boil() = 0;
	//2.����
	virtual void Brew() = 0;
	//3.���뱭��
	virtual void PourInCap() = 0;
	//4.��Ӹ���
	virtual void PutSomething() = 0;
};

//��������
class Coffee :public Abst_Drink
{
public:
	//1.��ˮ
	virtual void Boil()
	{
		cout<<"1.��ũ��ɽȪ"<<endl;
	}
	//2.����
	virtual void Brew()
	{
		cout<<"2.���ݿ���"<<endl;
	}
	//3.���뱭��
	virtual void PourInCap()
	{
		cout<<"3.���벣������"<<endl;
	}
	//4.��Ӹ���
	virtual void PutSomething()
	{
		cout<<"4.���Ũ����"<<endl;
	}
};

void MakeCoffee()
{
	Abst_Drink* coffee = new Coffee;
	cout << "����coffee�����̣�" <<endl;
	coffee->Boil();
	coffee->Brew();
	coffee->PourInCap();
	coffee->PutSomething();
	delete coffee;
}

//��������ķ�̲�
class Assam :public Abst_Drink
{
public:
	//1.��ˮ
	virtual void Boil()
	{
		cout << "1.����Ȫ" << endl;
	}
	//2.����
	virtual void Brew()
	{
		cout << "2.���ݰ���ķ" << endl;
	}
	//3.���뱭��
	virtual void PourInCap()
	{
		cout << "3.����߽Ų�������" << endl;
	}
	//4.��Ӹ���
	virtual void PutSomething()
	{
		cout << "4.������" << endl;
	}
};

void MakeAssam()
{
	Abst_Drink* assam = new Assam;
	cout << "���� ����ķ �̲�����̣�" << endl;
	assam->Boil();
	assam->Brew();
	assam->PourInCap();
	assam->PutSomething();
	delete assam;
}



//������ˮ
class Tea :public Abst_Drink
{
public:
	//1.��ˮ
	virtual void Boil()
	{
		cout << "1.��ɽȪ" << endl;
	}
	//2.����
	virtual void Brew()
	{
		cout << "2.����������" << endl;
	}
	//3.���뱭��
	virtual void PourInCap()
	{
		cout << "3.ɽȪ��������" << endl;
	}
	//4.��Ӹ���
	virtual void PutSomething()
	{
		cout << "4.������" << endl;
	}
};

void dotea(Abst_Drink* do_tea)//Abst_Drink*do_tea=new Tea,���������dotea��new Tea)
{
	do_tea->Boil();
	do_tea->Brew();
	do_tea->PourInCap();
	do_tea->PutSomething();
	delete do_tea;
}

//�����̲�
class PearlTea :public Abst_Drink
{
	//1.��ˮ
	virtual void Boil()
	{
		cout << "1.��ˮ" << endl;
	}
	//2.����
	virtual void Brew()
	{
		cout << "2.���̲��" << endl;
	}
	//3.���뱭��
	virtual void PourInCap()
	{
		cout << "3.��ˮ���̲�" << endl;
	}
	//4.��Ӹ���
	virtual void PutSomething()
	{
		cout << "4.��������" << endl;
	}
};

void Do_pearl_Tea(Abst_Drink* pearl_Tea)
{
	pearl_Tea->Boil();
	pearl_Tea->Brew();
	pearl_Tea->PourInCap();
	pearl_Tea->PutSomething();
	delete pearl_Tea;
}
void DoTea()
{
	cout << "�ݲ����" << endl;
	dotea(new Tea);
	cout << "==========�ָ���============"<<endl;
	cout << "�����̲���������" << endl;
	dotea(new PearlTea);

}