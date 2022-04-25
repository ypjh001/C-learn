#include<iostream>
#include"多态案例-计算机.h"
#include"纯虚函数和抽象类.h"
#include"多态案例-制作饮料.h"
#include"虚析构和纯虚析构.h"
#include"多态案例-电脑组装.h"
using namespace std;


/*
	多态是OOP的三大特征之一
	分类：
		静态多态：函数重载、符号重载，复用函数名
		动态多态：派生类（子类）和虚函数运行时多态

	动静态区别：
		静态地址早绑定：编译接团确定函数地址
		动态地址晚绑定：运行阶段确定函数地址
*/


/*
	动态多态满足条件：
		1.有继承关系，
		2.子类重写父类的虚函数（在子类中可以不写virtual，也可以写出来）

	注意：
		1.函数重载：在一个类里面两个函数返回值相同，名字相同，参数不同。
		2.函数重写：在继承关系中，子类重写一遍父类的虚函数。
*/
//动物父类（基类）
class Animal
{
public:
	virtual void speak()//virtual ：函数虚化--变成虚函数
	{
		cout << "是动物在说话\n";
	}
};
//小猫子类（派生类）
class Cat :public Animal
{
public:
	virtual void speak()
	{
		cout << "是小猫在说话\n";
	}
};
//小狗子类（派生类）
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "是小狗在说话\n";
	}
};
//执行说话，
void DoSpeak(Animal &animal)//父类可以直接指向之类对象--cat or dog
{
	animal.speak();
}
//测试说话
void test()
{
	Cat cat;
	Dog dog;
	//DoSpeak(cat);//这个默认调用谁？Animal还是Cat。当然是Animal，在Animal类创建成员void speak的时候，系统已经分配地址给speak。而DoSpeak调用animal的地址，所以执行Animal的speak。
				//我脾气暴躁非要用这个方法调用Cat里的spea呢？可以在父类的成员speak前加个virtual，使它变成虚函数
	DoSpeak(cat);
	DoSpeak(dog);
	cat.speak();//调猫
	dog.speak();//调狗
	cat.Animal::speak();//或者加个作用域--调动物
	dog.Animal::speak();//或者加个作用域--调动物
}

int main()
{
	//test();

	//cout<<add(3, 5)<<endl;
	//
	//test_Calculator();
	//
	//test_Add_Abs_traCalculator();//+
	//
	//test_Sub_Abs_traCalculator();//-
	//
	//test_Mul_Abs_traCalculator();//*

	//test_Div_Abs_traCalculator();///

	//test_Pow_Abs_traCalculator();//^

	//test_chun_vir();

	////=======================================
	//MakeCoffee();
	//cout << "==========分割线===========" << endl;
	//MakeAssam();
	//cout << "==========分割线===========" << endl;
	//DoTea();

	//test_speak();

	 test_leven_computer();
	 test_inter_computer();
	//cout << "学习";
	return 0;
}