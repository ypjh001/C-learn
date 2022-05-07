
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
	常用算法：
		1.主要由头文件algotithm.h、functional.h、numeic.h组成
		2.algorithm是STL里最大的一个头文件，涉及比较、交换、查找、遍历、复制、修改等
		3.numeic体积小，只包括几个序列上进行简单运算的模板函数
		4.functional定义了一些模板类用以声明函数对象

		常用函数
			1.for_each()
			2.tranfrom()
			3.常见查找算法
				a、find()
				b、find_if				--按条件查找、
				c、adjecent_find		--查找相邻重复元素、
				d、binary_search		--二分查找、
				e、count				--统计次数、
				f、count_if				--按条件统计元素个数
			
			4.常见排序算法
				a、sort():				对容器内元素进行排序
				b、random_shuffle():	洗牌，指定范围内的元素随机调整次序
				c、merge()：			容器元素和平，并存储到另一个容器中
				d、reverse():			反转指定范围内的元素

			5.常见拷贝函数
				a、copy					拷贝容器内范围元素到新容器里
				b、replace				将容器内指定范围旧元素修改为新元素
				c、replace_if			容器内指定范围内满足条件的元素换为新元素
				d、swap					互换两个容器

			6.常用算术生成算法
				a、accumulate			计算容器元素累计总和
				b、fill					向容器中添加元素

			7.常用集合算法
				a、set_intersection		 求两个容器的交集
				b、set_union			 求两个容器的并集
				c、set_difference	   	 求两个容器的差集

*/

class Myprint_func
{
public:
	int operator()(int a) const
	{
		return a;
	}

};



//遍历容器---仿函数
void myprint_for_each2(int val)
{
	cout <<val<<"  ";
}

//仿函数的形式---for_each()
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
	//遍历函数for_each
	for_each(v1.begin(), v1.end(), myprint_for_each2);
	cout << endl;
	//仿函数的形式打印
	for_each(v1.begin(), v1.end(), myprint_for_each1());
}

//==================================================================

//搬运容器到另一个容器中
class myfunc_transform
{
public:
	//创造仿函数给transform的第四个参数
	int operator()(int a) const
	{
		//好处可以返回一个算术结果
		return a+1;
	}
};

void test_transfrom()
{
	//创建源容器
	vector<int>v_root;
	for (int i = 0; i < 10; i++)
	{
		v_root.push_back(i);
	}
	//目标容器
	vector<int>v_target;
	//分配大小
	v_target.resize(v_root.size());//要提前开辟空间，不然搬不进去
	//v_root搬到v_target里
	transform(v_root.begin(),v_root.end(),v_target.begin(), myfunc_transform());
	//遍历v_target
	for_each(v_target.begin(), v_target.end(), myprint_for_each1());
	cout << endl;
	cout << "v_root的size：" << v_root.size() << endl;
	cout<<"v_targer的size：" << v_target.size() << endl;
}

//==================================================================

