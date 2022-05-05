#pragma once
#include<iostream>
#include<list>
using namespace std;

/*
	list链表：物理存储上是非连续性的，数据元素的逻辑顺序是通过链表中的指针链接实现的

	链表由节点构成--生活实例：狗链、伸缩梯子
		节点：
			1.数据域--数据元素、值
			2.指针域--维护下一个数据域的地址
	链表
		优点：可以快速的对任意的位置插入删除数据，动态分配，不会造成资源浪费
		缺点：容器遍历速度慢，没有数组快，而且暂用空间大，时间大

	STL中的链表是双向循环链表
		即一个节点有存有两个指针，一个指向该节点前的数据域地址，一个指向该节点后的数据域地址，链表首尾的适用--即循环一个圈

	list与vector是两个最常用的容器


*/


//list函数构造
void test_structurn_list();

//list赋值和交换
void test_AssignAndSwap_list();

//list容器大小操作
void test_sizeof_list();

//list插入、删除
void test_InsertAnddelete_list();

//list数据存取
void test_Access_list();

//list反转和排序
void test_ReverseAndSort_list();

//排序案例
void test_apply_list();

class person
{
public:
	person(string name,int age,int height);
	~person();

	string m_name;
	int m_age;
	int m_height;
private:

};

