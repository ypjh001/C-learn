#pragma once
#include<iostream>
//Vector��ͷ�ļ�
#include<vector>
#include<string>
using namespace std;


/*
	Voctor:
		������Vector
		�㷨��for_each
		��������vector<int>::itreator			(iterator:������)

	��������,Ҳ�ɵ�������

	vector������ȴ��
		�����Ǿ�̬�ռ�
		vector���Զ�̬��չ
			
	vector�ĸ�ֵ����

	vector�����ʹ�С

	vector�Ĳ����ɾ�� insert and delete

	vectorԤ���ռ�


*/

void leran_Vector();

//����������test_custom_vector()
void test_custom_Person_vector();
//����Person��
class Person
{
public:
	Person(string name,int age);
	~Person();
	string m_name;
	int m_age;
private:
};

//vector��Ƕ��
void test_Vct_nested_Vct();

//vector�Ĺ��캯��
void structure_vector();

//vector�ĸ�ֵ����
void test_assign_vector();

//vector�����ʹ�С
void test_volumeAndsize_vector();

//vector�Ĳ����ɾ�� insert and delete
void test_InsertAndDelete();

//vector���ݴ�ȡ--access
void test_AccessData_vector();

//������������
void test_Swap_vector();

//vectorԤ���ռ�
void test_reserves_vector();