//构造Person类
class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	//错误	C2676	二进制“ == ”:“Person”不定义该运算符或到预定义运算符可接收的类型的转换
	//解决：重载==
	bool operator==(const Person& p)
	{
		//要查年龄相同就要去掉名字相同的条件，因为这是混合文件，所以就不去掉同名比较了，直接在count里加几个同名同姓的数据就可以验算cuont函数了
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

//查找算法find
void test_find()
{
	//功能找到返回该元素迭代器，找不到返回结束迭代器end（）

	//查找-内置数据
	vector<int>v_find_int;

	for (int i = 0; i < 10; i++)
	{
		v_find_int.push_back(i);
	}
	//查找元素5
	vector<int>::iterator find_int_target=find(v_find_int.begin(), v_find_int.end(),1);
	//判断有没有找到
	if (find_int_target==v_find_int.end())
	{
		cout << "没有到" << endl;
	}
	else
	{
		cout << "find_int_target("<< *find_int_target <<"):" << *find_int_target << endl;
	}
	
	//查找自定义数据person
	vector<Person>v_find_person;
	//实例对象
	Person p1("同学A", 12);
	Person p2("同学B", 15);
	Person p3("同学C", 13);
	Person p4("同学D", 82);

	//插入数据
	v_find_person.push_back(p1);
	v_find_person.push_back(p2);
	v_find_person.push_back(p3);
	v_find_person.push_back(p4);

	//遍历person
	//for_each(v_find_person.begin(),v_find_person.end(),)

	//查找Person-同学B
	vector<Person>::iterator find_person_target = find(v_find_person.begin(), v_find_person.end(), p2);
	if (find_person_target == v_find_person.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "name:" << find_person_target->m_name << "  age:" << find_person_target->m_age << endl;
	}
}


//==================================================================

//查找算法find_if--按照条件查找

//find_if的仿函数
class imitate_func_find_if_int		//仿函数
{
public:
	int operator()(int a) const
	{
		return a > 5;
	}
};
//for_each仿函数
class imitate_func_for_each_person
{
public:
	void operator()(const Person& p)const
	{
		cout <<"name:" << p.m_name << " age:" << p.m_age << endl;
	}
};
//find_if的仿函数
class imitate_class_find_if_person
{
public:
	bool operator()(Person& p)const
	{
		//一个一个Person类型数据传进来，取Person的对象p的年龄age和14做比较，返回比较值（真--假）
		return p.m_age == 14;
	}
	
	
};
void test_find_if()//（前，后，条件）
{
	//查找内置数据int
	vector<int>v_find_if_int;

	//插入数据
	for (int i = 0; i < 10; i++)
	{
		v_find_if_int.push_back(i);
	}

	//find_if
	vector<int>::iterator find_if_target=find_if(v_find_if_int.begin(),v_find_if_int.end(),imitate_func_find_if_int());//返回find_if也是个迭代器，所以要拿迭代器来接收
	if (find_if_target==v_find_if_int.end())
	{
		cout << "没找到";
	}
	else
	{
		cout <<"找到个大于5的数值" << *find_if_target << endl;//6
	}


	//======================================

	//按条件查找自定义类型如Person

	//Person容器
	vector<Person>v_person;

	//实例化Person对象
	Person p1("张三", 15);
	Person p2("李四", 16);
	Person p3("王五", 14);
	Person p4("赵六", 18);
	Person p5("田七", 14);
	Person p6("王八", 14);
	Person p7("里八", 15);
	Person p8("靠八", 17);

	//插入数据--尾插
	v_person.push_back(p1);
	v_person.push_back(p2);
	v_person.push_back(p3);
	v_person.push_back(p4);
	v_person.push_back(p5);
	v_person.push_back(p6);
	v_person.push_back(p7);
	v_person.push_back(p8);

	//遍历一下v_person数据
	 for_each(v_person.begin(), v_person.end(),imitate_func_for_each_person());

	 //查找age=14的person
	 vector<Person>::iterator find_if_person_target= find_if(v_person.begin(), v_person.end(), imitate_class_find_if_person());//返回一个迭代器，用迭代器接收，*迭代器访问元素
	 if (find_if_person_target==v_person.end())
	 {
		 cout << "没找到" << endl;
	 }
	 else
	 {
		 cout << "name：" << find_if_person_target->m_name << " age：" << (*find_if_person_target).m_age << endl;
	 }
	 cout << endl;
	 //错误---还不能实现
	 ////找出所以满足的条件
	 ////思路，*迭代器age不等于14时，一直找
	 //cout << "输出age=14的全部元素";
	 //for (find_if_person_target=v_person.begin();(*find_if_person_target).m_age == 14;++find_if_person_target)
	 //{
		// 
		// cout << "name：" << find_if_person_target->m_name << " age：" << (*find_if_person_target).m_age << endl;
		//	 
	 //}


}



//==================================================================

//查找算法adjacent_find;查找 相邻 重复 的元素
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

	vector<int>::iterator adjacen_find_int_target= adjacent_find(v_int.begin(), v_int.end());//返回迭代器--用迭代器接收--*迭代器访问元素
	if (adjacen_find_int_target==v_int.end())
	{
		cout << "没找到相邻重复元素";
	}
	else
	{
		cout << "找到相邻同元素:" << endl;
		cout << *adjacen_find_int_target << endl;//out 2
	}



}


