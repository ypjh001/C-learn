#include<iostream>
#include"Vector.h"
#include "String����.h"
#include"deque����.h"
using namespace std;

/*
	STL:��׼ģ���

	�����Ϸ�Ϊ��
		1.������containner��
		2.�㷨��algorithm��
		3.��������iterator��

	�������㷨ͨ���������޷�����

	STL�������еĴ��붼����ģ�������ģ�庯��
	
	STL���������
		1.���� 2.�㷨 3.������ 4.�º��� 5.��������������� 6.�ռ�������

		1.�������������ݽṹ��vector  list���б�  deque��˫���У�  set������  map(ͼ) 
		2.�㷨�����ֳ��õ��㷨����sort  find  copy  for_each��
		3.�������������������㷨֮��Ľ��ϼ�
		4.�º�������Ϊ�����ں���������Ϊ�㷨��ĳ�ֲ���
		5.��������һ����������������������ӿڻ�º����Ķ���
		6.�ռ�������������ռ�ķ��������

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

	//test_Vct_nested_Vct();		//vector��Ƕ��

	//structure_vector();			//vector�Ĺ��캯��

	//test_assign_vector();			//vector�ĸ�ֵ����

	//test_volumeAndsize_vector();	//vector�����ʹ�С

	
	//test_InsertAndDelete();		//vector�Ĳ����ɾ�� insert and delete

	
	//test_AccessData_vector();	//vector���ݴ�ȡ--access

	 //test_Swap_vector();		//������������

	 //test_reserves_vector();	//vectorԤ���ռ�
}


void test_deque()
{

	 //test_Structurn_deque();	//deque�Ĺ��캯��

	//test_Assign_deque();		//deque�ĸ�ֵ

	 //test_Size_deque();		//deque��С����

	 //test_InsertAndDelete_deque();	//deque insert and delete

	
	 //test_Access_deque();		 //deque���ݴ�ȡ

	  test_Sort_deque();		//����sort
}

int main()
{
	//test_string();


	//test_vector();

	test_deque();

	return 0;
}