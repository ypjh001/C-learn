#pragma once
//普通员工类
#include<iostream>
#include"Worker.h"
using namespace std;

class Employee:public Worker
{
public:
	Employee(int id, string name, int dId);
	~Employee();
	//显示员工个人信息
	virtual void showInfo() ;

	//显示部门信息
	virtual string getDepaName() ;
private:

};


