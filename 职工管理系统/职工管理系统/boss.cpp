#include<iostream>
#include"boss.h"
using namespace std;

//ʵ���ϰ���Ϣ
boss::boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptId = dId;
}

boss::~boss()
{
}
//չʾ�ϰ���Ϣ
void boss::showInfo()
{
	/*cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_name
		<< "\t��λ:" << this->getDepaName()
		<< "\t��λ��Ϣ������˾�������" << endl;*/
	cout << "ְ�����:" << this->m_Id 
		<< "\tְ������:" << this->m_name 
		<< "\t��λ:" << this->getDepaName()
		<< "\t��λ��Ϣ:����˾�������"  << endl;
	cout << "===================================================================================================" << endl;
}

string boss::getDepaName()
{
	return string("�ϰ�");
}
