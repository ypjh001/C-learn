#pragma once
#include<iostream>
#include<string>
#include<set>
#include<typeinfo>

#include"queue����.h"//�õ�queueͷ�ļ����person��

using namespace std;
/*
	set/multiset����������Ԫ���ڲ���ʱ�Զ�����

	set��multiset���ڹ���ʽ�������ײ�ṹ�Ƕ�����

	set��multiset������
		set���������������ظ���Ԫ��
		multiset�������������ظ���Ԫ��

*/


//set�Ĺ���
void structurn_set();

//set�Ĵ�С�ͽ���
void tset_SizeAndSwap_set();

//set�Ĳ����ɾ��
void test_InsertAndDelete_set();

//set���Һ�ͳ��
void test_FindAndCount_set();

//set��multiset����
void test_set_dis_multiset();

//set���鴴��
void test_pair_srt();

//set����
void test_sort_set();

//�º�����
class Mycompare
{
public:
	bool operator()(int a, int b) const //��const������Mycompare,j����������->������	C3848	�������͡�const Mycompare���ı��ʽ�ᶪʧһЩ const - volatile �޶����Ե��á�bool Mycompare::operator ()(int, int)��	
	{
		return a > b;
	}
};

class MycomparePerson
{
public:
	bool operator()(const Person&p1,const Person&p2) const	//Ҫ�Ƚ�ʲôֵ�ʹ�����ʲôֵ���ڴ˱Ƚϵ���person������ĳ�Աm_age
	{
		return p1.m_age > p2.m_age;
	}
};


//set���Զ��壨person������
void test_sort_Person_set();