#include"set����.h"
#include<set>

//set�Ĵ�ӡ
void myprintset(const set<int>& s)
{
	if (s.empty())//empty�ж�Ϊ��
	{
		cout << "set����Ϊ��";
	}
	for (set<int>::const_iterator i = s.begin(); i  !=s.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

//multiset�Ĵ�ӡ
void myprintmultiset(const multiset<int>& muls)
{
	if (muls.empty())//empty�ж�Ϊ��
	{
		cout << "set����Ϊ��";
	}
	for (multiset<int>::const_iterator i = muls.begin(); i != muls.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}


//set�Ĺ���
void structurn_set()
{
	//����set����
	set<int>s1;

	//set��ֵ
	s1.insert(60);
	s1.insert(70);
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(80);
	s1.insert(40);
	s1.insert(30);


	//��ӡset
	myprintset(s1);//10 20 30 40 60 70 80	�����ӡ���30����Ϊ�������ظ�

	//ͨ��������������set����
	set<int>s2(s1);
	myprintset(s2);

	//ͨ�����乹��set����
	set<int>s3(s2.begin(), s2.end());
	myprintset(s3);

	
	
}


//set�Ĵ�С�ͽ���
void tset_SizeAndSwap_set()
{
	set<int>s1;
	s1.insert(60);
	s1.insert(70);
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(80);
	s1.insert(40);
	s1.insert(30);

	//s1��С

	cout<<"s1�Ĵ�С��" << s1.size() << endl;


	//����
	set<int>s2;
	s2.insert(80);
	s2.insert(40);
	s2.insert(30);
	cout << "����ǰs1��";
	myprintset(s1);
	cout << "����ǰs2��";
	myprintset(s2);
	cout << "s1��s2����" << endl;

	s2.swap(s1);
	cout << "������s1��";
	myprintset(s1);
	cout << "������s2��";
	myprintset(s2);
	cout << "s1�Ĵ�С��" << s1.size() << endl;
}


//set�Ĳ����ɾ��
void test_InsertAndDelete_set()
{
	set<int>s1;

	//����-insert
	s1.insert(60);
	s1.insert(70);
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(80);
	s1.insert(40);
	s1.insert(30);

	//s2����s1����
	set<int>s2(s1);

	//����
	myprintset(s1);//10 20 30 40 50 60 70 80

	//ɾ��-erase
	s1.erase(s1.begin());//���õ�����
	myprintset(s1);//20 30 40 50 60 70 80

	//s1.erase(s1.begin() + 2); error���󣬺�listһ��������ôɾ��
	set<int>::iterator it = s1.begin();//����������ʱit=20
	for (int i = 0; i < 3; i++)
	{
		++it;
	}
	s1.erase(it);//ѭ�����κ�it�ߵ�50����
	myprintset(s1);//20 30 40 60 70 80   ɾ����50
	
	//ָ��ɾ��
	s1.erase(30);
	myprintset(s1);//20 40 60 70 80

	//���clear
	s1.clear();
	myprintset(s1);//set����Ϊ��

	//�����������
	myprintset(s2);//10 20 30 40 50 60 70 80
	//���s2
	s2.erase(s2.begin(), s2.end());
	myprintset(s2);//set����Ϊ��
	
}

//set���Һ�ͳ��
void test_FindAndCount_set()
{
	//find(key) ;����key�Ƿ���ڣ������ڣ��򷵻�set.end�������������򷵻ظ�key�ĵ�����

	//count(key):ͳ��key�ĸ���������int


	set<int>s1;

	//����-insert
	s1.insert(60);
	s1.insert(70);
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(80);
	s1.insert(40);
	s1.insert(30);

	set<int>::iterator pos = s1.find(50);
	if (pos != s1.end())
	{
		cout << "���ҵ���:" << *pos << endl;//�������������ҵ���Ԫ��
	}
	else
	{
		cout << "û�ҵ���";
	}
	//ͳ��
	int num = s1.count(40);
	cout <<"������" << num << endl;
	//����set���ԣ�countֻ��0��1����Ϊsetû���ظ���Ԫ�ء�
}


//set��multiset����
void test_set_dis_multiset()
{
	/*
		set��multiset������
		set���������������ظ���Ԫ��
		multiset�������������ظ���Ԫ��
	*/
	multiset<int>ms;
	ms.insert(60);
	ms.insert(70);
	ms.insert(30);
	ms.insert(10);
	ms.insert(20);
	ms.insert(50);
	ms.insert(80);
	ms.insert(40);
	ms.insert(30);

	myprintmultiset(ms);//10 20 30 30 40 50 60 70 80

	set<int>s1;

	//����-insert
	s1.insert(60);
	s1.insert(70);
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(80);
	s1.insert(40);
	s1.insert(30);

	myprintset(s1);//10 20 30 40 50 60 70 80

	//set�ڲ������ݵ�ʱ����и��жϣ��ظ��ľ�ʧ�ܣ����ظ��ľͳɹ�
	//��֤

	set<int>s2;
	pair<set<int>::iterator, bool> ret = s2.insert(10);//�ص���bool���͵���ֵ
	
	if (ret.second)
	{
		cout << "��һ�β���ɹ���"<<endl;
	}
	else
	{
		cout << "��һ�β���ʧ�ܣ�" << endl;
	}

	//�ڶ��β���s2.insert(10)
	ret = s2.insert(10);
	//�ж�
	if (ret.second)
	{
		cout << "�ڶ��β���ɹ���" << endl;
	}
	else
	{
		cout << "�ڶ��β���ʧ�ܣ�" << endl;
	}


}


//set���鴴��
void test_pair_srt()
{
	//����1.��������
	pair<int, char>p1(3, 'A');
	cout << p1.first << " " << p1.second << endl;


	//����2.��������
	pair<char, string>p2;
	p2 = make_pair('G', ",���");
	cout << p2.first << " " << p2.second << endl;


}




//set����
void test_sort_set()
{
	//setĬ���Զ���������
	//���÷º��������Ըı��������

	set<int>s1;

	//����-insert
	s1.insert(60);
	s1.insert(70);
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(80);
	s1.insert(40);
	s1.insert(30);

	//Ĭ������
	myprintset(s1);

	set<int,Mycompare>s2;
	

	//����-insert
	s2.insert(3);
	s2.insert(1);
	s2.insert(5);
	s2.insert(4);
	s2.insert(2);
	s2.insert(7);
	s2.insert(6);

	//��s2�Ӵ�С������Ҫ�õ��º���
	//����s2
	for (set<int, Mycompare>::iterator it = s2.begin();it != s2.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//�����Զ������ͣ�����person��
	//����person������
	set<Person,MycomparePerson>s;

	//����Person����ֵ
	Person P1("����", 24);
	Person P2("����", 28);
	Person P3("�ŷ�", 25);
	Person P4("����", 21);

	//������������
	s.insert(P1);
	s.insert(P2);
	s.insert(P3);
	s.insert(P4);
	
	//��������
	for (set<Person,MycomparePerson>::iterator it = s.begin(); it !=s.end(); it++)
	{
		cout << "name:" << it->m_name << " age:" << it->m_age << endl;
	}


}


//set���Զ��壨person������
class people
{
public:
	people(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

class mypeopel_set
{
public:
	bool operator()(const people&p1,const people&p2) const
	{
		return p1.m_age < p2.m_age;
	}
};
void test_sort_Person_set()
{
	set<people,mypeopel_set>s1;
	
	//ʵ����people
	people p1("��", 16);
	people p2("������", 15);
	people p3("����", 19);
	people p4("����", 25);
	people p5("����", 20);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	s1.insert(p5);

	for (set<people, mypeopel_set>::iterator it = s1.begin();it != s1.end();it++)
	{
		cout <<"name:" << (*it).m_name << " age " << it->m_age << endl;
	}

}


