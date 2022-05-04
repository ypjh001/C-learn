#include"Vector.h"
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void myprintf(int val)
{
	//利用STL的回调函数，要自己创一个函数
	cout << val << "  ";
}
cout << endl;

void leran_Vector()
{
	//建一个Vector的容器、数组
	vector<int> V;

	//向容器中插入数据
	V.push_back(10);		//push:推、挤插入
	V.push_back(20);
	V.push_back(30);
	V.push_back(40);

	//通过迭代器访问V的vector里的数据
	vector<int>::iterator itBegin = V.begin();	 //起始迭代器，指向第一个数据，上例中“10”的位置
	vector<int>::iterator itEnd = V.end();		//结束迭代器，指向最后一个数据的下一个位置，上例中“40”后面的位置

	//第一种遍历访问
	while (itBegin != itEnd)
	{
		cout << *itBegin << "  ";
		itBegin++;
	}
	cout << endl;
	////倒回来遍历访问
	//while (itBegin!=itEnd)
	//{
	//	cout << *(itEnd-1) << endl;//因为*ITEnd指向一个空的地址，会出现错误，要想指向“40”，则要itEnd的地址向前移动一个单位：*(itEnd-1)
	//	itEnd--;
	//}

	////第二种遍历（常用、代码少）
	//for (vector<int>::iterator it=V.begin() ; it!=V.end(); it++)//
	//{
	//	cout << *it << endl;
	//}


	//第三种遍历算法,利用STL提供的遍历算法--目前对我来说要求较高
	for_each(V.begin(), V.end(), myprintf);

}


Person::Person(string name, int age)
{
	this->m_name = name;
	this->m_age = age;
}

Person::~Person()
{
}



//再实现函数：test_custom_vector()
void test_custom_Person_vector()
{
	//创造一个Person类的Vector  V这个容器叫V
	vector<Person> V;

	//创造对象--实例化并赋值
	Person P1("aaa", 10);
	Person P2("bbb", 20);
	Person P3("ccc", 30);
	Person P4("ddd", 40);
	Person P5("eee", 50);

	//向容器中插入数据--尾插法
	V.push_back(P1);
	V.push_back(P2);
	V.push_back(P3);
	V.push_back(P4);
	V.push_back(P5);

	//打印数据--遍历数据
	for (vector<Person>::iterator it = V.begin();it != V.end();it++)
	{
		//cout<<"姓名：" << it->m_name << " 年龄：" << it->m_age << endl;
		cout << "姓名：" << (*it).m_name << "年龄：" << (*it).m_age << endl;//.的运算优先级比*高，所以要加（）；<什么类型>，*it解出来的就是什么类型
	}

	//创造一个Person*的Vector 这个容器叫V1
	vector<Person*> V1;

	//创造对象--实例化并赋值
	Person P6("aaa", 10);
	Person P7("bbb", 20);
	Person P8("ccc", 30);
	Person P9("ddd", 40);
	Person P10("eee", 50);

	//向容器中插入数据--尾插法---V1容器存放的是地址，所以P6-10要加个取地址符号&
	V1.push_back(&P6);
	V1.push_back(&P7);
	V1.push_back(&P8);
	V1.push_back(&P9);
	V1.push_back(&P10);

	//打印数据--遍历数据
	for (vector<Person*>::iterator it = V1.begin();it != V1.end();it++)
	{
		//cout<<"姓名：" << it->m_name << " 年龄：" << it->m_age << endl;
		//cout << ":::姓名：" << (*it)->m_name << "年龄：" << (*it)->m_age << endl;//.的运算优先级比*高，所以要加（）；<什么类型>，*it解出来的就是什么类型	//指针用箭头，地址用解引号符*

		Person* p = (*it);
		cout << "name:" << p->m_name << "  age：" << p->m_age << endl;
	}
}


//容器嵌套容器-nested

