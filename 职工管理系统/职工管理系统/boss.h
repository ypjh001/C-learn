#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;
class boss:public Worker
{
public:
	//����ʵ���ϰ���Ϣ����
	boss(int id, string name, int dId);
	~boss();
	//��ʾ�ϰ������Ϣ
	virtual void showInfo();

	//��ʾ������Ϣ
	virtual string getDepaName();
private:

};

