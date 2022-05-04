#include"Vector.h"
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void myprintf(int val)
{
	//����STL�Ļص�������Ҫ�Լ���һ������
	cout << val << "  ";
}
cout << endl;

void leran_Vector()
{
	//��һ��Vector������������
	vector<int> V;

	//�������в�������
	V.push_back(10);		//push:�ơ�������
	V.push_back(20);
	V.push_back(30);
	V.push_back(40);

	//ͨ������������V��vector�������
	vector<int>::iterator itBegin = V.begin();	 //��ʼ��������ָ���һ�����ݣ������С�10����λ��
	vector<int>::iterator itEnd = V.end();		//������������ָ�����һ�����ݵ���һ��λ�ã������С�40�������λ��

	//��һ�ֱ�������
	while (itBegin != itEnd)
	{
		cout << *itBegin << "  ";
		itBegin++;
	}
	cout << endl;
	////��������������
	//while (itBegin!=itEnd)
	//{
	//	cout << *(itEnd-1) << endl;//��Ϊ*ITEndָ��һ���յĵ�ַ������ִ���Ҫ��ָ��40������ҪitEnd�ĵ�ַ��ǰ�ƶ�һ����λ��*(itEnd-1)
	//	itEnd--;
	//}

	////�ڶ��ֱ��������á������٣�
	//for (vector<int>::iterator it=V.begin() ; it!=V.end(); it++)//
	//{
	//	cout << *it << endl;
	//}


	//�����ֱ����㷨,����STL�ṩ�ı����㷨--Ŀǰ������˵Ҫ��ϸ�
	for_each(V.begin(), V.end(), myprintf);

}


Person::Person(string name, int age)
{
	this->m_name = name;
	this->m_age = age;
}

Person::~Person()
{
}



//��ʵ�ֺ�����test_custom_vector()
void test_custom_Person_vector()
{
	//����һ��Person���Vector  V���������V
	vector<Person> V;

	//�������--ʵ��������ֵ
	Person P1("aaa", 10);
	Person P2("bbb", 20);
	Person P3("ccc", 30);
	Person P4("ddd", 40);
	Person P5("eee", 50);

	//�������в�������--β�巨
	V.push_back(P1);
	V.push_back(P2);
	V.push_back(P3);
	V.push_back(P4);
	V.push_back(P5);

	//��ӡ����--��������
	for (vector<Person>::iterator it = V.begin();it != V.end();it++)
	{
		//cout<<"������" << it->m_name << " ���䣺" << it->m_age << endl;
		cout << "������" << (*it).m_name << "���䣺" << (*it).m_age << endl;//.���������ȼ���*�ߣ�����Ҫ�ӣ�����<ʲô����>��*it������ľ���ʲô����
	}

	//����һ��Person*��Vector ���������V1
	vector<Person*> V1;

	//�������--ʵ��������ֵ
	Person P6("aaa", 10);
	Person P7("bbb", 20);
	Person P8("ccc", 30);
	Person P9("ddd", 40);
	Person P10("eee", 50);

	//�������в�������--β�巨---V1������ŵ��ǵ�ַ������P6-10Ҫ�Ӹ�ȡ��ַ����&
	V1.push_back(&P6);
	V1.push_back(&P7);
	V1.push_back(&P8);
	V1.push_back(&P9);
	V1.push_back(&P10);

	//��ӡ����--��������
	for (vector<Person*>::iterator it = V1.begin();it != V1.end();it++)
	{
		//cout<<"������" << it->m_name << " ���䣺" << it->m_age << endl;
		//cout << ":::������" << (*it)->m_name << "���䣺" << (*it)->m_age << endl;//.���������ȼ���*�ߣ�����Ҫ�ӣ�����<ʲô����>��*it������ľ���ʲô����	//ָ���ü�ͷ����ַ�ý����ŷ�*

		Person* p = (*it);
		cout << "name:" << p->m_name << "  age��" << p->m_age << endl;
	}
}


//����Ƕ������-nested

