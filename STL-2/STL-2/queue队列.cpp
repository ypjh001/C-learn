#include"queue队列.h"


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
	//创建队列Person的队列
	queue<Person>q;

	//准备数据
	Person P1("孙悟空", 501);
	Person P2("猪八戒", 401);
	Person P3("沙憎  ", 301);
	Person P4("白龙马", 1001);
	Person P5("唐三藏", 26);

	//入队
	q.push(P1);
	q.push(P2);
	q.push(P3);
	q.push(P4);
	q.push(P5);
	cout << q .size() << endl;
	//判断只要队列不为空，查看队头、队尾出队
	while(!q.empty())
	{
		cout << "name:" << q.front().m_name << " age:" << q.front().m_age << endl;//输出队头
		cout << "name:" << q.back().m_name << " age:" << q.back().m_age << endl;//输出队尾
		//出队
		q.pop();
	}
	cout << q.size() << endl;
}
