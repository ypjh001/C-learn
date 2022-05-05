#include<iostream>
#include"stack栈.h"
#include"queue队列.h"
#include"list链表.h"
#include"set容器.h"
#include"map个multimap容器.h"


using namespace std;

void test_Stack()
{
	test_stack();

}

void test_Queue()
{

	 test_queue();

}

void test_List()
{

	 //test_structurn_list();		//构造list容器

	 //test_AssignAndSwap_list();	//赋值和交换

	 //test_sizeof_list();		//大小操作

	
	  //test_InsertAnddelete_list();	 //list插入、删除

	 
	   //test_Access_list();		 //list数据存取

	  
	   //test_ReverseAndSort_list();	 //list反转和排序

	   test_apply_list();	//list实例运用
}

void test_Set()
{

	
	//structurn_set();	//set的构造	

	//tset_SizeAndSwap_set();//set的大小和交换

	
	 //test_InsertAndDelete_set();	//set的插入和删除

	
	//test_FindAndCount_set();	 //set查找和统计

	//test_set_dis_multiset();//set与multiset的区别

	//test_pair_srt();//pair对组创建

	//test_sort_set();		//set排序

	//test_sort_Person_set();
}

void test_Map()
{
	//test_structurn_map();//构造map

	//tset_SizeAndSwap_map();	//大小和交换

	test_InsertAndDelete_map();
}



int main()
{
	//test_Stack();

	//test_Queue();

	//test_List();

	//test_Set();

	//test_Map();

	

	//cout << "调试！";

	return 0;
}