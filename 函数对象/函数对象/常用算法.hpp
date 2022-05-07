
#pragma once
#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<time.h>



using namespace std;

/*
	�����㷨��
		1.��Ҫ��ͷ�ļ�algotithm.h��functional.h��numeic.h���
		2.algorithm��STL������һ��ͷ�ļ����漰�Ƚϡ����������ҡ����������ơ��޸ĵ�
		3.numeic���С��ֻ�������������Ͻ��м������ģ�庯��
		4.functional������һЩģ��������������������

		���ú���
			1.for_each()
			2.tranfrom()
			3.���������㷨
				a��find()
				b��find_if				--���������ҡ�
				c��adjecent_find		--���������ظ�Ԫ�ء�
				d��binary_search		--���ֲ��ҡ�
				e��count				--ͳ�ƴ�����
				f��count_if				--������ͳ��Ԫ�ظ���
			
			4.���������㷨
				a��sort():				��������Ԫ�ؽ�������
				b��random_shuffle():	ϴ�ƣ�ָ����Χ�ڵ�Ԫ�������������
				c��merge()��			����Ԫ�غ�ƽ�����洢����һ��������
				d��reverse():			��תָ����Χ�ڵ�Ԫ��

			5.������������
				a��copy					���������ڷ�ΧԪ�ص���������
				b��replace				��������ָ����Χ��Ԫ���޸�Ϊ��Ԫ��
				c��replace_if			������ָ����Χ������������Ԫ�ػ�Ϊ��Ԫ��
				d��swap					������������

			6.�������������㷨
				a��accumulate			��������Ԫ���ۼ��ܺ�
				b��fill					�����������Ԫ��

			7.���ü����㷨
				a��set_intersection		 �����������Ľ���
				b��set_union			 �����������Ĳ���
				c��set_difference	   	 �����������Ĳ

*/

class Myprint_func
{
public:
	int operator()(int a) const
	{
		return a;
	}

};



//��������---�º���
void myprint_for_each2(int val)
{
	cout <<val<<"  ";
}

//�º�������ʽ---for_each()
class myprint_for_each1
{
public:
	void  operator()(int val) const
	{
		cout<< val<<"  ";
	}
};

void test_for_each()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//��������for_each
	for_each(v1.begin(), v1.end(), myprint_for_each2);
	cout << endl;
	//�º�������ʽ��ӡ
	for_each(v1.begin(), v1.end(), myprint_for_each1());
}

//==================================================================

//������������һ��������
class myfunc_transform
{
public:
	//����º�����transform�ĵ��ĸ�����
	int operator()(int a) const
	{
		//�ô����Է���һ���������
		return a+1;
	}
};

void test_transfrom()
{
	//����Դ����
	vector<int>v_root;
	for (int i = 0; i < 10; i++)
	{
		v_root.push_back(i);
	}
	//Ŀ������
	vector<int>v_target;
	//�����С
	v_target.resize(v_root.size());//Ҫ��ǰ���ٿռ䣬��Ȼ�᲻��ȥ
	//v_root�ᵽv_target��
	transform(v_root.begin(),v_root.end(),v_target.begin(), myfunc_transform());
	//����v_target
	for_each(v_target.begin(), v_target.end(), myprint_for_each1());
	cout << endl;
	cout << "v_root��size��" << v_root.size() << endl;
	cout<<"v_targer��size��" << v_target.size() << endl;
}

//==================================================================

