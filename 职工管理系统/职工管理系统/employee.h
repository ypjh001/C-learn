#pragma once
//��ͨԱ����
#include<iostream>
#include"Worker.h"
using namespace std;

class Employee:public Worker
{
public:
	Employee(int id, string name, int dId);
	~Employee();
	//��ʾԱ��������Ϣ
	virtual void showInfo() ;

	//��ʾ������Ϣ
	virtual string getDepaName() ;
private:

};


