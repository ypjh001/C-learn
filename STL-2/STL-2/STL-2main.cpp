#include<iostream>
#include"stackջ.h"
#include"queue����.h"
#include"list����.h"
#include"set����.h"
#include"map��multimap����.h"


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

	 //test_structurn_list();		//����list����

	 //test_AssignAndSwap_list();	//��ֵ�ͽ���

	 //test_sizeof_list();		//��С����

	
	  //test_InsertAnddelete_list();	 //list���롢ɾ��

	 
	   //test_Access_list();		 //list���ݴ�ȡ

	  
	   //test_ReverseAndSort_list();	 //list��ת������

	   test_apply_list();	//listʵ������
}

void test_Set()
{

	
	//structurn_set();	//set�Ĺ���	

	//tset_SizeAndSwap_set();//set�Ĵ�С�ͽ���

	
	 //test_InsertAndDelete_set();	//set�Ĳ����ɾ��

	
	//test_FindAndCount_set();	 //set���Һ�ͳ��

	//test_set_dis_multiset();//set��multiset������

	//test_pair_srt();//pair���鴴��

	//test_sort_set();		//set����

	//test_sort_Person_set();
}

void test_Map()
{
	//test_structurn_map();//����map

	//tset_SizeAndSwap_map();	//��С�ͽ���

	test_InsertAndDelete_map();
}



int main()
{
	//test_Stack();

	//test_Queue();

	//test_List();

	//test_Set();

	//test_Map();

	

	//cout << "���ԣ�";

	return 0;
}