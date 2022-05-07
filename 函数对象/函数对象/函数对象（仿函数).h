#pragma once
#include<iostream>
using namespace std;

/*
	函数对象概念：
		1.重载函数调用操作符的类，其对象常称为函数对象---operator操作员
		2.函数对象使用重载的（）时，行为类似函数调用，也叫仿函数

	本质：
		函数对象（仿函数）是一个类，不是一个函数

	函数对象使用
		1.函数对象在使用时，可以向普通函数那样调用，可以有参数，可以有返回值。
		2.函数对象超出普通函数的概念，函数对象可以有自己的状态。--可以调用自己的成员
		3.函数对象可以作为参数传递。

*/

class MyAdd
{
public:

	//仿函数声明
	int operator()(int v1, int v2);
};

class Myprint
{
public:
	Myprint()
	{
		this ->count = 0;
	}

	void operator()(string text);

	int count;
};


void test_Add();

void test_print();