void test_Vct_nested_Vct()
{
	//���������� V
	vector<vector<int>>V;

	//����С���� v
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;

	//��С�������������
	for (int i = 0; i < 3; i++)
	{
		v1.push_back(10);
		v2.push_back(20);
		v3.push_back(30);
		v4.push_back(40);
	}
	//�������V�����С����(v1-v4)
	V.push_back(v1);
	V.push_back(v2);
	V.push_back(v3);
	V.push_back(v4);
	
	//��ӡ�������������
	for (vector<vector<int>>::iterator It = V.begin(); It !=V.end(); It++) 
	{

		//��һ�ִ�ӡ

		////��ӡv1
		////cout << "��ӡv1" << endl;;
		//for (vector<int>::iterator it1 = v1.begin();it1 != v1.end();it1++)
		//{
		//	cout << *it1 << "  ";
		//}
		////��ӡv2
		////cout << "��ӡv2"<<endl;
		//for (vector<int>::iterator it2 = v2.begin();it2 != v2.end();it2++)
		//{
		//	cout << *it2 << "  ";
		//}
		////��ӡv3
		////cout << "��ӡv3"<<endl;
		//for (vector<int>::iterator it3 = v3.begin();it3 != v3.end();it3++)
		//{
		//	cout << *it3 << "  ";
		//}
		////��ӡv4
		////cout << "��ӡv4" << endl;
		//for (vector<int>::iterator it4 = v4.begin();it4 != v4.end();it4++)
		//{
		//	cout << *it4 << "  ";
		//}


		//�ڶ��ִ�ӡ
		for (vector<int>::iterator vit = (*It).begin(); vit != (*It).end(); vit++)
		{
			//It������vector<int>
			//*It������int������vit=*It��
			//*vit��������ʵ��10-40
			cout << *vit << "   ";
		}
		cout << endl;

	}
}

//�ж������Ƿ�Ϊ�պʹ�ӡ��������
void printvector(vector<int >& vec)
{
	if (vec.empty())
	{
		cout << "����Ϊ�գ�" << endl;
	}
	else
	{
		for (vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
		{
			cout << *i << " ";
			if (i == vec.end()-1)
			{
				cout << endl;
			}
		}
	}
	
	
}

//vector ��Ĭ�Ϲ���
void structure_vector()
{
	//Ĭ�Ϲ���
	vector<int >v1;
	for (int i = 0; i < 10; i++)
	{
		//��������
		v1.push_back(i);
	}
	printvector(v1);
	cout << endl;

	//ͨ�����䷽ʽ���й���,ֱ����v1�ķ�Χ���й���
	vector<int>v2(v1.begin(), v1.end());
	printvector(v2);
	cout << endl;


	//n��elem�ķ�ʽ����
	vector<int>v3(10, 100);//10��100
	printvector(v3);
	cout << endl;

	//��������
	vector<int>v4(v3);//����v3
	printvector(v4);

}


//vector�ĸ�ֵ����
void test_assign_vector()
{
	vector<int >v1;
	for (int i = 0; i < 5; i++)
	{
		//��������
		v1.push_back(i);
	}
	printvector(v1);
	cout << endl;

	//ֱ����=
	vector<int>v2;
	v2 = v1;
	printvector(v2);
	cout << endl;

	//assign��ֵ
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	printvector(v3);
	cout << endl;

	//n��elem��ʽ��ֵ
	vector<int>v4;
	v4.assign(10, 100);
	printvector(v4);
	cout << endl;
}

//vector�����ʹ�С--volume and size
void test_volumeAndsize_vector()
{
	//��������v
	vector<int>v1;
	vector<int>v2;
	//������v��ֵ
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//��ӡ����v������
	printvector(v1);
	if (v1.empty())//�ж������Ƿ�Ϊ������������գ�����ǿ�
	{
		cout << "����v1Ϊ��";
	}
	else
	{
		cout << "����v1��Ϊ��"<<endl;
		cout<<"����v1�Ĵ�С��"<<v1.size()<<endl;//������С
	}
	cout<<"����v1��������" << v1.capacity() << endl;//v1.������
	cout << "��v1���ټ�һ��Ԫ��10֮��"<<endl;
	v1.push_back(10);
	
	cout << "����v1�Ĵ�С��" << v1.size() << endl;//������С
	cout << "����v1��������" << v1.capacity()<<endl;//v1.������

	//�����ݴ�С
	v1.resize(15, 3);//����ָ��v1�Ĵ�СΪ15����3����
	printvector(v1);
	cout << "����v1�Ĵ�С��" << v1.size() << endl;//������С
	cout << "����v1��������" << v1.capacity() << endl;//v1.������

	v1.resize(20);//����ָ��v1�Ĵ�СΪ20����0����
	printvector(v1);
	cout << "����v1�Ĵ�С��" << v1.size() << endl;//������С
	cout << "����v1��������" << v1.capacity() << endl;//v1.������

	v1.resize(10);//����ָ��v1�Ĵ�СΪ10����������ɾ��
	printvector(v1);
	cout << "����v1�Ĵ�С��" << v1.size() << endl;//������С
	cout << "����v1��������" << v1.capacity() << endl;//v1.������

}


//vector�Ĳ����ɾ�� insert and delete
void test_InsertAndDelete()
{

	//����һ������
	vector<int>v1;

	//v1��ֵ
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 1);
	}
	printvector(v1);


	//v1����������
	v1.insert(v1.end(),6);//�²���һ��Ԫ��6
	printvector(v1);

	//������--ͨ��������������λ�ã�������Χ�ڣ��������
	//v1.begin���ڵ�һ������
	v1.insert(v1.begin() + 1, 3);//v1.begin�ڵڶ�λ�ã��Ӹ�3,	���ǵ�����
	printvector(v1);

	
	//��һ��λ�����������3��100������
	v1.insert(v1.begin(), 3, 100);//�ڵ�һ��λ��ǰ����3��100
	printvector(v1);

	//ɾ��
	v1.erase(v1.begin(), v1.begin() + 3);//ɾ��3��100
	printvector(v1);
	
	//���
	v1.clear();
	printvector(v1);

}


