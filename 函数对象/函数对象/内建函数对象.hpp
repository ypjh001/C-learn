#pragma once
#include<iostream>
#include<functional>//内建函数对象头文件
using namespace std;
/*
	内建函数对象：STL内部建了一些函数对象

	分类：
		1.算术仿函数
		2.关系仿函数
		3.逻辑仿函数

	用法：
		1.使用时要包含头文件functional
		2.用法与普通函数差不多

	1.算术仿函数
		a.negate	一元仿函数  举例：取反仿函数
		b.plus		二元仿函数	举例：加法

	2.关系仿函数
		a.举例：大于

	3.逻辑仿函数
		a.与
		b.或
		c.非

*/

//取反
void test_negage()
{
	//negate 取反、相反
	negate<>n;
	cout << n(50) << endl;
}

//加法
void test_plus()
{
	plus<int>add;

	cout << add(5, 3)<<endl;
}

//大于

class Mycompaer
{
public:
	bool operator()(int a, int b) const
	{
		return a > b;
	}
};

void test_great()
{
	vector<int>v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	//打印
	for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
	{
		cout << *it << " ";
	}//0 1 2 3 4 5 6 7 8 9
	cout << endl;
	//降序
	//sort(v1.begin(), v1.end(), Mycompare());//Mycompare是程序员写的大于仿函数
	sort(v1.begin(), v1.end(),greater<int>());//greater<>是系统提供的大于仿函数

	for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
	{
		cout << *it << " ";
	}//9 8 7 6 5 4 3 2 1 0
	cout << endl;
}


//逻辑
void test_logic()
{
	vector<bool>v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);

	//遍历
	for (vector<bool>::iterator it = v1.begin(); it < v1.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	//v容器2搬运v1并且取非
	vector<bool>v2;
	v2.resize(v1.size());
	//transfrom:搬运函数
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it < v2.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}