#include<iostream>
#include"Vector.h"
#include "String容器.h"
#include"deque容器.h"
using namespace std;

/*
	STL:标准模板库

	广义上分为：
		1.容器（containner）
		2.算法（algorithm）
		3.迭代器（iterator）

	容器和算法通过迭代器无缝连接

	STL几乎所有的代码都采用模板类或者模板函数
	
	STL六大组件：
		1.容器 2.算法 3.迭代器 4.仿函数 5.适配器（配接器） 6.空间配置器

		1.容器：各种数据结构，vector  list（列表）  deque（双队列）  set（树）  map(图) 
		2.算法：各种常用的算法：入sort  find  copy  for_each等
		3.迭代器：扮演容器和算法之间的胶合剂
		4.仿函数：行为类似于函数，可作为算法的某种策略
		5.适配器：一种用来修饰容器或迭代器接口或仿函数的东西
		6.空间配置器：负责空间的分配与管理

*/	

void test_string()
{
	//test_learn_construction_String();

	 //test_learn_assignment_string();


	// test_learn_link_string();

	 //test_learn_findAndreplace_string();

	//test_compare_string();

	//test_access_string();

	//test_insertAnddelete_string();

	test_subStr();

}

void test_vector()
{
	leran_Vector();

	//test_custom_Person_vector();

	//test_Vct_nested_Vct();		//vector的嵌套

	//structure_vector();			//vector的构造函数

	//test_assign_vector();			//vector的赋值操作

	//test_volumeAndsize_vector();	//vector容量和大小

	
	//test_InsertAndDelete();		//vector的插入和删除 insert and delete

	
	//test_AccessData_vector();	//vector数据存取--access

	 //test_Swap_vector();		//容器互换容器

	 //test_reserves_vector();	//vector预留空间
}


void test_deque()
{

	 //test_Structurn_deque();	//deque的构造函数

	//test_Assign_deque();		//deque的赋值

	 //test_Size_deque();		//deque大小操作

	 //test_InsertAndDelete_deque();	//deque insert and delete

	
	 //test_Access_deque();		 //deque数据存取

	  test_Sort_deque();		//排序sort
}

int main()
{
	//test_string();


	//test_vector();

	test_deque();

	return 0;
}