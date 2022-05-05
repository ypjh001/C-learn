#include "map��multimap����.h"


//��ӡmap
void myprintmap(const map<int, int>& m)
{
	if (m.empty())
	{
		cout << "mapΪ��";
	}
	else
	{
		//����map
		for (map<int,int>::const_iterator it=m.begin();it!=m.end(); it++)
		{
			cout << "key:" << it->first << " value:" << it->second << "|==���==| ";
		}
	}
	cout << endl;
}

//map����
void test_structurn_map()
{
	//����map����
	map<int, int>m1;
	//������ֵ--Ҫʹ�ö���
	m1.insert(pair<int, int>(1, 10));//1��key��10��value
	m1.insert(pair<int, int>(3, 12));
	m1.insert(pair<int, int>(5, 14));
	m1.insert(pair<int, int>(2, 11));
	myprintmap(m1);//key:1 value:10|==���==| key:2 value:11|==���==| key:3 value:12|==���==| key:5 value:14|==���==|
	//��ӡ������key˳��

	//���ÿ�������
	map<int, int>m2(m1);
	myprintmap(m2);//key:1 value:10|==���==| key:2 value:11|==���==| key:3 value:12|==���==| key:5 value:14|==���==|

	//��ֵ����
	map<int, int>m3=m2;
	myprintmap(m3);//key:1 value:10|==���==| key:2 value:11|==���==| key:3 value:12|==���==| key:5 value:14|==���==|
}


//��С�ͽ���
void tset_SizeAndSwap_map()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));//1��key��10��value
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	myprintmap(m1);
	map<int, int>m2;
	m2.insert(pair<int, int>(6, 60));
	m2.insert(pair<int, int>(2, 20));
	m2.insert(pair<int, int>(1, 10));
	myprintmap(m2);
	//��С
	cout <<"����ǰm1��С��" << m1.size()<<endl;
	cout << "����ǰm2��С��" << m2.size()<<endl;
	
	//����
	swap(m1, m2);
	cout << "������m1��С��" << m1.size() << endl;
	cout << "������m2��С��" << m2.size() << endl;
	myprintmap(m1);
	myprintmap(m2);
}


//map�Ĳ����ɾ��
void test_InsertAndDelete_map()
{
	map<int, int>m1;

	//1.����
	m1.insert(pair<int, int>(1, 10));

	//2.����
	m1.insert(make_pair(2, 20));

	//3.����
	m1.insert(map<int, int>::value_type(3, 10));
	myprintmap(m1);//key:1 value:10|==���==| key:2 value:20|==���==| key:3 value:10|==���==|

	//4.����
	m1[4] = 40;//�ڵ�4��λ�ò���40---������ʹ�����ַ�ʽ����
	map<int, int>m2(m1);

	//1.ɾ��
	m1.erase(m1.begin());
	myprintmap(m1);//key:2 value:20|==���==| key:3 value:10|==���==| key:4 value:40|==���==|

	//2.ɾ��
	m1.erase(3);//����keyɾ��
	myprintmap(m1);//key:2 value:20|==���==| key:4 value:40|==���==|

	//3.ɾ������գ�
	myprintmap(m2);//key:1 value:10|==���==| key:2 value:20|==���==| key:3 value:10|==���==| key:4 value:40|==���==|
	m2.clear();//or m2.erase(m2.begin(),m2.end())
	myprintmap(m2);//mapΪ��
}

 


