#include<iostream>

#include"WorkManager.h"
#include"Worker.h"
#include"employee.h"
#include"boss.h"
#include"Manager.h"

using namespace std;
/*
	0.退出管理系统 
1.增加职工信息 
2.现实职工信息 
3.删除离职职工 
4.修改职工信息 
5.查找职工信息 
6.按照编号排序 
7.清空所有文档 

*/

void test_work()
{
	Worker* W1 = new Employee(1,"张三",5);
	W1->showInfo();
	Worker* W2 = new Employee(2, "李四",3);
	W2->showInfo();
	W2 = new Manager(3, "王经理", 7);
	W2->showInfo();
	W2 = new boss(3, "王老板", 7);
	W2->showInfo();
}


int main()
{
	WorkManager WM;
	int choise = 0;

	while (true)
	{
		WM.ShowMenu();
		cout << "输入选择：" << endl;
		cin >> choise;
		switch (choise)
		{
		case 0:		//退出管理系统 
			WM.ExitSystem();
			//cout << "退出系统" << endl;
			break;
		case 1:		//增加职工信息
			WM.Add_Emp();		
			break;
		case 2:		//显示职工信息 
			cout << "===================================================================================================" << endl;
			WM.Show_Emp();
			break;
		case 3:		//删除离职职工 
			WM.Del_Emp();
			break;
		case 4:		//查找职工信息
			WM.Mod_Emp();
			break;
		case 5:		//查找职工信息 
			WM.Find_Emp();
			break;
		case 6:		//按照编号排序 
			//暂时不能实现排序
			WM.Sort_Emp();
			break;
		case 7:		//清空所有文档
			//暂时没写。后期写
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}