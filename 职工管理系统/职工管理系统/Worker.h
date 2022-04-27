#pragma once
#include<iomanip>//输出文本对齐头文件
#include<iostream>
#include<string>
using namespace std;
//公司员工公共信息
class Worker
{
public:
	Worker();
	~Worker();
	//显示员工个人信息
	virtual void showInfo() = 0;

	//显示部门信息
	virtual string getDepaName() = 0;

	//职工编号
	int m_Id = 0;//初始化m_Id
	//职工姓名
	string m_name;
	//部门编号 
	int m_DeptId = 0;//初始化m_DeptId


private:

};

