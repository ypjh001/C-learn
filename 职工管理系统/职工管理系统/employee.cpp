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
	 /*cout << "ְ����ţ�" << this->m_Id<< setw(10)
		 << "\tְ��������" <<this->m_name << setw(10)
		 << "\t��λ:" << this->getDepaName()
		 << "\t��λ��Ϣ����ɾ�����������" << endl;*/
	 cout << "ְ�����:" << this->m_Id
		 << "\tְ������:" << this->m_name
		 << "\t��λ:" << this->getDepaName() 
		 << "\t��λ��Ϣ:��ɾ�����������" << endl;
	 cout << "==================================================================================================="<<endl;
}

string Employee::getDepaName()
{
	 return string("Ա��");
}