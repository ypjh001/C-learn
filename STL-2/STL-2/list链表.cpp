#include"list链表.h"

person::person(string name, int age, int height)
{
	this->m_name = name;
	this->m_age = age;
	this->m_height = height;
}

person::~person()
{
}

void myprintlist(const list<int>& List){

	if (List.size() == 0)
	{
		cout << "链表为空";
	}
	else
	{
		//遍历链表--防止修改数据，所以用const_iterator修饰
		for (list<int>::const_iterator i = List.begin(); i !=List.end(); i++)
		{
			cout << *i << " ";
		}
	}
	cout << endl;
}

//list构造
void test_structurn_list()
{
	//创建链表list容器
	list<int>L1;

	//添加数据push
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	//遍历容器
	myprintlist(L1);

	//利用区间构造容器
	list<int>L2(L1.begin(), L1.end());
	myprintlist(L2);

	//利用拷贝构造容器
	list<int>L3(L2);
	myprintlist(L3);

	//利用n个element构造容器
	list<int>L4(5, 100);
	myprintlist(L4);
}


//list赋值和交换
void test_AssignAndSwap_list()
{
	//构造容器
	list<int>L1;

	//插入数据
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	//打印L1
	myprintlist(L1);	//10 20 30 40

	//operator=赋值
	list<int>L2;
	L2 = L1;
	myprintlist(L2);	//10 20 30 40

	//assign赋值
	list<int>L3;
	L3.assign(L2.begin(), L2.end());
	myprintlist(L3);	//10 20 30 40

	//n个elem的赋值
	list<int>L4(10,999);
	myprintlist(L4);	//999 999 999 999 999 999 999 999 999 999

	//容器交换L1与L4
	cout << "交换前L1.size：" << L1.size() << endl;//交换前L1.size：4	
	cout << "交换前L4.size：" << L4.size() << endl;//L1.size：10
	//交换
	swap(L1, L4);

	myprintlist(L1);//999 999 999 999 999 999 999 999 999 999
	myprintlist(L2);//10 20 30 40
	cout <<"交换后L1.size：" << L1.size() << endl;//交换后L1.size：10
	cout << "交换后L4.size：" << L4.size() << endl;//交换后L4.size：4


}


//list容器大小操作
void test_sizeof_list()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	cout <<"L1的size：" << L1.size() << endl;		//4
	//从新指定L1的大小
	L1.resize(10);
	cout << "重新指定L1的size：" << L1.size() << endl;	//10

	if (L1.empty())//判断是否为空，空1，非空0
	{
		cout << "容器为空" << endl;
	}
	else {
		cout << "容器不为空" << endl;
	}

	list<int>L2;//未指定大小
	if (L2.empty())
	{
		cout << "容器为空" << endl;
	}
	else {
		cout << "容器不为空" << endl;
		cout << "L2容器的大小：" << L2.size() << endl;
	}

	//从新指定L2大小并填充数值
	L2.resize(5, 10);//5个10填充L2
	myprintlist(L2);	//10 10 10 10 10

	L2.resize(10);//5个0填充剩余的空位置
	myprintlist(L2);	//10 10 10 10 10 0 0 0 0 0

	L2.resize(3);//只留下前3个数值，其他清空
	myprintlist(L2);	//10 10 10
}

//list插入、删除
void test_InsertAnddelete_list()
{
	list<int>L1;
	//尾插
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);

	//头插
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);

	myprintlist(L1);//300 200 100 10 20 30

	//头删
	L1.pop_front();
	myprintlist(L1);//200 100 10 20 30
	//尾删
	L1.pop_back();
	myprintlist(L1);//200 100 10 20 

	//insert插入
	L1.insert(L1.begin(), 1000);
	myprintlist(L1);//1000 200 100 10 20 
	L1.insert(L1.end(), 50);
	myprintlist(L1);//1000 200 100 10 20 50

	//在位置插入,用迭代器,不能直接用L1.begin()+n;
	list<int>::iterator bit = L1.begin();
	L1.insert(++bit, 88);
	myprintlist(L1);//1000 88 200 100 10 20 50

	//删除erase
	L1.erase(L1.begin());
	myprintlist(L1);//88 200 100 10 20 50

	//移除remove--移除所有指定的元素
	L1.resize(10, 10);
	myprintlist(L1);//88 200 100 10 20 50 10 10 10 10
	L1.remove(10);
	myprintlist(L1);//88 200 100 20 50

	//清空
	L1.clear();
	myprintlist(L1);//链表为空	
}


//list数据存取
void test_Access_list()
{
	//由于链表结构特殊，每个数据不是连续的空间存储，所有不能用[]和at访问元素。

	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	L1.push_back(60);
	L1.push_back(70);
	L1.push_back(80);

	//访问-front--访问第一个元素
	cout << L1.front() << endl;//10

	//访问最后一个元素--back
	cout << L1.back() << endl;//80

	//list的迭代器不支持跳跃式的访问
	list<int>::iterator it = L1.begin();
	//it += 1;//error
			
	//支持双向
	cout << *it << endl;//10
	it++;
	cout << *it << endl;//20
	it--;
	cout << *it << endl;//10

	//可以用循环自增的方式访问任意位置
	int num = 3;//要访问的位置
	for (int i = 0; i < num-1; i++)
	{
		it++;
	}
	cout << *it << endl;//30
}


bool mycompare(int a,int b)
{
	//降序：第一个数大于第二个数
	return a > b;
}

//list反转和排序
void test_ReverseAndSort_list()
{
	list<int>L1;
	L1.push_back(40);
	L1.push_back(20);
	L1.push_back(50);
	L1.push_back(60);
	L1.push_back(10);
	L1.push_back(30);
	cout << "反转前：" << endl;
	myprintlist(L1);

	//反转函数reverse  以中间为对称轴反转
	L1.reverse();
	cout << "反转后：" << endl;
	myprintlist(L1);

	//排序sort
	L1.sort();//默认升序
	cout << "升序：";
	myprintlist(L1);

	/*
		注意：
			list的排序不能直接sort(L1.begin(),L1.end())怎么用，所以不支持随机访问迭代器的容器，不支持直接用标准算法
			不支持随机访问，内部会提供对应的一些算法
	*/

	//sort降序--要构造一个函数
	L1.sort(mycompare);
	cout << "降序：";
	myprintlist(L1);


}


//排序案例--sort的仿函数
bool apply_comp_list(person& p1, person& p2)
{
	//按照年龄升序
	
	if (p1.m_age==p2.m_age)
	{//当年龄相同，按照身高排序
		return p1.m_height >p2.m_height;
	}
	return p1.m_age < p2.m_age;
}


//排序案例
void test_apply_list()
{
	//创建Person容器
	list<person>L;

	//Person数据
	person P1("刘备", 35, 175);
	person P2("曹操", 45, 180);
	person P3("孙权", 40, 170);
	person P4("赵云", 25, 190);
	person P5("张飞", 35, 160);
	person P6("关羽", 35, 200);

	//插入数据
	L.push_back(P1);
	L.push_back(P2);
	L.push_back(P3);
	L.push_back(P4);
	L.push_back(P5);
	L.push_back(P6);

	//打印
	for (list<person>::const_iterator it = L.begin(); it!=L.end(); it++)
	{
		cout<<"name:" << it->m_name << " age:" << (*it).m_age << " height:" << (*it).m_height << endl;
	}

	//排序
	cout << "===========================排序后========================"<<endl;
	L.sort(apply_comp_list);
	for (list<person>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "name:" << (*it).m_name << " age:" << (*it).m_age << " height:" << (*it).m_height << endl;
	}

}