//����Person��
class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	//����	C2676	�����ơ� == ��:��Person����������������Ԥ����������ɽ��յ����͵�ת��
	//���������==
	bool operator==(const Person& p)
	{
		//Ҫ��������ͬ��Ҫȥ��������ͬ����������Ϊ���ǻ���ļ������ԾͲ�ȥ��ͬ���Ƚ��ˣ�ֱ����count��Ӽ���ͬ��ͬ�յ����ݾͿ�������cuont������
		if (this->m_name == p.m_name&&this->m_age == p.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	

	string m_name;
	int m_age;
};

//�����㷨find
void test_find()
{
	//�����ҵ����ظ�Ԫ�ص��������Ҳ������ؽ���������end����

	//����-��������
	vector<int>v_find_int;

	for (int i = 0; i < 10; i++)
	{
		v_find_int.push_back(i);
	}
	//����Ԫ��5
	vector<int>::iterator find_int_target=find(v_find_int.begin(), v_find_int.end(),1);
	//�ж���û���ҵ�
	if (find_int_target==v_find_int.end())
	{
		cout << "û�е�" << endl;
	}
	else
	{
		cout << "find_int_target("<< *find_int_target <<"):" << *find_int_target << endl;
	}
	
	//�����Զ�������person
	vector<Person>v_find_person;
	//ʵ������
	Person p1("ͬѧA", 12);
	Person p2("ͬѧB", 15);
	Person p3("ͬѧC", 13);
	Person p4("ͬѧD", 82);

	//��������
	v_find_person.push_back(p1);
	v_find_person.push_back(p2);
	v_find_person.push_back(p3);
	v_find_person.push_back(p4);

	//����person
	//for_each(v_find_person.begin(),v_find_person.end(),)

	//����Person-ͬѧB
	vector<Person>::iterator find_person_target = find(v_find_person.begin(), v_find_person.end(), p2);
	if (find_person_target == v_find_person.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "name:" << find_person_target->m_name << "  age:" << find_person_target->m_age << endl;
	}
}


//==================================================================

//�����㷨find_if--������������

//find_if�ķº���
class imitate_func_find_if_int		//�º���
{
public:
	int operator()(int a) const
	{
		return a > 5;
	}
};
//for_each�º���
class imitate_func_for_each_person
{
public:
	void operator()(const Person& p)const
	{
		cout <<"name:" << p.m_name << " age:" << p.m_age << endl;
	}
};
//find_if�ķº���
class imitate_class_find_if_person
{
public:
	bool operator()(Person& p)const
	{
		//һ��һ��Person�������ݴ�������ȡPerson�Ķ���p������age��14���Ƚϣ����رȽ�ֵ����--�٣�
		return p.m_age == 14;
	}
	
	
};
void test_find_if()//��ǰ����������
{
	//������������int
	vector<int>v_find_if_int;

	//��������
	for (int i = 0; i < 10; i++)
	{
		v_find_if_int.push_back(i);
	}

	//find_if
	vector<int>::iterator find_if_target=find_if(v_find_if_int.begin(),v_find_if_int.end(),imitate_func_find_if_int());//����find_ifҲ�Ǹ�������������Ҫ�õ�����������
	if (find_if_target==v_find_if_int.end())
	{
		cout << "û�ҵ�";
	}
	else
	{
		cout <<"�ҵ�������5����ֵ" << *find_if_target << endl;//6
	}


	//======================================

	//�����������Զ���������Person

	//Person����
	vector<Person>v_person;

	//ʵ����Person����
	Person p1("����", 15);
	Person p2("����", 16);
	Person p3("����", 14);
	Person p4("����", 18);
	Person p5("����", 14);
	Person p6("����", 14);
	Person p7("���", 15);
	Person p8("����", 17);

	//��������--β��
	v_person.push_back(p1);
	v_person.push_back(p2);
	v_person.push_back(p3);
	v_person.push_back(p4);
	v_person.push_back(p5);
	v_person.push_back(p6);
	v_person.push_back(p7);
	v_person.push_back(p8);

	//����һ��v_person����
	 for_each(v_person.begin(), v_person.end(),imitate_func_for_each_person());

	 //����age=14��person
	 vector<Person>::iterator find_if_person_target= find_if(v_person.begin(), v_person.end(), imitate_class_find_if_person());//����һ�����������õ��������գ�*����������Ԫ��
	 if (find_if_person_target==v_person.end())
	 {
		 cout << "û�ҵ�" << endl;
	 }
	 else
	 {
		 cout << "name��" << find_if_person_target->m_name << " age��" << (*find_if_person_target).m_age << endl;
	 }
	 cout << endl;
	 //����---������ʵ��
	 ////�ҳ��������������
	 ////˼·��*������age������14ʱ��һֱ��
	 //cout << "���age=14��ȫ��Ԫ��";
	 //for (find_if_person_target=v_person.begin();(*find_if_person_target).m_age == 14;++find_if_person_target)
	 //{
		// 
		// cout << "name��" << find_if_person_target->m_name << " age��" << (*find_if_person_target).m_age << endl;
		//	 
	 //}


}



//==================================================================

//�����㷨adjacent_find;���� ���� �ظ� ��Ԫ��
void test_adjacent_find()
{
	vector<int>v_int;

	v_int.push_back(1);
	v_int.push_back(3);
	v_int.push_back(1);
	v_int.push_back(3);
	v_int.push_back(1);
	//v_int.push_back(1);
	v_int.push_back(2);
	v_int.push_back(2);
	v_int.push_back(1);

	vector<int>::iterator adjacen_find_int_target= adjacent_find(v_int.begin(), v_int.end());//���ص�����--�õ���������--*����������Ԫ��
	if (adjacen_find_int_target==v_int.end())
	{
		cout << "û�ҵ������ظ�Ԫ��";
	}
	else
	{
		cout << "�ҵ�����ͬԪ��:" << endl;
		cout << *adjacen_find_int_target << endl;//out 2
	}



}


//==================================================================
//���ֲ���binary_seach()
void test_binary_seach()
{
	vector<int>v_int;
	for (int i = 0; i < 10; i++)
	{
		v_int.push_back(i);
	}
	bool answer=binary_search(v_int.begin(),v_int.end(),3 );//����bool����,��������в����ã����ֲ����ٶȺܿ�
	if (answer)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û�ҵ�" << endl;
	}
}



