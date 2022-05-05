#include"list����.h"

person::person(string name, int age, int height)
{
	this->m_name = name;
	this->m_age = age;
	this->m_height = height;
}

person::~person()
{
}

void myprintlist(const list<int>& List){

	if (List.size() == 0)
	{
		cout << "����Ϊ��";
	}
	else
	{
		//��������--��ֹ�޸����ݣ�������const_iterator����
		for (list<int>::const_iterator i = List.begin(); i !=List.end(); i++)
		{
			cout << *i << " ";
		}
	}
	cout << endl;
}

//list����
void test_structurn_list()
{
	//��������list����
	list<int>L1;

	//�������push
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	//��������
	myprintlist(L1);

	//�������乹������
	list<int>L2(L1.begin(), L1.end());
	myprintlist(L2);

	//���ÿ�����������
	list<int>L3(L2);
	myprintlist(L3);

	//����n��element��������
	list<int>L4(5, 100);
	myprintlist(L4);
}


//list��ֵ�ͽ���
void test_AssignAndSwap_list()
{
	//��������
	list<int>L1;

	//��������
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	//��ӡL1
	myprintlist(L1);	//10 20 30 40

	//operator=��ֵ
	list<int>L2;
	L2 = L1;
	myprintlist(L2);	//10 20 30 40

	//assign��ֵ
	list<int>L3;
	L3.assign(L2.begin(), L2.end());
	myprintlist(L3);	//10 20 30 40

	//n��elem�ĸ�ֵ
	list<int>L4(10,999);
	myprintlist(L4);	//999 999 999 999 999 999 999 999 999 999

	//��������L1��L4
	cout << "����ǰL1.size��" << L1.size() << endl;//����ǰL1.size��4	
	cout << "����ǰL4.size��" << L4.size() << endl;//L1.size��10
	//����
	swap(L1, L4);

	myprintlist(L1);//999 999 999 999 999 999 999 999 999 999
	myprintlist(L2);//10 20 30 40
	cout <<"������L1.size��" << L1.size() << endl;//������L1.size��10
	cout << "������L4.size��" << L4.size() << endl;//������L4.size��4


}


//list������С����
void test_sizeof_list()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	cout <<"L1��size��" << L1.size() << endl;		//4
	//����ָ��L1�Ĵ�С
	L1.resize(10);
	cout << "����ָ��L1��size��" << L1.size() << endl;	//10

	if (L1.empty())//�ж��Ƿ�Ϊ�գ���1���ǿ�0
	{
		cout << "����Ϊ��" << endl;
	}
	else {
		cout << "������Ϊ��" << endl;
	}

	list<int>L2;//δָ����С
	if (L2.empty())
	{
		cout << "����Ϊ��" << endl;
	}
	else {
		cout << "������Ϊ��" << endl;
		cout << "L2�����Ĵ�С��" << L2.size() << endl;
	}

	//����ָ��L2��С�������ֵ
	L2.resize(5, 10);//5��10���L2
	myprintlist(L2);	//10 10 10 10 10

	L2.resize(10);//5��0���ʣ��Ŀ�λ��
	myprintlist(L2);	//10 10 10 10 10 0 0 0 0 0

	L2.resize(3);//ֻ����ǰ3����ֵ���������
	myprintlist(L2);	//10 10 10
}

//list���롢ɾ��
void test_InsertAnddelete_list()
{
	list<int>L1;
	//β��
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);

	//ͷ��
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);

	myprintlist(L1);//300 200 100 10 20 30

	//ͷɾ
	L1.pop_front();
	myprintlist(L1);//200 100 10 20 30
	//βɾ
	L1.pop_back();
	myprintlist(L1);//200 100 10 20 

	//insert����
	L1.insert(L1.begin(), 1000);
	myprintlist(L1);//1000 200 100 10 20 
	L1.insert(L1.end(), 50);
	myprintlist(L1);//1000 200 100 10 20 50

	//��λ�ò���,�õ�����,����ֱ����L1.begin()+n;
	list<int>::iterator bit = L1.begin();
	L1.insert(++bit, 88);
	myprintlist(L1);//1000 88 200 100 10 20 50

	//ɾ��erase
	L1.erase(L1.begin());
	myprintlist(L1);//88 200 100 10 20 50

	//�Ƴ�remove--�Ƴ�����ָ����Ԫ��
	L1.resize(10, 10);
	myprintlist(L1);//88 200 100 10 20 50 10 10 10 10
	L1.remove(10);
	myprintlist(L1);//88 200 100 20 50

	//���
	L1.clear();
	myprintlist(L1);//����Ϊ��	
}


