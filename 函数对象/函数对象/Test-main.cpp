#include<iostream>
#include"�������󣨷º���).h"
#include"ν��.hpp"
#include"�ڽ���������.hpp"
#include"�����㷨.hpp"

using namespace std;

void test_imit_func()
{

	 //test_Add();

	  test_print();
}

void test_predicate()
{
	//test_one_pridicate();

	test_tow_pridicate();
}

void test_intofunc()
{
	test_negage();//����ȡ��

	test_plus();//���Լӷ�

	test_great();//���Դ���

	test_logic();//�����߼�
}


void test_common_algorithm()
{
	//test_for_each();//���Ա���

	//test_transfrom();//���԰���

	//===========================����====================
	 //test_find();//���Բ���

	 //test_find_if();//������������
	
	 //test_adjacent_find();//���Բ�������ͬԪ��

	 //test_binary_seach();//���Զ��ֲ���

	 //test_count();	//ͳ�Ƹ���

	 //test_count_if();	//ͳ�����������ĸ���

	//===========================����====================
	 //test_sort();//����sort

	 //test_random_shufle();//ϴ�ƣ�����random_shuffle

	 //test_merge();//�ϲ�����1������2��������3��

	 //test_reverse();//��ת

	//===========================����====================

	//test_copy();//����--ָ����Χ��������һ��������

	//test_replace();//��������ָ����Χ��Ԫ���޸�Ϊ��Ԫ��

	//test_replace_if();//������ָ����Χ������������Ԫ�ػ�Ϊ��Ԫ��

	//test_swap();	//swap������������

	//==================�������������㷨================== 
	
	//test_accumulate();//��������Ԫ���ۼ��ܺ�

	//test_fill();//�����������Ԫ��

	//==================���úϼ��㷨================== 

	//test_set_intersection();//�����������Ľ���

	//test_set_union();	//�����������Ĳ���

	test_set_difference();//�����������Ĳ
}


int main()
{
	//test_imit_func();


	//test_predicate();


	
	//test_intofunc();

	test_common_algorithm();

	
}