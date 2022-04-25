#include<iostream>
using namespace std;

//1.CPU类
class CPU
{
public:
	virtual void Calculater() = 0;
};
//2.显卡类
class VideoCard
{
public:
	virtual void Display() = 0;
};
//3.内存类
class Memory
{
public:
	virtual void Storage() = 0;
};
//电脑类
class Computer
{
public:
	
	~Computer()
	{
		cout << "Computer的析构函数" << endl;
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
		cout << "Computer的构造函数" << endl;
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

//inter继承CPU、显卡、内存
class InternetCPU :public CPU
{
public:
	InternetCPU()
	{
		cout << "InternetCPU的构造函数" << endl;
	}
	~InternetCPU()
	{
		cout << "InternetCPU的析构函数" << endl;
	}
	virtual void Calculater()
	{
		cout << "inter的CPU开始运行" << endl;
	}
};

class InertnetMemoey :public Memory
{
public:
	InertnetMemoey()
	{
		cout << "InertnetMemoey 的构造函数" << endl;
	}

	~InertnetMemoey()
	{
		cout << "InertnetMemoey 的析构函数" << endl;
		/*if (m_mem != NULL)
		{

		}*/
	}

	
	virtual void Storage()
	{
		cout << "inter的存储开始运行" << endl;
	}
};

class InternetVideoCard :public VideoCard
{
public:
	InternetVideoCard()
	{
		cout << "InternetVideoCard的构造函数" << endl;
	}
	~InternetVideoCard()
	{
		cout << "InternetVideoCard的析构函数" << endl;
	}
	virtual void Display()
	{
		cout << "inter的显卡开始运行" << endl;
	}
};
//Leven继承CPU、显卡、内存
class LevenCPU :public CPU
{
public:
	virtual void Calculater()
	{
		cout << "Leven的CPU开始运行" << endl;
	}
};

class LevenMemoey :public Memory
{
public:
	virtual void Storage()
	{
		cout << "Leven的存储开始运行" << endl;
	}
};

class LevenVideoCard :public VideoCard
{
public:
	virtual void Display()
	{
		cout << "Leven的显卡开始运行" << endl;
	}
};


//class ReggedCPU :public CPU
//{
//public:
//	virtual void Calculater()
//	{
//		cout << "Regged的CPU开始运行" << endl;
//	}
//};
//
//class ReggedMemoey :public Memory
//{
//public:
//	virtual void Storage()
//	{
//		cout << "Regged的存储开始运行" << endl;
//	}
//};
//
//class ReggedVideoCard :public VideoCard
//{
//public:
//	virtual void Display()
//	{
//		cout << "Regged的显卡开始运行" << endl;
//	}
//};

void test_leven_computer()
{
	CPU* Leven_cpu = new LevenCPU;//实例化InternetCPU，（划分一块空间给他）
	Memory* Leven_mem = new LevenMemoey;//实例化并写数据
	VideoCard* Leven_vc = new LevenVideoCard;//实例化并写数据
	Computer* leven_computer= new Computer(Leven_cpu, Leven_mem, Leven_vc);//传数据
	leven_computer->Dowoork();//执行（实现）数据	
	delete leven_computer;
	cout << "==============分割线==================="<<endl;
	
}
void test_inter_computer()
{
	CPU* Intertnet_cpu = new InternetCPU;//实例化InternetCPU，（划分一块空间给他）
	Memory* Intertnet_mem = new InertnetMemoey;//实例化并写数据
	VideoCard* Intertnet_vc = new InternetVideoCard;//实例化并写数据
	Computer* Intertnet_computer = new Computer(Intertnet_cpu, Intertnet_mem, Intertnet_vc);//传数据
	Intertnet_computer->Dowoork();//执行（实现）数据	
	delete Intertnet_computer;
	cout << "==============分割线===================" << endl;
}



