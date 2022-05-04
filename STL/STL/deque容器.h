#pragma once
#include<iostream>
#include<deque>
#include<algorithm>//算法头文件
using namespace std;

/*
	deque容器---双端数组可以对头端进行插入删除

	deque与vector的区别：
		1.vector对头部的插入删除效率低，数据越大，效率越低
		2.deque相对而言，对头部的插入删除比vector速度快
		3.vector访问速度比deque快，这与两者的内部实现有关

	deque 内部结构
		由一个中控器管理的一大块内存（缓冲区），通过中控器记录大内存（缓冲区）里数据的对应地址，来记录数据
		
	deque的构造函数

	deque的赋值

	deque大小操作

	deque insert and delete
		1.两端插入
		2.指定位置插入

	deque数据存取


*/


//deque的构造函数
void test_Structurn_deque();


//deque的赋值
void test_Assign_deque();

//deque大小操作
void test_Size_deque();

//deque insert and delete
void test_InsertAndDelete_deque();

//deque数据存取
void test_Access_deque();

// sort deque
void test_Sort_deque();