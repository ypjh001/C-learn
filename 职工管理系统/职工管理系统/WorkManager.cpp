#include<iostream>
#include "WorkManager.h"

using namespace std;


//员工管理员构造函数
WorkManager::WorkManager()
{
	//1.判断文件是否存在：
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//打开文件方式--读文件
	if (!ifs.is_open())//成功打开返回1，打开失败返回0
	{
		cout << "文件打开失败" << endl;
		//初始化属性
		//初始化计数人数：
		this->m_EmpNum = 0;
		//初始化数组指针：
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在，但数据空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空" << endl;
		//初始化属性
		//初始化计数人数：
		this->m_EmpNum = 0;
		//初始化数组指针：
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//当文件存在，并且记录数据
	int num = this->get_EmpNum();
	//cout << "职工人数为" << num << "人" << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];

	//将文件中的数据，保存到数组中
	this->init_Emp();

	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号：" << this->m_EmpArray[i]->m_Id
			<< "\t姓名：" << this->m_EmpArray[i]->m_name
			<< "\t部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}


//员工管理员析构函数
WorkManager::~WorkManager()
{
	//释放空间
	if (this->m_EmpArray!=NULL)
	{
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
		
	}
}
//展示菜单
void WorkManager::ShowMenu()
{
	cout << "*************************************" << endl;
	cout << "*******  欢迎使用职工管理系统! ******" << endl;
	cout << "**********  0.退出管理系统  *********" << endl;
	cout << "**********  1.增加职工信息  *********" << endl;
	cout << "**********  2.显示职工信息  *********" << endl;
	cout << "**********  3.删除离职职工  *********" << endl;
	cout << "**********  4.修改职工信息  *********" << endl;
	cout << "**********  5.查找职工信息  *********" << endl;
	cout << "**********  6.按照编号排序  *********" << endl;
	cout << "**********  7.清空所有文档  *********" << endl;
	cout << "*************************************" << endl;
}


//添加员工
void WorkManager::Add_Emp()
{

	cout << "添加员工数量：" << endl;
	int add_Num = 0;//添加员工数量
	cin >> add_Num;
	if (add_Num>0)
	{
		//添加
		

		//计算添加空间大小
		int newsize = this->m_EmpNum+add_Num;


		//开辟新空间
		Worker** newSpace = new Worker * [newsize+4]; 

		//如果原来就有数据，则将原来的数据存到新开辟的空间。

		if (this->m_EmpNum!=NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加员工信息
		for (int i = 0; i < add_Num; i++)
		{
			int id;//职工编号
			string name;//姓名
			int dSelect;//部门选择
			cout << "输入第" << i + 1 << "个新员工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新员工姓名:" << endl;
			cin >> name;
			cout << "请选择该职工岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			//新员工的存放空间空间
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;

			default:
				break;
			}
			//将创造出来的员工加入到员工数组里
			newSpace[this->m_EmpNum + i] = worker;

		}
		//释放原来的空间
		delete[]this->m_EmpArray;
		//更改新空间指向
		this->m_EmpArray = newSpace;
		//更新员工人数
		this->m_EmpNum=newsize;
		//更新职工不为空时
		this->m_FileIsEmpty = false;

		cout << "添加" <<add_Num<< "名新员工" << endl;
		//调用保存数据函数
		this->SaveFile();
	
	}else
	{
		cout << "输入有误，请重新输入" << endl;
	}
	//按任意键后清屏,返回上一级目录
	system("pause");	
	system("cls");
}

//把信息写入文档
void WorkManager::SaveFile()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	//写输出方式打开文件--写文件的方式打开
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}


//读取现有员工数量
int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		num++;
	}
	return num;
}

//初始化员工
void WorkManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		//根据员工不同类型，创造不同的类型空间
		Worker* worker = NULL;
		if (dId==1)		//员工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)	//管理员
		{
			worker = new Manager(id, name, dId);
		}
		else		//老板
		{
			worker = new boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}


//显示员工
void WorkManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int  i = 0; i < m_EmpNum ;i++)
		{
			//调用显示信息函数
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}


//查找员工是否只存在 
int WorkManager::Is_Exist(int id)
{
	//id待查找对象id
	int index = -1;
	for (int i = 0; i < this->get_EmpNum(); i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
			index = i;
		break;
	}
	//返回查找对象
	return index;
}


//删除员工
void WorkManager::Del_Emp()
{
	//当文件存在且数据不为空时---m_FileIsEMpty为假，否则为真

	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "请输入想要删除的职工编号:" << endl;
		int id;
		cin >> id;

		int index = this->Is_Exist(id);
		if (index!=-1)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				//数据前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			//更新数组中的人数
			this->m_EmpNum--;

			//数据同步更新到文件中
			this->SaveFile();
			cout << "删除成功!" << endl;
		}
		else
		{
			cout << "删除失败，未找到该员工!" << endl;	
		}

	}
	//按任意键清屏
	system("pause");
	system("cls");

}

//修改员工信息
void WorkManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;
		int ret = this->Is_Exist(id);
		if (ret!=-1)
		{
			//查找到编号的员工
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName;
			int dSelect = 0;
			cout << "查到：" << id << "号职工，请输入新职员工号：" << endl;
			cin >> newId;

			cout << "请输入新姓名：" << endl;
			cin >> newName;

			cout << "请输入岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{

			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new boss(newId, newName, dSelect);
				break;

			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			//提示
			cout << "修改成功" << endl;

			//保存到文件中
			this->SaveFile();
		}
		else
		{
			cout << "修改失败，无此员工!" << endl;
		}
		//按任意键清屏
		system("pause");
		system("cls");
	}
	
}

//查找员工
void WorkManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式:" << endl;
		cout << "1.按照职工编号查找" << endl;
		cout << "2.按照职工信命查找" << endl;
		int select = 0;
		cin >> select;
		if (select==1)
		{
			//按照职工编号查找
			int id;
			cout << "请输入查找的职工的编号：" << endl;
			cin >> id;
			int ret = this->Is_Exist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下:" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
				cout << "查无此人" << endl;
		}
		else if(select==2)
		{
			//按照职工信命查找
			cout << "请输入查找的姓名：" << endl;
			string name;
			cin >> name;
			//判断是否找到的标志
			bool flag=false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name==name)
				{
					cout << "查找成功,该职工编号：" << this->m_EmpArray[i]->m_Id << endl;
					flag = true;
					//显示该员工信息
					this->m_EmpArray[i]->showInfo();
					
				}
			}
			if (flag==false)
			{
				cout << "查无此人" << endl;
			}
		}
		else
		{
			cout << "输入有误" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}


//职工排序
void WorkManager::Sort_Emp()
{

	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		//按任意键清屏
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择升序还是降序：" << endl;
		cout << "1.升序。" << endl;
		cout << "2.降序。" << endl;
		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax=i ;//确定最小值或最大值
			for (int j = 0; j < this->m_EmpNum; j++) 
			{
				if (select == 1)
				{
					//升序
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = i;
					}					
				}
				else
				{
					//降序
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = i;
					}
				}
				
				
			}	
			//判断一开始认定的最小值或最大值是不是计算的最小值或最大值，如果不是则交换数据
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功,排序后的结果:" << endl;
		this->SaveFile();//将排序后的保存入文档
		this->Show_Emp();//展示所有职工
		
		
	}

	


}

//退出系统
void WorkManager::ExitSystem()
{
	cout << "正在退出系统，欢迎下次使用。" << endl;
	system("pause");
	exit(0);//退出系统

}

