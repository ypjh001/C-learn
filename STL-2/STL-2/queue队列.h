#pragma once
#include<iostream>
#include<string>	
#include<queue>//队列头文件

using namespace std;

/*
	queue队列--先进先出FIFO--有两个入口--只有队头、队尾能访问，所以也不能遍历
		队头：出数据
		队尾：进数据
		生活实例：滑梯、排队

*/

class Person
{
public:
	Person(string name,int age);
	~Person();

	string m_name;
	int m_age;
private:

};



void test_queue();