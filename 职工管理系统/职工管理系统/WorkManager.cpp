#include<iostream>
#include "WorkManager.h"

using namespace std;


//Ա������Ա���캯��
WorkManager::WorkManager()
{
	//1.�ж��ļ��Ƿ���ڣ�
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//���ļ���ʽ--���ļ�
	if (!ifs.is_open())//�ɹ��򿪷���1����ʧ�ܷ���0
	{
		cout << "�ļ���ʧ��" << endl;
		//��ʼ������
		//��ʼ������������
		this->m_EmpNum = 0;
		//��ʼ������ָ�룺
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڣ������ݿ�
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		//��ʼ������������
		this->m_EmpNum = 0;
		//��ʼ������ָ�룺
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//���ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ" << num << "��" << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];

	//���ļ��е����ݣ����浽������
	this->init_Emp();

	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
			<< "\t������" << this->m_EmpArray[i]->m_name
			<< "\t���ű�ţ�" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}


//Ա������Ա��������
WorkManager::~WorkManager()
{
	//�ͷſռ�
	if (this->m_EmpArray!=NULL)
	{
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
		
	}
}
//չʾ�˵�
void WorkManager::ShowMenu()
{
	cout << "*************************************" << endl;
	cout << "*******  ��ӭʹ��ְ������ϵͳ! ******" << endl;
	cout << "**********  0.�˳�����ϵͳ  *********" << endl;
	cout << "**********  1.����ְ����Ϣ  *********" << endl;
	cout << "**********  2.��ʾְ����Ϣ  *********" << endl;
	cout << "**********  3.ɾ����ְְ��  *********" << endl;
	cout << "**********  4.�޸�ְ����Ϣ  *********" << endl;
	cout << "**********  5.����ְ����Ϣ  *********" << endl;
	cout << "**********  6.���ձ������  *********" << endl;
	cout << "**********  7.��������ĵ�  *********" << endl;
	cout << "*************************************" << endl;
}


//���Ա��
void WorkManager::Add_Emp()
{

	cout << "���Ա��������" << endl;
	int add_Num = 0;//���Ա������
	cin >> add_Num;
	if (add_Num>0)
	{
		//���
		

		//������ӿռ��С
		int newsize = this->m_EmpNum+add_Num;


		//�����¿ռ�
		Worker** newSpace = new Worker * [newsize+4]; 

		//���ԭ���������ݣ���ԭ�������ݴ浽�¿��ٵĿռ䡣

		if (this->m_EmpNum!=NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������Ա����Ϣ
		for (int i = 0; i < add_Num; i++)
		{
			int id;//ְ�����
			string name;//����
			int dSelect;//����ѡ��
			cout << "�����" << i + 1 << "����Ա����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����Ա������:" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			//��Ա���Ĵ�ſռ�ռ�
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
			//�����������Ա�����뵽Ա��������
			newSpace[this->m_EmpNum + i] = worker;

		}
		//�ͷ�ԭ���Ŀռ�
		delete[]this->m_EmpArray;
		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;
		//����Ա������
		this->m_EmpNum=newsize;
		//����ְ����Ϊ��ʱ
		this->m_FileIsEmpty = false;

		cout << "���" <<add_Num<< "����Ա��" << endl;
		//���ñ������ݺ���
		this->SaveFile();
	
	}else
	{
		cout << "������������������" << endl;
	}
	//�������������,������һ��Ŀ¼
	system("pause");	
	system("cls");
}

//����Ϣд���ĵ�
void WorkManager::SaveFile()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	//д�����ʽ���ļ�--д�ļ��ķ�ʽ��
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}


//��ȡ����Ա������
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

//��ʼ��Ա��
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
		//����Ա����ͬ���ͣ����첻ͬ�����Ϳռ�
		Worker* worker = NULL;
		if (dId==1)		//Ա��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)	//����Ա
		{
			worker = new Manager(id, name, dId);
		}
		else		//�ϰ�
		{
			worker = new boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}


//��ʾԱ��
void WorkManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int  i = 0; i < m_EmpNum ;i++)
		{
			//������ʾ��Ϣ����
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}


