#pragma once
#include<iostream>
#include"Worker.h"

using namespace std;

class Manager:public Worker
{
public:
	Manager(int id, string name, int dId);
	~Manager();
	//��ʾ���������Ϣ
	virtual void showInfo();

	//��ʾ������Ϣ
	virtual string getDepaName();
private:

};

