#pragma once
#include<iostream>
#include<deque>
#include<algorithm>//�㷨ͷ�ļ�
using namespace std;

/*
	deque����---˫��������Զ�ͷ�˽��в���ɾ��

	deque��vector������
		1.vector��ͷ���Ĳ���ɾ��Ч�ʵͣ�����Խ��Ч��Խ��
		2.deque��Զ��ԣ���ͷ���Ĳ���ɾ����vector�ٶȿ�
		3.vector�����ٶȱ�deque�죬�������ߵ��ڲ�ʵ���й�

	deque �ڲ��ṹ
		��һ���п��������һ����ڴ棨����������ͨ���п�����¼���ڴ棨�������������ݵĶ�Ӧ��ַ������¼����
		
	deque�Ĺ��캯��

	deque�ĸ�ֵ

	deque��С����

	deque insert and delete
		1.���˲���
		2.ָ��λ�ò���

	deque���ݴ�ȡ


*/


//deque�Ĺ��캯��
void test_Structurn_deque();


//deque�ĸ�ֵ
void test_Assign_deque();

//deque��С����
void test_Size_deque();

//deque insert and delete
void test_InsertAndDelete_deque();

//deque���ݴ�ȡ
void test_Access_deque();

// sort deque
void test_Sort_deque();