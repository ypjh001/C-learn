#include<iostream>
#include<iomanip>
#include"Manager.h"
Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptId = dId;
}

Manager::~Manager()
{
}

void Manager::showInfo()
{
	cout << "职工编号:" <<this->m_Id 
		<< "\t职工姓名:" <<this->m_name 
		<< "\t岗位:" <<this->getDepaName()
		<< "\t岗位信息:完成老板交给的任务，并下发任务。" << endl;
	cout << "===================================================================================================" << endl;
}

string Manager::getDepaName()
{
	return string("经理");
}