//list���ݴ�ȡ
void test_Access_list()
{
	//��������ṹ���⣬ÿ�����ݲ��������Ŀռ�洢�����в�����[]��at����Ԫ�ء�

	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	L1.push_back(60);
	L1.push_back(70);
	L1.push_back(80);

	//����-front--���ʵ�һ��Ԫ��
	cout << L1.front() << endl;//10

	//�������һ��Ԫ��--back
	cout << L1.back() << endl;//80

	//list�ĵ�������֧����Ծʽ�ķ���
	list<int>::iterator it = L1.begin();
	//it += 1;//error
			
	//֧��˫��
	cout << *it << endl;//10
	it++;
	cout << *it << endl;//20
	it--;
	cout << *it << endl;//10

	//������ѭ�������ķ�ʽ��������λ��
	int num = 3;//Ҫ���ʵ�λ��
	for (int i = 0; i < num-1; i++)
	{
		it++;
	}
	cout << *it << endl;//30
}


bool mycompare(int a,int b)
{
	//���򣺵�һ�������ڵڶ�����
	return a > b;
}

//list��ת������
void test_ReverseAndSort_list()
{
	list<int>L1;
	L1.push_back(40);
	L1.push_back(20);
	L1.push_back(50);
	L1.push_back(60);
	L1.push_back(10);
	L1.push_back(30);
	cout << "��תǰ��" << endl;
	myprintlist(L1);

	//��ת����reverse  ���м�Ϊ�Գ��ᷴת
	L1.reverse();
	cout << "��ת��" << endl;
	myprintlist(L1);

	//����sort
	L1.sort();//Ĭ������
	cout << "����";
	myprintlist(L1);

	/*
		ע�⣺
			list��������ֱ��sort(L1.begin(),L1.end())��ô�ã����Բ�֧��������ʵ���������������֧��ֱ���ñ�׼�㷨
			��֧��������ʣ��ڲ����ṩ��Ӧ��һЩ�㷨
	*/

	//sort����--Ҫ����һ������
	L1.sort(mycompare);
	cout << "����";
	myprintlist(L1);


}


//������--sort�ķº���
bool apply_comp_list(person& p1, person& p2)
{
	//������������
	
	if (p1.m_age==p2.m_age)
	{//��������ͬ�������������
		return p1.m_height >p2.m_height;
	}
	return p1.m_age < p2.m_age;
}


//������
void test_apply_list()
{
	//����Person����
	list<person>L;

	//Person����
	person P1("����", 35, 175);
	person P2("�ܲ�", 45, 180);
	person P3("��Ȩ", 40, 170);
	person P4("����", 25, 190);
	person P5("�ŷ�", 35, 160);
	person P6("����", 35, 200);

	//��������
	L.push_back(P1);
	L.push_back(P2);
	L.push_back(P3);
	L.push_back(P4);
	L.push_back(P5);
	L.push_back(P6);

	//��ӡ
	for (list<person>::const_iterator it = L.begin(); it!=L.end(); it++)
	{
		cout<<"name:" << it->m_name << " age:" << (*it).m_age << " height:" << (*it).m_height << endl;
	}

	//����
	cout << "===========================�����========================"<<endl;
	L.sort(apply_comp_list);
	for (list<person>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "name:" << (*it).m_name << " age:" << (*it).m_age << " height:" << (*it).m_height << endl;
	}

}


