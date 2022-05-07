#pragma once
#include<iostream>
#include<functional>//�ڽ���������ͷ�ļ�
using namespace std;
/*
	�ڽ���������STL�ڲ�����һЩ��������

	���ࣺ
		1.�����º���
		2.��ϵ�º���
		3.�߼��º���

	�÷���
		1.ʹ��ʱҪ����ͷ�ļ�functional
		2.�÷�����ͨ�������

	1.�����º���
		a.negate	һԪ�º���  ������ȡ���º���
		b.plus		��Ԫ�º���	�������ӷ�

	2.��ϵ�º���
		a.����������

	3.�߼��º���
		a.��
		b.��
		c.��

*/

//ȡ��
void test_negage()
{
	//negate ȡ�����෴
	negate<>n;
	cout << n(50) << endl;
}

//�ӷ�
void test_plus()
{
	plus<int>add;

	cout << add(5, 3)<<endl;
}

//����

class Mycompaer
{
public:
	bool operator()(int a, int b) const
	{
		return a > b;
	}
};

void test_great()
{
	vector<int>v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	//��ӡ
	for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
	{
		cout << *it << " ";
	}//0 1 2 3 4 5 6 7 8 9
	cout << endl;
	//����
	//sort(v1.begin(), v1.end(), Mycompare());//Mycompare�ǳ���Աд�Ĵ��ڷº���
	sort(v1.begin(), v1.end(),greater<int>());//greater<>��ϵͳ�ṩ�Ĵ��ڷº���

	for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
	{
		cout << *it << " ";
	}//9 8 7 6 5 4 3 2 1 0
	cout << endl;
}


//�߼�
void test_logic()
{
	vector<bool>v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);

	//����
	for (vector<bool>::iterator it = v1.begin(); it < v1.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	//v����2����v1����ȡ��
	vector<bool>v2;
	v2.resize(v1.size());
	//transfrom:���˺���
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it < v2.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}