//==================================================================
//二分查找binary_seach()
void test_binary_seach()
{
	vector<int>v_int;
	for (int i = 0; i < 10; i++)
	{
		v_int.push_back(i);
	}
	bool answer=binary_search(v_int.begin(),v_int.end(),3 );//返回bool类型,无序的序列不能用，二分查找速度很快
	if (answer)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
}



//==================================================================
//count统计个数
void test_count()
{
	//统计内置类型int
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
	cout << "=================分割线===================="<<endl;

	//统计自自定义数据类型Person
	vector<Person>v_person;

	//实例化Person对象
	Person p1("张三", 15);
	Person p2("李四", 16);
	Person p3("王五", 14);
	Person p4("赵六", 18);
	Person p5("田七", 14);
	Person p6("王八", 14);
	Person p7("里八", 15);
	Person p8("靠八", 17);
	Person p9("靠八", 17);
	

	//插入数据--尾插
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

	//查找与p9年龄相同的个数
	v_person.push_back(p9);


	cout<<count(v_person.begin(),v_person.end(), p9);//查找与P9数据（name and age）一样的数据有几个
}


//==================================================================
//按条件count统计个数

//创建count_if谓词--用于int
class imitate_class_count_if_int
{
public:
	int operator()(int n) const
	{
		//统计v_int中>30的数
		return n > 30;
	}
};
//创建count_if谓词--用于person
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
	//统计内置数据类型（int）

	vector<int>v_int;
	v_int.push_back(10);
	v_int.push_back(20);
	v_int.push_back(30);
	v_int.push_back(40);
	v_int.push_back(50);
	v_int.push_back(60);
	v_int.push_back(70);

	cout<<"容器v_int中>30的有:" << count_if(v_int.begin(), v_int.end(), imitate_class_count_if_int())<<"个"<<endl;//pred是谓词的意思

	//统计自定义类型Person
	vector<Person>v_person;

	Person p1("张三", 15);
	Person p2("张四", 25);
	Person p3("张五", 35);
	Person p4("张六", 55);
	Person p5("张七", 15);
	Person p6("张八", 25);
	Person p7("张九", 35);
	Person p8("张十", 45);

	v_person.push_back(p1);
	v_person.push_back(p2);
	v_person.push_back(p3);
	v_person.push_back(p4);
	v_person.push_back(p5);
	v_person.push_back(p6);
	v_person.push_back(p7);
	v_person.push_back(p8);

	cout<<"v_person中年龄（age）>20的有：" << count_if(v_person.begin(), v_person.end(), imitate_class_count_if_person())<<"个"<<endl;
	




}



//==================================================================
//=======================常见排序算法===============================
//=======1.sort===2.random_shuffle====3.merge===4.reverse===========
//==================================================================




//1.排序sort
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

	//小->大
	sort(v_int.begin(), v_int.end());

	//遍历打印
	for_each(v_int.begin(), v_int.end(),myprint_for_each1());//仿函数实现打印就好了:1  2  2  3  4  5  6  7  7  8  8  9
	cout << endl;
	//大->小:降序
	sort(v_int.begin(), v_int.end(),greater<int>());//greater内建函数
	//遍历
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());//9  8  8  7  7  6  5  4  3  2  2  1


}

