#include "map个multimap容器.h"


//打印map
void myprintmap(const map<int, int>& m)
{
	if (m.empty())
	{
		cout << "map为空";
	}
	else
	{
		//遍历map
		for (map<int,int>::const_iterator it=m.begin();it!=m.end(); it++)
		{
			cout << "key:" << it->first << " value:" << it->second << "|==间隔==| ";
		}
	}
	cout << endl;
}

//map构造
void test_structurn_map()
{
	//构造map容器
	map<int, int>m1;
	//插入数值--要使用对组
	m1.insert(pair<int, int>(1, 10));//1是key；10是value
	m1.insert(pair<int, int>(3, 12));
	m1.insert(pair<int, int>(5, 14));
	m1.insert(pair<int, int>(2, 11));
	myprintmap(m1);//key:1 value:10|==间隔==| key:2 value:11|==间隔==| key:3 value:12|==间隔==| key:5 value:14|==间隔==|
	//打印出来按key顺序

	//利用拷贝构造
	map<int, int>m2(m1);
	myprintmap(m2);//key:1 value:10|==间隔==| key:2 value:11|==间隔==| key:3 value:12|==间隔==| key:5 value:14|==间隔==|

	//赋值构造
	map<int, int>m3=m2;
	myprintmap(m3);//key:1 value:10|==间隔==| key:2 value:11|==间隔==| key:3 value:12|==间隔==| key:5 value:14|==间隔==|
}


//大小和交换
void tset_SizeAndSwap_map()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));//1是key；10是value
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	myprintmap(m1);
	map<int, int>m2;
	m2.insert(pair<int, int>(6, 60));
	m2.insert(pair<int, int>(2, 20));
	m2.insert(pair<int, int>(1, 10));
	myprintmap(m2);
	//大小
	cout <<"交换前m1大小：" << m1.size()<<endl;
	cout << "交换前m2大小：" << m2.size()<<endl;
	
	//交换
	swap(m1, m2);
	cout << "交换后m1大小：" << m1.size() << endl;
	cout << "交换后m2大小：" << m2.size() << endl;
	myprintmap(m1);
	myprintmap(m2);
}


//map的插入和删除
void test_InsertAndDelete_map()
{
	map<int, int>m1;

	//1.插入
	m1.insert(pair<int, int>(1, 10));

	//2.插入
	m1.insert(make_pair(2, 20));

	//3.插入
	m1.insert(map<int, int>::value_type(3, 10));
	myprintmap(m1);//key:1 value:10|==间隔==| key:2 value:20|==间隔==| key:3 value:10|==间隔==|

	//4.插入
	m1[4] = 40;//在第4个位置插入40---不建议使用这种方式插入
	map<int, int>m2(m1);

	//1.删除
	m1.erase(m1.begin());
	myprintmap(m1);//key:2 value:20|==间隔==| key:3 value:10|==间隔==| key:4 value:40|==间隔==|

	//2.删除
	m1.erase(3);//按照key删除
	myprintmap(m1);//key:2 value:20|==间隔==| key:4 value:40|==间隔==|

	//3.删除（清空）
	myprintmap(m2);//key:1 value:10|==间隔==| key:2 value:20|==间隔==| key:3 value:10|==间隔==| key:4 value:40|==间隔==|
	m2.clear();//or m2.erase(m2.begin(),m2.end())
	myprintmap(m2);//map为空
}

 


