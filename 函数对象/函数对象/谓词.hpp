#pragma once
#include<iostream>
#include<vector>

#include<algorithm>


using namespace std;

/*
	ν�ʣ�
		1.����bool���͵ķº�����Ϊν��
		2.���operator() ����һ����������ô��һԪν��
		3.���operator() ����������������ô�ж�Ԫν��

*/


//һԪν��
class GreaterFive
{
public:
	bool operator()(int n) const
	{
		return n > 5;
	}
};



void test_one_pridicate()//pridicateν��
{
	vector<int>v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//���������д���5��λ��
	//pred ��ν�ʵ���˼
	//GreaterFive()��һ�������ĺ�������
	vector<int>::iterator it= find_if(v1.begin(), v1.end(), GreaterFive());//find.if()����һ��������
	if (it==v1.end())
	{
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << *it << endl;
	}
}




//��Ԫν��
class Mycompare
{
public:
	bool operator()(int a, int b) const
	{
		return a > b;
	}
};
void test_tow_pridicate()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(50);
	sort(v1.begin(), v1.end());//sort����
	//��ӡv1
	for (vector<int>::iterator  it = v1.begin()	; it !=v1.end(); it++)
	{
		cout << *it << " ";
	}//10 20 30 40 50 60 70
	cout << endl;
	//�Ӵ�С����
	sort(v1.begin(), v1.end(),Mycompare() );//Ҫ����һ���º�����ʵ�ִ�->С����
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}//70 60 50 40 30 20 10


	//sort���������غ���

}