void test_Vct_nested_Vct()
{
	//创建大容器 V
	vector<vector<int>>V;

	//创建小容器 v
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;

	//向小容器中添加数据
	for (int i = 0; i < 3; i++)
	{
		v1.push_back(10);
		v2.push_back(20);
		v3.push_back(30);
		v4.push_back(40);
	}
	//向大容器V中添加小容器(v1-v4)
	V.push_back(v1);
	V.push_back(v2);
	V.push_back(v3);
	V.push_back(v4);
	
	//打印大容器里的数据
	for (vector<vector<int>>::iterator It = V.begin(); It !=V.end(); It++) 
	{

		//第一种打印

		////打印v1
		////cout << "打印v1" << endl;;
		//for (vector<int>::iterator it1 = v1.begin();it1 != v1.end();it1++)
		//{
		//	cout << *it1 << "  ";
		//}
		////打印v2
		////cout << "打印v2"<<endl;
		//for (vector<int>::iterator it2 = v2.begin();it2 != v2.end();it2++)
		//{
		//	cout << *it2 << "  ";
		//}
		////打印v3
		////cout << "打印v3"<<endl;
		//for (vector<int>::iterator it3 = v3.begin();it3 != v3.end();it3++)
		//{
		//	cout << *it3 << "  ";
		//}
		////打印v4
		////cout << "打印v4" << endl;
		//for (vector<int>::iterator it4 = v4.begin();it4 != v4.end();it4++)
		//{
		//	cout << *it4 << "  ";
		//}


		//第二种打印
		for (vector<int>::iterator vit = (*It).begin(); vit != (*It).end(); vit++)
		{
			//It类型是vector<int>
			//*It类型是int（这里vit=*It）
			//*vit的类型是实数10-40
			cout << *vit << "   ";
		}
		cout << endl;

	}
}

//判断容器是否为空和打印容器数据
void printvector(vector<int >& vec)
{
	if (vec.empty())
	{
		cout << "容器为空！" << endl;
	}
	else
	{
		for (vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
		{
			cout << *i << " ";
			if (i == vec.end()-1)
			{
				cout << endl;
			}
		}
	}
	
	
}

//vector 的默认构造
void structure_vector()
{
	//默认构造
	vector<int >v1;
	for (int i = 0; i < 10; i++)
	{
		//插入数据
		v1.push_back(i);
	}
	printvector(v1);
	cout << endl;

	//通过区间方式进行构造,直接拿v1的范围进行构造
	vector<int>v2(v1.begin(), v1.end());
	printvector(v2);
	cout << endl;


	//n个elem的方式构造
	vector<int>v3(10, 100);//10个100
	printvector(v3);
	cout << endl;

	//拷贝构造
	vector<int>v4(v3);//拷贝v3
	printvector(v4);

}


//vector的赋值操作
void test_assign_vector()
{
	vector<int >v1;
	for (int i = 0; i < 5; i++)
	{
		//插入数据
		v1.push_back(i);
	}
	printvector(v1);
	cout << endl;

	//直接用=
	vector<int>v2;
	v2 = v1;
	printvector(v2);
	cout << endl;

	//assign赋值
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	printvector(v3);
	cout << endl;

	//n个elem方式赋值
	vector<int>v4;
	v4.assign(10, 100);
	printvector(v4);
	cout << endl;
}

//vector容量和大小--volume and size
void test_volumeAndsize_vector()
{
	//构造容器v
	vector<int>v1;
	vector<int>v2;
	//给容器v赋值
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//打印容器v的数据
	printvector(v1);
	if (v1.empty())//判断容器是否为空容器，真则空，假则非空
	{
		cout << "容器v1为空";
	}
	else
	{
		cout << "容器v1不为空"<<endl;
		cout<<"容器v1的大小："<<v1.size()<<endl;//容器大小
	}
	cout<<"容器v1的容量：" << v1.capacity() << endl;//v1.的容量
	cout << "在v1中再加一个元素10之后"<<endl;
	v1.push_back(10);
	
	cout << "容器v1的大小：" << v1.size() << endl;//容器大小
	cout << "容器v1的容量：" << v1.capacity()<<endl;//v1.的容量

	//容量≥大小
	v1.resize(15, 3);//从新指定v1的大小为15，用3补上
	printvector(v1);
	cout << "容器v1的大小：" << v1.size() << endl;//容器大小
	cout << "容器v1的容量：" << v1.capacity() << endl;//v1.的容量

	v1.resize(20);//从新指定v1的大小为20，用0补上
	printvector(v1);
	cout << "容器v1的大小：" << v1.size() << endl;//容器大小
	cout << "容器v1的容量：" << v1.capacity() << endl;//v1.的容量

	v1.resize(10);//从新指定v1的大小为10，超出部分删掉
	printvector(v1);
	cout << "容器v1的大小：" << v1.size() << endl;//容器大小
	cout << "容器v1的容量：" << v1.capacity() << endl;//v1.的容量

}


//vector的插入和删除 insert and delete
void test_InsertAndDelete()
{

	//创建一个容器
	vector<int>v1;

	//v1赋值
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 1);
	}
	printvector(v1);


	//v1插入新数据
	v1.insert(v1.end(),6);//新插入一个元素6
	printvector(v1);

	//迭代器--通过迭代器在任意位置（容器范围内）添加数据
	//v1.begin是在第一个数据
	v1.insert(v1.begin() + 1, 3);//v1.begin在第二位置，加个3,	这是迭代器
	printvector(v1);

	
	//在一个位置上连续添加3个100的数据
	v1.insert(v1.begin(), 3, 100);//在第一个位置前插入3个100
	printvector(v1);

	//删除
	v1.erase(v1.begin(), v1.begin() + 3);//删除3个100
	printvector(v1);
	
	//清空
	v1.clear();
	printvector(v1);

}