//����Ա���Ƿ�ֻ���� 
int WorkManager::Is_Exist(int id)
{
	//id�����Ҷ���id
	int index = -1;
	for (int i = 0; i < this->get_EmpNum(); i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
			index = i;
		break;
	}
	//���ز��Ҷ���
	return index;
}


//ɾ��Ա��
void WorkManager::Del_Emp()
{
	//���ļ����������ݲ�Ϊ��ʱ---m_FileIsEMptyΪ�٣�����Ϊ��

	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else
	{
		cout << "��������Ҫɾ����ְ�����:" << endl;
		int id;
		cin >> id;

		int index = this->Is_Exist(id);
		if (index!=-1)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				//����ǰ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			//���������е�����
			this->m_EmpNum--;

			//����ͬ�����µ��ļ���
			this->SaveFile();
			cout << "ɾ���ɹ�!" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���Ա��!" << endl;	
		}

	}
	//�����������
	system("pause");
	system("cls");

}

//�޸�Ա����Ϣ
void WorkManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;
		int ret = this->Is_Exist(id);
		if (ret!=-1)
		{
			//���ҵ���ŵ�Ա��
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName;
			int dSelect = 0;
			cout << "�鵽��" << id << "��ְ������������ְԱ���ţ�" << endl;
			cin >> newId;

			cout << "��������������" << endl;
			cin >> newName;

			cout << "�������λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//��ʾ
			cout << "�޸ĳɹ�" << endl;

			//���浽�ļ���
			this->SaveFile();
		}
		else
		{
			cout << "�޸�ʧ�ܣ��޴�Ա��!" << endl;
		}
		//�����������
		system("pause");
		system("cls");
	}
	
}

//����Ա��
void WorkManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ:" << endl;
		cout << "1.����ְ����Ų���" << endl;
		cout << "2.����ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select==1)
		{
			//����ְ����Ų���
			int id;
			cout << "��������ҵ�ְ���ı�ţ�" << endl;
			cin >> id;
			int ret = this->Is_Exist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ����:" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
				cout << "���޴���" << endl;
		}
		else if(select==2)
		{
			//����ְ����������
			cout << "��������ҵ�������" << endl;
			string name;
			cin >> name;
			//�ж��Ƿ��ҵ��ı�־
			bool flag=false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name==name)
				{
					cout << "���ҳɹ�,��ְ����ţ�" << this->m_EmpArray[i]->m_Id << endl;
					flag = true;
					//��ʾ��Ա����Ϣ
					this->m_EmpArray[i]->showInfo();
					
				}
			}
			if (flag==false)
			{
				cout << "���޴���" << endl;
			}
		}
		else
		{
			cout << "��������" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}


//ְ������
void WorkManager::Sort_Emp()
{

	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		//�����������
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ�������ǽ���" << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax=i ;//ȷ����Сֵ�����ֵ
			for (int j = 0; j < this->m_EmpNum; j++) 
			{
				if (select == 1)
				{
					//����
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = i;
					}					
				}
				else
				{
					//����
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = i;
					}
				}
				
				
			}	
			//�ж�һ��ʼ�϶�����Сֵ�����ֵ�ǲ��Ǽ������Сֵ�����ֵ����������򽻻�����
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ�,�����Ľ��:" << endl;
		this->SaveFile();//�������ı������ĵ�
		this->Show_Emp();//չʾ����ְ��
		
		
	}

	


}

//�˳�ϵͳ
void WorkManager::ExitSystem()
{
	cout << "�����˳�ϵͳ����ӭ�´�ʹ�á�" << endl;
	system("pause");
	exit(0);//�˳�ϵͳ

}

