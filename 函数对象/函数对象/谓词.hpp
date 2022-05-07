#pragma once
#include<iostream>
#include<vector>

#include<algorithm>


using namespace std;

/*
	谓词：
		1.返回bool类型的仿函数成为谓词
		2.如果operator() 接受一个参数，那么叫一元谓词
		3.如果operator() 接受两个参数，那么叫二元谓词

*/


//一元谓词
class GreaterFive
{
public:
	bool operator()(int n) const
	{
		return n > 5;
	}
};



void test_one_pridicate()//pridicate谓词
{
	vector<int>v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//查找容器中大于5的位置
	//pred 是谓词的意思
	//GreaterFive()是一个匿名的函数对象
	vector<int>::iterator it= find_if(v1.begin(), v1.end(), GreaterFive());//find.if()返回一个迭代器
	if (it==v1.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了" << *it << endl;
	}
}




//二元谓词
class Mycompare
{
public:
	bool operator()(int a, int b) const
	{
		return a > b;
	}
};
void test_tow_pridicate()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(50);
	sort(v1.begin(), v1.end());//sort排序
	//打印v1
	for (vector<int>::iterator  it = v1.begin()	; it !=v1.end(); it++)
	{
		cout << *it << " ";
	}//10 20 30 40 50 60 70
	cout << endl;
	//从大到小排序
	sort(v1.begin(), v1.end(),Mycompare() );//要构造一个仿函数来实现大->小排序
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}//70 60 50 40 30 20 10


	//sort有两个重载函数

}