#include<iostream>

#include"WorkManager.h"
#include"Worker.h"
#include"employee.h"
#include"boss.h"
#include"Manager.h"

using namespace std;
/*
	0.�˳�����ϵͳ 
1.����ְ����Ϣ 
2.��ʵְ����Ϣ 
3.ɾ����ְְ�� 
4.�޸�ְ����Ϣ 
5.����ְ����Ϣ 
6.���ձ������ 
7.��������ĵ� 

*/

void test_work()
{
	Worker* W1 = new Employee(1,"����",5);
	W1->showInfo();
	Worker* W2 = new Employee(2, "����",3);
	W2->showInfo();
	W2 = new Manager(3, "������", 7);
	W2->showInfo();
	W2 = new boss(3, "���ϰ�", 7);
	W2->showInfo();
}


int main()
{
	WorkManager WM;
	int choise = 0;

	while (true)
	{
		WM.ShowMenu();
		cout << "����ѡ��" << endl;
		cin >> choise;
		switch (choise)
		{
		case 0:		//�˳�����ϵͳ 
			WM.ExitSystem();
			//cout << "�˳�ϵͳ" << endl;
			break;
		case 1:		//����ְ����Ϣ
			WM.Add_Emp();		
			break;
		case 2:		//��ʾְ����Ϣ 
			cout << "===================================================================================================" << endl;
			WM.Show_Emp();
			break;
		case 3:		//ɾ����ְְ�� 
			WM.Del_Emp();
			break;
		case 4:		//����ְ����Ϣ
			WM.Mod_Emp();
			break;
		case 5:		//����ְ����Ϣ 
			WM.Find_Emp();
			break;
		case 6:		//���ձ������ 
			//��ʱ����ʵ������
			WM.Sort_Emp();
			break;
		case 7:		//��������ĵ�
			//��ʱûд������д
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}