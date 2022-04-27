#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;
class boss:public Worker
{
public:
	//申明实现老板信息函数
	boss(int id, string name, int dId);
	~boss();
	//显示老板个人信息
	virtual void showInfo();

	//显示部门信息
	virtual string getDepaName();
private:

};

