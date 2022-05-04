#include"deque容器.h"

//打印deque的数据
void myPrintDeque(const deque<int>&deq)
{
	//先判断是否为空
	if (deq.size() == 0)
	{
		cout << "双端数组为空" << endl;
	}
	else
	{
		//否则打印双端数组内容
		for (deque<int>::const_iterator i = deq.begin(); i != deq.end(); i++)//用const修饰防止在函数体里修改数值
		{
			//比如
			//*i = 100;	//error
			cout << *i << "  ";
		}
		cout << endl;
	}

}



//deque的构造函数
void test_Structurn_deque()
{
	//1.默认构造函数构建双端数组d1
	deque<int>d1;

	//对双端数组d1赋值
	for (int i = 0; i < 5; i++)
	{
		d1.push_back(i);
	}
	myPrintDeque(d1);


	//2.利用区间的方式创建双端数组
	deque<int>d2(d1.begin(), d1.end());

	//打印双端数组d2
	myPrintDeque(d2);

	//3.利用n个element（元素）创建双端数组
	deque<int>d3(3, 100);

	//打印双端数组d3
	myPrintDeque(d3);

	//利用拷贝构造创建双端数组d4
	deque<int>d4(d3);//d4 copy d3
	
	//print d4
	myPrintDeque(d4);

}


//deque的赋值
void test_Assign_deque()
{
	//创建双端数组d1
	deque<int>d1;

	//赋值
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}

	//1.创建双端数组d2,然后用operator=赋值

	deque<int>d2(d1);
	myPrintDeque(d2);

	//2.利用assign赋值
	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	myPrintDeque(d3);

	//3.利用n个element的方式赋值
	deque<int>d4(5,100);
	myPrintDeque(d4);
}


//deque大小操作
void test_Size_deque()
{
	//deque没有容量（capacity)的概念

	//创建双端数组d1
	deque<int>d1;
	
	//双端数组赋值
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}

	//打印双端数组数据
	myPrintDeque(d1);

	if (d1.empty())	//empty:空的
	{
		//d1.empty()返回bool类型：空返回1，非空返回0
		cout << "空" << endl;
	}
	else
	{
		cout << "非空" << endl;
	}

	//重新指定大小
	cout << "重新指定前大小：" << d1.size() << endl;
	d1.resize(15);
	cout << "重新指定后大小：" << d1.size() << endl;

	//重新指定大小，并有某数填充
	cout << "重新指定前大小：" << d1.size() << endl;
	myPrintDeque(d1);
	d1.resize(20, 9);
	cout << "重新指定后大小：" << d1.size() << endl;
	myPrintDeque(d1);

	d1.erase(d1.begin(), d1.begin()+5);//从什么开始到什么结束删除数据
	myPrintDeque(d1);

	d1.resize(5);//从后面删除到剩余5个元素
	myPrintDeque(d1);
}


//deque insert and delete
void test_InsertAndDelete_deque()
{
	//创建双端数组d1
	deque<int>d1;

	//尾插入
	d1.push_back(10);
	d1.push_back(20);

	//头插入
	d1.push_front(100);
	d1.push_front(200);

	//打印双端数组
	myPrintDeque(d1);//200  100  10  20

	//头删
	d1.pop_front();
	myPrintDeque(d1);	//100  10  20
	//尾删
	d1.pop_back();
	myPrintDeque(d1);	//100  10

	//创建双端数组d2
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_front(10);
	d2.push_front(20);
	myPrintDeque(d2);	//20  10  1  2

	//在任意位置（d2.size范围内）
	d2.insert(d2.begin(), 100);//在第一个位置插入1个100,	//100  20  10  1  2
	myPrintDeque(d2);

	d2.insert(d2.begin(), 3,200);	//在第一个位置插入3个200		,200  200  200  100  20  10  1  2
	myPrintDeque(d2);

	d2.insert(d2.begin() + 3, 2, 400);	//在第d2.begin()+3=1+3=4的位置上加2个400		200  200  200  400  400  100  20  10  1  2
	myPrintDeque(d2);

	//按照区间的方式插入
	deque<int>d3;
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);
	d3.push_back(4);
	d2.insert(d2.begin(), d3.begin() + 1, d3.end());	//在d2的begin（）位置上开始插入，从d3.begin（）+1到d3.end（）{即2、3、4}的数据		2  3  4  200  200  200  400  400  100  20  10  1  2
	myPrintDeque(d2);


	//删除
	d2.erase(d2.begin()+3);//删除第四个元素	2  3  4  200  200  400  400  100  20  10  1  2
	myPrintDeque(d2);

	//按照区间的删除
	d2.erase(d2.begin() + 3, d2.end());	//删除第四个到最后一个
	myPrintDeque(d2);	//2 3 4

	//删除全部
	d2.clear();
	myPrintDeque(d2);	//双端数组为空

}


//deque数据存取
void test_Access_deque()
{
	//创建双端数组d1
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	//访问元素
	for (int i = 0; i < d1.size(); i++)
	{

		//通过[]访问元素
		cout << d1[i] << "  ";		
	}			//300  200  100  10  20  30
	cout << endl;
	for (int i = 0; i < d1.size(); i++)
	{
		//通过成员函数at访问
		cout << d1.at(i) << "  ";
	}		//300  200  100  10  20  30
	cout << endl;

	cout << "front访问第一个元素:" << d1.front() << endl;	//300
	cout << "back访问最后一个元素:" << d1.back() << endl;	//30
}

//sort deque 排序
int compare(int a, int b)
{
	return a > b ;
}
void test_Sort_deque()
{

	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	myPrintDeque(d1);	//300  200  100  10  20  30

	//排序
	cout << "排序后：" << endl;
	sort(d1.begin(), d1.end());	//默认从小到达排序（）里是排序范围
	myPrintDeque(d1);
	
}



