#pragma once
#include<iostream>
using namespace std;
#include<string>

/*
	String	������һ����
		char*��ָ��
		string���࣬���ڲ���װchar*,��������ַ�������һ��char*����
	
	�ص㣺
		string���װ�˺ܶ��Ա����
		���磺����find	����copy	ɾ��delete	����insert
		string����char*������Ŀռ䣬���õ��ĸ���Խ���ȡֵԽ��ȣ������ڲ�����

	string�Ĺ��캯����
		1.string;							//����һ���յ��ַ��� ���磺string str��
		2.string��const char* s��;			//ʹ���ַ���s��ʼ��
		3.string��const string& str��;		//ʹ��һ��string�����ʼ����һ��string����
		4.string��int n,char c��;			//ʹ��n���ַ�c��ʼ����
		

	string�ĸ�ֵ������
		1.string& operator=(const& char* s);			//char*�����ַ�����ֵ����ǰ���ַ���
		2.string& operator=��const string &s��;			//���ַ���s��ֵ����ǰ���ַ���
		3.string& operator=��char c��;					//�ַ���ֵ����ǰ���ַ���
		4.string& assign��const char *s��;				//���ַ���s��ֵ����ǰ���ַ���
		5.string& assign��const char *s,int n��;		//���ַ�����ǰn���ַ���ֵ����ǰ�ַ���
		6.string& assign��const string &s��;			//���ַ���s��ֵ����ǰ�ַ���
		7.string& assign(int n,char c);					//��n���ַ�c������ǰ�ַ���


	string�ַ���ƴ�ӣ�ʵ�����ַ���βƴ���ַ���
		1.string& operator+=(const char* str);				//����+=������
		2.string& operator+=(const char c);					//����+=������
		3.string& operator+=(const string& str);			//����+=������
		4.string& append(const char* s);					//�Ѳ�����s���ӵ���ǰ�ַ�����β��
		5.string& append(const char* s,int n);				//�Ѳ�����s��ǰn���ַ����ӵ���ǰ�ַ�����β��
		6.string& append(const string& s);					//ͬoperator+=��const string& str��
		7.string& append(const string& s,int pos,int n);	//�ַ���s�У��ӵ�pos��ʼ��n���ַ����ӵ��ַ���β��
		

	string�Ĳ��Һ��滻
		1.int find(const string& str ,int pos=0) const;			//����str��һ�γ��ֵ�λ�ã��ӵ�pos��ʼ����
		2.int find(const char* s ,int pos=0) const;				//����s��һ�γ��ֵ�λ�ã��ӵ�pos��ʼ����
		3.int find(const char* s ,int pos=0,int n) const;		//�ӵ�pos��ʼ����s��ǰn���ַ���һ�ε�λ��
		4.int find(const char c ,int pos=0) const;				//�����ַ�c��һ�γ��ֵ�λ��
		5.int rfind(const string& str ,int pos=npos) const;		//����str���һ�γ��ֵ�λ�ã���pos��ʼ����
		6.int rfind(const char* s ,int pos=npos) const;			//����s���һ�γ��ֵ�λ�ã���pos��ʼ����
		7.int rfind(const char* s,int pos,int n) const;			//��pos��ʼ����s��ǰn���ַ����һ��λ��
		8.int rfind(const char c ,int pos=0) const;				//�����ַ�c���һ�γ��ֵ�λ��,�ӵ�pos��ʼ����
		9.int replace(int pos,int n,const string& str);			//�滻��pos��ʼ��n���ַ�Ϊ�ַ���str
		10.int replace(int pos,int n,const char* s);			//�滻��pos��ʼ��n���ַ�Ϊ�ַ�s		


	string���ַ����Ƚ�
		�Ƚ��ǰ����ַ���ASCII����жԱ�
		 = ����0
		 > ����1
		 < ����-1


	string�ַ���ȡ
		1.char& operator[](int n)	//ͨ��[]��ʽȡ�ַ�
		2.char& ar(int n);			//ͨ��at������ȡ�ַ�


	string���롢ɾ��

	string�Ӵ�
		���ַ����н�ȡһС��

		
*/


//string���캯��
void test_learn_construction_String();

//�ַ�����ֵ
void test_learn_assignment_string();

//�ַ���ƴ��
void test_learn_link_string();

//�ַ������Һ��滻
void test_learn_findAndreplace_string();


//�ַ����Ƚ�
void test_compare_string();


//�ַ������ݷ���
void test_access_string();


//�ַ��������ɾ��
void test_insertAnddelete_string();

//�ַ����Ӵ�
void test_subStr();
