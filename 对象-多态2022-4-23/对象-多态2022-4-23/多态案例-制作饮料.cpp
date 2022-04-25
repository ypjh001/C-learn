#include<iostream>
using namespace std;

/*
	制作饮料：
		1.煮水
		2.冲泡
		3.倒入杯中
		4.添加辅料
*/

class Abst_Drink
{
public:
	//1.煮水
	virtual void Boil() = 0;
	//2.冲泡
	virtual void Brew() = 0;
	//3.倒入杯中
	virtual void PourInCap() = 0;
	//4.添加辅料
	virtual void PutSomething() = 0;
};

//制作咖啡
class Coffee :public Abst_Drink
{
public:
	//1.煮水
	virtual void Boil()
	{
		cout<<"1.煮农夫山泉"<<endl;
	}
	//2.冲泡
	virtual void Brew()
	{
		cout<<"2.冲泡咖啡"<<endl;
	}
	//3.倒入杯中
	virtual void PourInCap()
	{
		cout<<"3.倒入玻璃杯中"<<endl;
	}
	//4.添加辅料
	virtual void PutSomething()
	{
		cout<<"4.添加浓缩奶"<<endl;
	}
};

void MakeCoffee()
{
	Abst_Drink* coffee = new Coffee;
	cout << "制作coffee的流程：" <<endl;
	coffee->Boil();
	coffee->Brew();
	coffee->PourInCap();
	coffee->PutSomething();
	delete coffee;
}

//制作阿萨姆奶茶
class Assam :public Abst_Drink
{
public:
	//1.煮水
	virtual void Boil()
	{
		cout << "1.煮怡泉" << endl;
	}
	//2.冲泡
	virtual void Brew()
	{
		cout << "2.冲泡阿萨姆" << endl;
	}
	//3.倒入杯中
	virtual void PourInCap()
	{
		cout << "3.倒入高脚玻璃杯中" << endl;
	}
	//4.添加辅料
	virtual void PutSomething()
	{
		cout << "4.添加洋葱" << endl;
	}
};

void MakeAssam()
{
	Abst_Drink* assam = new Assam;
	cout << "制做 阿萨姆 奶茶的流程：" << endl;
	assam->Boil();
	assam->Brew();
	assam->PourInCap();
	assam->PutSomething();
	delete assam;
}



//制作茶水
class Tea :public Abst_Drink
{
public:
	//1.煮水
	virtual void Boil()
	{
		cout << "1.煮山泉" << endl;
	}
	//2.冲泡
	virtual void Brew()
	{
		cout << "2.冲泡铁观音" << endl;
	}
	//3.倒入杯中
	virtual void PourInCap()
	{
		cout << "3.山泉倒入茶壶中" << endl;
	}
	//4.添加辅料
	virtual void PutSomething()
	{
		cout << "4.添加枸杞" << endl;
	}
};

void dotea(Abst_Drink* do_tea)//Abst_Drink*do_tea=new Tea,联动下面的dotea（new Tea)
{
	do_tea->Boil();
	do_tea->Brew();
	do_tea->PourInCap();
	do_tea->PutSomething();
	delete do_tea;
}

//珍珠奶茶
class PearlTea :public Abst_Drink
{
	//1.煮水
	virtual void Boil()
	{
		cout << "1.煮水" << endl;
	}
	//2.冲泡
	virtual void Brew()
	{
		cout << "2.开奶茶粉" << endl;
	}
	//3.倒入杯中
	virtual void PourInCap()
	{
		cout << "3.开水冲奶茶" << endl;
	}
	//4.添加辅料
	virtual void PutSomething()
	{
		cout << "4.放入珍珠" << endl;
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
	cout << "泡茶过程" << endl;
	dotea(new Tea);
	cout << "==========分割线============"<<endl;
	cout << "珍珠奶茶制作过程" << endl;
	dotea(new PearlTea);

}