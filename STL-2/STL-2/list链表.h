#pragma once
#include<iostream>
#include<list>
using namespace std;

/*
	list��������洢���Ƿ������Եģ�����Ԫ�ص��߼�˳����ͨ�������е�ָ������ʵ�ֵ�

	�����ɽڵ㹹��--����ʵ������������������
		�ڵ㣺
			1.������--����Ԫ�ء�ֵ
			2.ָ����--ά����һ��������ĵ�ַ
	����
		�ŵ㣺���Կ��ٵĶ������λ�ò���ɾ�����ݣ���̬���䣬���������Դ�˷�
		ȱ�㣺���������ٶ�����û������죬�������ÿռ��ʱ���

	STL�е�������˫��ѭ������
		��һ���ڵ��д�������ָ�룬һ��ָ��ýڵ�ǰ���������ַ��һ��ָ��ýڵ����������ַ��������β������--��ѭ��һ��Ȧ

	list��vector��������õ�����


*/


//list��������
void test_structurn_list();

//list��ֵ�ͽ���
void test_AssignAndSwap_list();

//list������С����
void test_sizeof_list();

//list���롢ɾ��
void test_InsertAnddelete_list();

//list���ݴ�ȡ
void test_Access_list();

//list��ת������
void test_ReverseAndSort_list();

//������
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

