#include"queue����.h"


Person::Person(string name, int age)
{
	this->m_name=name;
	this->m_age=age;
}

Person::~Person()
{
}

void test_queue()
{
	//��������Person�Ķ���
	queue<Person>q;

	//׼������
	Person P1("�����", 501);
	Person P2("��˽�", 401);
	Person P3("ɳ��  ", 301);
	Person P4("������", 1001);
	Person P5("������", 26);

	//���
	q.push(P1);
	q.push(P2);
	q.push(P3);
	q.push(P4);
	q.push(P5);
	cout << q .size() << endl;
	//�ж�ֻҪ���в�Ϊ�գ��鿴��ͷ����β����
	while(!q.empty())
	{
		cout << "name:" << q.front().m_name << " age:" << q.front().m_age << endl;//�����ͷ
		cout << "name:" << q.back().m_name << " age:" << q.back().m_age << endl;//�����β
		//����
		q.pop();
	}
	cout << q.size() << endl;
}
