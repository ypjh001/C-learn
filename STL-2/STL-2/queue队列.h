#pragma once
#include<iostream>
#include<string>	
#include<queue>//����ͷ�ļ�

using namespace std;

/*
	queue����--�Ƚ��ȳ�FIFO--���������--ֻ�ж�ͷ����β�ܷ��ʣ�����Ҳ���ܱ���
		��ͷ��������
		��β��������
		����ʵ�������ݡ��Ŷ�

*/

class Person
{
public:
	Person(string name,int age);
	~Person();

	string m_name;
	int m_age;
private:

};



void test_queue();