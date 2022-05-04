#pragma once
#include<iostream>
//Vector的头文件
#include<vector>
#include<string>
using namespace std;


/*
	Voctor:
		容器：Vector
		算法：for_each
		迭代器：vector<int>::itreator			(iterator:迭代器)

	类似数组,也成单端数组

	vector与数组却别
		数组是静态空间
		vector可以动态扩展
			
	vector的赋值操作

	vector容量和大小

	vector的插入和删除 insert and delete

	vector预留空间


*/

void leran_Vector();

//先声明函数test_custom_vector()
void test_custom_Person_vector();
//声明Person类
class Person
{
public:
	Person(string name,int age);
	~Person();
	string m_name;
	int m_age;
private:
};

//vector的嵌套
void test_Vct_nested_Vct();

//vector的构造函数
void structure_vector();

//vector的赋值操作
void test_assign_vector();

//vector容量和大小
void test_volumeAndsize_vector();

//vector的插入和删除 insert and delete
void test_InsertAndDelete();

//vector数据存取--access
void test_AccessData_vector();

//容器互换容器
void test_Swap_vector();

//vector预留空间
void test_reserves_vector();