#pragma once
#include<iostream>
#include<string>
#include<set>
#include<typeinfo>

#include"queue队列.h"//用到queue头文件里的person类

using namespace std;
/*
	set/multiset容器：所以元素在插入时自动排序

	set与multiset属于关联式容器，底层结构是二叉树

	set与multiset的区别：
		set不允许容器中有重复的元素
		multiset允许容器中有重复的元素

*/


//set的构造
void structurn_set();

//set的大小和交换
void tset_SizeAndSwap_set();

//set的插入和删除
void test_InsertAndDelete_set();

//set查找和统计
void test_FindAndCount_set();

//set与multiset区别
void test_set_dis_multiset();

//set对组创建
void test_pair_srt();

//set排序
void test_sort_set();

//仿函数类
class Mycompare
{
public:
	bool operator()(int a, int b) const //用const来修饰Mycompare,j解决这个问题->严重性	C3848	具有类型“const Mycompare”的表达式会丢失一些 const - volatile 限定符以调用“bool Mycompare::operator ()(int, int)”	
	{
		return a > b;
	}
};

class MycomparePerson
{
public:
	bool operator()(const Person&p1,const Person&p2) const	//要比较什么值就传进来什么值，在此比较的是person类型里的成员m_age
	{
		return p1.m_age > p2.m_age;
	}
};


//set的自定义（person）排序
void test_sort_Person_set();