//2.打乱，洗牌random_shuffle
void test_random_shufle()
{
	//随机数种子---用random_shuffle时使用，不然打乱都是固定的
	srand((unsigned int)time(NULL));


	vector<int>v_int;
	for (int i = 0; i < 10; i++)
	{
		v_int.push_back(i);
	}
	//打乱前--遍历
	cout << "打乱前：";
	for_each(v_int.begin(), v_int.end(),myprint_for_each1());//0  1  2  3  4  5  6  7  8  9
	cout << endl;
	//打乱后--遍历
	random_shuffle(v_int.begin(), v_int.end());
	cout << "打乱后：";
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());//8  1  9  2  0  5  7  3  4  6


}


//merge，合并容器1和容器2到新容器3里
void test_merge()
{
	//注意：源容器1和源容器2要有排序，同意小到大或者大到小

	//源容器1和2
	vector<int>v_IntRootOne;
	vector<int>v_IntRootTow;

	for (int i = 0; i < 10; i++)
	{
		v_IntRootOne.push_back(i);
		v_IntRootTow.push_back(i+1);
	}

	//目标容器
	vector<int>v_IntTarget;
	//记得先给v_IntTarget分配空间不然报错
	v_IntTarget.resize(v_IntRootOne.size() + v_IntRootTow.size());

	merge(v_IntRootOne.begin(),v_IntRootOne.end(),v_IntRootTow.begin(),v_IntRootTow.end(),v_IntTarget.begin());
	for_each(v_IntTarget.begin(), v_IntTarget.end(), myprint_for_each1());

}

//reverse，反转
void test_reverse()
{
	vector<int>v_int;
	v_int.push_back(1);
	v_int.push_back(3);
	v_int.push_back(5);
	v_int.push_back(7);
	v_int.push_back(9);
	v_int.push_back(11);

	cout << "反转前：";
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());//遍历
	cout << endl;
	cout << "反转后：";
	//reverse(v_int.begin(), v_int.end());
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());//遍历

}


//================================================================== 
//=======================常见拷贝算法===============================
//=========1.copy===2.replace====3.replace_if===4.swap==============
//==================================================================


//copy拷贝--指定范围拷贝到另一个容器里
void test_copy()
{
	vector<int>v_IntRoot;
	vector<int>v_IntTarget;
	for (int i = 0; i < 10; i++)
	{
		v_IntRoot.push_back(i);
	}
	v_IntTarget.resize(10,0);
	//遍历
	cout << "第一行拷贝到第二行:" << endl;
	cout << "拷贝前：" << endl;
	for_each(v_IntRoot.begin(),v_IntRoot.end(),myprint_for_each1());
	cout << endl;
	for_each(v_IntTarget.begin(), v_IntTarget.end(), myprint_for_each1());
	cout << endl;
	copy(v_IntRoot.begin(),v_IntRoot.end(),v_IntTarget.begin());//Dest目标起始点

	cout << "拷贝后：" << endl;
	for_each(v_IntRoot.begin(), v_IntRoot.end(), myprint_for_each1());
	cout << endl;
	for_each(v_IntTarget.begin(), v_IntTarget.end(), myprint_for_each1());
}


//replace将容器内指定范围旧元素修改为新元素
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

	cout << "替换前:" << endl;
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());
	cout << endl;
	cout << "替换后:" << endl;
	replace(v_int.begin(),v_int.end(),10,100);//将范围内10替换100；
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());
}

//replace_if容器内指定范围内满足条件的元素换为新元素
class greatFifteen
{//一元谓词，大于15的数
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
	//一元谓词，小于15的数
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
	//替换--将大于15的替换20；小于15的替换10,15不动
	cout << "替换前:" << endl;
	//遍历
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());
	cout << endl;
	cout << "将大于15的替换20；小于15的替换10,15不动：" << endl;
	replace_if(v_int.begin(),v_int.end(),greatFifteen(),20);//(始，终，谓词，新值）
	replace_if(v_int.begin(), v_int.end(), lessFifteen(), 10);//(始，终，谓词，新值）
	//遍历
	for_each(v_int.begin(), v_int.end(), myprint_for_each1());
}


