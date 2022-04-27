#include "employee.h"

Employee::Employee(int id,string name,int dId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptId = dId;
}

Employee::~Employee()
{
}

 void Employee::showInfo()
{
	 /*cout << "职工编号：" << this->m_Id<< setw(10)
		 << "\t职工姓名：" <<this->m_name << setw(10)
		 << "\t岗位:" << this->getDepaName()
		 << "\t岗位信息：完成经理交给的任务" << endl;*/
	 cout << "职工编号:" << this->m_Id
		 << "\t职工姓名:" << this->m_name
		 << "\t岗位:" << this->getDepaName() 
		 << "\t岗位信息:完成经理交给的任务。" << endl;
	 cout << "==================================================================================================="<<endl;
}

string Employee::getDepaName()
{
	 return string("员工");
}