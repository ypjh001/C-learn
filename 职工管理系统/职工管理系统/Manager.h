#pragma once
#include<iostream>
#include"Worker.h"

using namespace std;

class Manager:public Worker
{
public:
	Manager(int id, string name, int dId);
	~Manager();
	//显示经理个人信息
	virtual void showInfo();

	//显示部门信息
	virtual string getDepaName();
private:

};