//vector���ݴ�ȡ--access
void test_AccessData_vector()
{
	//��������
	vector<int>v1;
	
	//������ֵ
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}

	//��ӡ��������--������������
	cout << "ͨ��[]��������v1����:";
	for (int i = 0; i < v1.size(); i++)
	{
		//ͨ��[]����
		cout << v1[i] << " ";
	}
	cout << endl;
	cout << "ͨ����Ա����at��������v1����:";
	for (int i = 0; i < v1.size(); i++)
	{
		//ͨ��at����
		cout << v1.at(i) << " ";
	}
	cout << endl;

	//���ʵ�һ��Ԫ��
	cout << "��һ��Ԫ���ǣ�" << v1.front() << endl;

	//�������һ��Ԫ��
	cout << "���һ��Ԫ�أ�" << v1.back() << endl;
}

//��������
void test_Swap_vector()
{
	//��������v1
	vector<int>v1;

	cout << "��������֮ǰ��" << endl;
	//����v1��ֵ
	for (int i = 1; i < 10; i++)
	{
		v1.push_back(i);
	}
	//����V1
	printvector(v1);
	

	//��������v2
	vector<int>v2;

	//����v2��ֵ
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	//����V2
	printvector(v2);
	cout << "v1.size=" << v1.size()<<"  ";
	cout << "v2.size=" << v2.size()<<"  "<<endl;

	cout << "��������֮��" << endl;
	swap(v1, v2);
	printvector(v1);
	printvector(v2);
	cout << "v1.size=" << v1.size()<<"  ";
	cout << "v2.size=" << v2.size()<<"  "<<endl;

	cout << "===============�ָ���====================="<<endl;

	//�����������������ڴ�
	//����һ��������v3
	vector<int>v3;

	//����v3��ֵ
	for (int i = 0; i < 100000; i++)
	{
		v3.push_back(i);
	}
	cout << "v3�Ĵ�С��" << v3.size()<<endl;
	cout << "v3��������" << v3.capacity()<<endl;
	
	cout << "��������v3�Ĵ�С"<<endl;
	//��������v3�Ĵ�С
	v3.resize(10);
	cout << "v3�Ĵ�С��" << v3.size() << endl;
	cout << "v3��������" << v3.capacity() << endl;
	cout << "����v3�Ͷദ�˺ö����������˷ѵ�" << endl;

	//ͨ������ķ���ʹv3��������С����Ӧ��Χ
	vector<int>(v4);
	swap(v3, v4);
	cout << "v3�Ĵ�С��" << v3.size() << endl;
	cout << "v3��������" << v3.capacity() << endl;
	cout << "v4�Ĵ�С��" << v4.size() << endl;
	cout << "v4��������" << v4.capacity() << endl;

	//ʹv4�������̵����ʵĴ�С��vector<int>(v4)��������
	//���������ص㣺ִ���굱��ʱ��ϵͳ�Զ����տռ�
	vector<int>(v4).swap(v4);
	cout << "v4�Ĵ�С��" << v4.size() << endl;
	cout << "v4��������" << v4.capacity() << endl;
}

//vectorԤ���ռ�
void test_reserves_vector()
{
	//��������v1
	vector<int>v1;

	int count = 0;//ͳ�����·����ڴ����
	int* p = NULL;//һ����ָ��

	//����v1��ֵ
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
		if (p != &v1[0])	//�ж�ָ��p�Ƿ�=������Ԫ�ص�ַ��������ǣ���ǿ�ƽ�ָ��p=������Ԫ�ص�ַ���ƴμ�һ
		{					//vector���ڶ�̬���������������Ǽ򵥵��ٺ�����������������¿���һ������Ŀռ���ԭ�������ݣ�����������Ԫ�ص�ַ�ᷢ���ı�
			p = &v1[0];
			count++;
		}		
	}
	cout << "�ڴ����·����ˣ�" << count<<"��" << endl;			//30��

	//�����Ѿ�֪����һ�������Ĵ����Ҫ���Ŀռ䣬�������Ԥ���ռ�reserve������
	vector<int>v2;
	v2.reserve(100000);
	int* p2=NULL;
	int count2=0;
	for (int i = 0; i < 100000; i++)
	{
		v2.push_back(i);
		if (p2!=&v2[0])
		{
			p2 = &v2[0];
			count2++;
		}
	}
	cout << "�ڴ����·����ˣ�" << count2 << "��" << endl;		//1��

	//����ʡȥ�����¿ռ��ʱ����ڴ�
}