//==================================================================
//countͳ�Ƹ���
void test_count()
{
	//ͳ����������int
	vector<int>v_int;

	v_int.push_back(10);
	v_int.push_back(10);
	v_int.push_back(10);
	v_int.push_back(10);
	v_int.push_back(20);
	v_int.push_back(10);
	v_int.push_back(20);
	v_int.push_back(10);
	v_int.push_back(30);

	cout<<count(v_int.begin(),v_int.end(),10)<<endl;//6
	cout << count(v_int.begin(), v_int.end(), 20)<<endl;//2
	cout << count(v_int.begin(), v_int.end(), 30)<<endl;//1 
	cout << "=================�ָ���===================="<<endl;

	//ͳ�����Զ�����������Person
	vector<Person>v_person;

	//ʵ����Person����
	Person p1("����", 15);
	Person p2("����", 16);
	Person p3("����", 14);
	Person p4("����", 18);
	Person p5("����", 14);
	Person p6("����", 14);
	Person p7("���", 15);
	Person p8("����", 17);
	Person p9("����", 17);
	

	//��������--β��
	v_person.push_back(p1);
	v_person.push_back(p2);
	v_person.push_back(p3);
	v_person.push_back(p4);
	v_person.push_back(p5);
	v_person.push_back(p6);
	v_person.push_back(p7);
	v_person.push_back(p8);
	v_person.push_back(p8);
	v_person.push_back(p8);
	v_person.push_back(p8);
	v_person.push_back(p8);

	//������p9������ͬ�ĸ���
	v_person.push_back(p9);


	cout<<count(v_person.begin(),v_person.end(), p9);//������P9���ݣ�name and age��һ���������м���
}


//==================================================================
//������countͳ�Ƹ���

