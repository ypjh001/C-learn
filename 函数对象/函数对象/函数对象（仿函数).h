#pragma once
#include<iostream>
using namespace std;

/*
	����������
		1.���غ������ò��������࣬����󳣳�Ϊ��������---operator����Ա
		2.��������ʹ�����صģ���ʱ����Ϊ���ƺ������ã�Ҳ�зº���

	���ʣ�
		�������󣨷º�������һ���࣬����һ������

	��������ʹ��
		1.����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ��
		2.�������󳬳���ͨ�����ĸ����������������Լ���״̬��--���Ե����Լ��ĳ�Ա
		3.�������������Ϊ�������ݡ�

*/

class MyAdd
{
public:

	//�º�������
	int operator()(int v1, int v2);
};

class Myprint
{
public:
	Myprint()
	{
		this ->count = 0;
	}

	void operator()(string text);

	int count;
};


void test_Add();

void test_print();