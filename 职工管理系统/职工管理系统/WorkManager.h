#pragma once//防止头文件重复
#include<iostream>
#include"Worker.h"
#include"boss.h"
#include"employee.h"
#include"Manager.h"
#include<fstream>


#define FILENAME "员工信息.txt"

//在WorkeManager的头文件中创造类
//在WorkeManager的源文件中写类的功能
class WorkManager
{
public:
	WorkManager();
	~WorkManager();
	//展示菜单
	void ShowMenu();
	//添加员工
	void Add_Emp();

	//保存文件
	void SaveFile();

	
	//读取员工数量
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示员工
	void Show_Emp();

	//检查员工是否存在
	int Is_Exist(int id);

	//删除职工
	void Del_Emp();

	//修改员工
	void Mod_Emp();
	
	//查找员工
	void Find_Emp();

	//按照编号排序
	void Sort_Emp();

	//退出系统
	void ExitSystem();

	//记入职工人数
	int m_EmpNum;
	//职工数组指针
	Worker** m_EmpArray=NULL;

	//判断文件是否为空
	bool m_FileIsEmpty;
private:

};
 