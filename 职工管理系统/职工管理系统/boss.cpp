#include<iostream>
#include"boss.h"
using namespace std;

//实现老板信息
boss::boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptId = dId;
}

boss::~boss()
{
}
//展示老板信息
void boss::showInfo()
{
	/*cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位:" << this->getDepaName()
		<< "\t岗位信息：管理公司所有事物。" << endl;*/
	cout << "职工编号:" << this->m_Id 
		<< "\t职工姓名:" << this->m_name 
		<< "\t岗位:" << this->getDepaName()
		<< "\t岗位信息:管理公司所有事物。"  << endl;
	cout << "===================================================================================================" << endl;
}

string boss::getDepaName()
{
	return string("老板");
}