//vector数据存取--access
void test_AccessData_vector()
{
	//创建容器
	vector<int>v1;
	
	//容器赋值
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}

	//打印容器数据--访问容器数据
	cout << "通过[]遍历容器v1数据:";
	for (int i = 0; i < v1.size(); i++)
	{
		//通过[]访问
		cout << v1[i] << " ";
	}
	cout << endl;
	cout << "通过成员函数at遍历容器v1数据:";
	for (int i = 0; i < v1.size(); i++)
	{
		//通过at访问
		cout << v1.at(i) << " ";
	}
	cout << endl;

	//访问第一个元素
	cout << "第一个元素是：" << v1.front() << endl;

	//访问最后一个元素
	cout << "最后一个元素：" << v1.back() << endl;
}

//容器互换
void test_Swap_vector()
{
	//创建容器v1
	vector<int>v1;

	cout << "容器交换之前：" << endl;
	//容器v1赋值
	for (int i = 1; i < 10; i++)
	{
		v1.push_back(i);
	}
	//遍历V1
	printvector(v1);
	

	//创建容器v2
	vector<int>v2;

	//容器v2赋值
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	//遍历V2
	printvector(v2);
	cout << "v1.size=" << v1.size()<<"  ";
	cout << "v2.size=" << v2.size()<<"  "<<endl;

	cout << "容器交换之后：" << endl;
	swap(v1, v2);
	printvector(v1);
	printvector(v2);
	cout << "v1.size=" << v1.size()<<"  ";
	cout << "v2.size=" << v2.size()<<"  "<<endl;

	cout << "===============分隔符====================="<<endl;

	//巧用容器交换收缩内存
	//创建一个大容器v3
	vector<int>v3;

	//容器v3赋值
	for (int i = 0; i < 100000; i++)
	{
		v3.push_back(i);
	}
	cout << "v3的大小：" << v3.size()<<endl;
	cout << "v3的容量：" << v3.capacity()<<endl;
	
	cout << "重新设置v3的大小"<<endl;
	//重新设置v3的大小
	v3.resize(10);
	cout << "v3的大小：" << v3.size() << endl;
	cout << "v3的容量：" << v3.capacity() << endl;
	cout << "这样v3就多处了好多空余的容量浪费掉" << endl;

	//通过下面的方法使v3的容量缩小到适应范围
	vector<int>(v4);
	swap(v3, v4);
	cout << "v3的大小：" << v3.size() << endl;
	cout << "v3的容量：" << v3.capacity() << endl;
	cout << "v4的大小：" << v4.size() << endl;
	cout << "v4的容量：" << v4.capacity() << endl;

	//使v4容量缩短到合适的大小。vector<int>(v4)匿名对象
	//匿名对象特点：执行完当行时，系统自动回收空间
	vector<int>(v4).swap(v4);
	cout << "v4的大小：" << v4.size() << endl;
	cout << "v4的容量：" << v4.capacity() << endl;
}

//vector预留空间
void test_reserves_vector()
{
	//创建容器v1
	vector<int>v1;

	int count = 0;//统计重新分配内存次数
	int* p = NULL;//一个空指针

	//容器v1赋值
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
		if (p != &v1[0])	//判断指针p是否=容器首元素地址，如果不是，则强制将指针p=容器首元素地址，计次加一
		{					//vector属于动态扩大容量，并不是简单的再后面加容量，而是重新开辟一个更大的空间存放原来的数据，所以容器首元素地址会发生改变
			p = &v1[0];
			count++;
		}		
	}
	cout << "内存重新分配了：" << count<<"次" << endl;			//30次

	//假设已经知道了一个容器的大概需要多大的空间，则可以用预留空间reserve来运作
	vector<int>v2;
	v2.reserve(100000);
	int* p2=NULL;
	int count2=0;
	for (int i = 0; i < 100000; i++)
	{
		v2.push_back(i);
		if (p2!=&v2[0])
		{
			p2 = &v2[0];
			count2++;
		}
	}
	cout << "内存重新分配了：" << count2 << "次" << endl;		//1次

	//可以省去开辟新空间的时间和内存
}
