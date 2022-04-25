#include<iostream>
using namespace std;

//1.CPU��
class CPU
{
public:
	virtual void Calculater() = 0;
};
//2.�Կ���
class VideoCard
{
public:
	virtual void Display() = 0;
};
//3.�ڴ���
class Memory
{
public:
	virtual void Storage() = 0;
};
//������
class Computer
{
public:
	
	~Computer()
	{
		cout << "Computer����������" << endl;
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
	}
	Computer(CPU* cpu, Memory* mem, VideoCard* vc)
	{
		m_cpu = cpu;
		m_mem = mem;
		m_vc = vc;
		cout << "Computer�Ĺ��캯��" << endl;
	}
	void Dowoork()
	{
		m_cpu->Calculater();
		m_vc->Display();
		m_mem->Storage();
	}
private:
	CPU* m_cpu;
	Memory* m_mem;
	VideoCard* m_vc;
};

//inter�̳�CPU���Կ����ڴ�
class InternetCPU :public CPU
{
public:
	InternetCPU()
	{
		cout << "InternetCPU�Ĺ��캯��" << endl;
	}
	~InternetCPU()
	{
		cout << "InternetCPU����������" << endl;
	}
	virtual void Calculater()
	{
		cout << "inter��CPU��ʼ����" << endl;
	}
};

class InertnetMemoey :public Memory
{
public:
	InertnetMemoey()
	{
		cout << "InertnetMemoey �Ĺ��캯��" << endl;
	}

	~InertnetMemoey()
	{
		cout << "InertnetMemoey ����������" << endl;
		/*if (m_mem != NULL)
		{

		}*/
	}

	
	virtual void Storage()
	{
		cout << "inter�Ĵ洢��ʼ����" << endl;
	}
};

class InternetVideoCard :public VideoCard
{
public:
	InternetVideoCard()
	{
		cout << "InternetVideoCard�Ĺ��캯��" << endl;
	}
	~InternetVideoCard()
	{
		cout << "InternetVideoCard����������" << endl;
	}
	virtual void Display()
	{
		cout << "inter���Կ���ʼ����" << endl;
	}
};
//Leven�̳�CPU���Կ����ڴ�
class LevenCPU :public CPU
{
public:
	virtual void Calculater()
	{
		cout << "Leven��CPU��ʼ����" << endl;
	}
};

class LevenMemoey :public Memory
{
public:
	virtual void Storage()
	{
		cout << "Leven�Ĵ洢��ʼ����" << endl;
	}
};

class LevenVideoCard :public VideoCard
{
public:
	virtual void Display()
	{
		cout << "Leven���Կ���ʼ����" << endl;
	}
};


//class ReggedCPU :public CPU
//{
//public:
//	virtual void Calculater()
//	{
//		cout << "Regged��CPU��ʼ����" << endl;
//	}
//};
//
//class ReggedMemoey :public Memory
//{
//public:
//	virtual void Storage()
//	{
//		cout << "Regged�Ĵ洢��ʼ����" << endl;
//	}
//};
//
//class ReggedVideoCard :public VideoCard
//{
//public:
//	virtual void Display()
//	{
//		cout << "Regged���Կ���ʼ����" << endl;
//	}
//};

void test_leven_computer()
{
	CPU* Leven_cpu = new LevenCPU;//ʵ����InternetCPU��������һ��ռ������
	Memory* Leven_mem = new LevenMemoey;//ʵ������д����
	VideoCard* Leven_vc = new LevenVideoCard;//ʵ������д����
	Computer* leven_computer= new Computer(Leven_cpu, Leven_mem, Leven_vc);//������
	leven_computer->Dowoork();//ִ�У�ʵ�֣�����	
	delete leven_computer;
	cout << "==============�ָ���==================="<<endl;
	
}
void test_inter_computer()
{
	CPU* Intertnet_cpu = new InternetCPU;//ʵ����InternetCPU��������һ��ռ������
	Memory* Intertnet_mem = new InertnetMemoey;//ʵ������д����
	VideoCard* Intertnet_vc = new InternetVideoCard;//ʵ������д����
	Computer* Intertnet_computer = new Computer(Intertnet_cpu, Intertnet_mem, Intertnet_vc);//������
	Intertnet_computer->Dowoork();//ִ�У�ʵ�֣�����	
	delete Intertnet_computer;
	cout << "==============�ָ���===================" << endl;
}



