#include"deque����.h"

//��ӡdeque������
void myPrintDeque(const deque<int>&deq)
{
	//���ж��Ƿ�Ϊ��
	if (deq.size() == 0)
	{
		cout << "˫������Ϊ��" << endl;
	}
	else
	{
		//�����ӡ˫����������
		for (deque<int>::const_iterator i = deq.begin(); i != deq.end(); i++)//��const���η�ֹ�ں��������޸���ֵ
		{
			//����
			//*i = 100;	//error
			cout << *i << "  ";
		}
		cout << endl;
	}

}



//deque�Ĺ��캯��
void test_Structurn_deque()
{
	//1.Ĭ�Ϲ��캯������˫������d1
	deque<int>d1;

	//��˫������d1��ֵ
	for (int i = 0; i < 5; i++)
	{
		d1.push_back(i);
	}
	myPrintDeque(d1);


	//2.��������ķ�ʽ����˫������
	deque<int>d2(d1.begin(), d1.end());

	//��ӡ˫������d2
	myPrintDeque(d2);

	//3.����n��element��Ԫ�أ�����˫������
	deque<int>d3(3, 100);

	//��ӡ˫������d3
	myPrintDeque(d3);

	//���ÿ������촴��˫������d4
	deque<int>d4(d3);//d4 copy d3
	
	//print d4
	myPrintDeque(d4);

}


//deque�ĸ�ֵ
void test_Assign_deque()
{
	//����˫������d1
	deque<int>d1;

	//��ֵ
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}

	//1.����˫������d2,Ȼ����operator=��ֵ

	deque<int>d2(d1);
	myPrintDeque(d2);

	//2.����assign��ֵ
	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	myPrintDeque(d3);

	//3.����n��element�ķ�ʽ��ֵ
	deque<int>d4(5,100);
	myPrintDeque(d4);
}


//deque��С����
void test_Size_deque()
{
	//dequeû��������capacity)�ĸ���

	//����˫������d1
	deque<int>d1;
	
	//˫�����鸳ֵ
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}

	//��ӡ˫����������
	myPrintDeque(d1);

	if (d1.empty())	//empty:�յ�
	{
		//d1.empty()����bool���ͣ��շ���1���ǿշ���0
		cout << "��" << endl;
	}
	else
	{
		cout << "�ǿ�" << endl;
	}

	//����ָ����С
	cout << "����ָ��ǰ��С��" << d1.size() << endl;
	d1.resize(15);
	cout << "����ָ�����С��" << d1.size() << endl;

	//����ָ����С������ĳ�����
	cout << "����ָ��ǰ��С��" << d1.size() << endl;
	myPrintDeque(d1);
	d1.resize(20, 9);
	cout << "����ָ�����С��" << d1.size() << endl;
	myPrintDeque(d1);

	d1.erase(d1.begin(), d1.begin()+5);//��ʲô��ʼ��ʲô����ɾ������
	myPrintDeque(d1);

	d1.resize(5);//�Ӻ���ɾ����ʣ��5��Ԫ��
	myPrintDeque(d1);
}


//deque insert and delete
void test_InsertAndDelete_deque()
{
	//����˫������d1
	deque<int>d1;

	//β����
	d1.push_back(10);
	d1.push_back(20);

	//ͷ����
	d1.push_front(100);
	d1.push_front(200);

	//��ӡ˫������
	myPrintDeque(d1);//200  100  10  20

	//ͷɾ
	d1.pop_front();
	myPrintDeque(d1);	//100  10  20
	//βɾ
	d1.pop_back();
	myPrintDeque(d1);	//100  10

	//����˫������d2
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_front(10);
	d2.push_front(20);
	myPrintDeque(d2);	//20  10  1  2

	//������λ�ã�d2.size��Χ�ڣ�
	d2.insert(d2.begin(), 100);//�ڵ�һ��λ�ò���1��100,	//100  20  10  1  2
	myPrintDeque(d2);

	d2.insert(d2.begin(), 3,200);	//�ڵ�һ��λ�ò���3��200		,200  200  200  100  20  10  1  2
	myPrintDeque(d2);

	d2.insert(d2.begin() + 3, 2, 400);	//�ڵ�d2.begin()+3=1+3=4��λ���ϼ�2��400		200  200  200  400  400  100  20  10  1  2
	myPrintDeque(d2);

	//��������ķ�ʽ����
	deque<int>d3;
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);
	d3.push_back(4);
	d2.insert(d2.begin(), d3.begin() + 1, d3.end());	//��d2��begin����λ���Ͽ�ʼ���룬��d3.begin����+1��d3.end����{��2��3��4}������		2  3  4  200  200  200  400  400  100  20  10  1  2
	myPrintDeque(d2);


	//ɾ��
	d2.erase(d2.begin()+3);//ɾ�����ĸ�Ԫ��	2  3  4  200  200  400  400  100  20  10  1  2
	myPrintDeque(d2);

	//���������ɾ��
	d2.erase(d2.begin() + 3, d2.end());	//ɾ�����ĸ������һ��
	myPrintDeque(d2);	//2 3 4

	//ɾ��ȫ��
	d2.clear();
	myPrintDeque(d2);	//˫������Ϊ��

}


//deque���ݴ�ȡ
void test_Access_deque()
{
	//����˫������d1
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	//����Ԫ��
	for (int i = 0; i < d1.size(); i++)
	{

		//ͨ��[]����Ԫ��
		cout << d1[i] << "  ";		
	}			//300  200  100  10  20  30
	cout << endl;
	for (int i = 0; i < d1.size(); i++)
	{
		//ͨ����Ա����at����
		cout << d1.at(i) << "  ";
	}		//300  200  100  10  20  30
	cout << endl;

	cout << "front���ʵ�һ��Ԫ��:" << d1.front() << endl;	//300
	cout << "back�������һ��Ԫ��:" << d1.back() << endl;	//30
}

//sort deque ����
int compare(int a, int b)
{
	return a > b ;
}
void test_Sort_deque()
{

	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	myPrintDeque(d1);	//300  200  100  10  20  30

	//����
	cout << "�����" << endl;
	sort(d1.begin(), d1.end());	//Ĭ�ϴ�С�������򣨣���������Χ
	myPrintDeque(d1);
	
}



