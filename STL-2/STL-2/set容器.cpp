#include"set容器.h"
#include<set>

//set的打印
void myprintset(const set<int>& s)
{
	if (s.empty())//empty判断为空
	{
		cout << "set容器为空";
	}
	for (set<int>::const_iterator i = s.begin(); i  !=s.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

//multiset的打印
void myprintmultiset(const multiset<int>& muls)
{
	if (muls.empty())//empty判断为空
	{
		cout << "set容器为空";
	}
	for (multiset<int>::const_iterator i = muls.begin(); i != muls.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}


//set的构造
void structurn_set()
{
	//构造set容器
	set<int>s1;

	//set赋值
	s1.insert(60);
	s1.insert(70);
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(80);
	s1.insert(40);
	s1.insert(30);


	//打印set
	myprintset(s1);//10 20 30 40 60 70 80	不会打印多个30，因为不能有重复

	//通过拷贝函数构造set容器
	set<int>s2(s1);
	myprintset(s2);

	//通过区间构造set容器
	set<int>s3(s2.begin(), s2.end());
	myprintset(s3);

	
	
}


//set的大小和交换
void tset_SizeAndSwap_set()
{
	set<int>s1;
	s1.insert(60);
	s1.insert(70);
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(80);
	s1.insert(40);
	s1.insert(30);

	//s1大小

	cout<<"s1的大小：" << s1.size() << endl;


	//交换
	set<int>s2;
	s2.insert(80);
	s2.insert(40);
	s2.insert(30);
	cout << "交换前s1：";
	myprintset(s1);
	cout << "交换前s2：";
	myprintset(s2);
	cout << "s1和s2交换" << endl;

	s2.swap(s1);
	cout << "交换后s1：";
	myprintset(s1);
	cout << "交换后s2：";
	myprintset(s2);
	cout << "s1的大小：" << s1.size() << endl;
}


//set的插入和删除
void test_InsertAndDelete_set()
{
	set<int>s1;

	//插入-insert
	s1.insert(60);
	s1.insert(70);
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(80);
	s1.insert(40);
	s1.insert(30);

	//s2复制s1过来
	set<int>s2(s1);

	//遍历
	myprintset(s1);//10 20 30 40 50 60 70 80

	//删除-erase
	s1.erase(s1.begin());//运用迭代器
	myprintset(s1);//20 30 40 50 60 70 80

	//s1.erase(s1.begin() + 2); error错误，和list一样不能怎么删除
	set<int>::iterator it = s1.begin();//迭代器，此时it=20
	for (int i = 0; i < 3; i++)
	{
		++it;
	}
	s1.erase(it);//循环三次后it走到50这里
	myprintset(s1);//20 30 40 60 70 80   删除了50
	
	//指定删除
	s1.erase(30);
	myprintset(s1);//20 40 60 70 80

	//清空clear
	s1.clear();
	myprintset(s1);//set容器为空

	//或者这样清空
	myprintset(s2);//10 20 30 40 50 60 70 80
	//清空s2
	s2.erase(s2.begin(), s2.end());
	myprintset(s2);//set容器为空
	
}

//set查找和统计
void test_FindAndCount_set()
{
	//find(key) ;查找key是否存在，不存在，则返回set.end（），若存在则返回该key的迭代器

	//count(key):统计key的个数，返回int


	set<int>s1;

	//插入-insert
	s1.insert(60);
	s1.insert(70);
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(80);
	s1.insert(40);
	s1.insert(30);

	set<int>::iterator pos = s1.find(50);
	if (pos != s1.end())
	{
		cout << "查找到了:" << *pos << endl;//迭代器解引用找到该元素
	}
	else
	{
		cout << "没找到！";
	}
	//统计
	int num = s1.count(40);
	cout <<"个数：" << num << endl;
	//对于set而言，count只有0和1，因为set没有重复的元素。
}


//set与multiset区别
void test_set_dis_multiset()
{
	/*
		set与multiset的区别：
		set不允许容器中有重复的元素
		multiset允许容器中有重复的元素
	*/
	multiset<int>ms;
	ms.insert(60);
	ms.insert(70);
	ms.insert(30);
	ms.insert(10);
	ms.insert(20);
	ms.insert(50);
	ms.insert(80);
	ms.insert(40);
	ms.insert(30);

	myprintmultiset(ms);//10 20 30 30 40 50 60 70 80

	set<int>s1;

	//插入-insert
	s1.insert(60);
	s1.insert(70);
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(80);
	s1.insert(40);
	s1.insert(30);

	myprintset(s1);//10 20 30 40 50 60 70 80

	//set在插入数据的时候会有个判断，重复的就失败，不重复的就成功
	//验证

	set<int>s2;
	pair<set<int>::iterator, bool> ret = s2.insert(10);//重点是bool类型的数值
	
	if (ret.second)
	{
		cout << "第一次插入成功，"<<endl;
	}
	else
	{
		cout << "第一次插入失败，" << endl;
	}

	//第二次插入s2.insert(10)
	ret = s2.insert(10);
	//判断
	if (ret.second)
	{
		cout << "第二次插入成功，" << endl;
	}
	else
	{
		cout << "第二次插入失败，" << endl;
	}


}


//set对组创建
void test_pair_srt()
{
	//方法1.创建对组
	pair<int, char>p1(3, 'A');
	cout << p1.first << " " << p1.second << endl;


	//方法2.创建对组
	pair<char, string>p2;
	p2 = make_pair('G', ",你好");
	cout << p2.first << " " << p2.second << endl;


}




//set排序
void test_sort_set()
{
	//set默认自动排序（升序）
	//利用仿函数，可以改变排序规则

	set<int>s1;

	//插入-insert
	s1.insert(60);
	s1.insert(70);
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(80);
	s1.insert(40);
	s1.insert(30);

	//默认升序
	myprintset(s1);

	set<int,Mycompare>s2;
	

	//插入-insert
	s2.insert(3);
	s2.insert(1);
	s2.insert(5);
	s2.insert(4);
	s2.insert(2);
	s2.insert(7);
	s2.insert(6);

	//让s2从大到小排序，需要用到仿函数
	//遍历s2
	for (set<int, Mycompare>::iterator it = s2.begin();it != s2.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//排序自定义类型，比如person类
	//创建person的容器
	set<Person,MycomparePerson>s;

	//创建Person对象赋值
	Person P1("刘备", 24);
	Person P2("关羽", 28);
	Person P3("张飞", 25);
	Person P4("赵云", 21);

	//容器插入数据
	s.insert(P1);
	s.insert(P2);
	s.insert(P3);
	s.insert(P4);
	
	//遍历数据
	for (set<Person,MycomparePerson>::iterator it = s.begin(); it !=s.end(); it++)
	{
		cout << "name:" << it->m_name << " age:" << it->m_age << endl;
	}


}


//set的自定义（person）排序
class people
{
public:
	people(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

class mypeopel_set
{
public:
	bool operator()(const people&p1,const people&p2) const
	{
		return p1.m_age < p2.m_age;
	}
};
void test_sort_Person_set()
{
	set<people,mypeopel_set>s1;
	
	//实例化people
	people p1("凯", 16);
	people p2("这是你", 15);
	people p3("李四", 19);
	people p4("王五", 25);
	people p5("张三", 20);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	s1.insert(p5);

	for (set<people, mypeopel_set>::iterator it = s1.begin();it != s1.end();it++)
	{
		cout <<"name:" << (*it).m_name << " age " << it->m_age << endl;
	}

}


