#pragma once//��ֹͷ�ļ��ظ�
#include<iostream>
#include"Worker.h"
#include"boss.h"
#include"employee.h"
#include"Manager.h"
#include<fstream>


#define FILENAME "Ա����Ϣ.txt"

//��WorkeManager��ͷ�ļ��д�����
//��WorkeManager��Դ�ļ���д��Ĺ���
class WorkManager
{
public:
	WorkManager();
	~WorkManager();
	//չʾ�˵�
	void ShowMenu();
	//���Ա��
	void Add_Emp();

	//�����ļ�
	void SaveFile();

	
	//��ȡԱ������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾԱ��
	void Show_Emp();

	//���Ա���Ƿ����
	int Is_Exist(int id);

	//ɾ��ְ��
	void Del_Emp();

	//�޸�Ա��
	void Mod_Emp();
	
	//����Ա��
	void Find_Emp();

	//���ձ������
	void Sort_Emp();

	//�˳�ϵͳ
	void ExitSystem();

	//����ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker** m_EmpArray=NULL;

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
private:

};
 