//swap互换两个容器
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
	cout << "交换前:" << endl;
	cout << "v_IntOne:";
	for_each(v_IntOne.begin(), v_IntOne.end(), myprint_for_each1());
	cout << endl;
	cout << "v_IntTow:";
	for_each(v_IntTwo.begin(), v_IntTwo.end(), myprint_for_each1());
	cout << endl;
	swap(v_IntOne, v_IntTwo);//容器交换
	cout << "交换后：" << endl;
	cout << "v_IntOne:";
	for_each(v_IntOne.begin(), v_IntOne.end(), myprint_for_each1());
	cout << endl;
	cout << "v_IntTow:";
	for_each(v_IntTwo.begin(), v_IntTwo.end(), myprint_for_each1());
	cout << endl;
}

//================================================================== 
//=======================常用算术生成算法===========================
//======================1.accumulate===2.fill=======================
//==================================================================

//accumulate计算容器元素累计总和
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
	cout<<accumulate(v_Int.begin(),v_Int.end(),0);//(始，终，起始值）
	

}

//fill向容器中添加元素
void test_fill()
{
	vector<int>v_Int{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for_each(v_Int.begin(), v_Int.end(), myprint_for_each1());//1  2  3  4  5  6  7  8  9  10
	cout << endl;
	//用fill填充10，全部换了10,如果前期没有给v_Int赋值，也可以后期通过fill填充数据
	fill(v_Int.begin(),v_Int.end(),10);
	for_each(v_Int.begin(), v_Int.end(), myprint_for_each1());//10  10  10  10  10  10  10  10  10  10  
}


//================================================================== 
//=======================常用合集算法===============================
//=======1.set_intersection===2.set_union===3.set_difference========
//==================================================================

//set_intersection		 求两个容器的交集
void test_set_intersection()
{
	//要求，要有序序列才可以
	//记得要提前分配空间
	cout << "求合集" << endl;
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
	//求合集
	vector<int>v_IntThree;

	//v_IntThree.resize(min(v_IntOne.size(), v_IntTwo.size()));
	////cout << v_IntThree.size();
	//vector<int>::iterator itEnd= set_intersection(v_IntOne.begin(), v_IntOne.end(), v_IntTwo.begin(), v_IntTwo.end(), v_IntThree.begin());
	//for_each(v_IntThree.begin(), itEnd, myprint_for_each1());

	v_IntThree.resize(min(v_IntOne.size(),v_IntTwo.size()));
	vector<int>::iterator  itEnd= set_intersection(v_IntOne.begin(), v_IntOne.end(), v_IntTwo.begin(), v_IntTwo.end(), v_IntThree.begin());//Dest=destination=目标地.返回的是一个迭代器，是交集的最后一个位置
	for_each(v_IntThree.begin(), itEnd, myprint_for_each1());
}

//set_union			 求两个容器的并集
void test_set_union()
{
	//要求，要有序序列才可以
	//记得要提前分配空间
	cout << "求并集：" << endl;
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
	//新容器
	vector<int>v_target;
	v_target.resize(v_IntOne.size() + v_IntTwo.size());

	//求并集
	vector<int>::iterator  itEnd = set_union(v_IntOne.begin(), v_IntOne.end(), v_IntTwo.begin(), v_IntTwo.end(), v_target.begin());//也返回一个迭代器，最后一个数
	//第一种情况才是符合要求的
	for_each(v_target.begin(), itEnd, myprint_for_each1());			//0  1  2  3  4  5  6  7  8  9  10  11  12  13  14
	cout << endl;
	for_each(v_target.begin(), v_target.end(), myprint_for_each1());//0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  0  0  0  0  0

}

//set_difference	   	 求两个容器的差集
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

	//求差集
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


	//另一个思路：v1-|v1-v2| or  v2-|v1-v2|


}