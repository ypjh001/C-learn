#pragma once
#include<iomanip>//����ı�����ͷ�ļ�
#include<iostream>
#include<string>
using namespace std;
//��˾Ա��������Ϣ
class Worker
{
public:
	Worker();
	~Worker();
	//��ʾԱ��������Ϣ
	virtual void showInfo() = 0;

	//��ʾ������Ϣ
	virtual string getDepaName() = 0;

	//ְ�����
	int m_Id = 0;//��ʼ��m_Id
	//ְ������
	string m_name;
	//���ű�� 
	int m_DeptId = 0;//��ʼ��m_DeptId


private:

};