//����count_ifν��--����int
class imitate_class_count_if_int
{
public:
	int operator()(int n) const
	{
		//ͳ��v_int��>30����
		return n > 30;
	}
};
//����count_ifν��--����person
class imitate_class_count_if_person
{
public:
	bool operator()(Person& p)const
	{
		if (p.m_age >= 20)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void test_count_if()
{
	//ͳ�������������ͣ�int��

	vector<int>v_int;
	v_int.push_back(10);
	v_int.push_back(20);
	v_int.push_back(30);
	v_int.push_back(40);
	v_int.push_back(50);
	v_int.push_back(60);
	v_int.push_back(70);

	cout<<"����v_int��>30����:" << count_if(v_int.begin(), v_int.end(), imitate_class_count_if_int())<<"��"<<endl;//pred��ν�ʵ���˼

	//ͳ���Զ�������Person
	vector<Person>v_person;

	Person p1("����", 15);
	Person p2("����", 25);
	Person p3("����", 35);
	Person p4("����", 55);
	Person p5("����", 15);
	Person p6("�Ű�", 25);
	Person p7("�ž�", 35);
	Person p8("��ʮ", 45);

	v_person.push_back(p1);
	v_person.push_back(p2);
	v_person.push_back(p3);
	v_person.push_back(p4);
	v_person.push_back(p5);
	v_person.push_back(p6);
	v_person.push_back(p7);
	v_person.push_back(p8);

	cout<<"v_person�����䣨age��>20���У�" << count_if(v_person.begin(), v_person.end(), imitate_class_count_if_person())<<"��"<<endl;
	




}



//==================================================================
//=======================���������㷨===============================
//=======1.sort===2.random_shuffle====3.merge===4.reverse===========
//==================================================================




//1.����sort
void test_sort()
{
	vector<int>v_int;

	v_int.push_back(3);
	v_int.push_back(1);
	v_int.push_back(5);
	v_int.push_back(4);
	v_int.push_back(2);
	v_int.push_back(8);
	v_int.push_back(7);
	v_int.push_back(6);
	v_int.push_back(9);
	v_int.push_back(2);
	v_int.push_back(8);
	v_int.push_back(7);

	//С->��
	sort(v_int.begin(), v_int.end());

	//������ӡ
	for_each(v_int.begin(), v_int.end(),myprint_for_each1());//�º���ʵ�ִ�ӡ�ͺ���:1  2  2  3  4  5  6  7  7  8  8  9
	cout << endl;
	//��->С:����
	sort(v_int.begin(), v_int.end(),greater<int>());//greater�ڽ�����
	//����
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());//9  8  8  7  7  6  5  4  3  2  2  1


}

//2.���ң�ϴ��random_shuffle
void test_random_shufle()
{
	//���������---��random_shuffleʱʹ�ã���Ȼ���Ҷ��ǹ̶���
	srand((unsigned int)time(NULL));


	vector<int>v_int;
	for (int i = 0; i < 10; i++)
	{
		v_int.push_back(i);
	}
	//����ǰ--����
	cout << "����ǰ��";
	for_each(v_int.begin(), v_int.end(),myprint_for_each1());//0  1  2  3  4  5  6  7  8  9
	cout << endl;
	//���Һ�--����
	random_shuffle(v_int.begin(), v_int.end());
	cout << "���Һ�";
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());//8  1  9  2  0  5  7  3  4  6


}


//merge���ϲ�����1������2��������3��
void test_merge()
{
	//ע�⣺Դ����1��Դ����2Ҫ������ͬ��С������ߴ�С

	//Դ����1��2
	vector<int>v_IntRootOne;
	vector<int>v_IntRootTow;

	for (int i = 0; i < 10; i++)
	{
		v_IntRootOne.push_back(i);
		v_IntRootTow.push_back(i+1);
	}

	//Ŀ������
	vector<int>v_IntTarget;
	//�ǵ��ȸ�v_IntTarget����ռ䲻Ȼ����
	v_IntTarget.resize(v_IntRootOne.size() + v_IntRootTow.size());

	merge(v_IntRootOne.begin(),v_IntRootOne.end(),v_IntRootTow.begin(),v_IntRootTow.end(),v_IntTarget.begin());
	for_each(v_IntTarget.begin(), v_IntTarget.end(), myprint_for_each1());

}

//reverse����ת
void test_reverse()
{
	vector<int>v_int;
	v_int.push_back(1);
	v_int.push_back(3);
	v_int.push_back(5);
	v_int.push_back(7);
	v_int.push_back(9);
	v_int.push_back(11);

	cout << "��תǰ��";
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());//����
	cout << endl;
	cout << "��ת��";
	//reverse(v_int.begin(), v_int.end());
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());//����

}


//================================================================== 
//=======================���������㷨===============================
//=========1.copy===2.replace====3.replace_if===4.swap==============
//==================================================================


//copy����--ָ����Χ��������һ��������
void test_copy()
{
	vector<int>v_IntRoot;
	vector<int>v_IntTarget;
	for (int i = 0; i < 10; i++)
	{
		v_IntRoot.push_back(i);
	}
	v_IntTarget.resize(10,0);
	//����
	cout << "��һ�п������ڶ���:" << endl;
	cout << "����ǰ��" << endl;
	for_each(v_IntRoot.begin(),v_IntRoot.end(),myprint_for_each1());
	cout << endl;
	for_each(v_IntTarget.begin(), v_IntTarget.end(), myprint_for_each1());
	cout << endl;
	copy(v_IntRoot.begin(),v_IntRoot.end(),v_IntTarget.begin());//DestĿ����ʼ��

	cout << "������" << endl;
	for_each(v_IntRoot.begin(), v_IntRoot.end(), myprint_for_each1());
	cout << endl;
	for_each(v_IntTarget.begin(), v_IntTarget.end(), myprint_for_each1());
}


