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
	cout << "ְ�����:" <<this->m_Id 
		<< "\tְ������:" <<this->m_name 
		<< "\t��λ:" <<this->getDepaName()
		<< "\t��λ��Ϣ:����ϰ彻�������񣬲��·�����" << endl;
	cout << "===================================================================================================" << endl;
}

string Manager::getDepaName()
{
	return string("����");
}