//replace��������ָ����Χ��Ԫ���޸�Ϊ��Ԫ��
void test_replace()
{
	vector<int>v_int;
	v_int.push_back(10);
	v_int.push_back(20);
	v_int.push_back(10);
	v_int.push_back(30);
	v_int.push_back(50);
	v_int.push_back(70);
	v_int.push_back(10);
	v_int.push_back(60);

	cout << "�滻ǰ:" << endl;
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());
	cout << endl;
	cout << "�滻��:" << endl;
	replace(v_int.begin(),v_int.end(),10,100);//����Χ��10�滻100��
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());
}

//replace_if������ָ����Χ������������Ԫ�ػ�Ϊ��Ԫ��
class greatFifteen
{//һԪν�ʣ�����15����
public:
	bool operator()(int n) const
	{
		if (n>15)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
class lessFifteen
{
	//һԪν�ʣ�С��15����
public:
	bool operator()(int n) const
	{
		if (n <15)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
void test_replace_if()
{
	vector<int>v_int;
	v_int.push_back(11);
	v_int.push_back(19);
	v_int.push_back(11);
	v_int.push_back(14);
	v_int.push_back(12);
	v_int.push_back(13);
	v_int.push_back(10);
	v_int.push_back(14);
	v_int.push_back(10);
	v_int.push_back(30);
	v_int.push_back(15);
	v_int.push_back(12);
	//�滻--������15���滻20��С��15���滻10,15����
	cout << "�滻ǰ:" << endl;
	//����
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());
	cout << endl;
	cout << "������15���滻20��С��15���滻10,15������" << endl;
	replace_if(v_int.begin(),v_int.end(),greatFifteen(),20);//(ʼ���գ�ν�ʣ���ֵ��
	replace_if(v_int.begin(), v_int.end(), lessFifteen(), 10);//(ʼ���գ�ν�ʣ���ֵ��
	//����
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());
}


//swap������������
void test_swap()
{
	vector<int>v_IntOne;
	vector<int>v_IntTwo;
	for (int i = 0; i < 10; i++)
	{
		v_IntOne.push_back(10*i);
	}	
	for (int i = 0; i < 10; i++)
	{
		v_IntTwo.push_back(i);
	}
	cout << "����ǰ:" << endl;
	cout << "v_IntOne:";
	for_each(v_IntOne.begin(), v_IntOne.end(), myprint_for_each1());
	cout << endl;
	cout << "v_IntTow:";
	for_each(v_IntTwo.begin(), v_IntTwo.end(), myprint_for_each1());
	cout << endl;
	swap(v_IntOne, v_IntTwo);//��������
	cout << "������" << endl;
	cout << "v_IntOne:";
	for_each(v_IntOne.begin(), v_IntOne.end(), myprint_for_each1());
	cout << endl;
	cout << "v_IntTow:";
	for_each(v_IntTwo.begin(), v_IntTwo.end(), myprint_for_each1());
	cout << endl;
}

//================================================================== 
//=======================�������������㷨===========================
//======================1.accumulate===2.fill=======================
//==================================================================

//accumulate��������Ԫ���ۼ��ܺ�
void test_accumulate()
{
	vector<int>v_Int;
	v_Int.push_back(10);
	v_Int.push_back(20);
	v_Int.push_back(30);
	v_Int.push_back(40);
	v_Int.push_back(60);
	v_Int.push_back(50);
	v_Int.push_back(80);
	v_Int.push_back(90);
	v_Int.push_back(70);
	cout<<accumulate(v_Int.begin(),v_Int.end(),0);//(ʼ���գ���ʼֵ��
	

}

//fill�����������Ԫ��
void test_fill()
{
	vector<int>v_Int{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for_each(v_Int.begin(), v_Int.end(), myprint_for_each1());//1  2  3  4  5  6  7  8  9  10
	cout << endl;
	//��fill���10��ȫ������10,���ǰ��û�и�v_Int��ֵ��Ҳ���Ժ���ͨ��fill�������
	fill(v_Int.begin(),v_Int.end(),10);
	for_each(v_Int.begin(), v_Int.end(), myprint_for_each1());//10  10  10  10  10  10  10  10  10  10  
}


//================================================================== 
//=======================���úϼ��㷨===============================
//=======1.set_intersection===2.set_union===3.set_difference========
//==================================================================

//set_intersection		 �����������Ľ���
void test_set_intersection()
{
	//Ҫ��Ҫ�������вſ���
	//�ǵ�Ҫ��ǰ����ռ�
	cout << "��ϼ�" << endl;
	vector<int>v_IntOne;
	vector<int>v_IntTwo;
	for (int i = 0; i < 10; i++)
	{
		v_IntOne.push_back(i);//0~9
		v_IntTwo.push_back(i + 5);//5~14
	}
	for_each(v_IntOne.begin(), v_IntOne.end(), myprint_for_each1());
	cout << endl;
	for_each(v_IntTwo.begin(), v_IntTwo.end(), myprint_for_each1());
	cout << endl;
	//��ϼ�
	vector<int>v_IntThree;

	//v_IntThree.resize(min(v_IntOne.size(), v_IntTwo.size()));
	////cout << v_IntThree.size();
	//vector<int>::iterator itEnd= set_intersection(v_IntOne.begin(), v_IntOne.end(), v_IntTwo.begin(), v_IntTwo.end(), v_IntThree.begin());
	//for_each(v_IntThree.begin(), itEnd, myprint_for_each1());

	v_IntThree.resize(min(v_IntOne.size(),v_IntTwo.size()));
	vector<int>::iterator  itEnd= set_intersection(v_IntOne.begin(), v_IntOne.end(), v_IntTwo.begin(), v_IntTwo.end(), v_IntThree.begin());//Dest=destination=Ŀ���.���ص���һ�����������ǽ��������һ��λ��
	for_each(v_IntThree.begin(), itEnd, myprint_for_each1());
}

//set_union			 �����������Ĳ���
void test_set_union()
{
	//Ҫ��Ҫ�������вſ���
	//�ǵ�Ҫ��ǰ����ռ�
	cout << "�󲢼���" << endl;
	vector<int>v_IntOne;
	vector<int>v_IntTwo;
	for (int i = 0; i < 10; i++)
	{
		v_IntOne.push_back(i);
		v_IntTwo.push_back(i + 5);
	}
	for_each(v_IntOne.begin(), v_IntOne.end(), myprint_for_each1());
	cout << endl;
	for_each(v_IntTwo.begin(), v_IntTwo.end(), myprint_for_each1());
	cout << endl;
	//������
	vector<int>v_target;
	v_target.resize(v_IntOne.size() + v_IntTwo.size());

	//�󲢼�
	vector<int>::iterator  itEnd = set_union(v_IntOne.begin(), v_IntOne.end(), v_IntTwo.begin(), v_IntTwo.end(), v_target.begin());//Ҳ����һ�������������һ����
	//��һ��������Ƿ���Ҫ���
	for_each(v_target.begin(), itEnd, myprint_for_each1());			//0  1  2  3  4  5  6  7  8  9  10  11  12  13  14
	cout << endl;
	for_each(v_target.begin(), v_target.end(), myprint_for_each1());//0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  0  0  0  0  0

}

//set_difference	   	 �����������Ĳ
void test_set_difference()
{
	vector<int>v_IntOne;
	vector<int>v_IntTwo;
	for (int i = 0; i < 10; i++)
	{
		v_IntOne.push_back(i);
		v_IntTwo.push_back(i + 5);
	}
	for_each(v_IntOne.begin(), v_IntOne.end(), myprint_for_each1());
	cout << endl;
	for_each(v_IntTwo.begin(), v_IntTwo.end(), myprint_for_each1());
	cout << endl;

	//��
	//v1-v2
	vector<int>v_target1;
	v_target1.resize(max(v_IntOne.size(),v_IntTwo.size()));
	cout << "v_IntOne-v_IntTwo:" << endl;
	vector<int>::iterator  itEnd1 = set_difference(v_IntOne.begin(), v_IntOne.end(), v_IntTwo.begin(), v_IntTwo.end(), v_target1.begin());
	for_each(v_target1.begin(), itEnd1, myprint_for_each2);
	cout << endl;

	//v2-v1
	vector<int>v_target2;
	v_target2.resize(max(v_IntOne.size(), v_IntTwo.size()));
	cout << "v_IntTwo-v_IntOne:" << endl;
	vector<int>::iterator  itEnd2 = set_difference(v_IntTwo.begin(), v_IntTwo.end(), v_IntOne.begin(), v_IntOne.end(),  v_target2.begin());
	for_each(v_target2.begin(), itEnd2, myprint_for_each2);


	//��һ��˼·��v1-|v1-v2| or  v2-|v1-v2|


}